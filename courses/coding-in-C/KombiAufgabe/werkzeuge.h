#ifndef WERKZEUGE_H
#define WERKZEUGE_H

typedef struct Tool
{
    int id;
    char *bezeichnung;
    char *zustand;
    struct Tool *p_next;
}Tool;

typedef struct ToolList
{
    struct Tool *p_head;
}ToolList;

void init_list (ToolList *p_list);
Tool *create_tool (int id, const char *bezeichnung, const char *zustand);
void append_tool (ToolList *p_list, Tool *p_tool);
void print_list (ToolList *p_list);
Tool *find_by_id (ToolList *p_list, int id);
void delete_first_tool (ToolList *p_list);
int count_tools (ToolList *p_list);
void delete_list (ToolList *p_list);

#endif 