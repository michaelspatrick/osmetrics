# mysql_os_metrics
A MySQL plugin for storing Operating System metrics in INFORMATION_SCHEMA.  This will allow monitoring tools, such as PMM, to retrieve these values remotely via the MySQL interface.  This is just a Proof of Concept (POC) at this point in time and needs to be expanded greatly.

Make sure you have the source code for MySQL and have done a cmake on it.  This will be necessary to compile the plugin.

I have been using the following to compile it:
SRCBASE="../percona-server-5.7.24-27"
g++ -DMYSQL_DYNAMIC_PLUGIN -Wall -fPIC -shared \
-I/usr/include/mysql -m64 \
-I${SRCBASE}/sql \
-I${SRCBASE}/include \
-I${SRCBASE}/libbinlogevents/export \
-I${SRCBASE}/libbinlogevents/include \
-I/home/michaelpatrick/osmetricsplugin \
-o osmetricsplugin.so osmetricsplugin.cc

Then copy the resulting osmetricsplugin.so file to the location of plugin_dir in MySQL.  For me, this is:
osmetricsplugin.so /usr/lib64/mysql/plugin/

Then, login to MySQL and Install the plugin with the following:
INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';

Check that the plugin exists with this:
mysql> SELECT * FROM information_schema.PLUGINS WHERE PLUGIN_NAME LIKE "%OS%";;
+-------------+----------------+---------------+--------------------+---------------------+--------------------+------------------------+-----------------+-------------------------------------+----------------+-------------+
| PLUGIN_NAME | PLUGIN_VERSION | PLUGIN_STATUS | PLUGIN_TYPE        | PLUGIN_TYPE_VERSION | PLUGIN_LIBRARY     | PLUGIN_LIBRARY_VERSION | PLUGIN_AUTHOR   | PLUGIN_DESCRIPTION                  | PLUGIN_LICENSE | LOAD_OPTION |
+-------------+----------------+---------------+--------------------+---------------------+-------------------+------------------------+-----------------+-------------------------------------+----------------+-------------+
| OS_METRICS  | 1.0            | ACTIVE        | INFORMATION SCHEMA | 50724.0             | osmetricsplugin.so | 1.7                    | Michael Patrick | OS Metrics INFORMATION_SCHEMA table | GPL            | ON          |
+-------------+----------------+---------------+--------------------+---------------------+--------------------+------------------------+-----------------+-------------------------------------+----------------+-------------+
1 row in set (0.00 sec)

To get results, the following SQL query will return metrics:
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

When you need to make changes, you may uninstall the plugin with this SQL command:
UNINSTALL PLUGIN OS_METRICS;
