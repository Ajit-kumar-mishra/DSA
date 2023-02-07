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

int main()
{
    int n;
    head=NULL;
    printf("enter the total number of nodes:\n");
    scanf("%d",&n);

    createlist(n);
    printf("circular link list are :\n");

    displaylist();

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

    printf("enter the data of node 1 :");
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

       
        printf("enter the data of node %d :",i);
        scanf("%d",&data);

         newnode->data = data;
        newnode->next = NULL;


        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;


}
void displaylist()
{
    struct node *temp,*newnode;

   if(head==NULL)
    {
       printf("list is empty:\n");
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
