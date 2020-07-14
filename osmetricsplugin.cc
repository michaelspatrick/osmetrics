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
//#include <includes/getload.h>
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

static struct st_mysql_information_schema simple_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO simple_table_fields[]=
{
  {"NAME", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
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
  struct statvfs disk;
  //struct utsname uts;
  struct ifaddrs *ifaddr, *ifa;
  int family, n;
  char fieldname[50];
  char comment[100];

  //load = getLoadAvg();  /* pulls from a separate library but changed to doing natively */
  sysinfo(&info);
  getrusage(RUSAGE_SELF, &buf);
  statvfs(mysql_data_home, &disk);
  //uname(&uts);

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

  // 1 minute load average
  strcpy(fieldname, "load_1min");
  strcpy(comment, "1 minute load average");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.loads[0] / 65536);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // 5 minute load average
  strcpy(fieldname, "load_5min");
  strcpy(comment, "5 minute load average");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.loads[1] / 65536);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // 15 minute load average
  strcpy(fieldname, "load_15min");
  strcpy(comment, "15 minute load average");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store((float) info.loads[2] / 65536);
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

  // Total swap space size
  strcpy(fieldname, "total_swap");
  strcpy(comment, "Total swap space size");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if (info.totalswap >= 0) {
    table->field[1]->store(info.totalswap);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space still available
  strcpy(fieldname, "free_swap");
  strcpy(comment, "Swap space available");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if (info.freeswap >= 0) {
    table->field[1]->store(info.freeswap);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space used
  strcpy(fieldname, "used_swap");
  strcpy(comment, "Swap space used");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if ((info.freeswap >= 0) && (info.totalswap > 0)) {
    table->field[1]->store(info.totalswap - info.freeswap);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space still available (percentage)
  strcpy(fieldname, "free_swap_pct");
  strcpy(comment, "Swap space available as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if ((info.freeswap >= 0) && (info.totalswap > 0)) {
    table->field[1]->store(info.freeswap / info.totalswap * 100);
  }
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space used (percentage)
  strcpy(fieldname, "used_swap_pct");
  strcpy(comment, "Swap space used as a percentage");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  if ((info.freeswap >= 0) && (info.totalswap > 0)) {
    table->field[1]->store((info.totalswap - info.freeswap) / info.totalswap * 100);
  }
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
  // swaps - not used in Linux
  strcpy(fieldname, "nswap");
  strcpy(comment, "Number of swaps");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_nswap);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  // block input operations
  strcpy(fieldname, "inblock");
  strcpy(comment, "Number of block input operations");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_inblock);
  table->field[2]->store(comment, strlen(comment), system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // block output operations
  strcpy(fieldname, "oublock");
  strcpy(comment, "Number of block output operations");
  table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
  table->field[1]->store(buf.ru_oublock);
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

  // Network Statistics
  if (getifaddrs(&ifaddr) != -1) {
    // Loop through each network interface
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
      if (ifa->ifa_addr == NULL) continue;
      family = ifa->ifa_addr->sa_family;

      if (family == AF_PACKET && ifa->ifa_data != NULL) {
        struct rtnl_link_stats *stats = (struct rtnl_link_stats *)ifa->ifa_data;

        // Network packets sent
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_tx_packets");
        strcpy(comment, "Number of network packets sent");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->tx_packets);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Network packets received
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_rx_packets");
        strcpy(comment, "Number of network packets received");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->rx_packets);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Network bytes sent
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_tx_bytes");
        strcpy(comment, "Number of bytes sent over the network interface");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->tx_bytes);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Network bytes received
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_rx_bytes");
        strcpy(comment, "Number of bytes received over the network interface");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->rx_bytes);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Received network packets dropped
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_tx_dropped");
        strcpy(comment, "Number of received network packets dropped");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->tx_dropped);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Sent network packets dropped
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_rx_dropped");
        strcpy(comment, "Number of sent network packets dropped");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->rx_dropped);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Received network errors
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_tx_errors");
        strcpy(comment, "Number of errors on received packets");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->tx_dropped);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;

        // Sent network errors
        strcpy(fieldname, ifa->ifa_name);
        strcat(fieldname, "_rx_errors");
        strcpy(comment, "Number of errors on sent packets");
        table->field[0]->store(fieldname, strlen(fieldname), system_charset_info);
        table->field[1]->store(stats->rx_dropped);
        table->field[2]->store(comment, strlen(comment), system_charset_info);
        if (schema_table_store_record(thd, table)) return 1;
      }
    }
  }
  freeifaddrs(ifaddr);

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
