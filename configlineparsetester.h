#ifndef CONFIGLINEPARSETESTER_H
#define CONFIGLINEPARSETESTER_H

#include "gtest/gtest.h"
#include "configlineparse.h"

class ConfigLineParseTester : public ConfigLineParse, public ::testing::Test
{
public:
    ConfigLineParseTester();
};

#endif // CONFIGLINEPARSETESTER_H
