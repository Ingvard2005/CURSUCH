#include "List.h"
#include "Head.h"
#include "File.h"
#include "menu.h"

void menuNode(DoublyList* list)
{
    setlocale(LC_ALL, "Russian");
    int choice;
    weapon* newData;
    string input;
    string positionInput;
    do
    {
        cout << "=============== MENU ===============" << endl;
        cout << "|    1. Print elements list         |" << endl;
        cout << "|    2. Delete element for list     |" << endl;
        cout << "| 3. transpose two elements list    |" << endl;
        cout << "|         4. Delete list            |" << endl;
        cout << "|         5. Creat list             |" << endl;
        cout << "|            6. Exit                |" << endl;
        cout << "-------------------------------------" << endl;

        while (true)
        {
            cout << "Select an operation: ";
            getline(cin, input);

            if (cin.fail()) 
            { 
                cin.clear(); // ?????????? ????? ??????
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?????????? ?????????? ???? ?? ????? ??????
                system("cls");
                cout << "The wrong command. Enter a number. \n\n";
            }

            if (input.empty()) // ???????? ?? ?????? ????
            {
                cout << "Error: Enter a number from 1 to 7." << endl;
                continue;
            }


            bool isDigit = true;
            for (char c : input) // ???????? ?? ??????? ???????????? ???????? ? ??????
            {
                if (!isdigit(c))
                {
                    isDigit = false;
                    break;
                }
            }

            if (!isDigit) 
            {
                cout << "Error: Enter a number from 1 to 7." << endl;
                continue;
            }


            choice = stoi(input); // ??????? ????????????? ????????? ?????? ? ????? ?????


            if (choice < 1 || choice > 7) // ???????? ?? ???????? ????? ?? 1 ?? 7
            {
                cout << "Error: Enter a number from 1 to 7." << endl;
                continue;
            }


            break;
        }
        system("cls");

        switch (choice)
        {
        case 1:
            if (list->head == nullptr)
            {
                cout << "The list is null." << endl;
            }
            else
            {
                printList(list);
            }
            break;
        case 2:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr)
            {
                cout << "The list is null. The item cannot be deleted." << endl;
            }
            else
            {
                deleteElement(list);
            }
            break;
        case 3:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr) 
            {
                cout << "There are not enough items in the list to rearrange." << endl;
            }
            else 
            {
                int a, b;
                cout << "Enter the position of the first element to rearrange: ";
                cin >> a;
                cout << "Enter the position of the second element for the permutation: ";
                cin >> b;
                swapNodes(list, a, b);
            }
            break;
        case 4:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr)
            {
                cout << "The list is empty." << endl;
            }
            else
            {
                deleteList(list);
            }
            break;
        case 5:
            newData = inputData();
            addToFront(list, newData);
            break;
        case 6:
            break;

        default:
            cout << "Wrong choice of operation. Try again." << endl;
            break;
        }
    } while (choice != 6);
}

void menuFile(DoublyList* list)
{
    setlocale(LC_ALL, "Russian");
    string filename;
    int choice;
    string input;

    do
    {
        cout << "========== Database Menu ============" << endl;
        cout << "| 1. Create new file database date   |" << endl;
        cout << "| 2. Delete file  database date      |" << endl;
        cout << "| 3. Download data from a file       |" << endl;
        cout << "| 4. Save date in file               |" << endl;
        cout << "| 5. Clearn   database date          |" << endl;
        cout << "| 6. Exit                            |" << endl;
        cout << "-------------------------------------" << endl;
        while (true)
        {
            cout << "Select an operation: ";
            getline(cin, input);

            if (cin.fail())
            {
                cin.clear(); // ?????????? ????? ??????
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?????????? ?????????? ???? ?? ????? ??????
                system("cls");
                cout << "The wrong command. Enter a number.\n\n";
            }


            if (input.empty())  // ???????? ?? ?????? ????
            {
                cout << "Error: Enter a number from 1 to 6." << endl;
                continue;
            }
            

            bool isDigit = true; // ???????? ?? ??????? ???????????? ???????? ? ??????
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    isDigit = false;
                    break;
                }
            }

            if (!isDigit)
            {
                cout << "Error: Enter a number from 1 to 6." << endl;
                continue;
            }


            choice = stoi(input); // ??????? ????????????? ????????? ?????? ? ????? ?????


            if (choice < 1 || choice > 6)  // ???????? ?? ???????? ????? ?? 1 ?? 6
            {
                cout << "Error: Enter a number from 1 to 6." << endl;
                continue;
            }


            break;
        }
        system("cls");

        switch (choice)
        {
        case 1:
            cout << "Enter the file name : ";
            getline(cin, filename);
            new_DB(filename);
            break;
        case 2:
            cout << "Enter the file name : ";
            getline(cin, filename);
            remove_DB(filename);
            break;
        case 3:
            cout << "Enter the file name : ";
            getline(cin, filename);
            load_DB(*list, filename);
            break;
        case 4:
            cout << "Enter the file name : ";
            getline(cin, filename);
            save_DB(list, filename);
            break;
        case 5:
            clear(*list);
            break;
        case 6:
            break;
        default:
            cout << "Wrong choice of operation. Try again." << endl;
        }
    } while (choice != 6);
}

void menuSort(DoublyList* list)
{
    int choice;
    string input;

    do
    {
        cout << " ============== Sorting Menu ===============" << endl;
        cout << "| 1. Bubble sorting (ascending)             |" << endl;
        cout << "| 2. Bubble sorting(descending)             |" << endl;
        cout << "| 3. List output                            |" << endl;
        cout << "| 4. Go back to the previous menu           |" << endl;
        cout << " --------------------------------------------" << endl;
        while (true)
        {
            cout << "Select an operation: ";
            getline(cin, input);

            if (cin.fail())
            {
                cin.clear(); // ?????????? ????? ??????
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?????????? ?????????? ???? ?? ????? ??????
                system("cls");
                cout << "The wrong command. Enter a number.\n\n";
            }

            if (input.empty()) // ???????? ?? ?????? ????
            {
                cout << "Error: Enter a number from 1 to 4." << endl;
                continue;
            }

            bool isDigit = true; // ???????? ?? ??????? ???????????? ???????? ? ??????
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    isDigit = false;
                    break;
                }
            }

            if (!isDigit)
            {
                cout << "Error: Enter a number from 1 to 4." << endl;
                continue;
            }

             
            choice = stoi(input);// ??????? ????????????? ????????? ?????? ? ????? ?????

           
            if (choice < 1 || choice > 4) // ???????? ?? ???????? ????? ?? 1 ?? 4
            {
                cout << "Error: Enter a number from 1 to 4." << endl;
                continue;
            }


            break;
        }
        system("cls");
        switch (choice)
        {
        case 1:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr)
            {
                cout << "The list is empty. Sorting is not possible." << endl;
            }
            else
            {
                bubbleSort(list);
                cout << "Bubble sorting (in ascending order) is done." << endl;
            }
            break;

        case 2:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr)
            {
                cout << "The list is empty. Sorting is not possible." << endl;
            }
            else
            {
                bubbleSortDescending(list);
                cout << "Bubble sorting (in descending order) is done." << endl;
            }
            break;

        case 3:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr)
            {
                cout << "List null." << endl;
            }
            else
            {
                printList(list);
            }
            break;
        case 4:
            break;
        default:
            cout << "Wrong choice of operation. Try again." << endl;
        }
    } while (choice != 4);
}

void menuSearch(DoublyList* list)
{
    setlocale(LC_ALL, "Russian");
    int choice;
    string field, value;
    Node* result = nullptr;
    string input;

    do
    {
        cout << " ========= Search Menu ===========" << endl;
        cout << "|       1. Linear search          |" << endl;
        cout << "|       2. Output a list          |" << endl;
        cout << "| 3. Go back to the previous menu |" << endl;
        cout << "----------------------------------" << endl;
        while (true)
        {
            cout << "Select an operation: ";
            getline(cin, input);

            if (cin.fail())
            {
                cin.clear(); // ?????????? ????? ??????
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?????????? ?????????? ???? ?? ????? ??????
                system("cls");
                cout << "The wrong command. Enter a number.\n\n";
            }

            if (input.empty()) // ???????? ?? ?????? ????
            {
                cout << "Error: Enter a number from 1 to 3." << endl;
                continue;
            }

            bool isDigit = true; // ???????? ?? ??????? ???????????? ???????? ? ??????
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    isDigit = false;
                    break;
                }
            }

            if (!isDigit)
            {
                cout << "Error: Enter a number from 1 to 3." << endl;
                continue;
            }

            choice = stoi(input); // ??????? ????????????? ????????? ?????? ? ????? ?????

            if (choice < 1 || choice > 3) // ???????? ?? ???????? ????? ?? 1 ?? 3
            {
                cout << "Error: Enter a number from 1 to 3." << endl;
                continue;
            }

            break;
        }
        system("cls");
        switch (choice)
        {
        case 1:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr)
            {
                cout << "The list is empty. Search is not possible." << endl;
            }
            else
            {
                cout << "====== Selecting the search field ======" << endl;
                cout << "|          1. Search by name           |" << endl;
                cout << "|          2. Search by model          |" << endl;
                cout << "|          3. Search by type           |" << endl;
                cout << "|          4. Search by user           |" << endl;
                cout << "|          5. Search by faction        |" << endl;
                cout << "|          6. Search by sword color    |" << endl;
                cout << "|          7. Search by type of sword  |" << endl;
                cout << "|        8. Return to the search menu  |" << endl;
                cout << "----------------------------------------" << endl;
                while (true)
                {
                    cout << "Select an operation: ";
                    getline(cin, input);

                    if (cin.fail())
                    { 
                        cin.clear(); // ?????????? ????? ??????
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?????????? ?????????? ???? ?? ????? ??????
                        system("cls");
                        cout << "The wrong command. Enter a number.\n\n";
                    }

                    if (input.empty() || input.find_first_not_of(" \t") == string::npos)
                    {
                        cout << " Error: Enter a number from 1 to 8." << endl;
                        continue;
                    }

                
                    choice = stoi(input);    // ??????? ????????????? ????????? ?????? ? ????? ?????

                    
                    if (choice < 1 || choice > 8)// ???????? ?? ???????? ????? ?? 1 ?? 8
                    {
                        cout << "Error: Enter a number from 1 to 8." << endl;
                        continue;
                    }

                    break;
                }

                switch (choice)
                {
                case 1:
                    field = "name";
                    break;
                case 2:
                    field = "model";
                    break;
                case 3:
                    field = "type";
                    break;
                case 4:
                    field = "users";
                    break;
                case 5:
                    field = "faction";
                    break;
                case 6:
                    field = "color_Kayber_Crystal";
                    break;
                case 7:
                    field = "typeLightSword";
                    break; 
                case 8:
                    break;
                    system("cls");
                default:
                    cout << "Wrong choice. Try again." << endl;
                    break;
                }

                if (choice >= 1 && choice <= 8)
                {
                    cout << "Enter a value to search for: ";
                    getline(cin, value);

                    result = findLinear(list, field, value);

                    if (result != nullptr)
                    {
                        cout << "The element is found:" << endl;
                        cout << "Name of the weapon: " << result->data->name << endl;
                        cout << "The weapon model: " << result->data->model << endl;
                        cout << "Type of weapon: " << result->data->type << endl;
                        cout << "User weapons: " << result->data->users << endl;
                        cout << "Faction: " << result->data->faction << endl;
                        cout << "The color of the light sword: " << result->data->color_Kayber_Crystal << endl;
                        cout << "type Light Sword: " << result->data->typeLightSword << endl;
                    }
                    else 
                    {
                        cout << "The element was not found." << endl;
                    }
                }
            }
            break;

        case 2:
            if (list->head == nullptr || list->head->next == nullptr || list->head->next->next == nullptr) {
                cout << "list null." << endl;
            }
            else
            {
                printList(list);
            }
            break;
        case 3:
            break;
        default:
            cout << "Wrong choice of operation. Try again." << endl;
        }
    } while (choice != 3);
}

void menuMain(DoublyList* list)
{
    int choice;
    string input;

    do
    {
        cout << "=========== MAIN MENU ===========" << endl;
        cout << "| 1. List Operations Menu       |" << endl;
        cout << "|  2. File Operations Menu      |" << endl;
        cout << "|    3. List Sorting menu       |" << endl;
        cout << "|        4. Search Menu         |" << endl;
        cout << "|           5. Exit             |" << endl;
        cout << "---------------------------------" << endl;

        while (true)
        {
            cout << "Select an operation: ";
            getline(cin, input);

            if (cin.fail())
            {
                cin.clear(); // ?????????? ????? ??????
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?????????? ?????????? ???? ?? ????? ??????
                system("cls");
                cout << "The wrong command. Enter a number.\n\n";
            }

            if (input.empty()) // ???????? ?? ?????? ????
            {
                cout << "Error: Enter a number from 1 to 5." << endl;
                continue;
            }


            bool isDigit = true;
            for (char c : input) // ???????? ?? ??????? ???????????? ???????? ? ??????
            {
                if (!isdigit(c)) 
                {
                    isDigit = false;
                    break;
                }
            }

            if (!isDigit)
            {
                cout << "Error: Enter a number from 1 to 5." << endl;
                continue;
            }

            choice = stoi(input);// ??????? ????????????? ????????? ?????? ? ????? ?????


            if (choice < 1 || choice > 5) // ???????? ?? ???????? ????? ?? 1 ?? 5
            {
                cout << "Error: Enter a number from 1 to 5." << endl;
                continue;
            }

            break;
        }

        system("cls");

        switch (choice)
        {
        case 1:
            menuNode(list);
            break;
        case 2:
            menuFile(list);
            break;
        case 3:
            menuSort(list);
            break;
        case 4:
            menuSearch(list);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Wrong choice of operation. Try again." << endl;
        }

        cout << endl;
    } while (choice != 5);
}