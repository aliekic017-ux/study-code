/*
*
* file: main.cpp
* @brief: Main-Funktion, Definition der Funktionen der Mitarbieter
*
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "mitarbeiter.hpp"
#include "raum.hpp"

int Raum::nextId = 0;
int Mitarbeiter::nextId = 0;

void Mitarbeiter::removeBerechtigungen(const std::string& entnehmenDerBerechtigung)
{
    auto it = std::find(berechtigungen.begin(), berechtigungen.end(), entnehmenDerBerechtigung);
    if (it != berechtigungen.end())
    {
        berechtigungen.erase(it);
    }
    
}

void Mitarbeiter::raumBuchen (Raum *raum)
{
    if (this->gebuchterRaum!= nullptr)
    {
        std::cout << "Mitarbeiter hat schon ein Raum gebucht" << std::endl;
        return;
    }

    if (raum->istVerfügbar())
    {
        if (std::find(berechtigungen.begin(), berechtigungen.end(), raum->getBerechtigung()) != berechtigungen.end())
        {
            this->gebuchterRaum = raum;
            raum->buchen();
            raum->mitarbeiterZuweisen(this);
        }
        else
        {
            std::cout << " Die Berechtigung reicht nicht aus" << std::endl;
        }
        
    }
    else
    {
        std::cout << "Raum ist nicht verfügbar" << std::endl;
    }
}

void MeetingRaum::printInfo() const
{
    std::cout << std::setw (20) << " Type: " << std::setw (20) << "Meeting Raum" << std::endl;
    std::cout << std::setw (20) << " Name: " << std::setw (20) << getName() << std::endl;
    std::cout << std::setw (20) << " Kapazität: " << std::setw(20) << getkapazität() << std::endl;
    std::cout << std::setw (20) << " Verfügbarkeit: " << std::setw(20) << std::boolalpha << istVerfügbar() << std::endl;
    std::cout << std::setw (20) << " Berechtigung: " << std::setw(20) << getBerechtigung() << std::endl;
    std::cout << std::setw (20) << " Beamer: " << std::setw(20) << std::boolalpha << getHasProjector() << std::endl;
    std::cout << std::setw (20) << "Reservierter Mitarbeiter" << std::setw(20) << ((getZugewiesenerMitarbeiter() == nullptr) ? "None" : getZugewiesenerMitarbeiter()->getName()) << std::endl;
}

void LaborRaum::printInfo() const
{
    std::cout << std::setw (20) << " Type: " << std::setw (20) << "Labor Raum" << std::endl;
    std::cout << std::setw (20) << " Name: " << std::setw (20) << getName() << std::endl;
    std::cout << std::setw (20) << " Kapazität: " << std::setw(20) << getkapazität() << std::endl;
    std::cout << std::setw (20) << " Verfügbarkeit: " << std::setw(20) << std::boolalpha << istVerfügbar() << std::endl;
    std::cout << std::setw (20) << " Berechtigung: " << std::setw(20) << getBerechtigung() << std::endl;
    std::cout << std::setw (20) << " Safety Level: " << std::setw(20) << getSafetyLevel() << std::endl;
    std::cout << std::setw (20) << "Reservierter Mitarbeiter" << std::setw(20) << ((getZugewiesenerMitarbeiter() == nullptr) ? "None" : getZugewiesenerMitarbeiter()->getName()) << std::endl;
}

int main()
{
    // Räume erstellen

    MeetingRaum meeting1("Besprechungsraum A", 10, "Office");
    MeetingRaum meeting2("Besprechungsraum B", 20, "Management");

    LaborRaum labor1("Elektroniklabor", 15, "Labor", 3);
    LaborRaum labor2("Chemielabor", 8, "Labor", 5);

    // Berechtigungen anlegen

    std::vector<std::string> berechtigungen;

    berechtigungen.push_back("Office");
    berechtigungen.push_back("Labor");

    // Mitarbeiter erstellen

    Mitarbeiter mitarbeiter1("Ezgi", berechtigungen);

    // Ausgabe vor der Buchung

    meeting1.printInfo();

    std::cout << "----------------------------------------" << std::endl;

    // Raum buchen

    mitarbeiter1.raumBuchen(&meeting1);

    // Ausgabe nach der Buchung

    meeting1.printInfo();

    std::cout << "----------------------------------------" << std::endl;

    // Versuch einen zweiten Raum zu buchen

    mitarbeiter1.raumBuchen(&labor1);

    // Polymorphismus

    std::vector<Raum*> alleRaeume;

    alleRaeume.push_back(&meeting1);
    alleRaeume.push_back(&meeting2);
    alleRaeume.push_back(&labor1);
    alleRaeume.push_back(&labor2);

    // Alle Räume ausgeben

    for (Raum* raum : alleRaeume)
    {
        std::cout << "----------------------------------------" << std::endl;
        raum->printInfo();
    }

    return 0;
}