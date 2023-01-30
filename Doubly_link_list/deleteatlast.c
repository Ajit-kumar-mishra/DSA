#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head,*last;

void createlist(int n);
void traversefromfirst();
void deleteatlast(int data);
int main()
{
    int n;
    int data;
  int choice;
    printf("enter the total number of nodes :");
    scanf("%d",&n);

    createlist(n);
     traversefromfirst();

     printf("press 1 to delete first node:\n");
     scanf("%d",&choice);
if(choice==1){
    deleteatlast(data);
}

        traversefromfirst();

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

    printf("enter the data of node 1:");
    scanf("%d",&data);

    head->data = data;
    head->prev = NULL;
    head->next = NULL;


    last = head;

    for(i=2;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode==NULL)
        {
            printf("unable to create meory:\n");
            return ;
        }

        printf("enter the data of node %d:",i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->prev = last;
        newnode->next = NULL;

        last->next = newnode;
        last = last->next; 
    }
}

void traversefromfirst()
{
    struct node *temp;
    int data;

    if(head==NULL)
    {
        printf("list is already empty:\n");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
}

void deleteatlast(int data)
{
    struct node *temp,*todelete,*secondlastnode;

    if(head==NULL)
    {
        printf("list is already empty:\n");
        return;
    }
    todelete = head;
    secondlastnode = head;
    while(todelete->next!=NULL)
    {
        secondlastnode = todelete;
        todelete=todelete->next;
    }
    secondlastnode->next = NULL;
        free(todelete);
         printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
}
