//---------------------------------------------------STACK implemented using Linked List-------------------------------------------
//------------------------------PUSH function is implemented using Insertation at Beginning into linked list-----------------------------
//------------------------------POP function is implemented using Deletion at Beginning into linked list-----------------------------

#include <stdio.h>
#include <stdlib.h>


// -------------------------------------------------------Structure of STACK-------------------------------------------------------
typedef struct nodetype
{
    int info;                                                
    struct nodetype *next;
} Stack;

// -------------------------------------------------------MAIN Function-------------------------------------------------------
void main()
{
    void push(Stack **);
    int pop(Stack **);
    int operation, item;
    Stack *top = NULL;
    while (1)
    {
        printf("\nEnter Operation: \n");
        printf("1.Push\n2.Pop\n3.Exit\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            push(&top);
            break;
        case 2:
            if (top == NULL)
                printf("UnderFlow");
            else
                item=pop(&top);
                printf("%d is deleted",item);
            break;
        case 3:
            exit(0);
            break;
        }
    }
}


// -------------------------------------------------------PUSH Function-------------------------------------------------------
void push(Stack **top)
{
    Stack *ptr;
    int item;
    ptr = (Stack *)malloc(sizeof(Stack));
    if (ptr == NULL)
        printf("OverFlow");
    else
    {
        printf("Enter item: ");
        scanf("%d", &item);
        ptr->info = item;
        if ((*top) == NULL)
        {
            ptr->next = NULL;
            (*top) = ptr;
        }
        else
        {
            ptr->next = (*top);
            (*top) = ptr;
        }
    }
}

// -------------------------------------------------------POP Function-------------------------------------------------------
int pop(Stack **top)
{
    Stack *loc;
    int item;
    loc = (*top);
    item = loc->info;
    (*top) = (*top)->next;
    free(loc);
    return item;
}

// -------------------------------------------------------END of Program-------------------------------------------------------