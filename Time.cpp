#include "Time.h"
#include <cstring>
#include <iostream>

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

// 12:34:56
bool Time::parseString(std::string s) {
    const char* delimiter = ":";
    char* token = std::strtok(const_cast<char *>(s.c_str()), delimiter);

    int count = 0;
    while (token) {
        count++;
        if (count > 3)
            return false;

        try {
            saveValues(count, token);
        }
        catch(...) {
            return false;
        }

        token = std::strtok(nullptr, delimiter);
    }

    if (count == 3)
        return true;
    return false;
}

void Time::saveValues(int count, std::string token) {
    switch (count) {
        case 1:
            hour = std::stoi(token);
            break;
        case 2:
            minute = std::stoi(token);
            break;
        case 3:
            second = std::stoi(token);
            break;
    }
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
