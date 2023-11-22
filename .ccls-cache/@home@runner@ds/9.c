#include <stdio.h>
#include <stdlib.h>

#define qsize 3

void insert(int item, int q[], int *r) {
  int j;
  if (*r == qsize - 1) {
    printf("QUEUE OVERFLOW\n");
    return;
  }
  j = *r;
  while (j >= 0 && item < q[j]) {
    q[j + 1] = q[j];
    j--;
  }
  q[j + 1] = item;
  *r = *r + 1;
}

void display(int *r, int *f, int q[]) {
  int i;
  if (*f > *r)
    printf("QUEUE IS EMPTY\n");
  else {
    for (i = *f; i <= *r; i++)
      printf("%d ", q[i]);
  }
  printf("\n");
}

int delete (int *f, int *r, int q[]) {
  if (*f > *r)
    return -1;
  else
    return q[(*f)++];
}

int main() {
  int front, rear, ch, delitm, item, q[5];
  front = 0;
  rear = -1;
  while (1) {
    printf("ENTER YOUR CHOICE\n");
    printf("1. INSERT 2. DELETE 3. DISPLAY 4. EXIT\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("ENTER THE ITEM\n");
      scanf("%d", &item);
      insert(item, q, &rear);
      break;
    case 2:
      delitm = delete (&front, &rear, q);
      if (delitm == -1)
        printf("QUEUE UNDERFLOW\n");
      else
        printf("DELETED ITEM = %d\n", delitm);
      break;
    case 3:
      display(&rear, &front, q);
      break;
    case 4:
      exit(0);
    default:
      printf("INVALID CHOICE!! TRY AGAIN\n");
      break;
    }
  }
  return 0;
}
