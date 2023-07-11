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

extern AddressBook *create_address_node(char *line);
extern AddressBook *create_node(char *name, char *surname, char *email, char *number);
extern void add_to_list(AddressBook **list, AddressBook *address);
extern void load_addresses(FILE *file, AddressBook **list);
extern void print_list(AddressBook *list);
extern void delete_list(AddressBook **list);
extern void insert_to_list(AddressBook **list, AddressBook *address, const int *index);
extern int list_length(AddressBook *list);
extern void delete_address(AddressBook **list, const int *index);
extern AddressBook *find_address_by_index(AddressBook **list, const int *index);
extern AddressBook *find_address_by_name(AddressBook **list, const char *name);
extern AddressBook *find_address_by_surname(AddressBook **list, const char *surname);
extern AddressBook *find_address_by_email(AddressBook **list, const char *email);
extern AddressBook *find_address_by_phone_number(AddressBook **list, const char *number);

#endif
