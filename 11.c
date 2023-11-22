#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* Node;

Node createNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node front;
    Node rear;
} Queue;

Queue initializeQueue() {
    Queue q;
    q.front = q.rear = NULL;
    return q;
}

int isEmpty(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue *q, int data) {
    Node newNode = createNode(data);
    if (isEmpty(*q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue underflow\n");
        exit(1);
    }

    int data = q->front->data;
    Node temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node current = q.front;
    printf("Queue elements are: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q = initializeQueue();
    int choice, data;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                if (!isEmpty(q)) {
                    printf("Dequeued element: %d\n", dequeue(&q));
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
