#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <ctype.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>
//#include <includes/getmem.h>
//#include <includes/getload.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

extern char *mysql_data_home;

static struct st_mysql_information_schema simple_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO simple_table_fields[]=
{
  {"NAME", 15, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"VALUE", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"COMMENT", 50, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int simple_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  //double *load;
  struct rusage buf;
  struct sysinfo info;
  TABLE *table= tables->table;
  
  //load = getLoadAvg();  /* pulls from a separate library but changed to doing natively */
  sysinfo(&info);
  getrusage(RUSAGE_SELF, &buf);
  statvfs(mysql_data_home, &disk);
  
  // Datadir Size
  table->field[0]->store("DATADIR_SIZE", 13, system_charset_info);
  table->field[1]->store(disk.f_blocks * disk.f_frsize);
  table->field[2]->store("MySQL data directory size", 25, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Datadir Size Free
  table->field[0]->store("DATADIR_SIZE_FREE", 18, system_charset_info);
  table->field[1]->store(disk.f_bfree * disk.f_frsize);
  table->field[2]->store("MySQL data directory size free space", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Datadir Size Used
  table->field[0]->store("DATADIR_SIZE_USED", 18, system_charset_info);
  table->field[1]->store((disk.f_blocks * disk.f_frsize) - (disk.f_bfree * disk.f_frsize));
  table->field[2]->store("MySQL data directory size used space", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Datadir Size Used Percentage
  table->field[0]->store("DATADIR_SIZE_USED_PCT", 22, system_charset_info);
  table->field[1]->store(((double) ((disk.f_blocks * disk.f_frsize) - (disk.f_bfree * disk.f_frsize)) / (double) (disk.f_blocks * disk.f_frsize)) * (double) 100);
  table->field[2]->store("MySQL data directory used space as a percentage", 47, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Total RAM - works for various OS
  //table->field[0]->store("MEMORY_TOTAL", 12, system_charset_info);
  //table->field[1]->store(getMemorySize());
  //table->field[2]->store("Total RAM", 9, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // Total usable main memory size
  table->field[0]->store("TOTAL_RAM", 9, system_charset_info);
  table->field[1]->store(info.totalram * info.mem_unit);
  table->field[2]->store("Total usable main memory size", 29, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Available memory size
  table->field[0]->store("FREE_RAM", 8, system_charset_info);
  table->field[1]->store(info.freeram * info.mem_unit);
  table->field[2]->store("Available memory size", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Used memory size
  table->field[0]->store("USED_RAM", 8, system_charset_info);
  table->field[1]->store((info.totalram - info.freeram) * info.mem_unit);
  table->field[2]->store("Used memory size", 16, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Available memory (percentage)
  table->field[0]->store("FREE_RAM_PCT", 12, system_charset_info);
  table->field[1]->store((float) info.freeram / info.totalram * 100 * info.mem_unit);
  table->field[2]->store("Available memory as a percentage", 32, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Used memory (percentage)
  table->field[0]->store("USED_RAM_PCT", 12, system_charset_info);
  table->field[1]->store((float) (info.totalram - info.freeram) / info.totalram * 100 * info.mem_unit);
  table->field[2]->store("Free memory as a percentage", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Amount of shared memory
  table->field[0]->store("SHARED_RAM", 10, system_charset_info);
  table->field[1]->store(info.sharedram * info.mem_unit);
  table->field[2]->store("Amount of shared memory", 23, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Memory used by buffers
  table->field[0]->store("BUFFER_RAM", 10, system_charset_info);
  table->field[1]->store(info.bufferram * info.mem_unit);
  table->field[2]->store("Memory used by buffers", 22, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Total high memory size
  table->field[0]->store("TOTAL_HIGH_RAM", 14, system_charset_info);
  table->field[1]->store(info.totalhigh * info.mem_unit);
  table->field[2]->store("Total high memory size", 22, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Available high memory size
  table->field[0]->store("FREE_HIGH_RAM", 13, system_charset_info);
  table->field[1]->store(info.freehigh * info.mem_unit);
  table->field[2]->store("Available high memory size", 26, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Total low memory size
  table->field[0]->store("TOTAL_LOW_RAM", 13, system_charset_info);
  table->field[1]->store((info.totalram - info.totalhigh) * info.mem_unit);
  table->field[2]->store("Total low memory size", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Available low memory size
  table->field[0]->store("FREE_LOW_RAM", 12, system_charset_info);
  table->field[1]->store((info.freeram - info.freehigh) * info.mem_unit);
  table->field[2]->store("Available low memory size", 25, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Load 1 Minute Average - uses getload.h
  //table->field[0]->store("LOADAVG_1MIN", 12, system_charset_info);
  //table->field[1]->store(load[0]);
  //table->field[2]->store("Load average over 1 minute", 26, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // Load 5 Minute Average - uses getload.h
  //table->field[0]->store("LOADAVG_5MIN", 12, system_charset_info);
  //table->field[1]->store(load[1]);
  //table->field[2]->store("Load average over 5 minutes", 28, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // Load 15 Minute Average - uses getload.h
  //table->field[0]->store("LOADAVG_15MIN", 13, system_charset_info);
  //table->field[1]->store(load[2]);
  //table->field[2]->store("Load average over 15 minutes", 29, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // 1 minute load average
  table->field[0]->store("LOAD_1MIN", 9, system_charset_info);
  table->field[1]->store((float) info.loads[0] / 65536);
  table->field[2]->store("1 minute load average", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // 5 minute load average
  table->field[0]->store("LOAD_5MIN", 9, system_charset_info);
  table->field[1]->store((float) info.loads[1] / 65536);
  table->field[2]->store("5 minute load average", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // 15 minute load average
  table->field[0]->store("LOAD_15MIN", 10, system_charset_info);
  table->field[1]->store((float) info.loads[2] / 65536);
  table->field[2]->store("15 minute load average", 22, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Seconds since boot
  table->field[0]->store("UPTIME", 6, system_charset_info);
  table->field[1]->store(info.uptime);
  table->field[2]->store("Uptime (in seconds)", 19, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Uptime since boot in days
  table->field[0]->store("UPTIME_DAYS", 11, system_charset_info);
  table->field[1]->store(info.uptime / (60 * 60 * 24));
  table->field[2]->store("Uptime (in days)", 16, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Uptime since boot in hours
  table->field[0]->store("UPTIME_HOURS", 12, system_charset_info);
  table->field[1]->store(info.uptime / (60 * 60));
  table->field[2]->store("Uptime (in hours)", 17, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Total swap space size
  table->field[0]->store("TOTAL_SWAP", 10, system_charset_info);
  table->field[1]->store(info.totalswap);
  table->field[2]->store("Total swap space size", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // swap space still available
  table->field[0]->store("FREE_SWAP", 10, system_charset_info);
  table->field[1]->store(info.freeswap);
  table->field[2]->store("Swap space available", 20, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // swap space used
  table->field[0]->store("USED_SWAP", 10, system_charset_info);
  table->field[1]->store(info.totalswap - info.freeswap);
  table->field[2]->store("Swap space used", 15, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // swap space still available (percentage)
  table->field[0]->store("FREE_SWAP_PCT", 14, system_charset_info);
  table->field[1]->store(info.freeswap / info.totalswap * 100);
  table->field[2]->store("Swap space available as a percentage", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // swap space used (percentage)
  table->field[0]->store("USED_SWAP_PCT", 14, system_charset_info);
  table->field[1]->store((info.totalswap - info.freeswap) / info.totalswap * 100);
  table->field[2]->store("Swap space used as a percentage", 31, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // Number of current processes
  table->field[0]->store("PROCS", 5, system_charset_info);
  table->field[1]->store(info.procs);
  table->field[2]->store("Number of current processes", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // user CPU time used in seconds
  //table->field[0]->store("UTIME_TV_SEC", 12, system_charset_info);
  //table->field[1]->store(buf.ru_utime.tv_sec);
  //table->field[2]->store("User CPU time used (in seconds)", 30, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // user CPU time used in microseconds
  //table->field[0]->store("UTIME_TV_USEC", 13, system_charset_info);
  //table->field[1]->store(buf.ru_utime.tv_usec);
  //table->field[2]->store("User CPU time used (in microseconds)", 36, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // system CPU time used in seconds
  //table->field[0]->store("STIME_TV_SEC", 12, system_charset_info);
  //table->field[1]->store(buf.ru_stime.tv_sec);
  //table->field[2]->store("System CPU time (in seconds)", 29, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // system CPU time used in microseconds
  //table->field[0]->store("STIME_TV_USEC", 13, system_charset_info);
  //table->field[1]->store(buf.ru_stime.tv_usec);
  //table->field[2]->store("System CPU time (in microseconds)", 33, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
  // total user time
  table->field[0]->store("UTIME", 5, system_charset_info);
  table->field[1]->store(buf.ru_utime.tv_sec + buf.ru_utime.tv_usec / (double) 1000000);
  table->field[2]->store("Total user time", 15, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // total system time
  table->field[0]->store("STIME", 5, system_charset_info);
  table->field[1]->store(buf.ru_stime.tv_sec + buf.ru_stime.tv_usec / (double) 1000000);
  table->field[2]->store("Total system time", 17, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // maximum resident set size
  table->field[0]->store("MAXRSS", 6, system_charset_info);
  table->field[1]->store(buf.ru_maxrss);
  table->field[2]->store("Maximum resident set size", 25, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // maximum resident set size in bytes
  table->field[0]->store("MAXRSS_BYTES", 12, system_charset_info);
  table->field[1]->store(buf.ru_maxrss * 1024);
  table->field[2]->store("Maximum resident set size (in bytes)", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #if defined(BSD)
  
  // integral shared memory size - not used in Linux
  table->field[0]->store("IXRSS",5, system_charset_info);
  table->field[1]->store(buf.ru_ixrss);
  table->field[2]->store("Integral shared memory size", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  #if defined(BSD)
  // integral unshared data size - not used in Linux
  table->field[0]->store("IDRSS", 5, system_charset_info);
  table->field[1]->store(buf.ru_idrss);
  table->field[2]->store("Integral unshared data size", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  #if defined(BSD)
  // integral unshared stack size - not used in Linux
  table->field[0]->store("ISRSS", 5, system_charset_info);
  table->field[1]->store(buf.ru_isrss);
  table->field[2]->store("Integral unshared stack size", 28, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  // page reclaims (soft page faults)
  table->field[0]->store("MINFLT", 6, system_charset_info);
  table->field[1]->store(buf.ru_minflt);
  table->field[2]->store("Page reclaims (soft page faults)", 32, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // page faults (hard page faults)
  table->field[0]->store("MAJFLT", 6, system_charset_info);
  table->field[1]->store(buf.ru_majflt);
  table->field[2]->store("Page faults", 11, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  #if defined(BSD)
  // swaps - not used in Linux
  table->field[0]->store("NSWAP", 5, system_charset_info);
  table->field[1]->store(buf.ru_nswap);
  table->field[2]->store("Number of swaps", 15, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  // block input operations
  table->field[0]->store("INBLOCK", 7, system_charset_info);
  table->field[1]->store(buf.ru_inblock);
  table->field[2]->store("Number of block input operations", 32, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // block output operations
  table->field[0]->store("OUBLOCK", 7, system_charset_info);
  table->field[1]->store(buf.ru_oublock);
  table->field[2]->store("Number of block output operations", 33, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  #if defined(BSD)
  // IPC messages sent - not used in Linux
  table->field[0]->store("MSGSND", 6, system_charset_info);
  table->field[1]->store(buf.ru_msgsnd);
  table->field[2]->store("Number of IPC messages sent", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  #if defined(BSD)
  // IPC messages received - not used in Linux
  table->field[0]->store("MSGRCV", 6, system_charset_info);
  table->field[1]->store(buf.ru_msgrcv);
  table->field[2]->store("Number of IPC messages received", 31, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  #if defined(BSD)
  // signals received - not used in Linux
  table->field[0]->store("NSIGNALS", 8, system_charset_info);
  table->field[1]->store(buf.ru_nsignals);
  table->field[2]->store("Number of signals received", 26, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  // voluntary context switches
  table->field[0]->store("NVCSW", 5, system_charset_info);
  table->field[1]->store(buf.ru_nvcsw);
  table->field[2]->store("Number of voluntary context switches", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
  // involuntary context switches
  table->field[0]->store("NIVCSW", 6, system_charset_info);
  table->field[1]->store(buf.ru_nivcsw);
  table->field[2]->store("Number of involuntary context switches", 38, system_charset_info);
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
