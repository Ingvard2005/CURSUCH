#pragma once
#ifndef MENU_H
#define MENU_H
#include "List.h"
#include "Head.h"
#include "File.h"

void menuNode(DoublyList* list);
void menuFile(DoublyList* list);
void menuSort(DoublyList* list);
void menuSearch(DoublyList* list);
void menuMain(DoublyList* list);

int main() 
{
    setlocale(LC_ALL, "Ru");
 
    DoublyList* list = initializeList();
    menuMain(list);
    return 0;
}

#endif