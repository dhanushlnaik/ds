#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node *Node;

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

Node push(Node top, int data) {
  Node newNode = createNode(data);
  newNode->next = top;
  return newNode;
}

Node pop(Node top) {
  if (top == NULL) {
    printf("Stack underflow\n");
    return top;
  }

  Node temp = top;
  printf("Popped element: %d\n", temp->data);
  top = top->next;
  free(temp);
  return top;
}

void display(Node top) {
  if (top == NULL) {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack elements are: ");
  while (top != NULL) {
    printf("%d ", top->data);
    top = top->next;
  }
  printf("\n");
}

int main() {
  Node top = NULL;
  int choice, data;

  while (1) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the element to push: ");
      scanf("%d", &data);
      top = push(top, data);
      break;
    case 2:
      top = pop(top);
      break;
    case 3:
      display(top);
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}
