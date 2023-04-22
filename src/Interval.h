#include <Arduino.h>

class Interval
{
    public:
        Interval(void (*iCallback)(), unsigned long iInterval, bool start = true);
        void loop();
        void cancel();
        void start();
    private:
        int running = true;
        void (*callback)();
        unsigned long startTime;
        unsigned long interval;
        int counter = 0;
};