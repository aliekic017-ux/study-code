#ifndef PATIENTEN_H
#define PATIENTEN_H

typedef struct Patient
{
    int id;
    char name [50];
    struct Patient *next;
}Patient;

typedef struct Queue
{
    struct Patient *front;
    struct Patient *rear;
}Queue;


void init_queue (Queue *p_queue);
Patient *create_patient (int id, char name []);
void enqueue (Queue *p_queue, Patient *p_patient);
void dequeue (Queue *p_queue);
void print_queue(Queue *p_queue);
void delete_queue (Queue *p_queue);
int count_patient (Queue *p_queue);
Patient *find_patient_by_id (Queue *p_queue, int id);
void peek_front (Queue *p_queue);

#endif