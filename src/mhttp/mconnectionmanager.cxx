#include "mconnectionmanager.h"

namespace mhttp {
  void MConnectionManager::start(MConnectionPtr conn) {
    _connections.insert(conn);
    conn->start();
  }

  void MConnectionManager::stop(MConnectionPtr conn) {
    _connections.erase(conn);
    conn->stop();
  }

  void MConnectionManager::stopAll() {
    std::for_each(_connections.begin(), _connections.end(), 
    [this](auto conn) { this->stop(conn); });
    _connections.clear();
  }
} // mhttp
