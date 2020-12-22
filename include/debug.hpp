#ifndef CLASHING_COUNTRIES_DEBUG_HPP
#define CLASHING_COUNTRIES_DEBUG_HPP

#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::cerr;
using std::clog;

namespace ClashingCountries {
    namespace Debug {
        std::string get_timestamp(time_t *t1, struct tm *t2);
    }
}

#endif