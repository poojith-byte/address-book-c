#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
extern int arr[100];
int print(int index,AddressBook *AddressBook){
    // it will recive the index and print it 
    Contact *p = &AddressBook->contacts[index]; //in pointer p we store the address of AddressBook->contacts[index]
    printf("\n==================== Contact List (%d) ====================\n", index);
    printf("%-20s %-15s %-30s\n", "NAME", "PHONE", "EMAIL");
    printf("-----------------------------------------------------------\n");
    //printf("%s  %s   %s",p->name,p->phone,p->email);
    printf("%-20.20s %-15s %-30s\n",p->name,p->phone,p->email);
    fflush(stdout);
}
int validatename(char *prename){
    // This function will recive string first address as a argument and validata the name by is it in range of A-Z or a-z ,if name is correct it will return 1 or if not correct it will return 0
    int i=0;
    int space = 0;
    while(prename[i]!='\0'){
        if((prename[i]>='A' && prename[i]<='Z') || (prename[i]>='a' && prename[i]<='z') || prename[i] == ' ') // in this condition we r checking prename[i] is with in a-z or A-Z or ' '
        {
            if(prename[i]==' ')//condition to check if prename[i] == ' '
            {
                space ++;
            }
            i++;
        }
        else{
            return i;
        }
    }
    if((i>3) && (space<3))//condition to check name size is greater then 3 and space should not be more then 3
    {
    return 1;
    }
    else{
        printf("Error: Name must contain at least 3 characters or it has more then 3 space.\n");
        return 0;
    };
}

int del(int index,AddressBook *addressBook){
    //this function accepts a string index and an addressbook pointer as arguments,and it will exchange the values of index and decrese the Contactcount by 1 
    int count = addressBook->contactCount;//collect total count of contact 
    int i=0;
    for(i=index;i<=count-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];//it will swap the i with i++
    }
    if(i==count)//to check loop has completed sucessfully or not
    {
        addressBook->contactCount--;//decrement contact count by 1
        return 1;
    }
    else{
        return 0;
    }
}
int uniq(char *ph,AddressBook *addressBook){
    //This function accept a phone nhumber string 0th index address and addressbook pointer, and it will compare the ph string with string with in addressbook
    int index = addressBook->contactCount;//collect total count of contact 
    for(int i=0;i<index;i++){
        if(!(strcmp(ph,addressBook->contacts[i].phone)))//compare ph with contact phone number of index i
        {
            return 1;//if it founds a duplicate it will return 1
        }
    }
    return 0;
}
int uniqmail(char *gm,AddressBook *addressBook){
    //This function accept a phone nhumber string 0th index address and addressbook pointer, and it will compare the gm string with string with in addressbook
    int index = addressBook->contactCount;
    for(int i=0;i<index;i++){
        if(!(strcmp(gm,addressBook->contacts[i].email))){
            return 1;
        }
    }
    return 0;
}

int search_by_name(char *myname,AddressBook *addressBook){
    //This function accept a string address and addressbook pointer , and it will search the name in the addressbook and return in index if found ,if not return -1
    int index = addressBook->contactCount,i=0,found=0;//collect total count of contact 
    for(i=0;i<index;i++){
        if(!strcmp(addressBook->contacts[i].name,myname))//compare name with contact name number of index i
        {
            return i;//if found it will return index
        }  
    }
return -1;
}
int search_by_number(char *phone,AddressBook *addressBook){
    //This function accept a string address and addressbook pointer , and it will search the name in the addressbook and return in index if found ,if not return -1
    int index = addressBook->contactCount,i;//collect total count of contact 
    for(i=0;i<index;i++){
        if(!strcmp(addressBook->contacts[i].phone,phone))//compare phone with contact phone number of index i
        {
            return i;//if it founds a duplicate it will return 1
        }
    }
    return -1;
}
int search_by_mail(char *mail,AddressBook *addressBook){
    //This function accept a string address and addressbook pointer , and it will search the name in the addressbook and return in index if found ,if not return -1
    int index = addressBook->contactCount,i=0;//collect total count of contact 
    for(i=0;i<index;i++){
        if(!strcmp(addressBook->contacts[i].email,mail))//compare male with contact name number of index i
        {
            return i;//if it founds a duplicate it will return 1
        }
    }
    return -1;
}
int validatephone(char *perphone,AddressBook *addressBook){
    //This function accept a string address and addressbook pointer , and it will chact will str 0th index have 6-9 and must have 10 character 
    int i=0;
    if((perphone[0]>='6' && perphone[0]<='9'))//it should start with 6-9
    {
    while(perphone[i]!='\0'){
        if(perphone[i]>='0' && perphone[i]<='9')//it should contais only 0-9
        {
            i++;
        }
        else{
            return 0;
        }
    }
    if(i==10)//total sount should be 10
        {
            return 1; // if every thing is validated it will return 1
        }
    else{
        printf("Error: Number is less then 10 digits\n");
        return 0;
    }
    
    }
    else{
        printf("Error: Numner should start with 6-9\n");
        return 0;
    }
    
}
int validateemail(char *premail,AddressBook *addressBook){
    //This function accept a string address and addressbook pointer, and validate mail
    char *mail[]={"@gmail.","@outlook.","@yahoo."};//domine names
    int i=0,c=0,d;
    char domine[20];
    while(premail[i]!='@')//looping till premail of i finds '@'
    {
                if(premail[i]>='a'&& premail[i]<='z' || premail[i]>='0' && premail[i]<='9' || premail[i]=='.')//mail should contains only a-z or A-Z or 1-9 or '.'
                
                {
                    c++;
                }
                else{
                    printf("Error: email should not contain : %c\n",premail[i]);
                    return 0;
                }
                i++;
    }
            d=c;
            if(c>=6) //before count there should me min of 6 character
            {
                while(premail[d]!='\0')//collect the index of '.'
                {
                    if(premail[d]=='.'){
                    break;
                }   
                d++;
                }
                if(premail[d]=='\0'){

                    return 0;
                }
            }
            else{
                printf("Error: before '@' there must be 6 characters\n");
                return 0;
            }

    i=0;
    while(c<=d)//loading domine to a domint string
    {
        domine[i]=premail[c];
        i++;
        c++;
    }
    domine[i]='\0';//making domine string last index as null character
    for(i=0;i<3;i++)
    {
    if(!strcmp(domine,mail[i]))//comparing the domine with all avaliable domine name
    {
        int len = strlen(premail);
        if (len >= 4 && strcmp(&premail[len - 4], ".com") == 0)//checking it has '.com'
        {
        return 1;
    }
    }
    }
    printf("Error: enter a vaild domine\n");
    return 0;
    }
int dup(char *name,AddressBook * addressbook){
    //This function accepts a string pointer and an AddressBook pointer as arguments, searches for contacts matching the name, stores their indices in an array, and returns the total count of matches found.
    int index = addressbook->contactCount;//collect the total count of contacts
    int i;
    int com=0;
    int f =search_by_name(name,addressbook);//it will search the name and return index
    if(f!=-1)
    {
    for(i=0;i<index;i++){
        if(!strcmp(name,addressbook->contacts[i].name))// compare with contacts name
        {
            arr[com] = i; //collecting the index of duplicates names 
            com++;//incriment the index 
        }
    }
    return com;//return the total duplicates count
    }
    else{
        return -1;
        }
    }
void listContacts(AddressBook *addressBook) 
//This function accept addressbook pointer , and list every element in addressbook
{
    int index = addressBook->contactCount;//collect the total count od contacts
    if(index==0)//if contacts is empty it will check
    {
        printf("contacts is empty");
    }
    else{
    int i=0;
    printf("\n==================== Contact List (%d) ====================\n", index);
    printf("%-20s %-15s %-30s\n", "NAME", "PHONE", "EMAIL");
    printf("-----------------------------------------------------------\n");
    while(i<index)//loop till the contacts index 
    {
        printf("%-20.20s %-15s %-30s\n", 
                   addressBook->contacts[i].name, 
                   addressBook->contacts[i].phone, 
                   addressBook->contacts[i].email);
        i++;
    }
}}
void initialize(AddressBook *addressBook) {
    // initialize addressbook and count to 0
    addressBook->contactCount = 0;
    
    
    loadContactsFromFile(addressBook);
}
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
//This function accept a addressbook pointer ,and menu will be prented and select the funtions
{   
    int index = addressBook->contactCount;//collect the total contact count
    int vname,vphone,vemail,limit=0;
	char prename[50];
    char perphone[20];
    char premail[50];


    while(limit!=1)//untill user enter correct valid name it will loop
    {
    printf("enter name: ");
    getchar();
    //collecting the name
    scanf(" %[^\n]",prename);
    vname=validatename(prename);//validate name
        if(vname==1)//if user enter valid name it will go inside the loop
        {
            strcpy(addressBook->contacts[index].name,prename);//copy to the contacts
            limit=1;
        }
        else if(vname==-1){
            printf("Create again\n");
        }
        else{
            printf("%c is wrong\nplz enter a correct name\n",prename[vname]);//if user enter nat a valid name
        }
    }


    limit=0;
    while(limit!=1)//untill user enter correct valid name it will loop
    {
        //collecting the name
        printf("enter phone number: ");
        scanf("%s",perphone);
        vphone=validatephone(perphone,addressBook);//validation of phone number
        int unq =uniq(perphone,addressBook);//check for any duplicate number
        if((vphone==1) && (unq==0))//if only phone number is validated and it is unique then only copy to contacts
        {
            strcpy(addressBook->contacts[index].phone,perphone);//copying to contacts
            limit=1;
        }
        else{
            printf("enter correct phone number\n");
        }
    }



    limit=0;
    while(limit!=1)//untill user enter correct valid name it will loop
    {   printf("These are the valid email gmail.com, outlook.com,yahoo.com\n");
        printf("enter email.d:");
        //collecting the name
        scanf("%s",premail);
        if((uniqmail(premail,addressBook))){
            printf("Error: Email already exist\n");
        }
        if((validateemail(premail,addressBook)) && (!uniqmail(premail,addressBook)))//if only mail is validated and it is unique then only copy to contacts
        {
            strcpy(addressBook->contacts[index].email,premail);//copying to contacts
            limit=1;
        }
        else{
            printf("enter a correct mailid\n");
        }
    }

        printf("Contact successfully created\n");
        
        addressBook->contactCount++;
    
}

void searchContact(AddressBook *addressBook) 
// This function accepts an addressbook pointer and searches for contacts by name, phone, or email
{
    char name[50],phone[20],mail[50];
    int choose,v,i,exit=0;
    int index;
    do
    {
    printf("search contact menu\n1:Name\n2:phone number\n3:email\n4:exit\nEnter your choice: ");
    scanf("%d",&choose);// Input the user's choice for search criteria
    while (getchar() != '\n');// Clear the input buffer
    switch (choose){
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]",name);// Read name including spaces
            v=validatename(name);// Validate the name format
            if(v==1){
                index = search_by_name(name,addressBook);// Search for the name index
                if(index == -1){
                    printf("Contact not found. Please enter the correct name.\n");
                    
                }
                else{
                    print(index,addressBook);// Print the found contact details
                    exit=1;
                }
            }
            break;
        case 2:
            printf("enter phone number: ");
            scanf("%s",phone);// Input phone number string
            v=validatephone(phone,addressBook);// Validate phone number rules
            if(v==1)
            {
                index = search_by_number(phone,addressBook);// Search for phone index
                if(index == -1)
                {
                    printf("Contact not found. Please enter the correct phone number.\n");
                   
                }
                else
                {   
                    print(index,addressBook);// Print the found contact details
                    exit=1;
                }
            }
            else
            {
                printf("enter a valid phone number.\n");
            }
            break;
        case 3:
            printf("Enter mail id: ");
            scanf("%s",mail);// Input email string
            if(validateemail(mail,addressBook))// Validate email format 
            {
                index=search_by_mail(mail,addressBook);// Search for email index
                if(index == -1){
                    printf("mail id not present\n\n");
                }
                else{
                    print(index,addressBook);// Print the found contact details
                    exit=1;
                }
                
            }
            else{
                printf("\nenter a valid mail id\n\n");// User chose to exit manually
            }
            break;
        case 4:
            
            exit=1;
            break;
        default:
            printf("\nenter number 1 - 4 only\n");
            


    }

}while(exit!=1);
            printf("-----------------------------------------------------------\n");
            printf("----------------exited sucessfully-------------------------\n");
            printf("-----------------------------------------------------------\n");
        
        }

void editContact(AddressBook *addressBook)
//This function accept a addressbook pointer, and print the menu and edit the addressbook
{
	int choose,exit,k;
    char str[50],newstr[50];
    do{
        printf("\n1:Edit name\n2:Edit phone number\n3:Edit email.d\n4:Exit\nEnter the choose: ");
        scanf("%d",&choose);// Input choice for editing
        getchar();// Clear newline
        switch(choose){
            case 1:
                printf("Name: ");
                scanf(" %[^\n]",str);// Read the name to search for
                getchar();
                if(validatename(str)){
                    int count = dup(str,addressBook);// Check for duplicate names and store indices in arr[]
                    if(count == -1){
                        printf("\nname is not in the contact\n");
                    }else{
                    printf("conform the contecxt\n");
                    int i=0; 
                    while(i<count){
                        int k  = arr[i];// Access index stored in global array
                        printf("\n====================++ Contact List ++====================\n");
                        printf("%-6s %-20s %-15s %-30s\n", "Sl no","NAME", "PHONE", "EMAIL");
                        printf("-----------------------------------------------------------\n");
                        printf("%-6d %-20.20s %-15s %-30s\n",i+1,addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
                        i++;
                    }
                    printf("enter the sl no of name which u want to edit\n");
                    int index;
                    scanf("%d",&index);// User selects which duplicate to edit
                    printf("\nEnter a new name: ");
                    getchar();
                    scanf(" %[^\n]",newstr);// Read the replacement name
                    if(validatename(newstr)){
                    strcpy(addressBook->contacts[arr[index-1]].name,newstr);//copying the new name to it address book
                    exit =4;}
                    else{
                        printf("Enter the valid New name\n");
                    }
                }
                }
                else{
                    printf("enter a valid name");
                }
                break;
            case 2:
                printf("Phone number: ");
                scanf(" %[^\n]",str);
                getchar();
                k=search_by_number(str,addressBook);// Locate contact by phone
                if(validatephone(str,addressBook)){
                if(k==-1){
                    printf("number not in context--enter a valid number\n\n");
                }
                else{   
                        printf("enter a new number: ");
                        scanf(" %[^\n]",newstr);
                        if(validatephone(newstr,addressBook)){
                        strcpy(addressBook->contacts[k].phone,newstr);// Update phone number
                        exit =4;
                    }   
                }}
                else{
                    printf("enter a valid number");
                }
                break;
            case 3:
                printf("mail id: ");
                scanf(" %[^\n]",str);
                getchar();
                k=search_by_mail(str,addressBook);// Locate contact by email
                if(validateemail(str,addressBook)){
                if(k==-1){
                    printf("mail not in context--enter a valid mail\n\n");
                }
                else{
                        printf("Enter new mail id: ");
                        scanf(" %[^\n]",newstr);
                        if(validateemail(newstr,addressBook)){
                        strcpy(addressBook->contacts[k].email,newstr);// Update email
                        exit =4;
                    }
                
                }}
                else{
                    printf("enter a valid mail id");
                }
                break;
            case 4:
                exit =4;// Exit edit menu

                

        }

    }while(exit!=4);
    printf("contact sucessfully updated\n");
}

void deleteContact(AddressBook *addressBook)
//This function accept a string address and addressbook pointer ,and print the menue and delete the content based on the manu
{   
    char str[50];
    int choose,v,i,exi=0;
    int index;
    char yes;
    do
    {
    printf("\ncontact menu\n1:Name\n2:phone number\n3:email\n4:exit\nEnter your choice: ");
    scanf("%d",&choose);//selecttion of menu
    while (getchar() != '\n');
    switch (choose){
        case 1:
            printf("Enter name: ");
            //taking input name
            scanf(" %[^\n]",str);
            v=validatename(str);
                if(v==1){
                    index = search_by_name(str,addressBook);
                    if(index == -1){
                        printf("Contact not found. Please enter the correct name.\n");
                    }
                    else{
                        printf("are u sure u want to delete(y/n) \n");
                        getchar();
                        scanf(" %c",&yes);
                        if(yes == 'y')
                        {
                        del(index,addressBook);
                        exi=1;
                        }
                        else
                        {
                            break;
                        }
                       
                    }
                }
            break;
        case 2:
            printf("enter phone number: ");
            scanf("%s",str);
            v=validatephone(str,addressBook);
                if(v==1)
                {
                    index = search_by_number(str,addressBook);
                    if(index == -1)
                    {
                        printf("Contact not found. Please enter the correct phone number.\n");
                    
                    }
                    else
                    {   printf("are you sure you want to delete(y/n) \n");
                        getchar();
                        scanf(" %c",&yes);
                        if(yes == 'y'){
                            del(index,addressBook);
                        exi=1;}
                        else{
                            break;
                        }
                    }
                }
                else
                {
                    printf("enter a valid phone number.\n");
                }
            break;
        case 3:
            printf("Enter mail id: ");
            scanf(" %s",str);
            if(validateemail(str,addressBook))
                {
                    index=search_by_mail(str,addressBook);
                    if(index == -1)
                    {
                        printf("enter a valid mail id\n");
                    }
                    else
                    {printf("are u sure u want to delete(y/n) \n");
                        getchar();
                        scanf(" %c",&yes);
                        if(yes == 'y')
                        {
                        del(index,addressBook);
                        exi=1;
                        }
                        else
                        {
                            break;
                        }
                    }
                    
                }
                else
                {
                    printf("enter a valid mail id");
                }
            break;
        case 4:
            exi=1;
            break;
        default:
            printf("enter number 1 - 4 only");
            


    }

}while(exi!=1);

printf("contact sucessfully Deleted\n");
}

