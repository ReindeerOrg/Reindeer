#include "utils.h"
#include <stdio.h>
//It is a linked list
struct __ListObj{
    void* data;
    struct __ListObj* prev;
    struct __ListObj* next;
};
struct __List{
    struct __ListObj* head;
    size_t length;
};

List CreateList1(){
    List list = malloc(sizeof(struct __List));
    list->head = NULL;
    list->length = 0;
    return list;
}
List CreateList2(List list,void* (*copy)(void* data)){
    NULL_PTR_ASSERT(list);
    List new_list = CreateList1();
    struct __ListObj* current = list->head;
    if(copy == NULL){
        for(size_t i = 0; i < list->length; i++){
            ListPushBack(new_list, current->data);
            current = current->next;
        }
    }
    else{
        for(size_t i = 0; i < list->length; i++){
            ListPushBack(new_list, copy(current->data));
            current = current->next;
        }
    }
    return new_list;
}

void ListPushBack(List list,void* data){
    NULL_PTR_ASSERT(list);
    struct __ListObj* new_node = malloc(sizeof(struct __ListObj));
    new_node->data = data;
    if(list->head == NULL){
        new_node->prev = new_node;
        new_node->next = new_node;
        list->head = new_node;
    }else{
        new_node->prev = list->head->prev;
        new_node->next = list->head;
        list->head->prev->next = new_node;
        list->head->prev = new_node;
    }
    list->length += 1;
}

void* ListGet(const List list, size_t idx){
    NULL_PTR_ASSERT(list);
    INVALID_INDEX_ASSERT(idx, list->length);
    struct __ListObj* current = list->head;
    if(idx>=list->length/2){
        idx = list->length - idx - 1;
        current = current->prev;
        for(size_t i = 0; i < idx; i++){
            current = current->prev;
        }
    }
    else{
        for(size_t i = 0; i < idx; i++){
            current = current->next;
        }
    }
    return current->data;
}
void* ListSet(List list, size_t idx, void* data){
    NULL_PTR_ASSERT(list);
    INVALID_INDEX_ASSERT(idx, list->length);
    struct __ListObj* current = list->head;
    if(idx>=list->length/2){
        idx = list->length - idx - 1;
        current = current->prev;
        for(size_t i = 0; i < idx; i++){
            current = current->prev;
        }
    }
    else{
        for(size_t i = 0; i < idx; i++){
            current = current->next;
        }
    }
    void* old_data = current->data;
    current->data = data;
    return old_data;
}

void* ListPop(List list, size_t idx){
    NULL_PTR_ASSERT(list);
    INVALID_INDEX_ASSERT(idx, list->length);
    void* data;
    if(list->length == 1){
        data = list->head->data;
        free(list->head);
        list->head = NULL;
    }
    else{
        struct __ListObj* current = list->head;
        if(idx>=list->length/2){
            idx = list->length - idx - 1;
            current = current->prev;
            for(size_t i = 0; i < idx; i++){
                current = current->prev;
            }
        }
        else{
            for(size_t i = 0; i < idx; i++){
                current = current->next;
            }
        }
        data = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if(idx==0){
            list->head = current->next;
        }
        free(current);
    }
    list->length -= 1;
    return data;
}

size_t ListLength(List list){
    NULL_PTR_ASSERT(list);
    return list->length;
}
bool ListIsEmpty(List list){
    NULL_PTR_ASSERT(list);
    return list->length == 0;
}

void ListPrint(const List list, void (*print)(void* data)){
    NULL_PTR_ASSERT(list);
    struct __ListObj* current = list->head;
    if(print == NULL){
        for(size_t i = 0; i < list->length; i++){
            printf("%p ",current->data);
            current = current->next;
        }
    }
    else{
        for(size_t i = 0; i < list->length; i++){
            print(current->data);
            putchar(' ');
            current = current->next;
        }
    }
    putchar('\n');
}

void ListDestroy(List list, void (*destroy)(void* data)){
    NULL_PTR_ASSERT(list);
    struct __ListObj* current = list->head;
    if(destroy == NULL){
        for(size_t i = 0; i < list->length; i++){
            struct __ListObj* next = current->next;
            free(current);
            current = next;
        }
    }
    else{
        for(size_t i = 0; i < list->length; i++){
            struct __ListObj* next = current->next;
            destroy(current->data);
            free(current);
            current = next;
        }
    }
    free(list);
}