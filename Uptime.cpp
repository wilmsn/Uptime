#include "Uptime.h"

Uptime::Uptime() {
  resultstr = (char*)malloc(RESSTRLEN);
  last_millis = 0;
  sec_add = 0;
  up_sec = 0;
}

void Uptime::update() {
  my_millis = millis();
  if ( my_millis < last_millis ) {
    sec_add += OVERFLOWSEC;
  }
  // statt durch 1000 wird hier durch 1024 geteilt !!!
  up_sec = sec_add + (my_millis>>10);
}

char* Uptime::uptimestr() {
  unsigned long up_min = (up_sec / 60) % 60;
  unsigned long up_hour = (up_sec / 60 / 60) % 24;
  unsigned long up_days = (up_sec / 60 / 60 / 24);
  snprintf(resultstr,RESSTRLEN,"%luD %02lu:%02lu", up_days, up_hour, up_min); 
  return resultstr;
}
