#pragma once
#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "StudentType.h"

#define MAXLIST 10

// array based simple sorted list.
template <class T>
class SortedList{
private:
	T			m_array[MAXLIST];		// Array
	int			m_length;				// number of Record in list.
	int			m_curPointer;			// iterator pointer.

public:
	// default constructor
	SortedList() {
		m_length = 0;
		ResetList();
	}

	// default destrctor.
	~SortedList() {}

	/**
	 * @brief   Make list empty.
	 * @pre     None.
	 * @post    clear list.
	 */
	void MakeEmpty();

	/**
	 * @brief   Get a number of records in current list.
	 * @pre     None.
	 * @post    None.
	 * @return  Number of record in current list.
	 */
	int GetLength() const;

	/**
	 * @brief   Check capacity of list is full
	 * @pre     None.
	 * @post    None.
	 * @return  Return true if list capacity reached to the upper bound,
	 * 			Oterwise return false.
	 */
	bool IsFull() const;

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
	 * @param   _item    Get current iterator's item. It does not need to be initialized.
	 * @return  Index of current iterator's item if is not end of list
	 * 			Oterwise return -1.
	 */
	int GetNextItem(T& _item);

	/**
	 * @brief   Add a new record into sorted list.
	 * @pre     List should be initialized.
	 * @post    Added the new record into the sorted list.
	 * @param   _item    New Item
	 * @return  Return 1 if this function works well,
	 *          Return 0 if a record already exists,
	 * 			Return -1 if list is full.
	 */
	int Add(T _item);

	/**
	 * @brief   Delete existing a record.
	 * @pre     Two T should be initialized.
	 * @post    Delete the record into the list and m_length--.
	 * @param   _item    Delete Item.
	 * @return  Return 1 if the item to be deleted is in the list,
	 * 			Return -1 if list is empty,
	 * 			Oterwise return 0.
	 */
	int Delete(T _item);

	/**
	 * @brief   Searching for same Primary Key by Sequential search and Get the data.
	 * @pre     ItemType should be initialized.
	 * @post    Get a record.
	 * @param   _item    Get current iterator's item.
	 * @return  Return 1 if record with same Primary Key is set,
	 * 			Otherwise return 0.
	 */
	int Retrieve_SeqS(T& _item);

	/**
	 * @brief   Searching for same Primary Key by Binary search and Get the data.
	 * @pre     ItemType should be initialized.
	 * @post    Get a record.
	 * @param   _item    Get current iterator's item.
	 * @return  Return 1 if record with same Primary Key is set,
	 * 			Otherwise return 0.
	 */
	int Retrieve_BinS(T& _item);

	/**
	 * @brief   Searching for same record and replace record with input record.
	 * @pre     Two ItemType should be initialized.
	 * @post    None.
	 * @param   _item    Replace Record.
	 * @return  Return 1 if two record are the same,
	 * 			Oterwise return 0.
	 */
	int Replace(T _item);
};

// Make list empty.
template <class T>
void SortedList<T>::MakeEmpty() {
    m_length = 0;
}

// Get a number of records in current list.
template <class T>
int SortedList<T>::GetLength() const {
    return m_length;
}

// Check capacity of list is full
template <class T>
bool SortedList<T>::IsFull() const {
    if (m_length > MAXLIST - 1)
		return true;
	else
		return false;
}

// Initialize list iterator.
template <class T>
void SortedList<T>::ResetList() {
    m_curPointer = -1;
}

// Move list iterator to the next item in list and Get the item.
template <class T>
int SortedList<T>::GetNextItem(T& _item) {
    m_curPointer++;
    if (m_curPointer == m_length)
        return -1;
    
	_item = m_array[m_curPointer];
    return m_curPointer;
}

// Add a new record into sorted list.
template <class T>
int SortedList<T>::Add(T _item) {
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
template <class T>
int SortedList<T>::Delete(T _item) {
    if (m_length == 0)
        return -1;

    if (Retrieve_SeqS(_item) != 0) {     // target record is set
        for (int i = m_curPointer; i < m_length; i++)
            m_array[i] = m_array[i + 1];
        m_length--;
        return 1;
    }
    return 0;
}

// Searching for same PK by Sequential search and Get the data.
template <class T>
int SortedList<T>::Retrieve_SeqS(T& _item) {
	StudentType curItem;
    ResetList();
    GetNextItem(curItem);
    
    while (m_curPointer < m_length && m_curPointer != -1) {
        if (_item == curItem) {    // find
            _item = curItem;
            return 1;
        }
        GetNextItem(curItem);
    }
    return 0;  // record isn't in list.
}

// Searching for same PK by Binary search and Get the data.
template <class T>
int SortedList<T>::Retrieve_BinS(T& _item) {
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

// Searching for same record and replace record with input record.
template <class T>
int SortedList<T>::Replace(T _item) {
	StudentType item;
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