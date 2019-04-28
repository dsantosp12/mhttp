#ifndef MHTTP_MHEADERS_H
#define MHTTP_MHEADERS_H

#include <map>
#include <string>
#include <optional>
#include <boost/noncopyable.hpp>

#include "mobject.h"

namespace mhttp {
  class MHeaders {
    using HeaderMap = std::map<std::string, std::string>;
    public:
      void set(const std::string& key, const std::string& value);

      MOptString get(const std::string& key) const;

      inline HeaderMap::iterator begin() {
        return _headers.begin();
      }

      inline HeaderMap::iterator end() {
        return _headers.end();
      }

      inline HeaderMap::const_iterator cbegin() const {
        return _headers.cbegin();
      }

      inline HeaderMap::const_iterator cend() const {
        return _headers.cend();
      }

      inline std::size_t size() const {
        return _headers.size();
      }

    private:
      HeaderMap _headers;
  };
}

#endif