/**
* A small library to calculate an uptime string
* in the form "xxxxxD yy:zz" 
* xxxxx => Days, up to 99999
* yy    => Hours
* zz    => Minutes
* The format is fixed!
*/

#ifndef UPTIME_H
#define UPTIME_H

#define RESSTRLEN   14
#define OVERFLOWSEC   4294967
#include "Arduino.h"

class Uptime
{
  public:
    /**
     * Constructor
     *
     */
    Uptime();

    /**
     * Update the calculation
     * shall be called in loop of main program
     * 
     */
    void update();

    /**
     * Fill the result string and give the handle back
     *
     */
    char* uptimestr();
    
  private:
    
    char* resultstr;
    unsigned long my_millis;
    unsigned long last_millis;
    unsigned long up_sec;
    unsigned long sec_add;
  
};

#endif 

