#ifndef TIMER_DATETIME_H
#define TIMER_DATETIME_H

#include "Timer.h"

class DateTime : public Time {
private:
    int date;
    int month;
    int year;

    Timer timer;

    void init();
public:
    DateTime();
    DateTime(int year, int month, int date, int hour, int minute, int second);
    DateTime(Timer &t);

    DateTime(std::string s);

    std::string str();

    std::string format();

    void printResult();

    bool isSameDate(DateTime &d);

    int getDate() const;
    void setDate(int date);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);

    Timer getTimer();
};


#endif //TIMER_DATETIME_H
