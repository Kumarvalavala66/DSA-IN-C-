#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void traverse(struct Node*head){
    struct Node*ptr = head;
      do{
        
        printf("the element is %d \n",ptr -> data);
        ptr = ptr -> next;
    }
    while (ptr   != head);
    

    free(ptr);
    
}
struct Node* insert_beg(struct Node*head,int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL) return NULL; 
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
    
    
}

int main(){
    struct Node * head;
    struct Node * one;
    struct Node * two;
    struct Node * three;
    struct Node * four;
    struct Node * five;

    head = (struct Node*)malloc(sizeof(struct Node));
    one = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    three = (struct Node*)malloc(sizeof(struct Node));
    four = (struct Node*)malloc(sizeof(struct Node));
    five = (struct Node*)malloc(sizeof(struct Node));


    head -> data = 12;
    one -> data = 51;
    two -> data = 21;
    three -> data = 38;
    four -> data = 49;
    five -> data = 52;




    head -> next = one;
    one -> next = two;
    two -> next = three;
    three -> next = four;    
    four -> next = five;
    five -> next = head;

    traverse(head);
    printf("\n");
    head = insert_beg(head,123);
    traverse(head);
    return 0;


}

