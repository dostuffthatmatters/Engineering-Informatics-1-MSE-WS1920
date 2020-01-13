/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 09
************************************************************************************/


#include <stdlib.h>
#include <stdio.h>

#include "../list.h"


/**
 * This function prints out a list.
 */
void print_list(struct list *list) {
    printf("[");
    for (struct node *node = list->head; node != 0; node = node->next) {
        printf("%d", node->value);
        if (node->next != 0) {
            printf(", ");
        }
    }
    printf("]\n");
}


/**
 * This function initialized an empty singly-
 * linked list.
 *
 * @return Pointer to the initialized list
 */
struct list *init_list() {
    struct list *list = calloc(sizeof(struct list), 1);
    return list;
}


/**
 * This function adds a new list element at
 * the end of the list.
 *
 * @param list - list to modify
 * @param value - value to append
 */
void append(struct list *list, int value) {
    // YOUR CODE HERE
}


/**
 * This function inserts a value into a given list at
 * a specific index all elements from that index on
 * get shifted backwards by one slot.
 *
 * @param list - list to modify
 * @param value - value to insert
 * @param index - index to insert at
 *
 * @return 1 if index exists and value was added to
 * the list and 0 otherwise (list index out of range)
 */
int insert(struct list *list, int value, int index) {
    // YOUR CODE HERE
    return 1;
}


/**
 * This function removes all appearances of a given
 * value from the list.
 *
 * @param list - list to modify
 * @param value - value to remove
 */
void remove_by_value(struct list *list, int value) {
    // YOUR CODE HERE
}


/**
 * This function removes the element at a specific index
 * of a given list.
 *
 * @param list - list to modify
 * @param index - index of the element to remove
 *
 * @return 1 if index exists and value was removed from
 * the list and 0 otherwise (list index out of range)
 */
int remove_by_index(struct list *list, int index) {
    // YOUR CODE HERE
    return 0;
}


/**
 * This function returns the value of the list-element at
 * a given index.
 *
 * @param list - list to analyze
 * @param index - index to look up
 *
 * @return value of element or 0 if element doesn't exist
 * (list index out of range)
 */
int get_value_at_index(struct list *list, int index) {
    // YOUR CODE HERE
    return 0;
}


/**
 * This function returns the index of the first list-
 * element with a given value.
 *
 * @param list - list to analyze
 * @param value - value to look up
 *
 * @return index of element or -1 if element doesn't exist
 */
int get_index_of_value(struct list *list, int value) {
    // YOUR CODE HERE
    return -1;
}


/**
 * This function returns the length of a list (the
 * number of elements it contains).
 *
 * @param list - list to analyze
 *
 * @return Number of elements inside the list
 */
int length(struct list *list) {
    // YOUR CODE HERE
    return 0;
}


/**
 * This function returns the sum of all element-values
 * stored inside the list.
 *
 * @param list - list to analyze
 *
 * @return Sum of all values
 */
int total(struct list *list) {
    // YOUR CODE HERE
    return 0;
}


/**
 * This function removes a whole list (including all of
 * its list-elements) and free's all allocated memory.
 *
 * @param list - list to remove
 */
void remove_list(struct list *list) {
    // YOUR CODE HERE
}

