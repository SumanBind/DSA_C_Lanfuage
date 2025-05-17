#include<stdio.h>

int main() 
{
    int r, c, i, j, k = 0;  
    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);
    int sparse_matrix[r][c];
    
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
		{
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    
    // Count non-zero elements in the matrix
    int size = 0;
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
		{
            if (sparse_matrix[i][j] != 0) 
			{
                size++;  
            }
        }
    }


    // Define a compact matrix to store the sparse matrix representation
    int compact_matrix[3][size];
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
		{
            if (sparse_matrix[i][j] != 0) 
			{
                compact_matrix[0][k] = i;           // Row index
                compact_matrix[1][k] = j;           // Column index
                compact_matrix[2][k] = sparse_matrix[i][j];    // Non-zero value
                k++;                    
            }
        }
    }
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
		{
            printf("%d ", sparse_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nSparse Matrix Representation:\n");
    for (i = 0; i < 3; i++) 
	{
        for (j = 0; j < size; j++) 
		{
            printf("%d ", compact_matrix
			[i][j]);
        }
        printf("\n");
    }

    return 0;
}
