#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

int findMinimumDepth(node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    if(root->left == NULL){
        return findMinimumDepth(root->right) + 1;
    }
    if(root->right == NULL){
        return findMinimumDepth(root->left) + 1;
    }
    return (findMinimumDepth(root->left) < findMinimumDepth(root->right)) ? findMinimumDepth(root->left) + 1 : findMinimumDepth(root->right) + 1;
}

int main(){

    node *root = (node *)malloc(sizeof(node));
    root->data = 1;
    root->left = (node *)malloc(sizeof(node));
    root->right = (node *)malloc(sizeof(node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    printf("%d\n", findMinimumDepth(root));
    free(root);

    return 0;
}