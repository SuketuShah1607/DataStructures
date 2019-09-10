#include<stdio.h>
#include<conio.h>
#define SIZE 20

void enqueue(int);
void dequeue();
void traverse();

int queue[SIZE];
int front=0,rear=0,choice,ele,i;

int main()
{
    printf("QUEUE IMPLEMENTATION\n\n");
    while(1)
    {
       printf("1-ENQUEUE\n");
       printf("2-DEQUEUE\n");
       printf("3-TRAVERSE\n");
       printf("ENTER YOUR CHOICE: ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
              printf("Enter data: ");
              scanf("%d",&ele);
              enqueue(ele);
              break;
            
           case 2:
              dequeue();
              break;
            
           case 3:
              traverse();
              break; 
            
           default:
              printf("INVALID CHOICE\n\n");
              break;
       }
    }
}

void enqueue(int ele)
{
    if(rear == SIZE)
    {
        printf("Queue is full\n\n");
    }
    else
    {
        queue[rear]= ele;
        rear++;
    }
}
void dequeue()
{
    if(front == rear)
    {
        printf("List is empty \n\n");
    }
    else
    {
        printf("%d element deleted\n",queue[front]);
        for(i=0;i<rear-1;i++)
        {
            queue[i]= queue[i+1];
        }
        rear--;
    }
}
void traverse()
{
    if(rear == front)
    {
        printf("List is empty\n\n");
    }
    else
    {
        for(i=0;i<rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n\n");
    }
}
