#include <stdio.h>
#include <stdlib.h>

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
	surname = strtok(NULL, ",");
	email = strtok(NULL, ",");
	number = strtok(NULL, ",");

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
	while (temp != NULL) {
		printf("%s %s %s %s\n", temp->name, temp->surname, temp->email, temp->number);
		temp = temp->next;
	}
}

void delete_list(AddressBook **list)
{
	AddressBook *delete = *list;
	while (*list != NULL) {
		*list = (*(list))->next;
		free(delete);
		delete = *list;
	}
}

void insert_to_list(AddressBook **list, AddressBook *address, int *index)
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
	}
	else {	
		for (int i = 1; i < *index - 1; i++) {
			temp = temp->next;
		}
		address->next = temp->next;
		temp->next = address;
	}
}

void delete_address(AddressBook **list, int *index) {
	AddressBook *temp = *list;
	if (!(*index > 0 && *index <= list_length(*list))) {
		return;
	}
	if (*index == 1) {
		*list = temp->next;
		free(temp);
		return;
	}
	else if (*index > 1 && *index < list_length(*list)){
		for (int i = 1; i < *index -1; i++) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
		}
		AddressBook *toDelete = temp->next;
		temp->next = temp->next->next;
		free(toDelete);
		return;
	}
	else if (*index == list_length(*list)){
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		return ;
	}
}

AddressBook *find_address(AddressBook **list, int *index)
{
	AddressBook *temp = *list;
	for (int i = 1; i < *index; i++) {
		temp = temp->next;
	}
	AddressBook *address = temp;
	return address;

	printf("%s %s %s %s\n", temp->name, temp->surname, temp->email, temp->number);

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
