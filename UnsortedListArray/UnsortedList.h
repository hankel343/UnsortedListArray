#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
#include "ItemType.h"
#define DEFAULT_MAX 5

class FullList {};
class EmptyList {};

class UnsortedList
{
private:
	int m_nMaxItems;
	ItemType* pInfo;
	int m_nLength = -1;
	int m_nIndex = -1;

public:

	//Constructors:
	UnsortedList();
	UnsortedList(int nMax);

	//Destructor:
	~UnsortedList();

	//Methods:
	ItemType GetCurrentItem();
	ItemType Insert(ItemType iItem);
	ItemType Delete(ItemType iItem, bool& found);
	ItemType AdvanceCurrentItem();
	void MakeEmpty();
	bool IsFull();
	bool IsEmpty();

};

#endif UNSORTEDLIST_H