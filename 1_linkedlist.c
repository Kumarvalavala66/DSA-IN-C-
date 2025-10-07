#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void tranversal(struct Node *ptr){
    while (ptr!= NULL)
    {
        printf("The element is %d \n ", ptr -> data);
        ptr  = ptr-> next;
    }
    
}

int main()
{
    //allocating memeory 

    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    

    // data allocation and assigning the next value 


    head->data = 12;
    head -> next = first;

    first->data = 17;
    first -> next = second;

    second->data = 12;
    second -> next = third;

    third->data = 12;
    third -> next = fourth;

    fourth->data = 12;
    fourth -> next = NULL;
  
    tranversal(head);
    return 0;
}