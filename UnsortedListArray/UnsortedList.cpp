#include "UnsortedList.h"

UnsortedList::UnsortedList()
{
	m_nMaxItems = DEFAULT_MAX;
	pInfo = new ItemType[DEFAULT_MAX];
}

UnsortedList::UnsortedList(int nMax)
{
	m_nMaxItems = nMax;
	pInfo = new ItemType[nMax];
}

bool UnsortedList::IsFull()
{
	return (m_nLength == m_nMaxItems - 1);
}

bool UnsortedList::IsEmpty()
{
	return (m_nLength == -1);
}

ItemType UnsortedList::Insert(ItemType iItem)
{
	if (IsFull() == true)
		throw FullList();
	else
	{
		m_nLength++;
		m_nIndex++;
		pInfo[m_nIndex] = iItem;
		return pInfo[m_nIndex];
	}
}

ItemType UnsortedList::Delete(ItemType item, bool& found)
{
	found = false;

	for (int i = 0; i < m_nMaxItems; i++)
	{
		if (pInfo[i].ComparedTo(item) == EQUAL)
		{
			found = true;
			m_nLength--;
			ItemType iTemp = pInfo[i];
			for (int j = i; j < m_nMaxItems; j++) //Stops one before last element
			{
				pInfo[j] = pInfo[j + 1]; //Shift all array elements down by one.
			}
			return iTemp;
		}
	}

	return item; //If item to delete is not found in the list.
}

ItemType UnsortedList::GetCurrentItem()
{
	if (IsEmpty() == true)
		throw EmptyList();
	else
		return pInfo[m_nIndex];
}

ItemType UnsortedList::AdvanceCurrentItem()
{
	if (IsEmpty() == true)
		throw EmptyList();

	if (m_nIndex >= m_nLength) {
		m_nIndex = 0;
	} else {
		m_nIndex++;
	}

	return pInfo[m_nIndex];
		
}

void UnsortedList::MakeEmpty()
{
	m_nLength = -1;
	m_nIndex = -1;
}

UnsortedList::~UnsortedList()
{
	delete[] pInfo;
}

