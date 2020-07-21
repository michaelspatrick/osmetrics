PLUGINDIR=/jet/var/mysqld/plugin

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

all: osmetrics-cpu.so osmetrics-network.so osmetrics-loadavg.so osmetrics-swapinfo.so osmetrics-memory.so osmetrics-vmstat.so osmetrics-cpuinfo.so osmetrics-mounts.so osmetrics-misc.so \
     osmetrics-diskstats.so osmetrics-version.so osmetrics-ioscheduler.so osmetrics-meminfo.so osmetrics-cpugovernor.so
     
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
        
osmetrics-version.so: osmetrics-version.c
        $(CC) $(CFLAGS) -o osmetrics-version.so osmetrics-version.c

osmetrics-ioscheduler.so: osmetrics-ioscheduler.c
        $(CC) $(CFLAGS) -o osmetrics-ioscheduler.so osmetrics-ioscheduler.c

osmetrics-meminfo.so: osmetrics-meminfo.c
        $(CC) $(CFLAGS) -o osmetrics-meminfo.so osmetrics-meminfo.c

osmetrics-cpugovernor.so: osmetrics-cpugovernor.c
        $(CC) $(CFLAGS) -o osmetrics-cpugovernor.so osmetrics-cpugovernor.c
	
clean:
      	rm -f ${PLUGINDIR}/osmetrics-cpu.so
        rm -f ${PLUGINDIR}/osmetrics-network.so
        rm -f ${PLUGINDIR}/osmetrics-loadavg.so
        rm -f ${PLUGINDIR}/osmetrics-swapinfo.so
        rm -f ${PLUGINDIR}/osmetrics-memory.so
        rm -f ${PLUGINDIR}/osmetrics-vmstat.so
        rm -f ${PLUGINDIR}/osmetrics-cpuinfo.so
        rm -f ${PLUGINDIR}/osmetrics-mounts.so
        rm -f ${PLUGINDIR}/osmetrics-misc.so
        rm -f ${PLUGINDIR}/osmetrics-diskstats.so
        rm -f ${PLUGINDIR}/osmetrics-version.so
        rm -f ${PLUGINDIR}/osmetrics-ioscheduler.so
	rm -f ${PLUGINDIR}/osmetrics-meminfo.so
	rm -f ${PLUGINDIR}/osmetrics-cpugovernor.so
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
        rm -f osmetrics-version.so
        rm -f osmetrics-ioscheduler.so
	rm -f osmetrics-meminfo.so
	rm -f osmetrics-cpugovernor.so

install:
        cp -f osmetrics-cpu.so ${PLUGINDIR}
        cp -f osmetrics-network.so ${PLUGINDIR}
        cp -f osmetrics-loadavg.so ${PLUGINDIR}
        cp -f osmetrics-swapinfo.so ${PLUGINDIR}
        cp -f osmetrics-memory.so ${PLUGINDIR}
        cp -f osmetrics-vmstat.so ${PLUGINDIR}
        cp -f osmetrics-cpuinfo.so ${PLUGINDIR}
        cp -f osmetrics-mounts.so ${PLUGINDIR}
        cp -f osmetrics-misc.so ${PLUGINDIR}
        cp -f osmetrics-diskstats.so ${PLUGINDIR}
        cp -f osmetrics-version.so ${PLUGINDIR}
        cp -f osmetrics-ioscheduler.so ${PLUGINDIR}   
        cp -f osmetrics-meminfo.so ${PLUGINDIR}
	cp -f osmetrics-cpugovernor.so ${PLUGINDIR}
	
uninstall:
	rm -f ${PLUGINDIR}/osmetrics-cpu.so
        rm -f ${PLUGINDIR}/osmetrics-network.so
        rm -f ${PLUGINDIR}/osmetrics-loadavg.so
        rm -f ${PLUGINDIR}/osmetrics-swapinfo.so
        rm -f ${PLUGINDIR}/osmetrics-memory.so
        rm -f ${PLUGINDIR}/osmetrics-vmstat.so
        rm -f ${PLUGINDIR}/osmetrics-cpuinfo.so
        rm -f ${PLUGINDIR}/osmetrics-mounts.so
        rm -f ${PLUGINDIR}/osmetrics-misc.so
        rm -f ${PLUGINDIR}/osmetrics-diskstats.so
        rm -f ${PLUGINDIR}/osmetrics-version.so
        rm -f ${PLUGINDIR}/osmetrics-ioscheduler.so
	rm -f ${PLUGINDIR}/osmetrics-meminfo.so
	rm -f ${PLUGINDIR}/osmetrics-cpugovernor.so
	
distclean:
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
        rm -f osmetrics-version.so
        rm -f osmetrics-ioscheduler.so
	rm -f osmetrics-meminfo.so
	rm -f osmetrics-cpugovernor.so
