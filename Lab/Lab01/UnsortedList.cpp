#include "UnsortedList.h"

// Make list empty.
void UnsortedList::MakeEmpty() {
	m_length = 0;
}

// Get a number of records in current list.
int UnsortedList::GetLength() {
	return m_length;
}

// Check whether capacity of list is full.
bool UnsortedList::IsFull() {
	if (m_length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// Check whether capacity of list is empty.
bool UnsortedList::IsEmpty() {
	return (m_length == 0);
}

// Initialize list iterator.
void UnsortedList::ResetList() {
	m_curPointer = -1;
}

// Move list iterator to the next item in list and Get the item.
int UnsortedList::GetNextItem(ItemType& _item) {
	m_curPointer++;
	if (m_curPointer == MAXSIZE)
		return -1;

	_item = m_array[m_curPointer];
	return m_curPointer;
}

// Add a new record into list.
int UnsortedList::Add(ItemType _item) {
	if (IsFull())
		return -1;
	
    if (Get(_item))
		return 0;
	
	else {
		m_array[m_length++] = _item;
		return 1;
	}
}

// Delete existing a record.
int UnsortedList::Delete(ItemType _item) {
	if (IsEmpty())
		return -1;

	if (Get(_item) != 0) {
		for (int i = 0; i < m_length; i++) {
			if (m_array[i] == _item) {
				m_array[i] = m_array[m_length - 1];
				m_length--;
				return 1;
			}
		}
	}
	return 0;
}

// Search for same m_id and Get the _item.
int UnsortedList::Get(ItemType& _item) {
	ItemType curItem;
	ResetList();
	GetNextItem(curItem);

	while (m_curPointer < m_length && m_curPointer != -1) {
		if (_item == curItem) {
			_item = curItem;
			return 1;
		}
		GetNextItem(curItem);
	}
	return 0;
}

// Search for same Primary Key and Replace record with input same Primary Key.
int UnsortedList::Replace(ItemType _item) {
	ItemType curItem;
	ResetList();
	GetNextItem(curItem);

	for (int i = 0; i < m_length; i++) {
		if (curItem == _item) {
			m_array[i] = _item;
			return 1;
		}
		GetNextItem(curItem);
	}
	return 0; // -1 -> fail // else -> success
}