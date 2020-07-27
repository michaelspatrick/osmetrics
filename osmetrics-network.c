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
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <linux/if_link.h>

extern char *mysql_data_home;

static struct st_mysql_information_schema osmetrics_network_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_network_table_fields[]=
{
  {"interface", 25, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"tx_packets", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rx_packets", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"tx_bytes", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rx_bytes", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"tx_dropped", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rx_dropped", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"tx_errors", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rx_errors", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int osmetrics_network_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;
  struct ifaddrs *ifaddr, *ifa;
  int family, n;

  // Network Statistics
  if (getifaddrs(&ifaddr) != -1) {
    // Loop through each network interface
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
      if (ifa->ifa_addr == NULL) continue;
      family = ifa->ifa_addr->sa_family;
      if (family == AF_PACKET && ifa->ifa_data != NULL) {
        struct rtnl_link_stats *stats = (struct rtnl_link_stats *)ifa->ifa_data;
        table->field[0]->store(ifa->ifa_name, strlen(ifa->ifa_name), system_charset_info);
        table->field[1]->store(stats->tx_packets);
        table->field[2]->store(stats->rx_packets);
        table->field[3]->store(stats->tx_bytes);
        table->field[4]->store(stats->rx_bytes);
        table->field[5]->store(stats->tx_dropped);
        table->field[6]->store(stats->rx_dropped);
        table->field[7]->store(stats->tx_dropped);
        table->field[8]->store(stats->rx_dropped);
        if (schema_table_store_record(thd, table)) return 1;
      }
    }
  }
  freeifaddrs(ifaddr);

  return 0;
}

static int osmetrics_network_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_network_table_fields;
  schema_table->fill_table= osmetrics_network_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_network)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_network_table_info,                 /* type-specific descriptor */
  "OS_NETWORK",                                  /* table name */
  "Michael Patrick",                             /* author */
  "OS Metrics: Network Stats",                   /* description */
  PLUGIN_LICENSE_GPL,                            /* license type */
  osmetrics_network_table_init,                  /* init function */
  NULL,
  0x0001,                                        /* version = 0.1 */
  NULL,                                          /* no status variables */
  NULL,                                          /* no system variables */
  NULL,                                          /* no reserved information */
  0                                              /* no flags */
}
mysql_declare_plugin_end;
