#ifndef TEMPERATURE_STATS_HPP
#define TEMPERATURE_STATS_HPP

#include <string>
#include <vector>

double averageTemperature(const std::vector<int>& values);
int highestTemperature(const std::vector<int>& values);
std::string classifyTemperature(int value);
bool containsCriticalTemperature(const std::vector<int>& values);

#endif
