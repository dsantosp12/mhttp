#ifndef MHTTP_MRESPONSE_H
#define MHTTP_MRESPONSE_H

#include "mcommon.h"
#include "mobject.h"

namespace mhttp {
  class MResponse : public MObject {
    public: 
      MResponse();

      MBuffers buffers() override;

      // Static helper method
      static MBuffers badRequest();

    private:
      MMethod _method;

  };
}

#endif
