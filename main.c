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

	return 0;
}
