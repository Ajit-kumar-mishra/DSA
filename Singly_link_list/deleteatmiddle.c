#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void deleteatmiddle(int possition);
void displaylist();

int main() 
{
    int n,data;
    int choice;
    int possition;
    struct node *newnode,*temp;

    printf("enter the total number of nodes :\n");
    scanf("%d",&n);

    createlist(n);

    printf("SINGLY LINK LIST CREATED SUCESSFULLY:\n");

    printf("data in the list are:\n");
    displaylist();

    printf("enter the pssition to be deleted;\n");
    scanf("%d",&possition);

    printf("enter 1 to delete node:\n");
    scanf("%d",&choice);
    if(choice==1)
        deleteatmiddle(possition);
    printf("data in the list after deliting middle node :\n");
    displaylist();
    return 0;

}

void createlist(int n)
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

void deleteatmiddle(int possition)
{
    struct node *todelete,*temp;
    int i;

    if(head==NULL)
    {
        printf("list is empty:\n");
        return;
    }

    temp = head;
    todelete = head;

    for(i=2;i<=possition;i++)
    {
        temp = todelete;
        todelete = todelete->next;
        
            if(todelete == NULL)
                break;
    }
    if(todelete!=NULL)
    {
        if(todelete==head)
        head = head->next;
        temp->next = todelete->next;

        free(todelete);

    }
}
void displaylist()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}