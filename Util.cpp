#include "Util.h"
#include <sstream>

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
