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

osmetricsplugin.so: osmetricsplugin.c
        $(CC) $(CFLAGS) -o osmetricsplugin.so osmetricsplugin.c

clean:
      	rm -f /jet/var/mysqld/plugin/osmetricsplugin.so
        rm -f osmetricsplugin.so

install:
        cp -f osmetricsplugin.so /jet/var/mysqld/plugin/
