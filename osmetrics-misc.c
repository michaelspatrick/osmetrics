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
//#include <sys/utsname.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <linux/if_link.h>

extern char *mysql_data_home;

static struct st_mysql_information_schema osmetrics_misc_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_misc_table_fields[]=
{
  {"NAME", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"VALUE", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"COMMENT", 75, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_misc_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  struct sysinfo info;
  TABLE *table= tables->table;
  struct statvfs disk;
  //struct utsname uts;
  //struct ifaddrs *ifaddr, *ifa;
  //int family, n;
  char fieldname[50];
  char comment[100];

  procstat ps;
  ps = getprocstat();

  sysinfo(&info);
  statvfs(mysql_data_home, &disk);

  // Datadir Size
  strcpy(fieldname, "datadir_size");
  strcpy(comment, "MySQL data directory size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(disk.f_blocks * disk.f_frsize);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Datadir Size Free
  strcpy(fieldname, "datadir_size_free");
  strcpy(comment, "MySQL data directory size free space");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(disk.f_bfree * disk.f_frsize);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Datadir Size Used
  strcpy(fieldname, "datadir_size_used");
  strcpy(comment, "MySQL data directory size used space");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((disk.f_blocks * disk.f_frsize) - (disk.f_bfree * disk.f_frsize));
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Datadir Size Used Percentage
  strcpy(fieldname, "datadir_size_used_pct");
  strcpy(comment, "MySQL data directory used space as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(((double) ((disk.f_blocks * disk.f_frsize) - (disk.f_bfree * disk.f_frsize)) / (double) (disk.f_blocks * disk.f_frsize)) * (double) 100);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Seconds since boot
  strcpy(fieldname, "uptime");
  strcpy(comment, "Uptime (in seconds)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.uptime);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Uptime since boot in days
  strcpy(fieldname, "uptime_days");
  strcpy(comment, "Uptime (in days)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.uptime / (60 * 60 * 24));
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Uptime since boot in hours
  strcpy(fieldname, "uptime_hours");
  strcpy(comment, "Uptime (in hours)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.uptime / (60 * 60));
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Number of current processes
  strcpy(fieldname, "procs");
  strcpy(comment, "Number of current processes");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.procs);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  //char line[256];
  FILE* fp = fopen("/proc/sys/vm/swappiness", "r");
  int swappiness;
  assert(fp != NULL);
  //while (fgets(line, sizeof(line), fp)) {
    //sscanf( line, "%d", swappiness);
    strcpy(comment, "Swappiness setting");
    fscanf( fp, "%d", &swappiness);
    table->field[0]->store("swappiness", strlen("swappiness"), system_charset_info);
    table->field[1]->store((int)swappiness);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  //}
  fclose(fp);

  return 0;
}

static int osmetrics_misc_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_misc_table_fields;
  schema_table->fill_table= osmetrics_misc_fill_table;
  return 0;
}

mysql_declare_plugin(os_metrics)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_misc_table_info,                /* type-specific descriptor */
  "OS_MISC",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics Misc INFORMATION_SCHEMA table", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_misc_table_init,                 /* init function */
  NULL,
  0x0100,                            /* version = 1.0 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
