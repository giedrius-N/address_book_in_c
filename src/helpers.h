#ifndef HELPERS_DEFINES_H
#define HELPERS_DEFINES_H

extern void print_controls();
extern void add_new_address_to_address_book(AddressBook **list);
extern void insert_new_address(AddressBook **list);
extern void delete_address_by_position(AddressBook **list);
extern void find_address_by_position(AddressBook *list);
extern void search_by_criteria(AddressBook *list);

#endif
