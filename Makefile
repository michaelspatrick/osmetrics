CC=g++
CFLAGS=-DMYSQL_DYNAMIC_PLUGIN -Wall -fPIC -shared \
-I/usr/include/mysql -m64 \
-I/home/ec2-user/percona-server-5.7.17-13/sql \
-I/home/ec2-user/percona-server-5.7.17-13/include \
-I/home/ec2-user/percona-server-5.7.17-13/libbinlogevents/export \
-I/home/ec2-user/percona-server-5.7.17-13/libbinlogevents/include \
-I/home/ec2-user/percona-server-5.7.17-13/sql \
-I/home/ec2-user/mysql_os_metrics-master/includes \
-I/home/ec2-user/mysql_os_metrics-master

osmetricsplugin.so: osmetricsplugin.cc
        $(CC) $(CFLAGS) -o osmetricsplugin.so osmetricsplugin.cc

clean:
      	rm -f /jet/var/mysqld/plugin/osmetricsplugin.so
        rm -f osmetricsplugin.so

install:
        cp -f osmetricsplugin.so /jet/var/mysqld/plugin/
