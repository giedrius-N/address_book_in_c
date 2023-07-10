#ifndef DEFINES_H
#define DEFINES_H

typedef struct AddressBook
{
	char name[30];
	char surname[30];
	char email[30];
	char number[13];
	struct AddressBook *next;	
} AddressBook;

AddressBook *create_address_node(char *line);
AddressBook *create_node(char *name, char *surname, char *email, char *number);
void add_to_list(AddressBook **list, AddressBook *address);
void load_addresses(FILE *file, AddressBook **list);
void print_list(AddressBook *list);
void delete_list(AddressBook **list);
void insert_to_list(AddressBook **list, AddressBook *address, int *index);
int list_length(AddressBook *list);
void delete_address(AddressBook **list, int *index);
AddressBook *find_address_by_index(AddressBook **list, int *index);
AddressBook *find_address_by_name(AddressBook **list, char *name);
AddressBook *find_address_by_surname(AddressBook **list, char *surname);
AddressBook *find_address_by_email(AddressBook **list, char *email);
AddressBook *find_address_by_phone_number(AddressBook **list, char *number);

#endif
