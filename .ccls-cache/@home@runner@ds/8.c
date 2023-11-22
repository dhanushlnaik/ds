#include <stdio.h>
#include <stdlib.h>

#define que_size 5

// Define the structure for the circular queue
struct CircularQueue {
  int rear, front, count, item, q[que_size];
};

// Function to insert an element into the circular queue
void insertq(struct CircularQueue *cq) {
  if (cq->count == que_size) {
    printf("Queue is full\n");
    return;
  }
  cq->rear = (cq->rear + 1) % que_size;
  cq->q[cq->rear] = cq->item;
  cq->count++;
}

// Function to delete an element from the circular queue
int deleteq(struct CircularQueue *cq) {
  if (cq->count == 0)
    return -1;
  cq->item = cq->q[cq->front];
  cq->front = (cq->front + 1) % que_size;
  cq->count--;
  return cq->item;
}

// Function to display the elements of the circular queue
void displayq(struct CircularQueue *cq) {
  int i, f;
  if (cq->count == 0) {
    printf("Queue is empty\n");
    return;
  } else {
    printf("Queue elements are:\n");
    for (i = 1, f = cq->front; i <= cq->count; i++) {
      printf("%d\n", cq->q[f]);
      f = (f + 1) % que_size;
    }
  }
}

int main() {
  int ch, delitem;
  struct CircularQueue cq;
  cq.front = 0;
  cq.rear = -1;
  cq.count = 0;

  while (1) {
    printf("1. INSERT 2. DELETE 3. DISPLAY 4. EXIT\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter the Item: ");
      scanf("%d", &cq.item);
      insertq(&cq);
      break;
    case 2:
      delitem = deleteq(&cq);
      if (delitem == -1)
        printf("Queue Underflow\n");
      else
        printf("Deleted Item is %d\n", delitem);
      break;
    case 3:
      displayq(&cq);
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
