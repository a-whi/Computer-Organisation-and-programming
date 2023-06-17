#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Swaps the first and last nodes just using pointers and not creating any additional temp nodes
void swap(struct Node **head_ref) {
    struct Node *prev_node = NULL;
    struct Node *node = *head_ref;

    /* Case of empty list or single node. */
    if (node == NULL || node->next == NULL) {
        return;
    }

    /* Find the last node and its previous node. */
    struct Node *prev_last_node = NULL;
    while (node->next != NULL) {
        prev_last_node = node;
        node = node->next;
    }

    /* If list has only two nodes. */
    if (prev_last_node == *head_ref) {
        (*head_ref)->next = NULL;
        node->next = *head_ref;
        *head_ref = node;
        return;
    }

    /* Swap the first and last node for list with more than two nodes. */
    prev_node = (*head_ref)->next;
    prev_last_node->next = *head_ref;
    (*head_ref)->next = node->next;
    node->next = prev_node;
    *head_ref = node;
}


void insert(struct Node** head_ref, int new_data){
    struct Node* new_node = new_Node(new_data);

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void removeNode(struct Node** head_ref, int position){
    if (*head_ref == NULL){
        return;
    }
    struct Node* temp = *head_ref;

    if (position == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position -1; i++){
        temp = temp->next;
        if(temp == NULL||temp->next == NULL){
            return;
        }
    }
    struct Node *next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

int main(){

    struct Node *head = NULL;
    int data; 
    printf("Enter data: \n");
    scanf("%d", &data);

    insert(&head, data);

    return 0;
}