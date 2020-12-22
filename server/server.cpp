#include <debug.hpp>
#include <SFML/Network.hpp>

using std::cout;
using std::cerr;
using std::clog;
using namespace ClashingCountries;

int main() {
    
    freopen("clashing_countries_server.log", "r", stderr);

    // sf::UdpSocket s;
    time_t current_time;
    struct tm *local_current_time;
    /*
    if (s.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
        std::string timestamp = Debug::get_timestamp(&current_time, local_current_time);
        std::cout << timestamp <<  " Error: could not establish UDP socket" << std::endl;
        std::cerr <<  timestamp <<" Error: could not establish UDP socket" << std::endl;
    }

    std::cout << Debug::get_timestamp(&current_time, local_current_time) << " Successfully started UDP Socket on port " << s.getLocalPort() << std::endl;
    */

    sf::TcpListener l;
    if (l.listen(sf::Socket::AnyPort) != sf::Socket::Done) {
        std::cerr << Debug::get_timestamp(&current_time, local_current_time) << " Could not create TcpListener" << std::endl;
    }
    std::cout << Debug::get_timestamp(&current_time, local_current_time) << " Successfully created TcpListener at port " << l.getLocalPort() << std::endl;
    int connections = 0;
    sf::TcpSocket clients[5];
    while (connections < 5) {
        if (l.accept(clients[connections]) != sf::Socket::Done) {

        } else {
            std::cout << "Successfully added client" << std::endl;
            connections++;
        }
    }

    return 0;

}