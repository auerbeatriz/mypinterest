#include <stdbool.h>

#include "image.h"
#include "list.h"

struct list {
    ListNode* first;
    ListNode* last;
};
struct list_node {
    Image* image;
    ListNode* next;
    ListNode* previous;
};

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;

    return list;
}

void insertList(List* list, Image* img) {
    ListNode* imgListNode = (ListNode*) malloc(sizeof(ListNode));

    imgListNode->previous = NULL;
    imgListNode->next = list->first;

    if(is_empty_list(list)) {
       _setFirstElementInList(list, imgListNode);
    }
    else {
        list->first->previous = imgListNode;
        list->first = imgListNode;
    }
}


void appendList(List* list, Image* img) {
    ListNode* imgListNode = (ListNode*) malloc(sizeof(ListNode));
    
    imgListNode->next = NULL;
    imgListNode->previous = list->last;
    if(is_empty_list(list)) {
        _setFirstElementInList(list, imgListNode);
    }
    else {
        list->last->next = imgListNode;
        list->last = imgListNode;
    }
}

void _setFirstElementInList(List* list, ListNode* listNode) {
    list->first = listNode;
    list->last = listNode;
}

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
