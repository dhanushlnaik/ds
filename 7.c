#include <stdio.h>
#include <stdlib.h>

#define que_size 5

int rear, front, count, item, q[que_size];

void insertq() {
  if (count == que_size) {
    printf("Queue is full\n");
    return;
  }
  rear = (rear + 1) % que_size;
  q[rear] = item;
  count++;
}

int deleteq() {
  if (count == 0)
    return -1;
  item = q[front];
  front = (front + 1) % que_size;
  count--;
  return item;
}

void displayq() {
  int i, f;
  if (count == 0) {
    printf("Queue is empty\n");
    return;
  } else {
    printf("Queue elements are:\n");
    for (i = 1, f = front; i <= count; i++) {
      printf("%d\n", q[f]);
      f = (f + 1) % que_size;
    }
  }
}

int main() {
  int ch, delitem;
  front = 0;
  rear = -1;
  count = 0;

  while (1) {
    printf("1. INSERT 2. DELETE 3. DISPLAY 4. EXIT\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter the Item: ");
      scanf("%d", &item);
      insertq();
      break;
    case 2:
      delitem = deleteq();
      if (delitem == -1)
        printf("Queue Underflow\n");
      else
        printf("Deleted Item is %d\n", delitem);
      break;
    case 3:
      displayq();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid Choice\n");
      break;
    }
  }

  return 0;
}
