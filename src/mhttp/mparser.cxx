#include <algorithm>
#include <optional>
#include <vector>
#include <utility>
#include <iostream>

#include "mparser.h"

namespace mhttp {
  const std::string HTTP_VERSION_1_0 = "HTTP/1.0";
  const std::string HTTP_VERSION_1_1 = "HTTP/1.1";

  static MRequest _currentRequest;
  static std::string _currentKey;

  MParser::MParser() : _parser(new NHTTPParser) {
    http_parser_init(_parser, HTTP_REQUEST);
    http_parser_settings_init(&_settings);

    _settings.on_message_begin = &_onBegin;
    _settings.on_url = &_onUrl;
    _settings.on_status = &_onStatus;
    _settings.on_header_field = &_onHeaderField;
    _settings.on_header_value = &_onHeaderValue;
    _settings.on_headers_complete = &_onHeadersComplete;
    _settings.on_body = &_onBody;
    _settings.on_message_complete = &_onMessageComplete;
  }

  MParser::~MParser() {
    if (_parser) {
      delete _parser;
      _parser = nullptr;
    }
  }

  int MParser::_onBegin(http_parser* parser) {
    auto method = http_method_str(static_cast<enum http_method>(parser->method));

    if (method) {
      _currentRequest.setMethod(method);
      return 0;
    } else {
      return -1;
    }
  }

  int MParser::_onUrl(http_parser* parser, const char* data, unsigned long length) {
    if (length > 0) {
      _currentRequest._uri = std::string(data, length);
      return 0;
    } else {
      return -1;
    }
  }

  int MParser::_onStatus(http_parser* parser, const char* data, unsigned long length) {
    return 0;
  }

  int MParser::_onHeaderField(NHTTPParser* parser, const char* data, std::size_t length) {
    if (length > 0) {
      _currentKey = std::string(data, length);
      return 0;
    } else {
      return -1;
    }
  }

  int MParser::_onHeaderValue(NHTTPParser* parser, const char* data, std::size_t length) {
    if (length > 0) {
      _currentRequest._headers.set(_currentKey, std::string(data, length));
      return 0;
    } else {
      return -1;
    }
  }

  int MParser::_onHeadersComplete(NHTTPParser* parser) {
    return 0;
  }

  int MParser::_onBody(NHTTPParser* parser, const char* data, std::size_t length) {
    if (length > 0) {
      _currentRequest._body = std::string(data, length);
      return 0;
    } else {
      return -1;
    }
  }

  int MParser::_onMessageComplete(NHTTPParser* parser) {
    return 0;
  }

  void MParser::parse(MBuffer& buff, std::size_t length, const MParserDoneCB& cb) {
    auto numParsed = http_parser_execute(_parser, &_settings, buff.data(), length);

    if (_parser->http_errno == 0) {
      cb(_currentRequest);
    } else {
      cb(std::optional<MRequest>(std::nullopt));

      // TODO: Implement logger
      std::cerr << http_errno_description(static_cast<http_errno>(_parser->http_errno)) << std::endl;
    }
  }
} // mhttp