#ifndef JTP_MCONNECTIONMANAGER_H
#define JTP_MCONNECTIONMANAGER_H

#include <set>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include "connection.h"

namespace jtp {
  class MConnectionManager : private boost::noncopyable {
    public:
      void start(MConnectionPtr conn);

      void stop(MConnectionPtr conn);

      void stopAll();

    private:
      std::set<MConnectionPtr> _connections;
  };
} // namespace jtp

#endif