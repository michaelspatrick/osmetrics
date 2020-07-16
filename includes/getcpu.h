#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>
#include <errno.h>

struct procstat{
  int user;
  int nice;
  int sys;
  int idle;
  int iowait;
  int irq;
  int softirq;
  int intr;
  int ctxt;
  int btime;
  int processes;
  int procs_running;
  int procs_blocked;
  int total_softirq;
  int numcores;
  float cpu_speed;
  float cpu_bogomips;
};

procstat getprocstat(void) {
  char line[256];
  FILE* fp = fopen("/proc/stat", "r");
  struct procstat ps;
  char id[16], dummy[16];

  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, "cpu ")) {
      sscanf( line, "%s %s %d %d %d %d %d %d %d", dummy, id, &ps.user, &ps.nice, &ps.sys, &ps.idle, &ps.iowait, &ps.irq, &ps.softirq);
    } else if (strstr(line, "intr")) {
      sscanf( line, "%s %d", dummy, &ps.intr);
    } else if (strstr(line, "ctxt")) {
      sscanf( line, "%s %d", dummy, &ps.ctxt);
    } else if (strstr(line, "btime")) {
      sscanf( line, "%s %d", dummy, &ps.btime);
    } else if (strstr(line, "processes")) {
      sscanf( line, "%s %d", dummy, &ps.processes);
    } else if (strstr(line, "procs_running")) {
      sscanf( line, "%s %d", dummy, &ps.procs_running);
    } else if (strstr(line, "procs_blocked")) {
      sscanf( line, "%s %d", dummy, &ps.procs_blocked);
    } else if (strstr(line, "softirq")) {
      sscanf( line, "%s %d", dummy, &ps.total_softirq);
    }
  }

  fclose(fp);
  
    // Read /proc/cpuinfo
  fp = fopen("/proc/cpuinfo", "r");
  assert(fp != NULL);
  char *token;
  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, "cpu cores")) {
      token = strtok(line, ":");
      token = strtok(NULL, ": ");
      ps.numcores = atoi(token);
    } else if (strstr(line, "cpu MHz")) {
      token = strtok(line, ":");
      token = strtok(NULL, ": ");
      ps.cpu_speed = atof(token);
    } else if (strstr(line, "bogomips")) {
      token = strtok(line, ":");
      token = strtok(NULL, ": ");
      ps.cpu_bogomips = atof(token);
    }
  }
  fclose(fp);

  return ps;
}
