#ifndef MHTTP_MCONNECTION_H
#define MHTTP_MCONNECTION_H

#include <thread>
#include <array>
#include <set>
#include <memory>
#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/array.hpp>

#include "mcommon.h"
#include "mdispatcher.h"

namespace mhttp {
  class MConnectionManager;

  class MConnection 
    : private boost::noncopyable,
      public boost::enable_shared_from_this<MConnection> {
    public:
      explicit MConnection(MIOService& service, MConnectionManager& manager,
                           MDispatcher& dispatcher);

      MSocket& socket();

      void start();

      void stop();

    private:
      void handleRead(const MError& ec, std::size_t bytes);

      void handleWrite(const MError& ec);

      MSocket _socket;

      MConnectionManager& _connManager;

      MBuffer _buffer;

      MDispatcher& _dispatcher;
  };

  using MConnectionPtr = boost::shared_ptr<MConnection>;
}

#endif
