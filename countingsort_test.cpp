#include <cstdint>
#include <vector>
#include <gtest/gtest.h>

#include "countingsort.h"

void assertEquals(std::vector<uint16_t> expected, std::vector<uint16_t> actual) {
    for (uint16_t i = 0; i < expected.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]);
    }
}

void testCountingSort(std::vector<uint16_t> input, std::vector<uint16_t> expected) {
    const auto actual = countingsort(input);
    assertEquals(expected, actual);
}

TEST(CountingSortTests, Range) {
    testCountingSort({1}, {1});
    testCountingSort({1, 2}, {1, 2});
    testCountingSort({2, 1}, {1, 2});
    testCountingSort({1, 2, 3}, {1, 2, 3});
    testCountingSort({2, 3, 1}, {1, 2, 3});
    testCountingSort({9, 7, 8, 6, 4, 5, 3}, {3, 4, 5, 6, 7, 8, 9});
}

TEST(CountingSortTests, Gaps) {
    testCountingSort({3, 1}, {1, 3});
    testCountingSort({4, 2}, {2, 4});
    testCountingSort({5, 7, 2, 10, 67, 32}, {2, 5, 7, 10, 32, 67});
}

TEST(CountingSortTests, Duplicates) {
    testCountingSort({4, 2, 2, 4, 3}, {2, 2, 3, 4, 4});
    testCountingSort({1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1});
}
