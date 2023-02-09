#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int);
int pop(void);
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
    struct node *temp;
    temp= (struct node*)malloc(sizeof(struct node));
    printf("enter the node value:");
    scanf("%d",&temp->data);
    temp->next = top;
    top= temp;

}

int pop()
{
     if(top == NULL){
        printf("Stack is Underflow ");
    }else{
        printf("Element %d is deleted",top->data);
        top = top->next;
}
}

void atTop()
{
    struct node *temp;
     printf("element at the top is:%d",top->data);
    
}

void traverse()
{
     struct node * temp;
    if(top == NULL){
        printf("No element available in the stackn");
    }else{
        temp = top;
        while(temp != NULL){
            printf("%d-->",temp->data);
            temp = temp->next;
        }
}
}





