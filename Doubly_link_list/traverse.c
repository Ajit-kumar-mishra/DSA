#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head,*last;

void createlist(int n);
void traversefromfirst();
void traversefromlast();

int main()
{
    int n;
    int choice;
    printf("enter the total number of nodes :");
    scanf("%d",&n);

    createlist(n);

    printf("DOUBLY LINK LIST IS CREATED SUCCESFULLY\n");

    printf("\n press 1 to display from first:\n");
    printf("\n press 2 to display from last:\n");

    printf("\nenter your choice either 1 or 2\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("YOUR DATA WILL BE SHOW YOU FROM FIRST TO LAST:\n");
        traversefromfirst();
    }

    if(choice==2)
    {
        printf("YOUR DATA WILL BE SHOW YOU FROM LAST TO FIRST:\n");
        traversefromlast();
    }

    return 0;

}

void createlist(int n)
{
    struct node *temp,*newnode;
    int data,i;

    head = (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("unable to create memory:\n");
        exit(0);
    }

    printf("enter the data of node 1:");
    scanf("%d",&data);

    head->data = data;
    head->prev = NULL;
    head->next = NULL;


    last = head;

    for(i=2;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode==NULL)
        {
            printf("unable to create meory:\n");
            return ;
        }

        printf("enter the data of node %d:",i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        last->next = newnode;
        newnode->prev = last;
        last = last->next; 
    }
}

void traversefromfirst()
{
    struct node *temp;
    int data;

    if(head==NULL)
    {
        printf("list is already empty:\n");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
}
void traversefromlast()
{
    struct node *temp;
    int data;

    if(head==NULL)
    {
        printf("list is already empty:\n");
        return;
    }
    temp = last;
    while(temp!=NULL)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->prev;
    }
}
