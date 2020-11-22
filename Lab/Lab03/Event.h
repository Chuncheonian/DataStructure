#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MultimediaContent.h"
#include "CircularQue.h"

using namespace std;

class Event {
private:
	string              m_name;             // event name
	string              m_description;      // event description
	int                 m_countMC;			// MC count in eventList
	CircularQue<string> m_pQueMC;			// Queue including content Name of MC with same event.

public:
	// default constructor.
	Event() {
		m_name = "";
		m_description = "";
		m_countMC = 0;
	}

	// default destructor.
	~Event() {}

	/**
	 * @brief	Get event name
	 * @pre	    event name is set
	 * @post	none
	 * @return  event name
	 */
	string GetName() const { return m_name; }

	/**
	 * @brief	Get event description
	 * @pre	    event description is set
	 * @post	none
	 * @return  event description
	 */
	string GetDescription() const { return m_description; }

	/**
	 * @brief	Get count MC
	 * @pre	    count MC is set
	 * @post	none
	 * @return  count MC
	 */
	int GetCountMC() const { return m_countMC; }

	/**
	 * @brief	Set event name.
	 * @pre		none.
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
	 * @brief	Set count MC
	 * @pre		none.
	 * @post	count MC is set.
	 * @param	_countMC	count MC
	 */
	void SetCountMC(int _countMC) { m_countMC = _countMC; }

	/**
	 * @brief	Set Event record.
	 * @pre		none.
	 * @post	Event record is set.
	 * @param	_name			event name.
	 * @param	_description	event description
	 * @param	_countMC		count MC
	 */ 
	void SetRecord(string _name, string _description, int _countMC) {
		SetName(_name);
		SetDescription(_description);
		SetCountMC(_countMC);
	}

	/**
	 * @brief	Display event name on screen.
	 * @pre		event name is set.
	 * @post	event name is on screen.
	 */ 
	void DisplayNameOnscreen() { cout << "\tEvent Name: " << m_name; }

	/**
	 * @brief	Display event description on screen
	 * @pre     event description is set
	 * @post	event description is on screen
	 */
	void DisplayDescriptionOnscreen() { cout << "\tEvent Description: " << m_description; }

	/**
	 * @brief	Display content creation date and time on screen.
	 * @pre	    content creation date and time are set.
	 * @post	content creation date and time are on screen.
	 */ 
	void DisplayCounMCOnscreen() { cout << "\tMC count: " << m_countMC; }

	/**
	 * @brief	Display content Name of MC with same event on screen.
	 * @pre	    content Name of MC with same event are set.
	 * @post	content Name of MC with same eventare on screen.
	 */ 
	void DisplayAllMCOnscreen() { m_pQueMC.Print(); }

	/**
	 * @brief	Display a content record on screen.
	 * @pre 	content record is set.
	 * @post	content record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnscreen();
		DisplayDescriptionOnscreen();
		DisplayCounMCOnscreen();
		DisplayAllMCOnscreen();
		cout << endl;
	}

	/**
	 * @brief	Set content name from keyboard.
	 * @pre 	none.
	 * @post	content name is set.
	 */  
	void SetNameFromKB();

 	/**
	  * @brief	Set event description from keyboard.
	  * @pre	none.
	  * @post	event description is set.
	  */ 
	void SetDescriptionFromKB();

	/**
	 * @brief	Set count MC from keyboard.
	 * @pre	    none.
	 * @post	count MC is set.
	 */	
	void SetCountMCFromKB();

	/**
	 * @brief	Set content record from keyboard.
	 * @pre 	none.
	 * @post	content record is set.
	 */	
	void SetRecordFromKB();

    /**
     * @brief   Add content Name of MC with same event into list.
     * @pre     queue should be initialized.
     * @post    new content Name of MC with same event is added into the queue and MC count++.
	 * @param	_item	new data
     */
	void AddMC(MultimediaContent _item);

    /**
     * @brief   delete content Name.
     * @pre     queue should be initialized.
     * @post    record is deleted into the list and MC count--
	 * @param	_item	delete data
     */
	void DeleteMC(MultimediaContent _item);

	/**
	 * @brief	Compare content name in two Event class
	 * @pre		two Event class should be initialized.
	 * @post	none.
	 * @param	data	target Event for comparing.	
	 * @return	return true if this->m_name == data->m_name,
	 * 			otherwise return false.
	 */    
	bool operator==(const Event& data) {
		if (m_name == data.m_name)
			return true;
		else
			return false;
	}

	/**
	 * @brief	Assign content record to another.
	 * @pre		right Event class should be initialized.
	 * @post	content record in left Event class is set.
	 * @param	data	target Event for assigning.
	 */
	void operator=(const Event& data) {
		m_name = data.m_name;
		m_description = data.m_description;
		m_countMC = data.m_countMC;
	}

	/**
	 * @brief	Print event class variables.
	 * @pre		event class should be initialized.
	 * @post	event class variables are on screen.
     * @param	cout	ostream instance
	 * @param	_item	target event class for printing.
	 */
	friend ostream& operator<<(ostream& cout, Event& _item) {
		cout << "\t[ Event name: " << _item.GetName() << ", Description: " << _item.GetDescription() << ", MC Count: " << _item.GetCountMC() << ", { Content name: ";
		_item.DisplayAllMCOnscreen();
		cout << " } ]" << endl;
		return cout;
	}

	/**
	 * @brief	Input event class variables.
	 * @pre		none.
	 * @post	event class is initialized.
     * @param	cin	    istream instance
	 * @param	_item	target event class for Input.
	 */
	friend istream& operator>>(istream& cin, Event& _item) {
		cout << "\n\tEnter Name: ";
		cin >> _item.m_name;
		cout << "\tEnter Description: ";
		cin >> _item.m_description;
		cout << "\tEnter MC Count: ";
		cin >> _item.m_countMC;

		return cin;
	}
};