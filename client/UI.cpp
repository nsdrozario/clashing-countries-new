#include <UI.hpp>
#include <cstdlib>
#include <string>
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

std::string ConsoleUI::getCommand() {
    move(28,2);
    int tmp;
    char *cmdbuf = new char[256];
    int it = 0;
    tmp = getch();
    bool running = true;
    while (running && it < 255) {
        switch(tmp) {
            case 8:
            case KEY_BACKSPACE:
                if (it > 0) {
                    cmdbuf[it]=' ';
                    it--;
                    addch(' ');
                    move(getcury(stdscr),getcurx(stdscr)-1);
                    refresh();
                }
                break;
            case KEY_ENTER:
            case 10:
                running = false;
                break;
            default:
                cmdbuf[it] = tmp;
                addch(tmp);
                refresh();
                it++;
                tmp = getch();
                break;
        }
    }
    cmdbuf[++it] = '\0';
    std::string ret(cmdbuf);
    delete[] cmdbuf;
    return ret;
}

void ConsoleUI::clearConsole() {
    for (int i = 2; i <= 120; i++) {
        mvwdelch(RuntimeDataUI::CommandConsole, 1, i);
    }
}