#include <stdio.h>
#include <stdlib.h>





typedef struct song
{
    char *songtitel;
    char *künstlernamen;
    struct song *next;
}song;

typedef struct playlist
{
    struct song *head;
}playlist;


playlist init_playlist()
{
    playlist new_playlist;
    new_playlist.head = NULL;

    return new_playlist;
}

add_song(playlist *playlist, char *songtitel, char *künstlernamen)
{
    song *new_song = malloc(sizeof(*new_song));
    if (new_song != NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }

    

    

}


int main ()
{
    playlist main_playlist = init_playlist();


    return 0;
}