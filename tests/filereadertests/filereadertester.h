#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "filereader.h"

class FileReaderTester : public ::testing::Test{
    protected:
    FileReaderTester();

    virtual ~FileReaderTester();

    virtual void SetUp();

    virtual void TearDown();

public:
    FileReader* fr;
};