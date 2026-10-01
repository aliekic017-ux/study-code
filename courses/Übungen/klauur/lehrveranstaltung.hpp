/*
*
* file: Lehrveranstaltung.hpp
* @brief: ANlegen der verschiedenen Klassen fpr das Hochschulmanagementsystem
*
*/

#ifndef LEHRVERANSTALTUNGEN_HPP
#define LEHRVERANSTALTUNGEN_HPP

#include <vector>
#include <string>


class Lehrveranstaltungen
{
    private: 
        static int nextId;
        int id;
        std::string name;
        int ects; 

    public:
        Lehrveranstaltungen(const std::string& name, int ects)
            :id(++nextId), name(name), ects(ects)
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

        int getEcts () const
        {
            return ects;
        }

        virtual ~Lehrveranstaltungen() = default;
        virtual void printInfo () const = 0;
};

class Vorlesung : public Lehrveranstaltungen
{
    private: 
        int vorlesungsstunden;
    
    public: 
        Vorlesung(const std::string& name, int ects, int vorlesungsstunden)
            :Lehrveranstaltungen(name, ects), vorlesungsstunden(vorlesungsstunden)
            {

            };

        
        int getVorlesungsstunden () const 
        {
            return vorlesungsstunden;
        }

        void printInfo() const override;
};

class Praktikum : public Lehrveranstaltungen
{
    private: 
        int AnzahlLaborVersuche;



    public:
        Praktikum(const std::string& name, int ects, int AnzahlLaborVersuche)
            :Lehrveranstaltungen(name, ects), AnzahlLaborVersuche(AnzahlLaborVersuche)
            {

            };

        int getAnzahlLaborVersuche () const
        {
            return AnzahlLaborVersuche;
        }

        void printInfo() const override; 
};

#endif