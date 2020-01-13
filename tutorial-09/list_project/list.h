/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 09
************************************************************************************/


#ifndef LIST_H
#define LIST_H

struct list {
    struct node *head;
};

struct node {
    int value;
    struct node *next;
};

void print_list(struct list *list);

struct list *init_list();
void remove_list(struct list *list);

void append(struct list *list, int value);
int insert(struct list *list, int value, int index);

void remove_by_value(struct list *list, int value);
int remove_by_index(struct list *list, int index);

int get_value_at_index(struct list *list, int index);
int get_index_of_value(struct list *list, int value);

int length(struct list *list);
int total(struct list *list);

#endif
