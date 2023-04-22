#include <Arduino.h>

#include "Interval.h"

Interval::Interval(void (*iCallback)(), unsigned long iInterval)
{
    startTime = millis();
    callback = iCallback;
    interval = iInterval;
}

void Interval::loop()
{
    unsigned long time = millis();
    if (previous != time && (time - startTime) % interval == 0 && running)
    {
        callback();
        previous = time;
    }
}

void Interval::cancel()
{
    running = false;
}