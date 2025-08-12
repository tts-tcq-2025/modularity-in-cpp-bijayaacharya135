#include "colorcoder.h"
#include <sstream>
#include <stdexcept>

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    const int numberOfMajorColors = 5;
    const int numberOfMinorColors = 5;

    ColorPair::ColorPair(MajorColor major, MinorColor minor)
        : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajorColor() const { return majorColor; }
    MinorColor ColorPair::getMinorColor() const { return minorColor; }

    std::string ColorPair::ToString() const {
        std::ostringstream oss;
        oss << MajorColorNames[majorColor] << " " << MinorColorNames[minorColor];
        return oss.str();
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        if(pairNumber < 1 || pairNumber > numberOfMajorColors * numberOfMinorColors)
            throw std::out_of_range("Pair number out of range");
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor major = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(major, minor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    std::string GetReferenceManual() {
        std::ostringstream oss;
        oss << "Pair No | Major Color | Minor Color\n";
        oss << "-------------------------------\n";
        for(int i = 1; i <= numberOfMajorColors * numberOfMinorColors; ++i) {
            ColorPair pair = GetColorFromPairNumber(i);
            oss << i << " | " << MajorColorNames[pair.getMajorColor()]
                << " | " << MinorColorNames[pair.getMinorColor()] << "\n";
        }
        return oss.str();
    }
}
