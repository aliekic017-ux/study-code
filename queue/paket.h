#ifndef PAKET_H
#define PAKET_H

typedef struct Paket
{
    int id;
    float gewicht;
    struct Paket *p_next;
}Paket;

typedef struct Queue
{
    struct Paket *p_front;
    struct Paket *p_rear;
}Queue;

void init_queue (Queue *p_queue);
Paket *create_node (int id, float gewicht);
void enqueue (Queue *p_queue, Paket *p_paket);
void dequeue (Queue *p_queue);
void print_queue (Queue *p_queue);
void free_queue (Queue *p_queue);


#endif 