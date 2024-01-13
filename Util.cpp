#include "Util.h"
#include <sstream>
#include <iostream>
#include <windows.h>

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

void playSound() {
    PlaySound("..\\sound.wav", NULL, SND_ASYNC);
}
