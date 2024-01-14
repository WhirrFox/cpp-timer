#include <iostream>
#include <chrono>
#include <thread>
#include "Timer.h"
#include "DateTime.h"
#include "../Util.h"
#include "../History.h"
#include "../Settings.h"

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

void Timer::run(bool isBreak) {
    DateTime dt(*this);
    Timer breakTimer = getBreakTimer();

    clear();
    if (isBreak) {
        cout << "Break" << endl;
    } else {
        cout << "Work" << endl;
    }

    printLine(7);
    while (!isDone()) {
        cout << "\r" << str() << flush;
        tick();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    playSound();

    if (isBreak || breakTimer.getDurationInSeconds() < 10)
        return;

    saveEntry(dt);
    breakTimer.run(true);
}

Timer Timer::getBreakTimer() {
    int seconds = getDurationInSeconds();
    seconds /= timerDevider;

    int newHours = seconds / 3600;
    seconds %= 3600;

    int newMinutes = seconds / 60;
    seconds %= 60;

    return {newHours, newMinutes, seconds};
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
