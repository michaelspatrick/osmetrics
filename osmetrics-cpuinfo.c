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
  char line[512];
  FILE* fp = fopen("/proc/cpuinfo", "r");
  unsigned int i = 0;
  int j = 0;

  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    if (strlen(line) > 1) {
      if (strstr(line, "processor") != NULL) j=0;
      char val[256]="";
      char *pos = strchr(line, ':');
      pos = strip_newlines(pos);
      for (i=2; i< strlen(pos); i++) strncat(val, &pos[i], 1);
      table->field[j]->store(val, strlen(val), system_charset_info);
      j++;
    }
  }
  if (schema_table_store_record(thd, table)) return 1;
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
  &osmetrics_cpuinfo_table_info,     /* type-specific descriptor */
  "OS_CPUINFO",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics: CPU Info",            /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_cpuinfo_table_init,      /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
