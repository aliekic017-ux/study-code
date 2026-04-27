#include "playlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void init_playlist (Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
}

void add_song (Playlist *p_playlist , const char *titel, const char *name)
{
    Song *new_Song = malloc (sizeof *new_Song);
    if (new_Song == NULL)
    {
        printf("Fehler bei der Speicherallokation.\n");
        return;
    }
    new_Song->name = malloc(strlen(name)+1);
    if (new_Song->name == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        free (new_Song);
        return;
    }
    new_Song->titel = malloc(strlen(titel)+1);
    if (new_Song->titel == NULL)
    {
        printf("Speicherallokation fehlgeschlagen.\n");
        free(new_Song->name);
        free(new_Song);
        return;
    }
    
    strcpy(new_Song->titel, titel);
    strcpy(new_Song->name, name);
    new_Song->p_next = NULL;

    if (p_playlist->p_head == NULL)
    {
        p_playlist->p_head = new_Song;
        return;
    }
    
    Song *iterator = p_playlist->p_head;
    while (iterator->p_next != NULL)
    {
        iterator = iterator->p_next;
    }
    iterator->p_next = new_Song;

    
}

void print_playlist (Playlist *p_playlist)
{
    if (p_playlist->p_head == NULL)
    {
        printf("Die Liste ist leer.");
    }
    
    Song *iterator = p_playlist->p_head;
    while (iterator != NULL)
    {
        printf("Titel: %s, Künstler: %s\n", iterator->titel, iterator->name);
        iterator = iterator->p_next;
    }
    
}

void delete_firstSong (Playlist *p_playlist)
{
    if (p_playlist->p_head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    
    Song *temp = p_playlist->p_head;
    p_playlist->p_head = p_playlist->p_head->p_next;

    free(temp->titel);
    free(temp->name);
    free(temp);
}

void delete_playlist (Playlist *p_playlist)
{
    if (p_playlist->p_head == NULL)
    {
        printf("Die Playlist ist leer.\n");
        return;
    }
    while (p_playlist->p_head != NULL)
    {
        delete_firstSong(p_playlist);
    }
    
}

