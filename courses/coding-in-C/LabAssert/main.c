#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");

    printf("Gesamte Playlist: \n");
    print_playlist(&myPlaylist);
    delete_firstSong(&myPlaylist);

    printf("Playlist, nachdem ein Song gelöscht wurde: \n");
    print_playlist(&myPlaylist);

    delete_playlist(&myPlaylist);

    return 0;
}