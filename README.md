# uptime
An Uptime Library for Arduino and ESP

Very tiny library to get a fixed timestring with the uptime of a device.

The usage is very simple:

A simple example:
~~~c
#include <Uptime.h>

Uptime uptime;

void setup() {
  Serial.begin(9600);
  // no setup needed for uptime library
}

void loop() {
  delay(1000);
  uptime.update();
  Serial.println( uptime.uptimestr() );
}
~~~