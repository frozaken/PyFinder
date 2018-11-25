#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "tokenizer.h"
#include <string>

class TokenizerTester : public ::testing::Test{
    protected:
    TokenizerTester();

    virtual ~TokenizerTester();

    virtual void SetUp();

    virtual void TearDown();

public:
    Tokenizer* tkn;
};