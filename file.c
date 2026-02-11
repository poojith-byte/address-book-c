#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE *fptr = fopen("contacts.csv","w");
  int i=0;
  int index = addressBook->contactCount;
  fprintf(fptr,"#%d\n",index);
  for(i=0;i<index;i++){
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
  }
  fclose(fptr);
  printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr = fopen("contacts.csv","r");
    int i=0,count ;
    fscanf(fptr,"#%d\n",&count);
    addressBook->contactCount = count;
    for(i=0;i<count;i++){
      fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
  }