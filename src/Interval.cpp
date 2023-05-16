#include <Arduino.h>

#include "Interval.h"

Interval::Interval(void (*iCallback)(), unsigned long iInterval, bool start = true)
{
    startTime = millis();
    callback = iCallback;
    interval = iInterval;
    running = start;
}

void Interval::loop()
{
    unsigned long time = millis();
    if ((time - startTime) >= (counter * interval) && running)
    {
        callback();
        counter++;
    }
}

void Interval::cancel()
{
    running = false;
}

void Interval::start()
{
    running = true;
    startTime = millis();
    counter = 0;
}