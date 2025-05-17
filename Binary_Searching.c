#include <stdio.h>
int main()
{
	int n,key,p, c, i, j, temp;;
	printf("Enter the number:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter shorted array element:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter a key\n");
	scanf("%d",&key);
     p = n-1;
     c = n;
     for(i=1; i<=p; i++)
     {
          for(j=1; j<=c; j++);
          {
               if(a[j] > a[j+1])
               {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
               }
          }
     }
	int m;
	int l=0;
	int h=n;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==key)
		{
			printf("Element found at %d ",m+1);
			break;
		}
		else if(a[m]<key)
		{
			l=m+1;
		}
		else if(a[m]>key)
		{
			h=m-1;
		}
	}
	if(l>h)
	{
		printf("Data not found\n");
	}
	return 0;
}


