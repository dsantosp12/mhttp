#ifndef JTP_MPARSER_H
#define JTP_MPARSER_H

#include <optional>
#include <functional>
#include <boost/noncopyable.hpp>

#include "common.h"
#include "response.h"
#include "request.h"

namespace jtp {
  class MParser : boost::noncopyable {
    public:
      MParser();

      ~MParser();

      void parse(const std::string& buff, MRequest* outReq);

    private:
      json _buffer;
  };
} // namespace jtp

#endif