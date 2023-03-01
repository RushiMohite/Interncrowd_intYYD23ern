#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function prototypes
void createList();
void addBirthday();
void deleteBirthday();
void searchBirthday();

// Global variables
map<string, string> birthdayList;

int main()
{
    int choice;
    cout << "Welcome to Birthday List Program!" << endl;
    do {
        cout << "\nPlease choose an option:" << endl;
        cout << "1. Create a new list" << endl;
        cout << "2. Add a birthday" << endl;
        cout << "3. Delete a birthday" << endl;
        cout << "4. Search for a birthday" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                createList();
                break;
            case 2:
                addBirthday();
                break;
            case 3:
                deleteBirthday();
                break;
            case 4:
                searchBirthday();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}

void createList()
{
    cout << "Creating a new list..." << endl;
    birthdayList.clear();
    cout << "New list created." << endl;
}

void addBirthday()
{
    string name, date;
    cout << "Enter the person's name: ";
    cin >> name;
    cout << "Enter the person's birthday (MM/DD/YYYY): ";
    cin >> date;
    birthdayList.insert(pair<string, string>(name, date));
    cout << "Birthday added." << endl;
}

void deleteBirthday()
{
    string name;
    cout << "Enter the person's name to delete: ";
    cin >> name;
    if (birthdayList.count(name) == 0)
    {
        cout << "No birthday found for " << name << "." << endl;
    }
    else
    {
        birthdayList.erase(name);
        cout << "Birthday deleted." << endl;
    }
}

void searchBirthday()
{
    string name;
    cout << "Enter the person's name to search: ";
    cin >> name;
    if (birthdayList.count(name) == 0)
    {
        cout << "No birthday found for " << name << "." << endl;
    }
    else
    {
        cout << "Birthday for " << name << ": " << birthdayList[name] << endl;
    }
}
