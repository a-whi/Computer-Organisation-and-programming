// Linked list rotation
#include <stdio.h>

//List = 1->2->3->4
struct Node {   
    int data;   
    struct Node *nextPtr; 
};
struct Node_2 {   
    int data;   
    struct Node_2 *nextPtr; 
};

//List = 2->3->4->1
void RotateLeftLinkedList(struct Node** Header) {
    // Check to make sure the linked list has stuff in it
    // First part checks if the list is empty, the second checks to see if there is more than 1 item in the list
    if (*Header == NULL || (*Header)->nextPtr == NULL){
        return;
    }

    // Create 2 variables last and second_last
    // last will just be the first element in the list
    // Second last will be NULL
    struct Node* last = *Header;
    struct Node* second_last = NULL;

    // Now we loop 
    while(last->nextPtr != NULL){
        second_last = last;
        last = last->nextPtr;
        // So at the end second_last == 4
        // last = NULL
    }

    // change the last pointer to point at the head
    last->nextPtr = *Header;

    // Set the Header to be the second value in the list (element 2)
    *Header = (*Header)->nextPtr;

    // Now we set the (new) last element in the list to point to NULL
    second_last->nextPtr = NULL;
}

//List = 4->1->2->3
void RotateRightLinkedList(struct Node** Header) {
    // Check to make sure the linked list has stuff in it
    // First part checks if the list is empty, the second checks to see if there is more than 1 item in the list
    if (*Header == NULL || (*Header)->nextPtr == NULL){
        return;
    }

    // Create 2 variables last and second_last
    // last will just be the first element in the list
    // Second last will be NULL
    struct Node* last = *Header;
    struct Node* second_last = NULL;

    // Now we loop to find the last value in the linked list
    while(last->nextPtr != NULL){
        second_last = last;
        last = last->nextPtr;
        // So at the end second_last == 4
        // last = NULL
    }

    // Set the next pointer of the last node to point to the first node
    last->nextPtr = *Header;

    // Set the Header to be the element 4 ( th  original last element)
    *Header = last;

    // Now we set the (new) last element in the list to point to NULL
    second_last->nextPtr = NULL;
}

void combine2Lists(struct Node** Header, struct Node_2** Header_2){
    // Add  List2 to List1
    // To do this I'll by rotating the linked list to the left twice 
    // Then appending the new version of List2 to the back of List 1
    RotateLeftLinkedList((struct Node_2**) Header_2);
    RotateLeftLinkedList((struct Node_2**) Header_2);

    // Create 2 variables last and second_last
    // last will just be the first element in the list
    // Second last will be NULL
    struct Node* last = *Header;

    // Now we loop to find the last value in the linked list
    while(last->nextPtr != NULL){
        last = last->nextPtr;
        // last = NULL (Last element in List 1)
    }

    // Make the last element in List 1 point to the start of list 2
    last->nextPtr = (struct Node*) *Header_2;

    // Update the header of List2 to be the same as the header of List1
    *Header_2 = *Header;

}

int main(){
    return 1;
}