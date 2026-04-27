#ifndef NOTIZEN_H
#define NOTIZEN_H

typedef struct Note
{
    int id;
    char *text;
    struct Note *p_next;
}Note;

typedef struct NoteList
{
    struct Note *head;
}NoteList;

void init_list (NoteList *p_list);
Note *create_note (int id, const char *text);
void append_note (NoteList *p_list, Note *p_note);
void print_list (NoteList *p_list);
Note *find_note_by_id (NoteList *p_list, int id);
void delete_first_note (NoteList *p_list);
int count_notes (NoteList *p_list);
void delete_list (NoteList *p_list);

#endif 