//write a C program to find the depth of a binary tree node

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int findDepth(struct Node* root, int key, int depth) {
    
    if (root == NULL) {
        return -1;
    }
    
    if (root->data == key) {
        return depth;
    }
    
   
    int leftDepth = findDepth(root->left, key, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }
    
   
    return findDepth(root->right, key, depth + 1);
}

int main() {
   
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->left->left->left = createNode(7);
    
   
   
    printf("Depth of node with value 1: %d\n", findDepth(root, 1, 0));
    printf("Depth of node with value 4: %d\n", findDepth(root, 4, 0));
    printf("Depth of node with value 7: %d\n", findDepth(root, 7, 0));
    printf("Depth of node with value 6: %d\n", findDepth(root, 6, 0));
    
    return 0;
}