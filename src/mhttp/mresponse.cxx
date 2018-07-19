#include <boost/asio.hpp>

#include "mresponse.h"

namespace mhttp {
  MResponse::MResponse() {
  }

  MBuffers MResponse::buffers() {
    const std::string ok = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: 19\r\n\r\nHi I'm a message\r\n";

    MBuffers buffers;
    buffers.push_back(boost::asio::buffer(ok));
 
    return buffers;
  }

  MBuffers MResponse::badRequest() {
    const std::string badRequest = "HTTP/1.1 400 Bad Request\r\nContent-type: text/plain\r\nContent-length: \rn";

    MBuffers buffers;
    buffers.push_back(boost::asio::buffer(badRequest));

    return buffers;
  }
}

