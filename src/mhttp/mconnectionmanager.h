#ifndef MHTTP_MCONNECTIONMANAGER_H
#define  MHTTP_MCONNECTIONMANAGER_H

#include <set>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include "mconnection.h"

namespace mhttp {
  class MConnectionManager : private boost::noncopyable {
    public:
      void start(MConnectionPtr conn);

      void stop(MConnectionPtr conn);

      void stopAll();

    private:
      std::set<MConnectionPtr> _connections;
  };
} // mhttp

#endif