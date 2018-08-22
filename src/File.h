#include <boost/algorithm/string.hpp>
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

    void vector_string_toLower(vector<string> &data) {
        for (unsigned int i = 0; i < data.size(); i++)
            boost::to_lower(data[i]);
    }

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
    string removeSpecificWord(const string &line);
};
