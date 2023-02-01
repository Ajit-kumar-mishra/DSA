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
void insertbeforenode(int data,int element);
int main()
{
    int n;
    int data;
    int element;
    printf("enter the total number of nodes :");
    scanf("%d",&n);

    createlist(n);
     traversefromfirst();

     printf("enter the data which you want to insert at first :\n");
     scanf("%d",&data);

     printf("enter the element before which you want to insert:\n");
     scanf("%d",&element);

    insertbeforenode(data,element);

    printf("DOUBLY LINK LIST IS CREATED SUCCESFULLY\n");

        traversefromfirst();

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
        newnode->prev = last;
        newnode->next = NULL;

        last->next = newnode;
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

void insertbeforenode(int data,int element)
{
    struct node *newnode,*temp,*prevnode,*curnode;
    int i;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("unable to create memory:\n");
        return ;
    }
    temp = head;
    prevnode = head;
    curnode = head;
    while(temp->data!=element)
    {
        prevnode = curnode;
        curnode = curnode->next;
        temp = temp->next;
    }
    if(temp->data==element)
    {
        newnode->data = data;
         prevnode->next = newnode;
        curnode->prev = newnode;
        newnode->prev = prevnode;
        newnode->next = curnode;
    }

}
