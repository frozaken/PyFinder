#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "pyfinder.h"
#include <string>

class PyFinderTester : public ::testing::Test{
    protected:
    PyFinderTester();

    virtual ~PyFinderTester();

    virtual void SetUp();

    virtual void TearDown();

public:
    PyFinder* pf;
};