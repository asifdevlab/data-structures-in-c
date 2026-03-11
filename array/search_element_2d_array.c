/*
Program: Search an element in a 2D array
Concept: Arrays, Linear Search
Time Complexity: O(n*m)
Space Complexity: O(1)
*/

#include <stdio.h>

int main()
{
    int arr[3][3];
    int search, found = 0;

    printf("Enter 9 elements of the 2D array:\n");

    // Input elements
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    // Searching element
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(arr[i][j] == search)
            {
                printf("Element found at position (%d,%d)\n", i, j);
                found = 1;
            }
        }
    }

    if(found == 0)
    {
        printf("Element not found in the array");
    }

    return 0;
}

/*
Sample Input:
1 2 3
4 5 6
7 8 9
Search element: 5

Sample Output:
Element found at position (1,1)
*/