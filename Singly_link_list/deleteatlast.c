#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int num);
void deleteatlast();
void displaylist();

int main()
{
    struct node *newnode,*temp;
    int num,choice;
    printf("enter the total number of nodes:\n");
    scanf("%d",&num);
    
    createlist(num);

    printf("SINGLY LINK LIST CREATED SUCCESSFULLY:\n");

    printf("Data in the list are :\n");
    displaylist();

     printf("\nPress 1 to delete last node: ");
    scanf("%d", &choice);

    if(choice == 1)
        deleteatlast();

    printf("\n Data in the list are :\n");

    displaylist();
    return 0;

}

void createlist(int num)
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

    for(i=2;i<=num;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode==NULL)
        {
            printf("unable to create memory:\n");
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
void deleteatlast()
{
    struct node *todelete,*secondlastnode;

    if(head==NULL)
    {
        printf("list is lready empty:\n");
        return ;
    }

    todelete = head;
    secondlastnode = head;
    while(todelete->next!=NULL)
    {
        secondlastnode = todelete;
        todelete = todelete->next;
    }
     if(todelete == head)
        {
            head = NULL;
        }
    secondlastnode->next = NULL;
    free(todelete);

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
