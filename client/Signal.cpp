#include <Signal.hpp>
#include <ClientState.hpp>
using namespace ClashingCountries;

void clientSigtermHandler(int signal_id) {
    sf::Packet disconnectRequest;
    disconnectRequest << std::string("Disconnect");
    connection.send(disconnectRequest, server, serverPort);
}