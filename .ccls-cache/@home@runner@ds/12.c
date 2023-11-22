#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("OUT OF MEMORY\n");
        exit(0);
    }
    return x;
}

NODE insert_front(int item, NODE head)
{
    NODE temp, first;
    temp = getnode();
    temp->info = item;
    first = head->link;
    head->link = temp;
    temp->link = first;
    return head;
}

NODE insert_rear(int item, NODE head)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    cur = head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE delete_rear(NODE head)
{
    NODE prev, cur;
    if (head->link == head)
    {
        printf("List is empty\n");
        return head;
    }
    cur = head->link;
    prev = head;
    while (cur->link != head)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = head;
    printf("The item deleted is %d\n", cur->info);
    free(cur);
    return head;
}

NODE delete_front(NODE head)
{
    NODE first, second;
    if (head->link == head)
    {
        printf("List is empty\n");
        return head;
    }
    first = head->link;
    second = first->link;
    head->link = second;
    printf("The item deleted is %d\n", first->info);
    free(first);
    return head;
}

void display(NODE head)
{
    NODE temp;
    if (head->link == head)
    {
        printf("List is empty\n");
        return;
    }
    printf("The contents of singly linked list: ");
    temp = head->link;
    while (temp != head)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    NODE head;
    int choice, item;
    head = getnode();
    head->link = head;
    for (;;)
    {
        printf("1: Insert_Front 2: Insert_Rear\t");
        printf("3: Delete_Front\t 4: Delete_Rear\t 5: Display\t 6: Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted in front: ");
            scanf("%d", &item);
            head = insert_front(item, head);
            break;
        case 2:
            printf("Enter the item to be inserted at rear: ");
            scanf("%d", &item);
            head = insert_rear(item, head);
            break;
        case 3:
            head = delete_front(head);
            break;
        case 4:
            head = delete_rear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again\n");
        }
    }
    return 0;
}
