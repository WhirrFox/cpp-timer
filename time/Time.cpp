#include "Time.h"
#include <cstring>
#include "../Util.h"

using namespace std;

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

string Time::str() {
    return formatInt(hour, 2) + ":" + formatInt(minute, 2) + ":" + formatInt(second, 2);
}

// 12:34:56 or 12h 34m 56(s)
void Time::parseString(string s) {
    if (s.find(':') != string::npos) {
        parse1(s);
        return;
    }
    parse2(s);
}

void Time::parse1(string s) {
    const char* delimiter = ":";
    char *token = strtok(const_cast<char *>(s.c_str()), delimiter);

    int count = 0;
    while (token) {
        count++;
        if (count > 3)
            throw "Wrong format.";

        parseValues1(count, token);

        token = strtok(nullptr, delimiter);
    }

    if (count == 3)
        throw "Wrong format.";
}

void Time::parseValues1(int count, string token) {
    switch (count) {
        case 1:
            hour = stoi(token);
            break;
        case 2:
            minute = stoi(token);
            break;
        case 3:
            second = stoi(token);
            break;
    }
}

void Time::parse2(string s) {
    const char *delimiter = " ";
    char *token = strtok(const_cast<char *>(s.c_str()), delimiter);

    while (token) {
        string str(token);
        parseValues2(str);

        token = strtok(nullptr, delimiter);
    }
}

void Time::parseValues2(std::string s) {
    if (s.length() == 0)
        return;
    if (s.length() == 1) {
        second += stoi(s);
        return;
    }

    int i = stoi(s.substr(0, s.length() - 1));
    switch (s[s.length() - 1]) {
        case 'h':
            hour += i;
            break;
        case 'm':
            minute += i;
            break;
        default:
            second += stoi(s);
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

