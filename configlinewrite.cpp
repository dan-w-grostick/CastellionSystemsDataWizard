#include "configlinewrite.h"

ConfigLineWrite::ConfigLineWrite()
{

}

void ConfigLineWrite::convert_data(const ConfigLine &data, std::string &text_line) const {
    std::stringstream ss;

    ss << "id=" << data.id;
    ss << ",val2=" << data.val2;
    ss << ",meta_val1=" << data.meta_val1;
    ss << ",val3=" << data.val3;

    text_line = ss.str();
}

//id=22505,val2=51,meta_val1=70,val3=52
