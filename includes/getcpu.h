#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

struct procstat{
  char id;
  int user;
  int nice;
  int sys;
  int idle;
  int iowait;
  int irq;
  int softirq;
  int guest;
  int guest_nice;
};

//char id[16], dummy[16];

procstat getprocstat(void) {
  char *line = NULL;
  FILE* fp = fopen("/proc/stat", "r");
  size_t len = 0;
  struct procstat ps;

  getline(&line, &len, fp);
  sscanf( line, "%s %d %d %d %d %d %d %d %d %d", &ps.id, &ps.user, &ps.nice, &ps.sys, &ps.idle, &ps.iowait, &ps.irq, &ps.softirq, &ps.guest, &ps.guest_nice);
  free(line);
  fclose(fp);
  return ps;
}
