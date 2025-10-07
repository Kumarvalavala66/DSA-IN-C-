#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
int is_empty(struct Node *top)
{
    if (top == NULL)
        return -1;
    return 0;
}
void traverse(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("the element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *push(struct Node *top, int data)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = top;
    new_node->data = data;
    printf("%d is pushed in \n", new_node->data);
    top = new_node;
    return top;
}
struct Node *pop(struct Node *top)
{
    if (is_empty(top) == -1)
    {
        printf("list in underflow can't pop \n");
        return top;
    }
    struct Node *ptr = top;
    printf("%d is poped out \n", top->data);
    top = top->next;
    free(ptr);
    return top;
}

void peek(struct Node *top)
{
    if (is_empty(top) == -1)
    {
        printf("the stack is empty nothing to display");
    }
    else
    {
        printf("the top element is %d \n", top->data);
    }
}

int main()
{
    struct Node *top = NULL;
    printf("cheacking stack for empty \n\n");
    is_empty(top);
    printf("pushing elements \n\n");
    top = push(top, 123);
    top = push(top, 156);
    top = push(top, 245);
    top = push(top, 675);
    top = push(top, 891);

    printf("now traversing \n\n");
    traverse(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);

    printf("after poping traversing\n \n");
    traverse(top);
    printf("displaying top \n \n");
    peek(top);

    return 0;
}
