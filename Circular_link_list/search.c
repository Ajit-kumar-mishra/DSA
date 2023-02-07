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
int search(int key);

int main()
{
    head = NULL;
    int n;
    int KeyToSearch,index;
    printf("enter the total number of nodes ");
    scanf("%d",&n);

    createlist(n);

    printf("\nData in the list are \n");

    traverselist();

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
    struct node *newnode, *temp;
    int data,i;

    head = (struct node *)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("unable to create memory : \n");
        exit(0);
    }
    printf("enter the data of node 1: ");
    scanf("%d",&data);

    head->data = data;
    head->next = NULL;

    temp = head;

    for(i=2;i<=n;i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if(newnode==NULL)
        {
            printf("unable to create memory\n");
            break;
        }
        printf("enter the data of node %d: ", i);
        scanf("%d",&data);

        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;
}
void traverselist()
{
    struct node *temp;

    if(head==NULL)
    {
        printf("list is empty \n");
        return ;
    }

    temp = head;
    while(temp->next!=head)
    {
        printf("Data =  %d\n",temp->data);
        temp = temp->next;
    }
    printf("Data =  %d\n",temp->data);

}

int search(int key)
{
    int index;
    struct node *curnode;
    index=0;
    curnode = head;

    while(curnode->next!=head && curnode->data != key)
    {
        index++;
        curnode = curnode->next;
    }
    return (curnode!=NULL) ? index : -1;

}