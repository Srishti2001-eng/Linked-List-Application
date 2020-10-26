#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create();
void display();
int find_loop_length();

void main()
{
    int ch;
    while(1)
    {
        printf("1.create\n");
        printf("2.display\n");
        printf("3.finfd length of the loop in linked list\n");
        printf("4.exits\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:find_loop_length();
            break;
            case 4:exit(1);
            default:printf("invalid choice");


        }
    }
}



void create()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        struct node*p;
        p=start;
        while(temp->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    
}

void display()
{
   struct node *temp;
   temp=start;
   if(temp==NULL)
    {
        printf("List is Empty\n\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }
}

int find_loop_length()
{
    int counter=0;
    int loopExists=0;
    struct node *t1=start;
    struct node *t2=start;
    while(t1 && t2&& t2->next)
    {
        t1=t1->next;
        t2=t2->next->next;
       if(t1=t2)
       {
          loopExists=1;
          break;
        }
    }
    if(loopExists);
    {
        t2=t2->next;
        while(t1->next!=NULL)
        {
            t2=t2->next;
           counter++;
        }
        return counter;
           
    }
    return 0;
}

