#include <string.h>
#include <stdio.h>


void ersetzen(char tausch[])
{
   
    *(tausch+1) = 'c';
}

int main()

{
 char word [] = "Curly bird catches the worm";
char word2 [] = "AAtions are louder than words";
 char *p_word = word;
 *p_word = 'E';
 *(p_word+1) = 'a';

 ersetzen(word2);
 printf("%s\n", word2);
 



 printf("%s\n", word);
 printf("%s", p_word);


}