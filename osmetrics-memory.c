#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>
//#include <includes/getmem.h>
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

static struct st_mysql_information_schema osmetrics_memory_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_memory_table_fields[]=
{
  {"NAME", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"VALUE", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"COMMENT", 75, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_memory_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  struct rusage buf;
  struct sysinfo info;
  TABLE *table= tables->table;
  char fieldname[50];
  char comment[100];

  sysinfo(&info);

  // Total usable main memory size
  strcpy(fieldname, "total_ram");
  strcpy(comment, "Total usable main memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.totalram * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available memory size
  strcpy(fieldname, "free_ram");
  strcpy(comment, "Available memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.freeram * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Used memory size
  strcpy(fieldname, "used_ram");
  strcpy(comment, "Used memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((info.totalram - info.freeram) * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available memory (percentage)
  strcpy(fieldname, "free_ram_pct");
  strcpy(comment, "Available memory as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.freeram / info.totalram * 100 * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Used memory (percentage)
  strcpy(fieldname, "used_ram_pct");
  strcpy(comment, "Free memory as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) (info.totalram - info.freeram) / info.totalram * 100 * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Amount of shared memory
  strcpy(fieldname, "shared_ram");
  strcpy(comment, "Amount of shared memory");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.sharedram * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Memory used by buffers
  strcpy(fieldname, "buffer_ram");
  strcpy(comment, "Memory used by buffers");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.bufferram * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Total high memory size
  strcpy(fieldname, "total_high_ram");
  strcpy(comment, "Total high memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.totalhigh * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available high memory size
  strcpy(fieldname, "free_high_ram");
  strcpy(comment, "Available high memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.freehigh * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Total low memory size
  strcpy(fieldname, "total_low_ram");
  strcpy(comment, "Total low memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((info.totalram - info.totalhigh) * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available low memory size
  strcpy(fieldname, "free_low_ram");
  strcpy(comment, "Available low memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((info.freeram - info.freehigh) * info.mem_unit);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // maximum resident set size
  strcpy(fieldname, "maxrss");
  strcpy(comment, "Maximum resident set size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_maxrss);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // maximum resident set size in bytes
  strcpy(fieldname, "maxrss_bytes");
  strcpy(comment, "Maximum resident set size (in bytes)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_maxrss * 1024);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  #if defined(BSD)
  // integral shared memory size - not used in Linux
  strcpy(fieldname, "ixrss");
  strcpy(comment, "Integral shared memory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_ixrss);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  #if defined(BSD)
  // integral unshared data size - not used in Linux
  strcpy(fieldname, "idrss");
  strcpy(comment, "Integral unshared data size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_idrss);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  #if defined(BSD)
  // integral unshared stack size - not used in Linux
  strcpy(fieldname, "isrss");
  strcpy(comment, "Integral unshared stack size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_isrss);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  return 0;
}

static int osmetrics_memory_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_memory_table_fields;
  schema_table->fill_table= osmetrics_memory_fill_table;
  return 0;
}

mysql_declare_plugin(os_memory)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_memory_table_info,                /* type-specific descriptor */
  "OS_MEMORY",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics Memory INFORMATION_SCHEMA table", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_memory_table_init,                 /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
