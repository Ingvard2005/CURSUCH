#pragma once
#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <string>
#include <fstream>
#include <fstream>
#include <iomanip>

using namespace std;

struct weapon
{
    string name;
    string model;
    string type;
    string users;
    string faction;
    string color_Kayber_Crystal;
    string typeLightSword;
};

struct Node //  ??????????? ???? ???????????? ??????
{
    weapon* data;
    Node* prev;
    Node* next;
};

struct DoublyList // ????????? 2? ???????? ??????
{
    Node* head;
    Node* tail;
    Node* current;
};

weapon* inputData();
void deleteData(weapon* data);
bool isAlphaString(const string& str);

#endif