/*
* file: playlist.c
* description: Definition der Funktionen für die Playlist
*/

#include "../include/playlist.h"


void init_playlist(playlist *playlist)
{
    playlist->head = NULL;
    playlist->size = 0;
    return;
}


void add_song(playlist *playlist, char *title, char *artist)
{
    if (playlist->size >= MAX_SONGS)
    {
        printf("Warnung: Maximum Anzahl von %d Songs erreicht \n", MAX_SONGS);
        return;
    }
    song *new_Song = malloc(sizeof (*new_Song));
    if (new_Song == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return ;
    }
    

    // Speicher reservieren für die genaue Länge der EIngabe von Artist und Title

    new_Song->titel = malloc (strlen(title)+1);
    new_Song->artist = malloc (strlen(artist)+1);

    if (new_Song->artist == NULL || new_Song->titel == NULL )
    {
        printf("Speicherallokation fehlgeschlagen");
        free(new_Song->artist);
        free(new_Song->titel);
        free(new_Song);
        return;
    }

    // man übergibbt die eingabe von title und artist an den speicher im neuen Song

    strcpy(new_Song->titel, title);
    strcpy(new_Song->artist, artist);
    new_Song->next = NULL;

    if(playlist->head == NULL)
    {
        playlist->head = new_Song;
    
    }
    
    else
    {
         // Hilfpointer um durch ganze Playlist zu iterieren 
        song *iterator = playlist->head;
    
        while (iterator->next)
        {
            iterator = iterator->next;
    
        }
        iterator->next = new_Song;
    }
    playlist->size++;
}


void print_playlist(playlist *playlist)
{
    printf("Playlist hat %d Songs. \n",playlist->size);
    song *iterator = playlist->head;

    while (iterator != NULL)
    {
        printf("Title: %s , Artist: %s \n", iterator->titel, iterator->artist);
        iterator = iterator->next;
    }
    return;
    
}

void delete_firstSong(playlist *playlist)
{
    if (playlist->head == NULL)
    {
        printf("Die Playlist ist leer - es kann kein Element gelöscht werden");
        return;
    }

    song *temp = playlist->head;
    playlist->head = temp->next;

    free(temp->artist);
    free(temp->titel);
    free(temp);

    playlist->size--;
    
}

void delete_playlist(playlist *playlist)
{
    

    while (playlist->head != NULL)
    {
        delete_firstSong(playlist);
    }
    return;
    

}