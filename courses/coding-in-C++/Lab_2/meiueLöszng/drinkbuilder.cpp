#include <iostream>
#include <string>

class DrinkBuilder
{
private:

    // Attribute der Klasse
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;

    // constexpr:
    // Diese Werte sind bereits zur Compile-Zeit bekannt
    // und können als Standardwerte verwendet werden
    static constexpr int DEFAULT_TEMPERATURE = 60;
    static constexpr int MAX_SUGAR = 10;

    // was bringt das mit static??
public:

    // Konstruktor:
    // Setzt sinnvolle Startwerte
    DrinkBuilder()
    {
        name = "";
        sugar = 0;

        // Initialisierung mit constexpr Wert
        temperature = DEFAULT_TEMPERATURE;

        withMilk = false;
    }

    // Method Chaining:
    // Rückgabe von *this ermöglicht:
    // builder.setName(...).setSugar(...)

    DrinkBuilder& setName(const std::string& newName)
    {
        name = newName;

        // *this = aktuelles Objekt
        return *this;
    }

    DrinkBuilder& setSugar(int newSugar)
    {
        // Prüfung auf ungültige Werte
        if (newSugar >= 0 && newSugar <= MAX_SUGAR)
        {
            sugar = newSugar;
        }
        else
        {
            std::cout << "Invalid sugar amount."
                      << std::endl;
        }

        return *this;
    }

    DrinkBuilder& setTemperature(int newTemperature)
    // durch & rückgabe vom Originalen..
    {
        // Temperatur darf nicht negativ oder 0 sein
        if (newTemperature > 0)
        {
            temperature = newTemperature;
        }
        else
        {
            std::cout << "Temperature must be greater than 0."
                      << std::endl;
        }

        return *this;
        // man muss immer bei Method chaining die refernez übergeben, um mit dem Originalen zu arbeiten.,
    }

    DrinkBuilder& setWithMilk(bool milk)
    {
        withMilk = milk;

        return *this;
    }

    // const:
    // Diese Methode verändert das Objekt NICHT
    bool isValid() const
    {
        return temperature > 0 &&
               sugar >= 0 &&
               sugar <= MAX_SUGAR;
    }

    // Ebenfalls const, da nur Ausgabe
    void print() const
    {
        std::cout << "Drink: "
                  << name
                  << std::endl;

        std::cout << "Sugar: "
                  << sugar
                  << std::endl;

        std::cout << "Temperature: "
                  << temperature
                  << std::endl;

        std::cout << "With milk: ";

        // bool schön als Text ausgeben
        if (withMilk)
        {
            std::cout << "true";
        }
        else
        {
            std::cout << "false";
        }

        std::cout << std::endl;
    }
};

int main()
{
    // Objekt erzeugen
    DrinkBuilder builder;

    // Method Chaining:
    // Jede Methode gibt Referenz auf dasselbe Objekt zurück
    builder.setName("Tea")
           .setSugar(2)
           .setTemperature(65)
           .setWithMilk(true)
           .print();

    // Prüfen ob Konfiguration gültig ist
    if (builder.isValid())
    {
        std::cout << "Drink configuration is valid."
                  << std::endl;
    }
    else
    {
        std::cout << "Drink configuration is invalid."
                  << std::endl;
    }

    return 0;
}