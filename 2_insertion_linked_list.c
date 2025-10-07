#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};




struct Node *transverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The element is %d \n ", ptr->data);
        ptr = ptr->next;
    }
    return NULL;
}




struct Node *insert_beg(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insert_end(struct Node *head, int data)
{
    struct Node *ptr ;
    struct Node *p;
    p  = head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = data;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    return head;
}

struct Node * insert_b_idx(struct Node* head,int data,int index){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int j = 0;
    while(j < index-1){
        j++;
        p = p -> next;
    }
    ptr-> next = p->next;
    ptr -> data = data;
    p -> next = ptr;
    return head;

}






struct Node * insert_a_idx(struct Node* head,int data,int index){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int j = 0;
    while(j < index){
        j++;
        p = p -> next;
    }
    ptr-> next = p->next;
    ptr -> data = data;
    p -> next = ptr;
    return head;

}










int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *end;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    end = (struct Node *)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = first;

    first->data = 78;
    first->next = second;

    second->data = 19;
    second->next = third;

    third->data = 89;
    third->next = fourth;

    fourth->data = 100;
    fourth->next = fifth;

    fifth->data = 32;
    fifth->next = NULL;
    transverse(head);

    head = insert_beg(head, 123);
    printf("\n");
    printf("after inserting at begining  \n");
    transverse(head);
    head = insert_b_idx(head, 183,4);
    printf("after inserting before index. \n");

    transverse(head);
    printf("\n");
    printf("after inserting after index.  \n");
    head = insert_a_idx(head, 13,4);
    transverse(head);
    printf("\n");
    printf("after inserting at end. \n");
    head = insert_end(head,1234);
    transverse(head);

}