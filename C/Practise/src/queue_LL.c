// How to Queue Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// The queue, front stores the front node of the linked list and rear stores the last node of the linked list
struct Queue {
    struct Node *front, *rear;
};

// A utility function to create a new linked list node.
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// A utility function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a data to q
void enqueue(struct Queue* q, int data) {
    // Create a new node
    struct Node* node = newNode(data);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = node;
    q->rear = node;
}

// Function to remove a data from given queue q
void dequeue(struct Queue* q) {
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct Node* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

