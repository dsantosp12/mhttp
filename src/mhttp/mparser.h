#ifndef MHTTP_MPARSER_H
#define MHTTP_MPARSER_H

#include <optional>
#include <functional>
#include <boost/noncopyable.hpp>

#include "mcommon.h"
#include "mresponse.h"
#include "mrequest.h"

namespace mhttp {
  class MParser : boost::noncopyable {
    public:
      MParser();

      ~MParser();

      void parse(const std::string& buff, MRequest* outReq);

    private:
      json _buffer;
  };
} // mhttp

#endif