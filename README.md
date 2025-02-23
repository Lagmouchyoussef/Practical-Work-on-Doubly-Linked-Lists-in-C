# TP

## Doubly Linked Lists

**Recall of some course concepts:**

A doubly linked list is a data structure that allows storing a sequence of values, where each cell contains a value and two pointers:

- A pointer to the next element in the list,
- A pointer to the previous element in the list.

Code:

```c
typedef struct cell {
    int value;
    struct cell* next; // Pointer to the next cell
    struct cell* prev; // Pointer to the previous cell
} cell;

typedef struct double_list {
    cell* head; // Pointer to the first element
    cell* tail; // Pointer to the last element
} list;

**Exercise 1:**
a. Write a C function to create a node for a doubly linked list.

b. Write a function to add a node at the beginning of the doubly linked list.

c. Write a function to add a node at the end of the doubly linked list.

d. Write a function to display all elements of a doubly linked list in order.

e. Write a function to delete the first element of the doubly linked list.

f. Write a function to delete the last element of the doubly linked list.

g. Write a function to delete a specific element based on its value in the doubly linked list. If multiple elements contain the value, delete only the first one found.
