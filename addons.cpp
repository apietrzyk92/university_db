#include "addons.hpp"
#include <random>

std::array<size_t, 11> generatePESEL() {
    size_t S = 0;
    std::array<size_t, 10> w = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::array<size_t, 11> output;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    for (size_t i = 0; i < 10; i++) {
        output[i] = (size_t)distrib(gen);
        S += output[i] * w[i];
    }
    S = S % 10;
    if (S == 0) {
        output[10] = 0;
    } else {
        output[10] = 10 - S;
    }
    return output;
}
std::array<size_t, 6> generateIndex() {
    std::array<size_t, 6> output;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);
    for (size_t i = 0; i < 6; i++) {
        output[i] = (size_t)distrib(gen);
    }
    return output;
}