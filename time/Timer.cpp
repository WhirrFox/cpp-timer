#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include "DateTime.h"
#include "../Util.h"
#include "../History.h"
#include "../Settings.h"

using namespace std;

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

void Timer::printHeadline(bool isBreak) {
    clear();
    if (isBreak) {
        cout << "Break";
    } else {
        cout << "Learn";
    }
    if (!name.empty()) {
        cout << " - " << name;
    }
    cout << endl;
    printLine(7);
    cout << endl;
}

void Timer::run(bool isBreak) {
    DateTime dt(*this);
    Timer breakTimer = getBreakTimer();
    printHeadline(isBreak);

    while (!isDone()) {
        cout << "\r" << str() << flush;
        tick();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    playSound();

    if (isBreak)
        return;

    saveEntry(dt);

    if (breakTimer.getDurationInSeconds() >= minBreakTime)
        breakTimer.run(true);

    dt.printResult();
}

Timer Timer::getBreakTimer() {
    int seconds = getDurationInSeconds();
    seconds /= timerDivider;
    return Timer(seconds);
}

const string &Timer::getName() const {
    return name;
}

void Timer::setName(const string &name) {
    Timer::name = name;
}

int Timer::getDurationInSeconds() {
    return hour * 360 + minute * 60 + second;
}

string Timer::format() {
    ostringstream o;
    if (hour > 0)
        o << hour << "h ";
    if (minute > 0)
        o << minute << "m ";
    if (second > 0)
        o << second << "s";
    return o.str();
}

Timer Timer::operator+(Timer t) {
    return Timer(getDurationInSeconds() + t.getDurationInSeconds());
}

Timer createTimer() {
    Timer t;
    clear();
    while (true) {
        cout << "enter time: ";
        string time;
        while (!time.length())
            getline(cin, time);

        t.parseString(time);
        if (t.getSecond() + t.getMinute() + t.getHour() > 0)
            break;
    }

    cout << "name (optional): ";
    string name;
    getline(cin, name);
    t.setName(name);
    return t;
}
