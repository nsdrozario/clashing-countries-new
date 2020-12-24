#ifndef CLASHING_COUNTRIES_UI_HPP
#define CLASHING_COUNTRIES_UI_HPP

extern "C" {
    #include <ncurses.h>
}

#include <string>

namespace ClashingCountries {
    namespace ConsoleUI {
        enum Colors {
            Default,
            PositiveText,
            PositiveButton,
            NegativeText,
            NegativeButton,
            UnselectedButton,
            MainHeader,
            SubHeader,

        };
        class RuntimeDataUI {
        public:
            static WINDOW *RenderArea;
            static WINDOW *CommandConsole;
        };
        void CustomInit();
        std::string getCommand();
        void clearConsole(); 
        void CustomDealloc();
    }
}


#endif