
#include <stdlib.h>
#include <stdio.h>

#include "../list.h"


// Not required - just as a recursion example
void remove_list_recursively(struct list *list);
void remove_node_recursively(struct node *node);


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
 * This function removes a whole list (including all of
 * its list-elements) and free's all allocated memory.
 *
 * @param list - list to remove
 */
void remove_list(struct list *list) {
    while (list->head != 0) {
        struct node *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }

    free(list);
}


// --------------------------------------------------------------------------------------------------------------------

/**
 * Does exactly the same as 'remove_list'
 * but uses recursion
 *
 * @param list - list to remove
 */
void remove_list_recursively(struct list *list) {
    if (list->head != 0) {
        remove_node_recursively(list->head);
    }
    free(list);
}

void remove_node_recursively(struct node *node) {
    if (node->next != 0) {
        remove_node_recursively(node->next);
    }
    free(node);
}

// --------------------------------------------------------------------------------------------------------------------


/**
 * This function adds a new list element at
 * the end of the list.
 *
 * @param list - list to modify
 * @param value - value to append
 */
void append(struct list *list, int value) {
    struct node *node = calloc(sizeof(struct node), 1);
    node->value = value;

    if (list->head == 0) {
        list->head = node;
    } else {
        struct node *tail = list->head;
        while (tail->next != 0) {
            tail = tail->next;
        }
        tail->next = node;
    }
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
    struct node *node = calloc(sizeof(struct node), 1);
    node->value = value;
    if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        struct node *node_to_append_to = list->head;
        if (node_to_append_to == 0) {
            return 0;
        }

        for (int i=1; i<index; i++) {
            node_to_append_to = node_to_append_to->next;
            if (node_to_append_to == 0) {
                return 0;
            }
        }

        node->next = node_to_append_to->next;
        node_to_append_to->next = node;
    }

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

    // Removing all nodes from the beginning of the
    // list that contain this value until the list is
    // either empty or a node with some other value is
    // at the head
    while (list->head != 0) {
        if (list->head->value == value) {
            struct node *tmp = list->head;
            list->head = list->head->next;
            free(tmp);
        } else {
            break;
        }
    }

    for (struct node *node = list->head; node->next != 0;) {
        if (node->next->value == value) {
            struct node *tmp = node->next;
            node->next = node->next->next;
            free(tmp);
        } else {
            node = node->next;
        }
    }
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
    if (list->head == 0) {
        return 0;
    }

    if (index == 0) {
        struct node *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        return 1;
    } else {
        struct node *node = list->head;
        for (int i=1; i<index; i++) {
            if (node->next == 0) {
                return 0;
            } else {
                node = node->next;
            }
        }
        struct node *tmp = node->next;
        node->next = node->next->next;
        free(tmp);
        return 1;
    }
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

    // If you want to support negative indexing (element
    // at index -1 is the last element, index -2 is the
    // second to last element, ...) you should use a doubly
    // linked list.
    if ((list->head == 0) || (index < 0)) {
        return 0;
    }

    if (index == 0) {
        return list->head->value;
    } else {
        struct node *node = list->head;
        for (int i=0; i<index; i++) {
            if (node->next == 0) {
                return 0;
            } else {
                node = node->next;
            }
        }
        return node->value;
    }
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
    int index = 0;
    for (struct node *node = list->head; node != 0; node = node->next) {
        if (node->value == value) {
            return index;
        } else {
            index++;
        }
    }

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
    int running_length = 0;

    struct node *tail = list->head;

    while (tail != 0) {
        running_length++;
        tail = tail->next;
    }

    return running_length;
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
    int running_total = 0;
    struct node *tail = list->head;

    while (tail != 0) {
        running_total += tail->value;
        tail = tail->next;
    }

    return running_total;
}
