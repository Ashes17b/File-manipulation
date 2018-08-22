#include "File.h"

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
        while (getline(infile, line)) {
            string lineChanged = removeSpecificWord(line);
            outfile << lineChanged << endl;
        }

        outfile.close();
        infile.close();
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
}

string File::removeSpecificWord(const string &line) {
    vector<string> data;
    boost::split(data, line, boost::is_any_of(" ,.:"));
    data.erase(remove(data.begin(), data.end(), word), data.end());
    vector_string_toLower(data);
    sort(data.begin(), data.end());

    string result = "";
    for (const auto &i : data)
        result += i + ' ';
    return result;
}