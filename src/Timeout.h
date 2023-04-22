#include <Arduino.h>

class Timeout
{
    public:
        Timeout(void (*iCallback)(), unsigned long iTimeout, bool start = true);
        void loop();
        void cancel();
        void start();
    private:
        int running = true;
        void (*callback)();
        unsigned long targetTime;
        unsigned long timeout;
};

// bool timeoutRunning = true;