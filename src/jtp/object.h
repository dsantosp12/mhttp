#ifndef JTP_MOBJECT_H
#define JTP_MOBJECT_H

#include <ostream>
#include "common.h"

namespace jtp {
  class MObject {
    public:
      MObject() {}

      virtual MBuffers buffers() = 0;

      friend std::ostream& operator<<(std::ostream& s, const MObject& headers);
  };
} // namespace jtp

#endif