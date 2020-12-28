#ifndef CLASHING_COUNTRIES_SIGNAL_HPP
#define CLASHING_COUNTRIES_SIGNAL_HPP

#include <csignal>
#include "ClientState.hpp"

namespace ClashingCountries {
    void clientSigtermHandler(int signal_id);
}

#endif