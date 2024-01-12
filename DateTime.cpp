#include "DateTime.h"
#include <chrono>
#include <ctime>
#include <iostream>

void DateTime::init() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
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

DateTime::DateTime(Timer &t) : Time() {
    init();
    timer = t;
}