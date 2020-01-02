#ifndef CONFIGLINEPARSE_H
#define CONFIGLINEPARSE_H

#include "configline.h"
#include <vector>

class ConfigLineParse
{
public:
    ConfigLineParse();
    bool parse_line(ConfigLine&, const std::string&) const;
protected:
    bool inline contains(const std::string&, char, size_t starting_index = 0) const;
    std::vector<std::string> mTags;
};

#endif // CONFIGLINEPARSE_H
