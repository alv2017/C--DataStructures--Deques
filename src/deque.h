#ifndef DEQUE_H
#define DEQUE_H

#define DQSIZE 10

// Deque
struct deque {
	long first;
	long last;
	int *data;
};

struct deque deque;

// Operation status
short op_status;

// Display deque
void display_deque(struct deque *);

// Add the first element to deque
struct deque *deque_add_first(struct deque *, int, short *);

// Add the last element to deque
struct deque *deque_add_last(struct deque *, int, short *);

// Remove first element from deque
int deque_remove_first(struct deque *, short *);

// Remove last element from deque
int deque_remove_last(struct deque *, short *);

// Return the value of the first element
int deque_first(struct deque *, short *);

// Return the value of the last element
int deque_last(struct deque *, short *);

#endif



