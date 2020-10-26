#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start=NULL;


void create_list(struct node **st,int n)
{
    struct node*temp;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(*st==NULL)
    {
        *st=newnode;
    }
    else
    {
        temp=*st;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
}

void display(struct node **st)
{
    struct node*t;
    t=*st;
    while(t!=NULL)
        {
            printf("%d-->",t->data);
            t=t->next;
        }
        printf("\n\n");
    
    
}

void find_middle(struct node **st)
{
	struct node*q=*st;
    struct node *p=*st;
	if(p)
	{
		if(p->next == NULL)
			{
				printf("\n Middle node is  %d", p->data);
			}
		else
		{
			while(p && p->next)
			{
				q = q->next;
				p = p->next->next;
			}

			printf("\n Middle node is  %d", q->data);			

		}
	}
}

void main()
{
    int ch,n;
    while(1)
    {
        printf("1.creating a list \n");
        printf("2.display the linked list \n");
        printf("3.middle of the linked list\n");
        printf("4.exits\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter newnode to the linked list\n");
            scanf("%d",&n);
            create_list(&start,n);
            break;
            case 2:display(&start);
            break;
            case 3:find_middle(&start);
            break;
            case 4:exit(1);
            default:printf("invalid choice");


        }
    }
}
