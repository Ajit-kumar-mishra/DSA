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
    int count = 0;
    printf("enter the total number of node in the list\n");
    scanf("%d",&n);

    createlist(n);
    
    printf("\n SINGLY LINK LIST CREATED SUCCESSFULLY \n");
    
    printf("\n Data in the list are\n");

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
        printf("unable to create memory \n");
        exit(0);
    }
    printf("enetr the data of the node 1:");
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
            break;
        }

        printf("enter the data of the node %d:",i);
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
    int count=0;
    struct node *temp;

    if(head==NULL)
    {
        printf("list is empty\n");
        return ;
    }

    temp = head;

    while(temp->next!=head)
    {
        count++;
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    printf("Data = %d\n",temp->data);

    printf("\nlenth of the list is :\t%d",count+1);

}
