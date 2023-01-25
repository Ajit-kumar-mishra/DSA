#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void deleteall();
void displaylist();

int main()
{
    int n;
    int choice;
    printf("enter the all number of nodes;\n");
    scanf("%d",&n);

    createlist(n);

    printf("SINGLY LINK LIST CREATED SUCSESSFULLY:\n");
    printf("Data in the list are:\n");

    displaylist();

    printf("enter 1 to delete all nodes:\n");
    scanf("%d",&choice);

    if(choice == 1)
    deleteall();

    //printf("\n Data in the list are:\n");

    //displaylist();

    if(displaylist ==NULL)
    printf("NULL");
}

void createlist(int n)
{
    struct node *newnode,*temp;
    int data,i;

    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("unable to create meomry:\n");
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

        if(newnode == NULL)
        {
            printf("unable to create memory:\n");
            return ;
        }

        printf("enter the data of node %d:",i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }

}

void deleteall()
{
    struct node *todelete;

    if(head == NULL)
    {
        printf("list is already empty:\n");
        return ;
    }
    while(head!=NULL)
    {
        todelete = head;
        head = head->next;
        free(todelete);
    }

     printf("SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
}

void displaylist()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("ist is already empty:\n");
        return;
    }

    temp = head;

    while(temp!=NULL)
    {
        printf("Data =%d\n",temp->data);
        temp = temp->next;
    }
}