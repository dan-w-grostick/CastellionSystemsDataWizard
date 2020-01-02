#ifndef DEBUGPRINTHELPER_H
#define DEBUGPRINTHELPER_H

#include <iostream>
#include <string>

class DebugPrintHelper
{
public:
    DebugPrintHelper();

    inline void static ConfigLineTagSize(size_t s) {
        if (allow_printing)
            std::cout << s << " tag(s)" << std::endl;
    }

    inline void static ConfigLineTagName(const std::string &s, bool b) {
        if (allow_printing)
            std::cout << "Tag: " << s << " -- " << b << std::endl;
    }

    inline void static ConfigLineLineParse(const std::string &s, std::string::size_type t) {
        if (allow_printing)
            std::cout << "Looking for ',' in " << s << " starting at " << t << std::endl;
    }

    inline void static ConfigLineIndex(std::string::size_type t) {
        if (allow_printing)
            std::cout << "Found at index: " << t << "[" << std::string::npos << "]" << std::endl;
    }

    inline void static ConfigLineValue(const std::string &s) {
        if (allow_printing)
            std::cout << "Found value: " << s << std::endl;
    }
protected:
    static const bool allow_printing = false;
};

#endif // DEBUGPRINTHELPER_H
