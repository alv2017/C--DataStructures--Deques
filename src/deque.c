#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// Display deque
void display_deque(struct deque *dq) {
	// The deque is empty
	if (dq->first == -1) {
		printf("The deque is empty.\n");
		return;
	}

	long cnt = 1;
	long i = dq->first;

	while(i != dq->last ) {
		printf("Deque: %5ld; position: %5ld; value: %5d\n", cnt, i, dq->data[i]);
		i = (i+1) % DQSIZE;
		cnt++;
	}
	printf("Deque: %5ld; position: %5ld; value: %5d\n", cnt, i, dq->data[i]);
}

// Add first element to deque
struct deque *deque_add_first(struct deque *dq, int value, short *op_status) {
	*op_status = 0;
	// Deque is full
	if ( (dq->last + 1) % DQSIZE == dq->first ) {
		puts("The deque is full. It is not possible to add a new item.");
		return dq;
	}
	*op_status = 1;
	if (dq->first == -1) {
		dq->first = 0;
		dq->last = 0;
	} else {
		dq->first = (dq->first + DQSIZE - 1) % DQSIZE;
	}
	dq->data[dq->first] = value;
	return dq;
}

// Add last element to deque
struct deque *deque_add_last(struct deque *dq, int val, short *op_status) {
	*op_status = 0;
	// Deque is full
	if ( (dq->last+1)%DQSIZE == dq->first ) {
		puts("The deque is full. It is not possible to add a new element.");
		return dq;
	}

	*op_status = 1;

	if (dq->first == -1) {
		dq->first = 0;
		dq->last = 0;
	} else {
		dq->last = dq->last + 1;
	}
	dq->data[dq->last] = val;
	return dq;
}

// Remove first element from deque
int deque_remove_first(struct deque *dq, short *op_status) {
	*op_status = 0;
	int val = 0;

	// Deque is empty
	if (dq->first == -1) {
		printf("The deque is empty. There is nothing to remove.\n");
		return val;
	}
	*op_status = 1;
	val = dq->data[dq->first];

	if (dq->first == dq->last) {
		dq->first = -1;
		dq->last = -1;
	} else {
		dq->first = (dq->first + 1) % DQSIZE;
	}
	return val;
}

// Remove last deque element
int deque_remove_last(struct deque *dq, short *op_status) {
	*op_status = 0;
	int val = 0;
	// Deque is empty
	if (dq->first == -1) {
		printf("The deque is empty. There is nothing to remove.\n");
		return val;
	}

	*op_status = 1;
	val = dq->data[dq->last];

	if (dq->first == dq->last) {
		dq->first = -1;
		dq->last = -1;
	} else {
		dq->last = (dq->last + DQSIZE - 1) % DQSIZE;
	}
	return val;
}

// Return value of the first deque element
int deque_first(struct deque *dq, short *op_status) {
	*op_status = 0;
	int val = 0;
	// Deque is empty
	if (dq->first == -1) {
		puts("The deque is empty.");
	} else {
		*op_status = 1;
		val = dq->data[dq->first];
	}
	return val;
}

// Return value of the last deque element
int deque_last(struct deque *dq, short *op_status) {
	*op_status = 0;
	int val = 0;
	// Deque is empty
	if (dq->first == -1) {
		puts("The deque is empty.");
	} else {
		*op_status = 1;
		val = dq->data[dq->last];
	}
	return val;
}





