#include "common.h"

namespace jtp
{

std::string MmethodToStr(MMethod m)
{
    switch (m)
    {
    case GET:
        return "GET";
    case POST:
        return "POST";
    case PUT:
        return "PUT";
    case DELETE:
        return "DELETE";
    default:
        throw std::invalid_argument("Invalid method");
    }
}


MMethod MstrToMethod(const std::string& s)
{
    MMethod method = UNKNOWN;
    if (s == "GET") { method = GET; }
    else if (s == "POST") { method = POST; }
    else if (s == "PUT") { method = PUT; }
    else if (s == "DELETE") { method = DELETE; }

    return method;
}

} // namespace jtp
