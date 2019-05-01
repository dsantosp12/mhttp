#include <boost/bind.hpp>

#include "server.h"

namespace jtp {
  MServer::MServer(const std::string& address, const std::string& port)
    : _service(),
      _signals(_service),
      _acceptor(_service),
      _connManager(),
      _newConnection(),
      _dispatcher() {

    _signals.add(SIGINT);
    _signals.add(SIGTERM);
    _signals.async_wait(boost::bind(&MServer::handleStop, this));

    MResolver resolver(_service);
    MQuery query(address, port);
    MEndpoint endpoint = *resolver.resolve(query);

    _acceptor.open(endpoint.protocol());
    _acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    _acceptor.bind(endpoint);
    _acceptor.listen();

    initAccept();
  }

  void MServer::run() {
    _service.run();
  }

  void MServer::initAccept() {
    _newConnection.reset(new MConnection(_service, _connManager, _dispatcher));
    _acceptor.async_accept(_newConnection->socket(),
      boost::bind(&MServer::handleAccept, this,
        boost::asio::placeholders::error));
  }

  void MServer::handleAccept(const MError& ec) {
    if (!_acceptor.is_open()) {
      return;
    }

    if (!ec) {
      _connManager.start(_newConnection);
    }

    initAccept();
  }

  void MServer::handleStop() {
    _acceptor.close();
    _connManager.stopAll();
  }
} // namespace jtp
