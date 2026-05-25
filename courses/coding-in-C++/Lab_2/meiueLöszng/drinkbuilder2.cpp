#include <iostream>
#include <string>

class DrinkBuilder
{
    private:
    static constexpr int DEFAULT_TEMPERATURE = 60;
    static constexpr int MAX_SUGAR =125;
    std::string name;
    int sugar;
    int temperature;
    bool withmilk;

    public:

    // Initialisierung von Standard-Startwerten
    DrinkBuilder()
    {
        name = "Unknown";
        sugar = 0;
        temperature = DEFAULT_TEMPERATURE;
        withmilk = false;
    }

    DrinkBuilder& setName (const std::string& name)
    {
        this->name = name;
        return *this;
    }


    DrinkBuilder& setSugar (int sugar)
    {
        if (sugar>=0 && sugar<=MAX_SUGAR)
        {
            this->sugar = sugar; // mot this greift man auf den aktuellen Objekt zu 
        }
        else
        {
            std::cout<<"Unvalid number of Sugar"<<std::endl;
        }

        return *this;
    }

    DrinkBuilder& setTemperature (int temperature)
    {
        if (temperature > 0)
        {
            this->temperature = temperature;
        }
        else
        {
            std::cout<<"Unvalid temperature"<<std::endl;
        }

        return *this;
    }

    DrinkBuilder& setWithMilk (bool withMilk)
    {
        this->withmilk = withMilk;
        return *this;
    }


    // const da diese nur eine Ausgabe ist und die Werte nicht veärndert bzw. modifiziert
    void print () const 
    {
        std::cout<<"Drink: "<< name <<std::endl;
        std::cout<<"Sugar: "<< sugar <<std::endl;
        std::cout<<"Temperature: "<< temperature << std::endl;
        std::cout<<"With Milk: "<< std::boolalpha << withmilk <<std::endl;
    }


    // Probe, ob die Drink Konstellation möglich bzw. valid ist

    bool isValid () const // wieder const da nichts verändert wird und lediglich geperüft wird
    {
        return temperature > 0 && sugar>= 0 && sugar <=MAX_SUGAR;
    }


};



int main ()
{
    DrinkBuilder builder;
    builder.setName("Alis").setSugar(10).setTemperature(120).setWithMilk(true).print();


    return 0;
}