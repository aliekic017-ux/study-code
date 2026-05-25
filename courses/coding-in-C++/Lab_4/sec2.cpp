#include <iostream>
#include <string>



class Shape
{
    public:
        virtual double area () const = 0;


        virtual ~Shape()
        {

        }
};


// die Klasse Circle erbt die public Attribute von Shape
class Circle : public Shape
{
    private:
        double radius;


    public:

    // Konstruktor mit der Initialiseung von Radius mit dm Wert von Radius direkt beim Erzeugen ienes Objekts
        Circle(double radius)
            : radius(radius)
        {
         
        }

        // eigene Flächenberechnung vom Kreis --> double area von Klasse shape wird überschrieben mit Override
        double area () const override
        {
            return 3.14 * radius * radius; 
        }

};



class Rectangle : public Shape
{
    private: 
        double width;
        double height;

    
    public:
        Rectangle(double width, double height)
            :width(width), height(height)
        {

        }

        double area () const override
        {
            return width * height;
        }



};



int main ()
{
    /*Circle circle1(5.0);
    Rectangle rectangle1(2.0,4.0);

    std::cout << "Circle Area: "<< circle1.area() << std::endl;
    std::cout << "Rectangle Area: " << rectangle1.area() << std::endl;

    */



    Shape* shapes[4];
    
    int max_shapes = 4;
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(2.0,3.0);
    shapes[2] = new Circle(7.0);
    shapes[3] = new Rectangle(3.4,5.4);


    for (int index = 0 ; index < max_shapes; index++)
        {
            std::cout << "Area: " << shapes[index]->area() << std::endl;
        }

    for (int index = 0; index < max_shapes ; index++)
    {
        delete shapes[index];
    }
    

    return 0;
}



/*
Was ist der Zweck von virtual??

-> wenn man eine Methode über einen Zeiger auf die Basisklasse aufruft, soll C++ zur Laufzeit entscheiden,
welche Methode wirklich ausgeführt wird.

Was ist der Unterschied zwischen Overriding und Overloading??

Overriding: eine abgeleitete Klasse ersetzt eine Methode der Basisklasse durch eigene Version z. bersetzen von area zu Circle.area() bzw. Rectangle.area()
Overloading: mehrere Funktionen können zwar den gleichen NAmen haben, sie unterschieden sich jedoch beim Typ oder Anzahl der Parameter.

Was ist eine rein virtuelle Funktion??

-> eine rein virtuelle Funktion ist eine Methode, die in der Basisklasse nur vorgeschrieben wird, aber dort keine richtige Implementierung hat.

bsp: virtual double area() const = 0;
das beutet, dass jede ageleitete Klasse diese Methode slebst implementieren muss
dadurch wird Shape zu einer abstrakten Klasse

Warum sind abstrakte Klassen nützlich??

--> abstrakte Klassen sind nützlich, weil sie eine gemeinsame Struktur vorgeben.
Bei der abstrakten Klasse Shape bedeutet das: jede Form muss eine Methode area() besitzen.

--> aber jede Form berechnet seine Fläche anders. -> muss selsbt implementiert werden für jede form einzeln
so kann man verschieden Fprmen gemeinsam über Shape* speichern und trotzdem wird mmmer die passende area()-Methode aufgerufen

*/