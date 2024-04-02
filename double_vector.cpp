#include "double_vector.h"
#include <cmath>
#include <vector>

using namespace std;

double dot_product(const double_vector& one, const double_vector& two) {
    double result = 0.0;
    for (size_t i = 0; i < one.elements.size() && i < two.elements.size(); i++) {
        result += one.elements[i] * two.elements[i];
    }
    return result;
}

double magnitude(const double_vector& vec) {
    double sum = 0.0;
    for (double elem : vec.elements) {
        sum += elem * elem;
    }
    return sqrt(sum);
}

double cosine_distance(const double_vector& one, const double_vector& two) {
    double dot = dot_product(one, two);
    double mag_one = magnitude(one);
    double mag_two = magnitude(two);
    double temp = dot / (mag_one * mag_two);
    return acos(temp);
}
