#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void displaylist();
void insertafternode(int data,int element);

int main()
{
    int n,data,element;

    printf("enter the total number of nodes:\n");
    scanf("%d",&n);

    createlist(n);

    printf("Data in the list are:\n");

    displaylist();

    printf("enter the data which you want to insert:\n");
    scanf("%d",&data);

    printf("enter the elememt after which you want to insert:\n");
    scanf("%d",&element);

    insertafternode(data,element);

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
        printf("unable to create memory:\n");
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
            printf("unable to create memory:\n");
            return;
        }

        printf("enter the data of node %d:",i);
        scanf("%d",&data);

        newnode->data =data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;

}

void displaylist()
{
    struct node *temp;

    if(head==NULL)
    {
        printf("list is alredy empty:\n");
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

void insertafternode(int data,int element)
{
    struct node *newnode,*temp,*curnode,*prevnode;

    int i;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("unable to create memory:\n");
        return ;
    }
    
    newnode->data = data;
    newnode->next = NULL;

    curnode = head;
    temp = head;

   while(temp->data!=element)
    {
        temp = temp->next;  
    }
    if(temp->data == element)
    {
        newnode->next = temp->next ;
        temp->next = newnode; 
    }
}
