#include <Arduino.h>

class Date
{
    public:
        Date(long timestamp, long time);
        Date(long timestamp, String time);
        Date(long timestamp, long hours, long minutes, long seconds = 0, long milliseconds = 0);
        long getTimestamp(long timestamp);
        void setTimestamp(long timestamp);
        int getYears();
        int getDays();
        int getHours();
        int getMinutes();
        int getSeconds();
        int getMilliseconds();
    private:
        long difference;
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

class Timeout
{
    public:
        Timeout(void (*iCallback)(), unsigned long iTargetTime);
        void loop();
        void cancel();
    private:
        int running = true;
        void (*callback)();
        unsigned long targetTime;
};

/**
 * @return The string between the separator specified by the index and the next separator
 * */
String splitString(String data, char separator, int index)
{
  int lastSep = 0;
  int currIndex = 0;
  for (int i = 0; i <= data.length(); i++)
  {
    if (data[i] == separator || i == data.length())
    {
      if (currIndex == index)
        return data.substring(lastSep, i);
      lastSep = i + 1;
      currIndex++;
    }
  }
}