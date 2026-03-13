#include <stdio.h>

/*
Program: Matrix Operations (Addition, Subtraction, Multiplication, Transpose)
Author: Asif Hussain

Description:
This program performs basic matrix operations including
addition, subtraction, multiplication, and transpose.
The user enters the dimensions and elements of two matrices,
and the program performs the selected operation.

Experiment: Matrix Operations (Data Structures Using C Lab)

Algorithm:
1. Read the number of rows and columns of Matrix A and Matrix B.
2. Input the elements of both matrices.
3. Display a menu for matrix operations.
4. If the user selects addition or subtraction:
   - Check if both matrices have the same dimensions.
   - Perform element-wise addition or subtraction.
5. If the user selects multiplication:
   - Check if number of columns of Matrix A equals number of rows of Matrix B.
   - Perform matrix multiplication using nested loops.
6. If the user selects transpose:
   - Swap rows and columns of Matrix A.
7. Display the resulting matrix.

Time Complexity:
Addition: O(n × m)
Subtraction: O(n × m)
Multiplication: O(n × m × p)
Transpose: O(n × m)

Space Complexity:
O(n × m)
*/

int main()
{
    // Declaring matrices
    int A[10][10], B[10][10], result[10][10];
    
    // Variables for rows, columns and loops
    int r1, c1, r2, c2;
    int i, j, k;
    int choice;

    // Taking size of Matrix A
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    // Taking size of Matrix B
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Taking elements of Matrix A
    printf("\nEnter elements of Matrix A:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Taking elements of Matrix B
    printf("\nEnter elements of Matrix B:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Displaying operation menu
    printf("\nChoose the operation:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Transpose of Matrix A\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {

        // Matrix Addition
        case 1:

            // Condition: matrices must have same size
            if(r1 == r2 && c1 == c2)
            {
                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c1; j++)
                    {
                        result[i][j] = A[i][j] + B[i][j];
                    }
                }

                printf("\nResultant Matrix (Addition):\n");

                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c1; j++)
                    {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Addition not possible. Matrices must have same dimensions.\n");
            }

        break;


        // Matrix Subtraction
        case 2:

            if(r1 == r2 && c1 == c2)
            {
                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c1; j++)
                    {
                        result[i][j] = A[i][j] - B[i][j];
                    }
                }

                printf("\nResultant Matrix (Subtraction):\n");

                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c1; j++)
                    {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Subtraction not possible. Matrices must have same dimensions.\n");
            }

        break;


        // Matrix Multiplication
        case 3:

            // Condition: columns of A must equal rows of B
            if(c1 == r2)
            {
                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c2; j++)
                    {
                        result[i][j] = 0;

                        for(k = 0; k < c1; k++)
                        {
                            result[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }

                printf("\nResultant Matrix (Multiplication):\n");

                for(i = 0; i < r1; i++)
                {
                    for(j = 0; j < c2; j++)
                    {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Multiplication not possible.\n");
            }

        break;


        // Transpose of Matrix A
        case 4:

            printf("\nTranspose of Matrix A:\n");

            for(i = 0; i < c1; i++)
            {
                for(j = 0; j < r1; j++)
                {
                    printf("%d ", A[j][i]);
                }
                printf("\n");
            }

        break;

        default:
            printf("Invalid Choice.\n");
    }

    return 0;
}