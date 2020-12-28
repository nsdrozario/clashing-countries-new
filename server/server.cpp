#include <debug.hpp>
#include <SFML/Network.hpp>
#include <utility>

using std::cout;
using std::cerr;
using std::clog;
using namespace ClashingCountries;

std::pair<sf::IpAddress, unsigned short> playerConnections [5];

int num_players = 0;
bool gameStarted = false;


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
    /*
    sf::TcpListener l;
    if (l.listen(sf::Socket::AnyPort) != sf::Socket::Done) {
        std::cerr << Debug::get_timestamp(&current_time, local_current_time) << " Could not create TcpListener" << std::endl;
    }
    std::cout << Debug::get_timestamp(&current_time, local_current_time) << " Successfully created LAN TcpListener on IP " << sf::IpAddress::getLocalAddress() << "at port " << l.getLocalPort() << std::endl;
    int connections = 0;
    sf::TcpSocket clients[5];
    while (connections < 5) {
        if (l.accept(clients[connections]) != sf::Socket::Done) {

        } else {
            std::cout << "Successfully added client" << std::endl;
            connections++;
        }
    }
*/


    sf::UdpSocket s;
    if (s.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
        std::string timestamp = Debug::get_timestamp(&current_time, local_current_time);
        std::cout << timestamp <<  " Error: could not establish UDP socket" << std::endl;
        std::cerr <<  timestamp <<" Error: could not establish UDP socket" << std::endl;
    }
    
    std::cout << "Sucessfully created UdpSocket on " << sf::IpAddress::getLocalAddress() << " at port "<< s.getLocalPort() << std::endl;
    std::cout << "Awaiting connections..." << std::endl;

    while (!gameStarted) {

        sf::IpAddress senderIP;
        unsigned short senderPort;
        sf::Packet attemptConnectionPacket;
        if (s.receive(attemptConnectionPacket, senderIP, senderPort) != sf::Socket::Done) {
            // stuff
        }

        std::string received;
        attemptConnectionPacket >> received;
        
        std::cout << "Got message " << received << " from " << senderIP.toString() << std::endl;

        if (received == "ClashingCountriesJoinRequest") {
          
           std::cout << "Got connection from IP " << senderIP.toString() << ", port " << senderPort << ". Adding to user list..." << std::endl;
            playerConnections[++num_players-1] =  std::pair<sf::IpAddress, unsigned short>(senderIP, senderPort);

            std::string msg = "ConnectionAccepted";
            sf::Packet response;
            response << msg;
            s.send(response, playerConnections[num_players-1].first, playerConnections[num_players-1].second);
        } else if (received == "Disconnect") {
            std::cout << "Disconnecting player from IP " << senderIP.toString() << ", port " << senderPort << std::endl;
            std::find(std::begin(playerConnections), std::end(playerConnections), std::make_pair(senderIP, senderPort));
        }

        
    }



    return 0;

}