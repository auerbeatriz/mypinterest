#include <stdbool.h>

#ifndef LIST_H
#define LIST_H

typedef struct list List;
typedef struct list_node ListNode;
typedef enum {DESCRIPTOR, IMAGE} ElementType;

/*
* Initializes an empty generic list
*/
List* createList();

/*
* Inserts an element at the beggiing of the list
* It could be of any type, as it is a generic list
*/
void insertList(List* list, void* element, ElementType type);

/*
* Inserts an element at the end of the list
* It could be of any type, as it is a generic list
*/
void appendList(List* list, void* element, ElementType type);

/*
* Remove and return the last element of the list
*/
void* popList(List* list);

/*
* Remove a specific element of the list
*/
void removeFromList(List* list, void* element);

/*
* Return if the list has any element on it
*/
bool isEmptyList(List* list);

/*
* Remove all the elements of the list and dealocate it
! The given list can not be used anymore after this action !
*/
void clearList(List* list);

/**
 * Prints all the elements of the given list
*/
void printListElements(List* list);

/**
 * ? Verifys if an element is on the list
*/
bool isInList(List* list, void* element);

void printFirstElement(List* list);

/**PRIVATE*/
void _setFirstElementInList(List* list, ListNode* listNode);
void printFirstElement(List* list);

#endif