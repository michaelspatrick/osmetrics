#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <ctype.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>

#include <includes/getmem.h>
#include <includes/getload.h>

static struct st_mysql_information_schema simple_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO simple_table_fields[]=
{
  {"NAME", 15, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"VALUE", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int simple_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  double *load;

  TABLE *table= tables->table;

  table->field[0]->store("MEMORY_TOTAL", 12, system_charset_info);
  table->field[1]->store(getMemorySize());
  if (schema_table_store_record(thd, table)) return 1;

  table->field[0]->store("LOADAVG_1MIN", 12, system_charset_info);
  load = getLoadAvg();
  table->field[1]->store(load[0]);
  if (schema_table_store_record(thd, table)) return 1;

  table->field[0]->store("LOADAVG_5MIN", 12, system_charset_info);
  load = getLoadAvg();
  table->field[1]->store(load[1]);
  if (schema_table_store_record(thd, table)) return 1;

  table->field[0]->store("LOADAVG_15MIN", 13, system_charset_info);
  load = getLoadAvg();
  table->field[1]->store(load[2]);
  if (schema_table_store_record(thd, table)) return 1;
  
  return 0;
}

static int simple_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;

  schema_table->fields_info= simple_table_fields;
  schema_table->fill_table= simple_fill_table;
  return 0;
}


mysql_declare_plugin(os_metrics)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &simple_table_info,                /* type-specific descriptor */
  "OS_METRICS",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics INFORMATION_SCHEMA table", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  simple_table_init,                 /* init function */
  NULL,
  0x0100,                            /* version = 1.0 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
