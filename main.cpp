#include <iostream>
#include "time/Timer.h"
#include "Util.h"
#include "History.h"

using namespace std;

bool menu() {
    clear();
    cout << " /$$$$$$$$ /$$                                  \n"
            "|__  $$__/|__/                                  \n"
            "   | $$    /$$ /$$$$$$/$$$$   /$$$$$$   /$$$$$$ \n"
            "   | $$   | $$| $$_  $$_  $$ /$$__  $$ /$$__  $$\n"
            "   | $$   | $$| $$ \\ $$ \\ $$| $$$$$$$$| $$  \\__/\n"
            "   | $$   | $$| $$ | $$ | $$| $$_____/| $$      \n"
            "   | $$   | $$| $$ | $$ | $$|  $$$$$$$| $$      \n"
            "   |__/   |__/|__/ |__/ |__/ \\_______/|__/      \n"
            "                                                \n"; //font: Big Money-ne
    string leanedToday = getTimeLearnedToday();
    if (!leanedToday.empty())
        cout << "Today you worked " << leanedToday << endl << endl;

    cout << "[n] new timer" << endl << "[h] history" << endl << "[q] quit" << endl;
    string a;
    getline(cin, a);
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