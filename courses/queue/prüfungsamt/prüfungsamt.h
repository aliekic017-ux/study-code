#ifndef PRUFUNGSAMT_H
#define PRUFUNGSAMT_H

typedef struct Student
{
    int martikelnummer;
    char name[50];
    float notenschnitt;
    struct Student *next;

}Student;


typedef struct Queue
{
    struct Student *front;
    struct Student *rear;

}Queue;

void init_queue(Queue *p_queue);
Student *create_student (int martikelnummer, char name[], float notenschnitt);
void enqueue (Queue *p_queue, Student *p_student);
void dequeue (Queue *p_queue);
void print_queue (Queue *p_queue);
void delete_queue (Queue *p_queue);
Student *find_student_by_martikelnummer (Queue *p_queue, int martikelnummer);
int count_students (Queue *p_queue);
void peek_front (Queue *p_queue);



#endif