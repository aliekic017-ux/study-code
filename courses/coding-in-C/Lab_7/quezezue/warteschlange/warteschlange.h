#ifndef WARTESCHLANGE_H
#define WARTESCHLANGE_H

typedef struct customer
{
    int id;
    char *name;
    struct customer *next;
}customer;


typedef struct Queue
{
    struct customer *front;
    struct customer *rear;
}Queue;

void init_queue (Queue *p_queue);
customer *create_customer (int id, char *name);
void enqueue (Queue *p_queue, customer *p_customer);
void dequeue (Queue *p_queue);
void print_queue (Queue *p_queue);
void delete_queue (Queue *p_queue);


#endif 
