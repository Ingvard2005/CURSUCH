#include "Head.h"

bool isAlphaString(const string& str)
{
    for (char c : str)
    {
        if (!isalpha(c) && c != ' ' && c != '-' && c != '_')
        {
            return false;
        }
    }
    return true;
}

weapon* inputData() // ???? ??????
{
    string input;
    weapon* car = new weapon;

   

    cout << "Enter the name of the weapon: ";
    getline(cin, input);
    while (input.empty() || !isAlphaString(input))
    {
        if (input.empty())
        {
            cout << "Invalid input. Please enter a non-empty value." << endl;
        }
        else
        {
            cout << "Invalid input. Please enter only letters." << endl;
        }
        getline(cin, input);
    }
    car->name = input;

    cout << "Enter the weapon model: ";
    getline(cin, input);
    while (input.empty())
    {
        cout << "Invalid input. Please enter a non-empty value." << endl;
        getline(cin, input);
    }
    car->model = input;

    cout << "Enter the type of weapon: ";
    getline(cin, input);
    while (input.empty() || !isAlphaString(input))
    {
        if (input.empty())
        {
            cout << "Invalid input. Please enter a non-empty value." << endl;
        }
        else
        {
            cout << "Invalid input. Please enter only letters." << endl;
        }
        getline(cin, input);
    }
    car->type = input;

    cout << "Enter the user: ";
    getline(cin, input);
    while (input.empty())
    {
        cout << "Invalid input. Please enter a non-empty value." << endl;
        getline(cin, input);
    }
    car->users = input;

    cout << "Enter the fraction : ";
    getline(cin, input);
    while (input.empty() || !isAlphaString(input))
    {
        if (input.empty())
        {
            cout << "Invalid input. Please enter a non-empty value." << endl;
        }
        else
        {
            cout << "Invalid input. Please enter only letters." << endl;
        }
        getline(cin, input);
    }
    car->faction = input;

    cout << "Enter the color of the sword crystal: ";
    getline(cin, input);
    while (input.empty() || !isAlphaString(input))
    {
        if (input.empty())
        {
            cout << "Invalid input. Please enter a non-empty value." << endl;
        }
        else
        {
            cout << "Invalid input. Please enter only letters." << endl;
        }
        getline(cin, input);
    }
    car->color_Kayber_Crystal = input;

    cout << "Enter the type of light sword: ";
    getline(cin, input);
    while (input.empty() || !isAlphaString(input))
    {
        if (input.empty())
        {
            cout << "Invalid input. Please enter a non-empty value." << endl;
        }
        else
        {
            cout << "Invalid input. Please enter only letters." << endl;
        }
        getline(cin, input);
    }
    car->typeLightSword = input;

    return car;
}

void deleteData(weapon* data)  // ???????? ??????
{
    delete data;
}