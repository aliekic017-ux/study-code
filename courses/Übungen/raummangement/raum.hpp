/*
*
* file: raum.hpp
* @brief: Anlegen und deklarieren der abstrakten Basisklasse Raum und der abgeleiteten Klassen
*
*/
#ifndef RAUM_HPP
#define RAUM_HPP

#include <string>

class Mitarbeiter; 

class Raum
{
    private: 
        static int nextId;
        int id;
        std::string name;
        int kapazität; 
        bool verfügbarkeit;
        std::string berechtigung;
        Mitarbeiter* zugewiesenerMitarbeiter;

    public:
        Raum(const std::string& name, int kapazität, std::string berechtigung)
            :id(++nextId), name(name), kapazität(kapazität), verfügbarkeit(true), berechtigung(berechtigung), zugewiesenerMitarbeiter(nullptr)
            {

            };

        int getId () const
        {
            return id;
        }

        const std::string& getName () const
        {
            return name;
        }

        void setName (const std::string& name)
        {
            this->name = name;
        }

        int getkapazität () const
        {
            return kapazität;
        }

        bool istVerfügbar () const
        {
            return verfügbarkeit;
        }
        const std::string& getBerechtigung () const
        {
            return berechtigung;
        }
        Mitarbeiter* getZugewiesenerMitarbeiter () const
        {
            return zugewiesenerMitarbeiter;
        }
        void buchen ()
        {
            verfügbarkeit = false;
        }

        void mitarbeiterZuweisen (Mitarbeiter* mitarbeiter)
        {
            this->zugewiesenerMitarbeiter = mitarbeiter;
        }

        virtual void printInfo() const = 0;
        virtual ~Raum() = default;



};

class MeetingRaum : public Raum
{
    private: 
        bool hasProjector;

    public:
        MeetingRaum(const std::string& name, int kapazität, std::string berechtigung)
            :Raum(name, kapazität, berechtigung), hasProjector(false)
            {

            };

        void printInfo() const override;

        bool getHasProjector() const
        {
            return hasProjector;
        }
};

class LaborRaum : public Raum
{
    private:
        int Safetylebel;


    public:
        LaborRaum(const std::string& name, int kapazität, std::string berechtigung, int Safetylebel)
            :Raum(name, kapazität, berechtigung), Safetylebel(Safetylebel)
            {

            };

        int getSafetyLevel () const 
        {
            return Safetylebel;
        }

        void printInfo() const override;
};


#endif
