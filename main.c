#include <stdio.h>
#include <string.h>
#include "linkedlist.c"
#include "defines.h"

int main(void) 
{
	char address_file_path[30];
	strcpy(address_file_path, getenv("HOME"));
	strcat(address_file_path, "/addresses.csv");
	AddressBook *list = NULL;
	FILE *address_file = NULL;
	
	address_file = fopen(address_file_path, "r");

	if (address_file == NULL) {
		printf("File not found");
	}

	load_addresses(address_file, &list);	
	print_list(list);
	
	/*
	printf("Add new address, information should be in one line and separated by , [name,surname,email,number] :\n");
	char new_line[50];
	scanf("%[^\n]%*c", new_line);
	
	AddressBook *new_address = create_address_node(new_line);	
	add_to_list(&list, new_address);
	print_list(list);
	*/
	/* 
	delete_list(&list);
	printf("po delete");
	print_list(list);
	*/
	
	/*
	char insert_line[50];
	printf("Insert new address in desired place\n");
	printf("Type [name,surname,email,number]:\n");
	scanf("%[^\n]%*c", insert_line);
	printf("Enter desired place: \n");
	int place_to_insert;
	scanf("%d", &place_to_insert);

	AddressBook *new_address_to_insert = create_address_node(insert_line);

	insert_to_list(&list, new_address_to_insert, &place_to_insert);
	printf("Updated list:\n");	
	print_list(list);
	
	int length = list_length(list);
	printf("%d is the length of the list", length);
	*/

	/*
	int length = list_length(list);
	printf("%d\n", length);
	if (length > 0) {
		int place_to_delete;
		printf("Enter which address to delete [1 - %d]\n", length);	
		scanf("%d", &place_to_delete);
		delete_address(&list, &place_to_delete);
		print_list(list);
	}
	*/

		
	int length = list_length(list);
	int address_to_find;
	printf("Enter position [1 - %d]: \n", length);
	scanf("%d", &address_to_find);
	if (address_to_find > 0 && address_to_find <= length) {
		AddressBook *found_address = find_address(&list, &address_to_find);
		printf("Found address: %s %s %s %s\n", found_address->name, found_address->surname, found_address->email, found_address->number);
	}
	else {
		printf("Invalid position\n");
	}
	return 0;
}
