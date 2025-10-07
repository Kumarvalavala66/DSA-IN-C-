#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != 0)
    {
        printf("The element is :::::::::: %d \n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *delete_beg(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node* delete_end(struct Node* head){
    struct Node* ptr = head;
    struct Node* p = ptr -> next;
    while(p -> next != NULL){
        p = p-> next;
        ptr = ptr -> next;
    }
    ptr -> next = NULL;
    free(p);
    return head;

}

struct Node *delete_idx(struct Node *head, int idx)
{
    if (idx == 0)
    {
        head = delete_beg(head);
        return head;
    }
    if (head == NULL)
        return head;
    struct Node *ptr = head;
    struct Node *p = head;
    int i = 0;
    while ((i < idx-1) && (p->next != NULL))
    {
        p = p->next;
        i++;
    }
    ptr = p->next;
    p->next = ptr->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *one;
    struct Node *two;
    struct Node *three;
    struct Node *four;
    struct Node *five;
    struct Node *six;

    head = (struct Node *)malloc(sizeof(struct Node));
    one = (struct Node *)malloc(sizeof(struct Node));
    two = (struct Node *)malloc(sizeof(struct Node));
    three = (struct Node *)malloc(sizeof(struct Node));
    four = (struct Node *)malloc(sizeof(struct Node));
    five = (struct Node *)malloc(sizeof(struct Node));
    six = (struct Node *)malloc(sizeof(struct Node));

    head->data = 12;
    head->next = one;

    one->data = 45;
    one->next = two;

    two->data = 78;
    two->next = three;

    three->data = 90;
    three->next = four;

    four->data = 34;
    four->next = five;

    five->data = 23;
    five->next = six;

    six->data = 67;
    six->next = NULL;
    traversal(head);

    head = delete_end(head);
    printf("\n");
    traversal(head);
    return 0;
}