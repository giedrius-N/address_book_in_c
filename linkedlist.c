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

