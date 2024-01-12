#include "Time.h"

Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

Time::Time(Time &t) {
    hour = t.hour;
    minute = t.minute;
    second = t.second;
}

std::string Time::formatTime() {
    std::ostringstream s;
    if (hour < 10)
        s << "0";
    s << hour << ":";

    if (minute < 10)
        s << "0";
    s << minute << ":";

    if (second < 10)
        s << "0";
    s << second;

    return s.str();
}

bool Time::parseString(std::string s) {
    hour = 0;
    minute = 0;
    second = 10;
    return true;
}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int hour) {
    Time::hour = hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int minute) {
    Time::minute = minute;
}

int Time::getSecond() const {
    return second;
}

void Time::setSecond(int second) {
    Time::second = second;
}
