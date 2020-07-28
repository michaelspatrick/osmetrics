# MySQL OSMetrics Plugins
A collection of MySQL plugins for displaying Operating System metrics in INFORMATION_SCHEMA.  This would allow monitoring tools, such as PMM, to retrieve these values remotely via the MySQL interface.

Values are pulled via standard C library calls and some are read from the /proc filesystem so overhead is absolutely minimal.  I added a couple of libraries originally to show that even Windows and other variants of UNIX can be utilized, but commented them out to keep it all simple for now.

Many variables were added to show what was possible.  Some of these may not be of interest.  I just wanted to see what kind of stuff was possible and would tweak these over time.  

Also, none of the calculations were rounded.  This was done just to keep precision for graphing of values but could easily be changed later.

If there is interest, this could be expanded to add more metrics and unnecessary ones removed.  Just looking for feedback.

Also keep in mind that my C programming skills are rusty and I am sure the code could be cleaned up.

Make sure you have the source code for MySQL and have done a cmake on it.  This will be necessary to compile the plugin.

#### Preparing the environment
Below is the way that I compiled the plugin.  You will obviously need to make changes to match your environment.
You will also need to have the Percona Server source code on your server:

    wget https://www.percona.com/downloads/Percona-Server-5.7/Percona-Server-5.7.17-13/source/tarball/percona-server-5.7.17-13.tar.gz

Uncompress the file and go into the directory:

    tar -zxvf percona-server-5.7.17-13.tar.gz
    cd percona-server-5.7.17-13

I also had to add a few utilities:

    sudo yum install cmake
    sudo yum install boost
    sudo yum install ncurses-devel
    sudo yum install readline-devel
    cmake -DDOWNLOAD_BOOST=1 -DWITH_BOOST=..

#### Compiling the Plugins
First, you will need to put the plugin code in the plugin directory of the source code you downloaded.  For me, this was "/home/ec2-user/percona-server-5.7.17-13/plugin" and I named the directory "osmetrics".  Of course, you can just do a "git" to retrieve this to your server or download as a zip file and decompress.  Just make sure it is placed into the "plugin" directory of the source code as noted above.

Next, you will need to know where your MySQL plugin directory is located.  You can query that with the following SQL:

    mysql> SHOW GLOBAL VARIABLES LIKE "%plugin_dir%";
    +---------------+-------------------------+
    | Variable_name | Value                   |
    +---------------+-------------------------+
    | plugin_dir    | /jet/var/mysqld/plugin/ |
    +---------------+-------------------------+
    1 row in set (0.01 sec)

You will then need to edit the Makefile and define this path there.  Once that is complete, you can compile the plugins:

    make clean
    make
    make install

#### Installing the Plugins
Finally, you can login to MySQL and activate the plugins:

    mysql> INSTALL PLUGIN OS_CPU SONAME 'osmetrics-cpu.so';
    mysql> INSTALL PLUGIN OS_CPUGOVERNOR SONAME 'osmetrics-cpugovernor.so';
    mysql> INSTALL PLUGIN OS_CPUINFO SONAME 'osmetrics-cpuinfo.so';
    mysql> INSTALL PLUGIN OS_IOSCHEDULER SONAME 'osmetrics-ioscheduler.so';
    mysql> INSTALL PLUGIN OS_DISKSTATS SONAME 'osmetrics-diskstats.so';
    mysql> INSTALL PLUGIN OS_LOADAVG SONAME 'osmetrics-loadavg.so';
    mysql> INSTALL PLUGIN OS_MEMINFO SONAME 'osmetrics-meminfo.so';
    mysql> INSTALL PLUGIN OS_MEMORY SONAME 'osmetrics-memory.so';
    mysql> INSTALL PLUGIN OS_MISC SONAME 'osmetrics-misc.so';
    mysql> INSTALL PLUGIN OS_MOUNTS SONAME 'osmetrics-mounts.so';
    mysql> INSTALL PLUGIN OS_NETWORK SONAME 'osmetrics-network.so';
    mysql> INSTALL PLUGIN OS_STAT SONAME 'osmetrics-stat.so';
    mysql> INSTALL PLUGIN OS_SWAPINFO SONAME 'osmetrics-swapinfo.so';
    mysql> INSTALL PLUGIN OS_VERSION SONAME 'osmetrics-version.so';    
    mysql> INSTALL PLUGIN OS_VMSTAT SONAME 'osmetrics-vmstat.so';

Alternatively, you can run the install SQL script:

    mysql> SOURCE /path/to/install_plugins.sql

#### Verify Installation
If all went well, you should see several new plugins available.  Just make sure the status is "ACTIVE."

    mysql> SHOW PLUGINS;
    +-----------------------------+----------+--------------------+----------------------------+---------+
    | Name                        | Status   | Type               | Library                    | License |
    +-----------------------------+----------+--------------------+----------------------------+---------+
    ...
    | OS_CPU                      | ACTIVE   | INFORMATION SCHEMA | osmetrics-cpu.so           | GPL     |
    | OS_GOVERNOR                 | ACTIVE   | INFORMATION SCHEMA | osmetrics-cpugovernor.so   | GPL     |
    | OS_CPUINFO                  | ACTIVE   | INFORMATION SCHEMA | osmetrics-cpuinfo.so       | GPL     |
    | OS_DISKSTATS                | ACTIVE   | INFORMATION SCHEMA | osmetrics-diskstats.so     | GPL     |
    | OS_IOSCHEDULER              | ACTIVE   | INFORMATION SCHEMA | osmetrics-diskscheduler.so | GPL     |    
    | OS_LOADAVG                  | ACTIVE   | INFORMATION SCHEMA | osmetrics-loadavg.so       | GPL     |
    | OS_MEMINFO                  | ACTIVE   | INFORMATION SCHEMA | osmetrics-meminfo.so       | GPL     |
    | OS_MEMORY                   | ACTIVE   | INFORMATION SCHEMA | osmetrics-memory.so        | GPL     |
    | OS_MISC                     | ACTIVE   | INFORMATION SCHEMA | osmetrics-misc.so          | GPL     |
    | OS_MOUNTS                   | ACTIVE   | INFORMATION SCHEMA | osmetrics-mounts.so        | GPL     |
    | OS_NETWORK                  | ACTIVE   | INFORMATION SCHEMA | osmetrics-network.so       | GPL     |
    | OS_STAT                     | ACTIVE   | INFORMATION SCHEMA | osmetrics-stat.so          | GPL     |
    | OS_SWAPINFO                 | ACTIVE   | INFORMATION SCHEMA | osmetrics-swapinfo.so      | GPL     |
    | OS_VERSION                  | ACTIVE   | INFORMATION SCHEMA | osmetrics-version.so       | GPL     |
    | OS_VMSTAT                   | ACTIVE   | INFORMATION SCHEMA | osmetrics-vmstat.so        | GPL     |
    +-----------------------------+----------+--------------------+----------------------------+---------+

#### Querying the Plugins
Let's look at example output from each of the plugins below:

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_CPU;
    +---------------+------------+--------------------------------------------------------------------+
    | name          | value      | comment                                                            |
    +---------------+------------+--------------------------------------------------------------------+
    | numcores      |          1 | Number of virtual CPU cores                                        |
    | speed         |   2299.892 | CPU speed in MHz                                                   |
    | bogomips      |    4600.08 | CPU bogomips                                                       |
    | user          |          0 | Normal processes executing in user mode                            |
    | nice          |       4213 | Niced processes executing in user mode                             |
    | sys           |     610627 | Processes executing in kernel mode                                 |
    | idle          |        524 | Processes which are idle                                           |
    | iowait        |          0 | Processes waiting for I/O to complete                              |
    | irq           |          9 | Processes servicing interrupts                                     |
    | softirq       |        765 | Processes servicing Softirqs                                       |
    | guest         |          0 | Processes running a guest                                          |
    | guest_nice    |          0 | Processes running a niced guest                                    |
    | intr          |     200642 | Count of interrupts serviced since boot time                       |
    | ctxt          |     434493 | Total number of context switches across all CPUs                   |
    | btime         | 1595891204 | Ttime at which the system booted, in seconds since the Unix epoch  |
    | processes     |       9270 | Number of processes and threads created                            |
    | procs_running |          3 | Total number of threads that are running or ready to run           |
    | procs_blocked |          0 | Number of processes currently blocked, waiting for I/O to complete |
    | softirq       |        765 | Counts of softirqs serviced since boot time                        |
    | idle_pct      |       0.09 | Average CPU idle time                                              |
    | util_pct      |      99.91 | Average CPU utilization                                            |
    | procs         |        120 | Number of current processes                                        |
    | uptime_tv_sec |          1 | User CPU time used (in seconds)                                    |
    | utime_tv_usec |     943740 | User CPU time used (in microseconds)                               |
    | stime_tv_sec  |          1 | System CPU time (in seconds)                                       |
    | stime_tv_usec |     315574 | System CPU time (in microseconds)                                  |
    | utime         |    1.94374 | Total user time                                                    |
    | stime         |   1.315574 | Total system time                                                  |
    | minflt        |      34783 | Page reclaims (soft page faults)                                   |
    | majflt        |          0 | Page faults                                                        |
    | nvcsw         |        503 | Number of voluntary context switches                               |
    | nivcsw        |        135 | Number of involuntary context switches                             |
    +---------------+------------+--------------------------------------------------------------------+
    32 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_CPUGOVERNOR;
    +--------+-------------+
    | name   | governor    |
    +--------+-------------+
    | cpu0   | performance |
    +--------+-------------+
    1 row in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_CPUINFO;
    +-----------+--------------+------------+-------+-------------------------------------------+----------+-----------+----------+------------+-------------+----------+---------+-----------+--------+----------------+-----+---------------+-------------+-----+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+----------+--------------+-----------------+-----------------------------------+------------------+
    | processor | vendor_id    | cpu_family | model | model_name                                | stepping | microcode | cpu_MHz  | cache_size | physical_id | siblings | core_id | cpu_cores | apicid | initial_apicid | fpu | fpu_exception | cpuid_level | wp  | flags                                                                                                                                                                                                                                                                   | bugs                                                                               | bogomips | clflush_size | cache_alignment | address_sizes                     | power_management |
    +-----------+--------------+------------+-------+-------------------------------------------+----------+-----------+----------+------------+-------------+----------+---------+-----------+--------+----------------+-----+---------------+-------------+-----+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+----------+--------------+-----------------+-----------------------------------+------------------+
    | 0         | GenuineIntel | 6          | 63    | Intel(R) Xeon(R) CPU E5-2676 v3 @ 2.40GHz | 2        | 0x43      | 2400.005 | 30720 KB   | 0           | 1        | 0       | 1         | 0      | 0              | yes | yes           | 13          | yes | fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology cpuid pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave a | cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit | 4800.11  | 64           | 64              | 46 bits physical, 48 bits virtual |                  |
    +-----------+--------------+------------+-------+-------------------------------------------+----------+-----------+----------+------------+-------------+----------+---------+-----------+--------+----------------+-----+---------------+-------------+-----+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------+----------+--------------+-----------------+-----------------------------------+------------------+
    1 row in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_IOSCHEDULER;
    +--------+-----------+
    | device | scheduler |
    +--------+-----------+
    | xvda   | [noop]    |
    +--------+-----------+
    1 row in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_DISKSTATS;
    +-----------+-----------+--------+---------------+--------------+--------------+---------------+----------------+---------------+-----------------+----------------+-----------------+------------------+---------------------------+
    | major_num | minor_num | device | reads_success | reads_merged | sectors_read | time_reads_ms | writes_success | writes_merged | sectors_written | time_writes_ms | ios_in_progress | time_doing_io_ms | weighted_time_doing_io_ms |
    +-----------+-----------+--------+---------------+--------------+--------------+---------------+----------------+---------------+-----------------+----------------+-----------------+------------------+---------------------------+
    |       202 |         0 | xvda   |         10286 |           10 |       472913 |          7312 |           4137 |          2472 |          351864 |          14276 |               0 |             4452 |                     21580 |
    |       202 |         1 | xvda1  |         10209 |           10 |       468929 |          7280 |           4137 |          2472 |          351864 |          14276 |               0 |             4436 |                     21548 |
    |       202 |         2 | xvda2  |            40 |            0 |         3504 |            24 |              0 |             0 |               0 |              0 |               0 |               24 |                        24 |
    +-----------+-----------+--------+---------------+--------------+--------------+---------------+----------------+---------------+-----------------+----------------+-----------------+------------------+---------------------------+
    3 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_LOADAVG;
    +--------+-------+------------------------+
    | name   | value | comment                |
    +--------+-------+------------------------+
    | 1_min  |  0.09 | 1 minute load average  |
    | 5_min  |  0.02 | 5 minute load average  |
    | 15_min |  0.01 | 15 minute load average |
    +--------+-------+------------------------+
    3 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_MEMINFO;
    +-----------------+------------+
    | name            | value      |
    +-----------------+------------+
    | MemTotal        | 2090319872 |
    | MemFree         | 1658920960 |
    | MemAvailable    | 1762938880 |
    | Buffers         |   22573056 |
    | Cached          |  206209024 |
    | SwapCached      |          0 |
    | Active          |  284999680 |
    | Inactive        |  100868096 |
    | Active(anon)    |  156110848 |
    | Inactive(anon)  |      53248 |
    | Active(file)    |  128888832 |
    | Inactive(file)  |  100814848 |
    | Unevictable     |          0 |
    | Mlocked         |          0 |
    | SwapTotal       |          0 |
    | SwapFree        |          0 |
    | Dirty           |     811008 |
    | Writeback       |          0 |
    | AnonPages       |  157085696 |
    | Mapped          |   53223424 |
    | Shmem           |      65536 |
    | Slab            |   29102080 |
    | SReclaimable    |   18337792 |
    | SUnreclaim      |   10764288 |
    | KernelStack     |    2162688 |
    | PageTables      |    3444736 |
    | NFS_Unstable    |          0 |
    | Bounce          |          0 |
    | WritebackTmp    |          0 |
    | CommitLimit     | 1045159936 |
    | Committed_AS    |  770662400 |
    | VmallocTotal    | 4294966272 |
    | VmallocUsed     |          0 |
    | VmallocChunk    |          0 |
    | AnonHugePages   |          0 |
    | ShmemHugePages  |          0 |
    | ShmemPmdMapped  |          0 |
    | HugePages_Total |          0 |
    | HugePages_Free  |          0 |
    | HugePages_Rsvd  |          0 |
    | HugePages_Surp  |          0 |
    | Hugepagesize    |    2097152 |
    | DirectMap4k     |   60817408 |
    | DirectMap2M     | 2086666240 |
    +-----------------+------------+
    44 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_MEMORY;
    +----------------+-----------------------+--------------------------------------+
    | name           | value                 | comment                              |
    +----------------+-----------------------+--------------------------------------+
    | total_ram      |            2090319872 | Total usable main memory size        |
    | free_ram       |            1452339200 | Available memory size                |
    | used_ram       |             637980672 | Used memory size                     |
    | free_ram_pct   |                 69.48 | Available memory as a percentage     |
    | used_ram_pct   |                 30.52 | Free memory as a percentage          |
    | shared_ram     |                 61440 | Amount of shared memory              |
    | buffer_ram     |             108040192 | Memory used by buffers               |
    | total_high_ram |                     0 | Total high memory size               |
    | free_high_ram  |                     0 | Available high memory size           |
    | total_low_ram  |            2090319872 | Total low memory size                |
    | free_low_ram   |            1452339200 | Available low memory size            |
    | maxrss         |       140308942222128 | Maximum resident set size            |
    +----------------+-----------------------+--------------------------------------+
    12 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_MISC;
    +-----------------------+-------------------+-------------------------------------------------+
    | name                  | value             | comment                                         |
    +-----------------------+-------------------+-------------------------------------------------+
    | datadir_size          |        8318783488 | MySQL data directory size                       |
    | datadir_size_free     |        2277470208 | MySQL data directory size free space            |
    | datadir_size_used     |        6041313280 | MySQL data directory size used space            |
    | datadir_size_used_pct |             72.62 | MySQL data directory used space as a percentage |
    | uptime                |            100026 | Uptime (in seconds)                             |
    | uptime_days           |                 1 | Uptime (in days)                                |
    | uptime_hours          |                27 | Uptime (in hours)                               |
    | procs                 |               122 | Number of current processes                     |
    | swappiness            |                60 | Swappiness setting                              |
    +-----------------------+-------------------+-------------------------------------------------+
    9 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_MOUNTS;
    +------------+--------------------------+------------------+---------------------------+
    | device     | mount_point              | file_system_type | mount_options             |
    +------------+--------------------------+------------------+---------------------------+
    | proc       | /proc                    | proc             | rw,relatime               |
    | sysfs      | /sys                     | sysfs            | rw,relatime               |
    | devtmpfs   | /dev                     | devtmpfs         | rw,relatime,size=1010060k |
    | devpts     | /dev/pts                 | devpts           | rw,relatime,gid=5,mode=62 |
    | tmpfs      | /dev/shm                 | tmpfs            | rw,relatime               |
    | /dev/xvda1 | /                        | ext4             | rw,noatime,data=ordered   |
    | devpts     | /dev/pts                 | devpts           | rw,relatime,gid=5,mode=62 |
    | none       | /proc/sys/fs/binfmt_misc | binfmt_misc      | rw,relatime               |
    +------------+--------------------------+------------------+---------------------------+
    8 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_NETWORK;
    +-----------+------------+------------+----------+----------+------------+------------+-----------+-----------+
    | interface | tx_packets | rx_packets | tx_bytes | rx_bytes | tx_dropped | rx_dropped | tx_errors | rx_errors |
    +-----------+------------+------------+----------+----------+------------+------------+-----------+-----------+
    | lo        |      26528 |      26528 |  1380012 |  1380012 |          0 |          0 |         0 |         0 |
    | eth0      |     102533 |     144031 | 16962983 | 23600676 |          0 |          0 |         0 |         0 |
    +-----------+------------+------------+----------+----------+------------+------------+-----------+-----------+
    2 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_STAT;
    | pid  | comm     | state | ppid | pgrp | session | tty_nr | tpgid | flags   | minflt | cminflt | majflt | cmajflt | utime | stime | cutime | cstime | priority | nice | num_threads | itrealvalue | starttime | vsize      | rss   | rsslim                | startcode | endcode  | startstack      | kstkeep | kstkeip | signal | blocked | sigignore | sigcatch | wchan | nswap | cnswap | exit_signal | processor | rt_priority | policy | delayacct_blkio_ticks | guest_time | cguest_time | start_data | end_data | start_brk | arg_start       | arg_end         | env_start       | env_end         | exit_code |
    +------+----------+-------+------+------+---------+--------+-------+---------+--------+---------+--------+---------+-------+-------+--------+--------+----------+------+-------------+-------------+-----------+------------+-------+-----------------------+-----------+----------+-----------------+---------+---------+--------+---------+-----------+----------+-------+-------+--------+-------------+-----------+-------------+--------+-----------------------+------------+-------------+------------+----------+-----------+-----------------+-----------------+-----------------+-----------------+-----------+
    | 6656 | (mysqld) | S     | 2030 | 1896 |    1896 |      0 |    -1 | 4194304 |  34784 |       0 |      0 |       0 |    96 |    55 |      0 |      0 |       20 |    0 |          29 |           0 |    965078 | 1153900544 | 37324 | 1.8446744073709552e19 |   4194304 | 27414570 | 140728454321408 |       0 |       0 |      0 |  540679 |     12294 |     1768 |     0 |     0 |      0 |          17 |         0 |           0 |      0 |                     4 |          0 |           0 |   29511728 | 31209920 |  36462592 | 140728454327797 | 140728454328040 | 140728454328040 | 140728454328281 |         0 |
    +------+----------+-------+------+------+---------+--------+-------+---------+--------+---------+--------+---------+-------+-------+--------+--------+----------+------+-------------+-------------+-----------+------------+-------+-----------------------+-----------+----------+-----------------+---------+---------+--------+---------+-----------+----------+-------+-------+--------+-------------+-----------+-------------+--------+-----------------------+------------+-------------+------------+----------+-----------+-----------------+-----------------+-----------------+-----------------+-----------+
    1 row in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_SWAPINFO;
    +---------------+-------+--------------------------------------+
    | name          | value | comment                              |
    +---------------+-------+--------------------------------------+
    | total_swap    |     0 | Total swap space size                |
    | free_swap     |     0 | Swap space available                 |
    | used_swap     |     0 | Swap space used                      |
    | free_swap_pct |     0 | Swap space available as a percentage |
    | used_swap_pct |     0 | Swap space used as a percentage      |
    +---------------+-------+--------------------------------------+
    5 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_VMSTAT;
    +---------------------------+----------+
    | name                      | value    |
    +---------------------------+----------+
    | nr_free_pages             |   354544 |
    | nr_zone_inactive_anon     |       13 |
    | nr_zone_active_anon       |    38257 |
    | nr_zone_inactive_file     |    30742 |
    | nr_zone_active_file       |    70367 |
    | nr_zone_unevictable       |        0 |
    | nr_zone_write_pending     |        9 |
    | nr_mlock                  |        0 |
    | nr_page_table_pages       |      854 |
    | nr_kernel_stack           |     2176 |
    | nr_bounce                 |        0 |
    | nr_zspages                |        0 |
    | nr_free_cma               |        0 |
    | numa_hit                  | 14011351 |
    | numa_miss                 |        0 |
    | numa_foreign              |        0 |
    | numa_interleave           |    15133 |
    | numa_local                | 14011351 |
    | numa_other                |        0 |
    | nr_inactive_anon          |       13 |
    | nr_active_anon            |    38257 |
    | nr_inactive_file          |    30742 |
    | nr_active_file            |    70367 |
    | nr_unevictable            |        0 |
    | nr_slab_reclaimable       |     9379 |
    | nr_slab_unreclaimable     |     2829 |
    | nr_isolated_anon          |        0 |
    | nr_isolated_file          |        0 |
    | workingset_refault        |        0 |
    | workingset_activate       |        0 |
    | workingset_nodereclaim    |        0 |
    | nr_anon_pages             |    38504 |
    | nr_mapped                 |    13172 |
    | nr_file_pages             |   100873 |
    | nr_dirty                  |        9 |
    | nr_writeback              |        0 |
    | nr_writeback_temp         |        0 |
    | nr_shmem                  |       15 |
    | nr_shmem_hugepages        |        0 |
    | nr_shmem_pmdmapped        |        0 |
    | nr_anon_transparent_hugep |        0 |
    | nr_unstable               |        0 |
    | nr_vmscan_write           |        0 |
    | nr_vmscan_immediate_recla |        0 |
    | nr_dirtied                |   389218 |
    | nr_written                |   381326 |
    | nr_dirty_threshold        |    87339 |
    | nr_dirty_background_thres |    43616 |
    | pgpgin                    |   619972 |
    | pgpgout                   |  2180908 |
    | pswpin                    |        0 |
    | pswpout                   |        0 |
    | pgalloc_dma               |        0 |
    | pgalloc_dma32             | 14085334 |
    | pgalloc_normal            |        0 |
    | pgalloc_movable           |        0 |
    | allocstall_dma            |        0 |
    | allocstall_dma32          |        0 |
    | allocstall_normal         |        0 |
    | allocstall_movable        |        0 |
    | pgskip_dma                |        0 |
    | pgskip_dma32              |        0 |
    | pgskip_normal             |        0 |
    | pgskip_movable            |        0 |
    | pgfree                    | 14440053 |
    | pgactivate                |    55703 |
    | pgdeactivate              |        1 |
    | pglazyfree                |      249 |
    | pgfault                   | 14687206 |
    | pgmajfault                |     1264 |
    | pglazyfreed               |        0 |
    | pgrefill                  |        0 |
    | pgsteal_kswapd            |        0 |
    | pgsteal_direct            |        0 |
    | pgscan_kswapd             |        0 |
    | pgscan_direct             |        0 |
    | pgscan_direct_throttle    |        0 |
    | zone_reclaim_failed       |        0 |
    | pginodesteal              |        0 |
    | slabs_scanned             |        0 |
    | kswapd_inodesteal         |        0 |
    | kswapd_low_wmark_hit_quic |        0 |
    | kswapd_high_wmark_hit_qui |        0 |
    | pageoutrun                |        0 |
    | pgrotated                 |       44 |
    | drop_pagecache            |        0 |
    | drop_slab                 |        0 |
    | oom_kill                  |        0 |
    | numa_pte_updates          |        0 |
    | numa_huge_pte_updates     |        0 |
    | numa_hint_faults          |        0 |
    | numa_hint_faults_local    |        0 |
    | numa_pages_migrated       |        0 |
    | pgmigrate_success         |        0 |
    | pgmigrate_fail            |        0 |
    | compact_migrate_scanned   |        0 |
    | compact_free_scanned      |        0 |
    | compact_isolated          |        0 |
    | compact_stall             |        0 |
    | compact_fail              |        0 |
    | compact_success           |        0 |
    | compact_daemon_wake       |        0 |
    | compact_daemon_migrate_sc |        0 |
    | compact_daemon_free_scann |        0 |
    | htlb_buddy_alloc_success  |        0 |
    | htlb_buddy_alloc_fail     |        0 |
    | unevictable_pgs_culled    |     1300 |
    | unevictable_pgs_scanned   |        0 |
    | unevictable_pgs_rescued   |      266 |
    | unevictable_pgs_mlocked   |     2626 |
    | unevictable_pgs_munlocked |     2626 |
    | unevictable_pgs_cleared   |        0 |
    | unevictable_pgs_stranded  |        0 |
    | thp_fault_alloc           |        0 |
    | thp_fault_fallback        |        0 |
    | thp_collapse_alloc        |        0 |
    | thp_collapse_alloc_failed |        0 |
    | thp_file_alloc            |        0 |
    | thp_file_mapped           |        0 |
    | thp_split_page            |        0 |
    | thp_split_page_failed     |        0 |
    | thp_deferred_split_page   |        0 |
    | thp_split_pmd             |        0 |
    | thp_split_pud             |        0 |
    | thp_zero_page_alloc       |        0 |
    | thp_zero_page_alloc_faile |        0 |
    | thp_swpout                |        0 |
    | thp_swpout_fallback       |        0 |
    | swap_ra                   |        0 |
    | swap_ra_hit               |        0 |
    +---------------------------+----------+
    130 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_VERSION;
    +------------+---------------------------+
    | name       | value                     |
    +------------+---------------------------+
    | sysname    | Linux                     |
    | nodename   | ip-172-31-25-133          |
    | release    | 4.14.181-108.257.amzn1.x8 |
    | version    | #1 SMP Wed May 27 02:43:0 |
    | machine    | x86_64                    |
    | domainname | (none)                    |
    +------------+---------------------------+
    6 rows in set (0.00 sec)

#### Uninstalling the Plugins
To uninstall the plugins, you can remove them with the following SQL commands.  To completely remove them, you will need to remove them from your plugin directory.

    mysql> UNINSTALL PLUGIN OS_CPU;
    mysql> UNINSTALL PLUGIN OS_CPUGOVERNOR;
    mysql> UNINSTALL PLUGIN OS_CPUINFO;
    mysql> UNINSTALL PLUGIN OS_IOSCHEDULER;
    mysql> UNINSTALL PLUGIN OS_DISKSTATS;
    mysql> UNINSTALL PLUGIN OS_LOADAVG;
    mysql> UNINSTALL PLUGIN OS_MEMINFO;
    mysql> UNINSTALL PLUGIN OS_MEMORY;
    mysql> UNINSTALL PLUGIN OS_MISC;
    mysql> UNINSTALL PLUGIN OS_MOUNTS;
    mysql> UNINSTALL PLUGIN OS_NETWORK;
    mysql> UNINSTALL PLUGIN OS_STAT;
    mysql> UNINSTALL PLUGIN OS_SWAPINFO;
    mysql> UNINSTALL PLUGIN OS_VERSION;
    mysql> UNINSTALL PLUGIN OS_VMSTAT;

Alternatively, you can run the uninstall SQL script:

    mysql> SOURCE /path/to/uninstall_plugins.sql

#### What's next?

Who knows.  If there is enough interest, I would be happy to expand the plugins.  First, I need to do some more code cleanup and performance test them.  I do not expect them to have a significant performance impact, but one never knows until you test...
