/*
*
* file: team.hpp
* @brief: Anlegen einer KLasse Team
*
*/


#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "projekt.hpp"
#include "mitarbeiter.hpp"

class Team
{
    private:
        std::string name;
        std::vector<Mitarbeiter*> mitarbeiter;
        std::vector<Projekt*> projekte;

    public:
        Team(const std::string& name)
            :name(name)
            {

            };

        const std::string& getName() const
        {
            return name;
        }

        void addMitarbeiter (Mitarbeiter* mitarbeiter);
        void removeMitarbeiter (Mitarbeiter* mitarbeiter);


        void addProjekte (Projekt* projekt);
        void removeProjekte (Projekt* projekt);



};

#endif