#include "Exception.hpp"

#include <cstring>

namespace GPP {

Exception::Exception() : w(nullptr) { }

Exception::Exception(const std::string & what_arg) {
    if (what_arg.empty())
        w = nullptr;
    else {
        w = new std::string::value_type[what_arg.length()];
        std::strcpy(w, what_arg.c_str());
    }
}

Exception::Exception(const char * what_arg) {
    if (what_arg == nullptr) 
        w = nullptr;
    else {
        w = new std::string::value_type[std::strlen(what_arg)];
        std::strcpy(w, what_arg);
    }
}

Exception::~Exception() {
    delete w;
}

const char * Exception::what() const noexcept {
    return w;
}

} // end gpp namespace
