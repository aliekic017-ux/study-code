#ifndef KRANKENHAUS_H
#define KRANKENHAUS_H

typedef struct patient 
{
    int patient_id;
    char *name;
    char *symptom;
    struct patient *next;
}patient;

typedef struct Queue
{
    struct patient *front; // Pointer vorne der Liste (erster Patient)
    struct patient *rear;  // Pointer hinten an der Liste (letzter Patient)
}Queue;

void init_queue (Queue *p_queue);
patient *create_patient (int patient_id, char *name, char *symptom);
void enqueue (Queue *p_queue, patient *p_patient);
void dequeue (Queue *p_queue);
void print_queue (Queue *p_queue);
void delete_queue (Queue *p_queue);
void peek_front (Queue *p_queue);
patient *find_patient_by_id (Queue *p_queue, int patient_id);
patient *find_patient_by_name (Queue *p_queue, char *name);
patient *find_patient_by_symptom (Queue *p_queue, char *symptom);


#endif 