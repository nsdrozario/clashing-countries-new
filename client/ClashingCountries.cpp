#include <UI.hpp>
using namespace ClashingCountries;

int main () {

    ConsoleUI::CustomInit();
    wrefresh(ConsoleUI::RuntimeDataUI::CommandConsole);
    wrefresh(ConsoleUI::RuntimeDataUI::RenderArea);
    getch();
    return 0;

}