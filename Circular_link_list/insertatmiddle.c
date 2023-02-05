#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void insertatmiddle(int data,int possition);
void displaylist();

int main()
{
    int n;
    int data;
    int possition;
    printf("enter the total number of node: ");
    scanf("%d",&n);

    createlist(n);

    printf("\n SINGLY LINK LIST CREATED SUCCESFULLY\n");

    printf("\n data in the list are\n");

    displaylist();

    printf("insert the data of  middle  node  which you want to insert\n");
    scanf("%d",&data);

    printf("enter the possition at you want to insert new node:\n");
    scanf("%d",&possition);

    insertatmiddle(data,possition);
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
temp->next = head;
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
    while(temp->next!=head)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;

    }
    printf("Data = %d\n",temp->data);
}
void insertatmiddle(int data, int possition)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = NULL;

        temp = head;

        /* 
         * Traverse to the n-1 position 
         */
        for(i=2; i<=possition-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next; 

            /* Link address part of n-1 node */
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}


