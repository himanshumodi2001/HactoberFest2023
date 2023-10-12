#include <stdio.h>
#include <stdlib.h>
// Declare Linked List
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
// Create Linked List from an array
void create(int arr[], int sz)
{
    struct Node *p, *q;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    q = first;
    for (i = 1; i < sz; i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = arr[i];
        p->next = NULL;
        q->next = p;
        q = p;
    }
}
// Length of the linked list
int length_LL(struct Node *p)
{
    int c;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return (c);
}
// Insert in the beginning
void insert_begin(struct Node *p, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = first;
    first = t;
}
// Insert at the end
void insert_end(struct Node *p, int x)
{
    struct Node *t;
    p = first;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    while (p->next != NULL)
        p = p->next;
    p->next = t;
}
// Insert at any position
void insert_pos(struct Node *p, int x, int index)
{
    struct Node *t;
    int i;
    if (index < 0 || index > length_LL(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    for (i = 0; i < index - 1; i++)
        p = p->next;
    t->next = p->next;
    p->next = t;
}
// Delete link with a particular value
void delete_val(struct Node *p, int val)
{
    struct Node *q = NULL;
    int x = 1;
    q = first;
    while (p->data != val)
    {
        q = p;
        p = p->next;
        x++;
    }
    q->next = p->next;
    free(p);
    printf("Element is deleted from %d node.\n", x);
}
// Delete link with a particular location
void delete_pos(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > length_LL(p))
        printf("Invalid index\n");
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        // return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        // return x;
    }
    printf("Deleted element is %d.\n", x);
}
// Deleting an element from the beginning
void delete_begin(struct Node *p)
{
    struct Node *q = NULL;
    int x = -1, i;
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    printf("Deleted element is %d.\n", x);
}
// Deleting an element from the last
void delete_end(struct Node *p)
{
    struct Node *q = NULL;
    int x = -1, i;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    printf("Deleted element is %d.\n", x);
}
// Search an element
struct Node *search(struct Node *p, int key)
{
    struct Node *q;
    int count = 0;
    while (p != NULL)
    {
        count++;
        if (key == p->data)
        {
            printf("Element is at node %d.\n", count);
        }
        p = p->next;
    }
    return NULL;
}
// Reverse Linked List
void reverse(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * length_LL(p));
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
// Count even and odd elements
void count_even_odd(struct Node *p)
{
    int even = 0, odd = 0;
    while (p != NULL)
    {

        if (p->data % 2 == 0) // If element is even
        {
            even++;
        }
        else // If element is odd
        {
            odd++;
        }
        p = p->next;
    }
    printf("Number of odd elements = %d.\n", odd);
    printf("Number of even elements = %d.\n", even);
    printf("\n");
}
// Display Linked List
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    int n, i, x, pos, err = 0;
    // If user enters incorrect choice for 3 consecutive time, then program
    terminates automatically.printf("Enter the number of elements in the Linked List: ");
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    create(A, n);
    printf("Select your choice: "
                                           "\n\t1.\tInsertion in the beginning of list"
                                           "\n\t2.\tInsertion at the end of the list"
                                           "\n\t3.\tInsertion in a particular location of the list"
                                           "\n\t4.\tDeletion based on a particular value"
                                           "\n\t5.\tDeletion based on a particular location"
                                           "\n\t6.\tDeleting an element at the beginning"
                                           "\n\t7.\tDeleting an element at the end of the list"
                                           "\n\t8.\tSearch an element"
                                           "\n\t9.\tReverse the list"
                                           "\n\t10.\tCount the number of even and odd numbers in the list"
                                           "\n\t11.\tDisplay the contents of the list"
                                           "\n\t12.\tStop and exit\n");
    int ch = 0;
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the data to be inserted: ");
            scanf("%d", &x);
            insert_begin(first, x);
            err = 0;
        }
        break;
        case 2:
        {
            printf("Enter the data to be inserted: ");
            scanf("%d", &x);
            insert_end(first, x);
            err = 0;
        }
        break;
        case 3:
        {
            printf("Enter the data to be inserted: ");
            scanf("%d", &x);
 printf("Enter the position after which elements has to be
inserted: ");
 scanf("%d", &pos);
 if(pos == 0)
 insert_begin(first,pos);
 else if(pos == length_LL(first))
 insert_end(first,x);
 else
 insert_pos(first,x,pos);
 err = 0;
        }
        break;
        case 4:
        {
 printf("Enter the value to be deleted: ");
 scanf("%d", &x);
 delete_val(first, x);
 err = 0;
        }
        break;
        case 5:
        {
 printf("Enter the position of the node which has to be
deleted: ");
 scanf("%d", &x);
 delete_pos(first,x);
 err = 0;
        }
        break;
        case 6:
        {
 delete_begin(first);
 err = 0;
        }
        break;
        case 7:
        {
 delete_end(first);
 err = 0;
        }
        break;
        case 8:
        {
 printf("Enter the element to be searched: ");
 scanf("%d", &x);
 search(first, x);
 err = 0;
        }
        break;
        case 9:
        {
 reverse(first);
 err = 0;
        }
        break;
        case 10:
        {
 count_even_odd(first);
 err = 0;
        }
        break;
        case 11:
 display(first);
 break;
        case 12:
 exit(0);
        default:
        {
 err++;
 if (err == 3)
 {
     exit(0);
 }
 printf("Enter the correct choice.\n");
        }
        }
    } while (ch >= 0);
    return 0;
}
