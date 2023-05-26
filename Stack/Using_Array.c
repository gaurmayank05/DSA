//=======================This program is used to explain the operation of Stack i.e. PUSH & POP========================

/*      1. In this code we are declearing a MACRO 'MAX' = 100 which represent the size of the array.
        2. We initially assiging 'top=-1' because we are asuming that Stack is Empty (Stack Pointer pointing towards nothing).
        3. We are passing the address of top because if we pass the value then it will act as Automatic variable for a function
           and it will not retain the item therefore passing its address will help to reatin the value.
*/

//========================================================================================================================

#define MAX 100
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//=================================================MAIN FUNCTION========================================================
void main()
{
    void push(int[], int *, int);                               // Function Declearation                             // Function Declearation
    int pop(int[], int *);                                      // Function Declearation
    int Stack[MAX], top = -1, operation, item, del;
    while (1)
    {
        printf("Select an Operation: \n1. Insertation\n2. Deletion\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
        {
            if (top == (MAX - 1))
            {
                printf("\nOverflow");
            }
            else
            {
                printf("\nEnter item: ");
                scanf("%d", &item);
                push(Stack, &top, item);
            }
            break;
        }
        case 2:
        {
            if (top == -1)
            {
                printf("\nUnderflow\n");
            }
            else
            {
                del = pop(Stack, &top);
                printf("\n%d is deleted.\n", del);
            }
            break;
        }
        deafult:
            exit(0);
        }
    }
}

//=================================================PUSH FUNCTION========================================================
void push(int Stack[], int *top, int item)
{
    (*top)++;
    Stack[*top] = item;
}

//=================================================POP FUNCTION========================================================
int pop(int Stack[], int *top)
{
    int del;
    del = Stack[*top];
    (*top)--;
    return del;
}

//======================================================================================================================