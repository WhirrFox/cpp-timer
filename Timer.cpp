#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include "DateTime.h"

Timer::Timer(int hour, int minute, int second) : Time (hour, minute, second){}

bool Timer::isDone() {
    return hour == 0 && minute == 0 && second == 0;
}

bool Timer::tick() {
    if (isDone())
        return false;

    second--;
    if (second == -1) {
        second = 59;
        minute--;
    }
    if (minute == -1) {
        minute = 59;
        hour--;
    }
    if (hour == -1) {
        hour = 0;
        minute = 0;
        second = 0;
    }
    return true;
}

void Timer::run() {
    while (!isDone()) {
        std::cout << "\r" << formatTime() << std::flush;
        tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

Timer createTimer() {
    std::cout << "enter time: " << std::flush;
    std::string time;
    std::cin >> time;
    Timer t;
    if (t.parseString(time)) {
        DateTime a(t);
        return t;
    }

    return createTimer();
}