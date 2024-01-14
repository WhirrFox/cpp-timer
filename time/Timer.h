
#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H

#include "Time.h"

class Timer : public Time {
private:
    std::string name;

    void printHeadline(bool isBreak);
public:
    Timer() = default;

    Timer(int hour, int minute, int second) : Time(hour, minute, second) {};

    explicit Timer(int seconds) : Time(seconds) {};
    bool isDone();

    // returns false if timer is done
    bool tick();

    void run(bool isBreak = false);

    Timer getBreakTimer();

    const std::string &getName() const;

    void setName(const std::string &name);

    int getDurationInSeconds();

    std::string format();

    Timer operator+(Timer t);
};

Timer createTimer();

#endif //TIMER_TIMER_H
