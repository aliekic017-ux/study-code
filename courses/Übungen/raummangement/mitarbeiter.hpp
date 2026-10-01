/*
*
* file: mitarbeiter.hpp
* @brief: Anölegen der Klasse MItarbeiter fpr dsas Raummanagementssystem
*
*/

#ifndef MIARBEITER_HPP
#define MITARBEITER_HPP


#include <string>
#include <vector>
#include <algorithm>
#include "raum.hpp"

class Raum;

class Mitarbeiter
{
    private:
        static int nextId;
        int id;
        std::string name;
        std::vector<std::string> berechtigungen;
        Raum* gebuchterRaum;

    public:

        Mitarbeiter(const std::string& name, const std::vector<std::string>& berechtigungen)
            :id(++nextId), name(name), berechtigungen(berechtigungen), gebuchterRaum(nullptr)
            {

            };
        int getId () const
        {
            return id;
        } 
        const std::string& getName() const
        {
            return name;
        }
        const std::vector<std::string>& getBerechtigungen () const
        {
           return this->berechtigungen;
        }

        void addBerechtigungen (const std::string& neueBerechtigung)
        {
            berechtigungen.push_back(neueBerechtigung);
        }

        void removeBerechtigungen (const std::string& entnehmenDerBerechtigung);
        void raumBuchen(Raum* raum);
};

#endif