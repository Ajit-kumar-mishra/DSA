#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void traverselist();

int main()
{
    int n;
    printf("enter the total number of nodes");
    scanf("%d",&n);

    createlist(n);

    printf("\ndata in the list:\n");

    traverselist();

    return 0;
}

void createlist(int n)
{
    struct node *newnode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("unable to create memory\n");
        exit(0);
    }

    printf("\nenter the data of node 1 ");
    scanf("%d",&data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for(i=2;i<=n;i++)
    {
        newnode  = (struct node *)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("unable to create memory\n");
            break;
        }
        printf("enter the data of node %d ", i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;

    }
}
void traverselist()
{
    struct node *temp;

    if(head==NULL)
    {
        printf("list is empty:\n");
        return;
    }
    temp = head;

    while(temp!=NULL)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
}



