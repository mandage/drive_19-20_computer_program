#include<stdio.h>
#include<malloc.h>

void displayPrime(int arr[],int iSize)
{
	int i=0,j=0,iCnt=1;
	if(arr==NULL || iSize<=0)
	{
		return;
	}
 for(i=0;i<iSize;i++)
        {
                printf("%d",arr[i]);
        }

	printf("\n");


	for(i=0;i<iSize;i++)
	{
	
		for(j=2;j<=(arr[i]/2);j++)
		{
			if((arr[i]%j)==0)
			{
				break;
				
			}
		}
	
		if((j>(arr[i]/2)))
		{
			iCnt++;
			
		 	if((iCnt%2)==0)
			{
			
			
				printf("%d",arr[i]);
			}
		}
	}
		
}
int main()
{
	int n=0,i=0;
	int *p=NULL;

	printf("Enter how many elements you want:");
	scanf("%d",&n);

	p=(int*)malloc(n*sizeof(int));

	if(p==NULL)
	{
		printf("memory failure");
		return -1;
	}

	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}

	displayPrime(p,n);


	return 0;
}
