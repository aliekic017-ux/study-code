#include "temperature_stats.hpp"

#include <stdexcept>

double averageTemperature(const std::vector<int>& values)
{
    if (values.empty())
    {
        throw std::invalid_argument("values must not be empty");
    }

    int sum = 0;
    for (int value : values)
    {
        sum += value;
    }

    return static_cast<double>(sum) / static_cast<double>(values.size());
}

int highestTemperature(const std::vector<int>& values)
{
    if (values.empty())
    {
        throw std::invalid_argument("values must not be empty");
    }

    int highest = values.front();
    for (int value : values)
    {
        if (value > highest)
        {
            highest = value;
        }
    }

    return highest;
}

std::string classifyTemperature(int value)
{
    if (value < 18)
    {
        return "LOW";
    }

    if (value <= 25)
    {
        return "NORMAL";
    }

    return "HIGH";
}

bool containsCriticalTemperature(const std::vector<int>& values)
{
    for (int value : values)
    {
        if (value < -20 || value > 80)
        {
            return true;
        }
    }

    return false;
}
