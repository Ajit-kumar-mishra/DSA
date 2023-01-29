#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
int  count(struct node *list);
int swap(struct node *list,int pos1,int pos2);
void displaylist();

int main()
{
    int n,pos1,pos2;

    printf("enter total number of nodes:\n");
    scanf("%d",&n);

    createlist(n);

    printf("Data in the list before swapping:\n");
    displaylist();

    printf("enter the first node possition which you want to swap:\n");
    scanf("%d",&pos1);

    printf("enter the second node possition which you want to swap:\n");
    scanf("%d",&pos2);

    swap(head, pos1, pos2);

    printf("after swapping the nodes new list is:\n");

    displaylist();
   

    return 0;
}

void createlist(int n)
{
    struct node *newnode,*temp;
    int data,i;

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
int count(struct node *list)
{
    int nodes = 0;
    while(list!=NULL)
    {
        nodes++;
        list = list->next;
    }
    return nodes;

}

void displaylist()
{
    struct node *temp;
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
int swap(struct node *list,int pos1,int pos2)
{
    struct node *node1,*node2,*prev1,*prev2,*temp;
    int i;
    const int maxpos = (pos1>pos2)?pos1:pos2;
    const int totalnodes = count(list);

    if(( pos1<=0 || pos1>totalnodes )|| (pos2<=0 || pos2>totalnodes))
    {
        return -1;
    }

    if(pos1 == pos2)
    {
        return 1;
    }

    i = 1;
    temp = list;
    prev1 = NULL;
    prev2 = NULL;

    while(temp!=NULL && i<=maxpos)
    {
        if(i==pos1-1)
        prev1 = temp;
        if(i==pos1)
        node1 = temp;


        if(i==pos2-1)
        prev2 = temp;
        if(i==pos2)
        node2 = temp;

        temp = temp->next;
        i++;
    }

    if(node1!= NULL && node2!= NULL)
    {
        if(prev1!=NULL)
        prev1->next = node2;

        if(prev2!=NULL)
        prev2->next = node1;

        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

         // first element.
        if (prev1 == NULL)
            head = node2;
        else if (prev2 == NULL)
            head = node1;
    }

    return 1;
}
    


