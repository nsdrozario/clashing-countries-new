#include <UI.hpp>
#include <cstdlib>
using namespace ClashingCountries;

WINDOW *ConsoleUI::RuntimeDataUI::CommandConsole;
WINDOW *ConsoleUI::RuntimeDataUI::RenderArea;

void ConsoleUI::CustomInit() {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    if (!has_colors()) {
        endwin();
        exit(-1);
    }

    start_color();
    init_pair(PositiveText, COLOR_GREEN, COLOR_BLACK);
    init_pair(NegativeText, COLOR_RED, COLOR_BLACK);
    init_pair(PositiveButton, COLOR_WHITE, COLOR_GREEN);
    init_pair(NegativeButton, COLOR_WHITE, COLOR_RED);
    init_pair(UnselectedButton, COLOR_BLACK, COLOR_WHITE);
    init_pair(MainHeader, COLOR_CYAN, COLOR_BLACK);
    init_pair(SubHeader, COLOR_WHITE, COLOR_BLACK);

    clear();
    refresh();

    RuntimeDataUI::RenderArea = newwin(27, 120, 0, 0);
    RuntimeDataUI::CommandConsole = newwin(3, 120, 27, 0);

    wattron(RuntimeDataUI::RenderArea, A_BOLD);
    box(RuntimeDataUI::RenderArea, 0,0);
    wattroff(RuntimeDataUI::RenderArea,A_BOLD);

    wattron(RuntimeDataUI::CommandConsole, A_BOLD);
    box(RuntimeDataUI::CommandConsole, 0,0);
    wattroff(RuntimeDataUI::CommandConsole,A_BOLD);

    wrefresh(RuntimeDataUI::RenderArea);
    wrefresh(RuntimeDataUI::CommandConsole);
    
}

void ConsoleUI::CustomDealloc() {
    endwin();
}