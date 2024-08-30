#pragma once
#ifndef FILE_H
#define FILE_H

#include "Head.h"
#include "List.h"


ofstream new_DB(string filename);
void remove_DB(const string& filename);
void clear(DoublyList& list);
void save_DB(const DoublyList* list, const string& filename);
void load_DB(DoublyList& list, const string& filename);

#endif