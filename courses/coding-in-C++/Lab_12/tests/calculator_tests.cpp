#include <gtest/gtest.h>
#include "calculator.hpp"

TEST(CalculatorTest, Addition)
{
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
}

TEST(CalculatorTest, Subtraction)
{
    Calculator calc;
    EXPECT_EQ(calc.subtract(5, 3), 2);
}

TEST(CalculatorTest, Multiplication)
{
    Calculator calc;
    EXPECT_EQ(calc.multiply(4, 3), 12);
}

TEST(CalculatorTest, Division)
{
    Calculator calc;
    EXPECT_EQ(calc.divide(10, 2), 5);
}

TEST(CalculatorTest, DivisionByZero)
{
    Calculator calc;
    EXPECT_THROW(calc.divide(10, 0), std::invalid_argument);
}