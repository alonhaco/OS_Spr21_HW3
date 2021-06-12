#include "myQueue.h"

node_t *head = NULL;
node_t *tail = NULL;


void enqueue(void *x){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->client_fd = x;
    new_node->next = NULL;

    if (tail == NULL){
        head = new_node;
    }
    else{
        tail->next = new_node;
    }
    tail = new_node;
    queue_size++;
}

void* dequeue(){
    if (head == NULL){
        return NULL;
    }else{
        void *result = head->client_fd;
        node_t *temp = head;
        head = head->next;
        if (head == NULL){
            tail = NULL;
        }
        queue_size--;
        free(temp);
        return result;
    }
}