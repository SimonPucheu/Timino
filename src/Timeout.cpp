#include <Arduino.h>

#include "Timeout.h"

Timeout::Timeout(void (*iCallback)(), unsigned long iTimeout, bool start = true)
{
    timeout = iTimeout;
    targetTime = millis() + timeout;
    callback = iCallback;
    running = start;
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

void Timeout::start()
{
    running = true;
    targetTime = millis() + timeout;
}