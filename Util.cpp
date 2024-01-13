#include "Util.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>

#endif

using namespace std;

string formatInt(int i, int width) {
    if (width != 2) {
        throw "Not implemented";
    }

    ostringstream s;
    if (i < 10) {
        s << "0";
    }
    s << i;
    return s.str();
}

void clear() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void printLine(int length) {
    while (length) {
        cout << "=";
        length--;
    }
    cout << endl;
}

void playSound() {
#ifdef _WIN32
    PlaySound("..\\sound.wav", NULL, SND_ASYNC);
#endif
}
