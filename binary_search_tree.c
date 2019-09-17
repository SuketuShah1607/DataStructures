#include <stdio.h>
#include <stdlib.h>

void insert();
int choice,buff_data;
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*head;

void traverse(struct node* buff);

int main()
{
    printf("Binary Search Tree Implementation\n\n");
    while(1)
    {
        printf("1-Insert node\n");
        printf("2-Delete node\n");
        printf("3-Traverse all nodes and print\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                break;

            case 3:
                traverse(head);
                printf("\n");
                break;

            default:
                printf("Invalid Choice\n\n");
                break;
        }
    }
    return 0;
}

void insert()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(!head)
    {
        printf("Enter head data: ");
        scanf("%d",&(temp->data));
        head=temp;
    }
    else
    {
        struct node *parent,*child;
        parent=head;
        child=head;
        printf("Enter data: ");
        scanf("%d",&(buff_data));
        temp->data= buff_data;
        while(child != NULL)
        {
            if(buff_data < child->data)
            {
                parent=child;
                child=parent->left;
            }
            else
            {
                parent=child;
                child=parent->right;
            }
        }
        if(buff_data < parent->data)
            parent->left= temp;
        else
            parent->right= temp;
    }
}

void traverse(struct node* buff)
{
    if(buff->left != NULL)
        traverse(buff->left);

    printf("%d-",buff->data);

    if(buff->right != NULL)
        traverse(buff->right);
}





