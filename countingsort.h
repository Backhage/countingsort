#pragma once

#include <cstdint>
#include <vector>

/**
 * Counting Sort is a sorting algorithm that can sort positive integers
 * in O(n + k) where n represents the size of the input and k the maximum
 * value of the elements in the input.
 * 
 * This implementation ensures only positive integers (including zero) and
 * puts a limit on k by only accepting elements of type uint16_t (max 65535).
**/
std::vector<uint16_t> countingsort(std::vector<uint16_t> input);
