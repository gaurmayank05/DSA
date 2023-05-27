/*
                ***************Doubly Linked List***************
                               DATE- 27/05/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    struct nodetype *prev;
    int info;
    struct nodetype *next;
} node;

//------------------------------------------------------Function Declearation----------------------------------------------------
void Insertation_at_beg(node **, node **, node **, int);
void Insertation_at_end(node **, node **, node **, int);
void Insertation_after_element(node **, node **, node **, int);
void Insertation_before_element(node **, node **, node **, int);
void Traversal(node *);
void Reverse_traversal(node *);
node *search(node *, int);
int Deletion_at_beg(node **, node **);
int Deletion_at_end(node **, node **);
int Deletion_at_pos(node **, node **);
void Delete_entire(node **, node **);

//------------------------------------------------------MAIN Function------------------------------------------------------------
void main()
{
    node *head, *tail, *ptr;
    int item, operation;
    head = tail = NULL;
    while (1)
    {
        printf("\nEnter operation: \n");
        printf("1.Insertation at Beginning\n2.Insertation at End\n3.Insertation after an item\n4.Insertation before an item\n");
        printf("5.Traversal\n6.Reverse Traversal\n7.Deletion at beginning\n8.Deletion at End\n");
        printf("9.Deletion at any Position\n10.Delete entire List\n11.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            ptr = (node *)malloc(sizeof(node));
            if (ptr == NULL)
                printf("OverFlow");
            else
            {
                printf("Enter item: ");
                scanf("%d", &item);
                Insertation_at_beg(&head, &tail, &ptr, item);
            }
            break;
        case 2:
            ptr = (node *)malloc(sizeof(node));
            if (ptr == NULL)
                printf("OverFlow");
            else
            {
                printf("Enter item: ");
                scanf("%d", &item);
                Insertation_at_end(&head, &tail, &ptr, item);
            }
            break;
        case 3:
            ptr = (node *)malloc(sizeof(node));
            if (ptr == NULL)
                printf("OverFlow");
            else
            {
                printf("Enter item: ");
                scanf("%d", &item);
                Insertation_after_element(&head, &tail, &ptr, item);
            }
            break;
        case 4:
            ptr = (node *)malloc(sizeof(node));
            if (ptr == NULL)
                printf("OverFlow");
            else
            {
                printf("Enter item: ");
                scanf("%d", &item);
                Insertation_before_element(&head, &tail, &ptr, item);
            }
            break;
        case 5:
            if ((head == NULL) && (tail == NULL))
                printf("List is Empty");
            else
                Traversal(head);
            break;
        case 6:
            if ((head == NULL) && (tail == NULL))
                printf("List is Empty");
            else
                Reverse_traversal(tail);
            break;
        case 7:
            if ((head == NULL) && (tail == NULL))
                printf("UnderFlow");
            else
            {
                item = Deletion_at_beg(&head, &tail);
                printf("%d is deleted", item);
            }
            break;
        case 8:
            if ((head == NULL) && (tail == NULL))
                printf("UnderFlow");
            else
            {
                item = Deletion_at_end(&head, &tail);
                printf("%d is deleted", item);
            }
            break;
        case 9:
            if ((head == NULL) && (tail == NULL))
                printf("UnderFlow");
            else
            {
                item = Deletion_at_pos(&head, &tail);
                printf("%d is deleted", item);
            }
            break;
        case 10:
            if ((head == NULL) && (tail == NULL))
                printf("UnderFlow");
            else
                Delete_entire(&head, &tail);
            break;
        default:
            exit(0);
        }
    }
}

//------------------------------------------------------Insertation at Beginning-------------------------------------------------
void Insertation_at_beg(node **head, node **tail, node **ptr, int item)
{
    (*ptr)->info = item;
    (*ptr)->prev = NULL;
    if ((*head) == NULL)            // If list is initially Empty
    {
        (*ptr)->next = NULL;
        (*head) = (*tail) = (*ptr);
    }
    else
    {
        (*head)->prev = (*ptr);
        (*ptr)->next = (*head);
        (*head) = (*ptr);
    }
}

//------------------------------------------------------Insertation at End---------------------------------------------------------
void Insertation_at_end(node **head, node **tail, node **ptr, int item)
{
    (*ptr)->info = item;
    (*ptr)->next = NULL;
    if ((*head) == NULL)                            // If list is initially Empty
    {
        (*ptr)->prev = NULL;
        (*head) = (*tail) = (*ptr);
    }
    else
    {
        (*tail)->next = (*ptr);
        (*ptr)->prev = (*tail);
        (*tail) = (*ptr);
    }
}

//------------------------------------------------------Insertation after Item----------------------------------------------------
void Insertation_after_element(node **head, node **tail, node **ptr, int item)
{
    node *loc;
    int after_item;
    (*ptr)->info = item;
    if ((*head) == NULL)                                // If list is initially Empty
    {
        (*ptr)->next = NULL;
        (*ptr)->prev = NULL;
        (*head) = (*tail) = (*ptr);
    }
    else                                                // if list contain some item
    {
        printf("Enter after item: ");
        scanf("%d", &after_item);
        loc = search(*head, after_item);                   // address of item after which new item will insert
        if (loc == NULL)
            printf("Searched item is not found");
        else
        {
            (*ptr)->next = loc->next;                    // connecting new item with the next adjacent item
            (loc->next)->prev = (*ptr);             
            (*ptr)->prev = loc;                       
            loc->next = (*ptr);
        }
    }
}

//------------------------------------------------------Insertation after Item----------------------------------------------------
void Insertation_before_element(node **head, node **tail, node **ptr, int item)
{
    node *loc;
    int before_item;
    (*ptr)->info = item;
    if (*head == NULL)                              // If list is initially Empty
    {
        (*ptr)->next = (*ptr)->prev = NULL;
        (*head) = (*tail) = (*ptr);
    }
    else                                            // if list contain some item
    {
        printf("Enter before item: ");
        scanf("%d",&before_item);
        loc = search(*head,before_item);              // address of item before which new item will insert
        (loc->prev)->next=(*ptr);
        (*ptr)->prev= loc->prev;                       // connecting new item with the previous adjacent item
        (*ptr)->next=loc;
        loc->prev = (*ptr);
    }
}
//-----------------------------------------------------------Search Function-----------------------------------------------------
node *search(node *head, int item)
{
    while (head != NULL)
    {
        if (head->info == item)
            return head;
        head = head->next;
    }
    return NULL;
}

//-----------------------------------------------------------Traversal Function-----------------------------------------------------
void Traversal(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
}
//----------------------------------------------------------Reverse Traversal Function------------------------------------------------
void Reverse_traversal(node *tail)
{
    while (tail != NULL)
    {
        printf("%d ", tail->info);
        tail = tail->prev;
    }
}
//----------------------------------------------------------Deletion at Beginning Function------------------------------------------------
int Deletion_at_beg(node **head, node **tail)
{
    int item;
    node *loc;
    if ((*head)->next == NULL)                          // If list is initially Empty
    {
        item = (*head)->info;
        (*head) = (*tail) = NULL;
        free(*head);
        free(*tail);
    }
    else                                                // if list contain some item
    {
        loc = (*head);
        (*head) = (*head)->next;
        item = loc->info;
        free(loc);
    }
    return item;
}
//----------------------------------------------------------Deletion at End Function------------------------------------------------
int Deletion_at_end(node **head, node **tail)
{
    node *loc;
    int item;
    if ((*head)->next == NULL)                          // If list is initially Empty
    {
        item = (*head)->info;
        (*head) = (*tail) = NULL;
        free(*head);
        free(*tail);
    }
    else                                                  // if list contain some item
    {
        loc = (*tail);
        (*tail) = (*tail)->prev;
        (*tail)->next = NULL;
        item = (loc)->info;
        free(loc);
    }
    return item;
}
//----------------------------------------------------------Deletion at any Position Function------------------------------------------------
int Deletion_at_pos(node **head, node **tail)
{
    node *loc;
    int item, search_item;
    if ((*head)->next == NULL)                                  // If list is initially Empty
    {
        item = (*head)->info;
        (*head) = (*tail) = NULL;
        free(*head);
        free(*tail);
    }
    else                                                        // if list contain some item
    {
        printf("Enter item which is to be deleted: ");
        scanf("%d", &search_item);
        loc = search(*head, search_item);                       // address of the item which is to be deleted
        (loc->prev)->next = loc->next;
        (loc->next)->prev = loc->prev;
        item = loc->info;
        free(loc);
    }
    return item;
}
//----------------------------------------------------------Deletion Entire List Function------------------------------------------------
void Delete_entire(node **head, node **tail)
{
    node *loc;
    while ((*head) != NULL)
    {
        loc = (*head);
        (*head) = (*head)->next;
        free(loc);
    }
    (*tail) = NULL;
    printf("Entire list is deleted.");
}

//                                       ************************ END of PROGRAM ************************