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

static struct st_mysql_information_schema osmetrics_mounts_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_mounts_table_fields[]=
{
  {"device", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"mount_point", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"file_system_type", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"mount_options", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_mounts_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;

  char line[256];
  FILE* fp = fopen("/proc/stat", "r");
  char device[255], mount_point[255], file_system_type[255], mount_options[255];

  fp = fopen("/proc/mounts", "r");
  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    sscanf( line, "%s %s %s %s", device, mount_point, file_system_type, mount_options);
    table->field[0]->store(device, strlen(device), system_charset_info);
    table->field[1]->store(mount_point, strlen(mount_point), system_charset_info);
    table->field[2]->store(file_system_type, strlen(file_system_type), system_charset_info);
    table->field[3]->store(mount_options, strlen(mount_options), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }
  fclose(fp);

  return 0;
}

static int osmetrics_mounts_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_mounts_table_fields;
  schema_table->fill_table= osmetrics_mounts_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_mounts)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_mounts_table_info,      /* type-specific descriptor */
  "OS_MOUNTS",                       /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics: Filesystem Mounts",   /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_mounts_table_init,       /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
