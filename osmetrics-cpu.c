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
//#include <sys/statvfs.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <netdb.h>
//#include <unistd.h>
//#include <linux/if_link.h>

using namespace std;

//extern char *mysql_data_home;

static struct st_mysql_information_schema osmetrics_cpu_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_cpu_table_fields[]=
{
  {"name", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"value", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"comment", 75, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_cpu_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  struct rusage buf;
  struct sysinfo info;
  TABLE *table= tables->table;
  char fieldname[50];
  char comment[100];
  char pct[10]="";

  procstat ps;
  ps = getprocstat();
  sysinfo(&info);
  getrusage(RUSAGE_SELF, &buf);

  // CPU Num Cores
  if (ps.numcores >= 0) {
    strcpy(fieldname, "numcores");
    strcpy(comment, "Number of virtual CPU cores");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.numcores);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU Speed
  if (ps.cpu_speed >= 0) {
    strcpy(fieldname, "speed");
    strcpy(comment, "CPU speed in MHz");
    sprintf(pct, "%.3f", ps.cpu_speed);
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(atof(pct));
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU Bogomips
  if (ps.cpu_speed >= 0) {
    strcpy(fieldname, "bogomips");
    strcpy(comment, "CPU bogomips");
    sprintf(pct, "%.2f", ps.cpu_bogomips);
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(atof(pct));
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU User Time Overall
  strcpy(fieldname, "user");
  strcpy(comment, "Normal processes executing in user mode");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.user);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU Nice Time Overall
  strcpy(fieldname, "nice");
  strcpy(comment, "Niced processes executing in user mode");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.nice);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU Sys Overall
  strcpy(fieldname, "sys");
  strcpy(comment, "Processes executing in kernel mode");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.sys);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU Idle Overall
  strcpy(fieldname, "idle");
  strcpy(comment, "Processes which are idle");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.idle);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU IOWAIT Overall
  strcpy(fieldname, "iowait");
  strcpy(comment, "Processes waiting for I/O to complete");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.iowait);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU IRQ Overall
  strcpy(fieldname, "irq");
  strcpy(comment, "Processes servicing interrupts");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.irq);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU SOFTIRQ Overall
  strcpy(fieldname, "softirq");
  strcpy(comment, "Processes servicing Softirqs");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(ps.softirq);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU GUEST Overall
  if (ps.guest >= 0) {
    strcpy(fieldname, "guest");
    strcpy(comment, "Processes running a guest");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.guest);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU NICEGUEST Overall
  if (ps.guest_nice >= 0) {
    strcpy(fieldname, "guest_nice");
    strcpy(comment, "Processes running a niced guest");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.guest_nice);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU INTERRUPTS
  if (ps.intr >= 0) {
    strcpy(fieldname, "intr");
    strcpy(comment, "Count of interrupts serviced since boot time");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.intr);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU CTXT Overall
  if (ps.ctxt >= 0) {
    strcpy(fieldname, "ctxt");
    strcpy(comment, "Total number of context switches across all CPUs");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.ctxt);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU BTIME Overall
  if (ps.btime >= 0) {
    strcpy(fieldname, "btime");
    strcpy(comment, "Ttime at which the system booted, in seconds since the Unix epoch");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.btime);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU Processes Overall
  if (ps.processes >= 0) {
    strcpy(fieldname, "processes");
    strcpy(comment, "Number of processes and threads created");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.processes);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU Processes Running Overall
  if (ps.procs_running >= 0) {
    strcpy(fieldname, "procs_running");
    strcpy(comment, "Total number of threads that are running or ready to run");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.procs_running);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU Processes Blocked Overall
  if (ps.procs_blocked >= 0) {
    strcpy(fieldname, "procs_blocked");
    strcpy(comment, "Number of processes currently blocked, waiting for I/O to complete");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.procs_blocked);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU IRQ Overall
  if (ps.softirq >= 0) {
    strcpy(fieldname, "softirq");
    strcpy(comment, "Counts of softirqs serviced since boot time");
    table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
    table->field[1]->store(ps.softirq);
    table->field[2]->store(comment, strlen(comment), system_charset_info);
    if (schema_table_store_record(thd, table)) return 1;
  }

  // CPU Util Overall
  double proctimes = ( ps.user + ps.nice + ps.sys + ps.idle + ps.iowait + ps.irq + ps.softirq );
  double avg_idle_pct = (double)ps.idle * 100 / proctimes;
  sprintf(pct, "%.2f", avg_idle_pct);
  strcpy(fieldname, "idle_pct");
  strcpy(comment, "Average CPU idle time");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(atof(pct));
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // CPU Util Overall
  strcpy(fieldname, "util_pct");
  strcpy(comment, "Average CPU utilization");
  sprintf(pct, "%.2f", 100 - avg_idle_pct);
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(atof(pct));
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Number of current processes
  strcpy(fieldname, "procs");
  strcpy(comment, "Number of current processes");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(info.procs);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // user CPU time used in seconds
  strcpy(fieldname, "uptime_tv_sec");
  strcpy(comment, "User CPU time used (in seconds)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_utime.tv_sec);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // user CPU time used in microseconds
  strcpy(fieldname, "utime_tv_usec");
  strcpy(comment, "User CPU time used (in microseconds)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_utime.tv_usec);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // system CPU time used in seconds
  strcpy(fieldname, "stime_tv_sec");
  strcpy(comment, "System CPU time (in seconds)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_stime.tv_sec);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // system CPU time used in microseconds
  strcpy(fieldname, "stime_tv_usec");
  strcpy(comment, "System CPU time (in microseconds)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_stime.tv_usec);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // total user time
  strcpy(fieldname, "utime");
  strcpy(comment, "Total user time");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_utime.tv_sec + buf.ru_utime.tv_usec / (double) 1000000);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // total system time
  strcpy(fieldname, "stime");
  strcpy(comment, "Total system time");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_stime.tv_sec + buf.ru_stime.tv_usec / (double) 1000000);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // page reclaims (soft page faults)
  strcpy(fieldname, "minflt");
  strcpy(comment, "Page reclaims (soft page faults)");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_minflt);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // page faults (hard page faults)
  strcpy(fieldname, "majflt");
  strcpy(comment, "Page faults");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_majflt);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  #if defined(BSD)
  // IPC messages sent - not used in Linux
  strcpy(fieldname, "msgsnd");
  strcpy(comment, "Number of IPC messages sent");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_msgsnd);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  #if defined(BSD)
  // IPC messages received - not used in Linux
  strcpy(fieldname, "msgrcv");
  strcpy(comment, "Number of IPC messages received",);
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_msgrcv);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  #if defined(BSD)
  // signals received - not used in Linux
  strcpy(fieldname, "nsignals");
  strcpy(comment, "Number of signals received");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_nsignals);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  // voluntary context switches
  strcpy(fieldname, "nvcsw");
  strcpy(comment, "Number of voluntary context switches");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_nvcsw);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // involuntary context switches
  strcpy(fieldname, "nivcsw");
  strcpy(comment, "Number of involuntary context switches");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_nivcsw);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  return 0;
}

static int osmetrics_cpu_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_cpu_table_fields;
  schema_table->fill_table= osmetrics_cpu_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_cpu_plugin)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_cpu_table_info,           	/* type-specific descriptor */
  "OS_CPU",                          		/* table name */
  "Michael Patrick",                 		/* author */
  "OS Metrics: CPU Details",          	/* description */
  PLUGIN_LICENSE_GPL,                		/* license type */
  osmetrics_cpu_table_init,           	/* init function */
  NULL,
  0x0001,                            		/* version = 0.1 */
  NULL,                              		/* no status variables */
  NULL,                              		/* no system variables */
  NULL,                              		/* no reserved information */
  0                                  		/* no flags */
}
mysql_declare_plugin_end;
