#ifndef JTP_MRESPONSE_H
#define JTP_MRESPONSE_H

#include "common.h"
#include "object.h"

namespace jtp {
  class MResponse : public MObject {
    public: 
      MResponse();

      MBuffers buffers() override;

      // Static helper method
      static MBuffers badRequest();

      MMethod _method;
  };
} // namespace jtp

#endif
