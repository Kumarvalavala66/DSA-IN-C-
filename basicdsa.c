#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void transverse(struct Node*ptr){
    while(ptr -> next != NULL){
        printf("The element is %d \n",ptr->data);
        ptr = ptr -> next;
    }
}



struct Node* insert_beg(struct Node* head,int data){
    struct Node*ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}


struct Node* insert_b_idx (struct  Node*head,int data,int idx){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p= head;
    int i =0;
    while(i < idx-1){
        p  = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    ptr -> data = data;
    p -> next = ptr;
    return head;
}


struct Node* insert_end(struct Node * head,int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head;
    while(p -> next != NULL){
        p = p -> next;
    }
     p ->next =  ptr;
    ptr -> next = NULL;
    ptr -> data = data;
   
    return head;
}


struct Node* insert_a_idx (struct  Node*head,int data,int idx){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head;
    int i =0;
    while(i < idx){
        p  = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    ptr -> data = data;
    p -> next = ptr;
    return head;


}



int main(){
    struct Node*head;
    struct Node*first;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;
    struct Node*fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head ->data = 4;
    head -> next = first;
     

    first ->data = 5;
    first -> next = second;

    second ->data = 6;
    second -> next = third;

    third ->data = 7;
    third -> next = fourth;

    fourth ->data = 8;
    fourth -> next = fifth;

    fifth ->data = 678;
    fifth -> next = NULL;

    transverse(head);

    head = insert_beg(head,3);
    printf("\n");
    transverse(head);

 printf("\n");
    head = insert_b_idx(head,10,3);
    transverse(head);
 printf("\n");

    head = insert_a_idx(head,12,3);
    transverse(head);

printf("\n");
    head = insert_end(head,15);
    transverse(head);
}