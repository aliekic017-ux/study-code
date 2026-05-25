#include <iostream>
#include <string>


class User
{
    protected:
    // protected wird verwendet, damit die abgeleiteten Klassen
    // die Attrbute name und id zugreifen können.
    // von außen sind die Attribute dennoch geschützt
    // : kennzeichnet die Vererbung
    std::string name;
    int id;

    public:

    // Konstruktor von der Klasse user
    // die Attribute name und id werden direkt beim Erzeugen des Objekts mit den übertragenen Werten befüllt..
    User(const std::string& name, int id)
        :name(name), id(id)
    {

    }

    void printInfo () const
    {
        std::cout<<"Name: "<< name << std::endl;
        std::cout<<"ID: "<< id << std::endl;
    }
};


class Student : public User
{
    private: 
    std::string course;
    double notenschnitt;

    public:
    Student(const std::string& name, int id, const std::string& course, double notenschnitt)
            :User(name, id), course(course), notenschnitt(notenschnitt) // ewichtig user davor wenn man im Konsturktor Attribute von der verbeten Klasse vwrwerndet
    {

    }

    void printRole () const
    {
        std::cout <<"Name: "<< name << " ist ein Student im Kurs: " << course << std::endl;
        std::cout <<"Notenschnitt:" << notenschnitt << std::endl;
    }
};

class Instructor : public User
{
    private:
    std::string fach;

    public:
    Instructor(const std::string& name, int id, const std::string& fach)
            :User(name, id), fach(fach)
    {

    }

    void printRole () const
    {
        std::cout <<"Name: " << name << " mit der ID: " << id << "unterrichtet das Fach:" << fach <<std::endl;
    }
};


int main()
{
    Student student1 ("Ali", 1001, "Informatik2", 2.1);
    Instructor instructor1 ("Pagliarulo", 1002, "Grundlagen der Informatik 2");

    student1.printInfo();
    student1.printRole ();

    instructor1.printInfo ();
    instructor1.printRole ();

    return 0;
}

