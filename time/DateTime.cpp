#include "DateTime.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include "../Util.h"

using namespace std;

void DateTime::init() {
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    tm *l = localtime(&time);

    year = l->tm_year + 1900;
    month = l->tm_mon + 1;
    date = l->tm_mday;

    hour = l->tm_hour;
    minute = l->tm_min;
    second = l->tm_sec;
}

int DateTime::getDate() const {
    return date;
}

void DateTime::setDate(int date) {
    DateTime::date = date;
}

int DateTime::getMonth() const {
    return month;
}

void DateTime::setMonth(int month) {
    DateTime::month = month;
}

int DateTime::getYear() const {
    return year;
}

void DateTime::setYear(int year) {
    DateTime::year = year;
}

DateTime::DateTime(int year, int month, int date, int hour, int minute, int second) : Time(hour, minute, second) {
    this->year = year;
    this->month = month;
    this->date = date;
}

DateTime::DateTime() {
    init();
}

DateTime::DateTime(Timer &t) : Time() {
    init();
    timer = t;
}

DateTime::DateTime(std::string s) : Time() {
    year = stoi(s.substr(0, 4));
    month = stoi(s.substr(5, 2));
    date = stoi(s.substr(8, 2));
    hour = stoi(s.substr(11, 2));
    minute = stoi(s.substr(14, 2));
    second = stoi(s.substr(17, 2));

    timer.setHour(stoi(s.substr(20, 2)));
    timer.setMinute(stoi(s.substr(23, 2)));
    timer.setSecond(stoi(s.substr(26, 2)));

    if (s.length() >= 30)
        timer.setName(s.substr(29, s.length() - 29));
}

string DateTime::str() {
    return formatInt(year, 2) + "-" + formatInt(month, 2) + "-" + formatInt(date, 2) +
                                                                  "T" + Time::str() + "," + timer.str() + "," +
                                                                  timer.getName();
}

string DateTime::format() {
    ostringstream o;
    o << formatInt(date, 2) << '.' << formatInt(month, 2) << '.' << year << ' '
      << formatInt(hour, 2) << ':' << formatInt(minute, 2) << ':' << formatInt(second, 2)
                                                                  << "\t" << timer.format() << '\t' << timer.getName();
    return o.str();
}

bool DateTime::isSameDate(DateTime &d) {
    return year == d.year && month == d.month && date == d.date;
}

Timer DateTime::getTimer() {
    return timer;
}
