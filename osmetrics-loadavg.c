#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>
#include <includes/getcpu.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <linux/if_link.h>

extern char *mysql_data_home;

static struct st_mysql_information_schema osmetrics_loadavg_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_loadavg_table_fields[]=
{
  {"name", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"comment", 75, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_loadavg_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  struct sysinfo info;
  TABLE *table= tables->table;
  char fieldname[50];
  char comment[100];

  sysinfo(&info);

  // 1 minute load average
  strcpy(fieldname, "1_min");
  strcpy(comment, "1 minute load average");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.loads[0] / 65536);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // 5 minute load average
  strcpy(fieldname, "5_min");
  strcpy(comment, "5 minute load average");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.loads[1] / 65536);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // 15 minute load average
  strcpy(fieldname, "15_min");
  strcpy(comment, "15 minute load average");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.loads[2] / 65536);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  return 0;
}

static int osmetrics_loadavg_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_loadavg_table_fields;
  schema_table->fill_table= osmetrics_loadavg_fill_table;
  return 0;
}

mysql_declare_plugin(os_metrics_loadavg)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_loadavg_table_info,     /* type-specific descriptor */
  "OS_LOADAVG",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics: Load Average",       /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_loadavg_table_init,      /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
