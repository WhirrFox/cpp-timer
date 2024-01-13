#ifndef TIMER_TIME_H
#define TIMER_TIME_H

#include <sstream>

class Time {
protected:
    int hour{};
    int minute{};
    int second{};

    void saveValues(int count, std::string token);
public:
    Time() = default;
    Time(int hour, int minute, int second);
    Time(Time &t);
    virtual ~Time() = default;

    virtual std::string str();
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
