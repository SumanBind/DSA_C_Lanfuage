#include<stdio.h>




int main()
{
    int r1, c1, i, j;

    // Input matrix dimensions
    printf("Enter rows and columns of the matrix: ");
    scanf("%d%d", &r1, &c1);

    int a[r1][c1], b[r1][c1], result[r1][c1];

    // Input the first matrix
    printf("Enter first matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input the second matrix
    printf("Enter second matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    int choice;
    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // Matrix addition
            for(i = 0; i < r1; i++)
            {
                for(j = 0; j < c1; j++)
                {
                    result[i][j] = a[i][j] + b[i][j];
                }
            }
            printf("Sum of matrices:\n");
             for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
            break;

        case 2: // Matrix subtraction
            for(i = 0; i < r1; i++)
            {
                for(j = 0; j < c1; j++)
                {

                    result[i][j] = a[i][j] - b[i][j];
                }
            }
            printf("Difference of matrices:\n");
         for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}

