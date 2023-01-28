#include <Arduino.h>

#include "Timeout.h"

Timeout::Timeout(void (*iCallback)(), unsigned long delay)
{
    targetTime = millis() + delay;
    callback = iCallback;
}

void Timeout::loop()
{
    // running = timeoutRunning;
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