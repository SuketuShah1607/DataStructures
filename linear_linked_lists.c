#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display();
void insert();
void Delete();
int length();
void InsertAtBeginning();
void InsertAtEnd();
void InsertAtPos(int);
void DeleteAtBeginning();
void DeleteAtEnd();
void DeleteAtPos(int);
void nodeswap(int);

int choice,insertchoice,deletechoice,len;
int pos,count,i,menuflag=1,j,k,l,m,loc;
char menuchoice;
struct node
{
    int data;
    struct node *link;
}*head;

int main()
{
    printf("Linked lists\n");
    while(1)
    {
        if(menuflag==1)
        {
        printf("1-Insert\n");
        printf("2-Delete\n");
        printf("3-Display\n");
        printf("4-Length\n");
        printf("5-Node swap\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        }
        
        switch(choice)
        {
            case 1: 
               printf("1-Insert at beginning\n");
               printf("2-Insert at position\n");
               printf("3-Insert at end\n");
               printf("Enter your choice: ");
               scanf("%d",&insertchoice);
               insert();
               printf("Press y to continue or anything else to exit: ");
               scanf("%s",&menuchoice);
               break;
            
            case 2:
               printf("1-Delete at beginning\n");
               printf("2-Delete at position\n");
               printf("3-Delete at end\n");
               printf("Enter your choice: ");
               scanf("%d",&deletechoice);
               Delete();
               printf("Press y to continue or anything else to exit: ");
               scanf("%s",&menuchoice);
               break;
            
            case 3: 
               display();
               break;
            
            case 4:
               len= length();
               printf("There are %d elements in list \n",len);
               break;
            
            case 5:
               printf("Enter location of node with which succeding node will be swapped: \n");
               scanf("%d",&loc);
               nodeswap(loc);
               break;
            
            default:
               printf("Invalid choice\n");
               break;
        }
        if(menuchoice == 'y' || menuchoice == 'Y')
            menuflag=0;
        else
            menuflag=1;
    }
}

void display()
{
    struct node *p;
    if(head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        p=head;
        i=0;
        while(i<length()-1)
        {
            printf("%d->",p->data);
            p=p->link;
            i++;
        }
        printf("%d\n",p->data);
    }
}

int length()
{
    struct node *p;
    if(head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        p=head;
        count=1;
        while(p->link != NULL)
        {
            p=p->link;
            count++;
        }
        
    }
    return count;
}

void insert()
{
    switch(insertchoice)
    {
        case 1: 
           InsertAtBeginning();
           break;
        
        case 2: 
           printf("Enter position of node after which new node to be added :");
           scanf("%d",&pos);
           InsertAtPos(pos);
           break;
        
        case 3:
           InsertAtEnd();
           break;
        
        default:
           printf("Invalid choice\n");
    }
}

void Delete()
{
    switch(deletechoice)
    {
        case 1: 
           DeleteAtBeginning();
           break;
        
        case 2: 
           printf("Enter position of node to be deleted :");
           scanf("%d",&pos);
           DeleteAtPos(pos);
           break;
        
        case 3:
           DeleteAtEnd();
           break;
        
        default: 
           printf("Invalid choice\n");
           break;
    }
}

void InsertAtBeginning()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    if(head == NULL)
    {
        temp->link= NULL;
        head= temp;
    }
    else
    {
        temp->link = head;
        head= temp;
    }
}
void InsertAtEnd()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    if(head == NULL)
    {
        temp->link= NULL;
        head= temp;
    }
    else
    {
        struct node *p;
        p=head;
        temp->link = NULL;
        while(p->link != NULL)
        {
            p= p->link;
        }
        p->link = temp;
    }
}
void InsertAtPos(int pos)
{
    if(pos>length())
    {
        printf("Invalid position\n");
    }
    else
    {
        
        struct node *p,*q,*temp;
        temp= (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&temp->data);
        p= head;
        for(j=1;j<pos;j++)
        {
            p= p->link;
        }
        temp->link= p->link;
        p->link= temp;
    }
}
void DeleteAtBeginning()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *p;
        p=head;
        head=p->link;
        p->link=NULL;
    }
}
void DeleteAtEnd()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *p;
        k=1;
        p=head;
        while(k<(length()-1))
        {
            p=p->link;
            k++;
        }
        p->link=NULL;
    }
}
void DeleteAtPos(int pos)
{
    if(pos>length())
    {
        printf("Invalid position\n");
    }
    else
    {
        
        struct node *p,*q;
        p= head;
        for(l=1;l<pos-1;l++)
        {
            p= p->link;
        }
        q=p->link;
        p->link= q->link;
        q->link= NULL;
    }
}

void nodeswap(int loc)
{
    struct node *p,*q,*r;
    p= head;
    m=1;
    if(loc>1 && loc < length())
    {
        while(m<loc-1)
        {
            p=p->link;
            m++;
        }
        q=p->link;
        r=q->link;
        q->link= r->link;
        r->link=p->link;
        p->link=r;
    }
    else if(loc ==1)
    {
        q=p->link;
        r=q->link;
        p->link=q->link;
        q->link=p;
        head=q;
        
    }
    else if(loc == length())
    {
        printf("!!!Last node selected!!!\n");
    }
    else if(loc > length())
    {
        printf("Node not available!!!\n");
    }
}
