#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include "DateTime.h"
#include "../Util.h"
#include "../History.h"

using namespace std;

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
    DateTime dt(*this);
    while (!isDone()) {
        cout << "\r" << str() << flush;
        tick();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    playSound();
    saveEntry(dt);
}

Timer createTimer() {
    cout << "enter time: ";
    string time;
    while (!time.length())
        getline(cin, time);

    Timer t;
    try {
        t.parseString(time);
        if (t.getSecond() + t.getMinute() + t.getHour() == 0)
            return createTimer();

        return t;
    } catch (...) {
        return createTimer();
    }
}
