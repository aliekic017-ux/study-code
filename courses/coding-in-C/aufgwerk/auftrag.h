#ifndef AUFTRAG_H
#define AUFTRAG_H

typedef struct Order
{
    int id;
    char *titel;
    int dauer_minuten;
    struct Order *next;
}Order;


typedef struct Queue
{
    struct Order *front;
    struct Order *rear;

}Queue;


void init_queue (Queue *p_queue);
Order *create_new_Order (int id, char *titel, int dauer_minuten);
void enqueue (Queue *p_queue , Order *p_order);
void dequeue (Queue *p_queue);
void print_queue (Queue *p_queue);
void free_queue (Queue *p_queue);

void load_orders_from_file (Queue *p_queue, char *filename);
void save_queue_to_file (Queue *p_queue, char *filename);


#endif 