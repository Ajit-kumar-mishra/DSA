#include<stdio.h>
#include<stdlib.h>

#define size 5

int stack[size];
int top = -1;

void push(int);
int pop(void);
int isfull(void);
int isempty(void);
void traverse(void);
void atTop(void);

int main()
{
    int choice,data;
    while(1)
    {
        printf("\nstack operation:\n");
        printf("press 1 for PUSH operation\n");
        printf("enter 2 for POP operation\n");
        printf("press 3 for TOP operation\n");
        printf("press 4 for TRAVERSE operatipon\n");
        printf("press 5 for QUIT operation\n");

        printf("\nenter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            push(data);
            break;

            case 2:
            pop();
            break;

            case 3:
            atTop();
            break;

            case 4:
            traverse();
            break;

            case 5:
            break;
            default:printf("please enter correct choice:");

        }
    }
}

void push(int data)
{
    if(isfull())
    {
        printf("stack is full it cannot be overflowed:");
    }
    else{
        printf("enter the integer value:");
        scanf("%d",&data);
        top++;
        stack[top] = data;
        printf("%d has been pushed on to the stack:",data);
    }
}

int isfull()
{
    if(top==size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("underflow");
    }
    else{ 
        printf("Last popped element is :%d",stack[top]);
        top--;
    }
}

void atTop()
{
    if(isfull())
    {
        printf("stack is empty:");
    }
    else{
        printf("element at the top is:%d",stack[top]);
    }
}

void traverse()
{
    if(isempty())
    {
        printf("stack is empty:");
    }
    else{
        printf("stack element are");
        for(int i=0;i<=top;i++)
        {
            printf("%d",stack[i]);
        }
    }
}





