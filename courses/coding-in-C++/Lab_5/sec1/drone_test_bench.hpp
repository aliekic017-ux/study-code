#ifndef DRONE_TEST_BENCH_HPP
#define DRONE_TEST_BENCH_HPP


#include <iostream>
#include <string>

// Task 1::
/*template < typename T>
void swap (T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
*/


// Task 2
template <typename T> // generische Programmierun, ersetzen des Datentyps mit T 
void printFrame(const T array[], std::size_t size)  // angeben vom Datentyp, und die Anzahl der Elemente, dann in der main.cpp
{
    std::cout << "[";

    for(std::size_t i = 0; i<size; i++)
    {
        std::cout << array[i];
        if (i < size-1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << '\n';
}

// Task 3
/*
template <typename T>
T findMinimum(const T array[], std::size_t size)
{
    T minValue = array[0];


    for (std::size_t i = 0; i < size; i++)
    {
        if (array[i] < minValue)
        {
            minValue = array[i];
        }
        
    }
    return minValue;
    
}
*/
// Task 4

template <typename T, typename U>
void verknüpfen (std::string label1, T value1, std::string label2, U value2) // die Labels sind Strings deshalb per Reference übergeben 
{
    std::cout <<label1 << ":" << value1 << "|" << label2 << ":" << value2 << '\n';
}


// Task 5
/* 
template <typename T, std::size_t N>
void printFrame (const T (&array)[N]) // Referenz auf ein Array deshalb braucht man die Klammer und das &
{
    std::cout << "[";

    for (std::size_t i = 0; i < N; i++)
    {
        std::cout << array[i];

        if (i < N-1)
        {
            std::cout <<", "; 
        }
        
    }
    std::cout <<"]" << '\n';
}

template <typename T, std::size_t N>
T findMinimum(const T (&array)[N])
{
    T minValue = array[0];

    for (std::size_t i = 1; i < N; i++)
    {
        if (array[i] < minValue)
        {
            minValue = array[i];
        }
    }

    return minValue;
}
*/
#endif 