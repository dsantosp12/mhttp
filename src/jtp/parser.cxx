#include <algorithm>
#include <optional>
#include <vector>
#include <utility>
#include <iostream>

#include "parser.h"

namespace jtp {
  const std::string HTTP_VERSION_1_0 = "HTTP/1.0";
  const std::string HTTP_VERSION_1_1 = "HTTP/1.1";

  static MRequest _currentRequest;
  static std::string _currentKey;

  MParser::MParser()
    : _buffer()
  {
  }

  MParser::~MParser()
  {
  }

  void MParser::parse(const std::string& buff, MRequest* outRequest) {
    // Parse the JSON string
    _buffer = json::parse(buff);
    outRequest->serialize(_buffer);
  }
} // namespace jtp