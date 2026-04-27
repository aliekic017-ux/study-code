#include <iostream>
#include <cstdint>
#include <limits>

const std::uint8_t min_age_adult = 18;
const std::uint8_t min_age_senior = 65;
const int max_age = 99;

namespace validation
{ // Funktionen werden angekündigt 
    bool isAdult (std::uint8_t age);
    bool isSenior (std::uint8_t age);
}

bool validation::isAdult (std::uint8_t age)
{ // Angekündigte Funktionen werden definiert
    return age >= min_age_adult;
}

bool validation::isSenior (std::uint8_t age)
{
    return age >= min_age_senior;
}

int main ()
{
    int input_age = 0;  // beim einlesen int verwenden nicht wie oben uint8_t, da sonst der ASCII-Code der Eingabe ausgegeben wird.
    std::uint8_t validate_age = 0;


    while (true)
    {
        // Benutzer nach dem Alter fragen

        std::cout << "Pleasr enter your age: ";
        std::cin >> input_age;


        if (std::cin.fail ()) // Prüfung bei falscher Eingabe machen. Sehr wichtig!!!!
        {
            std::cout << "Not valid number entered. Try again!!. \n";
            std::cin.clear(); // Clear fail bit 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabe-Puffer wird gelöscht
        }
        else if (input_age < 0)
        {
            std::cout << "Entered negative agre. Try again!!.\n";
        }
        else if (input_age > max_age)
        {
            std::cout << "Entered too high age. Try again!!.\n";
        }
        else
        {
            validate_age = static_cast<std::uint8_t>(input_age);
            break;
        }

    }

    std::cout << "You entered: " << input_age << '\n';

    std::cout << "You are " << input_age << " years old." << '\n';

    if (validation::isSenior(validate_age))
    {
        std::cout << "That means that you are a senior citizen." << '\n';
    }
    else if (validation::isAdult(validate_age))
    {
        std::cout << "That means you are an afult." << '\n';
    }
    else
    {
        std::cout << " That means that you are still a kind or a teenager." << '\n';
    }


    return 0;

}


//Übergabe per Referenz (&), wenn man Klasssen, Strings,... einfer Funktion übergibt.
//--> per Referenz wird kein zustäzlicher Speicher belegt