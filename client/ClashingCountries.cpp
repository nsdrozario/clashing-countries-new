#include <UI.hpp>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <SFML/Network.hpp>

using namespace ClashingCountries;

sf::UdpSocket connection;

void PrettyMain() {
    
    using ConsoleUI::RuntimeDataUI;

    ConsoleUI::CustomInit();

    wattron(RuntimeDataUI::RenderArea, COLOR_PAIR(ConsoleUI::Colors::MainHeader));
    mvwaddstr(RuntimeDataUI::RenderArea, 1, 60, "Clashing Countries");
    wattroff(RuntimeDataUI::RenderArea, COLOR_PAIR(ConsoleUI::Colors::MainHeader));

    wattron(RuntimeDataUI::RenderArea, COLOR_PAIR(ConsoleUI::Colors::PositiveText));
    mvwaddstr(RuntimeDataUI::RenderArea, 10, 45, "Type an IP address to connect to!");
    wattroff(RuntimeDataUI::RenderArea, COLOR_PAIR(ConsoleUI::Colors::PositiveText));

    mvwaddch(RuntimeDataUI::CommandConsole, 1, 1, '>');
    
    move(28, 2); // move to console

    wrefresh(RuntimeDataUI::CommandConsole);
    wrefresh(RuntimeDataUI::RenderArea);
    refresh();

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

        std::string msg = "ClashingCountriesJoinRequest";
        sf::Packet data;
        data << msg;
        if (connection.send(data, ip, port) != sf::Socket::Done) {
            std::cout << "Incorrect, try again" << std::endl;       
        }

        std::cout << "Waiting for server response... " << std::endl;

        sf::Packet successData; 
        sf::IpAddress host; 
        unsigned short hostPort;

        if (connection.receive(successData, host, hostPort) != sf::Socket::Done) {
            std::cout << "Something wrong " << std::endl;
        }

        std::string responseContents;
        successData >> responseContents;

        if (responseContents == "ConnectionAccepted") {
            std::cout << "Connection successful!" << std::endl;
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
