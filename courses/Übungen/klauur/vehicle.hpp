/*
* file:  Vehicle.hpp
* @brief define the class vehicle
*/


#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Driver;

class Vehicle
{
    private:
        static int nextID;
        int id;
        std::string brand;
        double mileage;
        bool Verfügbarkeit;
        std::string Führerschein;
        Driver *assignedDriver;
    
    public:
        Vehicle(const std::string& brand, double mileage, const std::string& Führerschein)
            :id(++nextID), brand(brand), mileage(mileage), Führerschein(Führerschein), Verfügbarkeit(true), assignedDriver(nullptr)
            {

            }

        
        
        // getter

        const std::string& getbrand () const
        {
            return brand;
        }
        double getmileage () const
        {
            return mileage;
        }
        bool isAvailable () const
        {
            return Verfügbarkeit;
        }
        const std::string& getFührerschein () const
        {
            return Führerschein;
        }
        Driver* getAssignedDriver () const
        {
            return assignedDriver;
        }
        void lendVehicle()
        {
            Verfügbarkeit = false;
        }
        void assignDriver(Driver* driver) // "jedes Fahrzeug soll wissen, welcher Fahrer aktuell zugewiesen ist"
        {
            this->assignedDriver = driver;
        }
        virtual void printInfo() const = 0;
        virtual ~Vehicle() = default;

};

class PKW : public Vehicle
{
    private: 
        double consumption;

    public:

    PKW(const std::string& brand, double mileage, const std::string& Führerschein, double consumption)
        :Vehicle(brand, mileage, Führerschein), consumption(consumption)
        {

        };
        double getConumption () const
        {
            return consumption;
        }

        void printInfo() const override;
};


class ElectricCar : public Vehicle
{
    private: 
        double capacity;
    
        public: 

        ElectricCar(const std::string& brand, double mileage, const std::string& Führerschein, double capacity)
            :Vehicle(brand, mileage, Führerschein), capacity(capacity)
            {

            };
        double getCapacity () const
        {
            return capacity;
        }

        void printInfo() const override;
};

#endif