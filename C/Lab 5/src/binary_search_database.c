#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////
typedef struct component{
    char name[50]; //(E.g., “resistor”, “capacitor”, “LED”, etc.)
    int value; //This will always be a whole number
    char unit[5]; //(E.g., “R”, “nF”, “mcd”, etc.)
    int quantity; //Whole numbers
    float price; //Has decimals
}Component;

typedef struct NODE{
    Component data;
    struct NODE* left;
    struct NODE* right;
}NODE;
//////////////////////////////////////////////////////////////////

// Inserts all componets into the tree
struct NODE* insert(struct NODE* root, Component component, int quantity, float price){
    // If the current tree is empty, return a new node 
    if (root == NULL){
        struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
        new_node->data = component;
        new_node->data.quantity = quantity;
        new_node->data.price = price;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // Will return a positive or negative number
    // This will dictate which side of the tree it should go on
    int compare = strcmp(root->data.name, component.name);

    if (compare > 0){
        root->left = insert(root->left, component, quantity, price);
    }else if (compare < 0){
        root->right = insert(root->right, component, quantity, price);
    }else {
        // Now we have to compare the values
        compare = root->data.value - component.value;
        if (compare > 0){
            root->left = insert(root->left, component, quantity, price);
        }else if (compare < 0){
            root->right = insert(root->right, component, quantity, price);
        }else{
            // Now we have to compare the unit
            compare = strcmp(root->data.unit, component.unit);
            if (compare > 0){
                root->left = insert(root->left, component, quantity, price);
            }else if (compare < 0){
                root->right = insert(root->right, component, quantity, price);
            }else{
                root->data.quantity += quantity;
                root->data.price = price;
            }
        }
    }
    return root;
}
//////////////////////////////////////////////////////////////////

struct NODE* delete_comp(struct NODE* root, Component component, int quantity) {
    if (root == NULL) {
        printf("Component not found.\n");
        return NULL;
    }
    //Now look for the node
    int compare = strcmp(root->data.name, component.name);
    
    if (compare > 0) {
        root->left = delete_comp(root->left, component, quantity);
    } else if (compare < 0) {
        root->right = delete_comp(root->right, component, quantity);
    } else {
        compare = root->data.value - component.value;
        if (compare > 0) {
            root->left = delete_comp(root->left, component, quantity);
        } else if (compare < 0) {
            root->right = delete_comp(root->right, component, quantity);
        } else {
            compare = strcmp(root->data.unit, component.unit);
            if (compare > 0) {
                root->left = delete_comp(root->left, component, quantity);
            } else if (compare < 0) {
                root->right = delete_comp(root->right, component, quantity);
            } else {
                // Component found
                if (root->data.quantity > quantity) {
                    root->data.quantity -= quantity;
                    printf("Updated successfully.\n");
                } else if (root->data.quantity == quantity) { // quantity = 0 now
                    struct NODE* temp;
                    printf("Component removed successfully.\n");
                    
                    //Checking for children
                    if (root->left == NULL) {
                        temp = root->right; //Set temp as the child
                        free(root); // Deallocate the memory
                        return temp; // Basically return the child as the parent node to replace the one we removed
                    } else if (root->right == NULL) {
                        temp = root->left;
                        free(root);
                        return temp;
                    }
                    
                    // If there are 2 children
                    // Find which one should be the parent
                    temp = root->right;
                    // loop through the left children until we reach the leftmost node, which will be the inorder successor
                    while (temp && temp->left != NULL) {
                        temp = temp->left;  
                    }

                    // Replace root data with inorder successor
                    root->data = temp->data;

                    // Remove the inorder successor
                    root->right = delete_comp(root->right, temp->data, temp->data.quantity);
                }
            }
        }
    }
    return root;
}

//////////////////////////////////////////////////////////////////

// Searches for components
struct NODE* search(struct NODE* root, Component component){
    // If NULL, the value does not exist in the tree
    if (root == NULL){
        printf("Component: %s %d %s, quantity: %d", root->data.name, root->data.value, root->data.unit, root->data.quantity);

    }else if (strcmp(root->data.name, component.name) == 0 && root->data.value == component.value && strcmp(root->data.unit, component.unit) == 0){
        // Target is found
        printf("Component: %s %d %s, quantity: %d, price: %.2f", root->data.name, root->data.value, root->data.unit, root->data.quantity, root->data.price);
    }else{
        // Recursive case:
        int compare = strcmp(root->data.name, component.name);

        if (compare > 0){
            // Search left subtree
            return search(root->left, component);
        }else if (compare < 0){
            // Search right subtree
            return search(root->right, component);
        }else{
            // Compare the values
            compare = root->data.value - component.value;
            if (compare > 0){
                return search(root->left, component);
            }else if (compare < 0){
                return search(root->right, component);
            }else{
                // Compare the unit
                compare = strcmp(root->data.unit, component.unit);
                if (compare > 0){
                    return search(root->left, component);
                }else if (compare < 0){
                    return search(root->right, component);
                }
            }
        }
    }
}
//////////////////////////////////////////////////////////////////

// Prints all components in tree in order
void print(struct NODE* root){
    if (root == NULL){
        // Base case we have hit the end
        return;
    }
    print(root->left);
    printf("Component: %s %d %s, quantity: %d, price: %.2f\n", root->data.name, root->data.value, root->data.unit, root->data.quantity, root->data.price);
    print(root->right);
}
//////////////////////////////////////////////////////////////////

// Basic traverse function to go through the tree
void traverse(struct NODE* root, FILE* fp){
    if (root == NULL){
        return;
    }
    traverse(root->left, fp);
    fprintf(fp, "Component: %s %d %s, quantity: %d, price: %.2f\n", root->data.name, root->data.value, root->data.unit, root->data.quantity, root->data.price);
    traverse(root->right, fp);
}
// Exports all components in the binary tree to a file
void export(struct NODE* root, char* filename){

    FILE *fp = fopen(filename, "w");
    if (root == NULL){
        printf("No list, cannot export nothing\n");
    }else{
        traverse(root, fp);
    }
    fclose(fp);
}
//////////////////////////////////////////////////////////////////
void deallocate(struct NODE* root){
    if (root == NULL){
        return;
    }
    // Recursively delete left and right subtrees
    deallocate(root->left);
    deallocate(root->right);

    // Delete the current node
    // Checks to see is root == NULL though so there is no memory error
    if (root != NULL) {
        free(root);
        root = NULL;
    }
}

// Deallocates all memory and quits the program
void quit(struct NODE** root_ptr){
    // Calls the delete function which will recursivly remove all nodes and clear the memory
    deallocate(*root_ptr);

    // Sets the pointer to NULL when it finishes
    *root_ptr = NULL;
}
//////////////////////////////////////////////////////////////////

int main(){

    struct NODE* root = NULL;

    char function[10];

    char name[50];
    int value; 
    char unit[5]; 
    int quantity; 
    float price; 

    char filename[100];


    while (1){
        scanf("%s", function);

        if (strcmp(function, "insert") == 0){
            scanf("%s %d %s %d %f", name, &value, unit, &quantity, &price);
            Component component;
            strcpy(component.name, name);
            component.value = value;
            strcpy(component.unit, unit);
            root = insert(root, component, quantity, price);

        }else if (strcmp(function, "remove") == 0) {
            scanf("%s %d %s %d", name, &value, unit, &quantity);
            Component component;
            strcpy(component.name, name);
            component.value = value;
            strcpy(component.unit, unit);
            delete_comp(root, component, quantity);
        
        }else if (strcmp(function, "search") == 0){
            scanf("%s %d %s", name, &value, unit);
            Component component;
            strcpy(component.name, name);
            component.value = value;
            strcpy(component.unit, unit);
            search(root, component);

        }else if (strcmp(function, "print") == 0){
            print(root);

        }else if (strcmp(function, "export") == 0){
            scanf("%s", filename);
            export(root, filename);

        }else if (strcmp(function, "quit") == 0){
            quit(&root);
            return 0;

        }else{
            printf("INVALID input, please try again\n");
        }
    }
    return 0;
}