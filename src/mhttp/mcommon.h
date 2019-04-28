#ifndef MHTTP_MCOMMON_H
#define MHTTP_MCOMMON_H

#include <string>
#include <functional>
#include <array>
#include <optional>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

namespace mhttp {
  using MCallback = std::function<void(const std::string&)>;
  using MError = boost::system::error_code;
  using MBuffers = std::vector<boost::asio::const_buffer>;
  using MSocket = boost::asio::ip::tcp::socket;
  using MIOService = boost::asio::io_service;
  using MIOContext = boost::asio::io_context;
  using MAcceptor = boost::asio::ip::tcp::acceptor;
  using MEndpoint = boost::asio::ip::tcp::endpoint;
  using MResolver = boost::asio::ip::tcp::resolver;
  using MQuery = boost::asio::ip::tcp::resolver::query;
  using MBuffer = std::array<char, 8192>;
  using MOptString = std::optional<std::string>;

  enum MMethod {
    GET,
    POST,
    PUT,
    DELETE,

    METHOD_COUNT,
    UNKNOWN,
  };

  std::string MmethodToStr(MMethod m);

  MMethod MstrToMethod(const std::string& s);
}

#endif