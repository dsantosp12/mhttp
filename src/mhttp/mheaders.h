#ifndef MHTTP_MHEADERS_H
#define MHTTP_MHEADERS_H

#include <map>
#include <string>
#include <optional>
#include <boost/noncopyable.hpp>

#include "mobject.h"

namespace mhttp {
  class MHeaders {
    public:
      void set(const std::string& key, const std::string& value);

      MOptString get(const std::string& key) const;

    private:
      std::map<std::string, std::string> _headers;
  };
}

#endif