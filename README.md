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
    +---------------+------------+
    | NAME          | VALUE      |
    +---------------+------------+
    | MEMORY_TOTAL  | 1040621568 |
    | LOADAVG_1MIN  |       0.12 |
    | LOADAVG_5MIN  |       0.05 |
    | LOADAVG_15MIN |       0.06 |
    +---------------+------------+
    4 rows in set (0.00 sec)

#### Plugin Uninstallation
    mysql> UNINSTALL PLUGIN OS_METRICS;
    
#### Future Additions
Below are some ideas for possible additions.
* Swappiness Setting
* Swap Usage
* Memory Used
* Memory Free
* CPU Utilization
* Datadir Disk Usage (Space used, remaining, etc.)
* Some data in iostat and vmstat (key metrics)
* I/O Scheduler Setting & other OS metrics (maybe useful for checking without having to login to terminal)
* And more...
