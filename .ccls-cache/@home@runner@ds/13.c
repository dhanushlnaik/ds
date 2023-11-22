#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *rlink;
  struct node *llink;
};

typedef struct node *NODE;

NODE getnode() {
  NODE x;
  x = (NODE)malloc(sizeof(struct node));
  if (x == NULL) {
    printf("OUT OF MEMORY\n");
    exit(0);
  }
  return x;
}

NODE insertfront(int item, NODE head) {
  NODE temp, cur;
  temp = getnode();
  temp->info = item;

  if (head->rlink == NULL) {
    head->rlink = temp;
    temp->llink = head;
    temp->rlink = NULL;
    head->llink = NULL;
    return head;
  } else {
    cur = head->rlink;
    temp->rlink = cur;
    head->rlink = temp;
    cur->llink = temp;
    temp->llink = head;
    return head;
  }
}

NODE insertrear(int item, NODE head) {
  NODE temp, cur;
  temp = getnode();
  temp->info = item;

  if (head->rlink == NULL) {
    head->rlink = temp;
    head->llink = NULL;
    temp->rlink = NULL;
    temp->llink = head;
    return head;
  }

  cur = head->rlink;
  while (cur->rlink != NULL) {
    cur = cur->rlink;
  }

  cur->rlink = temp;
  temp->rlink = NULL;
  temp->llink = cur;
  head->llink = NULL;
  return head;
}

NODE delfront(NODE head) {
  NODE temp, cur;
  if (head->rlink == NULL) {
    printf("LIST IS EMPTY \n");
    return head;
  }

  temp = head->rlink;
  cur = temp->rlink;

  if (cur == NULL) {
    head->rlink = NULL;
  } else {
    head->rlink = cur;
    cur->llink = head;
  }

  printf("DELETED ITEM = %d\n", temp->info);
  free(temp); // FREEING MEMORY
  return head;
}

NODE delrear(NODE head) {
  NODE temp, cur;
  if (head->rlink == NULL) {
    printf("LIST IS EMPTY\n");
    return head;
  } else {
    temp = head->rlink;
    while (temp->rlink != NULL) {
      temp = temp->rlink;
    }

    if (temp->llink == head)
      head->rlink = NULL;
    else {
      cur = temp->llink;
      cur->rlink = NULL;
      head->llink = NULL;
    }

    printf("DELETED ITEM = %d\n", temp->info);
    free(temp);
    return head;
  }
}

void display(NODE head) {
  NODE temp;
  if (head->rlink == NULL) {
    printf("LIST IS EMPTY\n");
  } else {
    temp = head->rlink;
    while (temp != NULL) {
      printf("%d ", temp->info);
      temp = temp->rlink;
    }
  }
  printf("\n");
}

int main() {
  int ch, item;
  NODE head = getnode();
  head->info = 0; // Dummy value
  head->rlink = NULL;
  head->llink = NULL;

  while (1) {
    printf("1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear "
           "5.Display 6.Exit\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("ENTER THE ITEM\n");
      scanf("%d", &item);
      head = insertfront(item, head);
      break;
    case 2:
      printf("ENTER THE ITEM\n");
      scanf("%d", &item);
      head = insertrear(item, head);
      break;
    case 3:
      head = delfront(head);
      break;
    case 4:
      head = delrear(head);
      break;
    case 5:
      display(head);
      break;
    case 6:
      exit(0);
      break;
    default:
      printf("INVALID CHOICE!!TRY AGAIN\n");
      break;
    }
  }

  return 0;
}
