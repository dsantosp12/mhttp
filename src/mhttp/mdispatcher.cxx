#include "mdispatcher.h"
#include "mparser.h"

namespace mhttp {
  MDispatcher::MDispatcher() { }

  void MDispatcher::dispatch(MBuffer& buff, std::size_t length, const MDispatcherDoneCB& cb) {
    _parser.parse(buff, length, [&cb](auto request) {
      if (request) {

      }
      MResponse resp;
      cb(resp);
    });
  }
} // mhttp
