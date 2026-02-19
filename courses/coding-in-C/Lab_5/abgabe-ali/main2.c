/*
*
*       file:                main2.c
*
*       description:         Programm 
*
*
*/

#include <string.h>
#include <stdio.h>

int main (int argc, char **argv)
{

    for (int i=0; i < argc; i++)
    {
        printf("The index is: %d the adresse is %p the content is %s length is %d \n", i, *(argv+i), *(argv+i), strlen(*(argv+i)) );

        printf("The index is: %d the adresse is %p the content is %s length is %d \n", i, argv[i], argv[i], strlen( argv[i]) );
    }

    
    return 0;






}