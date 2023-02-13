#include<stdio.h>
#include<string.h>
char stack[50];
int top = -1;
void push(char);
char pop();
int main()
{
    char str[50],t;
    int flag = 1;
    int i;
    printf("enter the string:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        push(str[i]);
        else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
            if(top==-1)
            flag=0;
            else{
            t=pop();
            if(str[i]==')' && (t=='{' || t=='['))
            flag=0;
            if(str[i]=='}' && (t=='(' || t=='['))
            flag=0;
            if(str[i]==']' && (t=='{' || t=='('))
            flag=0;
        }

    }
}    
if(top>=0)
flag=0;
if(flag==1)
printf("BALANCED PARANTHESIS");
else
printf("UNBALANCED PARANTHESIS");
    return 0;
}
void push(char a)
{
    stack[++top] = a;
}
char pop()
{
    return stack[top--];
}