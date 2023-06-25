#include <stdbool.h>
#include "image.h"

#ifndef LIST_H
#define LIST_H

typedef struct list List;
typedef struct list_node ListNode;

/*
* Initializes an empty list
*/
List* createList();

/*
* Inserts an image at the beggiing of the list
*/
void insertList(List* list, Image* img);

/*
* Inserts an image at the end of the list
*/
void appendList(List* list, Image* img);


/*
* Remove and return the last element on the list
*/
Image* popList(List* list);

/*
* Remove a specific element of the list
*/
Image* removeList(List* list, Image* img);

/*
* Returns true/false if the list has any element on it
*/
bool is_emptyList(List* list);

/*
* Remove all the elements of the list and dealocate it
! The given list can not be used anymore after this action !
*/
void clearList(List* list);

/**PRIVATE*/
void _setFirstElementInList(List* list, ListNode* listNode);

#endif