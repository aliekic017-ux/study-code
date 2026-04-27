 #ifndef AUFGABEN_H
 #define AUFGABEN_H
 
 typedef struct task
 {
    int id;
    int priority;
    char *text;
    struct task *next;
 }task;
 

typedef struct List
{
    struct task *head;
}List;

void init_list (List *liste);
void add_task (List *liste, int id, int priority, char *text);
void remove_task (List *liste);
void print_list (List *liste);

void read_file(List *liste, char *filename);
void write_file (List *liste, char *filename);


 #endif