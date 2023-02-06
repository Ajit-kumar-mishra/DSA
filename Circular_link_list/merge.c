#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    int data;
    struct node *next;
}*head1,*head2;

void createfirstlist(int n1);
void createsecondlist(int n2);
void mergelist();
void displayfirstlist();
void displaysecondlist();
void displaymergelist();

int main()
{
    int n1,n2;
    printf("enter the total number of nodes of first list:\n");
    scanf("%d",&n1);

    createfirstlist(n1);
    printf("data in the list are:\n");
    displayfirstlist();

    printf("enter the total number of nodes of second list:\n");
    scanf("%d",&n2);

    createsecondlist(n2);
    printf("data in the list are:\n");
    displaysecondlist();

    mergelist();

    printf("after merging two list new list are:\n");

    displaymergelist();

    return 0;   
}

void createfirstlist(int n1)
{
    struct node *newnode,*temp;
    int data,i;

    head1 = (struct node*)malloc(sizeof(struct node));

    if(head1==NULL)
    {
        printf("unable to create memory:\n");
        exit(0);
    }

    printf("enter the data of node 1:");
    scanf("%d",&data);

    head1->data = data;
    head1->next = NULL;

    temp = head1;

    for(i=2;i<=n1;i++)
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
    temp->next = head1;
}
void createsecondlist(int n2)
{
    struct node *newnode,*temp;
    int data,i;

    head2 = (struct node*)malloc(sizeof(struct node));

    if(head2==NULL)
    {
        printf("unable to create memory:\n");
        exit(0);
    }

    printf("enter the data of node 1:");
    scanf("%d",&data);

    head2->data = data;
    head2->next = NULL;

    temp = head2;

    for(i=2;i<=n2;i++)
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
    temp->next = head2;
}

void displayfirstlist()
{
    struct node *temp;

    if(head1==NULL)
    {
        printf("list is already empty:\n");
        return ;
    }

    temp = head1;

    while(temp->next!=head1)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    printf("Data = %d\n",temp->data);
}

void displaysecondlist()
{
    struct node *temp;

    if(head2==NULL)
    {
        printf("list is already empty:\n");
        return ;
    }

    temp = head2;

    while(temp->next!=head2)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    printf("Data = %d\n",temp->data);
}

void displaymergelist()
{
    struct node *temp;

    if(head1==NULL)
    {
        printf("list is already empty:\n");
        return ;
    }

    temp = head1;

    while(temp->next!=head1)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    printf("Data = %d\n",temp->data);
}

void mergelist()
{
    struct node *temp,*temp1;

    temp = head1;
    temp1= head2;
    while(temp->next!=head1)
    {
        temp = temp->next;
    }
    temp->next = head2;
    while(temp1->next!=head2)
    {
        temp1 = temp1->next;
    }
    temp1->next = head1;
}


