#include "mrequest.h"
#include "mparser.h"
#include "mcommon.h"

#include <iostream>

namespace mhttp {
          // TODO: Handle other methods
    void MRequest::setMethod(const std::string& method) {
        _method = MstrToMethod(method);
    }

    void MRequest::deserialize(json *out) const
    {
        if (!out) return;

        (*out)["method"] = MmethodToStr(_method);
        (*out)["uri"] = _uri;
        (*out)["version"] = _version;

        // Maps headers to array of objects
        json headers;
        for (auto it = _headers.cbegin(); it != _headers.cend(); it++) {
            headers[it->first] = it->second;
        }

        (*out)["headers"] = headers;

        (*out)["body"] = _body;
    }

    void MRequest::serialize(const json &data)
    {
        setMethod(data["method"]);
        _uri = data["uri"];
        _version = data["version"];

        // Insert the keys in JSON header object to the map
        for (auto it = data["headers"].begin(); it != data["headers"].end(); it++) {
            _headers.set(it.key(), it.value());
        }

        _body = data["body"];
    }
}
