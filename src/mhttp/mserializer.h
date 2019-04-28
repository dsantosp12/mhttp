#ifndef MHTTP_SERIALIZER
#define MHTTP_SERIALIZER

#include "mcommon.h"
#include "../json/json.hpp"

namespace mhttp
{

using namespace nlohmann;

class MRequest;
class MResponse;

class MSerializable
{
public:
    virtual void deserialize(json *out) const = 0;

    virtual void serialize(const json &data) = 0;
};

} // namespace http

#endif