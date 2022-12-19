#include <Arduino.h>

class Time
{
    public:
        Time(long timestamp, long time);
        Time(long timestamp, String time);
        Time(long timestamp, long hours, long minutes = 0, long seconds = 0, long milliseconds = 0);
        long getTimestamp(long timestamp);
        void setTimestamp(long timestamp);
        int getHours();
        int getMinutes();
        int getSeconds();
        int getMilliseconds();
        long difference;
        long time[4] = { 0, 0, 0, 0 };
        struct
        {
            long timestamp;
            long time;
        } start;
};

String splitString(String data, char separator, long index);