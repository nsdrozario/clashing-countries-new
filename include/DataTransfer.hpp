#ifndef CLASHING_COUNTRIES_DATATRANSFER_HPP
#define CLASHING_COUNTRIES_DATATRANSFER_HPP

#include <nlohmann/json.hpp>

namespace ClashingCountries {
    namespace Data {
        enum class RequestType {
            Login,
            Disconnect,
            RoundAction,
            Chat,
            Info
        };
        enum class ActionType {
            Attack,
            Defend,
            UseMana,
            Mine
        };
    }
}

#endif