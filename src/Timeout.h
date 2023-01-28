class Timeout
{
    public:
        Timeout(void (*iCallback)(), unsigned long delay);
        void loop();
        void cancel();
    private:
        int running = true;
        void (*callback)();
        unsigned long targetTime;
};

// bool timeoutRunning = true;