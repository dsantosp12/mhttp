#ifndef JTP_MREQUEST_H
#define JTP_MREQUEST_H

#include <string>

#include "common.h"
#include "object.h"
#include "url.h"
#include "headers.h"
#include "serializer.h"

namespace jtp {
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
} // namespace jtp

#endif