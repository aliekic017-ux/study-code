#include "status_analyzer.hpp"

#include <iostream>
#include <vector>

int main()
{
    StatusAnalyzer analyzer;
    const std::vector<int> loadSamples = { 42, 57, 61, 48 };
    const double average = analyzer.averageLoad(loadSamples);

    std::cout << "Average load: " << average << "\n";
    std::cout << "Status: " << analyzer.statusMessage(average) << "\n";

    return 0;
}
