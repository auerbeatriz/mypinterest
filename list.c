#include <stdbool.h>
#include <stdlib.h>

#include "list.h"
#include "image.h"
#include "descriptor.h"

struct list {
    ListNode* first;
    ListNode* last;
};
struct list_node {
    void* info;
    ElementType type;
    ListNode* next;
    ListNode* previous;
};

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;

    return list;
}

void insertList(List* list, void* element, ElementType type) {
    ListNode* listNode = (ListNode*) malloc(sizeof(ListNode));
    
    listNode->type = type;
    listNode->info = element;

    listNode->next = list->first;
    listNode->previous = NULL;
    
    if(!isEmptyList(list))
        list->first->previous = listNode;
    else
        list->last = listNode; 
    
    list->first = listNode;
}

void appendList(List* list, void* element, ElementType type) {
    ListNode* listNode = (ListNode*) malloc(sizeof(ListNode));
    
    listNode->type = type;
    listNode->info = element;

    listNode->next = NULL;
    listNode->previous = list->last;
    
    if(!isEmptyList(list))
        list->last->next = listNode;
    else
        list->first = listNode; 
    
    list->last = listNode;
}

void* popList(List* list) {
    ListNode* listNode = list->last;
    void* element = listNode->info;

    list->last = list->last->previous;
    list->last->next = NULL;
    
    free(listNode);
    return element;
}


bool isEmptyList(List* list) {
    return (list->first == NULL);
}

void clearList(List* list) {
    ListNode *p = list->first;
    while (p != NULL) {
        ListNode *t = p->next;
        free(p);
        p = t;
    }
    free(list);
}

void printFirstElement(List* list) {
    ListNode* firstElement = list->first;
    if(firstElement->type == IMAGE) {
        Image* img = (Image*) list->first->info;
        printImageContent(img);
        printf("\n\n");
    }

    if(firstElement->type == DESCRIPTOR) {
        Descriptor* descriptor = firstElement->info;
        printhistogram(descriptor);
        printf("\n\n");
    }
}

void removeFromList(List* list, void* element) {
    // to be implemented
}

bool isInList(List* list, void* element) {
    // to be implemented
}
