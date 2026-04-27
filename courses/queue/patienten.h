#ifndef PATIENTEN_H
#define PATIENTEN_H

typedef struct Patient
{
    int id;
    char *name;
    struct Patient *next;
}Patient;


typedef struct Queue
{
    struct Patient *front;
    struct Patient *rear;
}Queue;


void init_queue(Queue *p_queue);
Patient *create_patient(int id, char *name);
void enqueue(Queue *p_queue, Patient *p_patient);
void dequeue(Queue *p_queue);
void print_queue(Queue *p_queue);

#endif