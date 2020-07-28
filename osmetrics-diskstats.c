#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>

static struct st_mysql_information_schema osmetrics_diskstats_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_diskstats_table_fields[]=
{
  {"major_num", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"minor_num", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"device", 20, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"reads_success", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"reads_merged", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"sectors_read", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"time_reads_ms", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"writes_success", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"writes_merged", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"sectors_written", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"time_writes_ms", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"ios_in_progress", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"time_doing_io_ms", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"weighted_time_doing_io_ms", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

char* strip_newlines(char* szX) {
    int i = strlen(szX);
    while('\n'==szX[--i]) szX[i] = 0;
    return szX;
}

char* strip_tabs(char* szX) {
    int i = strlen(szX);
    while('\t'==szX[--i]) szX[i] = 0;
    return szX;
}

char* uniq_spc(char* str){
    char *from, *to;
    int spc=0;
    to=from=str;
    while(1){
        if(spc && *from == ' ' && to[-1] == ' ')
            ++from;
        else {
            spc = (*from==' ')? 1 : 0;
            *to++ = *from++;
            if(!to[-1])break;
        }
    }
    return str;
}

static int osmetrics_diskstats_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;
  char line[256];
  FILE* fp = fopen("/proc/diskstats", "r");
  int major_num, minor_num;
  char device[255];
  int reads_success, reads_merged, sectors_read, time_reads_ms, writes_success, writes_merged, sectors_written, time_writes_ms, ios_in_progress, time_doing_io_ms, weighted_time_doing_io_ms;

  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    char *line2 = &line[0];
    line2 = uniq_spc(line2);
    line2 = strip_tabs(line2);
    line2 = strip_newlines(line2);

    sscanf(line2, "%d %d %s %d %d %d %d %d %d %d %d %d %d %d",
                 &major_num, &minor_num, device, &reads_success, &reads_merged, &sectors_read, &time_reads_ms, &writes_success, &writes_merged, &sectors_written, &time_writes_ms,
                 &ios_in_progress, &time_doing_io_ms, &weighted_time_doing_io_ms);

    table->field[0]->store(major_num);
    table->field[1]->store(minor_num);
    table->field[2]->store(device, strlen(device), system_charset_info);
    table->field[3]->store(reads_success);
    table->field[4]->store(reads_merged);
    table->field[5]->store(sectors_read);
    table->field[6]->store(time_reads_ms);
    table->field[7]->store(writes_success);
    table->field[8]->store(writes_merged);
    table->field[9]->store(sectors_written);
    table->field[10]->store(time_writes_ms);
    table->field[11]->store(ios_in_progress);
    table->field[12]->store(time_doing_io_ms);
    table->field[13]->store(weighted_time_doing_io_ms);
    if (schema_table_store_record(thd, table)) return 1;
  }
  fclose(fp);

  return 0;
}

static int osmetrics_diskstats_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_diskstats_table_fields;
  schema_table->fill_table= osmetrics_diskstats_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_diskstats)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_diskstats_table_info,   /* type-specific descriptor */
  "OS_DISKSTATS",                    /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics: Disk Statistics",     /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_diskstats_table_init,    /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
