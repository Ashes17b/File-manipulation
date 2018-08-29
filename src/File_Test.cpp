#include <limits.h>
#include "gtest/gtest.h"
#include "File.h"

class FileTest : public::testing::Test {};

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

TEST_F(FileTest, removeSpecificWord_with_Delimiters)
{
    const string nameInFile = "../tests/test1.in";
    const string nameOutFile = "../tests/test1.out";
    const string nameAnsFile = "../tests/test1.ans";
    const string word = "help";
    File file(nameInFile, nameOutFile, word);
    file.readFileAndChange();
    EXPECT_EQ(true, compareFiles(nameOutFile, nameAnsFile));
}

TEST_F(FileTest, removeSpecificWord1)
{
    const string nameInFile = "../tests/test2.in";
    const string nameOutFile = "../tests/test2.out";
    const string nameAnsFile = "../tests/test2.ans";
    const string word = "love";
    File file(nameInFile, nameOutFile, word);
    file.readFileAndChange();
    EXPECT_EQ(false, compareFiles(nameOutFile, nameAnsFile));
}

TEST_F(FileTest, removeSpecificWord2)
{
    const string nameInFile = "../tests/test3.in";
    const string nameOutFile = "../tests/test3.out";
    const string nameAnsFile = "../tests/test3.ans";
    const string word = "error";
    File file(nameInFile, nameOutFile, word);
    file.readFileAndChange();
    EXPECT_EQ(true, compareFiles(nameOutFile, nameAnsFile));
}
