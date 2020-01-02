#ifndef CONFIGLINEWRITETESTER_H
#define CONFIGLINEWRITETESTER_H

#include "configlinewrite.h"
#include "configline.h"
#include "gtest/gtest.h"

class ConfigLineWriteTester : public ConfigLineWrite, public ::testing::Test
{
public:
    ConfigLineWriteTester();
};

#endif // CONFIGLINEWRITETESTER_H
