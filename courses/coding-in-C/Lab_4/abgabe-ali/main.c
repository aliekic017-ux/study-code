#include <string.h>
#include <stdio.h>

void tausch_char(char tausch[])

{
    *(tausch+1) ='c';
    printf(" %s\n", tausch);
    return;
}
int main ()

{

    char c_Satz [] = "Curly bird watches the worm";
    char *c_pSatz = c_Satz;

    char c_Satz2 [] = "AAtions speak louder than words";


    printf (" %s \n", c_Satz);
    printf (" %s \n", c_pSatz);

    *c_pSatz = 'E';
    *(c_pSatz +2) = 'a';

    printf(" %s\n", c_Satz);


   // -------------------------------------------------------

    char name[20];
    char *p_name = name;

    *(p_name+1) = 'c';
    printf ("Name eingeben: \n");
    fgets (name, sizeof(name), stdin); 

    
    printf (" Der eingegebene Name lautet: %s\n", name);

    tausch_char(c_Satz2);


    return 0;
 

}