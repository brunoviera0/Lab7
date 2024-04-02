#include "double_read_vector.h"
#include <sstream>


vector<double> doubles_read_one_line(istream &in_stream) {
    vector<double> result;
    double value;

    string line;
    getline(in_stream, line);
    istringstream iss(line);

    while (iss >> value) {
        result.push_back(value);
    }

    return result;
}
