#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
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

static struct st_mysql_information_schema osmetrics_cpuinfo_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_cpuinfo_table_fields[]=
{
  {"name", 40, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 1100, MYSQL_TYPE_STRING, 0, 0, 0, 0},
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

static int osmetrics_cpuinfo_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;
  char line[256];
  FILE* fp = fopen("/proc/cpuinfo", "r");
  char *token;
  //char name[255], val[255];

  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    token = strtok(line, ":");
    token = uniq_spc(token);
    token = strip_tabs(token);
    token = strip_newlines(token);
if (strlen(token) > 1) {
    table->field[0]->store(token, strlen(token), system_charset_info);
    while (token != NULL) {
      token = strip_newlines(token);
      token = uniq_spc(token);
      token = strip_tabs(token);
      token = strip_newlines(token);
      table->field[1]->store(token, strlen(token), system_charset_info);
      token = strtok(NULL, ":");
    }
    if (schema_table_store_record(thd, table)) return 1;
}
  }
  fclose(fp);

  return 0;
}

static int osmetrics_cpuinfo_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_cpuinfo_table_fields;
  schema_table->fill_table= osmetrics_cpuinfo_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_cpuinfo)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_cpuinfo_table_info,                /* type-specific descriptor */
  "OS_CPUINFO",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS metrics from /proc/cpuinfo", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_cpuinfo_table_init,                 /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
