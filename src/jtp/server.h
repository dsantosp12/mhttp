#ifndef JTP_MSERVER_H
#define JTP_MSERVER_H

#include <string>

#include <boost/noncopyable.hpp>

#include "common.h"
#include "connectionmanager.h"

namespace jtp {
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
} // namespace jtp

#endif
