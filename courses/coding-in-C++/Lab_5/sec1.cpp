/**
 * @file vector2d.cpp
 * @brief Implementation of a 2D vector class with operator overloading.
 */
#include <iostream>
#include <cmath>

/**
 * @class Vector2D
 * @brief Represents a 2D vector with x and y coordinates.
 */
class Vector2D
{
private:
    double x;
    double y;

public:
    /**
     * @brief Default constructor.
     * Initializes vector to (0.0, 0.0).
     */
    Vector2D() : x(0.0), y(0.0) {}

    /**
     * @brief Parameterized constructor.
     * @param[in] x_value X coordinate
     * @param[in] y_value Y coordinate
     */
    Vector2D(double x, double y) : x(x), y(y) {}


    double getX() const { return x; }


    double getY() const { return y; }


    void print() const
    {
        std::cout << '\n'
                  << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
    }

    // Betrag berechnen
    double magnitude () const
    {
        return sqrt((x * x) + (y * y));
    }


    double round ()
    {
        double factor = std::pow(10.0, precision);
        return std::round(value * factor) / factor;
    }


    Vector2D::Vector2D operator+(Vector2D& v1 , Vector2D &v2)
    {
         
    }


    int main()
    {
        int precision = 0;
        int value = 0;


        Vector2D v1(3.2, 4.2);


        return 0;
    }