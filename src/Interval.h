#include <Arduino.h>

class Interval
{
    public:
        Interval(void (*iCallback)(), unsigned long iInterval);
        void loop();
        void cancel();
    private:
        int running = true;
        void (*callback)();
        unsigned long startTime;
        unsigned long interval;
        unsigned long previous = 0;
};