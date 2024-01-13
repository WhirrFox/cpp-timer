#include "History.h"
#include <iostream>
#include <fstream>
using namespace std;

#define filename "log.csv"

void saveEntry(DateTime dt) {
    ofstream f;
    f.open(filename, ios_base::app);

    f << dt.str();
    f << "\n";

    f.close();
}
