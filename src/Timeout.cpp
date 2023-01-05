#include <Arduino.h>

#include "VirtualDate.h"

Timeout::Timeout(void (*iCallback)(), unsigned long delay)
{
    targetTime = millis() + delay;
    callback = iCallback;
}

void Timeout::loop()
{
    if (millis() >= targetTime && running)
    {
        callback();
        running = false;
    }
}

void Timeout::cancel()
{
    running = false;
}