#include <Arduino.h>

#include "TimeLib.h"

Time::Time(long timestamp, long time)
{
  start.timestamp = timestamp;
  start.time = time;
  difference = start.time - start.timestamp;
}

Time::Time(long timestamp, String time)
{
  start.timestamp = timestamp;
  long hours = splitString(time, ':', 0).toInt();
  long minutes = splitString(time, ':', 1).toInt();
  long seconds = splitString(time, ':', 2).toInt();
  long milliseconds = splitString(time, ':', 3).toInt();
  minutes += hours * 60;
  seconds += minutes * 60;
  milliseconds += seconds * 1000;
  start.time = milliseconds;
  difference = start.time - start.timestamp;
}

Time::Time(long timestamp, long hours, long minutes = 0, long seconds = 0, long milliseconds = 0)
{
  start.timestamp = timestamp;
  minutes += hours * 60;
  seconds += minutes * 60;
  milliseconds += seconds * 1000;
  start.time = milliseconds;
  difference = start.time - start.timestamp;
}

long Time::getTimestamp(long timestamp)
{
  return timestamp + difference;
}

void Time::setTimestamp(long timestamp)
{
  time[3] = getTimestamp(timestamp);
  time[2] = time[3] / 1000;
  time[3] %= 1000;
  time[1] = time[2] / 60;
  time[2] %= 60;
  time[0] = time[1] / 60;
  time[1] %= 60;
}

int Time::getHours()
{
  return time[0];
}

int Time::getMinutes()
{
  return time[1];
}

int Time::getSeconds()
{
  return time[2];
}

int Time::getMilliseconds()
{
  return time[3];
}

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