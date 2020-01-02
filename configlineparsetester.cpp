#include "configlineparsetester.h"

ConfigLineParseTester::ConfigLineParseTester()
{

}

TEST_F(ConfigLineParseTester, ParseValidLine) {
    ConfigLine data;
    std::string raw_line = "id=22501,val2=11,meta_val1=51,val3=12";
    bool result = this->parse_line(data, raw_line);

    ASSERT_TRUE(result);
    ASSERT_STREQ(data.id.c_str(), "22501");
    ASSERT_STREQ(data.val2.c_str(), "11");
    ASSERT_STREQ(data.meta_val1.c_str(), "51");
    ASSERT_STREQ(data.val3.c_str(), "12");
}

TEST_F(ConfigLineParseTester, ParseInvalidLine) {
    ConfigLine data;
    std::string raw_line = "hogwash";
    bool result = this->parse_line(data, raw_line);

    ASSERT_FALSE(result);
    ASSERT_STREQ(data.id.c_str(), "");
    ASSERT_STREQ(data.val2.c_str(), "");
    ASSERT_STREQ(data.meta_val1.c_str(), "");
    ASSERT_STREQ(data.val3.c_str(), "");
}
