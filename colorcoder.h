#pragma once

namespace TelCoColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    class ColorPair {
    public:
        ColorPair(MajorColor major, MinorColor minor);
        MajorColor getMajorColor() const;
        MinorColor getMinorColor() const;
        std::string ToString() const;
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    std::string GetReferenceManual();
}
