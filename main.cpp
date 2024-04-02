#include "double_vector.h"
#include "double_read_vector.h"
#include <fstream>
#include <algorithm>
#include <iostream>

#include "double_vector.h"
#include "double_read_vector.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    vector<double_vector> vectors;
    while (!file.eof()) {
    vector<double> elements = doubles_read_one_line(file);
    if (!elements.empty()) {
        vectors.emplace_back(elements, 0); // Pass a second argument for the id
    }
}

    vector<pair<double, pair<int, int>>> distances;
    for (size_t i = 0; i < vectors.size(); i++) {
        for (size_t j = i + 1; j < vectors.size(); j++) {
            double dist = cosine_distance(vectors[i], vectors[j]);
            distances.emplace_back(dist, make_pair(i, j));
        }
    }

    sort(distances.begin(), distances.end()); //sort cos distances so they're in order

    for (const auto& dist : distances) {
        cout << dist.second.first << " and  " << dist.second.second
             << " cos dist = " << dist.first << endl;
    }

    return 0;
}
