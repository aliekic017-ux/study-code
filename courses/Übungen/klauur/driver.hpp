/*
*
* file: driver.hpp
* @brief: deklaration off the class driver for the car management systeme
*
*/

#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <string>
#include <vector>
#include "vehicle.hpp"
#include <algorithm>

class vehicle;

class Driver
{
    private:
        static int nextId;

        const int id;
        std::string name;
        std::vector<std::string> licenses;
        Vehicle* assignedVehicle;

    public:
        Driver(const std::string& name, const std::vector<std::string>& licenses)
            :id(++nextId), name(name), licenses(licenses), assignedVehicle(nullptr)
            {

            };

        // setter und getter 


        int getId () const
        {
            return id;
        }

        std::string getNAme () const
        {
            return name;
        }


        void setName (const std::string& name)
        {
            this->name = name;
        }

        const std::vector<std::string>& getLicenses () const
        {
            return this->licenses;
        }
        void addNewLicense(const std::string& newLicense) // methode um neue Führerschienklassen für den Fahrer anuzulegen
        {
            licenses.push_back (newLicense);
        }
        void removeLIcense (const std::string& licenseToRemove); // methode um bestehende führerscheine zu löschen 
        void lendVehicle (Vehicle* vehicleToLend); // methode um das ein Fahrer ein Fahrzeug ausleihen kann.
};



#endif 