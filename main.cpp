#include "colorcoder.h"
#include <iostream>

int main() {
    auto manual = TelCoColorCoder::GetReferenceManual();
    std::cout << "Pair No | Major Color | Minor Color\n";
    std::cout << "-------------------------------\n";
    for(const auto& entry : manual) {
        std::cout << entry.pairNumber << " | "
                  << TelCoColorCoder::MajorColorToString(entry.major) << " | "
                  << TelCoColorCoder::MinorColorToString(entry.minor) << "\n";
    }
    return 0;
}
