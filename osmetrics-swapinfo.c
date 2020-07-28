#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>
//#include <includes/getcpu.h>
//#include <sys/time.h>
//#include <sys/resource.h>
#include <sys/sysinfo.h>
//#include <sys/statvfs.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <netdb.h>
//#include <unistd.h>
//#include <linux/if_link.h>

static struct st_mysql_information_schema osmetrics_swapinfo_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_swapinfo_table_fields[]=
{
  {"name", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"comment", 75, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_swapinfo_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  struct sysinfo info;
  TABLE *table= tables->table;
  char fieldname[50];
  char comment[100];

  sysinfo(&info);

  // Total swap space size
  strcpy(fieldname, "total_swap");
  strcpy(comment, "Total swap space size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if (info.totalswap >= 0) {
    table->field[1]->store(info.totalswap);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space still available
  strcpy(fieldname, "free_swap");
  strcpy(comment, "Swap space available");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if (info.freeswap >= 0) {
    table->field[1]->store(info.freeswap);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space used
  strcpy(fieldname, "used_swap");
  strcpy(comment, "Swap space used");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if ((info.freeswap >= 0) && (info.totalswap > 0)) {
    table->field[1]->store(info.totalswap - info.freeswap);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space still available (percentage)
  strcpy(fieldname, "free_swap_pct");
  strcpy(comment, "Swap space available as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if ((info.freeswap >= 0) && (info.totalswap > 0)) {
    table->field[1]->store(info.freeswap / info.totalswap * 100);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space used (percentage)
  strcpy(fieldname, "used_swap_pct");
  strcpy(comment, "Swap space used as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if ((info.freeswap >= 0) && (info.totalswap > 0)) {
    table->field[1]->store((info.totalswap - info.freeswap) / info.totalswap * 100);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  return 0;
}

static int osmetrics_swapinfo_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_swapinfo_table_fields;
  schema_table->fill_table= osmetrics_swapinfo_fill_table;
  return 0;
}

mysql_declare_plugin(os_metrics_swapinfo)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_swapinfo_table_info,                 /* type-specific descriptor */
  "OS_SWAPINFO",                               /* table name */
  "Michael Patrick",                           /* author */
  "OS Metrics: Swap Info",                     /* description */
  PLUGIN_LICENSE_GPL,                          /* license type */
  osmetrics_swapinfo_table_init,                  /* init function */
  NULL,
  0x0001,                                      /* version = 0.1 */
  NULL,                                        /* no status variables */
  NULL,                                        /* no system variables */
  NULL,                                        /* no reserved information */
  0                                            /* no flags */
}
mysql_declare_plugin_end;
