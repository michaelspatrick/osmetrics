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
#include <sys/utsname.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <linux/if_link.h>

extern char *mysql_data_home;

static struct st_mysql_information_schema osmetrics_version_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_version_table_fields[]=
{
  {"name", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_version_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;
  char fieldname[50];

  struct utsname buffer;

  errno = 0;
  if (uname(&buffer) != 0) {
     perror("uname");
     exit(EXIT_FAILURE);
  }

  strcpy(fieldname, "sysname");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buffer.sysname, strlen(buffer.sysname), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  strcpy(fieldname, "nodename");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buffer.nodename, strlen(buffer.nodename), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
    strcpy(fieldname, "release");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buffer.release, strlen(buffer.release), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  strcpy(fieldname, "version");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buffer.version, strlen(buffer.version), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  strcpy(fieldname, "machine");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buffer.machine, strlen(buffer.machine), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  #ifdef _GNU_SOURCE
    strcpy(fieldname, "domainname");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(buffer.domainname, strlen(buffer.domainname), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  #endif

  return 0;
}

static int osmetrics_version_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_version_table_fields;
  schema_table->fill_table= osmetrics_version_fill_table;
  return 0;
}

mysql_declare_plugin(os_metrics_version)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_version_table_info,                /* type-specific descriptor */
  "OS_VERSION",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics Version INFORMATION_SCHEMA table", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_version_table_init,                 /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
