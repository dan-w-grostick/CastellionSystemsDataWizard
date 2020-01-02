#include "configline.h"

ConfigLine::ConfigLine()
{
    this->clear();
}

void ConfigLine::clear() {
    this->id = "";
    this->val2 = "";
    this->meta_val1 = "";
    this->val3 = "";
}
