#include <iostream>
#include "time/Timer.h"
#include "Util.h"
#include "History.h"

using namespace std;

bool menu() {
    clear();
    cout << "Timer" << endl;
    printLine(15);
    cout << endl;

    string leanedToday = getTimeLearnedToday();
    if (!leanedToday.empty())
        cout << "Today you leaned " << leanedToday << endl << endl;

    cout << "[n] new timer" << endl << "[h] history" << endl << "[q] quit" << endl;
    string a;
    cin >> a;
    switch (a[0]) {
        case 'n':
            createTimer().run();
            break;
        case 'h':
            historyMenu();
            break;
        case 'q':
            return false;
    }
    return true;
}

int main() {
    while (menu()) {}
    return 0;
}