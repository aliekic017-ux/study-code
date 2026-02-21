#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

   // int variablen[10] ={90};
    
    //int *p_variablen = variablen;

   // printf("%d", *p_variablen);
    
     **pp=42;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp); 

    return 0;
}