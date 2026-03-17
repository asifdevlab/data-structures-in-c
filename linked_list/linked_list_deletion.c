#include <stdio.h>
#include <stdlib.h>

// Define structure
struct node 
{
    int data;
    struct node* next;
};

struct node* head = NULL;

// Function to create a node (for testing)
void insert_end(int value) 
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) 
	{
        head = newnode;
    } else 
	{
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

// Display list
void display() 
{
    struct node* temp = head;
    if (temp == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) 
	{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// a) Delete first node
void delete_first() 
{
    if (head == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted\n");
}

// b) Delete last node
void delete_last() 
{
    if (head == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) 
	{
        free(head);
        head = NULL;
    } else {
        struct node* temp = head;
        while (temp->next->next != NULL) 
		{
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("Last node deleted\n");
}

// c) Delete node after a given value
void delete_after(int key) 
{
    struct node* temp = head;

    while (temp != NULL && temp->data != key) 
	{
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) 
	{
        printf("Deletion not possible\n");
        return;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Node after %d deleted\n", key);
}

// Main function with menu
int main() 
{
    int choice, value;

    // Sample data
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    while (1) 
	{
        printf("\n--- MENU ---\n");
        printf("1. Delete First Node\n");
        printf("2. Delete Last Node\n");
        printf("3. Delete Node After Given Value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                delete_first();
                break;
            case 2:
                delete_last();
                break;
            case 3:
                printf("Enter value after which node to delete: ");
                scanf("%d", &value);
                delete_after(value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
    
}
