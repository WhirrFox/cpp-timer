
#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H

#include "Time.h"

class Timer : public Time {
private:
    std::string name;
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
};

Timer createTimer();

#endif //TIMER_TIMER_H
