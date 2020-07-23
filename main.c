#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/deque.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Add first deque element.",
		" 2. Add last deque element.",
		" 3. Remove first deque element.",
		" 4. Remove last deque element.",
		" 5. Return value of the first element.",
		" 6. Return value of the last element.",
		" 7. Display deque.",
		" 8. Exit the program",
		NULL
};

int main(void) {
	op_status = 0;

	// Deque
	int qdata[DQSIZE] = {0};
	deque.first = -1;
	deque.last = -1;
	deque.data = qdata;

	struct deque *dptr = &deque;

	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);
	clear();
	display_menu(menu);

	opt = select_option(MINOPT, MAXOPT);

	while (1) {
		printf("You have selected: %d\n", opt);
		switch (opt) {
			case 1:
				clear();
				printf("Adding the first element to deque.\n");
				int first_item = enter_value(&op_status);
				deque_add_first(dptr, first_item, &op_status);
				break;

			case 2:
				clear();
				printf("Adding the last element to deque.\n");
				int last_item = enter_value(&op_status);
				deque_add_last(dptr, last_item, &op_status);
				break;

			case 3:
				clear();
				printf("Removing the first element out of deque.\n");
				int removed_first = deque_remove_first(dptr, &op_status);
				if (op_status == 1) {
					printf("The value of the removed element is %d.\n", removed_first);
				}
				break;

			case 4:
				clear();
				printf("Removing the last element out of deque.\n");
				int removed_last = deque_remove_last(dptr, &op_status);
				if (op_status == 1) {
					printf("The value of the removed element is %d.\n", removed_last);
				}
				break;

			case 5:
				clear();
				printf("Returning the value of the first element.\n");
				first_item = deque_first(dptr, &op_status);
				if (op_status == 1) {
					printf("The value of the first element is %d.\n", first_item);
				}
				break;

			case 6:
				clear();
				printf("Returning the value of the last element.\n");
				last_item = deque_last(dptr, &op_status);
				if (op_status == 1) {
					printf("The value of the last element is %d.\n", last_item);
				}
				break;

			case 7:
				clear();
				printf("Displaying deque.\n");
				display_deque(dptr);
				break;

			case 8:
				clear();
				printf("Exiting the program\n");
				return 0;
		}
		// Asking user for further actions;
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
	}
	return 0;
}
