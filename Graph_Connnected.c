#include<stdio.h>
#include<stdlib.h>
int arr[100][100],n,iloop,jloop;
int check(int *ar)
{
	int counter=0;
	for(jloop=0;jloop<n;jloop++)
	{
		if(ar[jloop]==1)
		counter++;
	}
	return counter;
}
void check_connected()
{
	int flag;
	int *visit=(int *)calloc(sizeof(int),n);
	visit[0]=1;
	int current=0;
	while(check(visit)<n)
	{
		flag=0;
		for(iloop=0;iloop<n;iloop++)
		{
			if((arr[current][iloop]==1)&&(visit[iloop]==0))
			{
				flag=1;
				break;
			}
		}
		if(iloop==current)
		{
			printf("\nThe graph is disconnected\n");
			exit(0);
		}
		if(flag==1)
		{
			current=iloop;
			visit[current]=1;
			if(check(visit)==n)
			{printf("\nThe graph is connected\n");exit(0);}
			continue;
		}
		else
		{
			if(check(visit)==n)
			printf("\nThe graph is connected\n");
			else
			printf("\nThe graph is disconnected\n");
			exit(0);
		}
	}
}
void input()
{
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	//arr=(int **)calloc(sizeof(int),n*n);
	for(iloop=0;iloop<n-1;iloop++)
	{
		for(jloop=iloop+1;jloop<n;jloop++)
		{
			printf("\nEnter 1 if there is an edge between %d and %d, 0 otherwise:",(iloop+1),(jloop+1));
			scanf("%d",&arr[iloop][jloop]);
			if(arr[iloop][jloop]!=1&&arr[iloop][jloop]!=0)
			{
				printf("\nYou were told to enter either 1 or 0. You defied. My creator does not like defiants.\n");
				exit(0);
			}
			arr[jloop][iloop]=arr[iloop][jloop];
		}
	}
}
int main()
{
	input();
	check_connected();
}
