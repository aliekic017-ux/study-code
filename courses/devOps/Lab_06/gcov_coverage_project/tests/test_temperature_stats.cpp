#include "temperature_stats.hpp"

#include <cassert>
#include <cmath>
#include <string>
#include <vector>

int main()
{
    const std::vector<int> roomTemperatures = { 20, 21, 22, 23 };

    assert(std::fabs(averageTemperature(roomTemperatures) - 21.5) < 0.001);
    assert(highestTemperature(roomTemperatures) == 23);
    assert(classifyTemperature(16) == "LOW");
    assert(classifyTemperature(22) == "NORMAL");

    return 0;
}
