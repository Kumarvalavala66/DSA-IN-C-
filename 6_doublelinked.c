#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
void traverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("the element is %d \n ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insert_beg(struct Node *head, int data)
{
    struct Node *ptr = head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}
struct Node *insert_end(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL)
        return ptr;

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;

    return head;
}
struct Node *insert_b_idx(struct Node *head, int data, int idx)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL)
        return ptr;
    struct Node *p = head;
    int i = 0;
    while (i < idx - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    if (p->next != NULL)
        (p->next)->prev = ptr;

    p->next = ptr;
    return head;
}

struct Node *insert_a_idx(struct Node *head, int data, int idx)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL)
        return ptr;
    struct Node *p = head;
    int i = 0;
    while (i < idx)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    if (p->next != NULL)
        (p->next)->prev = ptr;

    p->next = ptr;
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

    head->data = 10;
    head->prev = NULL;
    head->next = one;

    one->data = 145;
    one->prev = head;
    one->next = two;

    two->data = 1032;
    two->prev = one;
    two->next = three;

    three->data = 1353;
    three->prev = two;
    three->next = four;

    four->data = 1212;
    four->prev = three;
    four->next = five;

    five->data = 1010;
    five->prev = four;
    five->next = six;

    six->data = 2344;
    six->prev = five;
    six->next = NULL;

    traverse(head);
    printf("\n ");
    head = insert_a_idx(head, 1234, 3);
    traverse(head);

    return 0;
}
