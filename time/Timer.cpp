#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include "DateTime.h"

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
    dt.saveEntry();
}

Timer createTimer() {
    cout << "enter time: " << flush;
    string time;
    cin >> time;
    Timer t;
    if (t.parseString(time)) {
        return t;
    }

    return createTimer();
}
