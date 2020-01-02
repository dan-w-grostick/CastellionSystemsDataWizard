#include "configlineparse.h"
#include "debugprinthelper.h"

ConfigLineParse::ConfigLineParse()
{
    mTags.push_back("id");
    mTags.push_back("val2");
    mTags.push_back("meta_val1");
    mTags.push_back("val3");
}

#include <iostream>

bool ConfigLineParse::parse_line(ConfigLine &data, const std::string &line) const {
    data.clear();

    bool successful_parse = true;
    bool additional_tags = true;
    std::string::size_type current_index = 0;

    DebugPrintHelper::ConfigLineTagSize(mTags.size());

    std::for_each(begin(mTags), end(mTags), [&current_index, &data, &line, &successful_parse, &additional_tags](const std::string &tag) {
        DebugPrintHelper::ConfigLineTagName(tag, successful_parse);
        if (additional_tags && successful_parse) {
            std::string::size_type index = line.find(",", current_index);
            DebugPrintHelper::ConfigLineLineParse(line, current_index);
            DebugPrintHelper::ConfigLineIndex(index);
            if (index == std::string::npos) {
                additional_tags = false;
            }
            std::string element = line.substr(current_index, index - current_index);

            std::string::size_type mid_index = element.find("=");
            if (mid_index == std::string::npos) {
                successful_parse = false;
            } else {
                std::string value = element.substr(mid_index + 1);
                DebugPrintHelper::ConfigLineValue(value);

                if (tag == "id") {
                    data.id = value;
                } else if (tag == "val2") {
                    data.val2 = value;
                } else if (tag == "meta_val1") {
                    data.meta_val1 = value;
                } else if (tag == "val3") {
                    data.val3 = value;
                } else {
                    successful_parse = false;
                }

                current_index = index + 1;
            }
        }
    });

    return successful_parse;
}

bool ConfigLineParse::contains(const std::string &line, char c, size_t starting_index) const {
    bool does_contain = true;
    if (line.find(c, starting_index) == std::string::npos)
        does_contain = false;

    return does_contain;
}
