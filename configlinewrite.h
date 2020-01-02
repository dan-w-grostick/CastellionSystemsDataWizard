#ifndef CONFIGLINEWRITE_H
#define CONFIGLINEWRITE_H

#include "configline.h"
#include <sstream>
#include <string>

class ConfigLineWrite
{
public:
    ConfigLineWrite();
    void convert_data(const ConfigLine&, std::string&) const;
};

#endif // CONFIGLINEWRITE_H
