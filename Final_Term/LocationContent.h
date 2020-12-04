#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "SortedList.h"
#include "SortedSinglyLinkedList.h"
#include "BinarySearchTree.h"

/**
 * Location information class.
 */
class LocationContent{
protected:
	string						    m_location;		    // Location Name (Primary KEY)
	int					    		m_numOfCreateTime;	// Number of CreateTime with same location name.
	SortedSinglyLinkedList<string>	m_createTimeList;	// createTime(Primary Key of MC) List with same location.
public:
	/**
	 * default constructor.
	 */
	LocationContent() {
		m_location = "";
		m_numOfCreateTime = 0;
	}

	/**
	 * default destructor.
	 */
	~LocationContent()	{

	}

	/**
	 * @brief	Get location name.
	 * @pre	    Location name is set.
	 * @post	None.
	 * @return	Location name.
	 */
	string GetName() { return m_location; }

	/**
	 * @brief	Get number of CreateTime.
	 * @pre	    Number of CreateTime.
	 * @post	None.
	 * @return	Number of CreateTime.
	 */
	int GetCount() { return m_numOfCreateTime; }

	/**
	 * @brief	Set location name.
	 * @pre	    None.
	 * @post	Location name is set.
	 * @param	_location	Location name.
	 */
	void SetName(string _location) { m_location = _location; }

	/**
	 * @brief	Set number of CreateTime.
	 * @pre	    None.
	 * @post	Number of CreateTime.
	 * @param	_numOfCreateTime	Number of CreateTime.
	 */
	void SetCount(int _numOfCreateTime) { m_numOfCreateTime = _numOfCreateTime; }
	
	/**
	 * @brief	Set location record.
	 * @pre	    None.
	 * @post	Location record is set.
	 * @param	_location			location name.
	 * @param	_numOfCreateTime	Number of CreateTime.
	 */
	void SetRecord(string _location, int _numOfCreateTime) {
		SetName(_location);
		SetCount(_numOfCreateTime);
	}

	/**
	 * @brief	Display location name on screen.
	 * @pre	    Location name is set.
	 * @post	Location name is on screen.
	 */
	void DisplayNameOnScreen() { cout << "\tName : " << m_location; }
	
	/**
	 * @brief	Display number of CreateTime.
	 * @pre	    Number of CreateTime is set.
	 * @post	Number of CreateTime is on screen.
	 */
	void DisplayCountOnScreen() { cout << "\tNumber of CreateTime with same location : " << m_numOfCreateTime; }

	/**
	 * @brief	Display an location record on screen.
	 * @pre	    Location record is set.
	 * @post	Location record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayCountOnScreen();
		DisplayAllCreateTime();
		cout << endl;
	}

	/**
	 * @brief	Set location name from keyboard.
	 * @pre	    None.
	 * @post	Location name is set.
	 */
	void SetNameFromKB();
	
	/**
	 * @brief	Set number of CreateTime.
	 * @pre	    None.
	 * @post	Number of CreateTime.
	 */
	void SetCountFromKB();
	
	/**
	 * @brief	Set location record from keyboard.
	 * @pre	    None.
	 * @post	location record is set.
	 */
	void SetRecordFromKB();
	
	/**
	 * @brief	Add new CreateTime into list.
	 * @pre     List should be initialized.
	 * @post	New record is added into the list and Number of CreateTime increases by one.
	 */
	void AddCreateTime(string _createTime);

	/**
	 * @brief	Delete CreateTime into list.
	 * @pre		List should be not empty.
	 * @post	Record is deleted into the list. and Number of CreateTime decreases by one.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int DeleteCreateTime(string _createTime);

	/**
	 * @brief	Display all elements in the CreateTime List on screen.
	 * @pre     None.
	 * @post	None.
	 */
	void DisplayAllCreateTime();

	/**
	 * @brief	Bring masterlist as pass by reference and Display detail MultimediaContent records.
	 * @pre		Exist location name.
	 * @post	None.
	 */
	void SearchAtMasterList(BinarySearchTree<MultimediaContent>& _masterList);

	/**
	 * @brief	Compare two LocationContent by location name.
	 * @pre	    Two LocationContent should be initialized.
	 * @param	_location	target location for comparing.
	 * @return	return 1 if this.location > data.location, 0 if not.
	 */
	bool operator>(LocationContent& _location);

	/**
	 * @brief	Compare two LocationContent by location name.
	 * @pre	    Two LocationContent should be initialized.
	 * @param	_location	target location for comparing.
	 * @return	return 1 if this.location < data.location, 0 if not.
	 */
	bool operator<(LocationContent& _location);

	/**
	 * @brief	Compare two LocationContent by location name.
	 * @pre	    Two LocationContent should be initialized.
	 * @param	_location	target location for comparing.
	 * @return	return 1 if this.location == data.location, 0 if not.
	 */
	bool operator==(LocationContent& _location);

	/**
	 * @brief	Print record.
	 * @pre		LocationContent class should be initialized.
	 * @post	content record is on screen.
     * @param	cout	ostream instance
	 * @param	_event	target LocationContent for printing.
	 */
	friend ostream& operator<<(ostream& cout, LocationContent& _location) {
		cout << "\t[ Location name: " << _location.m_location;
		cout << ", Number of CreateTime with same character: " << _location.m_numOfCreateTime;
		cout << ", ";
		_location.DisplayAllCreateTime();
		cout << "]";

		return cout;
	}
};