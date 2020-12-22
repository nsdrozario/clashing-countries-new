#include <UI.hpp>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <SFML/Network.hpp>

using namespace ClashingCountries;

sf::TcpSocket connection;


void PrettyMain() {
    ConsoleUI::CustomInit();
    wrefresh(ConsoleUI::RuntimeDataUI::CommandConsole);
    wrefresh(ConsoleUI::RuntimeDataUI::RenderArea);
    getch();
}

void RegularMain() {
    
    std::string ip;
    unsigned short port;
    bool valid_server = false;

    std::cout << "Welcome to Clashing Countries!\n"
              << "Please enter the IP address to.\n"
              << "Example: 192.168.0.1"
              << std::endl;
    
    while (!valid_server) {
        std::cin >> ip;
        std::cout << "Now, enter the port: ";
        std::cin >> port;
        if (connection.connect(ip, port) != sf::Socket::Done) {
            std::cout << "Incorrect, try again" << std::endl;       
        } else {
            std::cout <<"Successful connection" << std::endl;
            valid_server = true;
        }
    }

    getchar();

}

int main () {
    std::string response;
    std::cout << "Use pretty UI mode? [y/n]: ";
    std::cin >> response;
    if (response == "Y" || response=="y") {
        PrettyMain();
    } else {
        RegularMain();
    }
    return 0;
}
