#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>

static struct st_mysql_information_schema osmetrics_vmstat_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_vmstat_table_fields[]=
{
  {"name", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_vmstat_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;

  char line[256];
  FILE* fp = fopen("/proc/vmstat", "r");
  char name[255];
  char val[255];

  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    sscanf( line, "%s %s", name, val);
    table->field[0]->store(name, strlen(name), system_charset_info);
    table->field[1]->store(atoi(val));
    if (schema_table_store_record(thd, table)) return 1;
  }
  fclose(fp);

  return 0;
}

static int osmetrics_vmstat_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_vmstat_table_fields;
  schema_table->fill_table= osmetrics_vmstat_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_vmstat)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_vmstat_table_info,       /* type-specific descriptor */
  "OS_VMSTAT",                        /* table name */
  "Michael Patrick",                  /* author */
  "OS Metrics: Vmstat Info",          /* description */
  PLUGIN_LICENSE_GPL,                 /* license type */
  osmetrics_vmstat_table_init,        /* init function */
  NULL,
  0x0001,                             /* version = 0.1 */
  NULL,                               /* no status variables */
  NULL,                               /* no system variables */
  NULL,                               /* no reserved information */
  0                                   /* no flags */
}
mysql_declare_plugin_end;
