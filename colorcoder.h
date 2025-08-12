#pragma once
#include <string>
#include <vector>

namespace TelCoColorCoder
{
    enum class MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET, COUNT};
    enum class MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE, COUNT};

    struct ColorPair {
        MajorColor major;
        MinorColor minor;
        ColorPair(MajorColor maj, MinorColor min) : major(maj), minor(min) {}
        std::string ToString() const;
    };

    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    ColorPair GetColorFromPairNumber(int pairNumber);

    std::string MajorColorToString(MajorColor major);
    std::string MinorColorToString(MinorColor minor);

    struct ReferenceEntry {
        int pairNumber;
        MajorColor major;
        MinorColor minor;
    };
    std::vector<ReferenceEntry> GetReferenceManual();
}
