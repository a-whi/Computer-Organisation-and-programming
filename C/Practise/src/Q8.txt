#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ValueNode {
    float value;
    struct ValueNode * next;
};
void insert_node(struct ValueNode **Header, float value);
const int SEQ_LEN = 100; //use variable seq_len
void customSeq(int seed, struct ValueNode **Header);


int main(int argc, char *argv[]){

    struct ValueNode *Header = NULL; // set head
    int seed = 1356;    // I hope this isnt a command line argument as it was not specified
    
    //Opens the file
    FILE * readfile = fopen(argv[1], "w");

    //If file not found 'error'
    if (readfile == NULL) {
        printf("ERROR\n");
        return 1;
    }

    customSeq(seed, &Header);

    for( int i = 0; i < SEQ_LEN; i++){
        struct ValueNode* currentNode = Header;
        while(currentNode != NULL){
            putw("%.4f, ",currentNode->value, readfile);
        }
    }

    // Deallocates all memory and quits the program
    struct ValueNode current = *Header;
    while (current != NULL){
        struct ValueNode *next = current->next;
        free(current);
        current = next;
    }
    *Header = NULL; // Set the head to nothing after all memory is deallocated

   fclose(readfile);
    return 0;
}

// inserts the floating point number at the end of the linked list
void insert_node(struct ValueNode **Header, float value) {
        struct ValueNode* newValueNode = (struct ValueNode*) malloc(sizeof(struct ValueNode));
        newValueNode -> value = value;
        newValueNode -> next = NULL;

        if ( *Header == NULL) {
            *Header = newValueNode;
            return;
        }

        struct ValueNode* current = *Header;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newValueNode;
}

void customSeq(int seed, struct ValueNode ** Header){
    // Create new value
    float value;
    // Loop 100 times
    for (int i = 0; i < SEQ_LEN; i++){

        // Check if even or odd
        if (seed%2 == 0){
            value = seed/1.6;
            seed = floor(value);    // Floor the value so its a whole number
            insert_node(&Header, value); // Jump to insert and inserts the value to the last node
        }else{
            value = seed*1.2;
            seed = floor(value);
            insert_node(&Header, value);
        }
    }
}
