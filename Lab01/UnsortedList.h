#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
 *   Array based simple unsorted list.
 */
class UnsortedList{
private:
	ItemType	m_array[MAXSIZE];	// list array
	int			m_length;			// number of elements in list.
	int			m_curPointer;		// iterator pointer

public:
	/**
	 * @brief   default constructor.
	 */
	UnsortedList() {
		m_length = 0;
		ResetList();
	}
	
	/**
	 * @brief   default destructor
	 */
	~UnsortedList() {}
	
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
	 * @pre     list should be initialized.
	 * @post    iterator is reset.
	 */
	void ResetList();

	/**
	 * @brief   Move list iterator to the next item in list and Get the item.
	 * @pre     list and list iterator should not be initialized.
	 * @post    iterator is moved to next item.
	 * @param   _item    get current iterator's item. it does not need to be initialized.
	 * @return  index of current iterator's item if is not end of list
	 *          oterwise return -1.
	 */
	int GetNextItem(ItemType& _item);

	/**
	 * @brief   Add a new record into list.
	 * @pre     List should be initialized.
	 * @post    Added the new record into the list. and m_length++
	 * @param   _item    new Item
	 * @return  return 1 if this function works well,
	 *          oterwise return 0.
	 */
	int Add(ItemType _item);

	/**
	 * @brief   Delete existing a record.
	 * @pre     two ItemType should be initialized.
	 * @post    Delete the record into the list and m_length--.
	 * @param   _item    The record to want to delete.
	 * @return  return 1 if the item to be deleted is in the list,
	 *          oterwise return 0.
	 */
	int Delete(ItemType _item);

	/**
	 * @brief   Search for same m_id and Get the item.
	 * @pre     two ItemType should be initialized.
	 * @post    Get a record
	 * @param   _item    The record to want to find
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int Get(ItemType& _item);

	/**
	 * @brief   Search for same Primary Key and Replace record with input same Primary Key.
	 * @pre     two ItemType should be initialized.
	 * @post    none.
	 * @param   _item    replace record
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int Replace(ItemType _item);
};