#ifndef MHTTP_MPARSER_H
#define MHTTP_MPARSER_H

#include <optional>
#include <functional>
#include <boost/noncopyable.hpp>

// nodejs httparser
#include "http_parser.h"

#include "mcommon.h"
#include "mresponse.h"
#include "mrequest.h"

namespace mhttp {
  // Using Node HTTP Parser and other types.
  using NHTTPParser = http_parser;
  using NHTTPParserSetting = http_parser_settings;
  using MParserDoneCB = std::function<void(std::optional<MRequest>)>;

  class MParser : boost::noncopyable {
    public:
      MParser();

      ~MParser();

      void parse(MBuffer& buff, std::size_t length, const MParserDoneCB& cb);

    private:
      static int _onBegin(http_parser* parser);

      static int _onUrl(http_parser* parser, const char* data, unsigned long length);

      static int _onStatus(http_parser* parser, const char* data, unsigned long length);

      static int _onHeaderField(NHTTPParser* parser, const char* data, std::size_t length);

      static int _onHeaderValue(NHTTPParser* parser, const char* data, std::size_t length);

      static int _onHeadersComplete(NHTTPParser* parser);

      static int _onBody(NHTTPParser* parser, const char* data, std::size_t length);

      static int _onMessageComplete(NHTTPParser* parser);

      NHTTPParser* _parser;

      NHTTPParserSetting _settings;
  };
} // mhttp

#endif