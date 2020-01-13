/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 09
************************************************************************************/


#ifndef LIST_MAP_H
#define LIST_MAP_H

#include "list.h"

void map(struct list *list, void (*function)(struct node *));

#endif
