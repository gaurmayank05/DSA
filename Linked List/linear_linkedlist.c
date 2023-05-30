/*
                            Linear Linked List Program
                            DATE- 22/05/2023
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int info;              // Structure Template
    struct nodetype *next; // self referential structure
} node;

//----------------------------------------------------Function Decleartion----------------------------------------------------
void Insert_at_Beg(node **);
void Insert_at_End(node **);
void Insert_after_element(node **);
node *search(node *, int);
void traversal(node *);
void reverse_traversal(node *);
int Deletion_at_Beg(node **);
int Delete_at_End(node **);
int Delete_at_pos(node **);
void Delete_Entire(node **);

//  =============================================================Main Function=======================================================================================
void main()
{
    node *head = NULL, *ptr;
    int operation, result;
    while (1)
    {
        printf("\nEnter operation: \n1.Insertation from Beginning\n2.Insertation from End\n");
        printf("3.Insertation after an Element\n4.Traversal\n5.Reverse Traversal\n6.Deletion from Beginning\n7.Delete From Ending\n");
        printf("8.Delete at any position\n9.Delete entire list\n10.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            Insert_at_Beg(&head);
            break;
        }
        case 2:
        {
            Insert_at_End(&head);
            break;
        }
        case 3:
            Insert_after_element(&head);
            break;
        case 4:
        {
            if (head == NULL)
                printf("There is no element in list\n");
            else
                traversal(head);
            break;
        }
        case 5:
        {
            if (head == NULL)
                printf("There is no element in list\n");
            else
                reverse_traversal(head);
            break;
        }
        case 6:
        {
            if (head == NULL)
                printf("UnderFlow");
            else
            {
                result = Deletion_at_Beg(&head);
                printf("%d is deleted.", result);
            }
            break;
        }
        case 7:
        {
            if (head == NULL)
                printf("UnderFlow");
            else
            {
                result = Delete_at_End(&head);
                printf("%d is deleted.", result);
            }
            break;
        }
        case 8:
        {
            if (head == NULL)
                printf("UnderFlow");
            else
            {
                result = Delete_at_pos(&head);
                printf("%d is deleted.", result);
            }
            break;
        }
        case 9:
        {
            if (head == NULL)
                printf("UnderFlow");
            else
                Delete_Entire(&head);
            break;
        }
        default:
            exit(0);
        }
    }
}

// ========================================Insertation From Beginning Function========================================
void Insert_at_Beg(node **head)
{
    int item;
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
        printf("OverFlow");
    else
    {
        printf("Enter item: ");
        scanf("%d", &item);
        ptr->info = item;

        if ((*head) == NULL)                    // Initially Empty
            ptr->next = NULL;
        else
            ptr->next = (*head);
        (*head) = ptr;
    }
}

// ==============================================Insertation From Ending Function=======================================
void Insert_at_End(node **head)
{
    int item;
    node *ptr, *loc;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
        printf("OverFlow");
    else
    {
        printf("Enter item: ");
        scanf("%d", &item);
        ptr->info = item;
        ptr->next = NULL;
        if ((*head) == NULL)                            // List initially Empty
            (*head) = ptr;
        else
        {
            loc = (*head);
            while (loc->next != NULL)
                loc = loc->next;
            loc->next = ptr;
        }
    }
}

// ==============================================Insertation after Given Element Function=======================================
void Insert_after_element(node **head)
{
    int item, search_item;
    node *ptr, *loc;
    ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
        printf("OverFlow");
    else
    {
        printf("\nEnter item: ");
        scanf("%d", &item);
        ptr->info = item;
        if ((*head) == NULL)                    // Initially Empty List
        {
            ptr->next = NULL;
            *head = ptr;
        }
        else
        {
            printf("Enter insert after element: ");             
            scanf("%d", &search_item);
            loc = search(*head, search_item);               // Contain address of specific item
            if (loc == NULL)
                printf("\nEnter searched item is not found\n");
            else
            {
                ptr->next = loc->next;
                loc->next = ptr;
            }
        }
    }
}

// ============================================Traversal Function===============================================================
void traversal(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
}

// ============================================Reverse Order Traversal Function============================================
void reverse_traversal(node *head)
{
    if(head->next!=NULL)
        reverse_traversal(head->next);                  // Using Recursion 
    printf("%d ",head->info);
}
// ========================================Search Function=============================================================
node *search(node *loc, int search_item)                // It will return the address of selected item
{
    while (loc != NULL)
    {
        if (loc->info == search_item)
            return loc;
        loc = loc->next;
    }
    return NULL;                                      // if item will not in the list
}
// ==============================================Deletion From Beginnig Function=======================================
int Deletion_at_Beg(node **head)
{
    int item;
    node *ptr;
    ptr = (*head);
    item = ptr->info;
    (*head) = ptr->next;
    free(ptr);
    return item;
}

// ==============================================Deletion From Ending Function=======================================
int Delete_at_End(node **head)
{
    node *temp, *loc;
    int item;
    if ((*head)->next == NULL)          // if list contain only one node
    {
        item = (*head)->info;
        (*head) = NULL;
        free(*head);
    }
    else
    {
        temp = (*head);
        while ((temp->next)->next != NULL)
            temp = temp->next;
        loc = temp->next;
        temp->next = NULL;
        item = loc->info;
        free(loc);
    }
    return item;
}
// =========================================Deletion after any Element Function=======================================
int Delete_at_pos(node **head)
{
    node *loc, *ptr;
    int item, search_item;
    ptr = (*head);
    printf("Enter item which is to be deleted: ");
    scanf("%d", &search_item);
    loc = search(*head, search_item);
    if (loc == NULL)
        printf("Enter item is not found.");
    else
    {
        while (ptr->next != loc)                
            ptr = ptr->next;                    // Address of second last node
        ptr->next = loc->next;
        item = loc->info;
        loc = NULL;
        free(loc);
        return item;
    }
}
// =========================================Deletion Entire Linked List Function=======================================
void Delete_Entire(node **head)
{
    node *loc;
    loc = *head;
    while ((*head) != NULL)
    {
        loc = (*head);
        (*head) = (*head)->next;
        free(loc);
    }
    printf("Entire list is deleted");
}

//                   ********************* END OF PROGRAM *********************