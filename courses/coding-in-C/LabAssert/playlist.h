#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct Song
{
    char *titel;
    char *name;
    struct Song *p_next;
}Song;

typedef struct Playlist
{
    struct Song *p_head;
}Playlist;


void init_playlist (Playlist *p_playlist);
void add_song (Playlist *p_playlist, const char *titel, const char *name);
void print_playlist (Playlist *p_playlist);
void delete_firstSong (Playlist *p_playlist);
void delete_playlist (Playlist *p_playlist);

#endif