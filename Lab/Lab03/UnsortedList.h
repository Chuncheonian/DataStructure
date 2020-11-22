#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "FavoriteContent.h"
#include "Event.h"

#define MAXLIST 10

// Array based simple unsorted list.
template <class T>
class UnsortedList{
private:
	T		*m_pList;		// List array
	int		m_length;		// Number of elements in list.
	int		m_curPointer;	// Iterator pointer

public:
	// default constructor.
	UnsortedList() {
		m_length = 0;
		ResetList();
		m_pList = new T[MAXLIST];
	}

	// default destructor
	~UnsortedList() {
		delete[] m_pList;
	}
	
	/**
	 * @brief   Make list empty.
	 * @pre     None.
	 * @post    Clear list.
	 */
	void MakeEmpty();

	/**
	 * @brief   Get a number of records in current list.
	 * @pre     None.
	 * @post    None.
	 * @return  Number of record in current list.
	 */
	int GetLength();

	/**
	 * @brief   Check whether capacity of list is full.
	 * @pre     None.
	 * @post    None.
	 * @return  Return true if list capacity reached to the upper bound,
	 *          Oterwise return false.
	 */
	bool IsFull();

	/**
	 * @brief   Check whether capacity of list is empty.
	 * @pre     None.
	 * @post    None.
	 * @return  Return true if m_length == 0,
	 *          Oterwise return false.
	 */
	bool IsEmpty();

	/**
	 * @brief   Initialize list iterator.
	 * @pre     List should be initialized.
	 * @post    Iterator is reset.
	 */
	void ResetList();

	/**
	 * @brief   Move list iterator to the next item in list and Get the item.
	 * @pre     List and list iterator should not be initialized.
	 * @post    Iterator is moved to next item.
	 * @param   _item    get current iterator's item. it does not need to be initialized.
	 * @return  index of current iterator's item if is not end of list
	 *          oterwise return -1.
	 */
	int GetNextItem(T& _item);

	/**
	 * @brief   Add a new record into list.
	 * @pre     List should be initialized.
	 * @post    Added the new record into the list. and m_length++
	 * @param   _item    new item
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int Add(T _item);

	/**
	 * @brief   Delete existing a record.
	 * @pre     Two ItemType should be initialized.
	 * @post    Delete the record into the list and m_length--.
	 * @param   _item    The record to want to delete.
	 * @return  Return 1 if the item to be deleted is in the list,
	 * 			Return -1 if list is empty,
	 *          oterwise return 0.
	 */
	int Delete(T _item);

	/**
	 * @brief   Search for same variable and Get the item.
	 * @pre     Two ItemType should be initialized.
	 * @post    Get a record
	 * @param   _item    The record to want to find
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int Get(T& _item);

	/**
	 * @brief   Search for same Primary Key and Replace record with input same Primary Key.
	 * @pre     Two ItemType should be initialized.
	 * @post    None.
	 * @param   _item    Replace Record
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int Replace(T _item);
};

// Make list empty.
template <class T>
void UnsortedList<T>::MakeEmpty() {
	m_length = 0;
}

// Get a number of records in current list.
template <class T>
int UnsortedList<T>::GetLength() {
	return m_length;
}

// Check whether capacity of list is full.
template <class T>
bool UnsortedList<T>::IsFull() {
	if (m_length > MAXLIST - 1)
		return true;
	else
		return false;
}

// Check whether capacity of list is empty.
template <class T>
bool UnsortedList<T>::IsEmpty() {
	return (m_length == 0);
}

// Initialize list iterator.
template <class T>
void UnsortedList<T>::ResetList() {
	m_curPointer = -1;
}

// Move list iterator to the next item in list and Get the item.
template <class T>
int UnsortedList<T>::GetNextItem(T& _item) {
	m_curPointer++;
	if (m_curPointer == m_length)
		return -1;

	_item = m_pList[m_curPointer];
	return m_curPointer;
}

// Add a new record into list.
template <class T>
int UnsortedList<T>::Add(T _item) {
	if (IsFull())
		return -1;

	if (Get(_item))
		return 0;
	else {
		m_pList[m_length] = _item;
		m_length++;
		return 1;
	}
}

// Delete existing a record.
template <class T>
int UnsortedList<T>::Delete(T _item) {
	if (IsEmpty())
		return -1;

	if (Get(_item)) {
		for (int i = 0; i < m_length; i++) {
			if (m_pList[i] == _item) {
				m_pList[i] = m_pList[m_length - 1];
				m_length--;
				return 1;
			}
		}
	}
	return 0;
}

// Search for same variable and Get the item.
template <class T>
int UnsortedList<T>::Get(T& _item) {
	T curItem;
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
template <class T>
int UnsortedList<T>::Replace(T _item) {
	T curItem;
	ResetList();
	GetNextItem(curItem);

	for (int i = 0; i < m_length; i++) {
		if (curItem == _item) {
			m_pList[i] = _item;
			return 1;
		}
		GetNextItem(curItem);
	}
	return 0;
}