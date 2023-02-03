#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void deleteatfirst();
void displaylist();

int main()
{
    struct node *newnode,*temp;
    int n,data;
    int choice;

    printf("enter the total number of nodes \n");
    scanf("%d",&n);

    createlist(n);

    printf("\nSINGLY LINK LIST CREATED SUCCESFULLY:\n");
    
    printf("\nData in the list \n");
    displaylist();

    printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    if(choice == 1)
        deleteatfirst();

    printf("\n Data in the list are :\n");

    displaylist();

    return 0;

}

void createlist(int n)
{
    int data,i;
    struct node *temp,*newnode;
    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("unable to create memory :\n");
        exit(0);
    }

    printf("enter the data of the node 1:");
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

        printf("enter the data of the node %d:",i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;

}
 
 void deleteatfirst()
{
    struct node *todelete,*temp;

    if(head==NULL)
    {
        printf("list is empty:\n");
        return ;
    }

    todelete = head;
    temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = head->next;

    head = head->next;
     printf("\nData deleted = %d\n", todelete->data);
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
    while(temp->next!=head)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;

    }
    printf("Data = %d\n",temp->data);

}