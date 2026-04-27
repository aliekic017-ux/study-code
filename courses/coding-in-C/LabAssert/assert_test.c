#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "playlist.h"


void test_init_playlist (void)
{
    Playlist p;
    init_playlist(&p);

    assert(p.p_head == NULL);
}

void test_add_song (void)
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Titel1", "Song1");

    assert(p.p_head != NULL);
    assert(strcmp(p.p_head->titel, "Titel1")== 0);
    assert(strcmp(p.p_head->name, "Song1") == 0);
    assert (p.p_head->p_next == NULL);

}


void test_delete_firstSong (void)
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Titel1", "Song1");
    add_song(&p, "Titel2", "Song2");

    delete_firstSong(&p);

    assert(p.p_head != NULL);
    assert(strcmp(p.p_head->titel, "Titel2") == 0);
    assert(strcmp(p.p_head->name, "Song2") == 0);

}

void test_delete_firstSong_empty (void)
{
    Playlist p;
    init_playlist(&p);

    delete_firstSong(&p);
    assert(p.p_head == NULL);
}

void test_delete_playlist (void)
{
    Playlist p;
    init_playlist(&p);

    add_song(&p, "Titel1", "Song1");
    add_song(&p, "Titel2", "Song2");

    assert(p.p_head != NULL);

    delete_playlist(&p);
    assert(p.p_head == NULL);
}



int main (void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    test_delete_firstSong_empty();
    test_delete_playlist();

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}