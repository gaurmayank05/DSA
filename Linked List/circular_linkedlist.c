/*                                              Program of Circular Linked List
                                                    DATE - 26/MAY/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype                         // Structure of Circular Linked List
{
    int info;
    struct nodetype *next;                       // Self Refrential Structures
} circular;

// -------------------------------------------------------------Function Declaration-------------------------------------------
void Insertion_at_beg(circular **, circular **, int);
void Insertion_at_end(circular **, circular **, int);
void Insertion_after_item(circular **, circular **, int);
void Traversal(circular *);
int deletion_at_beg(circular **);
int deletion_at_end(circular **);
int deletion_item(circular **);
circular *search(circular *, int);
//--------------------------------------------------------------Main Function---------------------------------------------------
void main()
{
    circular *head = NULL, *ptr;
    int operation, item;
    while (1)
    {
        printf("\nEnter operation:\n1.Insertion at Beginning\n");
        printf("2.Insertion at End\n3.Insertion after element\n4.Traversal\n5.Deletion at Beginning\n6.Deletion at End\n");
        printf("7.Delete a specific element\n8.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            ptr = (circular *)malloc(sizeof(circular));
            if (ptr == NULL)
                printf("Overflow");
            else
            {
                printf("Enter item: ");
                scanf("%d", &item);
                Insertion_at_beg(&head, &ptr, item);
            }
            break;
        case 2:
            ptr = (circular *)malloc(sizeof(circular));
            if (ptr == NULL)
                printf("Overflow");
            else
            {
                printf("Enter item: ");
                scanf("%d", &item);
                Insertion_at_end(&head, &ptr, item);
            }
            break;
        case 3:
            ptr = (circular *)malloc(sizeof(circular));
            if(ptr == NULL)
                printf("OverFlow");
            else
            {
                printf("Enter item: ");
                scanf("%d",&item);
                Insertion_after_item(&head,&ptr,item);
            }
            break;
        case 4:
            Traversal(head);
            break;
        case 5:
            if (head == NULL)
                printf("UnderFlow");
            else
            {
                item = deletion_at_beg(&head);
                printf("%d is deleted.", item);
            }
            break;
        case 6:
            if (head == NULL)
                printf("UnderFlow");
            else
            {
                item = deletion_at_end(&head);
                printf("%d is deleted.", item);
            }
        case 7:
            if(head == NULL)
                printf("UnderFlow");
            else
            {
                item = deletion_item(&head);
                printf("%d is deleted.",item);
            }
            break;
        default:
            exit(0);
        }
    }
}

//--------------------------------------------------------------Insertation at Beginning Function---------------------------------------------------
void Insertion_at_beg(circular **head, circular **ptr, int item)
{
    circular *loc;
    loc = (*head);
    (*ptr)->info = item;
    if ((*head) == NULL)
    {
        (*head) = (*ptr);                   // Since, linked list is Empty therefore it will create the first node
        (*ptr)->next = (*head);
    }
    else
    {
        while (loc->next != (*head))
        {
            loc = loc->next;                // this loop will get the access of the address which is contained in last node
        }
        (*ptr)->next = (*head);
        (*head) = (*ptr);
        loc->next = *ptr;                   // providing address of the head so that it can act as a circular list.
    }
}

//----------------------------------------------------Insertation at End Function----------------------------------------------------
void Insertion_at_end(circular **head, circular **ptr, int item)
{
    circular *loc;
    loc = (*head);
    (*ptr)->info = item;
    if ((*head) == NULL)
    {
        (*head) = (*ptr); // Creation of first node
        (*ptr)->next = (*head);
    }
    else
    {
        while (loc->next != (*head))
            loc = loc->next;                           // Traversal till the end of node
        loc->next = (*ptr);
        (*ptr)->next = (*head);                     // providing address of the head node
    }
}

//------------------------------------------------------Insertion After Any Item Function------------------------------------------
void Insertion_after_item(circular **head, circular **ptr, int item)
{
    circular *loc;
    int search_item;
    printf("Insert after which item you want to insert new item: ");
    scanf("%d", &search_item);
    loc = search(*head, search_item);
    if (loc == NULL)
        printf("Searched item is not found");
    else
    {
        (*ptr)->info = item;
        if ((*head)->next == (*head))
        {
            (*head)->next = (*ptr);
            (*ptr)->next = (*head);
        }
        else
        {
            (*ptr)->next = loc->next;
            loc->next=(*ptr);
        }
    }
}

//--------------------------------------------------------------Traversal Function---------------------------------------------------
void Traversal(circular *head)
{
    circular *loc;
    loc = head;
    do
    {
        printf("%d ", loc->info);
        loc = loc->next;
    } while (loc != head);
}

//------------------------------------------------------Deletion from Beginning Function-----------------------------------------------
int deletion_at_beg(circular **head)
{
    circular *loc, *temp;
    int item;
    if ((*head)->next == (*head))                          // If it contained only one node.
    {
        item = (*head)->info;
        (*head) = NULL;
        free(*head);
    }
    else                                                   // if it will contain more than one node
    {
        temp = (*head);
        loc = (*head);
        item = temp->info;
        while (loc->next != (*head))
        {
            loc = loc->next;
        }
        (*head) = temp->next;
        loc->next = (*head);
        free(temp);
    }
    return item;
}

//------------------------------------------------------Deletion from End Function-----------------------------------------------
int deletion_at_end(circular **head)
{
    circular *loc, *temp;
    int item;
    if ((*head)->next == (*head))                       // if it will contain only one node
    {
        item = (*head)->info;
        (*head) = NULL;
        free(*head);
    }
    else                                                // if it will contain more than one node.
    {
        loc = (*head);
        while ((loc->next)->next != (*head))
            loc = loc->next;
        temp = loc->next;
        (loc->next) = (*head);
        item = temp->info;
        temp->next = NULL;
        free(temp);
    }
    return item;
}

//------------------------------------------------------Deletion After Any Item Function-----------------------------------------------
int deletion_item(circular **head)
{
    circular *loc,*temp;
    int item,search_item;
    printf("Enter item which is to be deleted:");
    scanf("%d",&search_item);
    loc = search((*head),search_item);
    if(loc==NULL)
        printf("Item not found");
    else
    {
        if((*head)->next==(*head))                      // If list contain only one node i.e. only head
        {
            item = (*head)->info;
            (*head)=NULL;
            free(*head);
        }
        else
        {                                                   // if it will contain more than one node
            temp = (*head);
            while(temp->next != loc){
                temp = temp->next;
            }
            temp->next=loc->next;
            item = loc->info;
            free(loc);
        }
        return item;
    }
}

//-----------------------------------------------------------Search Function---------------------------------------------------------
circular *search(circular *head, int item)        
{
    circular *loc;
    loc = head;
    do
    {
        if (loc->info == item)
            return loc;                             // It will return the location of required Item
        loc = loc->next;
    } while (loc != head);
    return NULL;                                   // It will return NULL if Item will not Found
}

//                                 ************************END of PROGRAM************************