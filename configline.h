#ifndef CONFIGLINE_H
#define CONFIGLINE_H

#include <string>

class ConfigLine
{
public:
    ConfigLine();
    std::string id;
    std::string val2;
    std::string meta_val1;
    std::string val3;
    void clear();
};

#endif // CONFIGLINE_H
