#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE,**PPNODE;

void create(PPNODE phead)
{
	int i,n;
	PNODE newn=NULL,temp=NULL;
	printf("Enter how many nodes you want to insert\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		newn=(PNODE)malloc(sizeof(NODE));
		newn->next=NULL;
		printf("Enter the data\n");
		scanf("%d",&newn->data);
		
		if(*phead==NULL)
		{
			*phead=newn;
		}
		else
		{
			temp=*phead;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;

		}
	}
}

void print(PNODE phead)
{

	if(phead==NULL)
	{
		printf("\nLinked list is empty\n");
		return;
	}
	while(phead!=NULL)	
	{
		printf("%d\t",phead->data);
		phead=phead->next;

	}
	printf("\n");

}

void add(PPNODE phead1,PPNODE phead2)
{
	PNODE temp1=*phead1,temp2=*phead2;

	if(phead1==NULL ||phead2==NULL)
	{
		return;
	}

	while(temp1!=NULL)
	{
		temp2=*phead2;
		*phead2=(*phead2)->next;
		temp2->next=temp1->next;
		temp1->next=temp2;
		temp1=temp1->next->next;
		
		
	}
}


int main()
{
	PNODE head1=NULL;
	PNODE head2=NULL;

	create(&head1);
	create(&head2);
	print(head1);
//	printf("\n");
	print(head2);

	add(&head1,&head2);
	print(head1);
//	printf("\n");
        print(head2);

	

	return 0;
}
