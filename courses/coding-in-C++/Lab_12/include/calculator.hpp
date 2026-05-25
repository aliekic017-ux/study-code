#pragma once

class Calculator
{
public:
    int add(int a, int b) const;
    int subtract(int a, int b) const;
    int multiply(int a, int b) const;

    // einfache Division (keine float, absichtlich simpel fürs Lab)
    int divide(int a, int b) const;
};