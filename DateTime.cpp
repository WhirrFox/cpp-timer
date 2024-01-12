#include "DateTime.h"
#include <chrono>
#include <ctime>
#include <iostream>

void DateTime::init() {
    if (false) {
        auto now = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(now);

        year = localtime(&time)->tm_year;
        month = localtime(&time)->tm_mon + 1;
        date = localtime(&time)->tm_mday;
    }
    time_t now;
    time(&now);
    char buf[sizeof "2024-01-11T21:24:00"];
    strftime(buf, sizeof buf, "%FT%T", gmtime(&now));
    std::cout << buf << std::endl;
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