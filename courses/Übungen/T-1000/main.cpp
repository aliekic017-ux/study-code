/*
*
* file: main.cpp
* @brief. ganzes Projekt fertigstellen und validieren
*
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "projekt.hpp"
#include "mitarbeiter.hpp"
#include "team.hpp"


void Mitarbeiter::setName(const std::string& name)
{
    this->name = name;
}

const std::vector<std::string>& Mitarbeiter::getQualifikationen() const
{
    return qualifikationen;
}

void Mitarbeiter::addQualifaktionen(const std::string& qualifikation)
{
    this->qualifikationen.push_back(qualifikation);
}

void Mitarbeiter::removeQualifikationen(const std::string& qualifakation)
{
    auto it = std::find(qualifikationen.begin(), qualifikationen.end(), qualifakation);
    if (it != qualifikationen.end())
    {
        qualifikationen.erase(it);
    }
    

}


void Team::addMitarbeiter(Mitarbeiter* mitarbeiter)
{
    this->mitarbeiter.push_back(mitarbeiter);
}

void Team::removeMitarbeiter(Mitarbeiter* mitarbeiter)
{
    auto it = std::find(this->mitarbeiter.begin(),
                        this->mitarbeiter.end(),
                        mitarbeiter);

    if (it != this->mitarbeiter.end())
    {
        this->mitarbeiter.erase(it);
    }
}

void Team::addProjekte(Projekt* projekt)
{
    this->projekte.push_back(projekt);
}

void Team::removeProjekte(Projekt* projekt)
{
    auto it = std::find(this->projekte.begin(),
                        this->projekte.end(),
                        projekt);

    if (it != this->projekte.end())
    {
        this->projekte.erase(it);
    }
}

void Softwareprojekt::printInfo() const
{
    std::cout << std::setw(20) << "Type:" << std::setw(20) << "Softwareprojekt" << std::endl;
    std::cout << std::setw(20) << "Titel:" << std::setw(20) << getTitel() << std::endl;
    std::cout << std::setw(20) << "Status:" << std::setw(20) << getStatus() << std::endl;
    std::cout << std::setw(20) << "Sprache:" << std::setw(20) << getProgrammiersprache() << std::endl;
}

void Hardwareprojekt::printInfo() const
{
    std::cout << std::setw(20) << "Type:" << std::setw(20) << "Hardwareprojekt" << std::endl;
    std::cout << std::setw(20) << "Titel:" << std::setw(20) << getTitel() << std::endl;
    std::cout << std::setw(20) << "Status:" << std::setw(20) << getStatus() << std::endl;
    std::cout << std::setw(20) << "Testgeraete:" << std::setw(20) << getAnzahlTestgeräte() << std::endl;
}

int Projekt::nextId = 0;
int Mitarbeiter::nextId = 0;

int main()
{
    Softwareprojekt software1("Diagnosesoftware", 1, "C++");
    Softwareprojekt software2("Webportal", 2, "Java");

    Hardwareprojekt hardware1("Sensorpruefstand", 1, 5);

    std::vector<std::string> aliQualifikationen;
    aliQualifikationen.push_back("C++");
    aliQualifikationen.push_back("Embedded");

    std::vector<std::string> ezgiQualifikationen;
    ezgiQualifikationen.push_back("Java");
    ezgiQualifikationen.push_back("Testing");

    Mitarbeiter ali("Ali", aliQualifikationen);
    Mitarbeiter ezgi("Ezgi", ezgiQualifikationen);

    Team team1("Fahrzeugelektronik");

    team1.addMitarbeiter(&ali);
    team1.addMitarbeiter(&ezgi);

    team1.addProjekte(&software1);
    team1.addProjekte(&software2);
    team1.addProjekte(&hardware1);

    ali.addQualifaktionen("Python");
    ali.removeQualifikationen("Embedded");

    std::vector<Projekt*> alleProjekte;

    alleProjekte.push_back(&software1);
    alleProjekte.push_back(&software2);
    alleProjekte.push_back(&hardware1);

    for (Projekt* projekt : alleProjekte)
    {
        std::cout << "----------------------------------------" << std::endl;
        projekt->printInfo();
    }

    return 0;
}