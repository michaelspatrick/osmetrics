#include <sql_class.h>
#include <table.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <mysql_version.h>
#include <mysql/plugin.h>
#include <my_global.h>

static struct st_mysql_information_schema osmetrics_stat_table_info = { MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

static ST_FIELD_INFO osmetrics_stat_table_fields[]=
{
  {"pid", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"comm", 50, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"state", 1, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"ppid", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"pgrp", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"session", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"tty_nr", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"tpgid", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"flags", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"minflt", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"cminflt", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"majflt", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"cmajflt", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"utime", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"stime", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"cutime", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"cstime", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"priority", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"nice", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"num_threads", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"itrealvalue", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"starttime", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"vsize", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rss", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rsslim", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"startcode", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"endcode", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"startstack", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"kstkeep", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"kstkeip", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"signal", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"blocked", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"sigignore", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"sigcatch", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"wchan", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"nswap", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"cnswap", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"exit_signal", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"processor", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"rt_priority", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"policy", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"delayacct_blkio_ticks", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"guest_time", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"cguest_time", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"start_data", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"end_data", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"start_brk", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"arg_start", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"arg_end", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"env_start", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"env_end", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {"exit_code", 6, MYSQL_TYPE_FLOAT, 0, MY_I_S_UNSIGNED, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

char* strip_newlines(char* szX) {
    int i = strlen(szX);
    while('\n'==szX[--i]) szX[i] = 0;
    return szX;
}

static int osmetrics_stat_fill_table(THD *thd, TABLE_LIST *tables, Item *cond)
{
  TABLE *table= tables->table;
  char line[512];
  FILE* fp = fopen("/proc/self/stat", "r");
  int                     pid;                      /** The process id. **/
  char                    comm [_POSIX_PATH_MAX];   /** The filename of the executable **/
  char                    state[1]; /** 1 **/       /** R is running, S is sleeping, D is sleeping in an uninterruptible wait, Z is zombie, T is traced or stopped **/
  int                     ppid;                     /** The pid of the parent. **/
  int                     pgrp;                     /** The pgrp of the process. **/
  int                     session;                  /** The session id of the process. **/
  int                     tty_nr;                   /** The tty the process uses **/
  int                     tpgid;                    /** (too long) **/
  unsigned int            flags;                    /** The flags of the process. **/
  long unsigned int       minflt;                   /** The number of minor faults **/
  long unsigned int       cminflt;                  /** The number of minor faults with childs **/
  long unsigned int       majflt;                   /** The number of major faults **/
  long unsigned int       cmajflt;                  /** The number of major faults with childs **/
  long unsigned int       utime;                    /** user mode jiffies **/
  long unsigned int       stime;                    /** kernel mode jiffies **/
  long int                cutime;                   /** user mode jiffies with childs **/
  long int                cstime;                   /** kernel mode jiffies with childs **/
  long int                priority;                 /** the standard nice value, plus fifteen **/
  long int                nice;
  long int                num_threads;
  long int                itrealvalue;              /** The time before the next SIGALRM is sent to the process **/
  long long unsigned int  starttime;                /** Time the process started after system boot **/
  long unsigned int       vsize;                    /** Virtual memory size **/
  long int                rss;                      /** Resident Set Size **/
  long unsigned int       rsslim;                   /** Current limit in bytes on the rss **/
  long unsigned int       startcode;                /** The address above which program text can run **/
  long unsigned int       endcode;                  /** The address below which program text can run **/
  long unsigned int       startstack;               /** The address of the start of the stack **/
  long unsigned int       kstkesp;                  /** The current value of ESP **/
  long unsigned int       kstkeip;                  /** The current value of EIP **/
  long unsigned int       signal;                   /** The bitmap of pending signals **/
  long unsigned int       blocked;                  /** The bitmap of blocked signals **/
  long unsigned int       sigignore;                /** The bitmap of ignored signals **/
  long unsigned int       sigcatch;                 /** The bitmap of catched signals **/
  long unsigned int       wchan;                    /** (too long) **/
  long unsigned int       nswap;
  long unsigned int       cnswap;
  int                     exit_signal;
  int                     processor;
  unsigned int            rt_priority;
  unsigned int            policy;
  long long unsigned int  delayacct_blkio_ticks;
  long unsigned int       guest_time;
  long int                cguest_time;
  long unsigned int       start_data;
  long unsigned int       end_data;
  long unsigned int       start_brk;
  long unsigned int       arg_start;
  long unsigned int       arg_end;
  long unsigned int       env_start;
  long unsigned int       env_end;
  int                     exit_code;

  assert(fp != NULL);
  while (fgets(line, sizeof(line), fp)) {
    sscanf(line, "%d %s %s %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %u %u %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %d",
          &pid, (char*)&comm, (char*)&state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt,
          &cminflt, &majflt, &cmajflt, &utime, &stime, &cutime, &cstime, &priority, &nice, &num_threads,
          &itrealvalue, &starttime, &vsize, &rss, &rsslim, &startcode, &endcode, &startstack, &kstkesp,
          &kstkeip, &signal, &blocked, &sigignore, &sigcatch, &wchan, &nswap, &cnswap, &exit_signal, &processor,
          &rt_priority, &policy, &delayacct_blkio_ticks, &guest_time, &cguest_time, &start_data, &end_data, &start_brk,
          &arg_start, &arg_end, &env_start, &env_end, &exit_code);

    table->field[0]->store(pid);
    table->field[1]->store(comm, strlen(comm), system_charset_info);
    table->field[2]->store(state, strlen(state), system_charset_info);
    table->field[3]->store(ppid);
    table->field[4]->store(pgrp);
    table->field[5]->store(session);
    table->field[6]->store(tty_nr);
    table->field[7]->store(tpgid);
    table->field[8]->store(flags);
    table->field[9]->store(minflt);
    table->field[10]->store(cminflt);
    table->field[11]->store(majflt);
    table->field[12]->store(cmajflt);
    table->field[13]->store(utime);
    table->field[14]->store(stime);
    table->field[15]->store(cutime);
    table->field[16]->store(cstime);
    table->field[17]->store(priority);
    table->field[18]->store(nice);
    table->field[19]->store(num_threads);
    table->field[20]->store(itrealvalue);
    table->field[21]->store(starttime);
    table->field[22]->store(vsize);
    table->field[23]->store(rss);
    table->field[24]->store(rsslim);
    table->field[25]->store(startcode);
    table->field[26]->store(endcode);
    table->field[27]->store(startstack);
    table->field[28]->store(kstkesp);
    table->field[29]->store(kstkeip);
    table->field[30]->store(signal);
    table->field[31]->store(blocked);
    table->field[32]->store(sigignore);
    table->field[33]->store(sigcatch);
    table->field[34]->store(wchan);
    table->field[35]->store(nswap);
    table->field[36]->store(cnswap);
    table->field[37]->store(exit_signal);
    table->field[38]->store(processor);
    table->field[39]->store(rt_priority);
    table->field[40]->store(policy);
    table->field[41]->store(delayacct_blkio_ticks);
    table->field[42]->store(guest_time);
    table->field[43]->store(cguest_time);
    table->field[44]->store(start_data);
    table->field[45]->store(end_data);
    table->field[46]->store(start_brk);
    table->field[47]->store(arg_start);
    table->field[48]->store(arg_end);
    table->field[49]->store(env_start);
    table->field[50]->store(env_end);
    table->field[51]->store(exit_code);
    if (schema_table_store_record(thd, table)) return 1;
  }
  fclose(fp);

  return 0;
}

static int osmetrics_stat_table_init(void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*)ptr;
  schema_table->fields_info= osmetrics_stat_table_fields;
  schema_table->fill_table= osmetrics_stat_fill_table;
  return 0;
}

mysql_declare_plugin(osmetrics_stat)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &osmetrics_stat_table_info,   /* type-specific descriptor */
  "OS_STAT",                    /* table name */
  "Michael Patrick",                 /* author */
  "OS Metrics: Self Stat",     /* description */
  PLUGIN_LICENSE_GPL,                /* license type */
  osmetrics_stat_table_init,    /* init function */
  NULL,
  0x0001,                            /* version = 0.1 */
  NULL,                              /* no status variables */
  NULL,                              /* no system variables */
  NULL,                              /* no reserved information */
  0                                  /* no flags */
}
mysql_declare_plugin_end;
