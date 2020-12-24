#ifndef CLASHING_COUNTRIES_PLAYER_HPP
#define CLASHING_COUNTRIES_PLAYER_HPP

#include <vector>
#include <string>

namespace ClashingCountries {
    namespace Game {
        class Player {
        public:
            Player();
            Player(std::string n);

            int getHP() const;
            long long getTotalMana() const;

        private:
            std::string name;
            int HP;
            long long totalMana;

        };
    }
}

#endif