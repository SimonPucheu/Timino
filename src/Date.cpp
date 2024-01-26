#include <Arduino.h>

#include "Date.h"

Date::Date(long timestamp, long time)
{
	start.timestamp = timestamp;
	start.time = time;
	difference = start.time - start.timestamp;
}

Date::Date(long timestamp, String time)
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

Date::Date(long timestamp, long hours, long minutes = 0, long seconds = 0, long milliseconds = 0, float iCoeff = 1.0)
{
	start.timestamp = timestamp;
	minutes += hours * 60;
	seconds += minutes * 60;
	milliseconds += seconds * 1000;
	start.time = milliseconds;
	difference = start.time - start.timestamp;
	coeff = iCoeff;
}

long Date::getTimestamp(long timestamp)
{
	return timestamp + difference;
}

void Date::setTimestamp(long timestamp)
{
	date.milliseconds = getTimestamp(timestamp * coeff);
	date.seconds = date.milliseconds / 1000;
	date.milliseconds %= 1000;
	date.minutes = date.seconds / 60;
	date.seconds %= 60;
	date.hours = date.minutes / 60;
	date.minutes %= 60;
	date.days = date.hours / 24;
	date.hours %= 24;
	date.years = date.days / 365;
	date.days %= 365;
}

int Date::getYears()
{
	return date.years;
}

int Date::getDays()
{
	return date.days;
}

int Date::getHours()
{
	return date.hours;
}

int Date::getMinutes()
{
	return date.minutes;
}

int Date::getSeconds()
{
	return date.seconds;
}

int Date::getMilliseconds()
{
	return date.milliseconds;
}

/**
 * @return The string between the separator specified by the index and the next separator
 * */
String Date::splitString(String data, char separator, int index)
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