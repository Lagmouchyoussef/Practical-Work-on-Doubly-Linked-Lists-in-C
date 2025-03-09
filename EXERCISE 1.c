#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int value;
    struct cell* next;
    struct cell* prev;
} cell;

typedef struct double_list {
    cell* head;
    cell* tail;
} list;

cell* create_node(int value) {
    cell* new_node = (cell*)malloc(sizeof(cell));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void add_to_beginning(list* lst, int value) {
    cell* new_node = create_node(value);
    if (lst->head == NULL) {
        lst->head = lst->tail = new_node;
    } else {
        new_node->next = lst->head;
        lst->head->prev = new_node;
        lst->head = new_node;
    }
}

void add_to_end(list* lst, int value) {
    cell* new_node = create_node(value);
    if (lst->tail == NULL) {
        lst->head = lst->tail = new_node;
    } else {
        new_node->prev = lst->tail;
        lst->tail->next = new_node;
        lst->tail = new_node;
    }
}

void display_list(list* lst) {
    cell* current = lst->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void delete_first(list* lst) {
    if (lst->head == NULL) return;
    cell* temp = lst->head;
    lst->head = lst->head->next;
    if (lst->head != NULL) {
        lst->head->prev = NULL;
    } else {
        lst->tail = NULL;
    }
    free(temp);
}

void delete_last(list* lst) {
    if (lst->tail == NULL) return;
    cell* temp = lst->tail;
    lst->tail = lst->tail->prev;
    if (lst->tail != NULL) {
        lst->tail->next = NULL;
    } else {
        lst->head = NULL;
    }
    free(temp);
}

void delete_by_value(list* lst, int value) {
    cell* current = lst->head;
    while (current != NULL) {
        if (current->value == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                lst->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                lst->tail = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

int main() {
    list lst = {NULL, NULL};
    add_to_beginning(&lst, 10);
    add_to_end(&lst, 20);
    add_to_beginning(&lst, 5);
    display_list(&lst);
    delete_first(&lst);
    display_list(&lst);
    delete_last(&lst);
    display_list(&lst);
    add_to_end(&lst, 30);
    delete_by_value(&lst, 20);
    display_list(&lst);
    return 0;
}