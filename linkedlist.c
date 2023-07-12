#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"

AddressBook *create_node(char *name, char *surname, char *email, char *number)
{
 	AddressBook *address = NULL;
	address = (AddressBook*) malloc(sizeof(AddressBook));
	if (address == NULL) {
		return NULL;
	}
	strcpy(address->name, name);
	strcpy(address->surname, surname);
	strcpy(address->email, email);
	strcpy(address->number, number);
	address->next = NULL;
	return address;
}

AddressBook *create_address_node(char *line)
{
	AddressBook *address = NULL;
	char *name, *surname, *email, *number;

	name = strtok(line, ",");
	if (name == NULL) return NULL;
	surname = strtok(NULL, ",");
	if (surname == NULL) return NULL;
	email = strtok(NULL, ",");
	if (email == NULL) return NULL;
	number = strtok(NULL, ",");
	if (number == NULL) return NULL;

	address = create_node(name, surname, email, number);

	return address;
}

void add_to_list(AddressBook **list, AddressBook *address)
{
	AddressBook *temp = *list;
	if (temp == NULL) {
		*list = address;
		return;
	}

	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = address;
}

void load_addresses(FILE *file, AddressBook **list)
{
	char line[128];
	while (fgets(line, sizeof(line), file)){
		AddressBook *address = NULL;
		if (strcmp(line, "\n") == 0){
			continue;
		}
		address = create_address_node(line);
		if (address != NULL){
			add_to_list(list, address);
		}
	}
}

void print_list(AddressBook *list)
{
	AddressBook *temp = list;

	if (temp == NULL) {
		printf("\nThe address book is empty\n");
		return;
	}	

	int i = 1;
	while (temp != NULL) {
		print_node(temp, &i);
		temp = temp->next;
		i++;
	}
}

void print_node(AddressBook *node, int *i)
{
	printf("[%d] %s %s %s %s\n", *i, node->name, node->surname, node->email, node->number);
}

void delete_list(AddressBook **list)
{	
	if (*list == NULL) {
		printf("\nList is already empty!\n");
		return;
	}
	AddressBook *delete = *list;
	while (*list != NULL) {
		*list = (*(list))->next;
		free(delete);
		delete = *list;
	}
}

void insert_to_list(AddressBook **list, AddressBook *address, const int *index)
{
	AddressBook *temp = *list;
	if (*index <= 1) {
		address->next = *list;
		*list = address;
		return;
	}
	else if (*index > list_length(temp)){
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = address;
		return;
	}
	else {	
		for (int i = 1; i < *index - 1; i++) {
			temp = temp->next;
		}
		address->next = temp->next;
		temp->next = address;
	}
}

void delete_addr_at_pos(AddressBook **list, const int *index) {
    	AddressBook *prev = *list;
    	AddressBook *temp = *list;
    	int i = 1;
    	if (*list == NULL) {
    		return;
    	}
    	while (temp != NULL) {
    		if (*index == i) {
    			prev->next = temp->next;
    			free(temp);
    			break;
    		}
    		prev = temp;
    		temp = temp->next;
    		i++;
    	}
    	return;
}

AddressBook *find_address_by_index(AddressBook **list, const int *index)
{
	AddressBook *temp = *list;
	for (int i = 1; i < *index; i++) {
		temp = temp->next;
	}
	AddressBook *address = temp;
	return address;
}

AddressBook *find_address_by_name(AddressBook **list, const char *name)
{
	AddressBook *temp = *list;
	AddressBook *result = NULL;
	while (temp != NULL) {
		if (strcmp(name, temp->name) == 0) {
			AddressBook* newAddress = (AddressBook*)malloc(sizeof(AddressBook));
			strcpy(newAddress->name, temp->name);
			strcpy(newAddress->surname, temp->surname);
			strcpy(newAddress->email, temp->email);
			strcpy(newAddress->number, temp->number);
			newAddress->next = NULL;
			
			if (result == NULL) {
				result = newAddress;
			}
			else {
				AddressBook *current = result;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = newAddress;
			}
		}
		temp = temp->next;
	}
	
	return result;
}

AddressBook *find_address_by_surname(AddressBook **list, const char *surname)
{
        AddressBook *temp = *list;
	AddressBook *result = NULL;
	while (temp != NULL) {
		if (strcmp(surname, temp->surname) == 0) {
			AddressBook* newAddress = (AddressBook*)malloc(sizeof(AddressBook));
			strcpy(newAddress->name, temp->name);
			strcpy(newAddress->surname, temp->surname);
			strcpy(newAddress->email, temp->email);
			strcpy(newAddress->number, temp->number);
			newAddress->next = NULL;
			
			if (result == NULL) {
				result = newAddress;
			}
			else {
				AddressBook *current = result;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = newAddress;
			}

			
		}
		temp = temp->next;
	}
	
	return result;

}

AddressBook *find_address_by_email(AddressBook **list, const char *email)
{
	AddressBook *temp = *list;
	AddressBook *result = NULL;
	while (temp != NULL) {
		if (strcmp(email, temp->email) == 0) {
			AddressBook* newAddress = (AddressBook*)malloc(sizeof(AddressBook));
			strcpy(newAddress->name, temp->name);
			strcpy(newAddress->surname, temp->surname);
			strcpy(newAddress->email, temp->email);
			strcpy(newAddress->number, temp->number);
			newAddress->next = NULL;
			
			if (result == NULL) {
				result = newAddress;
			}
			else {
				AddressBook *current = result;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = newAddress;
			}
		}
		temp = temp->next;
	}
	
	return result;
}

AddressBook *find_address_by_phone_number(AddressBook **list, const char *number)
{
        AddressBook *temp = *list;
	AddressBook *result = NULL;
	while (temp != NULL) {
		if (strcmp(number, temp->number) == 0) {
			AddressBook* newAddress = (AddressBook*)malloc(sizeof(AddressBook));
			strcpy(newAddress->name, temp->name);
			strcpy(newAddress->surname, temp->surname);
			strcpy(newAddress->email, temp->email);
			strcpy(newAddress->number, temp->number);
			newAddress->next = NULL;
			
			if (result == NULL) {
				result = newAddress;
			}
			else {
				AddressBook *current = result;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = newAddress;
			}
		}
		temp = temp->next;
	}
	
	return result;
}


int list_length(AddressBook *list)
{
	AddressBook *temp = list;
	int count = 0;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	
	return count;
}
