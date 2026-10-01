#include <iostream>
#include <string>
#include <vector>


class Vehicle
{
    protected: // jedes Auto soll eine ID und eine Marke haben
    // protected weil die Unterklassen darauf zugreifen dürfen, mit private würde es nicht gehen
        int id;
        std::string brand;

    public:

        Vehicle(int id, const std::string& brand) // das ist der sogenannte Konstruktor
        // damit werden die Attribute initilisiert
            : id(id), brand(brand)
        {
        }

        virtual void printInfo() const = 0; // das macht die Klasse abstrakt
        
        virtual ~Vehicle() = default;

};

//2. abgeleitete Klasse


class Car : public Vehicle
{
    private:
        double fuelConsumption;
        
    public:
        Car(int id, const std::string& brand, double fuelConsumption)
            : Vehicle(id, brand), fuelConsumption(fuelConsumption)
            {

            }

        // printINfo ist einfach eine Methode, um INformationen über das Objekt zu sagen
        void printInfo() const override // Methode wird überschrieben mit Override
        {

            std::cout << "Car ID: " << id << std::endl;
            std::cout << "Brand: " << brand << std::endl;
            std::cout << "Fuel Consumption: " << fuelConsumption << std::endl;

        };

};

class ElectricCar : public Vehicle
{
    private:
        double batteryCapacity;

    
    public:
        ElectricCar(int id, const std::string& brand, double batteryCapacity)
            : Vehicle(id, brand), batteryCapacity(batteryCapacity)
            {

            }
        // const std, da man keine Kopie erstellen will und den string auch nicht verändern will- !!!!wichtig!! 

        void printInfo() const override // const weil es nichts verändert sondern nur Informationen ausgibt
        {
            std::cout << "Electric - Car ID:" << id << std::endl;
            std::cout << "Brand: " << brand << std::endl;
            std::cout << "Battery Capacity: " << batteryCapacity << std::endl;

        }
};

class Driver
{
    private: 
        std::string name;
        Vehicle* currentVehicle; // jeder Fahrer soll ein aktuelles Fahrzeug kennen 

    public:
        Driver(const std::string& name)
            : name(name), currentVehicle(nullptr)
            {

            }
        
        void zuweisenVehicle (Vehicle* vehicle)
        {
            currentVehicle = vehicle;
        }

        void printDriverInfo() const
        {
            std::cout << "Driver: " << name << std::endl;
                if (currentVehicle != nullptr)
                {
                    currentVehicle->printInfo(); 
                    // wenn der Fahrer ein Fahrzeug hat dann kommt entweder Car::printInfo oder ElectricCar::printInfo
                    // je nachdem ob er ein normales Auto hat oder ein Electric Car
                }
                else
                {
                    std::cout << "Dem Fahrer wurde noch kein Fahrzeug zugewiesen." << std::endl;
                }
                
        }
};


int main ()
{
    Car car(1, "Mercedes", 6.7);
    ElectricCar elekcar(2, "Tesla", 67);
    Driver nr1("Ali");


    nr1.zuweisenVehicle(&car);
    nr1.printDriverInfo();

    // wir wollen später viele verschiedene Fhrzeugtypen speichern, deshalb verwenden wir std::vector<Vehicle*>
    // Car ist ein Vehicle, da es davon erbt, Electriccar erbt ebenso von Vehicle, deshalb können wir alles gemeinsam speichern

    std::vector<Vehicle*> vehicles;

    vehicles.push_back(&car);
    vehicles.push_back(&elekcar);

    for (Vehicle* vehicle : vehicles)
    {
        vehicle->printInfo();
        std::cout << std::endl;
    }


    return 0;
}
