#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void deletebykey( int key);
void displaylist();

int main()
{
    int n,key;

    printf("enter the total number of nodes:\n");
    scanf("%d",&n);

    createlist(n);

    printf("\n SINGLY LINK LIST CREATED SUCCESSFULLY\n");

    printf("data in the list are:\n");

    displaylist();

    printf("enter the element of the node to be deleted:\n");
    scanf("%d",&key);

    deletebykey(key);

    printf("after deliting the node list is:\n");

    displaylist();
    return 0;
}

void createlist(int n)
{
    struct node *newnode,*temp;
    int data ,i;

    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
    {
        printf("unable to allocate memory:\n");
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
        printf("unable to allocate memory:\n");
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

void deletebykey(int key)
{
    struct node *prev,*cur;

    int data,i;

    if(head==NULL)
    {
        printf("unable to allocate memory:\n");
        return ;
    }

    while (head != NULL && head->data == key)
    {
        
        prev = head;

      
        head = head->next;

       
        free(prev);

       
        return;
    }
     
    prev = NULL;
    cur  = head;

    while (cur != NULL)
    {
       
        if (cur->data == key)
        {
            
            if (prev != NULL) 
                prev->next = cur->next;

            free(cur);

            
            return;
        } 
        prev = cur;
        cur = cur->next;
    }
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