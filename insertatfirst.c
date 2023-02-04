#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void insertatfirst(int data);
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

    printf("insert the data at first node  which you want to insert\n");
    scanf("%d",&data);

    insertatfirst(data);
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
void insertatfirst(int data)
{
    struct node *newNode,*current;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part

       // head = newNode;          
    current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

        /*Makes new node as head node*/
        head = newNode;
    }
}
