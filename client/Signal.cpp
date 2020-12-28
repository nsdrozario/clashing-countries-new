#include <Signal.hpp>
#include <ClientState.hpp>

void ClashingCountries::clientSigtermHandler(int signal_id) {
    sf::Packet disconnectRequest;
    disconnectRequest << std::string("Disconnect");
    connection.send(disconnectRequest, server, serverPort);
}