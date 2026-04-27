#include "include/playlist.h"

int main (void)
{
    printf("Maximum playlist size is set to %d songs. \n", MAX_SONGS);
    playlist ali;
    init_playlist(&ali);

    add_song(&ali, "Crawling", "Linkin Park");
    add_song(&ali, "Layla", "Eric Clapton");
    add_song(&ali, "Esperanto", "Max Herre");

    print_playlist(&ali);

    //delete_firstSong(&ali);
    //print_playlist(&ali);

    //delete_playlist(&ali);
    //print_playlist(&ali);



    return 0;

}