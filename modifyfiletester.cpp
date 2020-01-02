#include "modifyfiletester.h"

ModifyFileTester::ModifyFileTester()
    : FileReadWrite(nullptr, nullptr)
{

}

TEST_F(ModifyFileTester, InitialModifyFileTest) {
    this->set_file_name(FileReadWrite::test_file_name());

    this->read();

    ASSERT_EQ(static_cast<int>(mLines.size()), 7);
    std::vector<std::string>::iterator iter = begin(mLines);
    ASSERT_STREQ(iter->c_str(), "A");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "B");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "C");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "D");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "E");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "F");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "G");
}

TEST_F(ModifyFileTester, TruncateFileTest) {
    this->set_file_name(FileReadWrite::trash_file_name());

    this->append("no thank you");

    this->read();

    ASSERT_GE(static_cast<int>(mLines.size()), 1);

    this->clear_file();

    this->read();

    ASSERT_EQ(static_cast<int>(mLines.size()), 0);
}

TEST_F(ModifyFileTester, AppendLineFileTest) {
    this->set_file_name(FileReadWrite::trash_file_name());
    this->clear_file();
    this->append("first");
    this->append("second");

    this->read();

    ASSERT_EQ(static_cast<int>(mLines.size()), 2);
    std::vector<std::string>::iterator iter = begin(mLines);
    ASSERT_STREQ(iter->c_str(), "first");
    ++iter;
    ASSERT_STREQ(iter->c_str(), "second");
}
