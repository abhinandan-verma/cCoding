#include<stdio.h>
#include<stdlib.h>

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

struct node* findNode(int key){
    if(head == NULL){
        printf("No list found");
        return NULL;
    }else{
        struct node* save = head;
        struct node* ptr = head->next;
        while(ptr != NULL){
            if(key <= save->data){
               return save;
            }else{
                save = ptr;
                ptr = ptr->next;
            }
        }
        return save;
    }
}
void insertAtNode(struct node* location, int item){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    if(location == NULL){
        new->next = head;
        head = new;
    }else{
        new->next = location->next;
        location->next = new;
    }
}

void deleteStartringNode(){
    
    if(head == NULL){
        printf("Underflow...");
        return;
    }
    struct node* current = head;
    head = head->next;
    free(current);
    printf("First Node deleted Successfully\n");
}


void displayList(){
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
     printf("NULL\n");
}

int main(){
   head = (struct node *)malloc(sizeof(struct node));
    head->data =  100;
    head->next = NULL;

    printf("1. Insert Element\n");
    printf("2. Delelte node with a key\n");
    printf("3. Insert node at a given Location\n");
    printf("4. Display the List\n");
    printf("5. -1 to exit\n");
    int choice;
    
    while(choice != -1){
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the Item to be Inserted :  ");
            int a;
            scanf("%d",&a);
            insertNode(a);
            break;
        case 2: 
            deleteStartringNode();
            break;
        case 3: printf("Enter the item to be inserted  : ");
            int k;
            scanf("%d",&k);
            insertAtNode(findNode(k),k);
            break;
        case 4:printf("List is printed here\n");
             displayList();
            break;
        default:printf("Enter legal Choice\n");
            break;
        }
    }
    printf("Exiting... :)");
    return 0;
}