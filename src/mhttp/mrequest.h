#ifndef MHTTP_MREQUEST_H
#define MHTTP_MREQUEST_H

#include <string>

#include "mcommon.h"
#include "mobject.h"
#include "murl.h"
#include "mheaders.h"

namespace mhttp {
  struct  MRequest {
      MMethod _method;

      MUri _uri;

      std::string _version;

      MHeaders _headers;

      std::string _body;

      // TODO: Handle other methods
      void setMethod(const std::string& method) {
        if (method == "GET") { _method = GET; }
        else if (method == "POST") { _method = POST; }
        else if (method == "PUT") { _method = PUT; }
        else if (method == "DELETE") { _method = DELETE; }
      }
  };
}

#endif