#include <limits.h>
#include "gtest/gtest.h"
#include "File.h"

class FileTest : public::testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

bool compareFiles(const string &p1, const string &p2) {
    ifstream f1(p1, ifstream::binary | ifstream::ate);
    ifstream f2(p2, ifstream::binary | ifstream::ate);

    if (f1.fail() || f2.fail()) { return false; }

    if (f1.tellg() != f2.tellg()) { return false; }

    f1.seekg(0, ifstream::beg);
    f2.seekg(0, ifstream::beg);
    return equal(istreambuf_iterator<char>(f1.rdbuf()),
                 istreambuf_iterator<char>(),
                 istreambuf_iterator<char>(f2.rdbuf()));
}

TEST_F(FileTest, removeSpecificWord)
{
    const string nameInFile1 = "test1.in";
    const string nameOutFile1 = "test1.out";
    const string nameAnsFile1 = "test1.ans";
    const string word1 = "c++";
    File file1(nameInFile1, nameOutFile1, word1);
    file1.readFileAndChange();
    EXPECT_EQ(true, compareFiles(nameOutFile1, nameAnsFile1));
}

TEST_F(FileTest, removeSpecificWordWithDeterminate) {
    const string nameInFile2 = "test2.in";
    const string nameOutFile2 = "test2.out";
    const string nameAnsFile2 = "test2.ans";
    const string word2 = "love";
    File file2(nameInFile2, nameOutFile2, word2);
    file2.readFileAndChange();
    EXPECT_EQ(false, compareFiles(nameOutFile2, nameAnsFile2));
}
