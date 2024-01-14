
#ifndef TIMER_HISTORY_H
#define TIMER_HISTORY_H

#include "time/DateTime.h"

void saveEntry(DateTime dt);

void historyMenu();

std::string getTimeLearnedToday();

#endif //TIMER_HISTORY_H
