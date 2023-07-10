#include <stdio.h>
#include <string.h>
#include "linkedlist.c"
#include "defines.h"

void add_new_address_to_address_book(AddressBook *list);
void insert_new_address(AddressBook *list);
void delete_address_by_position(AddressBook **list);
void find_address_by_position(AddressBook *list);
void search_by_criteria(AddressBook *list);

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
	
	char input[50];

	char control = ' ';
	while (control != '0') {
		printf("\nChoose function: \n");
		printf("[1] Display all records\n");
		printf("[2] Add new address\n");
		printf("[3] Add new address indicating the position\n");
		printf("[4] Delete address indicating the position\n");
		printf("[5] Delete whole address book\n");
		printf("[6] Find address by position\n");
		printf("[7] Find address by name, surname, email or phone number\n");
		printf("[0] Quit\n");

		scanf(" %s", input);

		if (strlen(input) > 1) {
			printf("\nInvalid selection!\n");
        		continue;
		}

		control = input[0];

		switch (control)
		{
			case '0':
				break;
			case '1':
				print_list(list);
				break;
			case '2':
				add_new_address_to_address_book(list);
				break;
			case '3':
				insert_new_address(list);
				break;
			case '4':
				delete_address_by_position(&list);
				break;
			case '5':
				delete_list(&list);
				break;
			case '6':
				find_address_by_position(list);
				break;
			case '7':
				search_by_criteria(list);
				break;
			default:
				printf("\nInvalid selection!\n");
				break;

		}
	}		

	return 0;
}

void add_new_address_to_address_book(AddressBook *list)
{
	printf("Add new address, information should be in one line and separated by , [name,surname,email,number] :\n");
        char new_line[50];
        scanf(" %[^\n]%*c", new_line);
        
        AddressBook *new_address = create_address_node(new_line);       
        add_to_list(&list, new_address);

}

void insert_new_address(AddressBook *list)
{
	char insert_line[50];
        printf("Insert new address in desired place\n");
        printf("Type [name,surname,email,number]:\n");
        scanf(" %[^\n]%*c", insert_line);
        printf("Enter desired place: \n");
        int place_to_insert;
        scanf("%d", &place_to_insert);

        AddressBook *new_address_to_insert = create_address_node(insert_line);

        insert_to_list(&list, new_address_to_insert, &place_to_insert);

}

void delete_address_by_position(AddressBook **list) {
    int length = list_length(*list);
    if (length > 0) {
        int place_to_delete;
        printf("Enter which address to delete [1 - %d]\n", length);     
        scanf("%d", &place_to_delete);
        delete_address(list, &place_to_delete);
    }
}

void find_address_by_position(AddressBook *list)
{
	int length = list_length(list);
        int address_to_find;
        printf("Enter position [1 - %d]: \n", length);
        scanf("%d", &address_to_find);
        if (address_to_find > 0 && address_to_find <= length) {
                AddressBook *found_address = find_address_by_index(&list, &address_to_find);
                printf("Found address:\n%s %s %s %s\n", found_address->name, found_address->surname, found_address->email, found_address->number);
        }
        else {
                printf("Invalid position\n");
        }
}

void search_by_criteria(AddressBook *list)
{
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
			printf("Invalid search type\n");
	}
}
