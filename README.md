# mysql_os_metrics
A MySQL plugin for storing Operating System metrics in INFORMATION_SCHEMA.  This will allow monitoring tools, such as PMM, to retrieve these values remotely via the MySQL interface.  This is just a Proof of Concept (POC) at this point in time and needs to be expanded greatly.

Make sure you have the source code for MySQL and have done a cmake on it.  This will be necessary to compile the plugin.

#### Compiling the Plugin
Below is the way that I compiled the plugin.  You will obviously need to make changes to match your environment.

    SRCBASE="../percona-server-5.7.24-27"
    g++ -DMYSQL_DYNAMIC_PLUGIN -Wall -fPIC -shared \
    -I/usr/include/mysql -m64 \
    -I${SRCBASE}/sql \
    -I${SRCBASE}/include \
    -I${SRCBASE}/libbinlogevents/export \
    -I${SRCBASE}/libbinlogevents/include \
    -I/home/michaelpatrick/osmetricsplugin \
    -o osmetricsplugin.so osmetricsplugin.cc

#### Plugin Installation
Copy the resulting osmetricsplugin.so file to the location of plugin_dir in MySQL.

    cp osmetricsplugin.so /usr/lib64/mysql/plugin/

    mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';

#### Verify Installation
    mysql> SELECT * FROM information_schema.PLUGINS WHERE PLUGIN_NAME LIKE "%OS%";;
    +-------------+----------------+---------------+--------------------+---------------------+--------------------+------------------------+-----------------+-------------------------------------+----------------+-------------+
    | PLUGIN_NAME | PLUGIN_VERSION | PLUGIN_STATUS | PLUGIN_TYPE        | PLUGIN_TYPE_VERSION | PLUGIN_LIBRARY     | PLUGIN_LIBRARY_VERSION | PLUGIN_AUTHOR   | PLUGIN_DESCRIPTION                  | PLUGIN_LICENSE | LOAD_OPTION |
    +-------------+----------------+---------------+--------------------+---------------------+-------------------+------------------------+-----------------+-------------------------------------+----------------+-------------+
    | OS_METRICS  | 1.0            | ACTIVE        | INFORMATION SCHEMA | 50724.0             | osmetricsplugin.so | 1.7                    | Michael Patrick | OS Metrics INFORMATION_SCHEMA table | GPL            | ON          |
    +-------------+----------------+---------------+--------------------+---------------------+--------------------+------------------------+-----------------+-------------------------------------+----------------+-------------+
    1 row in set (0.00 sec)

#### Query the Plugin
    mysql> SELECT * FROM information_schema.OS_METRICS;
    +----------------+-------------------+----------------------------------------+
    | NAME           | VALUE             | COMMENT                                |
    +----------------+-------------------+----------------------------------------+
    | TOTAL_RAM      |        1039118336 | Total usable main memory size          |
    | FREE_RAM       |         341049344 | Available memory size                  |
    | USED_RAM       |         698068992 | Used memory size                       |
    | FREE_RAM_PCT   | 32.82102966308594 | Available memory as a percentage       |
    | USED_RAM_PCT   | 67.17897033691406 | Free memory as a percentage            |
    | SHARED_RAM     |                 0 | Amount of shared memory                |
    | BUFFER_RAM     |           2158592 | Memory used by buffers                 |
    | TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
    | FREE_HIGH_RAM  |                 0 | Available high memory size             |
    | TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
    | FREE_LOW_RAM   |         341049344 | Available low memory size              |
    | LOAD_1MIN      |      0.0029296875 | 1 minute load average                  |
    | LOAD_5MIN      |      0.0146484375 | 5 minute load average                  |
    | LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
    | UPTIME         |             23410 | Uptime (in seconds)                    |
    | UPTIME_DAYS    |                 0 | Uptime (in days)                       |
    | UPTIME_HOURS   |                 6 | Uptime (in hours)                      |
    | TOTAL_SWAP     |         859828224 | Total swap space size                  |
    | FREE_SWAP      |         859828224 | Swap space available                   |
    | USED_SWAP      |                 0 | Swap space used                        |
    | FREE_SWAP_PCT  |               100 | Swap space available as a percentage   |
    | USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
    | PROCS          |               138 | Number of current processes            |
    | UTIME          |          1.654309 | Total user time                        |
    | STIME          |          0.550062 | Total system time                      |
    | MAXRSS         |            199372 | Maximum resident set size              |
    | MAXRSS_BYTES   |         204156928 | Maximum resident set size (in bytes)   |
    | MINFLT         |             23438 | Page reclaims (soft page faults)       |
    | MAJFLT         |                 0 | Page faults                            |
    | INBLOCK        |              7680 | Number of block input operations       |
    | OUBLOCK        |             33592 | Number of block output operations      |
    | NVCSW          |             42043 | Number of voluntary context switches   |
    | NIVCSW         |                38 | Number of involuntary context switches |
    +----------------+-------------------+----------------------------------------+
    33 rows in set (0.00 sec)

#### Plugin Uninstallation
    mysql> UNINSTALL PLUGIN OS_METRICS;
    
#### Future Additions
Below are some ideas for possible additions.
* Swappiness Setting
* CPU Utilization
* Datadir Disk Usage (Space used, remaining, etc.)
* Some data in iostat and vmstat (key metrics)
* I/O Scheduler Setting & other OS metrics (maybe useful for checking without having to login to terminal)
* And more...
