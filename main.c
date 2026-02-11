/*Description:

create a address book with functions with :
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit
7. Exit

Pr-requisites:- Functions,Pointers,structures 

Objective: - The objective of this project is to design and implement a modular 
Address Book Management System that allows users to store, retrieve, and manage contact information efficiently.

     
*/

#include <stdio.h>
#include "contact.h"
// creating arr to store duplicate index
int arr[100];
// initialize the address book and print the menu
int main() 
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book
    int str[100];
    do // loop will not end till choice is 7
    {   //print menu
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save and Exit\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        // selection of menu
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice <6);
    return 0;
}