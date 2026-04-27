#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct song
{
    char *title;
    char *künstler;
    struct song *next;
}song;


typedef struct playlist
{
    struct song *head;
}playlist;



void init_playlist (playlist *liste)
{
    liste->head = NULL;
}

void add_song (playlist *liste, char *title, char *künstler)
{
    song *new_song = malloc(sizeof *new_song);
    if (new_song == NULL)
    {
        printf("Speicherallokation fehlgeschlagen");
        return;
    }
    new_song->künstler = malloc (strlen(künstler)+1);
    new_song->title = malloc(strlen(title)+1);
    new_song->next = NULL;

    strcpy(new_song->title, title);
    strcpy(new_song->künstler, künstler);

    if (liste->head == NULL)
    {
        liste->head = new_song;
        return;
    }
    song *temp = NULL;
    temp = liste->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_song;
    new_song->next = NULL;
}

void print_playlist (playlist *liste)
{
    if (liste->head == NULL)
    {
        printf("Die Liste ist leer.\n");
        return;
    }
    song *iterator = liste->head;
    while (iterator != NULL)
    {
        printf("Titel:  %s  , Künstler:  %s  \n", iterator->title, iterator->künstler);
        iterator = iterator->next;
    }
    
}

void delete_firstSong (playlist *liste)
{
    if (liste->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    song *temp = liste->head;
    liste->head = liste->head->next;

    free(temp);
}

void delete_playlist(playlist *liste)
{
    if (liste->head == NULL)
    {
        printf("Die Liste ist leer");
        return;
    }
    song *iterator = liste->head;

    while (iterator != NULL)
    {
        delete_firstSong(liste);
        iterator = iterator->next;
    }
    
}


int main ()
{
    playlist ali;
    init_playlist(&ali);

    add_song(&ali, "Hak Kendi Nurundan", "Cem Dogan");
    add_song(&ali, "Bir Selam Sal", "Kivircik Ali");

    print_playlist(&ali);

    delete_firstSong(&ali);
    print_playlist(&ali);

    delete_playlist(&ali);
    print_playlist(&ali);


    return 0;

}