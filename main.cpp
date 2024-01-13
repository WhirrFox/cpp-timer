#include <iostream>
#include "time/Timer.h"
#include "Util.h"

using namespace std;

bool menu() {
    clear();
    cout << "[n] new timer" << endl << "[h] history" << endl << "[q] quit" << endl;
    string a;
    cin >> a;
    switch (a[0]) {
        case 'n':
            createTimer().run();
            break;
        case 'h':
            cout << "hist";
            break;
        case 'q':
            return false;
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    while (menu()) {}
    return 0;
}