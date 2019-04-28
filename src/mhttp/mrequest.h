#ifndef MHTTP_MREQUEST_H
#define MHTTP_MREQUEST_H

#include <string>

#include "mcommon.h"
#include "mobject.h"
#include "murl.h"
#include "mheaders.h"
#include "mserializer.h"

namespace mhttp {
  struct  MRequest : private MSerializable {
      MRequest()
        : _method(UNKNOWN),
          _uri(""),
          _version(""),
          _headers(),
          _body("")
      {}

      MMethod _method;

      MUri _uri;

      std::string _version;

      MHeaders _headers;

      std::string _body;

      // TODO: Handle other methods
      void setMethod(const std::string& method);

      // MSerializer Interface
      virtual void deserialize(json *out) const override;

      virtual void serialize(const json &data) override;
  };
}

#endif