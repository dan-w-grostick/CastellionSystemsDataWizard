#include "configlinewritetester.h"

ConfigLineWriteTester::ConfigLineWriteTester()
{

}


TEST_F(ConfigLineWriteTester, PrintConfigLine) {
    ConfigLine data;
    data.id = "22505";
    data.val2 = "51";
    data.meta_val1 = "70";
    data.val3 = "52";

    std::string line_text;

    this->convert_data(data, line_text);

    std::string result_line = "id=22505,val2=51,meta_val1=70,val3=52";

    ASSERT_STREQ(line_text.c_str(), result_line.c_str());
}
