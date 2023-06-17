#include <stdio.h>
#include <stdlib.h>
struct BinaryTreeNode{};

// Lowest common ansester problem BST
int find_parent(struct BinaryTreeNode root, int value1, int value2){
    if (root == NULL){
        return -1;
    }

    // If val1 and val2 are both smaller than the root we search left, but if they are on different sides of the 
    // tree then we should just return the current node as it will be the lowest parent
    if (root->data > value1 && root->data > value2 ){
        return find_parent(root->left, value1, value2);
    } else if (root->data < value1 && root->data < value2){
        return find_parent(root->right, value1, value2);
    }
    return root->data;
};
