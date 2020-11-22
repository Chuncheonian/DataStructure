#include "SortedList.h"

// Make list empty.
void SortedList::MakeEmpty() {
	m_length = 0;
}

// Get a number of records in current list.
int SortedList::GetLength() const {
	return m_length;
}

// Check capacity of list is full
bool SortedList::IsFull() const {
	if (m_length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// Initialize list iterator.
void SortedList::ResetList() {
	m_curPointer = -1;
}

// Move list iterator to the next item in list and Get the item.
int SortedList::GetNextItem(ItemType& _item) {
	m_curPointer++;
	if (m_curPointer == m_length)
		return -1;

	_item = m_array[m_curPointer];
	return m_curPointer;
}

// Add a new record into sorted list.
int SortedList::Add(ItemType _item) {
	if (IsFull())
		return -1;

	if (m_length == 0) {
		m_array[m_length] = _item;
		m_length++;
		return 1;
	}

	else {
		for (int i = 0; i < m_length; i++)  {
			if (m_array[i] < _item) {   // new PK is larger that existed PK in list
				if (i == m_length - 1) {   // new PK is the largest that existed PK in list 
					m_array[m_length] = _item;
					m_length++;
					return 1;
				}
			}

			else if (m_array[i] > _item) {  // new PK is smaller that existed PK in list
				for (int j = m_length; j > i; j--)
					m_array[j] = m_array[j - 1];
				m_array[i] = _item;
				m_length++;
				return 1;
			}

			else    // Record with same PK already exists.
				return 0;
		}
	}
	return -1;
}

// Delete existing a record.
int SortedList::Delete(ItemType _item) {
	if (m_length == 0)
		return -1;

	if (Retrieve_SeqS(_item)) {     // target record is set
		for (int i = m_curPointer; i < m_length; i++)
			m_array[i] = m_array[i + 1];
		m_length--;
		return 1;
	}
	return 0;
}

// Searching for same PK by Sequential search and Get the data.
int SortedList::Retrieve_SeqS(ItemType& _item) {
	ItemType item;
	ResetList();
	GetNextItem(item);
	
	while (m_curPointer < m_length && m_curPointer != -1) {
		if (_item == item) {    // find
			_item = item;
			return 1;
		}
		GetNextItem(item);
	}
	return 0;  // record isn't in list.
}

// Searching for same PK by Binary search and Get the data.
int SortedList::Retrieve_BinS(ItemType& _item) {
	int first = 0;
	int last = m_length - 1;
	bool found = false;

	while (first <= last && !found) {
		int mid = (first + last) / 2;

		if (_item < m_array[mid])
			last = mid - 1;

		else if (_item > m_array[mid])
			first = mid + 1;

		else {
			_item = m_array[mid];
			found = true;
			return 1;
		}
	}
	return 0;
}

// Searching for same record and Replace record with input record.
int SortedList::Replace(ItemType _item) {
	ItemType item;
	ResetList();
	GetNextItem(item);

	for (int i = 0; i < m_length; i++) {
		if (item == _item) {
			m_array[i] = _item;
			return 1;
		}
		GetNextItem(item);
	}
	return 0;
}