// Insert function & remove function for a linked list
/*
Reads in a single string of letters and numbers (you can assume that the only letter will be an 's' character)
For each single character in the string:
If it is a numerical character, convert that character to an integer and insert it into the queue
If it is an 's', serve the next item in the queue and print that integer to the console, followed by a single space charact
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct QueueNode {
    struct QueueNode *next;
    unsigned int value;    
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;    
};


void insert(struct Queue* queue, int value){

    // Create a new node struct to be added to the linked list
    struct QueueNode* new_node = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    // Set the value
    new_node->value = value;
    // Set the pointer of next to NULL as it will go at the back of the list
    new_node->next = NULL;

    // If there is nothing in the linked list already
    if (queue->rear == NULL){
        queue->front = queue->rear = new_node;
        return;
    }

    // Set current rear to point at the new value
    queue->rear->next = new_node;
    // Set the rear as the new node
    queue->rear = new_node;
};

// Remove item
int serve(struct Queue* queue){

    // If their is nothing in the list
    if (queue->front == NULL){
        return -1;
    }

    int VAL = queue->front->value;  // The value that will be returned
    struct QueueNode* temp = queue->front; //temp will be the original front

    // If there is nothing in the list it'll be NULL
    if (queue->front == queue->rear){
        queue->front = queue->rear = NULL;
    }else{
        // Set the front to be the element the front is pointing to 
        queue->front = queue->front->next;
    }

    free(temp);
    return VAL;
};

int main(){
    char string[100];
    printf("Enter your string: \n");
    scanf("%s", string);

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;

    int len = strlen(string);

    for (int i = 0; i < len; i++){

        // Add element to the string
        if (isdigit(string[i])){
            // convert string to int
            int value = string[i] - '0';
            // add it to list
            insert(queue, value);

        }else if (string[i] == 's'){
            int servedValue = serve(queue);
            printf("%d ", servedValue);
        }
    }
    printf("\n");

    // Free the remaining nodes in the queue before exiting
    while (queue->front != NULL) {
        serve(queue);
    }
    free(queue);

    return 0;
}