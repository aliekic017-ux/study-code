#include <iostream>

class adjacency
{
    
    private:

    static const int sieze = 3;
    bool matrix [sieze][sieze];


    public:

    adjacency()
    {
        for (int i = 0; i < sieze; i++)
        {
            for (int j = 0; j < sieze; j++)
            {
                matrix[i][j] = 0;
            }
        
    
        }
    }
    void set_element (int i, int j, bool wert)
    {
        if (i >= 0 && i < sieze && j >= 0 && j < sieze)
        {
            matrix[i][j] = wert;
        }
    }

    void print_matrix () const
    {
        std::cout <<"Adjacency Matrix:\n";
        for (int i = 0; i < sieze; i++)
        {
            for (int j = 0; j < sieze; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout <<"\n";
        }
         
    }

};

int main()
{
    adjacency graph1;

    graph1.set_element(0 , 1 , true);
    graph1.set_element(0 , 2 , true);
    graph1.set_element(1 , 0 , true);
    graph1.set_element(1 , 2 , true);
    graph1.set_element(2 , 0 , true);
    graph1.set_element(2 , 1 , true);


    graph1.print_matrix ();


    return 0;
}