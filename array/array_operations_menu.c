#include <stdio.h>

/*
Program: Menu Based Array Operations
Author: Asif Hussain

Description:
This program performs basic array operations using a menu-driven approach.
The user can insert an element at a specified position, delete an element
from a specified position, and display the array elements.

Experiment: 2 (Data Structures Using C Lab)

Operations Performed:
1. Insert an element at a given position
2. Delete an element from a given position
3. Display array elements

Algorithm:
1. Read the number of elements and store them in an array.
2. Display a menu with different operations.
3. Based on user choice:
   a. Insert an element at a given position by shifting elements to the right.
   b. Delete an element from a given position by shifting elements to the left.
   c. Display all elements of the array.
4. Repeat the menu until the user chooses to exit.

Time Complexity:
Insertion  : O(n)
Deletion   : O(n)
Display    : O(n)

Space Complexity: O(n)
*/

int main() {

    int arr[100], n, choice, pos, value;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n----- ARRAY OPERATIONS MENU -----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                // Insert element at specified position
                printf("Enter position to insert: ");
                scanf("%d", &pos);

                printf("Enter value to insert: ");
                scanf("%d", &value);

                if(pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                } 
                else {
                    // Shift elements to the right
                    for(int i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }

                    arr[pos - 1] = value;
                    n++;

                    printf("Element inserted successfully.\n");
                }
                break;

            case 2:
                // Delete element from specified position
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                } 
                else {
                    // Shift elements to the left
                    for(int i = pos - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }

                    n--;
                    printf("Element deleted successfully.\n");
                }
                break;

            case 3:
                // Display array elements
                printf("Array elements are:\n");
                for(int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}
