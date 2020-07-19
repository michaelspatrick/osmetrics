# MySQL OSMetrics Plugins
A collection of MySQL plugins for displaying Operating System metrics in INFORMATION_SCHEMA.  This would allow monitoring tools, such as PMM, to retrieve these values remotely via the MySQL interface.

Values are pulled via standard C library calls and some are read from the /proc filesystem so overhead is absolutely minimal.  I added a couple of libraries originally to show that even Windows and other variants of UNIX can be utilized, but commented them out to keep it all simple for now.

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
    
#### Plugin Installation
First, you will need to put the plugin code in the plugin directory of the source code you downloaded.  For me, this was "/home/ec2-user/percona-server-5.7.17-13/plugin" and I named the directory "osmetrics".  This directory contains the following files:

    includes  Makefile  osmetrics-cpu.c  osmetrics-cpuinfo.c  osmetrics-loadavg.c  osmetrics-memory.c  osmetrics-misc.c  osmetrics-mounts.c  osmetrics-network.c  osmetrics-swaps.c  osmetrics-vmstat.c  README.md

Next, you will need to know where your MySQL plugin directory is located.  You can query that with the following SQL:

    mysql> SHOW GLOBAL VARIABLES LIKE "%plugin_dir%";
    +---------------+-------------------------+
    | Variable_name | Value                   |
    +---------------+-------------------------+
    | plugin_dir    | /jet/var/mysqld/plugin/ |
    +---------------+-------------------------+
    1 row in set (0.01 sec)

You will then need to edit the Makefile and define this path there.  Once that is complete, you can compile the plugin:

    make clean
    make
    make install
    
Finally, you can login to MySQL and activate the plugins:

    mysql> INSTALL PLUGIN OS_CPU SONAME 'osmetrics-cpu.so';
    mysql> INSTALL PLUGIN OS_CPUINFO SONAME 'osmetrics-cpuinfo.so';
    mysql> INSTALL PLUGIN OS_LOADAVG SONAME 'osmetrics-loadavg.so';
    mysql> INSTALL PLUGIN OS_MEMORY SONAME 'osmetrics-memory.so';
    mysql> INSTALL PLUGIN OS_MISC SONAME 'osmetrics-misc.so';
    mysql> INSTALL PLUGIN OS_MOUNTS SONAME 'osmetrics-mounts.so';
    mysql> INSTALL PLUGIN OS_NETWORK SONAME 'osmetrics-network.so';
    mysql> INSTALL PLUGIN OS_SWAPS SONAME 'osmetrics-swaps.so';
    mysql> INSTALL PLUGIN OS_VMSTAT SONAME 'osmetrics-vmstat.so';

#### Verify Installation
    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_CPU;
    +---------------+---------------------+--------------------------------------------------------------------+
    | name          | value               | comment                                                            |
    +---------------+---------------------+--------------------------------------------------------------------+
    | numcores      |                   1 | Number of virtual CPU cores                                        |
    | speed         |      2300.123046875 | CPU speed in MHz                                                   |
    | bogomips      |      4600.080078125 | CPU bogomips                                                       |
    | user          |                  29 | Normal processes executing in user mode                            |
    | nice          |               11172 | Niced processes executing in user mode                             |
    | sys           |             9909218 | Processes executing in kernel mode                                 |
    | idle          |                2759 | Processes which are idle                                           |
    | iowait        |                   0 | Processes waiting for I/O to complete                              |
    | irq           |                  78 | Processes servicing interrupts                                     |
    | softirq       |                1710 | Processes servicing Softirqs                                       |
    | guest         |                   0 | Processes running a guest                                          |
    | guest_nice    |                   0 | Processes running a niced guest                                    |
    | intr          |             1852045 | Count of interrupts serviced since boot time                       |
    | ctxt          |             5277147 | Total number of context switches across all CPUs                   |
    | btime         |          1595028203 | Ttime at which the system booted, in seconds since the Unix epoch  |
    | processes     |               22357 | Number of processes and threads created                            |
    | procs_running |                   2 | Total number of threads that are running or ready to run           |
    | procs_blocked |                   0 | Number of processes currently blocked, waiting for I/O to complete |
    | softirq       |                1710 | Counts of softirqs serviced since boot time                        |
    | idle_pct      | 0.02779858389439319 | Average CPU idle time                                              |
    | util_pct      |    99.9722014161056 | Average CPU utilization                                            |
    | procs         |                 122 | Number of current processes                                        |
    | uptime_tv_sec |                   1 | User CPU time used (in seconds)                                    |
    | utime_tv_usec |              985439 | User CPU time used (in microseconds)                               |
    | stime_tv_sec  |                   1 | System CPU time (in seconds)                                       |
    | stime_tv_usec |              325261 | System CPU time (in microseconds)                                  |
    | utime         |            1.985439 | Total user time                                                    |
    | stime         |            1.325261 | Total system time                                                  |
    | minflt        |               34805 | Page reclaims (soft page faults)                                   |
    | majflt        |                   0 | Page faults                                                        |
    | nvcsw         |               46703 | Number of voluntary context switches                               |
    | nivcsw        |                 127 | Number of involuntary context switches                             |
    +---------------+---------------------+--------------------------------------------------------------------+
    32 rows in set (0.00 sec)
    
    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_CPUINFO;;
    +------------------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | name                                     | value                                                                                                                                                                                                                                                   |
    +------------------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    | processor                                |  0                                                                                                                                                                                                                                                      |
    | vendor_id                                |  GenuineIntel                                                                                                                                                                                                                                           |
    | cpu family                               |  6                                                                                                                                                                                                                                                      |
    | model                                    |  79                                                                                                                                                                                                                                                     |
    | model name                               |  Intel(R) Xeon(R) CPU E5-2686 v4 @ 2.30GHz                                                                                                                                                                                                              |
    | stepping                                 |  1                                                                                                                                                                                                                                                      |
    | microcode                                |  0xb000038                                                                                                                                                                                                                                              |
    | cpu MHz                                  |  2300.123                                                                                                                                                                                                                                               |
    | cache size                               |  46080 KB                                                                                                                                                                                                                                               |
    | physical id                              |  0                                                                                                                                                                                                                                                      |
    | siblings                                 |  1                                                                                                                                                                                                                                                      |
    | core id                                  |  0                                                                                                                                                                                                                                                      |
    | cpu cores                                |  1                                                                                                                                                                                                                                                      |
    | apicid                                   |  0                                                                                                                                                                                                                                                      |
    | initial apicid                           |  0                                                                                                                                                                                                                                                      |
    | fpu                                      |  yes                                                                                                                                                                                                                                                    |
    | fpu_exception                            |  yes                                                                                                                                                                                                                                                    |
    | cpuid level                              |  13                                                                                                                                                                                                                                                     |
    | wp                                       |  yes                                                                                                                                                                                                                                                    |
    | flags                                    |  fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology cpuid pni pclmulqdq ssse3 fma cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_ |
    | timer aes xsave avx f16c rdrand hypervis | timer aes xsave avx f16c rdrand hypervisor lahf_lm abm cpuid_fault invpcid_single pti fsgsbase bmi1 avx2 smep bmi2 erms invpcid xsaveopt                                                                                                                |
    | bugs                                     |  cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit                                                                                                                                                                     |
    | bogomips                                 |  4600.08                                                                                                                                                                                                                                                |
    | clflush size                             |  64                                                                                                                                                                                                                                                     |
    | cache_alignment                          |  64                                                                                                                                                                                                                                                     |
    | address sizes                            |  46 bits physical, 48 bits virtual                                                                                                                                                                                                                      |
    | power management                         |                                                                                                                                                                                                                                                         |
    +------------------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
    27 rows in set (0.00 sec)

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_LOADAVG;
    +--------+-------+------------------------+
    | name   | value | comment                |
    +--------+-------+------------------------+
    | 1_min  |     0 | 1 minute load average  |
    | 5_min  |     0 | 5 minute load average  |
    | 15_min |     0 | 15 minute load average |
    +--------+-------+------------------------+
    3 rows in set (0.00 sec)
    
    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_MEMORY;
    +----------------+-----------------------+--------------------------------------+
    | name           | value                 | comment                              |
    +----------------+-----------------------+--------------------------------------+
    | total_ram      |            2090319872 | Total usable main memory size        |
    | free_ram       |            1452339200 | Available memory size                |
    | used_ram       |             637980672 | Used memory size                     |
    | free_ram_pct   |     69.47927856445312 | Available memory as a percentage     |
    | used_ram_pct   |    30.520719528198242 | Free memory as a percentage          |
    | shared_ram     |                 61440 | Amount of shared memory              |
    | buffer_ram     |             108040192 | Memory used by buffers               |
    | total_high_ram |                     0 | Total high memory size               |
    | free_high_ram  |                     0 | Available high memory size           |
    | total_low_ram  |            2090319872 | Total low memory size                |
    | free_low_ram   |            1452339200 | Available low memory size            |
    | maxrss         |       140308942222128 | Maximum resident set size            |
    | maxrss_bytes   | 1.4367635683545907e17 | Maximum resident set size (in bytes) |
    +----------------+-----------------------+--------------------------------------+
    13 rows in set (0.00 sec)
    
    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_MISC;
    +-----------------------+-------------------+-------------------------------------------------+
    | name                  | value             | comment                                         |
    +-----------------------+-------------------+-------------------------------------------------+
    | datadir_size          |        8318783488 | MySQL data directory size                       |
    | datadir_size_free     |        2277470208 | MySQL data directory size free space            |
    | datadir_size_used     |        6041313280 | MySQL data directory size used space            |
    | datadir_size_used_pct | 72.62255699664148 | MySQL data directory used space as a percentage |
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

    mysql> SELECT * FROM INFORMATION_SCHEMA.OS_VMSTAT;;
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

#### Plugin Uninstallation
    mysql> UNINSTALL PLUGIN OS_CPU;
    mysql> UNINSTALL PLUGIN OS_CPUINFO;
    mysql> UNINSTALL PLUGIN OS_LOADAVG;
    mysql> UNINSTALL PLUGIN OS_MEMORY;
    mysql> UNINSTALL PLUGIN OS_MISC;
    mysql> UNINSTALL PLUGIN OS_MOUNTS;
    mysql> UNINSTALL PLUGIN OS_NETWORK;
    mysql> UNINSTALL PLUGIN OS_SWAPS;
    mysql> UNINSTALL PLUGIN OS_VMSTAT;
