#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "SortedList.h"
#include "SortedSinglyLinkedList.h"
#include "SortedDoublyLinkedList.h"

/**
 * Event information class.
 */
class EventContent {
private:
	string						m_name;					// Event name (Primary Key)
	string						m_description;			// Event description
	int							m_numOfCreateTime;		// Number of CreateTime with same event name.
	SortedSinglyLinkedList<string>	m_createTimeList;		// CreateTime(Primary Key of MC) List with same event.

public:
	// default constructor.
	EventContent() {
		m_name = "";
		m_description = "";
		m_numOfCreateTime = 0;
	}

	// default destructor.
	~EventContent() {}

	/**
	 * @brief	Get event name.
	 * @pre	    event name is set.
	 * @post	None.
	 * @return  event name.
	 */
	string GetName() const { return m_name; }

	/**
	 * @brief	Get event description.
	 * @pre	    event description is set.
	 * @post	None.
	 * @return  event description.
	 */
	string GetDescription() const { return m_description; }

	/**
	 * @brief	Get number of CreateTime.
	 * @pre	    Number of CreateTime.
	 * @post	None.
	 * @return	Number of CreateTime.
	 */
	int GetCount() const { return m_numOfCreateTime; }

	/**
	 * @brief	Set event name.
	 * @pre		None.
	 * @post	event name is set.
	 * @param	_name	event name.
	 */
	void SetName(string _name) { m_name = _name; }

	/**
	 * @brief	Set event description
	 * @pre		none.
	 * @post	event description is set.
	 * @param	_description	event description
	 */
	void SetDescription(string _description) { m_description = _description; }

	/**
	 * @brief	Set number of CreateTime.
	 * @pre	    None.
	 * @post	Number of CreateTime.
	 * @param	_numOfCreateTime	Number of CreateTime.
	 */
	void SetCount(int _numOfCreateTime) { m_numOfCreateTime = _numOfCreateTime; }

	/**
	 * @brief	Set Event record.
	 * @pre		None.
	 * @post	Event record is set.
	 * @param	_name				Event name.
	 * @param	_description		Event description.
	 */ 
	void SetRecord(string _name, string _description) {
		SetName(_name);
		SetDescription(_description);
	}

	/**
	 * @brief	Display event name on screen.
	 * @pre		Event name is set.
	 * @post	Event name is on screen.
	 */ 
	void DisplayNameOnscreen() { cout << "\tEvent Name: " << m_name; }

	/**
	 * @brief	Display event description on screen
	 * @pre     Event description is set
	 * @post	Event description is on screen
	 */
	void DisplayDescriptionOnscreen() { cout << "\tEvent Description: " << m_description; }

	/**
	 * @brief	Display number of CreateTime.
	 * @pre	    Number of CreateTime is set.
	 * @post	Number of CreateTime is on screen.
	 */
	void DisplayCountOnScreen() { cout << "\tNumber of CreateTime with same event : " << m_numOfCreateTime; }

	/**
	 * @brief	Display a Event record on screen.
	 * @pre 	Event record is set.
	 * @post	Event record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnscreen();
		DisplayDescriptionOnscreen();
		DisplayCountOnScreen();
		DisplayAllCreateTime();
		cout << endl;
	}

	/**
	 * @brief	Set event name from keyboard.
	 * @pre 	None.
	 * @post	Event name is set.
	 */  
	void SetNameFromKB();

 	/**
	  * @brief	Set event description from keyboard.
	  * @pre	None.
	  * @post	Event description is set.
	  */ 
	void SetDescriptionFromKB();

	/**
	 * @brief	Set number of CreateTime.
	 * @pre	    None.
	 * @post	Number of CreateTime is set.
	 */	
	void SetCountFromKB();

	/**
	 * @brief	Set Event record from keyboard.
	 * @pre 	None.
	 * @post	Eontent record is set.
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
	 * @post	Record is deleted into the list. and Number of CreateTime ddecreases by one.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int DeleteCreateTime(string _createTime);

	/**
	 * @brief	Display all elements in the createTime List on screen.
	 * @pre     None.
	 * @post	None.
	 */
	void DisplayAllCreateTime();

	/**
	 * @brief	Bring masterlist as pass by reference and Display detail MultimediaContent records.
	 * @pre		Exist event name.
	 * @post	None.
	 */
	void SearchAtMasterList(SortedDoublyLinkedList<MultimediaContent>& _masterList);

	/**
	 * @brief	Compare two EventContent by event name.
	 * @pre	    Two EventContent should be initialized.
	 * @param	_event	target event for comparing.
	 * @return	return 1 if this.m_name > data.m_name, 0 if not.
	 */
	bool operator>(EventContent& _event);

	/**
	 * @brief	Compare two EventContent by event name.
	 * @pre	    Two EventContent should be initialized.
	 * @param	_event	target event for comparing.
	 * @return	return 1 if this.m_name < data.m_name, 0 if not.
	 */
	bool operator<(EventContent& _event);

	/**
	 * @brief	Compare two EventContent by event name.
	 * @pre	    Two EventContent should be initialized.
	 * @param	_event	target event for comparing.
	 * @return	return 1 if this.m_name == data.m_name, 0 if not.
	 */
	bool operator==(const EventContent& _event);

	/**
	 * @brief	Print record.
	 * @pre		EventContent class should be initialized.
	 * @post	content record is on screen.
     * @param	cout	ostream instance
	 * @param	_event	target EventContent for printing.
	 */
	friend ostream& operator<<(ostream& cout, EventContent& _event) {
		cout << "\t[ Event name: " << _event.m_name;
		cout << ", Event description: " << _event.m_description;
		cout << ", Number of CreateTime with same character: " << _event.m_numOfCreateTime;
		cout << ", ";
		_event.DisplayAllCreateTime();
		cout << "]";

		return cout;
	}
};