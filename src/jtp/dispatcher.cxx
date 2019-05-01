#include "dispatcher.h"
#include "parser.h"

namespace jtp {
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
} // namespace jtp
