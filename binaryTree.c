// C code to implement a binary tree

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node
struct node *searchNode(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// Function to find the minimum value in a tree

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
struct node *deleteNode(struct node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the tree in order
void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to print the tree in pre-order
void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to print the tree in post-order
void postOrder(struct node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Main function

int main() {
    struct node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("In order: ");
    inOrder(root);
    printf("\n");
    printf("Pre order: ");
    preOrder(root);
    printf("\n");
    printf("Post order: ");
    postOrder(root);
    printf("\n");
    printf("Searching for 40: ");
    if (searchNode(root, 40) != NULL) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
    printf("Searching for 100: ");
    if (searchNode(root, 100) != NULL) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }
    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("In order: ");
    inOrder(root);
    printf("\n");
    printf("Deleting 30\n");
    root = deleteNode(root, 30);
    printf("In order: ");
    inOrder(root);
    printf("\n");
    printf("Deleting 50\n");
    root = deleteNode(root, 50);
    printf("In order: ");
    inOrder(root);
    printf("\n");
    return 0;
}