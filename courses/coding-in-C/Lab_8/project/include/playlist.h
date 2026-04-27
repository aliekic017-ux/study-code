/*
* file: playlist.h
* description: Deklaration von Funktionen für die Playlist 
*/
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 2

typedef struct song
{
    char *titel;
    char *artist;
    struct song *next;
}song;

typedef struct playlist 
{
    struct song *head;
    int size;
}playlist;


void init_playlist(playlist *playlist);
void add_song(playlist *playlist, char *title, char *artist);
void print_playlist(playlist *playlist);
void delete_firstSong(playlist *playlist);
void delete_playlist(playlist *playlist);

#endif 