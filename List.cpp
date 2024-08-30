#include "List.h"
#include "Head.h"
#include "File.h"

void addToFront(DoublyList* list, weapon* newData)
{
    Node* newNode = new Node;
    if (newNode == nullptr)
    {
        cout << "Memory allocation error. It is not possible to add a new element" << endl;
        return;
    }

    newNode->data = newData;
    newNode->prev = list->head;
    newNode->next = list->head->next;
    list->head->next->prev = newNode;
    list->head->next = newNode;

    cout << "The item has been successfully added to the top of the list." << endl;
}

DoublyList* initializeList() //???????? ??????(???????????) 
{
    DoublyList* newList = new DoublyList;
    newList->head = new Node;
    newList->tail = new Node;

    newList->head->prev = nullptr;
    newList->head->next = newList->tail;
    newList->tail->prev = newList->head;
    newList->tail->next = nullptr;

    newList->current = newList->head;

    return newList;
}

void printList(DoublyList* list) //  ????? ?????? ??????
{
    list->current = list->head->next;
    if (list->current == list->tail)
    {
        cout << "List null." << endl;
        return;
    }

    cout << "List Items:" << endl;
    cout << "-----------------------" << endl;

    while (list->current != list->tail)
    {
        cout << "Name of the weapon : " << list->current->data->name << endl;
        cout << "Model of the weapon: " << list->current->data->model << endl;
        cout << "Type of the weapon: " << list->current->data->type << endl;
        cout << "Users: " << list->current->data->users << endl;
        cout << "Faction: " << list->current->data->faction << endl;
        cout << "The color of the sword: " << list->current->data->color_Kayber_Crystal << endl;
        cout << "Type Light Sword: " << list->current->data->typeLightSword << endl;
        cout << "-----------------------" << endl;
        list->current = list->current->next;
    }
}

void deleteElement(DoublyList* list)
{
    int position;
    Node* temp = nullptr;

    printList(list); // ????? ????????? ??????

    cout << "Enter the position of the item to delete: ";
    cin >> position;
    cin.ignore(); // ??????? ?????? ?????

    list->current = list->head->next; // ????????? ???????? ???? ?? ?????? ????? ?????????? ???? head


    for (int i = 1; i < position && list->current != list->tail; i++) // ?????????? position-1 ?????????, ????? ????? ?? ??????? ????
    {
        list->current = list->current->next;
    }

    if (list->current != list->tail)
    {
        temp = list->current;
        list->current->prev->next = list->current->next;
        list->current->next->prev = list->current->prev;
        list->current = list->current->next;
        delete temp->data; // ???????????? ??????, ?????????? ??????? ????
        delete temp; // ???????????? ??????, ?????????? ?????
    }
    else
    {
        cout << "The position of the element to delete is incorrect." << endl;
    }
    list->current = list->head;
}

void deleteList(DoublyList* list) //???????? ??????
{
    Node* current = list->head->next;
    Node* temp;

    while (current != list->tail)
    {
        temp = current;
        current = current->next;
        deleteData(temp->data);  // ???????? ?????? ????
        delete temp;  // ???????? ?????? ????
    }

    list->head->next = list->tail;
    list->tail->prev = list->head;
}


void swapNodes(DoublyList* list, int a, int b) // ??????? ???????????? ?????????
{

    if (list->head == nullptr)
    {
        cout << "The list is empty or does not exist." << endl;
        return;
    }

    int listSize = 0;
    Node* temp = list->head->next;
    while (temp != list->tail)
    {
        listSize++;
        temp = temp->next;
    }

    if (a < 1 || b < 1 || a > listSize || b > listSize)
    {
        cout << "Incorrect indexes. The indexes must be in the range from 1 to " << listSize << "." << endl;
        return;
    }

    Node* nodeK = list->head; // ??? ??????????, ????? ????????, ??? ?????
    Node* nodeG = list->head;// ???? ??? ??????? ?????????? ????? ????? ???? ??????? ???? ????? ???? ?????? ?????????????

    
    //for (int i = 1; i <= a; i++)// ????? ???? ? ????????? a ? b
    //{
    //    // ??? ?? ????? nullptr
    //    nodeK = nodeK->next;//
    //}
    ////?????? ????? list->
    //for (int i = 1; i <= b; i++) //
    //{
    //    nodeG = nodeG->next;
    //}
    
    int i = 1;

    while (i <= a || i <= b)
    {
        if (i <= a)
        {
            nodeK = nodeK->next;
        }
        if (i <= b)
        {
            nodeG = nodeG->next;
        }
        i++;
    }

    weapon* tempData = nodeK->data;// ???????? ?????? ????? ??????
    nodeK->data = nodeG->data;
    nodeG->data = tempData;

    cout << "Elements with indexes" << a << " and " << b << " successfully swapped places." << endl;
}

void bubbleSort(DoublyList* list) // ?????????? ?????????
{
    string field;
    cout << "Enter the sorting field: ";
    cin >> field;
    if (list->head == nullptr)
    {
        cout << "The list is empty or does not exist." << endl;
        return;
    }

    int listSize = 0;
    Node* temp = list->head->next;
    while (temp != list->tail)
    {
        listSize++;
        temp = temp->next;
    }

    if (listSize <= 1)
    {
        cout << "The list has already been sorted." << endl;
        return;
    }

    for (int i = 0; i < listSize - 1; i++)
    {
        bool swapped = false;
        Node* current = list->head->next;

        for (int j = 0; j < listSize - i - 1; j++)
        {
            if (field == "name" && current->data->name > current->next->data->name)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "model" && current->data->model > current->next->data->model)
            {
                
                weapon* tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }

            else if (field == "type" && current->data->type > current->next->data->type)
            {
                
                weapon* tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "users" && current->data->users > current->next->data->users)
            {
                
                weapon* tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "faction" && current->data->faction > current->next->data->faction)
            {
                
                weapon* tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "color_Kayber_Crystal" && current->data->color_Kayber_Crystal > current->next->data->color_Kayber_Crystal)
            {
                
                weapon* tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }

            else if (field == "typeLightSword;" && current->data->typeLightSword > current->next->data->typeLightSword)
            {
                
                weapon* tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }


            current = current->next;
        }


        if (!swapped)
        {
            break;
        }
    }

    cout << "The list has been successfully sorted in ascending order" << field << "." << endl;
}

void bubbleSortDescending(DoublyList* list) // ?????????? ?? ????????
{
    string field;
    cout << "Enter the sorting field: ";
    cin >> field;
    if (list->head == nullptr) 
    {
        cout << "The list is empty or does not exist." << endl;
        return;
    }

    int listSize = 0;
    Node* temp = list->head->next;
    while (temp != list->tail)
    {
        listSize++;
        temp = temp->next;
    }

    if (listSize <= 1) 
    {
        cout << "The list has already been sorted." << endl;
        return;
    }

    for (int i = 0; i < listSize - 1; i++) 
    {
        bool swapped = false;
        Node* current = list->head->next;

        for (int j = 0; j < listSize - i - 1; j++)
        {
            if (field == "name" && current->data->name < current->next->data->name)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "model" && current->data->model < current->next->data->model)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "type" && current->data->type < current->next->data->type) 
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "users" && current->data->users < current->next->data->users)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "faction" && current->data->faction < current->next->data->faction)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "color_Kayber_Crystal" && current->data->color_Kayber_Crystal < current->next->data->color_Kayber_Crystal)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }
            else if (field == "typeLightSword" && current->data->typeLightSword < current->next->data->typeLightSword)
            {
                
                weapon* tempData = current->data;// ???????? ??????? ?????? ????? ??????
                current->data = current->next->data;
                current->next->data = tempData;

                swapped = true;
            }

            current = current->next;
        }

        if (!swapped) 
        {
            break;
        }
    }

    cout << "The list has been successfully sorted in descending order " << field << "." << endl;
}

Node* findLinear(DoublyList* list, const string& field, const string& value)
{
    Node* current = list->head->next; // ???????? ? ??????? ???????? ??????
    Node* result = nullptr;

    while (current != list->tail)
    {
        bool found = false;

        if (field == "name" && current->data->name == value)
        {
            found = true;
        }
        else if (field == "model" && current->data->model == value)
        {
            found = true;
        }
        else if (field == "type" && current->data->type == value)
        {
            found = true;
        }
        else if (field == "users" && current->data->users == value)
        {
            found = true;
        }
        else if (field == "faction" && current->data->faction == value)
        {
            found = true;
        }
        else if (field == "color_Kayber_Crystal" && current->data->color_Kayber_Crystal == value)
        {
            found = true;
        }
        else if (field == "typeLightSword" && current->data->typeLightSword == value)
        {
            found = true;
        }
        if (found)
        {
            result = current;
        }

        current = current->next;
    }

    if (result != nullptr)
    {
        cout << "A match was found with the element:" << endl;
        cout << "Name of the weapon: " << result->data->name << endl;
        cout << "Weapon Model: " << result->data->model << endl;
        cout << "Type of weapon: " << result->data->type << endl;
        cout << "Weapon User: " << result->data->users << endl;
        cout << "faction: " << result->data->faction << endl;
        cout << "The color of the light sword: " << result->data->color_Kayber_Crystal << endl;
        cout << "Type Light Sword: " << result->data->typeLightSword << endl;
        cout << endl;
    }

    return result;
}
