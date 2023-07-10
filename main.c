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

	/*		
	int length = list_length(list);
	int address_to_find;
	printf("Enter position [1 - %d]: \n", length);
	scanf("%d", &address_to_find);
	if (address_to_find > 0 && address_to_find <= length) {
		AddressBook *found_address = find_address_by_index(&list, &address_to_find);
		printf("Found address: %s %s %s %s\n", found_address->name, found_address->surname, found_address->email, found_address->number);
	}
	else {
		printf("Invalid position\n");
	}
	*/
	
	int search_type;
	printf("Search by: [1] Name [2] Surname [3] Email [4] Phone number\n");
	scanf("%d", &search_type);
	switch (search_type)
	{
		case 1:
			printf("Enter Name:\n");
			char name[15];
			scanf(" %[^\n]%*c", name);
			AddressBook *found_by_name = find_address_by_name(&list, name);
			if (found_by_name != NULL) {
			printf("Found address: %s %s %s %s\n", found_by_name->name, found_by_name->surname, found_by_name->email, found_by_name->number);
			}
			else {
				printf("Address could not be found!\n");
			}
			break;
		case 2:
			printf("Enter Surname:\n");
			char surname[15];
                        scanf(" %[^\n]%*c", surname);
			AddressBook *found_by_surname = find_address_by_surname(&list, surname);
			if (found_by_surname != NULL) {
                        printf("Found address: %s %s %s %s\n", found_by_surname->name, found_by_surname->surname, found_by_surname->email, found_by_surname->number);
                        }
                        else {
                                printf("Address could not be found!\n");
                        }
			break;
		case 3:
			printf("Enter Email:\n");
			char email[20];
                        scanf(" %[^\n]%*c", email);
			AddressBook *found_by_email = find_address_by_email(&list, email);
                        if (found_by_email != NULL) {
                        printf("Found address: %s %s %s %s\n", found_by_email->name, found_by_email->surname, found_by_email->email, found_by_email->number);
                        }
                        else {
                                printf("Address could not be found!\n");
                        }

			break;
		case 4:
			printf("Enter Phone number\n");
			char phNumber[15];
			scanf(" %[^\n]%*c", phNumber);
			AddressBook *found_by_number = find_address_by_phone_number(&list, phNumber);
                        if (found_by_number != NULL) {
                        printf("Found address: %s %s %s %s\n", found_by_number->name, found_by_number->surname, found_by_number->email, found_by_number->number);
                        }
                        else {
                                printf("Address could not be found!\n");
                        }

			break;
		default:
			printf("Invalind search type\n");
	}


	return 0;
}
