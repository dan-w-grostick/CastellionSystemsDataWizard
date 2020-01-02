#ifndef MODIFYFILETESTER_H
#define MODIFYFILETESTER_H

#include "gtest/gtest.h"
#include "filereadwrite.h"

class ModifyFileTester : public FileReadWrite, public ::testing::Test
{
public:
    ModifyFileTester();
};

#endif // MODIFYFILETESTER_H
