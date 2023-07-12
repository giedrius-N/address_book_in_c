#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "defines.h"

volatile sig_atomic_t g_signal_flag = 0;
void sig_handler(int signum)
{
	g_signal_flag = 1;
}

int main(void) 
{
	signal(SIGINT,sig_handler);
	signal(SIGQUIT,sig_handler);
	char address_file_path[30];
	strcpy(address_file_path, getenv("HOME"));
	strcat(address_file_path, "/addresses.csv");
	AddressBook *list = NULL;
	FILE *address_file = NULL;
	
	address_file = fopen(address_file_path, "r");

	if (address_file == NULL) {
		printf("\naddresses.csv file not found\n");
	}
	else {
		load_addresses(address_file, &list);	
		fclose(address_file);
	}
	
	char input[50];
	char control = ' ';
	while (control != '0' && !g_signal_flag) {
	
		print_controls();

		scanf(" %49s", input);

		if (strlen(input) > 1) {
			printf("\nInvalid selection!\n");
        		continue;
		}
		control = input[0];

		switch (control)
		{
			case '0':
				delete_list(&list);
				break;
			case '1':
				print_list(list);
				break;
			case '2':
				add_new_address_to_address_book(&list);
				break;
			case '3':
				insert_new_address(&list);
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
	if (list != NULL) {
		delete_list(&list);
	}
	
	return 0;
}
