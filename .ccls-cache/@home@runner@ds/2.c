#include <stdio.h>
#include <stdlib.h> // Include this header for exit()

#define MAX 3

struct Stack {
  int top;
  int array[MAX];
};

typedef struct Stack Stack;

void push(Stack *s);
void pop(Stack *s);
void display(Stack *s);

int main() {
  Stack s;
  s.top = -1;

  int ch;
  while (1) {
    printf("\n*** Stack Menu ***");
    printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit");
    printf("\n\nEnter your choice (1-4): ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      push(&s);
      break;
    case 2:
      pop(&s);
      break;
    case 3:
      display(&s);
      break;
    case 4:
      printf("\nExiting the program\n");
      exit(0);
    default:
      printf("\nWrong Choice!! Please enter a valid option.\n");
    }
  }
}

void push(Stack *s) {
  int val;
  if (s->top == MAX - 1) {
    printf("\nStack is full!! Cannot push more elements.\n");
  } else {
    printf("\nEnter element to push: ");
    scanf("%d", &val);
    s->top = s->top + 1;
    s->array[s->top] = val;
    printf("\n%d pushed to the stack.\n", val);
  }
}

void pop(Stack *s) {
  if (s->top == -1) {
    printf("\nStack is empty. Cannot pop.\n");
  } else {
    printf("\nDeleted element is %d\n", s->array[s->top]);
    s->top = s->top - 1;
  }
}

void display(Stack *s) {
  int i;
  if (s->top == -1) {
    printf("Stack is empty.\n");
  } else {
    printf("\nStack elements are:\n");
    for (i = s->top; i >= 0; --i)
      printf("%d\n", s->array[i]);
  }
}
