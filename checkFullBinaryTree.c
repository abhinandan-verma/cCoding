#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

int checkFullBinaryTree(node *root){
    if(root == NULL){
        return 1;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    if(root->left != NULL && root->right != NULL){
        return (checkFullBinaryTree(root->left) && checkFullBinaryTree(root->right));
    }
    return 0;
}

int main(){

    node *root = (node *)malloc(sizeof(node));
    root->data = 1;
    root->left = (node *)malloc(sizeof(node));
    root->right = (node *)malloc(sizeof(node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->data = 9;
    root->right->left = NULL;
    root->right->right = NULL;
    printf("%d\n", checkFullBinaryTree(root));
    free(root);
    return 0;
}