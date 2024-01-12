
#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H

#include "Time.h"

class Timer : public Time {
public:
    Timer() = default;
    Timer(int hour, int minute, int second);
    bool isDone();
    // returns false if timer is done
    bool tick();
    void run();
};

Timer createTimer();

#endif //TIMER_TIMER_H
