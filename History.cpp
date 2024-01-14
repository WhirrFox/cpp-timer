#include "History.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "Util.h"
#include "Settings.h"
using namespace std;

void saveEntry(DateTime dt) {
    ofstream f;
    f.open(filename, ios_base::app);

    f << dt.str();
    f << "\n";

    f.close();
}

int countLines() {
    int numLines = 0;
    ifstream in(filename);
    string unused;
    while (getline(in, unused))
        ++numLines;
    in.close();
    return numLines;
}

void printPage(int count, int p) {
    ifstream f(filename);
    string s;
    int offset = count - p * perPage;
    for (int i = 0; i < offset; i++) {
        getline(f, s);
    }

    int lines = offset < 0 ? offset * -1 : 0;
    for (int i = lines; i < perPage; i++) {
        getline(f, s);
        DateTime d(s);
        cout << d.format() << endl;
    }

    f.close();
}

void historyMenu() {
    int count = countLines();
    int maxPage = ceil((double) count / perPage);
    int p = 1;
    while (true) {
        clear();
        ostringstream o;
        o << "Page " << maxPage - p + 1 << " of " << maxPage << endl;
        cout << o.str();
        printLine(o.str().length());
        cout << endl;

        printPage(count, p);
        cout << endl << "[p] previous page [n] next page [q] return" << endl;
        string s;
        cin >> s;
        switch (s[0]) {
            case 'p':
                if (p < maxPage)
                    p++;
                break;
            case 'n':
                if (p > 1)
                    p--;
                break;
            case 'q':
                return;
        }
    }
}

string getTimeLearnedToday() {
    DateTime today{};
    Timer t{};

    ifstream f(filename);

    string s;
    while (getline(f, s)) {
        DateTime d(s);
        if (d.isSameDate(today)) {
            t = t + d.getTimer();
        }
    }

    f.close();

    if (t.getDurationInSeconds() == 0) {
        return "";
    }
    return t.format();
}
