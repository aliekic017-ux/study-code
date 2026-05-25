#include <iostream>
#include <string>


class Note 
{
    private:
    std::string* text; // Pointer auf einen Stringd


    public:
    Note(std::string input); // Konstruktor

    // Der Copy-Konstruktor wird ergänzt, damit beim Kopieren des Objekts nicht nur die Pointer-Adresse,
    // sondern ein eigener Speicherbereich erzeugt wird..
    Note(const Note& other); 

    ~Note(); // Destruktor 
    void display();
};

Note::Note (std::string input)
{
    // jetzt soll dynamischer Speicher reserviert werden

    text = new std::string(input); 
    // new reserviert Speicher im Heap
    // std::string(input) erzeugt einen String mit dem übergebenen Text
    // text --> der Pointer speichert die Adresse dieses Strings

}

Note::~Note()
{
    delete text;
    text = nullptr;

    std::cout << "Speicher freigegeben" << std::endl;

}

void Note::display()
{
    std::cout << *text << std::endl;
}

Note::Note(const Note& other)
{
    text = new std::string(*other.text);
}

int main ()
{

   Note note1("Hallo Ezgi");

   Note note2 = note1;

    note1.display();
    note2.display();


    // wichtig:: Destruktor wird automatisch aufgerufen, sobald das OBjekt seinen Bereich verlösst. (zerstört wird)



    // Part 1:
    // Beide Objekte teilen sich denselben Pointer.
    // Dadurch kann ein double delete entstehen.

    // Part 2:
    // Jedes Objekt bekommt seinen eigenen Speicher.
    // Dadurch wird das double delete Problem verhindert.
    

    // Das Double-Delete-Problem entsteht, wenn derselbe Speicherbereich zweimal gelöscht wird.
    // In Part 1 zeigen beide Objekte auf denselben Pointer, weil beim Kopieren nur die Speicheradresse übernommen wird. 
    // Dadurch versuchen beide Destruktoren denselben Speicher mit delete freizugeben. 
    // Das kann zu Abstürzen oder undefiniertem Verhalten führen.




    return 0;
}