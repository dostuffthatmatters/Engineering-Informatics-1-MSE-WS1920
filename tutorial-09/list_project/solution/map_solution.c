/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 09
************************************************************************************/


#include "../map.h"

void map(struct list *list, void (*function)(struct node *)) {
    struct node *node = list->head;

    while(node != 0) {
        function(node);
        node = node->next;
    }
}
