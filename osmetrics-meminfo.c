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

static struct st_mysql_information_schema osmetrics_meminfo_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_meminfo_table_fields[]=
{
  {"name", 50, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 20, MYSQL_TYPE_STRING, 0, 0, 0, 0},
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

void ltrim(char *src) {
  char *dst;
  for (dst=src; *src == ' '; src++) {;}
  if (dst==src) return;
  while ((*dst++ = *src++)) {;}
  return;
}

int strpos(char *haystack, char *needle)
{
   char *p = strstr(haystack, needle);
   if (p)
      return p - haystack;
   return -1;   // Not found = -1.
}

static int osmetrics_meminfo_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;
  char line[512];
  FILE* fp = fopen("/proc/meminfo", "r");
  int i = 0;

  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    if (strlen(line) > 1) {
      char val[256]="";
      char fieldname[256]="";
      char *pos = strchr(line, ':');
      pos = strip_newlines(pos);
      pos = uniq_spc(pos);
      int colonpos = strpos(line, (char *)":");

      for (i=0; i<colonpos; i++) strncat(fieldname, &line[i], 1);
      for (i=2; (unsigned int)i< strlen(pos); i++) strncat(val, &pos[i], 1);

      table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
      table->field[1]->store(val, strlen(val), system_charset_info);
      if (schema_table_store_record(thd, table)) return 1;
    }
  }
  fclose(fp);
  return 0;
}

static int osmetrics_meminfo_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_meminfo_table_fields;
  schema_table->fill_table= osmetrics_meminfo_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_meminfo)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_meminfo_table_info,                /* type-specific descriptor */
  "OS_MEMINFO",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS metrics from /proc/meminfo", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_meminfo_table_init,                 /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
