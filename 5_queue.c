#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Check if queue is empty
int is_empty(struct Node* front) {
    return front == NULL;
}

// Traverse and print queue
void traverse(struct Node* front) {
    struct Node* ptr = front;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Enqueue at the end
struct Node* enqueue(struct Node* front, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL) {
        printf("Element %d added\n", data);
        return new_node; // queue was empty
    }

    struct Node* ptr = front;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    printf("Element %d added\n", data);
    return front;
}

// Dequeue from front
struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node* ptr = front;
    front = front->next;
    printf("Element %d removed\n", ptr->data);
    free(ptr);
    return front;
}

int main() {
    struct Node* front = NULL;

    front = enqueue(front, 123);
    front = enqueue(front, 179);
    front = enqueue(front, 89);
    front = enqueue(front, 190);

    printf("\nQueue after enqueue:\n");
    traverse(front);

    front = dequeue(front);
    front = dequeue(front);

    printf("\nQueue after dequeue:\n");
    traverse(front);

    return 0;
}