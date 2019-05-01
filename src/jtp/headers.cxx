#include "headers.h"

namespace jtp {
  void MHeaders::set(const std::string& key, const std::string& val) {
    _headers.insert(std::make_pair(key, val));
  }
  
  std::optional<std::string> MHeaders::get(const std::string& key) const {
    auto itr = _headers.find(key);

    if (itr == _headers.end()) {
      return std::optional<std::string>(std::nullopt);
    } else {
      return std::make_optional(itr->second);
    }

  }
} // namespace jtp