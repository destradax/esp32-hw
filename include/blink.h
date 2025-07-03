#ifndef BLINK_H
#define BLINK_H

void turnOn();

void turnOff();

void turnOnForMillis(unsigned long millis);

void blinkFor(unsigned int blinkDuration, unsigned int stopDuration);

void blinkSlow();

void blink();

void blinkFast();

void blinkSlowTimes(unsigned int times);

void blinkTimes(unsigned int times);

void blinkFastTimes(unsigned int times);

#endif