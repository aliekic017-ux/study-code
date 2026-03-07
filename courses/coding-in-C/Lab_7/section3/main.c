#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Song
{
    char *Title;
    char *Artist;
    struct Song *next;

}Song;

typedef struct playlist
{
    struct Song *head;
}playlist;


void init_playlist(playlist *playlist)
{
    playlist->head = NULL;
}


Song *add_song(playlist *playlist, char *title, char *artist )
{
   Song *newSong = malloc (sizeof *newSong);
   if (newSong == NULL)
   {
    printf("Speicherallokation fehlgeschlagen");
    return NULL;
   }
   newSong->Title = malloc(strlen(title)+1);
   newSong->Artist = malloc(strlen(artist)+1);

   if (newSong->Artist == NULL || newSong->Title == NULL)
   {
    printf("Fehler bei der Speicherreservierung");
    free(newSong->Artist);
    free(newSong->Title);
    free(newSong);
    return; 
   }
   strcpy(newSong->Title, title);
   strcpy(newSong->Artist, artist);
   newSong->next = NULL;

   // Wenn noch kein Song in der Playlist ist newSong das erste Lied in der Playlist 
   // Prüfen, ob head == NULL oder nicht
   if (playlist->head == NULL)
   {
     playlist->head = newSong;
     return;
   }

   // Iterator der vom Anfang der Playlist die ganze durchgeht mit der while Schleife, bis man am Ende der PLaylist angekommen ist
   // Einfügen des neuen Songs am Ende der Schleife
   Song *iterator = playlist->head;
   while (iterator->next)
   {
        iterator = iterator->next;
   }
   iterator->next = newSong;

   return newSong;

}

void print_playlist (playlist *playlist)
{
    Song *iterator = playlist->head;

    while (iterator != NULL)
    {
        printf("Title: %s, Artist: %s ", iterator->Title, iterator->Artist);
        iterator = iterator->next;
    }
    
}

void delete_firstSong(playlist *playlist)
{
    if (playlist->head == NULL)
    {
        printf("Fehler - Playlist beinhaltet keine Songs");
        return;

    }
    // Erstelllen eines temporären Pointers der auch auf den ersten Song schaut

    Song *temp = playlist->head;
    playlist->head = playlist->head->next;

    free(temp->Artist);
    free(temp->Title);
    free(temp);
}