#include "colorcoder.h"
#include <cassert>
#include <iostream>

using namespace TelCoColorCoder;

void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.major == expectedMajor);
    assert(colorPair.minor == expectedMinor);
}

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
    int pairNumber = GetPairNumberFromColor(major, minor);
    assert(pairNumber == expectedPairNumber);
}

void runTests() {
    testNumberToPair(4, MajorColor::WHITE, MinorColor::BROWN);
    testNumberToPair(23, MajorColor::VIOLET, MinorColor::GREEN);

    testPairToNumber(MajorColor::RED, MinorColor::BLUE, 6);
    testPairToNumber(MajorColor::VIOLET, MinorColor::SLATE, 25);

    std::cout << "All tests passed!\n";
}

int main() {
    runTests();
    return 0;
}
