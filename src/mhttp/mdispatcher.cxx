#include "mdispatcher.h"
#include "mparser.h"

namespace mhttp {
  MDispatcher::MDispatcher() { }

  MResponse MDispatcher::dispatch(MBuffer& buff) {
    MRequest req;
    std::string raw(buff.data());
    _parser.parse(raw, &req);

    // TODO: Implement dispatcher
    MResponse resp;
    resp._method = GET;

    return resp;
  }
} // mhttp
