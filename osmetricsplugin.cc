Last login: Tue Jun 23 15:17:49 on console

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
MichaelsMBP1480:~ mike-personal$ ls
Applications	Documents	Library		Music		Public
Desktop		Downloads	Movies		Pictures
MichaelsMBP1480:~ mike-personal$ scp 192.168.2.136:/home/michaelpatrick/osm.tar.gz .
The authenticity of host '192.168.2.136 (192.168.2.136)' can't be established.
ECDSA key fingerprint is SHA256:aZZSW7i42Ai+fuSTojpl8fX8ISDEj9ZCFsZn51Mvyys.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '192.168.2.136' (ECDSA) to the list of known hosts.
mike-personal@192.168.2.136's password: 
Permission denied, please try again.
mike-personal@192.168.2.136's password: 
MichaelsMBP1480:~ mike-personal$ scp root@192.168.2.136:/home/michaelpatrick/osm.tar.gz .
root@192.168.2.136's password: 
osm.tar.gz                                    100% 6849     2.7MB/s   00:00    
MichaelsMBP1480:~ mike-personal$ pwd
/Users/mike-personal
MichaelsMBP1480:~ mike-personal$ mv osm.tar.gz Desktop/
MichaelsMBP1480:~ mike-personal$ ssh -lroot 192.168.2.136
root@192.168.2.136's password: 
Last login: Tue Jun 23 15:35:23 2020
[root@localhost ~]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SHOW PLUGINS;
+-------------------------------+----------+--------------------+---------+---------+
| Name                          | Status   | Type               | Library | License |
+-------------------------------+----------+--------------------+---------+---------+
| binlog                        | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| mysql_native_password         | ACTIVE   | AUTHENTICATION     | NULL    | GPL     |
| sha256_password               | ACTIVE   | AUTHENTICATION     | NULL    | GPL     |
| PERFORMANCE_SCHEMA            | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| InnoDB                        | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| XTRADB_READ_VIEW              | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| XTRADB_INTERNAL_HASH_TABLES   | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| XTRADB_RSEG                   | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| XTRADB_ZIP_DICT               | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| XTRADB_ZIP_DICT_COLS          | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_TRX                    | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_LOCKS                  | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_LOCK_WAITS             | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CMP                    | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CMP_RESET              | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CMPMEM                 | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CMPMEM_RESET           | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CMP_PER_INDEX          | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CMP_PER_INDEX_RESET    | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_BUFFER_PAGE            | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_BUFFER_PAGE_LRU        | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_BUFFER_POOL_STATS      | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_TEMP_TABLE_INFO        | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_METRICS                | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_FT_DEFAULT_STOPWORD    | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_FT_DELETED             | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_FT_BEING_DELETED       | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_FT_CONFIG              | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_FT_INDEX_CACHE         | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_FT_INDEX_TABLE         | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_TABLES             | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_TABLESTATS         | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_INDEXES            | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_COLUMNS            | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_FIELDS             | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_FOREIGN            | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_FOREIGN_COLS       | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_TABLESPACES        | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_DATAFILES          | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_CHANGED_PAGES          | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_SYS_VIRTUAL            | ACTIVE   | INFORMATION SCHEMA | NULL    | GPL     |
| INNODB_TABLESPACES_ENCRYPTION | ACTIVE   | INFORMATION SCHEMA | NULL    | BSD     |
| INNODB_TABLESPACES_SCRUBBING  | ACTIVE   | INFORMATION SCHEMA | NULL    | BSD     |
| MEMORY                        | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| CSV                           | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| MyISAM                        | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| MRG_MYISAM                    | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| partition                     | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| FEDERATED                     | DISABLED | STORAGE ENGINE     | NULL    | GPL     |
| ARCHIVE                       | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| BLACKHOLE                     | ACTIVE   | STORAGE ENGINE     | NULL    | GPL     |
| ngram                         | ACTIVE   | FTPARSER           | NULL    | GPL     |
+-------------------------------+----------+--------------------+---------+---------+
52 rows in set (0.00 sec)

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1126 (HY000): Can't open shared library 'osmetricsplugin.so' (errno: 0 API version for INFORMATION SCHEMA plugin is too different)
mysql> quit
Bye
[root@localhost ~]# ls
anaconda-ks.cfg
[root@localhost ~]# cd /home/michaelpatrick/
[root@localhost michaelpatrick]# ls
getcpu.cpp  hyperic-sigar-1.6.4           osmetricsplugin           osmetricsplugin-3.tar.gz  osm.tar.gz                pt-summaries  test.sql
getmem      michaelpatrick@192.168.2.143  osmetricsplugin-2.tar.gz  osmetricsplugin.tar.gz    percona-server-5.7.24-27  sigar
[root@localhost michaelpatrick]# cd osmetricsplugin
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1126 (HY000): Can't open shared library 'osmetricsplugin.so' (errno: 0 API version for INFORMATION SCHEMA plugin is too different)
mysql> quit
Bye
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1030 (HY000): Got error 1 from storage engine
mysql> quit
Bye
[root@localhost osmetricsplugin]# nano moveit.sh 
[root@localhost osmetricsplugin]# ls -l /usr/lib
lib/     lib64/   libexec/ 
[root@localhost osmetricsplugin]# ls -l /usr/lib
lib/     lib64/   libexec/ 
[root@localhost osmetricsplugin]# ls -l /usr/lib64/
Display all 653 possibilities? (y or n)
audit/                                     libdhcpctl.so.0.0.0                        libkrb5.so.3                               libply.so.2.1.0
bind9-export/                              libdl-2.17.so                              libkrb5.so.3.3                             libply-splash-core.so.2
cmake/                                     libdl.so                                   libkrb5support.so                          libply-splash-core.so.2.1.0
cracklib_dict.hwm                          libdl.so.2                                 libkrb5support.so.0                        libpng15.so.15
cracklib_dict.pwd                          libdns.so.1102                             libkrb5support.so.0.1                      libpng15.so.15.13.0
cracklib_dict.pwi                          libdns.so.1102.1.2                         liblber-2.4.so.2                           libpolkit-agent-1.so.0
crt1.o                                     libdrm_amdgpu.so.1                         liblber-2.4.so.2.10.7                      libpolkit-agent-1.so.0.0.0
crti.o                                     libdrm_amdgpu.so.1.0.0                     libldap-2.4.so.2                           libpolkit-gobject-1.so.0
crtn.o                                     libdrm_intel.so.1                          libldap-2.4.so.2.10.7                      libpolkit-gobject-1.so.0.0.0
dbus-1/                                    libdrm_intel.so.1.0.0                      libldap_r-2.4.so.2                         libpopt.so.0
device-mapper/                             libdrm_nouveau.so.2                        libldap_r-2.4.so.2.10.7                    libpopt.so.0.0.0
ebtables/                                  libdrm_nouveau.so.2.0.0                    liblua-5.1.so                              libprocps.so.4
elfutils/                                  libdrm_radeon.so.1                         liblvm2app.so.2.2                          libprocps.so.4.0.0
fipscheck/                                 libdrm_radeon.so.1.0.1                     liblvm2cmd.so.2.02                         libpthread-2.17.so
games/                                     libdrm.so.2                                liblz4.so.1                                libpthread_nonshared.a
gconv/                                     libdrm.so.2.4.0                            liblz4.so.1.7.5                            libpthread.so
gcrt1.o                                    libdw-0.176.so                             liblzma.so.5                               libpthread.so.0
gettext/                                   libdw.so.1                                 liblzma.so.5.2.2                           libpth.so.20
gio/                                       libe2p.so.2                                liblzo2.so.2                               libpth.so.20.0.27
girepository-1.0/                          libe2p.so.2.3                              liblzo2.so.2.0.0                           libpwquality.so.1
golang/                                    libebtc.so                                 libm-2.17.so                               libpwquality.so.1.0.2
krb5/                                      libedit.so.0                               libmagic.so.1                              libpython2.7.so.1.0
ld-2.17.so                                 libedit.so.0.0.42                          libmagic.so.1.0.0                          libqrencode.so.3
ld-linux-x86-64.so.2                       libelf-0.176.so                            libmcheck.a                                libqrencode.so.3.4.1
libacl.so.1                                libelf.so.1                                libmemusage.so                             libreadline.so
libacl.so.1.1.0                            libestr.so.0                               libmenu.so                                 libreadline.so.6
libaio.so.1                                libestr.so.0.0.0                           libmenu.so.5                               libreadline.so.6.2
libaio.so.1.0.0                            libexpat.so.1                              libmenu.so.5.9                             libresolv-2.17.so
libaio.so.1.0.1                            libexpat.so.1.6.0                          libmenuw.so                                libresolv.so
libanl-2.17.so                             libext2fs.so.2                             libmenuw.so.5                              libresolv.so.2
libanl.so                                  libext2fs.so.2.4                           libmenuw.so.5.9                            librpcsvc.a
libanl.so.1                                libfastjson.so.4                           libmnl.so.0                                librpmbuild.so.3
libarchive.so.13                           libfastjson.so.4.0.0                       libmnl.so.0.1.0                            librpmbuild.so.3.2.2
libarchive.so.13.1.2                       libffi.so.6                                libmount.so.1                              librpmio.so.3
libasm-0.176.so                            libffi.so.6.0.1                            libmount.so.1.1.0                          librpmio.so.3.2.2
libasm.so.1                                libfipscheck.so.1                          libmozjs-17.0.so                           librpmsign.so.1
libasound.so.2                             libfipscheck.so.1.2.1                      libmpc.so.3                                librpmsign.so.1.2.2
libasound.so.2.0.0                         libform.so                                 libmpc.so.3.0.0                            librpm.so.3
libasprintf.so.0                           libform.so.5                               libmpfr.so.4                               librpm.so.3.2.2
libasprintf.so.0.0.0                       libform.so.5.9                             libmpfr.so.4.1.1                           librt-2.17.so
libassuan.so.0                             libformw.so                                libm.so                                    librt.so
libassuan.so.0.4.0                         libformw.so.5                              libm.so.6                                  librt.so.1
libattr.so.1                               libformw.so.5.9                            libncurses.so                              libsasl2.so.3
libattr.so.1.1.0                           libfreebl3.chk                             libncurses++.so                            libsasl2.so.3.0.0
[root@localhost osmetricsplugin]# ls -l /usr/lib64/mysql/
total 15512
-rw-r--r--  1 root root 4734646 Jan 22 05:12 libmysqlclient.a
-rwxr-xr-x  1 root root 3619736 Jan 22 05:08 libmysqlclient_r.so.18.1.0
lrwxrwxrwx  1 root root      20 May 13 11:15 libmysqlclient.so -> libmysqlclient.so.20
lrwxrwxrwx  1 root root      26 May 13 11:15 libmysqlclient.so.18 -> libmysqlclient_r.so.18.1.0
-rwxr-xr-x  1 root root 3619736 Jan 22 05:08 libmysqlclient.so.18.1.0
lrwxrwxrwx  1 root root      25 May 13 11:13 libmysqlclient.so.20 -> libmysqlclient.so.20.3.16
-rwxr-xr-x  1 root root 3883008 Jan 22 05:12 libmysqlclient.so.20.3.16
-rw-r--r--  1 root root   18398 Jan 22 05:12 libmysqlservices.a
drwxrwxr-x. 4 root root      28 Jan 22 05:08 mecab
drwxr-xr-x. 3 root root    4096 May 13 11:14 plugin
[root@localhost osmetricsplugin]# cat moveit.sh 
cp -f osmetricsplugin.so /usr/lib64/mysql/plugin/
[root@localhost osmetricsplugin]# ls -l /usr/lib64/mysql/plugin/
total 5520
-rwxr-xr-x  1 root root   22464 Jan 22 05:12 adt_null.so
-rwxr-xr-x  1 root root   64984 Jan 22 05:12 audit_log.so
-rwxr-xr-x  1 root root   40760 Jan 22 05:12 authentication_ldap_sasl_client.so
-rwxr-xr-x  1 root root   16072 Jan 22 05:12 auth_pam_compat.so
-rwxr-xr-x  1 root root   16096 Jan 22 05:12 auth_pam.so
-rwxr-xr-x  1 root root   11920 Jan 22 05:12 auth.so
-rwxr-xr-x  1 root root    7448 Jan 22 05:12 auth_socket.so
-rwxr-xr-x  1 root root   50280 Jan 22 05:12 connection_control.so
drwxr-xr-x. 2 root root    4096 May 13 11:14 debug
-rwxr-xr-x  1 root root   11952 Jan 22 05:12 dialog.so
-rwxr-xr-x  1 root root 1265272 Jan 22 05:12 group_replication.so
-rwxr-xr-x  1 root root   45920 Jan 22 05:12 ha_example.so
-rwxr-xr-x  1 root root  108384 Jan 22 05:12 innodb_engine.so
-rwxr-xr-x  1 root root  102496 Jan 22 05:12 keyring_file.so
-rwxr-xr-x  1 root root   20040 Jan 22 05:12 keyring_udf.so
-rwxr-xr-x  1 root root  182304 Jan 22 05:12 keyring_vault.so
-rwxr-xr-x  1 root root    6936 Jan 22 05:12 libfnv1a_udf.so
-rwxr-xr-x  1 root root    6928 Jan 22 05:12 libfnv_udf.so
-rwxr-xr-x  1 root root  268344 Jan 22 05:12 libmemcached.so
-rwxr-xr-x  1 root root    6936 Jan 22 05:12 libmurmur_udf.so
-rwxr-xr-x  1 root root 1316000 Jan 22 05:12 libpluginmecab.so
-rwxr-xr-x  1 root root   10992 Jan 22 05:12 locking_service.so
-rwxr-xr-x  1 root root   11992 Jan 22 05:12 mypluglib.so
-rwxr-xr-x  1 root root    7328 Jan 22 05:12 mysql_no_login.so
-rwxr-xr-x  1 root root 1719688 Jan 22 05:12 mysqlx.so
-rwxr-xr-x  1 root root   15008 Jun 23 15:50 osmetricsplugin.so
-rwxr-xr-x  1 root root   16880 Jan 22 05:12 query_response_time.so
-rwxr-xr-x  1 root root    7536 Jan 22 05:12 rewrite_example.so
-rwxr-xr-x  1 root root   54056 Jan 22 05:12 rewriter.so
-rwxr-xr-x  1 root root   16400 Jan 22 05:12 scalability_metrics.so
-rwxr-xr-x  1 root root   63408 Jan 22 05:12 semisync_master.so
-rwxr-xr-x  1 root root   16224 Jan 22 05:12 semisync_slave.so
-rwxr-xr-x  1 root root   19808 Jan 22 05:12 udf_example.so
-rwxr-xr-x  1 root root   29408 Jan 22 05:12 validate_password.so
-rwxr-xr-x  1 root root   33072 Jan 22 05:12 version_token.so
[root@localhost osmetricsplugin]# ls -l
total 36
-rwxr-xr-x 1 root root   724 Jan 30  2019 compile
drwxr-xr-x 2 root root    62 Jan 31  2019 includes
-rw-r--r-- 1 root root    55 Jan 30  2019 install_plugin.sql
-rwxr-xr-x 1 root root    50 Jan 30  2019 moveit.sh
drwxr-xr-x 2 root root    28 Jan 30  2019 OLD
-rw-r--r-- 1 root root  2337 Jan 31  2019 osmetricsplugin.cc
-rwxr-xr-x 1 root root 15008 Jun 23 15:50 osmetricsplugin.so
-rw-r--r-- 1 root root    29 Jan 30  2019 uninstall_plugin.sh
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# cat compile 
SRCBASE="../percona-server-5.7.24-27"
g++ -DMYSQL_DYNAMIC_PLUGIN -Wall -fPIC -shared \
-I/usr/include/mysql -m64 \
-I${SRCBASE}/sql \
-I${SRCBASE}/include \
-I${SRCBASE}/libbinlogevents/export \
-I${SRCBASE}/libbinlogevents/include \
-I/home/michaelpatrick/osmetricsplugin \
-o osmetricsplugin.so osmetricsplugin.cc


#-I${SRCBASE}/build-ps/rpm/ \

#SRCBASE="../percona-server-5.7.24-27"
#g++ -DMYSQL_DYNAMIC_PLUGIN -Wall -fPIC -shared -I${SRCBASE}/zlib -I${SRCBASE}/libbinlogevents/include \
#-I${SRCBASE}/libbinlogevents/export/ -I${SRCBASE}/include -I${SRCBASE}/regex -I${SRCBASE}/sql \
#-I${SRCBASE}/packaging/rpm-common \
#-I/usr/include/mysql \
#-o osmetricsplugin.so osmetricsplugin.cc

#-I${SRCBASE}/build-ps/rpm/ \
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 5
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT @@VERSION;
+---------------+
| @@VERSION     |
+---------------+
| 5.7.29-32-log |
+---------------+
1 row in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# nano compile 
[root@localhost osmetricsplugin]# ls ../percona-server-5.7.24-27/
archive_output_directory  cmake           configure.cmake                      Docs                 libbinlogevents      man         policy        sql            unittest
boost_1_59_0              CMakeCache.txt  COPYING                              Doxyfile-perfschema  libbinlogstandalone  mysql-test  rapid         sql-common     VERSION
boost_1_59_0.tar.gz       CMakeFiles      COPYING.innodb-deadlock-count-patch  extra                libevent             mysys       README        storage        VERSION.dep
BUILD                     CMakeLists.txt  COPYING.show_temp_51                 include              libmysql             mysys_ssl   README.MySQL  strings        vio
build-ps                  cmd-line-utils  dbug                                 INSTALL              libmysqld            packaging   regex         support-files  win
client                    config.h.cmake  doc                                  internal             libservices          plugin      scripts       testclients    zlib
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# ps ax | grep mysql
 1387 pts/0    R+     0:00 grep --color=auto mysql
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# cd ../percona-server-5.7.24-27/
[root@localhost percona-server-5.7.24-27]# ls
archive_output_directory  cmake           configure.cmake                      Docs                 libbinlogevents      man         policy        sql            unittest
boost_1_59_0              CMakeCache.txt  COPYING                              Doxyfile-perfschema  libbinlogstandalone  mysql-test  rapid         sql-common     VERSION
boost_1_59_0.tar.gz       CMakeFiles      COPYING.innodb-deadlock-count-patch  extra                libevent             mysys       README        storage        VERSION.dep
BUILD                     CMakeLists.txt  COPYING.show_temp_51                 include              libmysql             mysys_ssl   README.MySQL  strings        vio
build-ps                  cmd-line-utils  dbug                                 INSTALL              libmysqld            packaging   regex         support-files  win
client                    config.h.cmake  doc                                  internal             libservices          plugin      scripts       testclients    zlib
[root@localhost percona-server-5.7.24-27]# yum install perconaserver*
Loaded plugins: fastestmirror
Determining fastest mirrors
 * base: mirror.atlantic.net
 * extras: mirrors.usinternet.com
 * updates: mirror.atlantic.net
base                                                                                                                                                           | 3.6 kB  00:00:00     
extras                                                                                                                                                         | 2.9 kB  00:00:00     
percona-release-noarch                                                                                                                                         | 2.9 kB  00:00:00     
percona-release-x86_64                                                                                                                                         | 2.9 kB  00:00:00     
updates                                                                                                                                                        | 2.9 kB  00:00:00     
(1/4): percona-release-noarch/7/primary_db                                                                                                                     |  23 kB  00:00:00     
(2/4): extras/7/x86_64/primary_db                                                                                                                              | 194 kB  00:00:00     
(3/4): percona-release-x86_64/7/primary_db                                                                                                                     | 1.1 MB  00:00:00     
(4/4): updates/7/x86_64/primary_db                                                                                                                             | 2.1 MB  00:00:01     
No package perconaserver* available.
Error: Nothing to do
[root@localhost percona-server-5.7.24-27]# yum install percona*
Loaded plugins: fastestmirror
Loading mirror speeds from cached hostfile
 * base: mirror.atlantic.net
 * extras: mirrors.usinternet.com
 * updates: mirror.atlantic.net
Package percona-toolkit-3.2.0-1.el7.x86_64 already installed and latest version
Resolving Dependencies
--> Running transaction check
---> Package percona-cacti-templates.noarch 0:1.1.8-1 will be installed
--> Processing Dependency: cacti >= 0.8.6 for package: percona-cacti-templates-1.1.8-1.noarch
---> Package percona-nagios-plugins.noarch 0:1.1.8-1 will be installed
---> Package percona-release.noarch 0:1.0-17 will be updated
---> Package percona-release.noarch 0:1.0-20 will be an update
---> Package percona-toolkit-debuginfo.x86_64 0:3.0.13-1.el7 will be installed
---> Package percona-xtrabackup.x86_64 0:2.3.10-1.el7 will be installed
--> Processing Dependency: libev.so.4()(64bit) for package: percona-xtrabackup-2.3.10-1.el7.x86_64
---> Package percona-xtrabackup-22.x86_64 0:2.2.13-1.el7 will be installed
---> Package percona-xtrabackup-22-debuginfo.x86_64 0:2.2.13-1.el7 will be installed
---> Package percona-xtrabackup-24.x86_64 0:2.4.20-1.el7 will be installed
---> Package percona-xtrabackup-24-debuginfo.x86_64 0:2.4.20-1.el7 will be installed
---> Package percona-xtrabackup-80.x86_64 0:8.0.13-1.el7 will be installed
---> Package percona-xtrabackup-80-debuginfo.x86_64 0:8.0.13-1.el7 will be installed
---> Package percona-xtrabackup-debuginfo.x86_64 0:2.3.10-1.el7 will be installed
---> Package percona-xtrabackup-test.x86_64 0:2.3.10-1.el7 will be installed
---> Package percona-xtrabackup-test-22.x86_64 0:2.2.13-1.el7 will be installed
--> Processing Dependency: percona-xtrabackup-2.2.13 = 2.2.13-1.el7 for package: percona-xtrabackup-test-22-2.2.13-1.el7.x86_64
---> Package percona-xtrabackup-test-24.x86_64 0:2.4.20-1.el7 will be installed
---> Package percona-xtrabackup-test-80.x86_64 0:8.0.13-1.el7 will be installed
---> Package percona-zabbix-templates.noarch 0:1.1.8-1 will be installed
--> Running transaction check
---> Package libev.x86_64 0:4.15-7.el7 will be installed
---> Package percona-cacti-templates.noarch 0:1.1.8-1 will be installed
--> Processing Dependency: cacti >= 0.8.6 for package: percona-cacti-templates-1.1.8-1.noarch
---> Package percona-xtrabackup-test-22.x86_64 0:2.2.13-1.el7 will be installed
--> Processing Dependency: percona-xtrabackup-2.2.13 = 2.2.13-1.el7 for package: percona-xtrabackup-test-22-2.2.13-1.el7.x86_64
--> Processing Conflict: percona-xtrabackup-24-2.4.20-1.el7.x86_64 conflicts percona-xtrabackup-22
--> Processing Conflict: percona-xtrabackup-24-2.4.20-1.el7.x86_64 conflicts percona-xtrabackup
--> Processing Conflict: percona-xtrabackup-80-8.0.13-1.el7.x86_64 conflicts percona-xtrabackup-24
--> Processing Conflict: percona-xtrabackup-80-8.0.13-1.el7.x86_64 conflicts percona-xtrabackup
--> Processing Conflict: percona-xtrabackup-80-8.0.13-1.el7.x86_64 conflicts percona-xtrabackup-22
--> Processing Conflict: percona-xtrabackup-2.3.10-1.el7.x86_64 conflicts percona-xtrabackup-22
--> Processing Conflict: percona-xtrabackup-22-2.2.13-1.el7.x86_64 conflicts percona-xtrabackup
--> Finished Dependency Resolution
Error: percona-xtrabackup-80 conflicts with percona-xtrabackup-24-2.4.20-1.el7.x86_64
Error: percona-xtrabackup-24 conflicts with percona-xtrabackup-22-2.2.13-1.el7.x86_64
Error: percona-xtrabackup-80 conflicts with percona-xtrabackup-22-2.2.13-1.el7.x86_64
Error: percona-xtrabackup-80 conflicts with percona-xtrabackup-2.3.10-1.el7.x86_64
Error: Package: percona-xtrabackup-test-22-2.2.13-1.el7.x86_64 (percona-release-x86_64)
           Requires: percona-xtrabackup-2.2.13 = 2.2.13-1.el7
Error: Package: percona-cacti-templates-1.1.8-1.noarch (percona-release-noarch)
           Requires: cacti >= 0.8.6
Error: percona-xtrabackup-24 conflicts with percona-xtrabackup-2.3.10-1.el7.x86_64
Error: percona-xtrabackup-22 conflicts with percona-xtrabackup-2.3.10-1.el7.x86_64
Error: percona-xtrabackup conflicts with percona-xtrabackup-22-2.2.13-1.el7.x86_64
 You could try using --skip-broken to work around the problem
 You could try running: rpm -Va --nofiles --nodigest
[root@localhost percona-server-5.7.24-27]# ls
archive_output_directory  cmake           configure.cmake                      Docs                 libbinlogevents      man         policy        sql            unittest
boost_1_59_0              CMakeCache.txt  COPYING                              Doxyfile-perfschema  libbinlogstandalone  mysql-test  rapid         sql-common     VERSION
boost_1_59_0.tar.gz       CMakeFiles      COPYING.innodb-deadlock-count-patch  extra                libevent             mysys       README        storage        VERSION.dep
BUILD                     CMakeLists.txt  COPYING.show_temp_51                 include              libmysql             mysys_ssl   README.MySQL  strings        vio
build-ps                  cmd-line-utils  dbug                                 INSTALL              libmysqld            packaging   regex         support-files  win
client                    config.h.cmake  doc                                  internal             libservices          plugin      scripts       testclients    zlib
[root@localhost percona-server-5.7.24-27]# cat INSTALL 
Pre-built binaries in different package formats can be found on

  http://www.mysql.com/downloads

You can find information about how to install from a source distribution at

  http://dev.mysql.com/doc/refman/5.7/en/source-installation.html

The MySQL 5.7 Reference Manual is available on

  http://dev.mysql.com/doc/refman/5.7/en/
[root@localhost percona-server-5.7.24-27]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost percona-server-5.7.24-27]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT @@VERSION;
+---------------+
| @@VERSION     |
+---------------+
| 5.7.29-32-log |
+---------------+
1 row in set (0.00 sec)

mysql> quit
Bye
[root@localhost percona-server-5.7.24-27]# ls
archive_output_directory  cmake           configure.cmake                      Docs                 libbinlogevents      man         policy        sql            unittest
boost_1_59_0              CMakeCache.txt  COPYING                              Doxyfile-perfschema  libbinlogstandalone  mysql-test  rapid         sql-common     VERSION
boost_1_59_0.tar.gz       CMakeFiles      COPYING.innodb-deadlock-count-patch  extra                libevent             mysys       README        storage        VERSION.dep
BUILD                     CMakeLists.txt  COPYING.show_temp_51                 include              libmysql             mysys_ssl   README.MySQL  strings        vio
build-ps                  cmd-line-utils  dbug                                 INSTALL              libmysqld            packaging   regex         support-files  win
client                    config.h.cmake  doc                                  internal             libservices          plugin      scripts       testclients    zlib
[root@localhost percona-server-5.7.24-27]# cd ../osmetricsplugin
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# cat install_plugin.sql 
INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SHOW PLUGINS;
+-------------------------------+----------+--------------------+--------------------+---------+
| Name                          | Status   | Type               | Library            | License |
+-------------------------------+----------+--------------------+--------------------+---------+
| binlog                        | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| mysql_native_password         | ACTIVE   | AUTHENTICATION     | NULL               | GPL     |
| sha256_password               | ACTIVE   | AUTHENTICATION     | NULL               | GPL     |
| PERFORMANCE_SCHEMA            | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| InnoDB                        | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| XTRADB_READ_VIEW              | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| XTRADB_INTERNAL_HASH_TABLES   | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| XTRADB_RSEG                   | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| XTRADB_ZIP_DICT               | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| XTRADB_ZIP_DICT_COLS          | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_TRX                    | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_LOCKS                  | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_LOCK_WAITS             | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CMP                    | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CMP_RESET              | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CMPMEM                 | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CMPMEM_RESET           | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CMP_PER_INDEX          | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CMP_PER_INDEX_RESET    | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_BUFFER_PAGE            | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_BUFFER_PAGE_LRU        | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_BUFFER_POOL_STATS      | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_TEMP_TABLE_INFO        | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_METRICS                | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_FT_DEFAULT_STOPWORD    | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_FT_DELETED             | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_FT_BEING_DELETED       | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_FT_CONFIG              | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_FT_INDEX_CACHE         | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_FT_INDEX_TABLE         | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_TABLES             | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_TABLESTATS         | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_INDEXES            | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_COLUMNS            | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_FIELDS             | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_FOREIGN            | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_FOREIGN_COLS       | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_TABLESPACES        | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_DATAFILES          | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_CHANGED_PAGES          | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_SYS_VIRTUAL            | ACTIVE   | INFORMATION SCHEMA | NULL               | GPL     |
| INNODB_TABLESPACES_ENCRYPTION | ACTIVE   | INFORMATION SCHEMA | NULL               | BSD     |
| INNODB_TABLESPACES_SCRUBBING  | ACTIVE   | INFORMATION SCHEMA | NULL               | BSD     |
| MEMORY                        | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| CSV                           | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| MyISAM                        | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| MRG_MYISAM                    | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| partition                     | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| FEDERATED                     | DISABLED | STORAGE ENGINE     | NULL               | GPL     |
| ARCHIVE                       | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| BLACKHOLE                     | ACTIVE   | STORAGE ENGINE     | NULL               | GPL     |
| ngram                         | ACTIVE   | FTPARSER           | NULL               | GPL     |
| OS_METRICS                    | ACTIVE   | INFORMATION SCHEMA | osmetricsplugin.so | GPL     |
+-------------------------------+----------+--------------------+--------------------+---------+
53 rows in set (0.00 sec)

mysql> SELECT * FROM OS_METRICS;
ERROR 1046 (3D000): No database selected
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
+---------------+------------+
4 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
+---------------+------------+
4 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
+---------------+------------+
4 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# cd in
-bash: cd: in: No such file or directory
[root@localhost osmetricsplugin]# cd includes/
[root@localhost includes]# ls
getload.h  getmem.h  getswappiness.h
[root@localhost includes]# cp getmem.h 
cp: missing destination file operand after ‘getmem.h’
Try 'cp --help' for more information.
[root@localhost includes]# nano getmem.h 
[root@localhost includes]# nano getrusage.h
[root@localhost includes]# ls
getload.h  getmem.h  getrusage.h  getswappiness.h
[root@localhost includes]# cd ..
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
In file included from osmetricsplugin.cc:11:0:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:4:8: error: expected identifier before ‘*’ token
 struct *usage getRUsage( )
        ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:4:15: error: expected initializer before ‘getRUsage’
 struct *usage getRUsage( )
               ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getrusage.h 
[root@localhost osmetricsplugin]# ./compile 
In file included from osmetricsplugin.cc:11:0:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:4:8: error: expected identifier before ‘*’ token
 struct * getRUsage( )
        ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h: In function ‘int* getRUsage()’:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:6:13: error: expected primary-expression before ‘int’
   getrusage(int who, struct rusage *usage);
             ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:6:22: error: expected primary-expression before ‘struct’
   getrusage(int who, struct rusage *usage);
                      ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:7:16: error: expected primary-expression before ‘;’ token
   return rusage;
                ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:8:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
[root@localhost osmetricsplugin]# nano includes/getrusage.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
In file included from osmetricsplugin.cc:11:0:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:4:8: error: expected identifier before ‘*’ token
 struct * getRUsage( )
        ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h: In function ‘int* getRUsage()’:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:6:13: error: expected primary-expression before ‘int’
   getrusage(int who, struct rusage *usage);
             ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:6:22: error: expected primary-expression before ‘struct’
   getrusage(int who, struct rusage *usage);
                      ^
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:7:16: error: expected primary-expression before ‘;’ token
   return rusage;
                ^
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:52:13: error: expected primary-expression before ‘int’
   getrusage(int who, struct rusage *usage);
             ^
osmetricsplugin.cc:52:22: error: expected primary-expression before ‘struct’
   getrusage(int who, struct rusage *usage);
                      ^
osmetricsplugin.cc:53:32: error: expected primary-expression before ‘.’ token
   table->field[1]->store(rusage.ru_maxrss);
                                ^
In file included from osmetricsplugin.cc:11:0:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h: In function ‘int* getRUsage()’:
/home/michaelpatrick/osmetricsplugin/includes/getrusage.h:8:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:51:13: error: expected primary-expression before ‘int’
   getrusage(int who, struct rusage *usage);
             ^
osmetricsplugin.cc:51:22: error: expected primary-expression before ‘struct’
   getrusage(int who, struct rusage *usage);
                      ^
osmetricsplugin.cc:52:32: error: expected primary-expression before ‘.’ token
   table->field[1]->store(rusage.ru_maxrss);
                                ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql restart
Redirecting to /bin/systemctl restart mysql.service
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.04 |
| LOADAVG_5MIN  |       0.03 |
| LOADAVG_15MIN |       0.05 |
| TEST OS_METRI |     184844 |
+---------------+------------+
5 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# cat /proc/cpuinfo 
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 61
model name	: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz
stepping	: 4
cpu MHz		: 2699.998
cache size	: 3072 KB
physical id	: 0
siblings	: 1
core id		: 0
cpu cores	: 1
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 20
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc eagerfpu pni pclmulqdq monitor ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single fsgsbase avx2 invpcid rdseed md_clear flush_l1d
bogomips	: 5399.99
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

[root@localhost osmetricsplugin]# cat /proc/meminfo 
MemTotal:        1014764 kB
MemFree:          349920 kB
MemAvailable:     574240 kB
Buffers:            2108 kB
Cached:           344084 kB
SwapCached:            0 kB
Active:           427000 kB
Inactive:         161668 kB
Active(anon):     242756 kB
Inactive(anon):     6612 kB
Active(file):     184244 kB
Inactive(file):   155056 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:        839676 kB
SwapFree:         839676 kB
Dirty:               576 kB
Writeback:             0 kB
AnonPages:        242508 kB
Mapped:            28236 kB
Shmem:              6892 kB
Slab:              38452 kB
SReclaimable:      25588 kB
SUnreclaim:        12864 kB
KernelStack:        2208 kB
PageTables:         4884 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     1347056 kB
Committed_AS:     850456 kB
VmallocTotal:   34359738367 kB
VmallocUsed:        5740 kB
VmallocChunk:   34359729152 kB
Percpu:              176 kB
HardwareCorrupted:     0 kB
AnonHugePages:    110592 kB
CmaTotal:              0 kB
CmaFree:               0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
DirectMap4k:       53184 kB
DirectMap2M:      995328 kB
[root@localhost osmetricsplugin]# quit
-bash: quit: command not found
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| STIME_TV_SEC  |          0 |
| MAXRSS IXRSS  |     190112 |
| IXRSS IDRSS I |          0 |
| IDRSS ISRSS M |          0 |
| ISRSS MINFLT  |          0 |
| MINFLT MAJFLT |      23301 |
| MAJFLT NSWAP  |          0 |
| NSWAP INBLOCK |          0 |
| INBLOCK OUBLO |          0 |
| OUBLOCK MSGSN |      33592 |
| MSGSND MSGRCV |          0 |
| MSGRCV NSIGNA |          0 |
| NSIGNALS NVCS |          0 |
| NVCSW NIVCSW  |        303 |
| NIVCSW OS_MET |         33 |
+---------------+------------+
20 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# meminfo
-bash: meminfo: command not found
[root@localhost osmetricsplugin]# cat /proc/meminfo | grep -i rss
[root@localhost osmetricsplugin]# cat /proc/meminfo | grep -i vss
[root@localhost osmetricsplugin]# cat /proc/cpuinfo | grep -i vss
[root@localhost osmetricsplugin]# cat /proc/cpuinfo | grep -i rss
[root@localhost osmetricsplugin]# iostat
Linux 3.10.0-1127.el7.x86_64 (localhost.localdomain) 	06/23/2020 	_x86_64_	(1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.19    0.00    0.13    0.02    0.00   99.66

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda               1.99        65.11        28.23     332911     144320
dm-0              1.60        62.75        27.82     320798     142252
dm-1              0.02         0.43         0.00       2204          0

[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          0 |
| STIME_TV_SEC  |          0 |
| MAXRSS        |     186004 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      24397 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32360 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        100 |
| NIVCSW        |          7 |
+---------------+------------+
20 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ps
  PID TTY          TIME CMD
 1309 pts/0    00:00:00 bash
 2071 pts/0    00:00:00 ps
[root@localhost osmetricsplugin]# ps ax
  PID TTY      STAT   TIME COMMAND
    1 ?        Ss     0:00 /usr/lib/systemd/systemd --switched-root --system --deserialize 22
    2 ?        S      0:00 [kthreadd]
    4 ?        S<     0:00 [kworker/0:0H]
    6 ?        S      0:00 [ksoftirqd/0]
    7 ?        S      0:00 [migration/0]
    8 ?        S      0:00 [rcu_bh]
    9 ?        R      0:00 [rcu_sched]
   10 ?        S<     0:00 [lru-add-drain]
   11 ?        S      0:00 [watchdog/0]
   13 ?        S      0:00 [kdevtmpfs]
   14 ?        S<     0:00 [netns]
   15 ?        S      0:00 [khungtaskd]
   16 ?        S<     0:00 [writeback]
   17 ?        S<     0:00 [kintegrityd]
   18 ?        S<     0:00 [bioset]
   19 ?        S<     0:00 [bioset]
   20 ?        S<     0:00 [bioset]
   21 ?        S<     0:00 [kblockd]
   22 ?        S<     0:00 [md]
   23 ?        S<     0:00 [edac-poller]
   24 ?        S<     0:00 [watchdogd]
   30 ?        S      0:00 [kswapd0]
   31 ?        SN     0:00 [ksmd]
   32 ?        SN     0:00 [khugepaged]
   33 ?        S<     0:00 [crypto]
   41 ?        S<     0:00 [kthrotld]
   43 ?        S<     0:00 [kmpath_rdacd]
   44 ?        S<     0:00 [kaluad]
   45 ?        S<     0:00 [kpsmoused]
   46 ?        S<     0:00 [ipv6_addrconf]
   60 ?        S<     0:00 [deferwq]
   95 ?        S      0:00 [kauditd]
  270 ?        S<     0:00 [ata_sff]
  281 ?        S      0:00 [scsi_eh_0]
  283 ?        S<     0:00 [scsi_tmf_0]
  284 ?        S      0:00 [scsi_eh_1]
  285 ?        S<     0:00 [scsi_tmf_1]
  286 ?        S      0:00 [scsi_eh_2]
  288 ?        S      0:00 [kworker/u2:3]
  289 ?        S<     0:00 [scsi_tmf_2]
  318 ?        S<     0:00 [kworker/0:1H]
  359 ?        S<     0:00 [kdmflush]
  360 ?        S<     0:00 [bioset]
  369 ?        S<     0:00 [kdmflush]
  370 ?        S<     0:00 [bioset]
  383 ?        S<     0:00 [bioset]
  384 ?        S<     0:00 [xfsalloc]
  385 ?        S<     0:00 [xfs_mru_cache]
  386 ?        S<     0:00 [xfs-buf/dm-0]
  387 ?        S<     0:00 [xfs-data/dm-0]
  388 ?        S<     0:00 [xfs-conv/dm-0]
  389 ?        S<     0:00 [xfs-cil/dm-0]
  390 ?        S<     0:00 [xfs-reclaim/dm-]
  391 ?        S<     0:00 [xfs-log/dm-0]
  392 ?        S<     0:00 [xfs-eofblocks/d]
  393 ?        S      0:00 [xfsaild/dm-0]
  471 ?        Ss     0:00 /usr/lib/systemd/systemd-journald
  493 ?        Ss     0:00 /usr/sbin/lvmetad -f
  500 ?        Ss     0:00 /usr/lib/systemd/systemd-udevd
  546 ?        S<     0:00 [xfs-buf/sda1]
  548 ?        S<     0:00 [xfs-data/sda1]
  550 ?        S<     0:00 [xfs-conv/sda1]
  552 ?        S<     0:00 [xfs-cil/sda1]
  554 ?        S<     0:00 [xfs-reclaim/sda]
  555 ?        S<     0:00 [xfs-log/sda1]
  558 ?        S<     0:00 [xfs-eofblocks/s]
  561 ?        S      0:00 [xfsaild/sda1]
  607 ?        S<sl   0:00 /sbin/auditd
  629 ?        Ss     0:00 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation
  631 ?        Ssl    0:00 /usr/lib/polkit-1/polkitd --no-debug
  634 ?        Ss     0:00 /usr/lib/systemd/systemd-logind
  642 ?        Ss     0:00 /usr/sbin/crond -n
  647 ?        S      0:00 /usr/sbin/chronyd
  649 ?        Ss     0:00 login -- root
  664 ?        Ssl    0:00 /usr/bin/python2 -Es /usr/sbin/firewalld --nofork --nopid
  665 ?        Ssl    0:00 /usr/sbin/NetworkManager --no-daemon
  793 ?        S      0:00 /sbin/dhclient -d -q -sf /usr/libexec/nm-dhcp-helper -pf /var/run/dhclient-enp0s3.pid -lf /var/lib/NetworkManager/dhclient-389fb7e2-ee6a-39e3-b60c-0a2f6395
 1066 ?        Ss     0:00 /usr/sbin/sshd -D
 1067 ?        Ssl    0:00 /usr/bin/python2 -Es /usr/sbin/tuned -l -P
 1068 ?        Ssl    0:00 /usr/sbin/rsyslogd -n
 1202 ?        S<     0:00 [dio/dm-0]
 1205 ?        Ss     0:00 /usr/libexec/postfix/master -w
 1206 ?        S      0:00 pickup -l -t unix -u
 1207 ?        S      0:00 qmgr -l -t unix -u
 1242 tty1     Ss+    0:00 -bash
 1305 ?        Ss     0:00 sshd: root@pts/0
 1309 pts/0    Ss     0:00 -bash
 1533 ?        Ss     0:00 /usr/sbin/anacron -s
 1776 ?        S      0:00 [kworker/u2:0]
 1868 ?        S      0:00 [kworker/0:1]
 1968 ?        S      0:00 [kworker/0:3]
 2036 ?        Sl     0:01 /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2068 ?        R      0:00 [kworker/0:0]
 2072 pts/0    R+     0:00 ps ax
[root@localhost osmetricsplugin]# ps -ef
UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0  0 15:34 ?        00:00:00 /usr/lib/systemd/systemd --switched-root --system --deserialize 22
root         2     0  0 15:34 ?        00:00:00 [kthreadd]
root         4     2  0 15:34 ?        00:00:00 [kworker/0:0H]
root         6     2  0 15:34 ?        00:00:00 [ksoftirqd/0]
root         7     2  0 15:34 ?        00:00:00 [migration/0]
root         8     2  0 15:34 ?        00:00:00 [rcu_bh]
root         9     2  0 15:34 ?        00:00:00 [rcu_sched]
root        10     2  0 15:34 ?        00:00:00 [lru-add-drain]
root        11     2  0 15:34 ?        00:00:00 [watchdog/0]
root        13     2  0 15:34 ?        00:00:00 [kdevtmpfs]
root        14     2  0 15:34 ?        00:00:00 [netns]
root        15     2  0 15:34 ?        00:00:00 [khungtaskd]
root        16     2  0 15:34 ?        00:00:00 [writeback]
root        17     2  0 15:34 ?        00:00:00 [kintegrityd]
root        18     2  0 15:34 ?        00:00:00 [bioset]
root        19     2  0 15:34 ?        00:00:00 [bioset]
root        20     2  0 15:34 ?        00:00:00 [bioset]
root        21     2  0 15:34 ?        00:00:00 [kblockd]
root        22     2  0 15:34 ?        00:00:00 [md]
root        23     2  0 15:34 ?        00:00:00 [edac-poller]
root        24     2  0 15:34 ?        00:00:00 [watchdogd]
root        30     2  0 15:34 ?        00:00:00 [kswapd0]
root        31     2  0 15:34 ?        00:00:00 [ksmd]
root        32     2  0 15:34 ?        00:00:00 [khugepaged]
root        33     2  0 15:34 ?        00:00:00 [crypto]
root        41     2  0 15:34 ?        00:00:00 [kthrotld]
root        43     2  0 15:34 ?        00:00:00 [kmpath_rdacd]
root        44     2  0 15:34 ?        00:00:00 [kaluad]
root        45     2  0 15:34 ?        00:00:00 [kpsmoused]
root        46     2  0 15:34 ?        00:00:00 [ipv6_addrconf]
root        60     2  0 15:34 ?        00:00:00 [deferwq]
root        95     2  0 15:34 ?        00:00:00 [kauditd]
root       270     2  0 15:34 ?        00:00:00 [ata_sff]
root       281     2  0 15:34 ?        00:00:00 [scsi_eh_0]
root       283     2  0 15:34 ?        00:00:00 [scsi_tmf_0]
root       284     2  0 15:34 ?        00:00:00 [scsi_eh_1]
root       285     2  0 15:34 ?        00:00:00 [scsi_tmf_1]
root       286     2  0 15:34 ?        00:00:00 [scsi_eh_2]
root       288     2  0 15:34 ?        00:00:00 [kworker/u2:3]
root       289     2  0 15:34 ?        00:00:00 [scsi_tmf_2]
root       318     2  0 15:34 ?        00:00:00 [kworker/0:1H]
root       359     2  0 15:34 ?        00:00:00 [kdmflush]
root       360     2  0 15:34 ?        00:00:00 [bioset]
root       369     2  0 15:34 ?        00:00:00 [kdmflush]
root       370     2  0 15:34 ?        00:00:00 [bioset]
root       383     2  0 15:34 ?        00:00:00 [bioset]
root       384     2  0 15:34 ?        00:00:00 [xfsalloc]
root       385     2  0 15:34 ?        00:00:00 [xfs_mru_cache]
root       386     2  0 15:34 ?        00:00:00 [xfs-buf/dm-0]
root       387     2  0 15:34 ?        00:00:00 [xfs-data/dm-0]
root       388     2  0 15:34 ?        00:00:00 [xfs-conv/dm-0]
root       389     2  0 15:34 ?        00:00:00 [xfs-cil/dm-0]
root       390     2  0 15:34 ?        00:00:00 [xfs-reclaim/dm-]
root       391     2  0 15:34 ?        00:00:00 [xfs-log/dm-0]
root       392     2  0 15:34 ?        00:00:00 [xfs-eofblocks/d]
root       393     2  0 15:34 ?        00:00:00 [xfsaild/dm-0]
root       471     1  0 15:34 ?        00:00:00 /usr/lib/systemd/systemd-journald
root       493     1  0 15:34 ?        00:00:00 /usr/sbin/lvmetad -f
root       500     1  0 15:34 ?        00:00:00 /usr/lib/systemd/systemd-udevd
root       546     2  0 15:34 ?        00:00:00 [xfs-buf/sda1]
root       548     2  0 15:34 ?        00:00:00 [xfs-data/sda1]
root       550     2  0 15:34 ?        00:00:00 [xfs-conv/sda1]
root       552     2  0 15:34 ?        00:00:00 [xfs-cil/sda1]
root       554     2  0 15:34 ?        00:00:00 [xfs-reclaim/sda]
root       555     2  0 15:34 ?        00:00:00 [xfs-log/sda1]
root       558     2  0 15:34 ?        00:00:00 [xfs-eofblocks/s]
root       561     2  0 15:34 ?        00:00:00 [xfsaild/sda1]
root       607     1  0 15:35 ?        00:00:00 /sbin/auditd
dbus       629     1  0 15:35 ?        00:00:00 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation
polkitd    631     1  0 15:35 ?        00:00:00 /usr/lib/polkit-1/polkitd --no-debug
root       634     1  0 15:35 ?        00:00:00 /usr/lib/systemd/systemd-logind
root       642     1  0 15:35 ?        00:00:00 /usr/sbin/crond -n
chrony     647     1  0 15:35 ?        00:00:00 /usr/sbin/chronyd
root       649     1  0 15:35 ?        00:00:00 login -- root
root       664     1  0 15:35 ?        00:00:00 /usr/bin/python2 -Es /usr/sbin/firewalld --nofork --nopid
root       665     1  0 15:35 ?        00:00:00 /usr/sbin/NetworkManager --no-daemon
root       793   665  0 15:35 ?        00:00:00 /sbin/dhclient -d -q -sf /usr/libexec/nm-dhcp-helper -pf /var/run/dhclient-enp0s3.pid -lf /var/lib/NetworkManager/dhclient-389fb7e2-ee
root      1066     1  0 15:35 ?        00:00:00 /usr/sbin/sshd -D
root      1067     1  0 15:35 ?        00:00:00 /usr/bin/python2 -Es /usr/sbin/tuned -l -P
root      1068     1  0 15:35 ?        00:00:00 /usr/sbin/rsyslogd -n
root      1202     2  0 15:35 ?        00:00:00 [dio/dm-0]
root      1205     1  0 15:35 ?        00:00:00 /usr/libexec/postfix/master -w
postfix   1206  1205  0 15:35 ?        00:00:00 pickup -l -t unix -u
postfix   1207  1205  0 15:35 ?        00:00:00 qmgr -l -t unix -u
root      1242   649  0 15:35 tty1     00:00:00 -bash
root      1305  1066  0 15:49 ?        00:00:00 sshd: root@pts/0
root      1309  1305  0 15:49 pts/0    00:00:00 -bash
root      1533     1  0 16:01 ?        00:00:00 /usr/sbin/anacron -s
root      1776     2  0 16:49 ?        00:00:00 [kworker/u2:0]
root      1868     2  0 16:58 ?        00:00:00 [kworker/0:1]
root      1968     2  0 16:59 ?        00:00:00 [kworker/0:3]
mysql     2036     1  0 17:03 ?        00:00:01 /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
root      2068     2  0 17:04 ?        00:00:00 [kworker/0:0]
root      2073     2  0 17:07 ?        00:00:00 [kworker/0:2]
root      2078  1309  0 17:09 pts/0    00:00:00 ps -ef
[root@localhost osmetricsplugin]# ps -ef | less
[root@localhost osmetricsplugin]# ps -efs
  UID   PID          PENDING          BLOCKED          IGNORED           CAUGHT STAT TTY        TIME COMMAND
    0  1309 0000000000000000 0000000000010000 0000000000384004 000000004b813efb Ss   pts/0      0:00 -bash LANG=en_US.UTF-8 USER=root LOGNAME=root HOME=/root PATH=/usr/local/sbin:/us
    0  2081 0000000000000000 0000000000000000 0000000000000000 00000001f3d1fef9 R+   pts/0      0:00  \_ ps -efs XDG_SESSION_ID=4 HOSTNAME=localhost.localdomain TERM=xterm-256color S
    0  1242 0000000000000000 0000000000000000 0000000000384004 000000004b813efb Ss+  tty1       0:00 -bash HOME=/root USER=root SHELL=/bin/bash TERM=linux PATH=/usr/local/sbin:/usr/l
[root@localhost osmetricsplugin]# ps -ex
  PID TTY      STAT   TIME COMMAND
    1 ?        Ss     0:00 /usr/lib/systemd/systemd --switched-root --system --deserialize 22
    2 ?        S      0:00 [kthreadd]
    4 ?        S<     0:00 [kworker/0:0H]
    6 ?        S      0:00 [ksoftirqd/0]
    7 ?        S      0:00 [migration/0]
    8 ?        S      0:00 [rcu_bh]
    9 ?        R      0:00 [rcu_sched]
   10 ?        S<     0:00 [lru-add-drain]
   11 ?        S      0:00 [watchdog/0]
   13 ?        S      0:00 [kdevtmpfs]
   14 ?        S<     0:00 [netns]
   15 ?        S      0:00 [khungtaskd]
   16 ?        S<     0:00 [writeback]
   17 ?        S<     0:00 [kintegrityd]
   18 ?        S<     0:00 [bioset]
   19 ?        S<     0:00 [bioset]
   20 ?        S<     0:00 [bioset]
   21 ?        S<     0:00 [kblockd]
   22 ?        S<     0:00 [md]
   23 ?        S<     0:00 [edac-poller]
   24 ?        S<     0:00 [watchdogd]
   30 ?        S      0:00 [kswapd0]
   31 ?        SN     0:00 [ksmd]
   32 ?        SN     0:00 [khugepaged]
   33 ?        S<     0:00 [crypto]
   41 ?        S<     0:00 [kthrotld]
   43 ?        S<     0:00 [kmpath_rdacd]
   44 ?        S<     0:00 [kaluad]
   45 ?        S<     0:00 [kpsmoused]
   46 ?        S<     0:00 [ipv6_addrconf]
   60 ?        S<     0:00 [deferwq]
   95 ?        S      0:00 [kauditd]
  270 ?        S<     0:00 [ata_sff]
  281 ?        S      0:00 [scsi_eh_0]
  283 ?        S<     0:00 [scsi_tmf_0]
  284 ?        S      0:00 [scsi_eh_1]
  285 ?        S<     0:00 [scsi_tmf_1]
  286 ?        S      0:00 [scsi_eh_2]
  288 ?        S      0:00 [kworker/u2:3]
  289 ?        S<     0:00 [scsi_tmf_2]
  318 ?        S<     0:00 [kworker/0:1H]
  359 ?        S<     0:00 [kdmflush]
  360 ?        S<     0:00 [bioset]
  369 ?        S<     0:00 [kdmflush]
  370 ?        S<     0:00 [bioset]
  383 ?        S<     0:00 [bioset]
  384 ?        S<     0:00 [xfsalloc]
  385 ?        S<     0:00 [xfs_mru_cache]
  386 ?        S<     0:00 [xfs-buf/dm-0]
  387 ?        S<     0:00 [xfs-data/dm-0]
  388 ?        S<     0:00 [xfs-conv/dm-0]
  389 ?        S<     0:00 [xfs-cil/dm-0]
  390 ?        S<     0:00 [xfs-reclaim/dm-]
  391 ?        S<     0:00 [xfs-log/dm-0]
  392 ?        S<     0:00 [xfs-eofblocks/d]
  393 ?        S      0:00 [xfsaild/dm-0]
  471 ?        Ss     0:00 /usr/lib/systemd/systemd-journald LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin NOTIFY_SOCKET=/run/systemd/notify LISTEN_PID=471
  493 ?        Ss     0:00 /usr/sbin/lvmetad -f LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin LISTEN_PID=493 LISTEN_FDS=1 SD_ACTIVATION=1
  500 ?        Ss     0:00 /usr/lib/systemd/systemd-udevd LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin NOTIFY_SOCKET=/run/systemd/notify LISTEN_PID=500 LIS
  546 ?        S<     0:00 [xfs-buf/sda1]
  548 ?        S<     0:00 [xfs-data/sda1]
  550 ?        S<     0:00 [xfs-conv/sda1]
  552 ?        S<     0:00 [xfs-cil/sda1]
  554 ?        S<     0:00 [xfs-reclaim/sda]
  555 ?        S<     0:00 [xfs-log/sda1]
  558 ?        S<     0:00 [xfs-eofblocks/s]
  561 ?        S      0:00 [xfsaild/sda1]
  607 ?        S<sl   0:00 /sbin/auditd LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin
  634 ?        Ss     0:00 /usr/lib/systemd/systemd-logind LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin NOTIFY_SOCKET=/run/systemd/notify WATCHDOG_PID=634
  642 ?        Ss     0:00 /usr/sbin/crond -n LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin CRONDARGS=
  649 ?        Ss     0:00 login -- root                                                                                                                                             
  664 ?        Ssl    0:00 /usr/bin/python2 -Es /usr/sbin/firewalld --nofork --nopid LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin FIREWALLD_ARGS=
  665 ?        Ssl    0:00 /usr/sbin/NetworkManager --no-daemon LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin
  793 ?        S      0:00 /sbin/dhclient -d -q -sf /usr/libexec/nm-dhcp-helper -pf /var/run/dhclient-enp0s3.pid -lf /var/lib/NetworkManager/dhclient-389fb7e2-ee6a-39e3-b60c-0a2f6395
 1066 ?        Ss     0:00 /usr/sbin/sshd -D LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin NOTIFY_SOCKET=/run/systemd/notify SSH_USE_STRONG_RNG=0
 1067 ?        Ssl    0:00 /usr/bin/python2 -Es /usr/sbin/tuned -l -P LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin
 1068 ?        Ssl    0:00 /usr/sbin/rsyslogd -n LANG=en_US.UTF-8 PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin NOTIFY_SOCKET=/run/systemd/notify SYSLOGD_OPTIONS=
 1202 ?        S<     0:00 [dio/dm-0]
 1205 ?        Ss     0:00 /usr/libexec/postfix/master -w MAIL_CONFIG=/etc/postfix data_directory=/var/lib/postfix sample_directory=/usr/share/doc/postfix-2.10.1/samples setgid_group
 1242 tty1     Ss+    0:00 -bash HOME=/root USER=root SHELL=/bin/bash TERM=linux PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin MAIL=/var/mail/root LOGNAME=root XD
 1305 ?        Ss     0:00 sshd: root@pts/0                                                                                                                              0
 1309 pts/0    Ss     0:00 -bash LANG=en_US.UTF-8 USER=root LOGNAME=root HOME=/root PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin MAIL=/var/mail/root SHELL=/bin/bash SSH_CLI
 1533 ?        Ss     0:00 /usr/sbin/anacron -s XDG_SESSION_ID=7 MAILTO=root SHELL=/bin/bash USER=root PATH=/sbin:/bin:/usr/sbin:/usr/bin PWD=/root LANG=en_US.UTF-8 SHLVL=3 HOME=/roo
 1776 ?        S      0:00 [kworker/u2:0]
 1868 ?        S      0:00 [kworker/0:1]
 1968 ?        R      0:00 [kworker/0:3]
 2068 ?        S      0:00 [kworker/0:0]
 2073 ?        S      0:00 [kworker/0:2]
 2082 pts/0    R+     0:00 ps -ex XDG_SESSION_ID=4 HOSTNAME=localhost.localdomain TERM=xterm-256color SHELL=/bin/bash HISTSIZE=1000 SSH_CLIENT=192.168.2.143 64996 22 SSH_TTY=/dev/pts
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS    VSZ USER     COMMAND
 2036 mysqld   200588 1185256 mysql  /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2091 grep       964 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| STIME_TV_SEC  |          0 |
| MAXRSS        |     200836 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      24469 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33608 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |      11172 |
| NIVCSW        |         33 |
+---------------+------------+
20 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS    VSZ USER     COMMAND
 2036 mysqld   200836 1185256 mysql  /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2094 grep       964 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command,swap | grep -e "RSS" -e "mysql"
error: unknown user-defined format specifier "swap"

Usage:
 ps [options]

 Try 'ps --help <simple|list|output|threads|misc|all>'
  or 'ps --help <s|l|o|t|m|a>'
 for additional help text.

For more details see ps(1).
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command,swaps | grep -e "RSS" -e "mysql"
error: unknown user-defined format specifier "swaps"

Usage:
 ps [options]

 Try 'ps --help <simple|list|output|threads|misc|all>'
  or 'ps --help <s|l|o|t|m|a>'
 for additional help text.

For more details see ps(1).
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command | grep -e "mysql"
 2036 mysqld   200836 1185256 mysql  /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2103 grep       976 112812 root     grep --color=auto -e mysql
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command,swaps | grep -e "RSS" -e "mysql"
error: unknown user-defined format specifier "swaps"

Usage:
 ps [options]

 Try 'ps --help <simple|list|output|threads|misc|all>'
  or 'ps --help <s|l|o|t|m|a>'
 for additional help text.

For more details see ps(1).
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS    VSZ USER     COMMAND
 2036 mysqld   200836 1185256 mysql  /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2107 grep       964 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# man ps
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| STIME_TV_SEC  |          0 |
| MAXRSS        |     200844 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      24471 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33624 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |      17531 |
| NIVCSW        |         33 |
+---------------+------------+
20 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,minflt,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS MINFLT    VSZ USER     COMMAND
 2036 mysqld   200844 24471 1185256 mysql   /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2133 grep       964    377 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 5
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.08 |
| LOADAVG_5MIN  |       0.03 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      87033 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     146566 |
| MAXRSS        |     191608 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      24041 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        175 |
| NIVCSW        |         47 |
+---------------+------------+
22 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,minflt,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS MINFLT    VSZ USER     COMMAND
 2182 mysqld   191608 24053 1185256 mysql   /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2213 grep       964    377 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,minflt,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS MINFLT    VSZ USER     COMMAND
 2182 mysqld   191608 24053 1185256 mysql   /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2215 grep       964    377 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     127454 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     153552 |
| MAXRSS        |     191812 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      24088 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33608 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |       2289 |
| NIVCSW        |         47 |
+---------------+------------+
22 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,minflt,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS MINFLT    VSZ USER     COMMAND
 2182 mysqld   191812 24088 1185256 mysql   /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2218 grep       964    378 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      83398 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     156584 |
| UTIME_TOTAL   |   1.083398 |
| MAXRSS        |     190432 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23492 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        166 |
| NIVCSW        |         32 |
+---------------+------------+
23 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      88174 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     157275 |
| UTIME_TOTAL   |   1.088174 |
| MAXRSS        |     195560 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23504 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        393 |
| NIVCSW        |         32 |
+---------------+------------+
23 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      89222 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     157426 |
| UTIME_TOTAL   |   1.089222 |
| MAXRSS        |     195560 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23505 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        433 |
| NIVCSW        |         32 |
+---------------+------------+
23 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      90596 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     157625 |
| UTIME_TOTAL   |   1.090596 |
| MAXRSS        |     195560 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23506 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        486 |
| NIVCSW        |         32 |
+---------------+------------+
23 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      92170 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     157852 |
| UTIME_TOTAL   |    1.09217 |
| MAXRSS        |     195560 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23507 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        552 |
| NIVCSW        |         32 |
+---------------+------------+
23 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.16 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.06 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     108725 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     119152 |
| UTIME_TOTAL   |   1.108725 |
| STIME_TOTAL   |   0.119152 |
| MAXRSS        |     183020 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23726 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |          0 |
| OUBLOCK       |      33584 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        165 |
| NIVCSW        |         51 |
+---------------+------------+
24 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ps -eopid,fname,rss,minflt,vsz,user,command | grep -e "RSS" -e "mysql"
  PID COMMAND    RSS MINFLT    VSZ USER     COMMAND
 2369 mysqld   187820 23737 1166588 mysql   /usr/sbin/mysqld --daemonize --pid-file=/var/run/mysqld/mysqld.pid
 2401 grep       964    377 112812 root     grep --color=auto -e RSS -e mysql
[root@localhost osmetricsplugin]# iostat
Linux 3.10.0-1127.el7.x86_64 (localhost.localdomain) 	06/23/2020 	_x86_64_	(1 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.19    0.00    0.12    0.02    0.00   99.67

Device:            tps    kB_read/s    kB_wrtn/s    kB_read    kB_wrtn
sda               1.59        50.36        31.20     346239     214491
dm-0              1.30        48.60        30.90     334126     212423
dm-1              0.01         0.32         0.00       2204          0

[root@localhost osmetricsplugin]# vmstat
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0      0 349548   2108 371728    0    0    50    31   36   76  0  0 100  0  0
[root@localhost osmetricsplugin]# vmstat
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0      0 349672   2108 371760    0    0    50    31   36   76  0  0 100  0  0
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.08 |
| LOADAVG_5MIN  |       0.04 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      55161 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     187841 |
| UTIME_TOTAL   |   1.055161 |
| STIME_TOTAL   |   0.187841 |
| MAXRSS        |     185256 |
| MAXRSS        |  189702144 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23712 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        166 |
| NIVCSW        |         49 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.05 |
| LOADAVG_5MIN  |       0.03 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          0 |
| UTIME_TV_USEC |     100224 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     134343 |
| UTIME_TOTAL   |   0.100224 |
| STIME_TOTAL   |   0.134343 |
| MAXRSS        |     182456 |
| MAXRSS_BYTES  |  186834944 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23494 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32352 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |         82 |
| NIVCSW        |         10 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |        0.1 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |      69722 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     167389 |
| UTIME_TOTAL   |   1.069722 |
| STIME_TOTAL   |   0.167389 |
| MAXRSS        |     189672 |
| MAXRSS_BYTES  |  194224128 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23539 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33608 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |        429 |
| NIVCSW        |         50 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# top

top - 17:35:19 up  2:00,  2 users,  load average: 0.16, 0.07, 0.06
Tasks:  93 total,   1 running,  92 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni, 99.7 id,  0.0 wa,  0.0 hi,  0.3 si,  0.0 st
KiB Mem : 43.4/1014764  [||||||||||||||||||||||||||||||||||||||||||||                                                        ]
KiB Swap:  0.0/839676   [                                                                                                    ]

  PID USER      PR  NI    VIRT    RES    SHR S %CPU %MEM     TIME+ COMMAND                                                                                                           
 1305 root      20   0  159400   6180   4808 S  0.0  0.6   0:01.13 sshd                                                                                                              
  793 root      20   0  102904   5492   3432 S  0.0  0.5   0:00.00 dhclient                                                                                                          
 1068 root      20   0  214576   5480   2600 S  0.0  0.5   0:00.62 rsyslogd                                                                                                          
 1066 root      20   0  112924   4320   3296 S  0.0  0.4   0:00.01 sshd                                                                                                              
 1207 postfix   20   0   90348   4240   3164 S  0.0  0.4   0:00.00 qmgr                                                                                                              
 2130 postfix   20   0   90280   4220   3148 S  0.0  0.4   0:00.00 pickup                                                                                                            
    1 root      20   0  125492   3888   2560 S  0.0  0.4   0:00.90 systemd                                                                                                           
  649 root      20   0   99208   2688   2008 S  0.0  0.3   0:00.04 login                                                                                                             
  629 dbus      20   0   58240   2508   1828 S  0.0  0.2   0:00.15 dbus-daemon                                                                                                       
  471 root      20   0   37232   2436   2124 S  0.0  0.2   0:00.16 systemd-journal                                                                                                   
 1309 root      20   0  115680   2264   1688 S  0.0  0.2   0:00.18 bash                                                                                                              
 1242 root      20   0  115676   2220   1692 S  0.0  0.2   0:00.05 bash                                                                                                              
 2549 root      20   0  162008   2216   1556 R  0.0  0.2   0:00.04 top                                                                                                               
 1205 root      20   0   90176   2180   1096 S  0.0  0.2   0:00.06 master                                                                                                            
  500 root      20   0   44988   1920   1324 S  0.0  0.2   0:00.05 systemd-udevd                                                                                                     
  647 chrony    20   0  117808   1860   1392 S  0.0  0.2   0:00.06 chronyd                                                                                                           
  634 root      20   0   26380   1788   1476 S  0.0  0.2   0:00.05 systemd-logind                                                                                                    
  642 root      20   0  126388   1584    964 S  0.0  0.2   0:00.02 crond                                                                                                             
  493 root      20   0  190376   1340    956 S  0.0  0.1   0:00.00 lvmetad                                                                                                           
  607 root      16  -4   55532    856    448 S  0.0  0.1   0:00.01 auditd                                                                                                            
    2 root      20   0       0      0      0 S  0.0  0.0   0:00.00 kthreadd                                                                                                          
    4 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 kworker/0:0H                                                                                                      
    6 root      20   0       0      0      0 S  0.0  0.0   0:00.22 ksoftirqd/0                                                                                                       
    7 root      rt   0       0      0      0 S  0.0  0.0   0:00.00 migration/0                                                                                                       
    8 root      20   0       0      0      0 S  0.0  0.0   0:00.00 rcu_bh                                                                                                            
    9 root      20   0       0      0      0 S  0.0  0.0   0:00.46 rcu_sched                                                                                                         
   10 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 lru-add-drain                                                                                                     
   11 root      rt   0       0      0      0 S  0.0  0.0   0:00.07 watchdog/0                                                                                                        
   13 root      20   0       0      0      0 S  0.0  0.0   0:00.00 kdevtmpfs                                                                                                         
   14 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 netns                                                                                                             
   15 root      20   0       0      0      0 S  0.0  0.0   0:00.00 khungtaskd                                                                                                        
   16 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 writeback                                                                                                         
   17 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 kintegrityd                                                                                                       
   18 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 bioset                                                                                                            
   19 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 bioset                                                                                                            
   20 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 bioset                                                                                                            
   21 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 kblockd                                                                                                           
   22 root       0 -20       0      0      0 S  0.0  0.0   0:00.00 md                                                                                                                
[root@localhost osmetricsplugin]# cat /proc/meminfo 
MemTotal:        1014764 kB
MemFree:          347704 kB
MemAvailable:     574196 kB
Buffers:            2108 kB
Cached:           346128 kB
SwapCached:            0 kB
Active:           428320 kB
Inactive:         162032 kB
Active(anon):     242372 kB
Inactive(anon):     6604 kB
Active(file):     185948 kB
Inactive(file):   155428 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:        839676 kB
SwapFree:         839676 kB
Dirty:               544 kB
Writeback:             0 kB
AnonPages:        242144 kB
Mapped:            28072 kB
Shmem:              6860 kB
Slab:              38632 kB
SReclaimable:      25784 kB
SUnreclaim:        12848 kB
KernelStack:        2176 kB
PageTables:         4804 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     1347056 kB
Committed_AS:     868576 kB
VmallocTotal:   34359738367 kB
VmallocUsed:        5740 kB
VmallocChunk:   34359729152 kB
Percpu:              176 kB
HardwareCorrupted:     0 kB
AnonHugePages:    110592 kB
CmaTotal:              0 kB
CmaFree:               0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
DirectMap4k:       53184 kB
DirectMap2M:      995328 kB
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.04 |
| LOADAVG_5MIN  |       0.06 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     124714 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     180611 |
| UTIME_TOTAL   |   1.124714 |
| STIME_TOTAL   |   0.180611 |
| MAXRSS        |     192724 |
| MAXRSS_BYTES  |  197349376 |
| IXRSS         |          0 |
| IDRSS         |          0 |
| ISRSS         |          0 |
| MINFLT        |      23576 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33616 |
| MSGSND        |          0 |
| MSGRCV        |          0 |
| NSIGNALS      |          0 |
| NVCSW         |       3367 |
| NIVCSW        |         50 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.08 |
| LOADAVG_5MIN  |       0.06 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          0 |
| UTIME_TV_USEC |     817535 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     146681 |
| UTIME_TOTAL   |   0.817535 |
| STIME_TOTAL   |   0.146681 |
| MAXRSS        |     183016 |
| MAXRSS_BYTES  |  187408384 |
| MINFLT        |      23664 |
| MAJFLT        |          0 |
| NSWAP         |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        151 |
| NIVCSW        |         48 |
+---------------+------------+
19 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.11 |
| LOADAVG_5MIN  |       0.06 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          0 |
| UTIME_TV_USEC |     107483 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     130682 |
| UTIME_TOTAL   |   0.107483 |
| STIME_TOTAL   |   0.130682 |
| MAXRSS        |     184344 |
| MAXRSS_BYTES  |  188768256 |
| MINFLT        |      22960 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32368 |
| NVCSW         |        111 |
| NIVCSW        |          9 |
+---------------+------------+
18 rows in set (0.01 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.03 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     123975 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     169845 |
| UTIME_TOTAL   |   1.123975 |
| STIME_TOTAL   |   0.169845 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22986 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33616 |
| NVCSW         |       2494 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     125096 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     169845 |
| UTIME_TOTAL   |   1.125096 |
| STIME_TOTAL   |   0.169845 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22987 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33624 |
| NVCSW         |       2522 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.01 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     126046 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     169845 |
| UTIME_TOTAL   |   1.126046 |
| STIME_TOTAL   |   0.169845 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22988 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33624 |
| NVCSW         |       2558 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     127251 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     169962 |
| UTIME_TOTAL   |   1.127251 |
| STIME_TOTAL   |   0.169962 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22989 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33624 |
| NVCSW         |       2598 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     128134 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     170095 |
| UTIME_TOTAL   |   1.128134 |
| STIME_TOTAL   |   0.170095 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22990 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33632 |
| NVCSW         |       2625 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     129168 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     170251 |
| UTIME_TOTAL   |   1.129168 |
| STIME_TOTAL   |   0.170251 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22991 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33632 |
| NVCSW         |       2663 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.02 |
| LOADAVG_5MIN  |       0.05 |
| LOADAVG_15MIN |       0.05 |
| UTIME_TV_SEC  |          1 |
| UTIME_TV_USEC |     130024 |
| STIME_TV_SEC  |          0 |
| STIME_TV_USEC |     170380 |
| UTIME_TOTAL   |   1.130024 |
| STIME_TOTAL   |    0.17038 |
| MAXRSS        |     189504 |
| MAXRSS_BYTES  |  194052096 |
| MINFLT        |      22992 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33632 |
| NVCSW         |       2690 |
| NIVCSW        |         52 |
+---------------+------------+
18 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano NOTES
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  NOTES  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# quit
-bash: quit: command not found
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME         |   0.453178 |
| STIME         |   0.139628 |
| MAXRSS        |     186696 |
| MAXRSS_BYTES  |  191176704 |
| MINFLT        |      23555 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        141 |
| NIVCSW        |         26 |
+---------------+------------+
14 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME         |   1.088244 |
| STIME         |   0.147262 |
| MAXRSS        |     186772 |
| MAXRSS_BYTES  |  191254528 |
| MINFLT        |      23567 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        269 |
| NIVCSW        |         34 |
+---------------+------------+
14 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME         |   1.089389 |
| STIME         |   0.147417 |
| MAXRSS        |     186772 |
| MAXRSS_BYTES  |  191254528 |
| MINFLT        |      23568 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        320 |
| NIVCSW        |         34 |
+---------------+------------+
14 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME         |   1.090314 |
| STIME         |   0.147542 |
| MAXRSS        |     191824 |
| MAXRSS_BYTES  |  196427776 |
| MINFLT        |      23569 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        349 |
| NIVCSW        |         34 |
+---------------+------------+
14 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME         |   1.091594 |
| STIME         |   0.147715 |
| MAXRSS        |     191824 |
| MAXRSS_BYTES  |  196427776 |
| MINFLT        |      23570 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        409 |
| NIVCSW        |         34 |
+---------------+------------+
14 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.02 |
| LOADAVG_15MIN |       0.05 |
| UTIME         |   1.092536 |
| STIME         |   0.147843 |
| MAXRSS        |     191824 |
| MAXRSS_BYTES  |  196427776 |
| MINFLT        |      23571 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33592 |
| NVCSW         |        449 |
| NIVCSW        |         34 |
+---------------+------------+
14 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:52:12: error: ‘info’ was not declared in this scope
   sysinfo(&info);
            ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| TOTAL_RAM     | 1039118336 |
| UTIME         |   0.111382 |
| STIME         |   0.149236 |
| MAXRSS        |     182476 |
| MAXRSS_BYTES  |  186855424 |
| MINFLT        |      23515 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32352 |
| NVCSW         |         82 |
| NIVCSW        |         11 |
+---------------+------------+
15 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano NOTES 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:55:36: error: no matching function for call to ‘Field::store(__kernel_ulong_t [3])’
   table->field[1]->store(info.loads);
                                    ^
osmetricsplugin.cc:55:36: note: candidates are:
In file included from ../percona-server-5.7.24-27/sql/protocol_classic.h:20:0,
                 from ../percona-server-5.7.24-27/sql/sql_class.h:33,
                 from osmetricsplugin.cc:1:
../percona-server-5.7.24-27/sql/field.h:780:34: note: virtual type_conversion_status Field::store(const char*, size_t, const CHARSET_INFO*)
   virtual type_conversion_status store(const char *to, size_t length,
                                  ^
../percona-server-5.7.24-27/sql/field.h:780:34: note:   candidate expects 3 arguments, 1 provided
../percona-server-5.7.24-27/sql/field.h:782:34: note: virtual type_conversion_status Field::store(double)
   virtual type_conversion_status store(double nr)=0;
                                  ^
../percona-server-5.7.24-27/sql/field.h:782:34: note:   no known conversion for argument 1 from ‘__kernel_ulong_t [3] {aka long unsigned int [3]}’ to ‘double’
../percona-server-5.7.24-27/sql/field.h:783:34: note: virtual type_conversion_status Field::store(longlong, bool)
   virtual type_conversion_status store(longlong nr, bool unsigned_val)=0;
                                  ^
../percona-server-5.7.24-27/sql/field.h:783:34: note:   candidate expects 2 arguments, 1 provided
../percona-server-5.7.24-27/sql/field.h:828:26: note: type_conversion_status Field::store(const char*, size_t, const CHARSET_INFO*, enum_check_fields)
   type_conversion_status store(const char *to, size_t length,
                          ^
../percona-server-5.7.24-27/sql/field.h:828:26: note:   candidate expects 4 arguments, 1 provided
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quir
    -> ^Cquir
^C
mysql> quit
Bye
[root@localhost osmetricsplugin]# serive mysql stop
-bash: serive: command not found
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| LOAD_1MIN     |        192 |
| LOAD_5MIN     |        960 |
| LOAD_15MIN    |       2976 |
| FREE_RAM      |  355528704 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| PROCS         |        139 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| MEM_UNIT      |          1 |
| UTIME         |   1.081225 |
| STIME         |    0.15245 |
| MAXRSS        |     189008 |
| MAXRSS_BYTES  |  193544192 |
| MINFLT        |      22534 |
| MAJFLT        |          0 |
| INBLOCK       |          0 |
| OUBLOCK       |      33592 |
| NVCSW         |        380 |
| NIVCSW        |         52 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  NOTES  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# nano NOTES 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| LOAD_1MIN     |        192 |
| LOAD_5MIN     |        960 |
| LOAD_15MIN    |       2976 |
| FREE_RAM      |  353378304 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| PROCS         |        138 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| MEM_UNIT      |          1 |
| UTIME         |   1.165252 |
| STIME         |   0.190041 |
| MAXRSS        |     191428 |
| MAXRSS_BYTES  |  196022272 |
| MINFLT        |      22553 |
| MAJFLT        |          0 |
| INBLOCK       |          0 |
| OUBLOCK       |      33608 |
| NVCSW         |       3952 |
| NIVCSW        |         53 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.08 |
| LOADAVG_5MIN  |       0.03 |
| LOADAVG_15MIN |       0.05 |
| LOAD_1MIN     |       4992 |
| LOAD_5MIN     |       2016 |
| LOAD_15MIN    |       3296 |
| FREE_RAM      |  361353216 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| PROCS         |        138 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| MEM_UNIT      |          1 |
| UTIME         |   0.098043 |
| STIME         |   0.181131 |
| MAXRSS        |     182936 |
| MAXRSS_BYTES  |  187326464 |
| MINFLT        |      23622 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32352 |
| NVCSW         |         82 |
| NIVCSW        |         14 |
+---------------+------------+
25 rows in set (0.01 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.04 |
| LOADAVG_5MIN  |       0.03 |
| LOADAVG_15MIN |       0.05 |
| LOAD_1MIN     |       2752 |
| LOAD_5MIN     |       1792 |
| LOAD_15MIN    |       3072 |
| FREE_RAM      |  353411072 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| PROCS         |        138 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| MEM_UNIT      |          1 |
| UTIME         |   1.103681 |
| STIME         |   0.190588 |
| MAXRSS        |     190644 |
| MAXRSS_BYTES  |  195219456 |
| MINFLT        |      23667 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33608 |
| NVCSW         |       1060 |
| NIVCSW        |         54 |
+---------------+------------+
25 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano NOTES 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UPTIME        |       9705 |
| UPTIME_DAYS   |          6 |
| UPTIME_HOURS  |          2 |
| LOAD_1MIN     |        192 |
| LOAD_5MIN     |        960 |
| LOAD_15MIN    |       2976 |
| FREE_RAM      |  357122048 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| PROCS         |        138 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| MEM_UNIT      |          1 |
| UTIME         |   0.861202 |
| STIME         |   0.170576 |
| MAXRSS        |     187100 |
| MAXRSS_BYTES  |  191590400 |
| MINFLT        |      24190 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      33600 |
| NVCSW         |        151 |
| NIVCSW        |         32 |
+---------------+------------+
28 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
^[[A[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |          0 |
| LOADAVG_5MIN  |       0.01 |
| LOADAVG_15MIN |       0.05 |
| UPTIME        |       9794 |
| UPTIME_DAYS   |          0 |
| UPTIME_HOURS  |          2 |
| LOAD_1MIN     |        192 |
| LOAD_5MIN     |        960 |
| LOAD_15MIN    |       2976 |
| FREE_RAM      |  361275392 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| PROCS         |        138 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| MEM_UNIT      |          1 |
| UTIME         |   0.096772 |
| STIME         |   0.154423 |
| MAXRSS        |     182992 |
| MAXRSS_BYTES  |  187383808 |
| MINFLT        |      23640 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32360 |
| NVCSW         |         93 |
| NIVCSW        |         13 |
+---------------+------------+
28 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano NOTES 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:53:19: error: ‘si_meminfo’ was not declared in this scope
   si_meminfo(&info);
                   ^
osmetricsplugin.cc:54:20: error: ‘si_swapinfo’ was not declared in this scope
   si_swapinfo(&info);
                    ^
osmetricsplugin.cc:55:32: error: ‘si_mem_available’ was not declared in this scope
   available = si_mem_available();
                                ^
osmetricsplugin.cc:122:26: error: ‘i’ was not declared in this scope
   table->field[1]->store(i.freeram - i.freehigh);
                          ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc:14:26: fatal error: linux/vmstat.h: No such file or directory
 #include <linux/vmstat.h>
                          ^
compilation terminated.
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:53:19: error: ‘si_meminfo’ was not declared in this scope
   si_meminfo(&info);
                   ^
osmetricsplugin.cc:54:20: error: ‘si_swapinfo’ was not declared in this scope
   si_swapinfo(&info);
                    ^
osmetricsplugin.cc:55:32: error: ‘si_mem_available’ was not declared in this scope
   available = si_mem_available();
                                ^
osmetricsplugin.cc:122:26: error: ‘i’ was not declared in this scope
   table->field[1]->store(i.freeram - i.freehigh);
                          ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:122:26: error: ‘i’ was not declared in this scope
   table->field[1]->store(i.freeram - i.freehigh);
                          ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:86:35: warning: ‘available’ may be used uninitialized in this function [-Wmaybe-uninitialized]
   table->field[1]->store(available);
                                   ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:30:8: warning: unused variable ‘available’ [-Wunused-variable]
   long available;
        ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+---------------+------------+
| NAME          | VALUE      |
+---------------+------------+
| MEMORY_TOTAL  | 1039118336 |
| LOADAVG_1MIN  |       0.12 |
| LOADAVG_5MIN  |       0.07 |
| LOADAVG_15MIN |       0.06 |
| UPTIME        |      10592 |
| UPTIME_DAYS   |          0 |
| UPTIME_HOURS  |          2 |
| LOAD_1MIN     |       7936 |
| LOAD_5MIN     |       4352 |
| LOAD_15MIN    |       3872 |
| FREE_RAM      |  362106880 |
| SHARED_RAM    |          0 |
| BUFFER_RAM    |    2158592 |
| TOTAL_SWAP    |  859828224 |
| FREE_SWAP     |  859828224 |
| PROCS         |        138 |
| TOTAL_HIGH    |          0 |
| FREE_HIGH     |          0 |
| LOW_TOTAL     | 1039118336 |
| LOW_FREE      |  362106880 |
| MEM_UNIT      |          1 |
| UTIME         |   0.132126 |
| STIME         |   0.120636 |
| MAXRSS        |     182244 |
| MAXRSS_BYTES  |  186617856 |
| MINFLT        |      22941 |
| MAJFLT        |          0 |
| INBLOCK       |       7680 |
| OUBLOCK       |      32352 |
| NVCSW         |         93 |
| NIVCSW        |         13 |
+---------------+------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| MEMORY_TOTAL   | 1039118336 |
| LOADAVG_1MIN   |          0 |
| LOADAVG_5MIN   |       0.01 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      11347 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  360685568 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        137 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| LOW_TOTAL_RAM  | 1039118336 |
| LOW_FREE_RAM   |  360685568 |
| MEM_UNIT       |          1 |
| UTIME          |   0.163211 |
| STIME          |   0.152903 |
| MAXRSS         |     183536 |
| MAXRSS_BYTES   |  187940864 |
| MINFLT         |      22765 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33576 |
| NVCSW          |        129 |
| NIVCSW         |         16 |
+----------------+------------+
29 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  NOTES  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# ls in
ls: cannot access in: No such file or directory
[root@localhost osmetricsplugin]# ls includes/
getload.h  getmem.h  getrusage.h  getswappiness.h
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  NOTES  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |          0 |
| LOADAVG_5MIN   |       0.01 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      11535 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  361811968 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| LOW_TOTAL_RAM  | 1039118336 |
| LOW_FREE_RAM   |  361811968 |
| MEM_UNIT       |          1 |
| UTIME          |    0.11762 |
| STIME          |   0.159432 |
| MAXRSS         |     182152 |
| MAXRSS_BYTES   |  186523648 |
| MINFLT         |      23479 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      32352 |
| NVCSW          |         82 |
| NIVCSW         |         11 |
+----------------+------------+
28 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |          0 |
| LOADAVG_5MIN   |       0.01 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      11583 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  362553344 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  362553344 |
| MEM_UNIT       |          1 |
| UTIME          |   0.104717 |
| STIME          |   0.171843 |
| MAXRSS         |     181360 |
| MAXRSS_BYTES   |  185712640 |
| MINFLT         |      23799 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      32352 |
| NVCSW          |         82 |
| NIVCSW         |         11 |
+----------------+------------+
28 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano NOTES 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.09 |
| LOADAVG_5MIN   |       0.05 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12164 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  362811392 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  362811392 |
| MEM_UNIT       |          1 |
| UTIME          |   0.113025 |
| STIME          |   0.150111 |
| MAXRSS         |     181120 |
| MAXRSS_BYTES   |  185466880 |
| MINFLT         |      24239 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      32360 |
| NVCSW          |         82 |
| NIVCSW         |         11 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.07 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12185 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  355332096 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  355332096 |
| MEM_UNIT       |          1 |
| UTIME          |   0.998327 |
| STIME          |   0.193871 |
| MAXRSS         |     188580 |
| MAXRSS_BYTES   |  193105920 |
| MINFLT         |      24276 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33600 |
| NVCSW          |        640 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.07 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12187 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  355319808 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  355319808 |
| MEM_UNIT       |          1 |
| UTIME          |   0.999168 |
| STIME          |   0.194034 |
| MAXRSS         |     188580 |
| MAXRSS_BYTES   |  193105920 |
| MINFLT         |      24277 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33600 |
| NVCSW          |        677 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.07 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12188 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  355319808 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  355319808 |
| MEM_UNIT       |          1 |
| UTIME          |   1.000041 |
| STIME          |   0.194034 |
| MAXRSS         |     188580 |
| MAXRSS_BYTES   |  193105920 |
| MINFLT         |      24277 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33600 |
| NVCSW          |        703 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.06 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12189 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  355319808 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  355319808 |
| MEM_UNIT       |          1 |
| UTIME          |   1.001264 |
| STIME          |   0.194034 |
| MAXRSS         |     188580 |
| MAXRSS_BYTES   |  193105920 |
| MINFLT         |      24277 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33600 |
| NVCSW          |        755 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.06 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12190 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  355319808 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  355319808 |
| MEM_UNIT       |          1 |
| UTIME          |   1.001264 |
| STIME          |   0.194869 |
| MAXRSS         |     188580 |
| MAXRSS_BYTES   |  193105920 |
| MINFLT         |      24277 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33600 |
| NVCSW          |        781 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.06 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12192 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  355319808 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  355319808 |
| MEM_UNIT       |          1 |
| UTIME          |   1.001264 |
| STIME          |   0.195728 |
| MAXRSS         |     188580 |
| MAXRSS_BYTES   |  193105920 |
| MINFLT         |      24277 |
| MAJFLT         |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      33600 |
| NVCSW          |        808 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> SHOW GLOBAL STATUS LIKE "%write%";
+-----------------------------------+-------+
| Variable_name                     | Value |
+-----------------------------------+-------+
| Delayed_writes                    | 0     |
| Handler_write                     | 196   |
| Innodb_buffer_pool_write_requests | 325   |
| Innodb_data_pending_writes        | 0     |
| Innodb_data_writes                | 57    |
| Innodb_dblwr_writes               | 1     |
| Innodb_log_write_requests         | 0     |
| Innodb_log_writes                 | 2     |
| Innodb_os_log_pending_writes      | 0     |
| Innodb_truncated_status_writes    | 0     |
| Key_write_requests                | 0     |
| Key_writes                        | 0     |
+-----------------------------------+-------+
12 rows in set (0.00 sec)

mysql> SHOW GLOBAL STATUS LIKE "%read%";
+--------------------------------------------------------+---------+
| Variable_name                                          | Value   |
+--------------------------------------------------------+---------+
| Com_ha_read                                            | 0       |
| Com_show_thread_statistics                             | 0       |
| Delayed_insert_threads                                 | 0       |
| Handler_read_first                                     | 13      |
| Handler_read_key                                       | 11      |
| Handler_read_last                                      | 0       |
| Handler_read_next                                      | 2       |
| Handler_read_prev                                      | 0       |
| Handler_read_rnd                                       | 0       |
| Handler_read_rnd_next                                  | 1078    |
| Innodb_buffer_pool_read_ahead_rnd                      | 0       |
| Innodb_buffer_pool_read_ahead                          | 0       |
| Innodb_buffer_pool_read_ahead_evicted                  | 0       |
| Innodb_buffer_pool_read_requests                       | 1796    |
| Innodb_buffer_pool_reads                               | 379     |
| Innodb_data_pending_reads                              | 0       |
| Innodb_data_read                                       | 8393728 |
| Innodb_data_reads                                      | 572     |
| Innodb_master_thread_active_loops                      | 1       |
| Innodb_master_thread_idle_loops                        | 60      |
| Innodb_pages_read                                      | 378     |
| Innodb_pages0_read                                     | 16      |
| Innodb_rows_read                                       | 9       |
| Innodb_secondary_index_triggered_cluster_reads         | 0       |
| Innodb_secondary_index_triggered_cluster_reads_avoided | 0       |
| Innodb_encryption_rotation_pages_read_from_cache       | 0       |
| Innodb_encryption_rotation_pages_read_from_disk        | 0       |
| Key_read_requests                                      | 6       |
| Key_reads                                              | 3       |
| Performance_schema_thread_classes_lost                 | 0       |
| Performance_schema_thread_instances_lost               | 0       |
| Slow_launch_threads                                    | 0       |
| Threadpool_idle_threads                                | 0       |
| Threadpool_threads                                     | 0       |
| Threads_cached                                         | 0       |
| Threads_connected                                      | 1       |
| Threads_created                                        | 1       |
| Threads_running                                        | 1       |
+--------------------------------------------------------+---------+
38 rows in set (0.00 sec)

mysql> SHOW GLOBAL STATUS LIKE "%block%";
+---------------------------------------------+-------+
| Variable_name                               | Value |
+---------------------------------------------+-------+
| Innodb_encryption_n_merge_blocks_encrypted  | 0     |
| Innodb_encryption_n_merge_blocks_decrypted  | 0     |
| Innodb_encryption_n_rowlog_blocks_encrypted | 0     |
| Innodb_encryption_n_rowlog_blocks_decrypted | 0     |
| Key_blocks_not_flushed                      | 0     |
| Key_blocks_unused                           | 6695  |
| Key_blocks_used                             | 3     |
| Qcache_free_blocks                          | 1     |
| Qcache_total_blocks                         | 1     |
+---------------------------------------------+-------+
9 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.02 |
| LOADAVG_5MIN   |       0.04 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12266 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  351436800 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        137 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  351436800 |
| MEM_UNIT       |          1 |
| UTIME          |   1.033916 |
| STIME          |   0.203615 |
| MAXRSS         |     192712 |
| MAXRSS_BYTES   |  197337088 |
| MINFLT         |      24831 |
| MAJFLT         |          1 |
| INBLOCK        |       8392 |
| OUBLOCK        |      33616 |
| NVCSW          |       2710 |
| NIVCSW         |         32 |
+----------------+------------+
28 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ls
compile  includes  install_plugin.sql  moveit.sh  NOTES  OLD  osmetricsplugin.cc  osmetricsplugin.so  uninstall_plugin.sh
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc:236:4: error: #endif without #if
   #endif
    ^
osmetricsplugin.cc:253:4: error: #endif without #if
   #endif
    ^
osmetricsplugin.cc:260:4: error: #endif without #if
   #endif
    ^
osmetricsplugin.cc:267:4: error: #endif without #if
   #endif
    ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |          0 |
| LOADAVG_5MIN   |       0.01 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      12913 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  363970560 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        138 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  363970560 |
| MEM_UNIT       |          1 |
| UTIME          |   0.104745 |
| STIME          |   0.165386 |
| MAXRSS         |     179656 |
| MAXRSS_BYTES   |  183967744 |
| IXRSS          |          0 |
| IDRSS          |          0 |
| ISRSS          |          0 |
| MINFLT         |      23878 |
| MAJFLT         |          0 |
| NSWAP          |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      32360 |
| MSGSND         |          0 |
| MSGRCV         |          0 |
| NSIGNALS       |          0 |
| NVCSW          |         82 |
| NIVCSW         |         17 |
+----------------+------------+
35 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+
| NAME           | VALUE      |
+----------------+------------+
| LOADAVG_1MIN   |       0.08 |
| LOADAVG_5MIN   |       0.03 |
| LOADAVG_15MIN  |       0.05 |
| UPTIME         |      13027 |
| UPTIME_DAYS    |          0 |
| UPTIME_HOURS   |          3 |
| TOTAL_RAM      | 1039118336 |
| FREE_RAM       |  359235584 |
| SHARED_RAM     |          0 |
| BUFFER_RAM     |    2158592 |
| TOTAL_SWAP     |  859828224 |
| FREE_SWAP      |  859828224 |
| PROCS          |        137 |
| TOTAL_HIGH_RAM |          0 |
| FREE_HIGH_RAM  |          0 |
| TOTAL_LOW_RAM  | 1039118336 |
| FREE_LOW_RAM   |  359235584 |
| MEM_UNIT       |          1 |
| UTIME          |   0.094369 |
| STIME          |   0.169865 |
| MAXRSS         |     184204 |
| MAXRSS_BYTES   |  188624896 |
| IXRSS          |          0 |
| IDRSS          |          0 |
| ISRSS          |          0 |
| MINFLT         |      23490 |
| MAJFLT         |          0 |
| NSWAP          |          0 |
| INBLOCK        |       7680 |
| OUBLOCK        |      32360 |
| MSGSND         |          0 |
| MSGRCV         |          0 |
| NSIGNALS       |          0 |
| NVCSW          |         99 |
| NIVCSW         |         12 |
+----------------+------------+
35 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# quit
-bash: quit: command not found
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:43:54: error: no matching function for call to ‘Field::store(const char [27])’
   table->field[2]->store("Load average over 1 minute");
                                                      ^
osmetricsplugin.cc:43:54: note: candidates are:
In file included from ../percona-server-5.7.24-27/sql/protocol_classic.h:20:0,
                 from ../percona-server-5.7.24-27/sql/sql_class.h:33,
                 from osmetricsplugin.cc:1:
../percona-server-5.7.24-27/sql/field.h:780:34: note: virtual type_conversion_status Field::store(const char*, size_t, const CHARSET_INFO*)
   virtual type_conversion_status store(const char *to, size_t length,
                                  ^
../percona-server-5.7.24-27/sql/field.h:780:34: note:   candidate expects 3 arguments, 1 provided
../percona-server-5.7.24-27/sql/field.h:782:34: note: virtual type_conversion_status Field::store(double)
   virtual type_conversion_status store(double nr)=0;
                                  ^
../percona-server-5.7.24-27/sql/field.h:782:34: note:   no known conversion for argument 1 from ‘const char [27]’ to ‘double’
../percona-server-5.7.24-27/sql/field.h:783:34: note: virtual type_conversion_status Field::store(longlong, bool)
   virtual type_conversion_status store(longlong nr, bool unsigned_val)=0;
                                  ^
../percona-server-5.7.24-27/sql/field.h:783:34: note:   candidate expects 2 arguments, 1 provided
../percona-server-5.7.24-27/sql/field.h:828:26: note: type_conversion_status Field::store(const char*, size_t, const CHARSET_INFO*, enum_check_fields)
   type_conversion_status store(const char *to, size_t length,
                          ^
../percona-server-5.7.24-27/sql/field.h:828:26: note:   candidate expects 4 arguments, 1 provided
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------+
| NAME           | VALUE      | COMMENT                    |
+----------------+------------+----------------------------+
| LOADAVG_1MIN   |          0 | Load average over 1 minute |
| LOADAVG_5MIN   |       0.02 | Load average over 1 minute |
| LOADAVG_15MIN  |       0.05 | Load average over 1 minute |
| UPTIME         |      13336 | Load average over 1 minute |
| UPTIME_DAYS    |          0 | Load average over 1 minute |
| UPTIME_HOURS   |          3 | Load average over 1 minute |
| TOTAL_RAM      | 1039118336 | Load average over 1 minute |
| FREE_RAM       |  352612352 | Load average over 1 minute |
| SHARED_RAM     |          0 | Load average over 1 minute |
| BUFFER_RAM     |    2158592 | Load average over 1 minute |
| TOTAL_SWAP     |  859828224 | Load average over 1 minute |
| FREE_SWAP      |  859828224 | Load average over 1 minute |
| PROCS          |        138 | Load average over 1 minute |
| TOTAL_HIGH_RAM |          0 | Load average over 1 minute |
| FREE_HIGH_RAM  |          0 | Load average over 1 minute |
| TOTAL_LOW_RAM  | 1039118336 | Load average over 1 minute |
| FREE_LOW_RAM   |  352612352 | Load average over 1 minute |
| MEM_UNIT       |          1 | Load average over 1 minute |
| UTIME          |   1.020595 | Load average over 1 minute |
| STIME          |   0.161146 | Load average over 1 minute |
| MAXRSS         |     190928 | Load average over 1 minute |
| MAXRSS_BYTES   |  195510272 | Load average over 1 minute |
| IXRSS          |          0 | Load average over 1 minute |
| IDRSS          |          0 | Load average over 1 minute |
| ISRSS          |          0 | Load average over 1 minute |
| MINFLT         |      23350 | Load average over 1 minute |
| MAJFLT         |          0 | Load average over 1 minute |
| NSWAP          |          0 | Load average over 1 minute |
| INBLOCK        |       7680 | Load average over 1 minute |
| OUBLOCK        |      33584 | Load average over 1 minute |
| MSGSND         |          0 | Load average over 1 minute |
| MSGRCV         |          0 | Load average over 1 minute |
| NSIGNALS       |          0 | Load average over 1 minute |
| NVCSW          |        255 | Load average over 1 minute |
| NIVCSW         |         59 | Load average over 1 minute |
+----------------+------------+----------------------------+
35 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+-------------------------------+
| NAME           | VALUE      | COMMENT                       |
+----------------+------------+-------------------------------+
| LOADAVG_1MIN   |          0 | Load average over 1 minute    |
| LOADAVG_5MIN   |       0.01 | Load average over 5 minutes   |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes  |
| UPTIME         |      13429 | Load average over 15 minutes  |
| UPTIME_DAYS    |          0 | Load average over 15 minutes  |
| UPTIME_HOURS   |          3 | Load average over 15 minutes  |
| TOTAL_RAM      | 1039118336 | Load average over 15 minutes  |
| FREE_RAM       |  359321600 | Load average over 15 minutes  |
| SHARED_RAM     |          0 | Load average over 15 minutes  |
| BUFFER_RAM     |    2158592 | Load average over 15 minutes  |
| TOTAL_SWAP     |  859828224 | Load average over 15 minutes  |
| FREE_SWAP      |  859828224 | Load average over 15 minutes  |
| PROCS          |        138 | Load average over 15 minutes  |
| TOTAL_HIGH_RAM |          0 | Load average over 15 minutes  |
| FREE_HIGH_RAM  |          0 | Load average over 15 minutes  |
| TOTAL_LOW_RAM  | 1039118336 | Load average over 15 minutes  |
| FREE_LOW_RAM   |  359321600 | Load average over 15 minutes  |
| MEM_UNIT       |          1 | Load average over 15 minutes  |
| UTIME          |   0.112448 | Load average over 15 minutes  |
| STIME          |   0.178042 | Load average over 15 minutes  |
| MAXRSS         |     184052 | Load average over 15 minutes  |
| MAXRSS_BYTES   |  188469248 | Load average over 15 minutes  |
| IXRSS          |          0 | Load average over 15 minutes  |
| IDRSS          |          0 | Load average over 15 minutes  |
| ISRSS          |          0 | Load average over 15 minutes  |
| MINFLT         |      23445 | Load average over 15 minutes  |
| MAJFLT         |          0 | Load average over 15 minutes  |
| NSWAP          |          0 | Load average over 15 minutes  |
| INBLOCK        |       7680 | Load average over 15 minutes  |
| OUBLOCK        |      32352 | Load average over 15 minutes  |
| MSGSND         |          0 | Load average over 15 minutes  |
| MSGRCV         |          0 | Load average over 15 minutes  |
| NSIGNALS       |          0 | Load average over 15 minutes  |
| NVCSW          |         82 | Load average over 15 minutes  |
| NIVCSW         |         16 | Load average over 15 minutes  |
+----------------+------------+-------------------------------+
35 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.01 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| UPTIME         |      15160 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  361283584 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffer                  |
| TOTAL_SWAP     |  859828224 | Total swap space siz                   |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        138 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory siz                  |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  361283584 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.115886 | Total user time                        |
| STIME          |   0.138394 | Total system time                      |
| MAXRSS         |     182120 | Maximum resident set size              |
| MAXRSS_BYTES   |  186490880 | Maximum resident set size (in bytes)   |
| IXRSS          |          0 | Integral shared memory size            |
| IDRSS          |          0 | Integral unshared data size            |
| ISRSS          |          0 | Integral unshared stack size           |
| MINFLT         |      22956 | Page reclaims (soft page faults        |
| MAJFLT         |          0 | Page reclaims (hard page faults        |
| NSWAP          |          0 | Number of swaps                        |
| INBLOCK        |       7680 | Number of swaps                        |
| OUBLOCK        |      32352 | Number of block output operations      |
| MSGSND         |          0 | Number of IPC messages sent            |
| MSGRCV         |          0 | Number of IPC messages sent            |
| NSIGNALS       |          0 | Number of signals received             |
| NVCSW          |         82 | Number of voluntary context switches   |
| NIVCSW         |         12 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
35 rows in set (0.00 sec)

mysql> ^Cquit
^C
mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
./[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.07 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| UPTIME         |      15290 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  358760448 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffer                  |
| TOTAL_SWAP     |  859828224 | Total swap space siz                   |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  358760448 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.106102 | Total user time                        |
| STIME          |   0.155294 | Total system time                      |
| MAXRSS         |     184612 | Maximum resident set size              |
| MAXRSS_BYTES   |  189042688 | Maximum resident set size (in bytes)   |
| IXRSS          |          0 | Integral shared memory size            |
| IDRSS          |          0 | Integral unshared data size            |
| ISRSS          |          0 | Integral unshared stack size           |
| MINFLT         |      23055 | Page reclaims (soft page faults        |
| MAJFLT         |          0 | Page reclaims (hard page faults        |
| NSWAP          |          0 | Number of swaps                        |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      32360 | Number of block output operations      |
| MSGSND         |          0 | Number of IPC messages sent            |
| MSGRCV         |          0 | Number of IPC messages sent            |
| NSIGNALS       |          0 | Number of signals received             |
| NVCSW          |         82 | Number of voluntary context switches   |
| NIVCSW         |         11 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
35 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |          0 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| UPTIME         |      15492 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  359616512 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        138 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  359616512 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.128594 | Total user time                        |
| STIME          |   0.136507 | Total system time                      |
| MAXRSS         |     183736 | Maximum resident set size              |
| MAXRSS_BYTES   |  188145664 | Maximum resident set size (in bytes)   |
| IXRSS          |          0 | Integral shared memory size            |
| IDRSS          |          0 | Integral unshared data size            |
| ISRSS          |          0 | Integral unshared stack size           |
| MINFLT         |      24368 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page reclaims (hard page faults)       |
| NSWAP          |          0 | Number of swaps                        |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      32352 | Number of block output operations      |
| MSGSND         |          0 | Number of IPC messages sent            |
| MSGRCV         |          0 | Number of IPC messages received        |
| NSIGNALS       |          0 | Number of signals received             |
| NVCSW          |         82 | Number of voluntary context switches   |
| NIVCSW         |         13 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
35 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.15 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.05 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.06 | Load average over 15 minutes           |
| UPTIME         |      15863 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  359051264 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  359051264 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.100852 | Total user time                        |
| STIME          |   0.153303 | Total system time                      |
| MAXRSS         |     184216 | Maximum resident set size              |
| MAXRSS_BYTES   |  188637184 | Maximum resident set size (in bytes)   |
| MINFLT         |      23470 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      32352 | Number of block output operations      |
| NVCSW          |         82 | Number of voluntary context switches   |
| NIVCSW         |         12 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
28 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano includes/getload.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.01 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |          0 | 1 minute load average                  |
| UPTIME         |      16003 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  358223872 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  358223872 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.108379 | Total user time                        |
| STIME          |     0.1569 | Total system time                      |
| MAXRSS         |     184992 | Maximum resident set size              |
| MAXRSS_BYTES   |  189431808 | Maximum resident set size (in bytes)   |
| MINFLT         |      23669 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      32352 | Number of block output operations      |
| NVCSW          |         82 | Number of voluntary context switches   |
| NIVCSW         |         13 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
29 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
./[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |          0 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |        192 | 1 minute load average                  |
| UPTIME         |      16095 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  357732352 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  357732352 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.133434 | Total user time                        |
| STIME          |   0.162894 | Total system time                      |
| MAXRSS         |     185412 | Maximum resident set size              |
| MAXRSS_BYTES   |  189861888 | Maximum resident set size (in bytes)   |
| MINFLT         |      23778 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      32352 | Number of block output operations      |
| NVCSW          |         82 | Number of voluntary context switches   |
| NIVCSW         |         17 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
29 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |   0.000625 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |        416 | 1 minute load average                  |
| UPTIME         |      16394 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  356245504 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  356245504 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   1.022244 | Total user time                        |
| STIME          |   0.164797 | Total system time                      |
| MAXRSS         |     186992 | Maximum resident set size              |
| MAXRSS_BYTES   |  191479808 | Maximum resident set size (in bytes)   |
| MINFLT         |      23684 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      33600 | Number of block output operations      |
| NVCSW          |        178 | Number of voluntary context switches   |
| NIVCSW         |         40 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
29 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.05 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |        204 | 1 minute load average                  |
| LOAD_5MIN      |        130 | 5 minute load average                  |
| LOAD_15MIN     |        196 | 15 minute load average                 |
| UPTIME         |      16514 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  358531072 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  358531072 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.990471 | Total user time                        |
| STIME          |    0.18499 | Total system time                      |
| MAXRSS         |     185156 | Maximum resident set size              |
| MAXRSS_BYTES   |  189599744 | Maximum resident set size (in bytes)   |
| MINFLT         |      23772 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |          0 | Number of block input operations       |
| OUBLOCK        |      33584 | Number of block output operations      |
| NVCSW          |        174 | Number of voluntary context switches   |
| NIVCSW         |         62 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.08 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |          0 | 1 minute load average                  |
| LOAD_5MIN      |        160 | 5 minute load average                  |
| LOAD_15MIN     |        206 | 15 minute load average                 |
| UPTIME         |      16612 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  358068224 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  358068224 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.092239 | Total user time                        |
| STIME          |   0.180999 | Total system time                      |
| MAXRSS         |     185120 | Maximum resident set size              |
| MAXRSS_BYTES   |  189562880 | Maximum resident set size (in bytes)   |
| MINFLT         |      24222 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      32376 | Number of block output operations      |
| NVCSW          |        117 | Number of voluntary context switches   |
| NIVCSW         |         13 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.07 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |          0 | 1 minute load average                  |
| LOAD_5MIN      |        156 | 5 minute load average                  |
| LOAD_15MIN     |        202 | 15 minute load average                 |
| UPTIME         |      16620 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  352268288 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  352268288 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.995095 | Total user time                        |
| STIME          |   0.200547 | Total system time                      |
| MAXRSS         |     190836 | Maximum resident set size              |
| MAXRSS_BYTES   |  195416064 | Maximum resident set size (in bytes)   |
| MINFLT         |      24265 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      33608 | Number of block output operations      |
| NVCSW          |        321 | Number of voluntary context switches   |
| NIVCSW         |         50 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.07 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |          0 | 1 minute load average                  |
| LOAD_5MIN      |        156 | 5 minute load average                  |
| LOAD_15MIN     |        202 | 15 minute load average                 |
| UPTIME         |      16622 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  352231424 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  352231424 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.996269 | Total user time                        |
| STIME          |   0.200783 | Total system time                      |
| MAXRSS         |     190836 | Maximum resident set size              |
| MAXRSS_BYTES   |  195416064 | Maximum resident set size (in bytes)   |
| MINFLT         |      24268 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      33608 | Number of block output operations      |
| NVCSW          |        364 | Number of voluntary context switches   |
| NIVCSW         |         50 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.06 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |          0 | 1 minute load average                  |
| LOAD_5MIN      |        154 | 5 minute load average                  |
| LOAD_15MIN     |        200 | 15 minute load average                 |
| UPTIME         |      16625 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  352247808 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  352247808 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.997778 | Total user time                        |
| STIME          |   0.201087 | Total system time                      |
| MAXRSS         |     190836 | Maximum resident set size              |
| MAXRSS_BYTES   |  195416064 | Maximum resident set size (in bytes)   |
| MINFLT         |      24268 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      33608 | Number of block output operations      |
| NVCSW          |        440 | Number of voluntary context switches   |
| NIVCSW         |         50 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+------------+----------------------------------------+
| NAME           | VALUE      | COMMENT                                |
+----------------+------------+----------------------------------------+
| LOADAVG_1MIN   |       0.06 | Load average over 1 minute             |
| LOADAVG_5MIN   |       0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |       0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |          0 | 1 minute load average                  |
| LOAD_5MIN      |        154 | 5 minute load average                  |
| LOAD_15MIN     |        200 | 15 minute load average                 |
| UPTIME         |      16627 | Uptime (in seconds)                    |
| UPTIME_DAYS    |          0 | Uptime (in days)                       |
| UPTIME_HOURS   |          4 | Uptime (in hours)                      |
| TOTAL_RAM      | 1039118336 | Total usable main memory size          |
| FREE_RAM       |  352247808 | Available memory size                  |
| SHARED_RAM     |          0 | Amount of shared memory                |
| BUFFER_RAM     |    2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |  859828224 | Total swap space size                  |
| FREE_SWAP      |  859828224 | Swap space available                   |
| PROCS          |        137 | Number of current processes            |
| TOTAL_HIGH_RAM |          0 | Total high memory size                 |
| FREE_HIGH_RAM  |          0 | Available high memory size             |
| TOTAL_LOW_RAM  | 1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |  352247808 | Available low memory size              |
| MEM_UNIT       |          1 | Memory unit size (in bytes)            |
| UTIME          |   0.999298 | Total user time                        |
| STIME          |   0.201394 | Total system time                      |
| MAXRSS         |     190836 | Maximum resident set size              |
| MAXRSS_BYTES   |  195416064 | Maximum resident set size (in bytes)   |
| MINFLT         |      24268 | Page reclaims (soft page faults)       |
| MAJFLT         |          0 | Page faults                            |
| INBLOCK        |       7680 | Number of block input operations       |
| OUBLOCK        |      33608 | Number of block output operations      |
| NVCSW          |        517 | Number of voluntary context switches   |
| NIVCSW         |         50 | Number of involuntary context switches |
+----------------+------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+--------------+----------------------------------------+
| NAME           | VALUE        | COMMENT                                |
+----------------+--------------+----------------------------------------+
| LOADAVG_1MIN   |         0.03 | Load average over 1 minute             |
| LOADAVG_5MIN   |         0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |         0.05 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.0283203125 | 1 minute load average                  |
| LOAD_5MIN      |          134 | 5 minute load average                  |
| LOAD_15MIN     |          186 | 15 minute load average                 |
| UPTIME         |        16677 | Uptime (in seconds)                    |
| UPTIME_DAYS    |            0 | Uptime (in days)                       |
| UPTIME_HOURS   |            4 | Uptime (in hours)                      |
| TOTAL_RAM      |   1039118336 | Total usable main memory size          |
| FREE_RAM       |    353685504 | Available memory size                  |
| SHARED_RAM     |            0 | Amount of shared memory                |
| BUFFER_RAM     |      2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |    859828224 | Total swap space size                  |
| FREE_SWAP      |    859828224 | Swap space available                   |
| PROCS          |          137 | Number of current processes            |
| TOTAL_HIGH_RAM |            0 | Total high memory size                 |
| FREE_HIGH_RAM  |            0 | Available high memory size             |
| TOTAL_LOW_RAM  |   1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |    353685504 | Available low memory size              |
| MEM_UNIT       |            1 | Memory unit size (in bytes)            |
| UTIME          |     0.114269 | Total user time                        |
| STIME          |     0.176934 | Total system time                      |
| MAXRSS         |       189196 | Maximum resident set size              |
| MAXRSS_BYTES   |    193736704 | Maximum resident set size (in bytes)   |
| MINFLT         |        23388 | Page reclaims (soft page faults)       |
| MAJFLT         |            0 | Page faults                            |
| INBLOCK        |         7680 | Number of block input operations       |
| OUBLOCK        |        32360 | Number of block output operations      |
| NVCSW          |           82 | Number of voluntary context switches   |
| NIVCSW         |           15 | Number of involuntary context switches |
+----------------+--------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
./[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.03 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.03271484375 | 1 minute load average                  |
| LOAD_5MIN      |           162 | 5 minute load average                  |
| LOAD_15MIN     |           186 | 15 minute load average                 |
| UPTIME         |         16749 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     356597760 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     356597760 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.108588 | Total user time                        |
| STIME          |      0.169087 | Total system time                      |
| MAXRSS         |        186464 | Maximum resident set size              |
| MAXRSS_BYTES   |     190939136 | Maximum resident set size (in bytes)   |
| MINFLT         |         23530 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            81 | Number of voluntary context switches   |
| NIVCSW         |            14 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.03 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.03271484375 | 1 minute load average                  |
| LOAD_5MIN      |           162 | 5 minute load average                  |
| LOAD_15MIN     |           186 | 15 minute load average                 |
| UPTIME         |         16752 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     354484224 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     354484224 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.987375 | Total user time                        |
| STIME          |      0.208362 | Total system time                      |
| MAXRSS         |        188776 | Maximum resident set size              |
| MAXRSS_BYTES   |     193306624 | Maximum resident set size (in bytes)   |
| MINFLT         |         23581 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         33592 | Number of block output operations      |
| NVCSW          |           175 | Number of voluntary context switches   |
| NIVCSW         |            59 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+--------------+----------------------------------------+
| NAME           | VALUE        | COMMENT                                |
+----------------+--------------+----------------------------------------+
| LOADAVG_1MIN   |         0.03 | Load average over 1 minute             |
| LOADAVG_5MIN   |         0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |         0.05 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.0302734375 | 1 minute load average                  |
| LOAD_5MIN      |          160 | 5 minute load average                  |
| LOAD_15MIN     |          186 | 15 minute load average                 |
| UPTIME         |        16755 | Uptime (in seconds)                    |
| UPTIME_DAYS    |            0 | Uptime (in days)                       |
| UPTIME_HOURS   |            4 | Uptime (in hours)                      |
| TOTAL_RAM      |   1039118336 | Total usable main memory size          |
| FREE_RAM       |    354484224 | Available memory size                  |
| SHARED_RAM     |            0 | Amount of shared memory                |
| BUFFER_RAM     |      2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |    859828224 | Total swap space size                  |
| FREE_SWAP      |    859828224 | Swap space available                   |
| PROCS          |          138 | Number of current processes            |
| TOTAL_HIGH_RAM |            0 | Total high memory size                 |
| FREE_HIGH_RAM  |            0 | Available high memory size             |
| TOTAL_LOW_RAM  |   1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |    354484224 | Available low memory size              |
| MEM_UNIT       |            1 | Memory unit size (in bytes)            |
| UTIME          |     0.989045 | Total user time                        |
| STIME          |     0.208714 | Total system time                      |
| MAXRSS         |       188776 | Maximum resident set size              |
| MAXRSS_BYTES   |    193306624 | Maximum resident set size (in bytes)   |
| MINFLT         |        23584 | Page reclaims (soft page faults)       |
| MAJFLT         |            0 | Page faults                            |
| INBLOCK        |         7680 | Number of block input operations       |
| OUBLOCK        |        33592 | Number of block output operations      |
| NVCSW          |          253 | Number of voluntary context switches   |
| NIVCSW         |           59 | Number of involuntary context switches |
+----------------+--------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.01 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.01416015625 | 1 minute load average                  |
| LOAD_5MIN      | 0.03466796875 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         16804 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     357908480 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     357908480 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.117855 | Total user time                        |
| STIME          |      0.150492 | Total system time                      |
| MAXRSS         |        185088 | Maximum resident set size              |
| MAXRSS_BYTES   |     189530112 | Maximum resident set size (in bytes)   |
| MINFLT         |         24738 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            94 | Number of voluntary context switches   |
| NIVCSW         |            11 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:70:60: error: ‘print’ was not declared in this scope
   table->field[1]->store(print("%ld", info.loads[0] / 65536));
                                                            ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1127 (HY000): Can't find symbol 'OS_METRICS' in library
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.08 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             1 | 1 minute load average                  |
| LOAD_5MIN      | 0.03369140625 | 5 minute load average                  |
| LOAD_15MIN     |    0.05078125 | 15 minute load average                 |
| UPTIME         |         16982 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     357752832 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     357752832 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      1.014859 | Total user time                        |
| STIME          |      0.161395 | Total system time                      |
| MAXRSS         |        185672 | Maximum resident set size              |
| MAXRSS_BYTES   |     190128128 | Maximum resident set size (in bytes)   |
| MINFLT         |         23325 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         33600 | Number of block output operations      |
| NVCSW          |           218 | Number of voluntary context switches   |
| NIVCSW         |            53 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:70:63: warning: format ‘%f’ expects argument of type ‘double’, but argument 2 has type ‘__kernel_ulong_t {aka long unsigned int}’ [-Wformat=]
   table->field[1]->store(printf("%0.2f", info.loads[0] / 65536));
                                                               ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.01 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      |  0.0205078125 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         17116 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     360828928 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     360828928 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.107776 | Total user time                        |
| STIME          |       0.15693 | Total system time                      |
| MAXRSS         |        182260 | Maximum resident set size              |
| MAXRSS_BYTES   |     186634240 | Maximum resident set size (in bytes)   |
| MINFLT         |         24009 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            14 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      |  0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         17201 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     361418752 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     361418752 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.119212 | Total user time                        |
| STIME          |      0.141351 | Total system time                      |
| MAXRSS         |        181664 | Maximum resident set size              |
| MAXRSS_BYTES   |     186023936 | Maximum resident set size (in bytes)   |
| MINFLT         |         24886 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            15 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      |  0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         17230 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     356507648 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     356507648 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.136873 | Total user time                        |
| STIME          |      0.220437 | Total system time                      |
| MAXRSS         |        186484 | Maximum resident set size              |
| MAXRSS_BYTES   |     190959616 | Maximum resident set size (in bytes)   |
| MINFLT         |         24052 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32368 | Number of block output operations      |
| NVCSW          |            99 | Number of voluntary context switches   |
| NIVCSW         |            15 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:71:57: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
   table->field[1]->store(sprintf("%0.2f", (float) 1.2345));
                                                         ^
osmetricsplugin.cc:71:57: error: cannot convert ‘float’ to ‘const char*’ for argument ‘2’ to ‘int sprintf(char*, const char*, ...)’
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:71:49: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
   table->field[1]->store(sprintf("%0.2f", 1.2345));
                                                 ^
osmetricsplugin.cc:71:49: error: cannot convert ‘double’ to ‘const char*’ for argument ‘2’ to ‘int sprintf(char*, const char*, ...)’
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      |  0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         17317 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     354693120 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     354693120 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |       0.10518 | Total user time                        |
| STIME          |      0.159086 | Total system time                      |
| MAXRSS         |        188120 | Maximum resident set size              |
| MAXRSS_BYTES   |     192634880 | Maximum resident set size (in bytes)   |
| MINFLT         |         22904 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            12 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:71:47: warning: format ‘%f’ expects argument of type ‘double’, but argument 2 has type ‘int’ [-Wformat=]
   table->field[1]->store(printf("%0.2f", 1 / 3));
                                               ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.03 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      |   0.025390625 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         17383 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     361930752 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     361930752 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.109233 | Total user time                        |
| STIME          |      0.152178 | Total system time                      |
| MAXRSS         |        181192 | Maximum resident set size              |
| MAXRSS_BYTES   |     185540608 | Maximum resident set size (in bytes)   |
| MINFLT         |         22719 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            13 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.08 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             8 | 1 minute load average                  |
| LOAD_5MIN      | 0.03466796875 | 5 minute load average                  |
| LOAD_15MIN     | 0.05029296875 | 15 minute load average                 |
| UPTIME         |         17456 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     359874560 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     359874560 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.130709 | Total user time                        |
| STIME          |      0.152493 | Total system time                      |
| MAXRSS         |        183164 | Maximum resident set size              |
| MAXRSS_BYTES   |     187559936 | Maximum resident set size (in bytes)   |
| MINFLT         |         23727 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32360 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            13 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      |      0.015625 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         17651 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     358080512 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     358080512 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.100662 | Total user time                        |
| STIME          |      0.170351 | Total system time                      |
| MAXRSS         |        183268 | Maximum resident set size              |
| MAXRSS_BYTES   |     187666432 | Maximum resident set size (in bytes)   |
| MINFLT         |         23241 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |         10752 | Number of block input operations       |
| OUBLOCK        |         32360 | Number of block output operations      |
| NVCSW          |            83 | Number of voluntary context switches   |
| NIVCSW         |            13 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:70:72: warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
   table->field[1]->store(sprintf("%4.2f", (float) info.loads[0] / 65536));
                                                                        ^
osmetricsplugin.cc:70:72: error: cannot convert ‘float’ to ‘const char*’ for argument ‘2’ to ‘int sprintf(char*, const char*, ...)’
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.11 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.04 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |             4 | 1 minute load average                  |
| LOAD_5MIN      | 0.04345703125 | 5 minute load average                  |
| LOAD_15MIN     |  0.0537109375 | 15 minute load average                 |
| UPTIME         |         17723 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     357937152 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     357937152 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.118694 | Total user time                        |
| STIME          |      0.167568 | Total system time                      |
| MAXRSS         |        183432 | Maximum resident set size              |
| MAXRSS_BYTES   |     187834368 | Maximum resident set size (in bytes)   |
| MINFLT         |         22776 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            94 | Number of voluntary context switches   |
| NIVCSW         |            18 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.02 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| LOADAVG_1MIN   |          0.45 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.17 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.09 | Load average over 15 minutes           |
| LOAD_1MIN      |             5 | 1 minute load average                  |
| LOAD_5MIN      |      0.171875 | 5 minute load average                  |
| LOAD_15MIN     | 0.09228515625 | 15 minute load average                 |
| UPTIME         |         17875 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             4 | Uptime (in hours)                      |
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     360693760 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           137 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     360693760 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.118208 | Total user time                        |
| STIME          |      0.159928 | Total system time                      |
| MAXRSS         |        180720 | Maximum resident set size              |
| MAXRSS_BYTES   |     185057280 | Maximum resident set size (in bytes)   |
| MINFLT         |         23123 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            94 | Number of voluntary context switches   |
| NIVCSW         |            11 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# nano includes/getmem.h 
[root@localhost osmetricsplugin]# nano includes/get
getload.h        getmem.h         getrusage.h      getswappiness.h  
[root@localhost osmetricsplugin]# nano includes/getrusage.h 
[root@localhost osmetricsplugin]# nano includes/getswappiness.h 
[root@localhost osmetricsplugin]# nano includes/getswappiness.h 
[root@localhost osmetricsplugin]# nano includes/getload.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+-------------+----------------------------------------+
| NAME           | VALUE       | COMMENT                                |
+----------------+-------------+----------------------------------------+
| LOADAVG_1MIN   |        0.09 | Load average over 1 minute             |
| LOADAVG_5MIN   |        0.09 | Load average over 5 minutes            |
| LOADAVG_15MIN  |        0.07 | Load average over 15 minutes           |
| LOAD_1MIN      |           4 | 1 minute load average                  |
| LOAD_5MIN      | 0.087890625 | 5 minute load average                  |
| LOAD_15MIN     | 0.072265625 | 15 minute load average                 |
| UPTIME         |       18135 | Uptime (in seconds)                    |
| UPTIME_DAYS    |           0 | Uptime (in days)                       |
| UPTIME_HOURS   |           5 | Uptime (in hours)                      |
| TOTAL_RAM      |  1039118336 | Total usable main memory size          |
| FREE_RAM       |   361132032 | Available memory size                  |
| SHARED_RAM     |           0 | Amount of shared memory                |
| BUFFER_RAM     |     2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |   859828224 | Total swap space size                  |
| FREE_SWAP      |   859828224 | Swap space available                   |
| PROCS          |         137 | Number of current processes            |
| TOTAL_HIGH_RAM |           0 | Total high memory size                 |
| FREE_HIGH_RAM  |           0 | Available high memory size             |
| TOTAL_LOW_RAM  |  1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |   361132032 | Available low memory size              |
| MEM_UNIT       |           1 | Memory unit size (in bytes)            |
| UTIME          |    0.138693 | Total user time                        |
| STIME          |    0.191528 | Total system time                      |
| MAXRSS         |      180284 | Maximum resident set size              |
| MAXRSS_BYTES   |   184610816 | Maximum resident set size (in bytes)   |
| MINFLT         |       23523 | Page reclaims (soft page faults)       |
| MAJFLT         |           0 | Page faults                            |
| INBLOCK        |        7680 | Number of block input operations       |
| OUBLOCK        |       32360 | Number of block output operations      |
| NVCSW          |          82 | Number of voluntary context switches   |
| NIVCSW         |          10 | Number of involuntary context switches |
+----------------+-------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
ERROR 2002 (HY000): Can't connect to local MySQL server through socket '/var/lib/mysql/mysql.sock' (111)
ERROR: 
Can't connect to the server

mysql> SELECT * FROM information_schema.OS_METRICS;
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
ERROR 2002 (HY000): Can't connect to local MySQL server through socket '/var/lib/mysql/mysql.sock' (111)
ERROR: 
Can't connect to the server

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+--------------+----------------------------------------+
| NAME           | VALUE        | COMMENT                                |
+----------------+--------------+----------------------------------------+
| LOADAVG_1MIN   |         0.27 | Load average over 1 minute             |
| LOADAVG_5MIN   |         0.11 | Load average over 5 minutes            |
| LOADAVG_15MIN  |         0.07 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.2666015625 | 1 minute load average                  |
| LOAD_5MIN      |  0.111328125 | 5 minute load average                  |
| LOAD_15MIN     |  0.072265625 | 15 minute load average                 |
| UPTIME         |        18548 | Uptime (in seconds)                    |
| UPTIME_DAYS    |            0 | Uptime (in days)                       |
| UPTIME_HOURS   |            5 | Uptime (in hours)                      |
| TOTAL_RAM      |   1039118336 | Total usable main memory size          |
| FREE_RAM       |    357994496 | Available memory size                  |
| SHARED_RAM     |            0 | Amount of shared memory                |
| BUFFER_RAM     |      2158592 | Memory used by buffers                 |
| TOTAL_SWAP     |    859828224 | Total swap space size                  |
| FREE_SWAP      |    859828224 | Swap space available                   |
| PROCS          |          138 | Number of current processes            |
| TOTAL_HIGH_RAM |            0 | Total high memory size                 |
| FREE_HIGH_RAM  |            0 | Available high memory size             |
| TOTAL_LOW_RAM  |   1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |    357994496 | Available low memory size              |
| MEM_UNIT       |            1 | Memory unit size (in bytes)            |
| UTIME          |     0.123534 | Total user time                        |
| STIME          |      0.16604 | Total system time                      |
| MAXRSS         |       183256 | Maximum resident set size              |
| MAXRSS_BYTES   |    187654144 | Maximum resident set size (in bytes)   |
| MINFLT         |        22729 | Page reclaims (soft page faults)       |
| MAJFLT         |            0 | Page faults                            |
| INBLOCK        |         7680 | Number of block input operations       |
| OUBLOCK        |        32352 | Number of block output operations      |
| NVCSW          |           72 | Number of voluntary context switches   |
| NIVCSW         |           14 | Number of involuntary context switches |
+----------------+--------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     358596608 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |  0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      | 0.02783203125 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         18981 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             5 | Uptime (in hours)                      |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     358596608 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.117824 | Total user time                        |
| STIME          |      0.142445 | Total system time                      |
| MAXRSS         |        182612 | Maximum resident set size              |
| MAXRSS_BYTES   |     186994688 | Maximum resident set size (in bytes)   |
| MINFLT         |         23583 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            13 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1125 (HY000): Function 'OS_METRICS' already exists
mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     356483072 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |  0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      | 0.02685546875 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         18994 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             5 | Uptime (in hours)                      |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           138 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     356483072 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      1.020346 | Total user time                        |
| STIME          |      0.167369 | Total system time                      |
| MAXRSS         |        185060 | Maximum resident set size              |
| MAXRSS_BYTES   |     189501440 | Maximum resident set size (in bytes)   |
| MINFLT         |         23656 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         33592 | Number of block output operations      |
| NVCSW          |           446 | Number of voluntary context switches   |
| NIVCSW         |            49 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     359505920 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |  0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      | 0.02392578125 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         19021 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             5 | Uptime (in hours)                      |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     359505920 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      1.029827 | Total user time                        |
| STIME          |      0.144655 | Total system time                      |
| MAXRSS         |        182120 | Maximum resident set size              |
| MAXRSS_BYTES   |     186490880 | Maximum resident set size (in bytes)   |
| MINFLT         |         23011 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |             0 | Number of block input operations       |
| OUBLOCK        |         33592 | Number of block output operations      |
| NVCSW          |           227 | Number of voluntary context switches   |
| NIVCSW         |            53 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     357785600 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| LOADAVG_1MIN   |             0 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |  0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |  0.0224609375 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         19037 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             5 | Uptime (in hours)                      |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           140 | Number of current processes            |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     357785600 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| UTIME          |      0.112938 | Total user time                        |
| STIME          |      0.148702 | Total system time                      |
| MAXRSS         |        183248 | Maximum resident set size              |
| MAXRSS_BYTES   |     187645952 | Maximum resident set size (in bytes)   |
| MINFLT         |         23237 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32360 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            11 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     358789120 | Available memory size                  |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     358789120 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |          0.15 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.05 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.06 | Load average over 15 minutes           |
| LOAD_1MIN      | 0.14990234375 | 1 minute load average                  |
| LOAD_5MIN      |   0.048828125 | 5 minute load average                  |
| LOAD_15MIN     |  0.0556640625 | 15 minute load average                 |
| UPTIME         |         19101 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             5 | Uptime (in hours)                      |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           139 | Number of current processes            |
| UTIME          |      0.091877 | Total user time                        |
| STIME          |      0.160294 | Total system time                      |
| MAXRSS         |        182228 | Maximum resident set size              |
| MAXRSS_BYTES   |     186601472 | Maximum resident set size (in bytes)   |
| MINFLT         |         23493 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            82 | Number of voluntary context switches   |
| NIVCSW         |            13 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
31 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:75:48: error: ‘struct sysinfo’ has no member named ‘total’
   table->field[1]->store(info.totalram / (info.total-ram - info.freeram) * 100);
                                                ^
osmetricsplugin.cc:75:54: error: ‘ram’ was not declared in this scope
   table->field[1]->store(info.totalram / (info.total-ram - info.freeram) * 100);
                                                      ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+--------------+----------------------------------------+
| NAME           | VALUE        | COMMENT                                |
+----------------+--------------+----------------------------------------+
| TOTAL_RAM      |   1039118336 | Total usable main memory size          |
| FREE_RAM       |    360927232 | Available memory size                  |
| USED_RAM       |    678191104 | Used memory size                       |
| FREE_RAM_PCT   |          200 | Available memory as a percentage       |
| USED_RAM_PCT   |          100 | Available memory as a percentage       |
| SHARED_RAM     |            0 | Amount of shared memory                |
| BUFFER_RAM     |      2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |            0 | Total high memory size                 |
| FREE_HIGH_RAM  |            0 | Available high memory size             |
| TOTAL_LOW_RAM  |   1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |    360927232 | Available low memory size              |
| MEM_UNIT       |            1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |         0.07 | Load average over 1 minute             |
| LOADAVG_5MIN   |         0.03 | Load average over 5 minutes            |
| LOADAVG_15MIN  |         0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |    0.0703125 | 1 minute load average                  |
| LOAD_5MIN      | 0.0302734375 | 5 minute load average                  |
| LOAD_15MIN     | 0.0498046875 | 15 minute load average                 |
| UPTIME         |        19542 | Uptime (in seconds)                    |
| UPTIME_DAYS    |            0 | Uptime (in days)                       |
| UPTIME_HOURS   |            5 | Uptime (in hours)                      |
| TOTAL_SWAP     |    859828224 | Total swap space size                  |
| FREE_SWAP      |    859828224 | Swap space available                   |
| PROCS          |          138 | Number of current processes            |
| UTIME          |     0.122904 | Total user time                        |
| STIME          |     0.146803 | Total system time                      |
| MAXRSS         |       180176 | Maximum resident set size              |
| MAXRSS_BYTES   |    184500224 | Maximum resident set size (in bytes)   |
| MINFLT         |        23492 | Page reclaims (soft page faults)       |
| MAJFLT         |            0 | Page faults                            |
| INBLOCK        |         7680 | Number of block input operations       |
| OUBLOCK        |        32352 | Number of block output operations      |
| NVCSW          |           82 | Number of voluntary context switches   |
| NIVCSW         |           12 | Number of involuntary context switches |
+----------------+--------------+----------------------------------------+
34 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+---------------+----------------------------------------+
| NAME           | VALUE         | COMMENT                                |
+----------------+---------------+----------------------------------------+
| TOTAL_RAM      |    1039118336 | Total usable main memory size          |
| FREE_RAM       |     356339712 | Available memory size                  |
| USED_RAM       |     682778624 | Used memory size                       |
| FREE_RAM_PCT   |             0 | Available memory as a percentage       |
| USED_RAM_PCT   |             0 | Free memory as a percentage            |
| SHARED_RAM     |             0 | Amount of shared memory                |
| BUFFER_RAM     |       2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |             0 | Total high memory size                 |
| FREE_HIGH_RAM  |             0 | Available high memory size             |
| TOTAL_LOW_RAM  |    1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |     356339712 | Available low memory size              |
| MEM_UNIT       |             1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |          0.01 | Load average over 1 minute             |
| LOADAVG_5MIN   |          0.02 | Load average over 5 minutes            |
| LOADAVG_15MIN  |          0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |   0.005859375 | 1 minute load average                  |
| LOAD_5MIN      |      0.015625 | 5 minute load average                  |
| LOAD_15MIN     | 0.04541015625 | 15 minute load average                 |
| UPTIME         |         19693 | Uptime (in seconds)                    |
| UPTIME_DAYS    |             0 | Uptime (in days)                       |
| UPTIME_HOURS   |             5 | Uptime (in hours)                      |
| TOTAL_SWAP     |     859828224 | Total swap space size                  |
| FREE_SWAP      |     859828224 | Swap space available                   |
| PROCS          |           137 | Number of current processes            |
| UTIME          |      0.115446 | Total user time                        |
| STIME          |      0.162641 | Total system time                      |
| MAXRSS         |        184764 | Maximum resident set size              |
| MAXRSS_BYTES   |     189198336 | Maximum resident set size (in bytes)   |
| MINFLT         |         23586 | Page reclaims (soft page faults)       |
| MAJFLT         |             0 | Page faults                            |
| INBLOCK        |          7680 | Number of block input operations       |
| OUBLOCK        |         32352 | Number of block output operations      |
| NVCSW          |            72 | Number of voluntary context switches   |
| NIVCSW         |            13 | Number of involuntary context switches |
+----------------+---------------+----------------------------------------+
34 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         359108608 | Available memory size                  |
| USED_RAM       |         680009728 | Used memory size                       |
| FREE_RAM_PCT   |  34.5589714050293 | Available memory as a percentage       |
| USED_RAM_PCT   | 65.44103240966797 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         359108608 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |                 0 | Load average over 1 minute             |
| LOADAVG_5MIN   |              0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |              0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |      0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |      0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
| UPTIME         |             19746 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| PROCS          |               138 | Number of current processes            |
| UTIME          |          0.128458 | Total user time                        |
| STIME          |          0.145394 | Total system time                      |
| MAXRSS         |            181976 | Maximum resident set size              |
| MAXRSS_BYTES   |         186343424 | Maximum resident set size (in bytes)   |
| MINFLT         |             22917 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |              7680 | Number of block input operations       |
| OUBLOCK        |             32352 | Number of block output operations      |
| NVCSW          |                82 | Number of voluntary context switches   |
| NIVCSW         |                13 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
34 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         360366080 | Available memory size                  |
| USED_RAM       |         678752256 | Used memory size                       |
| FREE_RAM_PCT   | 34.67998504638672 | Available memory as a percentage       |
| USED_RAM_PCT   | 65.32001495361328 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         360366080 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |                 0 | Load average over 1 minute             |
| LOADAVG_5MIN   |              0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |              0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |      0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |      0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
| UPTIME         |             20023 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space used (percentage)           |
| USED_SWAP_PCT  |                 0 | Swap space used (percentage)           |
| PROCS          |               138 | Number of current processes            |
| UTIME          |          0.119524 | Total user time                        |
| STIME          |          0.165627 | Total system time                      |
| MAXRSS         |            180640 | Maximum resident set size              |
| MAXRSS_BYTES   |         184975360 | Maximum resident set size (in bytes)   |
| MINFLT         |             23607 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |              7680 | Number of block input operations       |
| OUBLOCK        |             32360 | Number of block output operations      |
| NVCSW          |                82 | Number of voluntary context switches   |
| NIVCSW         |                13 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
37 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         357666816 | Available memory size                  |
| USED_RAM       |         681451520 | Used memory size                       |
| FREE_RAM_PCT   | 34.42021942138672 | Available memory as a percentage       |
| USED_RAM_PCT   | 65.57978057861328 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         357666816 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |                 0 | Load average over 1 minute             |
| LOADAVG_5MIN   |              0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |              0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |     0.00439453125 | 1 minute load average                  |
| LOAD_5MIN      |      0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
| UPTIME         |             20203 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space used as a percentage        |
| USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
| PROCS          |               137 | Number of current processes            |
| UTIME          |          0.098316 | Total user time                        |
| STIME          |          0.163861 | Total system time                      |
| MAXRSS         |            183384 | Maximum resident set size              |
| MAXRSS_BYTES   |         187785216 | Maximum resident set size (in bytes)   |
| MINFLT         |             22751 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |              7680 | Number of block input operations       |
| OUBLOCK        |             32352 | Number of block output operations      |
| NVCSW          |                81 | Number of voluntary context switches   |
| NIVCSW         |                12 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
37 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         358707200 | Available memory size                  |
| USED_RAM       |         680411136 | Used memory size                       |
| FREE_RAM_PCT   | 34.52034378051758 | Available memory as a percentage       |
| USED_RAM_PCT   | 65.47966003417969 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         358707200 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOADAVG_1MIN   |                 0 | Load average over 1 minute             |
| LOADAVG_5MIN   |              0.01 | Load average over 5 minutes            |
| LOADAVG_15MIN  |              0.05 | Load average over 15 minutes           |
| LOAD_1MIN      |      0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |      0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
| UPTIME         |             20355 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space used as a percentage        |
| USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
| PROCS          |               138 | Number of current processes            |
| UTIME          |          0.119309 | Total user time                        |
| STIME          |          0.146621 | Total system time                      |
| MAXRSS         |            182484 | Maximum resident set size              |
| MAXRSS_BYTES   |         186863616 | Maximum resident set size (in bytes)   |
| MINFLT         |             24031 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |              7680 | Number of block input operations       |
| OUBLOCK        |             32352 | Number of block output operations      |
| NVCSW          |                82 | Number of voluntary context switches   |
| NIVCSW         |                14 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
37 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:26:11: warning: unused variable ‘load’ [-Wunused-variable]
   double *load;
           ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         360857600 | Available memory size                  |
| USED_RAM       |         678260736 | Used memory size                       |
| FREE_RAM_PCT   | 34.72728729248047 | Available memory as a percentage       |
| USED_RAM_PCT   | 65.27271270751953 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         360857600 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOAD_1MIN      |       0.080078125 | 1 minute load average                  |
| LOAD_5MIN      |     0.03662109375 | 5 minute load average                  |
| LOAD_15MIN     |      0.0498046875 | 15 minute load average                 |
| UPTIME         |             20518 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space used as a percentage        |
| USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
| PROCS          |               137 | Number of current processes            |
| UTIME          |          0.085403 | Total user time                        |
| STIME          |          0.187646 | Total system time                      |
| MAXRSS         |            180200 | Maximum resident set size              |
| MAXRSS_BYTES   |         184524800 | Maximum resident set size (in bytes)   |
| MINFLT         |             24510 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |              7680 | Number of block input operations       |
| OUBLOCK        |             32352 | Number of block output operations      |
| NVCSW          |                82 | Number of voluntary context switches   |
| NIVCSW         |                11 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
34 rows in set (0.01 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./no
-bash: ./no: No such file or directory
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+--------------------+----------------------------------------+
| NAME           | VALUE              | COMMENT                                |
+----------------+--------------------+----------------------------------------+
| TOTAL_RAM      |         1039118336 | Total usable main memory size          |
| FREE_RAM       |          358694912 | Available memory size                  |
| USED_RAM       |          680423424 | Used memory size                       |
| FREE_RAM_PCT   | 34.519161224365234 | Available memory as a percentage       |
| USED_RAM_PCT   |  65.48084259033203 | Free memory as a percentage            |
| SHARED_RAM     |                  0 | Amount of shared memory                |
| BUFFER_RAM     |            2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                  0 | Total high memory size                 |
| FREE_HIGH_RAM  |                  0 | Available high memory size             |
| TOTAL_LOW_RAM  |         1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |          358694912 | Available low memory size              |
| MEM_UNIT       |                  1 | Memory unit size (in bytes)            |
| LOAD_1MIN      |       0.1025390625 | 1 minute load average                  |
| LOAD_5MIN      |       0.0537109375 | 5 minute load average                  |
| LOAD_15MIN     |         0.05078125 | 15 minute load average                 |
| UPTIME         |              20635 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                  0 | Uptime (in days)                       |
| UPTIME_HOURS   |                  5 | Uptime (in hours)                      |
| TOTAL_SWAP     |          859828224 | Total swap space size                  |
| FREE_SWAP      |          859828224 | Swap space available                   |
| USED_SWAP      |                  0 | Swap space used                        |
| FREE_SWAP_PCT  |                100 | Swap space available as a percentage   |
| USED_SWAP_PCT  |                  0 | Swap space used as a percentage        |
| PROCS          |                137 | Number of current processes            |
| UTIME          |           0.116341 | Total user time                        |
| STIME          |           0.156582 | Total system time                      |
| MAXRSS         |             182288 | Maximum resident set size              |
| MAXRSS_BYTES   |          186662912 | Maximum resident set size (in bytes)   |
| MINFLT         |              24015 | Page reclaims (soft page faults)       |
| MAJFLT         |                  0 | Page faults                            |
| INBLOCK        |               7680 | Number of block input operations       |
| OUBLOCK        |              32352 | Number of block output operations      |
| NVCSW          |                 72 | Number of voluntary context switches   |
| NIVCSW         |                 12 | Number of involuntary context switches |
+----------------+--------------------+----------------------------------------+
34 rows in set (0.01 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+--------------------+----------------------------------------+
| NAME           | VALUE              | COMMENT                                |
+----------------+--------------------+----------------------------------------+
| TOTAL_RAM      |         1039118336 | Total usable main memory size          |
| FREE_RAM       |          350736384 | Available memory size                  |
| USED_RAM       |          688381952 | Used memory size                       |
| FREE_RAM_PCT   | 33.753265380859375 | Available memory as a percentage       |
| USED_RAM_PCT   |  66.24673461914062 | Free memory as a percentage            |
| SHARED_RAM     |                  0 | Amount of shared memory                |
| BUFFER_RAM     |            2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                  0 | Total high memory size                 |
| FREE_HIGH_RAM  |                  0 | Available high memory size             |
| TOTAL_LOW_RAM  |         1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |          350736384 | Available low memory size              |
| MEM_UNIT       |                  1 | Memory unit size (in bytes)            |
| LOAD_1MIN      |       0.0576171875 | 1 minute load average                  |
| LOAD_5MIN      |           0.046875 | 5 minute load average                  |
| LOAD_15MIN     |      0.04736328125 | 15 minute load average                 |
| UPTIME         |              20670 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                  0 | Uptime (in days)                       |
| UPTIME_HOURS   |                  5 | Uptime (in hours)                      |
| TOTAL_SWAP     |          859828224 | Total swap space size                  |
| FREE_SWAP      |          859828224 | Swap space available                   |
| USED_SWAP      |                  0 | Swap space used                        |
| FREE_SWAP_PCT  |                100 | Swap space available as a percentage   |
| USED_SWAP_PCT  |                  0 | Swap space used as a percentage        |
| PROCS          |                137 | Number of current processes            |
| UTIME          |           1.028813 | Total user time                        |
| STIME          |           0.182298 | Total system time                      |
| MAXRSS         |             190060 | Maximum resident set size              |
| MAXRSS_BYTES   |          194621440 | Maximum resident set size (in bytes)   |
| MINFLT         |              24065 | Page reclaims (soft page faults)       |
| MAJFLT         |                  0 | Page faults                            |
| INBLOCK        |               7680 | Number of block input operations       |
| OUBLOCK        |              33592 | Number of block output operations      |
| NVCSW          |                983 | Number of voluntary context switches   |
| NIVCSW         |                 50 | Number of involuntary context switches |
+----------------+--------------------+----------------------------------------+
34 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ls includes/
getload.h  getmem.h  getrusage.h  getswappiness.h
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# nano includes/getswappiness.h 
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1126 (HY000): Can't open shared library '/usr/lib64/mysql/plugin/osmetricsplugin.so' (errno: 2 /usr/lib64/mysql/plugin/osmetricsplugin.so: undefined symbol: _Z12sysctlbynamePKcPvPmPKvm)
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1126 (HY000): Can't open shared library '/usr/lib64/mysql/plugin/osmetricsplugin.so' (errno: 2 /usr/lib64/mysql/plugin/osmetricsplugin.so: undefined symbol: _Z12sysctlbynamePKcPvPmPKvm)
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> quit
Bye
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1126 (HY000): Can't open shared library '/usr/lib64/mysql/plugin/osmetricsplugin.so' (errno: 2 /usr/lib64/mysql/plugin/osmetricsplugin.so: undefined symbol: _Z12sysctlbynamePKcPvPmPKvm)
mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1030 (HY000): Got error 1 from storage engine
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 1030 (HY000): Got error 1 from storage engine
mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# service mysql stop
Redirecting to /bin/systemctl stop mysql.service
[root@localhost osmetricsplugin]# service mysql start
Redirecting to /bin/systemctl start mysql.service
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         354590720 | Available memory size                  |
| USED_RAM       |         684527616 | Used memory size                       |
| FREE_RAM_PCT   | 34.12419128417969 | Available memory as a percentage       |
| USED_RAM_PCT   | 65.87580871582031 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         354590720 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOAD_1MIN      |     0.06201171875 | 1 minute load average                  |
| LOAD_5MIN      |       0.068359375 | 5 minute load average                  |
| LOAD_15MIN     |      0.0498046875 | 15 minute load average                 |
| UPTIME         |             21108 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space available as a percentage   |
| USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
| PROCS          |               138 | Number of current processes            |
| UTIME          |          1.000846 | Total user time                        |
| STIME          |          0.154486 | Total system time                      |
| MAXRSS         |            186504 | Maximum resident set size              |
| MAXRSS_BYTES   |         190980096 | Maximum resident set size (in bytes)   |
| MINFLT         |             23592 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |                 0 | Number of block input operations       |
| OUBLOCK        |             33600 | Number of block output operations      |
| NVCSW          |               189 | Number of voluntary context switches   |
| NIVCSW         |                53 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
34 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# cat /proc/swaps 
Filename				Type		Size	Used	Priority
/dev/dm-1                               partition	839676	0	-2
[root@localhost osmetricsplugin]# cat /proc/cpuinfo 
processor	: 0
vendor_id	: GenuineIntel
cpu family	: 6
model		: 61
model name	: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz
stepping	: 4
cpu MHz		: 2699.998
cache size	: 3072 KB
physical id	: 0
siblings	: 1
core id		: 0
cpu cores	: 1
apicid		: 0
initial apicid	: 0
fpu		: yes
fpu_exception	: yes
cpuid level	: 20
wp		: yes
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc eagerfpu pni pclmulqdq monitor ssse3 cx16 pcid sse4_1 sse4_2 x2apic movbe popcnt aes xsave avx rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single fsgsbase avx2 invpcid rdseed md_clear flush_l1d
bogomips	: 5399.99
clflush size	: 64
cache_alignment	: 64
address sizes	: 39 bits physical, 48 bits virtual
power management:

[root@localhost osmetricsplugin]# cat /proc/meminfo 
MemTotal:        1014764 kB
MemFree:          340220 kB
MemAvailable:     569764 kB
Buffers:            2108 kB
Cached:           349128 kB
SwapCached:            0 kB
Active:           434996 kB
Inactive:         162468 kB
Active(anon):     246484 kB
Inactive(anon):     6600 kB
Active(file):     188512 kB
Inactive(file):   155868 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:        839676 kB
SwapFree:         839676 kB
Dirty:                56 kB
Writeback:             0 kB
AnonPages:        246260 kB
Mapped:            28692 kB
Shmem:              6856 kB
Slab:              38796 kB
SReclaimable:      25880 kB
SUnreclaim:        12916 kB
KernelStack:        2176 kB
PageTables:         4792 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     1347056 kB
Committed_AS:     850008 kB
VmallocTotal:   34359738367 kB
VmallocUsed:        5740 kB
VmallocChunk:   34359729152 kB
Percpu:              176 kB
HardwareCorrupted:     0 kB
AnonHugePages:    118784 kB
CmaTotal:              0 kB
CmaFree:               0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
DirectMap4k:       53184 kB
DirectMap2M:      995328 kB
[root@localhost osmetricsplugin]# cat /proc/loadavg 
0.00 0.04 0.05 2/137 7494
[root@localhost osmetricsplugin]# cat /proc/
Display all 150 possibilities? (y or n)
1/             14/            281/           369/           393/           550/           642/           95/            driver/        kmsg           partitions     timer_stats
10/            15/            283/           370/           3992/          552/           647/           acpi/          execdomains    kpagecount     sched_debug    tty/
1066/          16/            284/           383/           4/             554/           649/           asound/        fb             kpageflags     schedstat      uptime
1067/          17/            285/           384/           41/            555/           664/           buddyinfo      filesystems    loadavg        scsi/          version
1068/          18/            286/           385/           43/            558/           665/           bus/           fs/            locks          self/          vmallocinfo
11/            19/            289/           386/           44/            561/           7/             cgroups        interrupts     mdstat         slabinfo       vmstat
1202/          2/             30/            387/           45/            5843/          7182/          cmdline        iomem          meminfo        softirqs       zoneinfo
1205/          20/            31/            388/           46/            6/             7285/          consoles       ioports        misc           stat           
1207/          21/            318/           389/           471/           60/            7286/          cpuinfo        irq/           modules        swaps          
1242/          22/            32/            390/           493/           607/           7450/          crypto         kallsyms       mounts         sys/           
13/            23/            33/            391/           500/           629/           7485/          devices        kcore          mtrr           sysrq-trigger  
1305/          24/            359/           392/           546/           631/           8/             diskstats      keys           net/           sysvipc/       
1309/          270/           360/           3928/          548/           634/           9/             dma            key-users      pagetypeinfo   timer_list     
[root@localhost osmetricsplugin]# cat /proc/vmstat
nr_free_pages 83889
nr_alloc_batch 1701
nr_inactive_anon 1650
nr_active_anon 62769
nr_inactive_file 38967
nr_active_file 47128
nr_unevictable 0
nr_mlock 0
nr_anon_pages 20729
nr_mapped 7173
nr_file_pages 87809
nr_dirty 0
nr_writeback 0
nr_slab_reclaimable 6470
nr_slab_unreclaimable 3229
nr_page_table_pages 1198
nr_kernel_stack 136
nr_unstable 0
nr_bounce 0
nr_vmscan_write 0
nr_vmscan_immediate_reclaim 0
nr_writeback_temp 0
nr_isolated_anon 0
nr_isolated_file 0
nr_shmem 1714
nr_dirtied 245569
nr_written 241522
numa_hit 4861304
numa_miss 0
numa_foreign 0
numa_interleave 13663
numa_local 4861304
numa_other 0
workingset_refault 0
workingset_activate 0
workingset_nodereclaim 0
nr_anon_transparent_hugepages 82
nr_free_cma 0
nr_dirty_threshold 42256
nr_dirty_background_threshold 14085
pgpgin 571183
pgpgout 1307947
pswpin 0
pswpout 0
pgalloc_dma 102979
pgalloc_dma32 7508843
pgalloc_normal 0
pgalloc_movable 0
pgfree 7695845
pgactivate 59982
pgdeactivate 0
pgfault 6213976
pgmajfault 805
pglazyfreed 0
pgrefill_dma 0
pgrefill_dma32 0
pgrefill_normal 0
pgrefill_movable 0
pgsteal_kswapd_dma 0
pgsteal_kswapd_dma32 0
pgsteal_kswapd_normal 0
pgsteal_kswapd_movable 0
pgsteal_direct_dma 0
pgsteal_direct_dma32 0
pgsteal_direct_normal 0
pgsteal_direct_movable 0
pgscan_kswapd_dma 0
pgscan_kswapd_dma32 0
pgscan_kswapd_normal 0
pgscan_kswapd_movable 0
pgscan_direct_dma 0
pgscan_direct_dma32 0
pgscan_direct_normal 0
pgscan_direct_movable 0
pgscan_direct_throttle 0
zone_reclaim_failed 0
pginodesteal 0
slabs_scanned 0
kswapd_inodesteal 0
kswapd_low_wmark_hit_quickly 0
kswapd_high_wmark_hit_quickly 0
pageoutrun 1
allocstall 0
pgrotated 0
drop_pagecache 0
drop_slab 0
numa_pte_updates 0
numa_huge_pte_updates 0
numa_hint_faults 0
numa_hint_faults_local 0
numa_pages_migrated 0
pgmigrate_success 0
pgmigrate_fail 0
compact_migrate_scanned 0
compact_free_scanned 0
compact_isolated 0
compact_stall 0
compact_fail 0
compact_success 0
htlb_buddy_alloc_success 0
htlb_buddy_alloc_fail 0
unevictable_pgs_culled 0
unevictable_pgs_scanned 0
unevictable_pgs_rescued 0
unevictable_pgs_mlocked 0
unevictable_pgs_munlocked 0
unevictable_pgs_cleared 0
unevictable_pgs_stranded 0
thp_fault_alloc 3964
thp_fault_fallback 0
thp_collapse_alloc 1343
thp_collapse_alloc_failed 0
thp_split 86
thp_zero_page_alloc 0
thp_zero_page_alloc_failed 0
balloon_inflate 0
balloon_deflate 0
balloon_migrate 0
swap_ra 0
swap_ra_hit 0
[root@localhost osmetricsplugin]# cat /proc/
Display all 150 possibilities? (y or n)
1/             14/            281/           369/           393/           550/           642/           95/            driver/        kmsg           partitions     timer_stats
10/            15/            283/           370/           3992/          552/           647/           acpi/          execdomains    kpagecount     sched_debug    tty/
1066/          16/            284/           383/           4/             554/           649/           asound/        fb             kpageflags     schedstat      uptime
1067/          17/            285/           384/           41/            555/           664/           buddyinfo      filesystems    loadavg        scsi/          version
1068/          18/            286/           385/           43/            558/           665/           bus/           fs/            locks          self/          vmallocinfo
11/            19/            289/           386/           44/            561/           7/             cgroups        interrupts     mdstat         slabinfo       vmstat
1202/          2/             30/            387/           45/            5843/          7182/          cmdline        iomem          meminfo        softirqs       zoneinfo
1205/          20/            31/            388/           46/            6/             7285/          consoles       ioports        misc           stat           
1207/          21/            318/           389/           471/           60/            7286/          cpuinfo        irq/           modules        swaps          
1242/          22/            32/            390/           493/           607/           7450/          crypto         kallsyms       mounts         sys/           
13/            23/            33/            391/           500/           629/           7485/          devices        kcore          mtrr           sysrq-trigger  
1305/          24/            359/           392/           546/           631/           8/             diskstats      keys           net/           sysvipc/       
1309/          270/           360/           3928/          548/           634/           9/             dma            key-users      pagetypeinfo   timer_list     
[root@localhost osmetricsplugin]# cat /proc/uptime 
21381.64 21141.82
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         342761472 | Available memory size                  |
| USED_RAM       |         696356864 | Used memory size                       |
| FREE_RAM_PCT   | 32.98579788208008 | Available memory as a percentage       |
| USED_RAM_PCT   | 67.01419830322266 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         342761472 | Available low memory size              |
| MEM_UNIT       |                 1 | Memory unit size (in bytes)            |
| LOAD_1MIN      |      0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |       0.025390625 | 5 minute load average                  |
| LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
| UPTIME         |             21425 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 5 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space available as a percentage   |
| USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
| PROCS          |               137 | Number of current processes            |
| UTIME          |          1.146307 | Total user time                        |
| STIME          |          0.211478 | Total system time                      |
| MAXRSS         |            198192 | Maximum resident set size              |
| MAXRSS_BYTES   |         202948608 | Maximum resident set size (in bytes)   |
| MINFLT         |             23611 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |                 0 | Number of block input operations       |
| OUBLOCK        |             33616 | Number of block output operations      |
| NVCSW          |              8165 | Number of voluntary context switches   |
| NIVCSW         |                54 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
34 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
osmetricsplugin.cc: In function ‘int simple_fill_table(THD*, TABLE_LIST*, Item*)’:
osmetricsplugin.cc:62:93: error: invalid operands of types ‘CHARSET_INFO* {aka charset_info_st*}’ and ‘__u32 {aka unsigned int}’ to binary ‘operator*’
   table->field[2]->store("Available memory as a percentage", 32, system_charset_info * info.mem_unit);
                                                                                             ^
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 
[root@localhost osmetricsplugin]# ./compile 
[root@localhost osmetricsplugin]# ./moveit.sh 
[root@localhost osmetricsplugin]# mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.7.29-32-log Percona Server (GPL), Release 32, Revision 56bce88

Copyright (c) 2009-2020 Percona LLC and/or its affiliates
Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 1109 (42S02): Unknown table 'OS_METRICS' in information_schema
mysql> INSTALL PLUGIN OS_METRICS SONAME 'osmetricsplugin.so';
ERROR 2013 (HY000): Lost connection to MySQL server during query
mysql> SELECT * FROM information_schema.OS_METRICS;
ERROR 2006 (HY000): MySQL server has gone away
No connection. Trying to reconnect...
Connection id:    2
Current database: *** NONE ***

+----------------+--------------------+----------------------------------------+
| NAME           | VALUE              | COMMENT                                |
+----------------+--------------------+----------------------------------------+
| TOTAL_RAM      |         1039118336 | Total usable main memory size          |
| FREE_RAM       |          354357248 | Available memory size                  |
| USED_RAM       |          684761088 | Used memory size                       |
| FREE_RAM_PCT   | 34.101722717285156 | Available memory as a percentage       |
| USED_RAM_PCT   |  65.89827728271484 | Free memory as a percentage            |
| SHARED_RAM     |                  0 | Amount of shared memory                |
| BUFFER_RAM     |            2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                  0 | Total high memory size                 |
| FREE_HIGH_RAM  |                  0 | Available high memory size             |
| TOTAL_LOW_RAM  |         1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |          354357248 | Available low memory size              |
| LOAD_1MIN      |       0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |       0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     |      0.04541015625 | 15 minute load average                 |
| UPTIME         |              21730 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                  0 | Uptime (in days)                       |
| UPTIME_HOURS   |                  6 | Uptime (in hours)                      |
| TOTAL_SWAP     |          859828224 | Total swap space size                  |
| FREE_SWAP      |          859828224 | Swap space available                   |
| USED_SWAP      |                  0 | Swap space used                        |
| FREE_SWAP_PCT  |                100 | Swap space available as a percentage   |
| USED_SWAP_PCT  |                  0 | Swap space used as a percentage        |
| PROCS          |                138 | Number of current processes            |
| UTIME          |            0.11595 | Total user time                        |
| STIME          |           0.184967 | Total system time                      |
| MAXRSS         |             186336 | Maximum resident set size              |
| MAXRSS_BYTES   |          190808064 | Maximum resident set size (in bytes)   |
| MINFLT         |              23396 | Page reclaims (soft page faults)       |
| MAJFLT         |                  0 | Page faults                            |
| INBLOCK        |               7680 | Number of block input operations       |
| OUBLOCK        |              32352 | Number of block output operations      |
| NVCSW          |                 81 | Number of voluntary context switches   |
| NIVCSW         |                 15 | Number of involuntary context switches |
+----------------+--------------------+----------------------------------------+
33 rows in set (0.01 sec)

mysql> SELECT * FROM information_schema.OS_METRICS;
+----------------+-------------------+----------------------------------------+
| NAME           | VALUE             | COMMENT                                |
+----------------+-------------------+----------------------------------------+
| TOTAL_RAM      |        1039118336 | Total usable main memory size          |
| FREE_RAM       |         341049344 | Available memory size                  |
| USED_RAM       |         698068992 | Used memory size                       |
| FREE_RAM_PCT   | 32.82102966308594 | Available memory as a percentage       |
| USED_RAM_PCT   | 67.17897033691406 | Free memory as a percentage            |
| SHARED_RAM     |                 0 | Amount of shared memory                |
| BUFFER_RAM     |           2158592 | Memory used by buffers                 |
| TOTAL_HIGH_RAM |                 0 | Total high memory size                 |
| FREE_HIGH_RAM  |                 0 | Available high memory size             |
| TOTAL_LOW_RAM  |        1039118336 | Total low memory size                  |
| FREE_LOW_RAM   |         341049344 | Available low memory size              |
| LOAD_1MIN      |      0.0029296875 | 1 minute load average                  |
| LOAD_5MIN      |      0.0146484375 | 5 minute load average                  |
| LOAD_15MIN     |     0.04541015625 | 15 minute load average                 |
| UPTIME         |             23410 | Uptime (in seconds)                    |
| UPTIME_DAYS    |                 0 | Uptime (in days)                       |
| UPTIME_HOURS   |                 6 | Uptime (in hours)                      |
| TOTAL_SWAP     |         859828224 | Total swap space size                  |
| FREE_SWAP      |         859828224 | Swap space available                   |
| USED_SWAP      |                 0 | Swap space used                        |
| FREE_SWAP_PCT  |               100 | Swap space available as a percentage   |
| USED_SWAP_PCT  |                 0 | Swap space used as a percentage        |
| PROCS          |               138 | Number of current processes            |
| UTIME          |          1.654309 | Total user time                        |
| STIME          |          0.550062 | Total system time                      |
| MAXRSS         |            199372 | Maximum resident set size              |
| MAXRSS_BYTES   |         204156928 | Maximum resident set size (in bytes)   |
| MINFLT         |             23438 | Page reclaims (soft page faults)       |
| MAJFLT         |                 0 | Page faults                            |
| INBLOCK        |              7680 | Number of block input operations       |
| OUBLOCK        |             33592 | Number of block output operations      |
| NVCSW          |             42043 | Number of voluntary context switches   |
| NIVCSW         |                38 | Number of involuntary context switches |
+----------------+-------------------+----------------------------------------+
33 rows in set (0.00 sec)

mysql> quit
Bye
[root@localhost osmetricsplugin]# nano osmetricsplugin.cc 

  GNU nano 2.3.1                                             File: osmetricsplugin.cc                                                                                                 

#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <ctype.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>
//#include <includes/getmem.h>
//#include <includes/getload.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

static struct st_mysql_information_schema simple_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO simple_table_fields[]=
{
  {"NAME", 15, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"VALUE", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"COMMENT", 50, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

static int simple_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  //double *load;
  struct rusage buf;
  struct sysinfo info;
  TABLE *table= tables->table;

  //load = getLoadAvg();
  sysinfo(&info);
  getrusage(RUSAGE_SELF, &buf);
  
    // Total RAM - works for various OS
  //table->field[0]->store("MEMORY_TOTAL", 12, system_charset_info);
  //table->field[1]->store(getMemorySize());
  //table->field[2]->store("Total RAM", 9, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;

  // Total usable main memory size
  table->field[0]->store("TOTAL_RAM", 9, system_charset_info);
  table->field[1]->store(info.totalram * info.mem_unit);
  table->field[2]->store("Total usable main memory size", 29, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available memory size
  table->field[0]->store("FREE_RAM", 8, system_charset_info);
  table->field[1]->store(info.freeram * info.mem_unit);
  table->field[2]->store("Available memory size", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Used memory size
  table->field[0]->store("USED_RAM", 8, system_charset_info);
  table->field[1]->store((info.totalram - info.freeram) * info.mem_unit);
  table->field[2]->store("Used memory size", 16, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available memory (percentage)
  table->field[0]->store("FREE_RAM_PCT", 12, system_charset_info);
  table->field[1]->store((float) info.freeram / info.totalram * 100 * info.mem_unit);
  table->field[2]->store("Available memory as a percentage", 32, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
    // Used memory (percentage)
  table->field[0]->store("USED_RAM_PCT", 12, system_charset_info);
  table->field[1]->store((float) (info.totalram - info.freeram) / info.totalram * 100 * info.mem_unit);
  table->field[2]->store("Free memory as a percentage", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Amount of shared memory
  table->field[0]->store("SHARED_RAM", 10, system_charset_info);
  table->field[1]->store(info.sharedram * info.mem_unit);
  table->field[2]->store("Amount of shared memory", 23, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Memory used by buffers
  table->field[0]->store("BUFFER_RAM", 10, system_charset_info);
  table->field[1]->store(info.bufferram * info.mem_unit);
  table->field[2]->store("Memory used by buffers", 22, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Total high memory size
  table->field[0]->store("TOTAL_HIGH_RAM", 14, system_charset_info);
  table->field[1]->store(info.totalhigh * info.mem_unit);
  table->field[2]->store("Total high memory size", 22, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available high memory size
  table->field[0]->store("FREE_HIGH_RAM", 13, system_charset_info);
  table->field[1]->store(info.freehigh * info.mem_unit);
  table->field[2]->store("Available high memory size", 26, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
    // Total low memory size
  table->field[0]->store("TOTAL_LOW_RAM", 13, system_charset_info);
  table->field[1]->store((info.totalram - info.totalhigh) * info.mem_unit);
  table->field[2]->store("Total low memory size", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Available low memory size
  table->field[0]->store("FREE_LOW_RAM", 12, system_charset_info);
  table->field[1]->store((info.freeram - info.freehigh) * info.mem_unit);
  table->field[2]->store("Available low memory size", 25, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Load 1 Minute Average - uses getload.h
  //table->field[0]->store("LOADAVG_1MIN", 12, system_charset_info);
  //table->field[1]->store(load[0]);
  //table->field[2]->store("Load average over 1 minute", 26, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;

  // Load 5 Minute Average - uses getload.h
  //table->field[0]->store("LOADAVG_5MIN", 12, system_charset_info);
  //table->field[1]->store(load[1]);
  //table->field[2]->store("Load average over 5 minutes", 28, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
    // Load 15 Minute Average - uses getload.h
  //table->field[0]->store("LOADAVG_15MIN", 13, system_charset_info);
  //table->field[1]->store(load[2]);
  //table->field[2]->store("Load average over 15 minutes", 29, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;

  // 1 minute load average
  table->field[0]->store("LOAD_1MIN", 9, system_charset_info);
  table->field[1]->store((float) info.loads[0] / 65536);
  table->field[2]->store("1 minute load average", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // 5 minute load average
  table->field[0]->store("LOAD_5MIN", 9, system_charset_info);
  table->field[1]->store((float) info.loads[1] / 65536);
  table->field[2]->store("5 minute load average", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // 15 minute load average
  table->field[0]->store("LOAD_15MIN", 10, system_charset_info);
  table->field[1]->store((float) info.loads[2] / 65536);
  table->field[2]->store("15 minute load average", 22, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Seconds since boot
  table->field[0]->store("UPTIME", 6, system_charset_info);
  table->field[1]->store(info.uptime);
  table->field[2]->store("Uptime (in seconds)", 19, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
    // Uptime since boot in days
  table->field[0]->store("UPTIME_DAYS", 11, system_charset_info);
  table->field[1]->store(info.uptime / (60 * 60 * 24));
  table->field[2]->store("Uptime (in days)", 16, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Uptime since boot in hours
  table->field[0]->store("UPTIME_HOURS", 12, system_charset_info);
  table->field[1]->store(info.uptime / (60 * 60));
  table->field[2]->store("Uptime (in hours)", 17, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Total swap space size
  table->field[0]->store("TOTAL_SWAP", 10, system_charset_info);
  table->field[1]->store(info.totalswap);
  table->field[2]->store("Total swap space size", 21, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space still available
  table->field[0]->store("FREE_SWAP", 10, system_charset_info);
  table->field[1]->store(info.freeswap);
  table->field[2]->store("Swap space available", 20, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

    // swap space used
  table->field[0]->store("USED_SWAP", 10, system_charset_info);
  table->field[1]->store(info.totalswap - info.freeswap);
  table->field[2]->store("Swap space used", 15, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space still available (percentage)
  table->field[0]->store("FREE_SWAP_PCT", 14, system_charset_info);
  table->field[1]->store(info.freeswap / info.totalswap * 100);
  table->field[2]->store("Swap space available as a percentage", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // swap space used (percentage)
  table->field[0]->store("USED_SWAP_PCT", 14, system_charset_info);
  table->field[1]->store((info.totalswap - info.freeswap) / info.totalswap * 100);
  table->field[2]->store("Swap space used as a percentage", 31, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // Number of current processes
  table->field[0]->store("PROCS", 5, system_charset_info);
  table->field[1]->store(info.procs);
  table->field[2]->store("Number of current processes", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // user CPU time used in seconds
  //table->field[0]->store("UTIME_TV_SEC", 12, system_charset_info);
  //table->field[1]->store(buf.ru_utime.tv_sec);
  //table->field[2]->store("User CPU time used (in seconds)", 30, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;
  
    // user CPU time used in microseconds
  //table->field[0]->store("UTIME_TV_USEC", 13, system_charset_info);
  //table->field[1]->store(buf.ru_utime.tv_usec);
  //table->field[2]->store("User CPU time used (in microseconds)", 36, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;

  // system CPU time used in seconds
  //table->field[0]->store("STIME_TV_SEC", 12, system_charset_info);
  //table->field[1]->store(buf.ru_stime.tv_sec);
  //table->field[2]->store("System CPU time (in seconds)", 29, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;

  // system CPU time used in microseconds
  //table->field[0]->store("STIME_TV_USEC", 13, system_charset_info);
  //table->field[1]->store(buf.ru_stime.tv_usec);
  //table->field[2]->store("System CPU time (in microseconds)", 33, system_charset_info);
  //if (schema_table_store_record(thd, table)) return 1;

  // total user time
  table->field[0]->store("UTIME", 5, system_charset_info);
  table->field[1]->store(buf.ru_utime.tv_sec + buf.ru_utime.tv_usec / (double) 1000000);
  table->field[2]->store("Total user time", 15, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
    // total system time
  table->field[0]->store("STIME", 5, system_charset_info);
  table->field[1]->store(buf.ru_stime.tv_sec + buf.ru_stime.tv_usec / (double) 1000000);
  table->field[2]->store("Total system time", 17, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // maximum resident set size
  table->field[0]->store("MAXRSS", 6, system_charset_info);
  table->field[1]->store(buf.ru_maxrss);
  table->field[2]->store("Maximum resident set size", 25, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // maximum resident set size in bytes
  table->field[0]->store("MAXRSS_BYTES", 12, system_charset_info);
  table->field[1]->store(buf.ru_maxrss * 1024);
  table->field[2]->store("Maximum resident set size (in bytes)", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  #if defined(BSD)
  // integral shared memory size - not used in Linux
  table->field[0]->store("IXRSS",5, system_charset_info);
  table->field[1]->store(buf.ru_ixrss);
  table->field[2]->store("Integral shared memory size", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
    #if defined(BSD)
  // integral unshared data size - not used in Linux
  table->field[0]->store("IDRSS", 5, system_charset_info);
  table->field[1]->store(buf.ru_idrss);
  table->field[2]->store("Integral unshared data size", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  #if defined(BSD)
  // integral unshared stack size - not used in Linux
  table->field[0]->store("ISRSS", 5, system_charset_info);
  table->field[1]->store(buf.ru_isrss);
  table->field[2]->store("Integral unshared stack size", 28, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  // page reclaims (soft page faults)
  table->field[0]->store("MINFLT", 6, system_charset_info);
  table->field[1]->store(buf.ru_minflt);
  table->field[2]->store("Page reclaims (soft page faults)", 32, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // page faults (hard page faults)
  table->field[0]->store("MAJFLT", 6, system_charset_info);
  table->field[1]->store(buf.ru_majflt);
  table->field[2]->store("Page faults", 11, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  
    #if defined(BSD)
  // swaps - not used in Linux
  table->field[0]->store("NSWAP", 5, system_charset_info);
  table->field[1]->store(buf.ru_nswap);
  table->field[2]->store("Number of swaps", 15, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  // block input operations
  table->field[0]->store("INBLOCK", 7, system_charset_info);
  table->field[1]->store(buf.ru_inblock);
  table->field[2]->store("Number of block input operations", 32, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // block output operations
  table->field[0]->store("OUBLOCK", 7, system_charset_info);
  table->field[1]->store(buf.ru_oublock);
  table->field[2]->store("Number of block output operations", 33, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  #if defined(BSD)
  // IPC messages sent - not used in Linux
  table->field[0]->store("MSGSND", 6, system_charset_info);
  table->field[1]->store(buf.ru_msgsnd);
  table->field[2]->store("Number of IPC messages sent", 27, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif
  
  #if defined(BSD)
  // IPC messages received - not used in Linux
  table->field[0]->store("MSGRCV", 6, system_charset_info);
  table->field[1]->store(buf.ru_msgrcv);
  table->field[2]->store("Number of IPC messages received", 31, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  #if defined(BSD)
  // signals received - not used in Linux
  table->field[0]->store("NSIGNALS", 8, system_charset_info);
  table->field[1]->store(buf.ru_nsignals);
  table->field[2]->store("Number of signals received", 26, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;
  #endif

  // voluntary context switches
  table->field[0]->store("NVCSW", 5, system_charset_info);
  table->field[1]->store(buf.ru_nvcsw);
  table->field[2]->store("Number of voluntary context switches", 36, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  // involuntary context switches
  table->field[0]->store("NIVCSW", 6, system_charset_info);
  table->field[1]->store(buf.ru_nivcsw);
  table->field[2]->store("Number of involuntary context switches", 38, system_charset_info);
  if (schema_table_store_record(thd, table)) return 1;

  return 0;
}

static int simple_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;

  schema_table->fields_info= simple_table_fields;
  schema_table->fill_table= simple_fill_table;
  return 0;
}

mysql_declare_plugin(os_metrics)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &simple_table_info,                /* type-specific descriptor */
  "OS_METRICS",                      /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics INFORMATION_SCHEMA table", /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  simple_table_init,                 /* init function */
  NULL,
  0x0100,                            /* version = 1.0 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;                                               
