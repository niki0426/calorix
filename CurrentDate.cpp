#include "CurrentDate.h"
#include <ctime>
#include <cstdio>

std::string currentDate() {
    time_t now = time(0);
    tm ltm{};
    localtime_s(&ltm, &now);
    char buf[32];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d", 1900 + ltm.tm_year, 1 + ltm.tm_mon, ltm.tm_mday);
    return std::string(buf);
}