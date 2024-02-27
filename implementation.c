#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* next;
};

struct node* head;

void insertNode(int item){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->next = head;
    head = new;
    printf("New item %d inserted at the begining\n", head -> data);
    return;
}

void deleteNode(int item){
    if(head == NULL){
        printf("Underflow...");
        return;
    }
    struct node* current = head;
    struct node* previous = NULL;
    while(current != NULL){
        if(current->data == item){
            if(previous == NULL){
                head = current->next;
                free(current);
                printf("Item %d deleted successfully\n", item);
                return;
            }else{
                previous->next = current->next;
                free(current);
                printf("Item %d deleted successfully\n", item);
                return;
            }
        }else{
            previous = current;
            current = current->next;
        }
    }
    printf("Item %d not found\n", item);
    return;
}

void printList(){
    if(head == NULL){
        printf("No list found\n");
        return;
    }
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void insertAfterGivenNode(int item, int after){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    struct node* ptr = head;
    while(ptr != NULL){
        if(ptr->data == after){
            new->next = ptr->next;
            ptr->next = new;
            printf("Item %d inserted after %d\n", item, after);
            return;
        }
        ptr = ptr->next;
    }
    printf("Item %d not found\n", after);
    return;
}

int main(){

    head = NULL;
    printf("Welcome to Linked List\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Print List\n");
    printf("4. Exit\n");
    printf("5. Insert after given node\n");
    printf("Enter your choice\n");

    
    int choice = 0, item;
    scanf("%d", &choice);
    
   while(choice != -1){
        switch(choice){
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%d", &item);
                insertNode(item);
                break;
            case 2:
                printf("Enter the item to be deleted\n");
                scanf("%d", &item);
                deleteNode(item);
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            case 5:
                printf("Enter the item to be inserted\n");
                scanf("%d", &item);
                printf("Enter the item after which %d is to be inserted\n", item);
                int after;
                scanf("%d", &after);
                insertAfterGivenNode(item, after);
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("Enter your choice\n");
        scanf("%d", &choice);
   }

   printf("Exiting...\n");

    return 0;
}