#include <iostream>
#include "UnsortedList.h"

using namespace std;

void Menu(UnsortedList& ListObj);
void ProcessInput(UnsortedList& ListObj, char cSelection);
void InsertCase(UnsortedList& ListObj, char cSelection);
void DeleteCase(UnsortedList& ListObj, char cSelection);

int main()
{
	
	char cConstructorPrompt;
	cout << "Would you like to specify the length of your list? Y/N\n";
	cout << "If no, then the default size of 5 will be used.\n";
	cout << "Enter your selection: ";
	cin >> cConstructorPrompt;

	if (toupper(cConstructorPrompt) == 'Y')
	{
		int nListLength = 0;
		cout << "Enter the desired size of your list: ";
		cin >> nListLength;
		UnsortedList ParameterizedList(nListLength);
		Menu(ParameterizedList);
	} else {
		UnsortedList UnparameterizedList;
		Menu(UnparameterizedList);
	}

	cout << "Goodbye...\n";

	return 0;
}

void Menu(UnsortedList& ListObj)
{
	char cSelection;
	do
	{
		cout << "Enter your selection from the menu below to perform operations on the list or press Q to quit.\n\n";
		cout << "1 - Insert an item to the list.\n";
		cout << "2 - Delete an item from the list.\n";
		cout << "3 - Make the list empty.\n";
		cout << "4 - Advance the current item.\n";
		cout << "5 - Get the current item.\n";
		cout << "Q - Quit.\n";
		cout << "Selection: ";
		cin >> cSelection;

		system("cls");

		ProcessInput(ListObj, cSelection);

	} while (toupper(cSelection) != 'Q');
}

void ProcessInput(UnsortedList& ListObj, char cSelection)
{
	switch (toupper(cSelection))
	{
	case '1':
		InsertCase(ListObj, cSelection);
		break;

	case '2':
		DeleteCase(ListObj, cSelection);
		break;

	case '3':
		ListObj.MakeEmpty();
		cout << "The list has been made empty.\n\n";
		break;
		
	case '4':
		try
		{
			cout << "The current item has been advanced and " << ListObj.AdvanceCurrentItem().Get() << " is now the current item.\n\n";
		}
		catch (EmptyList)
		{
			cerr << "Exception caught: The list is currently empty.\n\n";
		}
		
		break;

	case '5':
		try
		{
			cout << ListObj.GetCurrentItem().Get() << " is the current item.\n\n";
		}
		catch (EmptyList)
		{
			cerr << "Exception caught: The list is currently empty.\n";
		}
		
		break;

	case 'Q':
		break;

	default:
		cout << "Unknown input - please try again.\n";
		break;

	}
}

void InsertCase(UnsortedList& ListObj, char cSelection)
{
	int nNewData = 0;
	ItemType iNewItem;
	cout << "Enter the item that you would like to add to the list.\n";
	cout << "Item: ";
	while (!(cin >> nNewData))
	{
		cin.ignore(100, '\n');
		cin.clear();
		cout << "You have entered invalid data - your input should be an integer.\n";
	}
	iNewItem.Set(nNewData);

	try
	{
		cout << ListObj.Insert(iNewItem).Get() << " has been added to the list.\n\n";
	}
	catch (FullList)
	{
		cerr << "Exception caught: The list is currently full.\n";
	}
}

void DeleteCase(UnsortedList& ListObj, char cSelection)
{
	int nNewData = 0;
	ItemType iItemToDelete;
	bool found;
	cout << "Enter the data that you would like to delete from the list.\n";
	cout << "Data: ";
	while (!(cin >> nNewData))
	{
		cin.ignore(100, '\n');
		cin.clear();
		cout << "You have entered invalid data - Your input should be an integer.\n";
	}
	iItemToDelete.Set(nNewData);

	try
	{
		ListObj.Delete(iItemToDelete, found);
	}
	catch (EmptyList)
	{
		cerr << "Exception caught: The list is currently empty.\n\n";
	}
	

	if (found == true) {
		cout << iItemToDelete.Get() << " has been deleted from the list.\n\n";
	} else {
		cout << iItemToDelete.Get() << " was not found in the list.\n\n";
	}
}