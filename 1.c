#include <stdio.h>
#include <stdlib.h> // Include this header for exit()

#define MAX 3

int top = -1, stack[MAX];

void push();
void pop();
void display();

int main() {
  int ch;
  while (1) {
    printf("\n*** Stack Menu ***");
    printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit");
    printf("\n\nEnter your choice (1-4): ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("\nExiting the program\n");
      exit(0);
    default:
      printf("\nWrong Choice!! Please enter a valid option.\n");
    }
  }
}

void push() {
  int val;
  if (top == MAX - 1) {
    printf("\nStack is full!! Cannot push more elements.\n");
  } else {
    printf("\nEnter element to push: ");
    scanf("%d", &val);
    top = top + 1;
    stack[top] = val;
    printf("\n%d pushed to the stack.\n", val);
  }
}

void pop() {
  if (top == -1) {
    printf("\nStack is empty. Cannot pop.\n");
  } else {
    printf("\nDeleted element is %d\n", stack[top]);
    top = top - 1;
  }
}

void display() {
  int i;
  if (top == -1) {
    printf("Stack is empty.\n");
  } else {
    printf("\nStack elements are:\n");
    for (i = top; i >= 0; --i)
      printf("%d\n", stack[i]);
  }
}
