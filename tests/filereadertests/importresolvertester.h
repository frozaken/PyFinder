#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "importresolver.h"
#include <string>

class ImportResolverTester : public ::testing::Test{
    protected:
    ImportResolverTester();

    virtual ~ImportResolverTester();

    virtual void SetUp();

    virtual void TearDown();

public:
    ImportResolver* irs;
};