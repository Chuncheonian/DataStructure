#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 10

// Array based simple sorted list.
class SortedList{
private:
	ItemType	m_array[MAXSIZE];		// Array
	int			m_length;				// Number of Record in list.
	int			m_curPointer;			// Iterator pointer.

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
	 * @post    Clear list.
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
	 * @brief   Move list iterator to the next item in list and get the item.
	 * @pre     List and list iterator should not be initialized.
	 * @post    Iterator is moved to next item.
	 * @param   _item    get current iterator's item. it does not need to be initialized.
	 * @return  Index of current iterator's item if is not end of list
	 * 			Oterwise return -1.
	 */
	int GetNextItem(ItemType& _item);

	/**
	 * @brief   Add a new record into sorted list.
	 * @pre     List should be initialized.
	 * @post    Added the new record into the sorted list.
	 * @param   _item    New Item
	 * @return  Return 1 if this function works well,
	 *          Return 0 if a record already exists,
	 * 			Return -1 if list is full.
	 */
	int Add(ItemType _item);

	/**
	 * @brief   Delete existing a record.
	 * @pre     Two ItemType should be initialized.
	 * @post    Delete the record into the list and m_length--.
	 * @param   _item    delete data
	 * @return  Return 1 if the item to be deleted is in the list,
	 * 			Return -1 if list is empty,
	 * 			Oterwise return 0.
	 */
	int Delete(ItemType _item);

	/**
	 * @brief   Searching for same Primary Key by Sequential search and Get the data.
	 * @pre     ItemType should be initialized.
	 * @post    Get a record.
	 * @param   _item    Get current iterator's item.
	 * @return  Return 1 if record with same Primary Key is set,
	 * 			Otherwise return 0.
	 */
	int Retrieve_SeqS(ItemType& _item);

	/**
	 * @brief   Searching for same Primary Key by Binary search and Get the data.
	 * @pre     ItemType should be initialized.
	 * @post    Get a record.
	 * @param   _item    get current iterator's item.
	 * @return  Return 1 if record with same Primary Key is set,
	 * 			Otherwise return 0.
	 */
	int Retrieve_BinS(ItemType& _item);

	/**
	 * @brief   Searching for same Primary Key and Replace record with input record.
	 * @pre     Two ItemType should be initialized.
	 * @post    None.
	 * @param   _item    Replace Record
	 * @return  Return 1 if two record are the same,
	 * 			Oterwise return 0.
	 */
	int Replace(ItemType _item);
};
