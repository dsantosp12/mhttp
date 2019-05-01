#include <iostream>
#include <algorithm>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <signal.h>

#include "connection.h"
#include "request.h"
#include "response.h"
#include "connectionmanager.h"

namespace jtp {
  MConnection::MConnection(MIOService& service, MConnectionManager& manager,
                           MDispatcher& dispatcher)
    : _socket(service),
      _connManager(manager),
      _dispatcher(dispatcher) {
  }

  MSocket& MConnection::socket() {
    return _socket;
  }

  void MConnection::start() {
    _socket.async_read_some(boost::asio::buffer(_buffer),
      boost::bind(&MConnection::handleRead, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
  }

  void MConnection::stop() {
    _socket.close();
  }

  void MConnection::handleRead(const MError& ec, std::size_t length) {
    if (!ec) {
      auto resp = _dispatcher.dispatch(_buffer);

      boost::asio::async_write(_socket, resp.buffers(),
        boost::bind(&MConnection::handleWrite, shared_from_this(),
          boost::asio::placeholders::error));
    } else {
      _connManager.stop(shared_from_this());
    }
  }

  void MConnection::handleWrite(const MError& ec) {
    if (!ec) {
      boost::system::error_code ignored_ec;
      _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ignored_ec);
    }

    if (ec != boost::asio::error::operation_aborted) {
      _connManager.stop(shared_from_this());
    }
  }
} // namespace jtp