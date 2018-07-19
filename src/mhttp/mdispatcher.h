#ifndef MHTTP_MDISPATCHER_H
#define MHTTP_MDISPATCHER_H

#include <optional>
#include <boost/noncopyable.hpp>

#include "mcommon.h"
#include "mresponse.h"
#include "mparser.h"

namespace mhttp
{
  class MDispatcher : private boost::noncopyable {
    using MDispatcherDoneCB = std::function<void(const MResponse&)>;

    public:
      MDispatcher();

      ~MDispatcher() = default;

      void dispatch(MBuffer& buff, std::size_t length, const MDispatcherDoneCB& cb);

    private:
     MParser _parser;

  };
} // mhttp

#endif