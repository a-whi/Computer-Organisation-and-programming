#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Task 1: Write an insert function that takes in a RingNode pointer, a string, and an integer offset, and inserts each character from the string into the Ring Linked List at the specified offset (maintaining next and prev pointers as each new node is inserted).

You have been given the struct definition:

struct RingNode {
    struct RingNode *prev;
    char ringChar;
    int headFlag;
    struct RingNode *next;
};
This struct definition is for Linked Ring List. This is a linked list where the 'next' pointer of the final node points to the first node in the linked list.
Each node also has a 'prev' pointer that points backwards through the linked list (the prev pointer of the head will point to the final node in the linked list).
Each node has a ringChar attribute that stores a single character
The head node for the ring linked list will have the headFlag set to 1, and all other nodes will have the headFlag set to 0
For example, if the current ring linked list was (note the head is shown in bold, and appears twice , as this ring linked list loops back to the start):

h -> e -> l -> l -> o -> h

And we inserted the string "world" with an offset of 2, the resulting linked list would look like:

h -> e -> w -> o -> r -> l -> d -> l -> l -> o -> h
*/
struct RingNode {
    struct RingNode *prev;
    char ringChar;
    int headFlag;
    struct RingNode *next;
};

// Task 1
void insert(struct RingNode *head, const char *string, int offset) {
    struct RingNode *current = head;

    // Find the position to enter the new characters
    for (int i = 0; i < offset; i++) {
        current = current->next;
    }

    // Go through the characters in the string
    for (int i = 0; i < strlen(string); i++) {
        // Create a new node for the current character
        struct RingNode *newNode = (struct RingNode *)malloc(sizeof(struct RingNode));
        // Input the data
        newNode->ringChar = string[i];
        newNode->headFlag = 0;

        // Set the its next and prev pointers
        newNode->next = current->next;
        newNode->prev = current;

        // Update the next and prev pointers of the already existing nodes
        current->next->prev = newNode;
        current->next = newNode;

        // Move to the next position in the linked list
        current = newNode;
    }
}

/*
Task 2: Write a traverse function that takes in the head of the Ring Lists, and prints each character in reverse order from the end of the ring linked list to the head (without any spaces inbetween).

For example, for the ring linked list depicted above, the output would be the string "olldlroweh" "heworldllo"
*/
void traverse(struct RingNode *head) {
    // Find the last node
    struct RingNode *tail = head->prev;

    // Go backwards through the list
    for (struct RingNode *current = tail; current != tail->prev; current = current->prev){
        printf("%c", current->ringChar);
    }

    // Add new line
    printf("\n");
}

/*
Task 3: In the main function, write code that does the following:

Reads in a string and creates a ring linked list containing each character from that string in order
Reads in an integer offset and a second string
Inserts the second string into the ring linked list at the specified offset
Prints each character from the entire ring linked list in order (with no spaces separating each character)
*/
struct RingNode* ringLinked(char *string) {
    struct RingNode *head = (struct RingNode *)malloc(sizeof(struct RingNode));
    head->ringChar = string[0];
    head->headFlag = 1;
    head->prev = head;
    head->next = head;

    insert(head, string + 1, 0);

    return head;
}

int main(){
    char firstString[100];
    int offset;
    char secondString[100];

    scanf("%99s", firstString);
    struct RingNode *head = ringLinked(firstString);

    scanf("%d", &offset);
    scanf("%99s", secondString);

    insert(head, secondString,offset);
    traverse(head);


    return 0;
}


