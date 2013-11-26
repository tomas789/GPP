#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP

#include <exception>
#include <string>

namespace GPP {

class Exception : std::exception {
protected:
    char * w;

public:
    Exception();
    explicit Exception(const std::string & what_arg);
    explicit Exception(const char * what_arg);

    virtual ~Exception();

    virtual const char * what() const noexcept;
};

}

#endif
