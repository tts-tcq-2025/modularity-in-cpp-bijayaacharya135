#include "colorcoder.h"
#include <sstream>
#include <stdexcept>

namespace TelCoColorCoder
{
    static const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    static const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    static constexpr int numberOfMajorColors = static_cast<int>(MajorColor::COUNT);
    static constexpr int numberOfMinorColors = static_cast<int>(MinorColor::COUNT);

    std::string MajorColorToString(MajorColor major) {
        return MajorColorNames[static_cast<int>(major)];
    }
    std::string MinorColorToString(MinorColor minor) {
        return MinorColorNames[static_cast<int>(minor)];
    }

    std::string ColorPair::ToString() const {
        std::ostringstream oss;
        oss << MajorColorToString(major) << " " << MinorColorToString(minor);
        return oss.str();
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return static_cast<int>(major) * numberOfMinorColors + static_cast<int>(minor) + 1;
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        if(pairNumber < 1 || pairNumber > numberOfMajorColors * numberOfMinorColors)
            throw std::out_of_range("Pair number out of range");
        int zeroBased = pairNumber - 1;
        MajorColor major = static_cast<MajorColor>(zeroBased / numberOfMinorColors);
        MinorColor minor = static_cast<MinorColor>(zeroBased % numberOfMinorColors);
        return ColorPair(major, minor);
    }

    std::vector<ReferenceEntry> GetReferenceManual() {
        std::vector<ReferenceEntry> manual;
        for(int i = 1; i <= numberOfMajorColors * numberOfMinorColors; ++i) {
            ColorPair pair = GetColorFromPairNumber(i);
            manual.push_back({i, pair.major, pair.minor});
        }
        return manual;
    }
}
