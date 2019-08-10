#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int pid;
	struct node *next;
}NODE,*PNODE,**PPNODE;


void enQueue(PPNODE pHead)
{
	int i=0,n;
	PNODE newn=NULL;
	
	printf("Enter how many process are there\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		newn=(PNODE)malloc(sizeof(NODE));
		newn->next=NULL;
		printf("Enter the pid of process %d:",i);
		scanf("%d",&newn->pid);
		
		newn->next=*pHead;
		*pHead=newn;
		
	}


}

void deQueue(PPNODE pHead)
{
	PNODE temp=*pHead;
	int n=0;
	if(*pHead==NULL)
	{
		printf("\nThe queue is empty\n");
		return;
	}

	if(temp->next==NULL)
	{
		printf("\nThe process %d is delete from queue",temp->pid);
		free(temp);
		*pHead=NULL;
		return;
	}

	while((temp->next->next)!=NULL)
	{
		temp=temp->next;
	}
	n=(temp->next->pid);
	free(temp->next);
	temp->next=NULL;
	printf("\nThe process %d is delete from dequeue",n);
}

void peek(PNODE pHead)
{
	int i=0;
	if(pHead==NULL)
	{
		printf("\nThe queue is empty");
		return;
	}
	
	while(pHead->next!=NULL)
	{
		//printf("The current element is:%d",pHead->pid);
		pHead=pHead->next;
		
	}

	printf("\nThe current element is %d:",pHead->pid);
}
int main()
{
	int i=0,n=0;
	int ch;
	PNODE Head=NULL;
	do
	{
	printf("\nEnter \n1:Add \n2:peek \n3:delete\n4:exit\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
	case 1:
	enQueue(&Head);
	break;

	case 2:	
	peek(Head);
	break;

	case 3:
	deQueue(&Head);
	break;
	
	}
	}while(ch!=4);		
	return 0;
}
