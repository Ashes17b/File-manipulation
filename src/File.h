#include <regex>
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class File
{
  private:
    string nameInFile;
    string nameOutFile;
    string word;

    //Blocked copy
    File(File &) {}
    void operator=(const File &) {}

  public:
    File(const string &nameInFile, const string &nameOutFile, const string &word) {
        this->nameInFile = nameInFile;
        this->nameOutFile = nameOutFile;
        this->word = word;
    }
    ~File() {}

    void readFileAndChange();
    void removeCertainWordFromString(string&);
};
