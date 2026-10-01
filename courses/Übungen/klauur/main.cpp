/*
*
* file: main.cpp
* @brief Main function of the car management system in cpp
*
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "driver.hpp"
#include "vehicle.hpp"

int Vehicle::nextID = 0;
int Driver::nextId = 0;

//Methode, um Führerscheine zu löschen
void Driver::removeLIcense (const std::string& licenseToRemove)
{
    auto it = std::find(licenses.begin(), licenses.end(), licenseToRemove);
    // wenn die richtige Führerscheinklasse gefunden wurde, erasen
    if (it != licenses.end())
    {
        licenses.erase(it);
    }
    
};

void Driver::lendVehicle (Vehicle* vehicleToLend)
{
    //schauen ob der Fahre noch kien Fahrzeug ausgeleihen hat

    if (this->assignedVehicle != nullptr) // aktuell zugewiesesne Fahrzeug assignedVehicle
    {
        std::cout << "Fehler: Fahrer hat schon ein zugewiesenes Fahrzeug" << std::endl;
        return;
    }

    // checken ob Fahrzeug frei ist?? webnn er noch kein fahrzeug zugeiwesn hat auf ihn

    if (vehicleToLend->isAvailable())
    {
        // checken ob führerscheinjlasse ausreichend ist 
        if (std::find(licenses.begin(), licenses.end(), vehicleToLend->getFührerschein()) != licenses.end() )
        {
            // wenn führerschein ausreichend, dann fahrezeug dem fahrer zuweisen
            this->assignedVehicle = vehicleToLend;
            vehicleToLend->lendVehicle();
            vehicleToLend->assignDriver(this);
        }
        else
        {
            std::cout << "Führerscheinklasse nicht ausreichendfür das auszuleihende Fahrzeug" << std::endl;
        }
    }
    else
    {
        std::cout << "Fahrzeig ist nicht avaialable" << std::endl;
    }
    
}

void PKW::printInfo() const
{
    std::cout << std::setw(20) << "Type:" << std::setw(20) << "PKW" << std::endl;
    std::cout << std::setw(20) << "Brand:" << std::setw(20) << this->getbrand() << std::endl;
    std::cout << std::setw(20) << "Consumption:" << std::setw (20) << this->getConumption() << std::endl;
    std::cout << std::setw(20) << "Available:" << std::setw(20) << std::boolalpha << this->isAvailable() <<std::endl;
    std::cout << std::setw(20) << "Mileage:" << std::setw(20) << this->getmileage() << std::endl;
    std::cout << std::setw(20) << "Needed License:" << std::setw(20) << this->getFührerschein()<<std::endl;
    std::cout << std::setw(20) << "Assigned Driver:" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getNAme())<<std::endl;

}

void ElectricCar::printInfo() const
{
    std::cout << std::setw(20) << "Type:" << std::setw(20) << "ElectricCar" << std::endl;
    std::cout << std::setw(20) << "Brand:" << std::setw(20) << this->getbrand() << std::endl;
    std::cout << std::setw(20) << "Capacity:" << std::setw(20) << this->getCapacity() << std::endl;
    std::cout << std::setw(20) << "Available:" << std::setw(20) << std::boolalpha << this->isAvailable() << std::endl;
    std::cout << std::setw(20) << "Mileage:" << std::setw(20) << this->getmileage() << std::endl;
    std::cout << std::setw(20) << "Needed License:" << std::setw(20) << this->getFührerschein() << std::endl;
    std::cout << std::setw(20) << "Assigned Driver:" << std::setw(20) << ((this->getAssignedDriver() == nullptr) ? "None" : this->getAssignedDriver()->getNAme()) << std::endl;
}

int main()
{
    // fahrzeuge erstellen 

PKW pkw1 ("Mercedes", 333, "B", 6.3);
PKW pkw2 ("Porsche", 432, "B", 4.7);

ElectricCar elec2 ("Tesla", 232, "B", 75);
ElectricCar elec1 ("BYD", 2422, "B", 75);

    // führerscheine anlegen
std::vector <std::string> driver1Licenses;
driver1Licenses.push_back("B"); //  mit Pushback wird ein NEUes Element hinten am Vektor angehängt 
driver1Licenses.push_back("C1");

    // Fahrer anlegen

Driver driver11 ("Ezgi", driver1Licenses);

pkw1.printInfo();
std::cout << "--------------------------------------------------------" << std::endl;

driver11.lendVehicle(&pkw1);

pkw1.printInfo();

driver11.lendVehicle(&elec2);

// alle angelegten Fahrzeuge müssen in Vehicle* abgelegt werden um die Ausgabe aller Informationen zu den allen Fahrzeugen schenll und leicht zu machen ohne eine großen Aufwand
std::vector<Vehicle*> alles;
alles.push_back(&pkw1);
alles.push_back(&pkw2);
alles.push_back(&elec2);
alles.push_back(&elec1);


for(auto curVehicle : alles)
{
    std::cout << " -----------------------------------------" <<std::endl;
    curVehicle->printInfo();
}
}