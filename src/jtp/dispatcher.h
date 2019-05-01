#ifndef JTP_MDISPATCHER_H
#define JTP_MDISPATCHER_H

#include <optional>
#include <boost/noncopyable.hpp>

#include "common.h"
#include "response.h"
#include "parser.h"

namespace jtp
{
  class MDispatcher : private boost::noncopyable {
    using MDispatcherDoneCB = std::function<void(const MResponse&)>;

    public:
      MDispatcher();

      ~MDispatcher() = default;

      MResponse dispatch(MBuffer& buff);

    private:
     MParser _parser;

  };
} // namespace jtp

#endif