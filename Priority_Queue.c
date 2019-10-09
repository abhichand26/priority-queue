#include<stdio.h>
#include<malloc.h>
#define M 50

/*
** Program to implement Priority Queues
** Made by - Abhishek Chand
*/

int n=0;

void insert(int Q[],int x)
{
	int j;
	n++;
	j=n;
	while(j>1 && x<Q[j/2])
	{
		Q[j]=Q[j/2];
		j=j/2;
	}
	Q[j]=x;
}

void decreasePriority(int Q[],int i,int y)
{
	int j;
	j=i;
	while(j>1 && y<Q[j/2])
	{
		Q[j]=Q[j/2];
		j=j/2;
	}
	Q[j]=y;
}

void minHeapify(int Q[],int i)
{
	int x,l,r,min;
	x=Q[i];
	while(2*i<=n)
	{
		l=2*i;
		r=l+1;
		if(r<=n && Q[l]>Q[r])
			min=r;
		else
			min=l;
		if(x>Q[min])
		{
			Q[i]=Q[min];
			i=min;
		}
		else
			break;
	}
	Q[i]=x;
}

int extractMin(int Q[])
{
	int x=Q[1];
	Q[1]=Q[n];
	n--;
	minHeapify(Q,1);
	return x;
}


void printQueue(int Q[])
{
	int i;
  	printf("\nPriority Queue : ");
	for(i=1;i<=n;i++)
		printf("%d  ",Q[i]);
	printf("\n");
}

int main()
{
	int sel,x,i;
	char ch;
	int Q[M];
	do
	{
		printf("Select your action to perform:\n");
		printf("1-Insert Priority\n");
		printf("2-Extract Minimum Priority\n");
		printf("3-Decrease Priority\n");
		printf("4-Print Queue\n");
		printf("5-Exit\n");
		printf("Enter your choice:");
		scanf("%d",&sel);
		
		switch(sel)
 		{
			case 1:
  				printf("\nEnter the Priority to insert:");
  				scanf("%d",&x);
  				insert(Q,x);
  				break;
  				
			case 2:
  				x=extractMin(Q);
  				printf("\nExtracted Priority=%d",x);
  				break;

			case 3:
  				printf("\nEnter the place of Priority:");
  				scanf("%d",&i);
  				printf("\nEnter the new Priority:");
  				scanf("%d",&x);
  				decreasePriority(Q,i,x);
  				break;

			case 4:
				printQueue(Q);
  				break;

			case 5:
				return 0;

			default:
  				printf("That is not a valid selection!\n");
  		}
  		
  		printf("\nTo continue enter (Y/y):");
  		fflush(stdin);
  		scanf("%c",&ch);	
	}while(ch=='Y'||ch=='y');
	
	return 0;
}
