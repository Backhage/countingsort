#include <algorithm>
#include <cstdint>
#include <vector>
#include "countingsort.h"

std::vector<uint16_t> countingsort(const std::vector<uint16_t>& input) {
    const int tmpSize = *std::max_element(begin(input), end(input)) + 1;

    std::vector<uint16_t> tmp(tmpSize, 0);
    for (int i = 0; i < input.size(); i++) {
        tmp[input[i]]++;
    }
    for (int i = 1; i < tmpSize; i++) {
        tmp[i] += tmp[i-1];
    }

    std::vector<uint16_t> sorted(input.size());
    for (int i = input.size()-1; i >= 0; i--) {
        sorted[--tmp[input[i]]] = input[i];
    }

    return sorted;
}
