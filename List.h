#pragma once
#ifndef LIST_H
#define LIST_H
#include "Head.h"

DoublyList* initializeList();
void printList(DoublyList* list);
void deleteElement(DoublyList* list);
void deleteList(DoublyList* list);
void swapNodes(DoublyList* list, int a, int b);
void bubbleSort(DoublyList* list);
Node* findLinear(DoublyList* list, const string& field, const string& value);
void addToFront(DoublyList* list, weapon* newData);
void bubbleSortDescending(DoublyList* list);
#endif