#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter a number\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int key;
	printf("Enter a key \n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		{
			printf("possition=%d",i+1);
			break;
		}
	}
	if(i==n)
	{
		printf("key is not match\n");
	}
	return 0;
}
