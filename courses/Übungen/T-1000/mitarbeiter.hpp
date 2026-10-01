/*
*
* file: mitarbeiter.hpp
* @brief: Anlegen der Klasse Mitarbeiter
*
*/

#ifndef MITARBEITER_HPP
#define MITARBEITER_HPP

#include <string>
#include "projekt.hpp"
#include <vector>
#include <algorithm>


class Mitarbeiter
{
    private:
        std::string name;
        static int nextId;
        const int id;
        std::vector<std::string> qualifikationen;


    public:
        Mitarbeiter(const std::string& name, const std::vector<std::string>& qualifikationen)
            :id(++nextId), name(name), qualifikationen(qualifikationen)
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

        void setName (const std::string& name);

        const std::vector<std::string>& getQualifikationen () const;

        void addQualifaktionen(const std::string& qualifikationen);
        void removeQualifikationen (const std::string& qualifikationen);

};


#endif