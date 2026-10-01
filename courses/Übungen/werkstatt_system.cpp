#include <iostream>
#include <vector>
#include <string>


class Vehicle
{
    protected:
        int id;
        std::string marke;
        int kilometerstand;

    public:
        Vehicle(int id, const std::string& marke, int kilometerstand)
            : id(id), marke(marke), kilometerstand(kilometerstand)
            {

            }

        int getId () const
        {
            return id;
        }

        std::string getMarke () const 
        {
            return marke;
        }

        int getKilometerstand () const
        {
            return kilometerstand;
        }

        void setKilometerstand (int neuerKilometerstand)
        {
            kilometerstand = neuerKilometerstand;
        }

        virtual void printInfo() const = 0; // --> das macht die Klasse Vehicle abstrakt

        virtual ~Vehicle() = default;
};

class Motor
{
    private: 
        int seriennummer;
        int leistungKW;

    public:
        Motor(int seriennummer, int leistungKW)
            :seriennummer(seriennummer), leistungKW(leistungKW)
            {

            }

        void printMotorINfo () const
        {
            std::cout << "Das Motorrad mit der Seriennummer: " << seriennummer << " hat eine Leistung von: " << leistungKW << " PS" << std::endl;

        }
};

class Auto : public Vehicle
{
    private: 
        int anzahltueren;
        Motor motor;
    
    public: 
        Auto(int id, const std::string& marke, int kilometerstand, int anzahltueren, const Motor& motor)
            :Vehicle(id , marke , kilometerstand), anzahltueren(anzahltueren), motor(motor)
            {

            }

        void printInfo () const override
        {
            std::cout << "Auto ID: " << id << std::endl;
            std::cout << "Marke: " << marke << std::endl;
            std::cout << "Kilometerstand: " << kilometerstand << std::endl;
            std::cout << "Anzahl der vorhanden Türen beim Fahrzeug: " << anzahltueren << std::endl;
            motor.printMotorINfo();
        }
};

class Motorrad : public Vehicle
{
    private:
        int höchstgeschwindigkeit;
        Motor motor;

    public:
        Motorrad(int id, const std::string& marke, int kilometerstand, int höchstgeschwindigkeit, const Motor& motor)
            :Vehicle(id, marke, kilometerstand), höchstgeschwindigkeit(höchstgeschwindigkeit), motor(motor)
            {

            }

        void printInfo () const override
        {
            std::cout << "Motorrad ID: " << id << std::endl;
            std::cout << "Marke: " << marke << std::endl;
            std::cout << "Kilometerstand: " << kilometerstand << std::endl;
            std::cout << "Die Höchstgeschwindigkeitn des Motorrads ist: " << höchstgeschwindigkeit << " kmh" << std::endl;
            motor.printMotorINfo();
        }
        
};

class Mechaniker
{
    private:
        std::string name;
        int personalnummer;

        std::vector<Vehicle*> fahrzeuge;
    
    public:
        Mechaniker(const std::string& name, int personalnummer)
            :name(name), personalnummer(personalnummer)
            {

            }
        
        void zuweisenFahrzeug (Vehicle* fahrzeug) // Mechaniker kennt mehrere Fahrzeuge
        {
            fahrzeuge.push_back(fahrzeug);
        }

        void zugewieseneFahrzeugeAusgeben () const
        {
            std::cout << "Mechaniker: " << name << std::endl;
            for (Vehicle* fahrzeug : fahrzeuge)
            {
                fahrzeug->printInfo();
                std::cout << std::endl;
            }
        }
};

int main ()
{
    Motor motor1 (1001, 150);
    Motor motor2 (2001, 120);

    Auto auto1 (1, "Mercedes", 85000, 4, motor1);
    Motorrad motorrad1 (2, "BMW", 25000, 280, motor2);

    Mechaniker mech1("Ali", 1234);
    mech1.zuweisenFahrzeug(&auto1);
    mech1.zuweisenFahrzeug(&motorrad1);

    std::cout << " Fahrzeuge des Mechanikers " << std::endl;
    mech1.zugewieseneFahrzeugeAusgeben();

    std::cout << std::endl;

    std::cout << " -- Polymorphismus --" << std::endl;
    std::vector<Vehicle*> fahrzeuge;

    fahrzeuge.push_back(&auto1);
    fahrzeuge.push_back(&motorrad1);

    for (Vehicle* fahrzeug : fahrzeuge)
    {
        fahrzeug->printInfo();
        std::cout << std::endl;
    }

    return 0;
}
