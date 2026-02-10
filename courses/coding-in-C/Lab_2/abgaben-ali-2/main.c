#include <stdio.h>

 // möglichst wenig globale Variablen definieren. Eher direkt in main reinmachen. 
int main (void)
{
  const int Reihe = 8 ;
  const char Spalte [8] = {'A','B','C','D','E','F','G','H'}; 

 for (int i = Reihe; i > 0; i--)
 {
   for (int l = 0; l < Reihe; l++)
   {
      printf("%c %d", Spalte[l] ,i);
       
   }
   printf("\n");
   
   
 }
 return 0; 

 
}

