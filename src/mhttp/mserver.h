#ifndef MHTTP_MSERVER_H
#define MHTTP_MSERVER_H

#include <string>

#include <boost/noncopyable.hpp>

#include "mcommon.h"
#include "mconnectionmanager.h"

namespace mhttp {
  class MServer : private boost::noncopyable {
    public:
      explicit MServer(const std::string& address = "127.0.0.1", const std::string& port = "9999");

      void run();

    private:
      void initAccept();

      void handleAccept(const MError& ec);

      void handleStop();

      MIOService _service;

      boost::asio::signal_set _signals;

      MAcceptor _acceptor;

      MConnectionManager _connManager;

      MConnectionPtr _newConnection;

      MDispatcher _dispatcher;
  };
}

#endif
