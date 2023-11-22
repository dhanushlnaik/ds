#include <stdio.h>
#include <stdlib.h>

#define que_size 4

int rear, front, q[10];

void insertq() {
  int item;
  if (rear == que_size - 1)
    printf("Queue Overflow\n");
  else {
    printf("Enter the Item\n");
    scanf("%d", &item);
    rear = rear + 1;
    q[rear] = item;
  }
}

int delq() {
  if (front > rear)
    return -1;
  else
    return (q[front++]);
}

void display() {
  int i;
  if (front > rear)
    printf("Queue Underflow\n");
  else {
    for (i = front; i <= rear; i++) {
      printf("%d\t\n", q[i]);
    }
  }
}

int main() {
  int ch, delitem;
  front = 0;
  rear = -1;
  while (1) {
    printf("1.Insert 2.Delete 3.Display 4.Exit\n");
    printf("Enter your Choice\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      insertq();
      break;
    case 2:
      delitem = delq();
      if (delitem == -1)
        printf("Queue Underflow\n");
      else
        printf("Deleted item= %d\n", delitem);
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice!! Try again\n");
      break;
    }
  }
  return 0;
}
