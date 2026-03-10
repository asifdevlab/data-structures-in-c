#include<stdio.h>

/*
Program: Find Minimum and Maximum Element in an Array
Author: Asif Hussain
Description:
This program reads 'n' elements into an array and determines the
minimum and maximum values among them.

Experiment: 1 (Data Structures Using C Lab)

Algorithm:
1. Read the number of elements.
2. Store the elements in an array.
3. Assume the first element as both minimum and maximum.
4. Traverse the array and compare each element with current min and max.
5. Update min and max accordingly.
6. Display the minimum and maximum values.

Time Complexity: O(n)
Space Complexity: O(n)
*/

int main(){

    // Array to store elements and variable to store number of elements
    int arr[100], n;

    // Variables to store minimum and maximum values
    int min, max;

    // Taking input for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Reading array elements from user
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Assume first element as initial minimum and maximum
    min = arr[0];
    max = arr[0];

    // Traverse the array to find minimum and maximum
    for(int i = 0; i < n; i++){

        // Check for minimum element
        if(arr[i] < min){
            min = arr[i];
        }

        // Check for maximum element
        if(arr[i] > max){
            max = arr[i];
        }
    }

    // Display results
    printf("Minimum Element: %d\n", min);
    printf("Maximum Element: %d", max);

    return 0;
}
