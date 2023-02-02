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
void traversefromlast();
int search(int key);

int main()
{
    int n;
    int choice;
    int KeyToSearch,index;
    printf("enter the total number of nodes :");
    scanf("%d",&n);

    createlist(n);

    printf("DOUBLY LINK LIST IS CREATED SUCCESFULLY\n");

    printf("\n press 1 to display from first:\n");
    printf("\n press 2 to display from last:\n");

    printf("\nenter your choice either 1 or 2\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("YOUR DATA WILL BE SHOW YOU FROM FIRST TO LAST:\n");
        traversefromfirst();
    }

    if(choice==2)
    {
        printf("YOUR DATA WILL BE SHOW YOU FROM LAST TO FIRST:\n");
        traversefromlast();
    }

    printf("enter the element to search:\n");
    scanf("%d",&KeyToSearch);

    index = search(KeyToSearch);
    if(index>=0)
        printf("%d found in the list at possition %d",KeyToSearch,index+1);
    else
    printf("%d not found in the list ",KeyToSearch);


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
        newnode->prev = NULL;
        newnode->next = NULL;

        last->next = newnode;
        newnode->prev = last;
        last = last->next; 
    }
}

void traversefromfirst()
{
    struct node *temp;
    int data,count=0;

    if(head==NULL)
    {
        printf("list is already empty:\n");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        count++;
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    printf("\n TOTAL NUMBER OF NODES IN THE LIST ARE %d:\n",count);
}
void traversefromlast()
{
    struct node *temp;
    int data;
    int count=0;

    if(head==NULL)
    {
        printf("list is already empty:\n");
        return;
    }
    temp = last;
    while(temp!=NULL)
    {
        count++;
        printf("Data = %d\n",temp->data);
        temp = temp->prev;
    }
    printf("\n TOTAL NUMBER OF NODES IN THE LIST ARE %d:\n",count);
}

int search(int key)
{
    int index;
    int choice;
    struct node *curnode;
    index=0;
    printf("\n enter the choice either 1 or 2\n");
    printf("\nPRESS 1 TO DISPLAY NODE POSSITION FROM START\n");
    printf("\nPRESS 2 TO DISPLAY NODE POSSITION FROM LAST:\n");
    scanf("%d",&choice);
    if(choice==1){
        curnode = head;
    while(curnode!=NULL && curnode->data != key)
    {
        index++;
        curnode = curnode->next;
    }
    return (curnode!=NULL) ? index : -1;
    }
    if(choice==2)
    {
        curnode = last;
        while(curnode!=NULL && curnode->data!= key)
    {
        index++;
        curnode = curnode->prev;
    }
    return (curnode!=NULL) ? index : -1;
    }

}
