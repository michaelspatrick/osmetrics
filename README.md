# mysql_os_metrics
A MySQL plugin for displaying Operating System metrics in INFORMATION_SCHEMA.  This would allow monitoring tools, such as PMM, to retrieve these values remotely via the MySQL interface.  This is just a Proof of Concept (POC) at this point in time and needs to be expanded greatly.

Values are pulled via standard C library calls so overhead is absolutely minimal.  I added a couple of libraries originally to show that even Windows and other variants of UNIX can be utilized, but commented them out to keep it all simple for now.

Many variables were added to show what was possible.  Some of these may not be of interest.  I just wanted to see what kind of stuff was possible and would tweak these over time.  

Also, none of the calculations were rounded.  This was done just to keep precision for graphing of values but could easily be canged later.

If there is interest, this could be expanded to add more metrics and unnecessary ones removed.  Just looking for feedback.

Also keep in mind that my C programming skills are rusty and I am sure the code could be cleaned up.

Make sure you have the source code for MySQL and have done a cmake on it.  This will be necessary to compile the plugin.

#### Compiling the Plugin
Below is the way that I compiled the plugin.  You will obviously need to make changes to match your environment.
You will also need to have the Percona Server source code on your server:

    wget https://www.percona.com/downloads/Percona-Server-5.7/Percona-Server-5.7.17-13/source/tarball/percona-server-5.7.17-13.tar.gz

I also had to add a few utilities:

    sudo yum install cmake
    sudo yum install boost
    sudo yum install ncurses-devel
    sudo yum install readline-devel
    cmake -DDOWNLOAD_BOOST=1 -DWITH_BOOST=.. 

Once the above was complete, you need to edit the Makefile and then compile:

    make clean
    make
    make install
    
#### Plugin Installation
You will need to know where your plugin directory is.  You can query that with the following SQL:

    mysql> SHOW GLOBAL VARIABLES LIKE "%plugin_dir%";
    +---------------+-------------------------+
    | Variable_name | Value                   |
    +---------------+-------------------------+
    | plugin_dir    | /jet/var/mysqld/plugin/ |
    +---------------+-------------------------+
    1 row in set (0.01 sec)

You will need to edit the Makefile and define this path there.

Finally, you can login to MySQL and activate the plugin:

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
    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_METRICS;
    +-----------------------+----------------------+--------------------------------------------------------------------+    
    | NAME                  | VALUE                | COMMENT                                                            |
    +-----------------------+----------------------+--------------------------------------------------------------------+
    | cpu_numcores          |                    1 | Number of virtual CPU cores                                        |
    | cpu_speed             |     2300.01708984375 | CPU speed in MHz                                                   |
    | cpu_bogomips          |     4600.10986328125 | CPU bogomips                                                       |
    | cpu_user              |                   31 | Normal processes executing in user mode                            |
    | cpu_nice              |                 8555 | Niced processes executing in user mode                             |
    | cpu_sys               |              4331824 | Processes executing in kernel mode                                 |
    | cpu_idle              |                 1600 | Processes which are idle                                           |
    | cpu_iowait            |                    0 | Processes waiting for I/O to complete                              |
    | cpu_irq               |                   26 | Processes servicing interrupts                                     |
    | cpu_softirq           |                 1387 | Processes servicing Softirqs                                       |
    | cpu_guest             |                    0 | Processes running a guest                                          |
    | cpu_guest_nice        |                    0 | Processes running a niced guest                                    |
    | cpu_intr              |              1136775 | Count of interrupts serviced since boot time                       |
    | cpu_ctxt              |              4217435 | Total number of context switches across all CPUs                   |
    | cpu_btime             |           1594829433 | Ttime at which the system booted, in seconds since the Unix epoch  |
    | cpu_processes         |                11246 | Number of processes and threads created                            |
    | cpu_procs_running     |                    2 | Total number of threads that are running or ready to run           |
    | cpu_procs_blocked     |                    0 | Number of processes currently blocked, waiting for I/O to complete |
    | cpu_softirq           |                 1387 | Counts of softirqs serviced since boot time                        |
    | cpu_idle_pct          | 0.036837305507660664 | Average CPU idle time                                              |
    | cpu_util_pct          |    99.96316269449234 | Average CPU utilization                                            |
    | datadir_size          |           8318783488 | MySQL data directory size                                          |
    | datadir_size_free     |           2314563584 | MySQL data directory size free space                               |
    | datadir_size_used     |           6004219904 | MySQL data directory size used space                               |
    | datadir_size_used_pct |     72.1766579531875 | MySQL data directory used space as a percentage                    |
    | total_ram             |           2090319872 | Total usable main memory size                                      |
    | free_ram              |           1567313920 | Available memory size                                              |
    | used_ram              |            523005952 | Used memory size                                                   |
    | free_ram_pct          |    74.97962188720703 | Available memory as a percentage                                   |
    | used_ram_pct          |    25.02037811279297 | Free memory as a percentage                                        |
    | shared_ram            |                61440 | Amount of shared memory                                            |
    | buffer_ram            |             69537792 | Memory used by buffers                                             |
    | total_high_ram        |                    0 | Total high memory size                                             |
    | free_high_ram         |                    0 | Available high memory size                                         |
    | total_low_ram         |           2090319872 | Total low memory size                                              |
    | free_low_ram          |           1567313920 | Available low memory size                                          |
    | load_1min             |                    0 | 1 minute load average                                              |
    | load_5min             |                    0 | 5 minute load average                                              |
    | load_15min            |                    0 | 15 minute load average                                             |
    | uptime                |                43732 | Uptime (in seconds)                                                |
    | uptime_days           |                    0 | Uptime (in days)                                                   |
    | uptime_hours          |                   12 | Uptime (in hours)                                                  |
    | total_swap            |                    0 | Total swap space size                                              |
    | free_swap             |                    0 | Swap space available                                               |
    | used_swap             |                    0 | Swap space used                                                    |
    | free_swap_pct         |                    0 | Swap space available as a percentage                               |
    | used_swap_pct         |                    0 | Swap space used as a percentage                                    |
    | procs                 |                  121 | Number of current processes                                        |
    | uptime_tv_sec         |                    0 | User CPU time used (in seconds)                                    |
    | utime_tv_usec         |               901159 | User CPU time used (in microseconds)                               |
    | stime_tv_sec          |                    0 | System CPU time (in seconds)                                       |
    | stime_tv_usec         |               566674 | System CPU time (in microseconds)                                  |
    | utime                 |             0.901159 | Total user time                                                    |
    | stime                 |             0.566674 | Total system time                                                  |
    | maxrss                |               149040 | Maximum resident set size                                          |
    | maxrss_bytes          |            152616960 | Maximum resident set size (in bytes)                               |
    | minflt                |                34719 | Page reclaims (soft page faults)                                   |
    | majflt                |                    0 | Page faults                                                        |
    | inblock               |                 7680 | Number of block input operations                                   |
    | oublock               |                33688 | Number of block output operations                                  |
    | nvcsw                 |                17404 | Number of voluntary context switches                               |
    | nivcsw                |                   69 | Number of involuntary context switches                             |
    | lo_tx_packets         |                11595 | Number of network packets sent                                     |
    | lo_rx_packets         |                11595 | Number of network packets received                                 |
    | lo_tx_bytes           |               603258 | Number of bytes sent over the network interface                    |
    | lo_rx_bytes           |               603258 | Number of bytes received over the network interface                |
    | lo_tx_dropped         |                    0 | Number of received network packets dropped                         |
    | lo_rx_dropped         |                    0 | Number of sent network packets dropped                             |
    | lo_tx_errors          |                    0 | Number of errors on received packets                               |
    | lo_rx_errors          |                    0 | Number of errors on sent packets                                   |
    | eth0_tx_packets       |                88325 | Number of network packets sent                                     |
    | eth0_rx_packets       |               138027 | Number of network packets received                                 |
    | eth0_tx_bytes         |             16792269 | Number of bytes sent over the network interface                    |
    | eth0_rx_bytes         |             10783265 | Number of bytes received over the network interface                |
    | eth0_tx_dropped       |                    0 | Number of received network packets dropped                         |
    | eth0_rx_dropped       |                    0 | Number of sent network packets dropped                             |
    | eth0_tx_errors        |                    0 | Number of errors on received packets                               |
    | eth0_rx_errors        |                    0 | Number of errors on sent packets                                   |
    +-----------------------+----------------------+--------------------------------------------------------------------+
    78 rows in set (0.00 sec)

#### Plugin Uninstallation
    mysql> UNINSTALL PLUGIN OS_METRICS;
    
#### Future Additions
Below are some ideas for possible additions.
* Swappiness Setting
* CPU Utilization
* Some data in iostat and vmstat (key metrics)
* I/O Scheduler Setting & other OS metrics (maybe useful for checking without having to login to terminal)
* And more...
