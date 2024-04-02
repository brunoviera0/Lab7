#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"
#include <vector>

using namespace std;
using namespace doctest;

TEST_CASE("3D Vector Cosine (1, 2.5, 0.5) & (1, 3.6, 1.9)") {
    vector<double> vec1 = {1, 2.5, 0.5};
    vector<double> vec2 = {1, 3.6, 1.9};
    double_vector v1(vec1, 0);
    double_vector v2(vec2, 1);
    CHECK(Approx(cosine_distance(v1, v2)).epsilon(0.001) == 0.3049);
}

TEST_CASE("3D Vector Cosine (1, 1, 1) & (1, 1, 0)") {
    vector<double> vec1 = {1, 1, 1};
    vector<double> vec2 = {1, 1, 0};
    double_vector v1(vec1, 2);
    double_vector v2(vec2, 3);
    CHECK(Approx(cosine_distance(v1, v2)).epsilon(0.001) == 0.61548);
}

TEST_CASE("5D Vector Cosine (1, 1, 1, 1, 1) & (1, 1, 1, 1, 0)") {
    vector<double> vec1 = {1, 1, 1, 1, 1};
    vector<double> vec2 = {1, 1, 1, 1, 0};
    double_vector v1(vec1, 4);
    double_vector v2(vec2, 5);
    CHECK(Approx(cosine_distance(v1, v2)).epsilon(0.001) == 0.463648);
}

TEST_CASE("5D Vector Cosine (1, 2.5, 0.5, 0.99, 1.5) & (1, 3.6, 1.9, 0.98, -4)") {
    vector<double> vec1 = {1, 2.5, 0.5, 0.99, 1.5};
    vector<double> vec2 = {1, 3.6, 1.9, 0.98, -4};
    double_vector v1(vec1, 6);
    double_vector v2(vec2, 7);
    CHECK(Approx(cosine_distance(v1, v2)).epsilon(0.001) == 1.2582);
}
