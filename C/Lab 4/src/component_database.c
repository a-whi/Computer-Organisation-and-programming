#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// 2.1
typedef struct component{
    char name[50]; // Component name
    int value; // Will always be a whole number
    char unit[5]; // letters
    int quantity; // Will always be a whole number
    float cost; // Cost in dollars could have decimal values for cents
    struct component *next;
}component;

// 2.2

// Search function to find components in the linked list returns a component pointer
// **head allows you to modify the original head pointer in the calling function, making it global
component* search_comp(component **head, char *name, int value, char *unit){
    component *current = *head;
    while(current!= NULL){
        if (strcmp(current->name, name) == 0 && current->value == value && strcmp(current->unit, unit) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Insert function
void insert_comp(component **head, char *name, int value, char *unit, int quantity, float cost){
    // First searches the list of components
    component *temp = search_comp(head, name, value, unit);
    if (temp){
        temp->quantity += quantity;
        temp->cost = cost;
    }else{
        // Creates a new struct
        // Allocate memoery for the new component
        component *new_comp = (component *) malloc(sizeof(component));

        // Now we copy the name and add it to the struct, we add a NULL character to indicate the end of the string
        strncpy(new_comp->name, name, sizeof(new_comp->name)-1);
        new_comp->name[sizeof(new_comp->name)-1] = '\0';

        new_comp->value = value;

        // Now we copy the unit and add it to the struct, we add a NULL character to indicate the end of the string
        strncpy(new_comp->unit, unit, sizeof(new_comp->unit)-1);
        new_comp->unit[sizeof(new_comp->unit)-1] = '\0';

        new_comp->quantity = quantity;
        new_comp->cost = cost;


        // Now we update next so it points at the old head
        new_comp->next = *head;
        // Now we update the head of the linked list to point at the new component
        *head = new_comp;
    }

}

// Delete function
void remove_comp(component **head, char *name, int value, char *unit, int quantity){
    // Searches for the component
    component *temp = search_comp(head, name, value, unit);
    if (temp){
        // Deducts the quanity
        temp->quantity -= quantity;

        //Checks there is still some left
        if (temp->quantity <= 0){
            if (head == &temp){
                // If its at the start it will be removed and the head will be updated
                *head = temp->next;
            }else{
                // Else we make the previous component the head for the next component
                component *prev = *head;                
                while (prev->next != temp) {
                    prev = prev->next;
                }
                prev->next = temp->next;
            }
            // Free the memory
            free(temp);
        }
    }
}

// Prints output for search
void search_print_comp(component **head, char *name, int value, char *unit){
    //Goes through the search_comp function
    component *found = search_comp(head, name, value, unit);
    if (found != NULL){
        printf("Component: %s %d %s, quantity: %d, price: %0.2f \n",found->name, found->value, found->unit, found->quantity, found->cost);
    }else{
        printf("Component: %s %d %s, quantity: 0 \n",name, value, unit);
    }
}

// Prints all components in the linked list
void print_comp(component *head){
    component *current = head;

    if (current == NULL){
        printf("No list, cannot print nothing\n");
    }
    while (current != NULL){
        printf("Component: %s %d %s, quantity: %d, price: %0.2f \n",current->name, current->value,current->unit,current->quantity,current->cost);
        current = current->next;
    }

}

// Exports all components in the linked list to a file
void export_comp(component **head, char* filename){
    component *current = *head;
    FILE *fp;

    fp = fopen(filename, "w");
    if (current == NULL){
        printf("No list, cannot export nothing\n");
    }
    while (current != NULL){
        fprintf(fp,"Component: %s %d %s, quantity: %d, price: %0.2f \n",current->name, current->value,current->unit,current->quantity,current->cost);
        current = current->next;
    }

    fclose(fp);
}

// Deallocates all memory and quits the program
void quit_comp(component **head){
    component *current = *head;
    while (current != NULL){
        component *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL; // Set the head to nothing after all memory is deallocated
}

int main(){
    component *head = NULL;
    char function[10];

    char name[50]; // Component name
    int value; // Will always be a whole number
    char unit[5]; // letters
    int quantity; // Will always be a whole number
    float cost; // Cost in dollars could have decimal values for cents

    char filename[100];

    while (1){
        //printf("Enter your command: ");
        scanf("%s", function);

        if (strcmp(function, "insert") == 0){
            scanf("%s %d %s %d %f", name, &value, unit, &quantity, &cost);
            insert_comp(&head, name, value, unit, quantity, cost);

        }else if (strcmp(function, "remove") == 0){
            scanf("%s %d %s %d", name, &value, unit, &quantity);
            remove_comp(&head, name, value, unit, quantity);

        }else if (strcmp(function, "search") == 0){
            scanf("%s %d %s", name, &value, unit);
            search_print_comp(&head, name, value, unit);

        }else if (strcmp(function, "print") == 0){
            print_comp(head);

        }else if (strcmp(function, "export") == 0){
            scanf("%s", filename);
            export_comp(&head, filename);
            
        }else if (strcmp(function, "quit") == 0){
            quit_comp(&head);
            return 0;

        }else{
            printf("INVALID, try again \n");
        }
    }
    return 0;
}