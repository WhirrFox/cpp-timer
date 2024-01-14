#ifndef TIMER_TIME_H
#define TIMER_TIME_H

#include <sstream>

class Time {
protected:
    int hour{};
    int minute{};
    int second{};

    void parse1(std::string);

    void parseValues1(int count, std::string token);

    void parse2(std::string);

    void parseValues2(std::string s);
public:
    Time() = default;
    Time(int hour, int minute, int second);
    Time(Time &t);

    explicit Time(int seconds);
    virtual ~Time() = default;

    virtual std::string str();

    void parseString(std::string);

    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
};


#endif //TIMER_TIME_H
