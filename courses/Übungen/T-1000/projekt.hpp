/*
*
* file: projekt.hpp
* @brief: Anlegen der abstrakten Klasse und der abgeleiteten Klassen
*
*/

#ifndef PROJEKT_HPP
#define PROJEKT_HPP

#include <string>

class Projekt
{
    private: 
        static int nextId;
        int id;
        std::string titel;
        int status;

    public:
        Projekt(const std::string& titel, int status)
            :id(++nextId), titel(titel), status(status)
                {

                };
        
        int getId () const
        {
            return id;
        }

        int getStatus () const
        {
            return status;
        }
        const std::string& getTitel () const
        {
            return titel;
        }

        
        virtual void printInfo () const = 0;
 
        virtual ~Projekt () = default;
};

class Softwareprojekt : public Projekt
{
    private: 
        std::string programmiersprache;

    public:
        Softwareprojekt(const std::string& titel, int status, const std::string& programmiersprache)
            :Projekt (titel, status), programmiersprache(programmiersprache)
            {

            };

        void printInfo () const override;

        const std::string& getProgrammiersprache () const
        {
            return programmiersprache;
        }
};

class Hardwareprojekt : public Projekt
{
    private:
        int anzahlTestgeräte;
    
    public:
        Hardwareprojekt(const std::string& titel, int status, int anzahlTestgeräte)
            :Projekt(titel, status), anzahlTestgeräte(anzahlTestgeräte)
            {

            };

        void printInfo () const override;

        int getAnzahlTestgeräte () const
        {
            return anzahlTestgeräte;
        }
};  


class Projektplan
{
    private:
        int startwoche;
        int endwoche;
        int arbeitsstunden;

    public:
        Projektplan(int startwoche, int endwoche, int arbeitsstunden)
            :startwoche(startwoche), endwoche(endwoche), arbeitsstunden(arbeitsstunden)
            {

            };
        
        int getStartwoche () const
        {
            return startwoche;
        }

        int getEndwoche () const
        {
            return endwoche;
        }

        int getArbeitsstunden () const
        {
            return arbeitsstunden;
        }

};


#endif