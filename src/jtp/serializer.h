#ifndef JTP_SERIALIZER
#define JTP_SERIALIZER

#include "common.h"
#include "../json/json.hpp"

namespace jtp
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

} // namespace jtp

#endif