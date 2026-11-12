#include "status_analyzer.hpp"

#include <stdexcept>

double StatusAnalyzer::averageLoad(const std::vector<int>& samples) const
{
    if (samples.empty())
    {
        throw std::invalid_argument("samples must not be empty");
    }

    int total = 0;
    for (int sample : samples)
    {
        total += sample;
    }

    return static_cast<double>(total) / static_cast<double>(samples.size());
}

bool StatusAnalyzer::isOverloaded(double averageLoad) const
{
    return averageLoad >= 80.0;
}

std::string StatusAnalyzer::statusMessage(double averageLoad) const
{
    if (isOverloaded(averageLoad))
    {
        return "OVERLOADED";
    }

    return "OK";
}
