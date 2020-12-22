#include <debug.hpp>

std::string ClashingCountries::Debug::get_timestamp(time_t *t1, struct tm *t2) {
    time(t1); // this is not even remotely thread safe but it doesn't matter we don't need multithreading for a synchrous game
    t2 = localtime(t1);
    std::stringstream output;
    output << "[" << t2->tm_hour << ":" << t2->tm_min << ":" << t2->tm_sec << "]";
    return output.str();
}