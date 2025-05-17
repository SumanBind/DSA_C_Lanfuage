#include<stdio.h>
#include<math.h>
int main()
{
	int r1,c1,r2,c2,i,j,k;
	printf("Enter row and collom first matrix:");
	scanf("%d%d",&r1,&c1);
	printf("Enter row and collom second matrix:");
	scanf("%d%d",&r2,&c2);
	int a[r1][c1],b[r2][c2],result[r1][c2];
	
	printf("Enter first matrix");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter second matrix");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	int choice;
    printf("\nChoose an operation:\n");
    printf("1. Multiplaction\n");
    printf("2. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
       case 1: 
        	if(r1!=c2)
			{
				printf("Matrix not multiply\n");
				return 0;
			}
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c2;j++)
				{
					result[i][j]=0;
					for(k=0;k<r2;k++)
					{
						result[i][j]=result[i][j]+a[i][k]*b[k][j];
					}
				}
			}
			printf("multiply of matrix\n");
			for(i=0;i<r1;i++)
			{
		
				for(j=0;j<c2;j++)
				{
					printf("%d ",result[i][j]);
				}
				printf("\n");
			}
			break;
	case 2:
		printf("\n Transpose of first matrix:\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d ",a[j][i]);
			}
			printf("\n");
		}
		printf("\n Transpose of second matrix:\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d ",b[j][i]);
			}
			printf("\n");
		}
		break;
	 default:
            printf("Invalid choice\n");
	}
	return 0;
}

