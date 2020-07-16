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

osmetricsplugin.so: osmetrics.c
        $(CC) $(CFLAGS) -o osmetrics.so osmetrics.c

clean:
      	rm -f /jet/var/mysqld/plugin/osmetrics.so
        rm -f osmetrics.so

install:
        cp -f osmetrics.so /jet/var/mysqld/plugin/
