#include <stdbool.h>
#include <stdlib.h>

#include "image.h"
#include "list.h"
#include "locality.h"

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
    ListNode* listNode = list->first;
    void* element = listNode->info;

    list->first = list->first->next;
    list->first->previous = NULL;
    
    free(listNode);
    return element;
}

void removeFromList(List* list, void* element) {
    // to be implemented
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

void printListElements(List* list) {
    for (ListNode* p = list->first; p != NULL; p = p->next) {
        if(p->type == LOCALITY) {
            Locality* locality = (Locality*) p->info;
            printf("%s", getLocalityName(locality));
        }
    }
}

void printFirstElement(List* list) {
    Image* img = (Image*) list->first->info;
    printImageContent(img);
    printf("\n\n");
}

void execute(List* list, CallbackFunction callback) {
    for (ListNode* p = list->first; p != NULL; p = p->next) {
        Locality* locality = (Locality*) p->info;
        callback(locality);
    }
}

bool isInList(List* list, void* element) {
    // to be implemented
}
