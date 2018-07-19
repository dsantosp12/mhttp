#ifndef MHTTP_MOBJECT_H
#define MHTTP_MOBJECT_H

#include <ostream>
#include "mcommon.h"

namespace mhttp {
  class MObject {
    public:
      MObject() {}

      virtual MBuffers buffers() = 0;

      friend std::ostream& operator<<(std::ostream& s, const MObject& headers);
  };
}

#endif