#ifndef TIMER_TIME_H
#define TIMER_TIME_H

#include <sstream>

class Time {
protected:
    int hour;
    int minute;
    int second;
public:
    Time() = default;
    Time(int hour, int minute, int second);
    Time(Time &t);
    virtual ~Time() = default;
    std::string formatTime();
    // returns true if time was parsed correct
    bool parseString(std::string);

    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
};


#endif //TIMER_TIME_H
