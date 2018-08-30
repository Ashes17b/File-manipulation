#include "File.h"

bool stringCompare(const string &left, const string &right) {
    for (string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit)
        if (tolower(*lit) < tolower(*rit))
            return true;
        else if (tolower(*lit) > tolower(*rit))
            return false;
    if (left.size() < right.size())
        return true;
    return false;
}

void File::readFileAndChange() {
    try 
    {
        ifstream infile(nameInFile);
        ofstream outfile(nameOutFile);
        if (!infile) {
            string errorMessage = std::string("Error: can't open file");
            throw runtime_error(errorMessage);
        }
        if (infile.peek() == ifstream::traits_type::eof()) {
            infile.close();
            string errorMessage = std::string("Error: file is empty");
            throw runtime_error(errorMessage);
        }

        string line;
        vector<string> data;
        while (getline(infile, line)) {
            removeCertainWordFromString(line);
            data.push_back(line);
            sort(data.begin(), data.end(), stringCompare);
        }
        copy(data.begin(), data.end(), ostream_iterator<string>(outfile, "\n"));

        outfile.close();
        infile.close();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
}

void File::removeCertainWordFromString(string &line) {
    regex r("\\b" + word + "\\b"); 
    smatch m;
    
    while(regex_search(line, m, r)) {
        auto pos = m.position();
        line.erase(m.position(), m.length());
        if (isspace(line.at(pos)))
            line.erase(m.position(), 1);
    }
}