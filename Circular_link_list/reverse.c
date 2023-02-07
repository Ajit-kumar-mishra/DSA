#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void reverselist();
void displaylist();

int main()
{
    head = NULL;
    int n,choice;

    printf("enter the total number of nodes:\n");
    scanf("%d",&n);

    createlist(n);

    printf("data in the list are:\n");

    displaylist();

    printf("enter 1 to reverse the list:\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        reverselist();
    }

    printf("\nAfter reversing tha list :\n");

    displaylist();

    return 0;

}

void createlist(int n)
{
    struct node *newnode,*temp;
    int data,i;

    head = (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("unable to allocate memory:\n");
        exit(0);
    }

    printf("enter the data of node 1:");
    scanf("%d",&data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for(i=2;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode==NULL)
        {
            printf("unable to allocate memory:");
            return;
        }

        printf("enter the data of node %d:",i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;
}

void reverselist()
{
    struct node *curnode,*prevnode,*nextnode;

    prevnode = NULL;

    curnode = head;
    nextnode = head;

    while(nextnode->next!=NULL)
    {
        nextnode = nextnode->next;
        curnode->next = prevnode;
        prevnode = curnode;
        curnode = nextnode;
    }
          head = prevnode;
}

void displaylist()
{
    struct node *temp;

    if(head==NULL)
    {
        printf("list is alreay empty:\n");
        return ;
    }

    temp = head;

    while(temp->next!=head)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    printf("Data = %d\n",temp->data);
}
