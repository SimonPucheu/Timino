#include <Arduino.h>

class Date
{
    public:
        Date(long timestamp, long time);
        Date(long timestamp, String time);
        Date(long timestamp, long hours, long minutes, long seconds = 0, long milliseconds = 0, float iCoeff = 1.0);
        long getTimestamp(long timestamp);
        void setTimestamp(long timestamp);
        int getYears();
        int getDays();
        int getHours();
        int getMinutes();
        int getSeconds();
        int getMilliseconds();
    private:
        String splitString(String data, char separator, int index);
        long difference;
        float coeff = 1.0;
        struct
        {
            long years = 0;
            long days = 0;
            long hours = 0;
            long minutes = 0;
            long seconds = 0;
            long milliseconds = 0;
        } date;
        struct
        {
            long timestamp;
            long time;
        } start;
};