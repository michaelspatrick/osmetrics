CC=g++
CFLAGS=-DMYSQL_DYNAMIC_PLUGIN -Wall -fPIC -shared \
-I/usr/include/mysql -m64 \
-I../../sql \
-I../../include \
-I../../libbinlogevents/export \
-I../../libbinlogevents/include \
-I../../sql \
-I./includes \
-I./

all: osmetrics-cpu.so osmetrics-network.so osmetrics-loadavg.so osmetrics-swapinfo.so osmetrics-memory.so osmetrics-vmstat.so osmetrics-cpuinfo.so osmetrics-mounts.so osmetrics-misc.so osmetrics-diskstats.so

osmetrics-cpu.so: osmetrics-cpu.c
        $(CC) $(CFLAGS) -o osmetrics-cpu.so osmetrics-cpu.c

osmetrics-network.so: osmetrics-network.c
        $(CC) $(CFLAGS) -o osmetrics-network.so osmetrics-network.c

osmetrics-loadavg.so: osmetrics-loadavg.c
        $(CC) $(CFLAGS) -o osmetrics-loadavg.so osmetrics-loadavg.c

osmetrics-swapinfo.so: osmetrics-swapinfo.c
        $(CC) $(CFLAGS) -o osmetrics-swapinfo.so osmetrics-swapinfo.c

osmetrics-memory.so: osmetrics-memory.c
        $(CC) $(CFLAGS) -o osmetrics-memory.so osmetrics-memory.c

osmetrics-vmstat.so: osmetrics-vmstat.c
        $(CC) $(CFLAGS) -o osmetrics-vmstat.so osmetrics-vmstat.c

osmetrics-cpuinfo.so: osmetrics-cpuinfo.c
        $(CC) $(CFLAGS) -o osmetrics-cpuinfo.so osmetrics-cpuinfo.c

osmetrics-mounts.so: osmetrics-mounts.c
        $(CC) $(CFLAGS) -o osmetrics-mounts.so osmetrics-mounts.c

osmetrics-misc.so: osmetrics-misc.c
        $(CC) $(CFLAGS) -o osmetrics-misc.so osmetrics-misc.c

osmetrics-diskstats.so: osmetrics-diskstats.c
        $(CC) $(CFLAGS) -o osmetrics-diskstats.so osmetrics-diskstats.c

clean:
      	rm -f /jet/var/mysqld/plugin/osmetrics-cpu.so
        rm -f /jet/var/mysqld/plugin/osmetrics-network.so
        rm -f /jet/var/mysqld/plugin/osmetrics-loadavg.so
        rm -f /jet/var/mysqld/plugin/osmetrics-swapinfo.so
        rm -f /jet/var/mysqld/plugin/osmetrics-memory.so
        rm -f /jet/var/mysqld/plugin/osmetrics-vmstat.so
        rm -f /jet/var/mysqld/plugin/osmetrics-cpuinfo.so
        rm -f /jet/var/mysqld/plugin/osmetrics-mounts.so
        rm -f /jet/var/mysqld/plugin/osmetrics-misc.so
        rm -f /jet/var/mysqld/plugin/osmetrics-diskstats.so
        rm -f osmetrics-cpu.so
        rm -f osmetrics-network.so
        rm -f osmetrics-loadavg.so
        rm -f osmetrics-swapinfo.so
        rm -f osmetrics-memory.so
        rm -f osmetrics-vmstat.so
        rm -f osmetrics-cpuinfo.so
        rm -f osmetrics-mounts.so
        rm -f osmetrics-misc.so
        rm -f osmetrics-diskstats.so

install:
        cp -f osmetrics-cpu.so /jet/var/mysqld/plugin/
        cp -f osmetrics-network.so /jet/var/mysqld/plugin/
        cp -f osmetrics-loadavg.so /jet/var/mysqld/plugin/
        cp -f osmetrics-swapinfo.so /jet/var/mysqld/plugin/
        cp -f osmetrics-memory.so /jet/var/mysqld/plugin/
        cp -f osmetrics-vmstat.so /jet/var/mysqld/plugin/
        cp -f osmetrics-cpuinfo.so /jet/var/mysqld/plugin/
        cp -f osmetrics-mounts.so /jet/var/mysqld/plugin/
        cp -f osmetrics-misc.so /jet/var/mysqld/plugin/
        cp -f osmetrics-diskstats.so /jet/var/mysqld/plugin/
