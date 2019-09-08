#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 50
void push(char Alphabet);
char pop();
void traverse();
int isFull();
int isEmpty();

char str[SIZE]="MY NAME IS SUKETU SHAH";
char stack[SIZE];
int StackPointer= -1, i, StrLength;

struct node
{
    char data;
    struct node *link;
}*head;

int main()
{  
    StrLength=0;
    while(str[StrLength]!='\0')
    {
        StrLength++;
    }
    
    for(i=0;i<StrLength;i++)
    {
        push(str[i]);
    }
    
    for(i=0;i<StrLength;i++)
    {
        str[i] =pop();
    } 
    
    traverse();
}

void push(char Alphabet)
{
    if(isFull())
    {
        printf("Stack is filled\n");
    }
    else
    {
        struct node *temp;
        temp= (struct node *)malloc(sizeof(struct node));
        temp->data= Alphabet;
        temp->link= head;
        head= temp;
        StackPointer++;
    }
}

char pop()
{
    if(isEmpty())
    {
        printf("Stack is empty");
    }
    else
    {
        struct node* temp;
        temp= head;
        head= temp->link;
        temp->link= NULL;
        StackPointer--;
        return temp->data;
    }
}

void traverse()
{
    struct node *temp;
    temp= head;
    for(i=0;i<StrLength;i++)
    {
        printf("%c",str[i]);
    }
}

int isFull()
{
    if(StackPointer == SIZE -1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(StackPointer == -1)
         return 1;
    else 
         return 0;
}

