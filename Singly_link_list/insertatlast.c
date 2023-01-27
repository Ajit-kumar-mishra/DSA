#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void insertatlast(int data);
void displaylist();

int main()
{
    int n;
    int data;
    printf("enter the total number of node: ");
    scanf("%d",&n);

    createlist(n);

    printf("\n SINGLY LINK LIST CREATED SUCCESFULLY\n");

    printf("\n data in the list are\n");

    displaylist();

    printf("insert the data of  last node  which you want to insert\n");
    scanf("%d",&data);

    insertatlast(data);
    printf("\n Data in the list:\n");
    displaylist();

    return 0;
}
  void createlist(int n)
{
struct node *newnode,*temp;
    int data ,i;

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
            printf("unable to create memory\n");
            return;
        }

        printf("enter the data of node %d:",i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
}
}
   void displaylist()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\n list is empty:\n");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("Data =%d\n",temp->data);
        temp = temp->next;

    }
}
void insertatlast(int data)
{
    struct node *newNode,*temp;
 
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = NULL; // Link address part

        temp = head;    
        
         while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;      // Make newNode as first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
