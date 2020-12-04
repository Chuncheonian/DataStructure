#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "SortedList.h"
#include "SortedSinglyLinkedList.h"
#include "BinarySearchTree.h"

/**
 * Character information class.
 */
class CharacterContent{
protected:
	string				    		m_character;		// Character Name. (Primary KEY)
	int				    			m_numOfCreateTime;	// Number of createTime with same Character name.
	SortedSinglyLinkedList<string>	m_createTimeList;	// CreateTime(Primary Key of MC) List with same character.
public:
	/**
	 * default constructor.
	 */
	CharacterContent() {
		m_character = "";
		m_numOfCreateTime = 0;
	}

	/**
	 * destructor.
	 */
	~CharacterContent()	{}

	/**
	 * @brief	Get Character name.
	 * @pre	    Character name is set.
	 * @post	None.
	 * @return	Character name.
	 */
	string GetName() const { return m_character; }

	/**
	 * @brief	Get number of CreateTime.
	 * @pre	    Number of CreateTime.
	 * @post	None.
	 * @return	Number of CreateTime.
	 */
	int GetCount() const { return m_numOfCreateTime; }

	/**
	 * @brief	Set Character name.
	 * @pre	    None.
	 * @post	Character name is set.
	 * @param	_character	Character name.
	 */
	void SetName(string _character) { m_character = _character; }

	/**
	 * @brief	Set number of CreateTime.
	 * @pre	    None.
	 * @post	Number of CreateTime.
	 * @param	_numOfCreateTime	Number of CreateTime.
	 */
	void SetCount(int _numOfCreateTime) { m_numOfCreateTime = _numOfCreateTime; }
	
	/**
	 * @brief	Set Character record.
	 * @pre	    None.
	 * @post	Character record is set.
	 * @param	_character			Character name.
	 * @param	_numOfCreateTime	Number of CreateTime.
	 */
	void SetRecord(string _character, int _numOfCreateTime) {
		SetName(_character);
		SetCount(_numOfCreateTime);
	}

	/**
	 * @brief	Display Character name on screen.
	 * @pre	    Character name is set.
	 * @post	Character name is on screen.
	 */
	void DisplayNameOnScreen() { cout << "\tName : " << m_character; }
	
	/**
	 * @brief	Display number of CreateTime.
	 * @pre	    Number of CreateTime is set.
	 * @post	Number of CreateTime is on screen.
	 */
	void DisplayCountOnScreen() { cout << "\tNumber of CreateTime with same character : " << m_numOfCreateTime; }

	/**
	 * @brief	Display an Character record on screen.
	 * @pre	    Character record is set.
	 * @post	Character record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayCountOnScreen();
		DisplayAllCreateTime();
		cout << endl;
	}

	/**
	 * @brief	Set Character name from keyboard.
	 * @pre	    None.
	 * @post	Character name is set.
	 */
	void SetNameFromKB();
	
	/**
	 * @brief	Set number of CreateTime.
	 * @pre	    None.
	 * @post	Number of CreateTime is set.
	 */
	void SetCountFromKB();
	
	/**
	 * @brief	Set Character record from keyboard.
	 * @pre	    None.
	 * @post		Character record is set.
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
	 * @pre		Exist Character name.
	 * @post	None.
	 */
	void SearchAtMasterList(BinarySearchTree<MultimediaContent>& _masterList);

	/**
	 * @brief	Compare two CharacterContent by Character name.
	 * @pre	    two CharacterContent should be initialized.
	 * @param	_character	target Character for comparing.
	 * @return	return 1 if this.character > data.character, 0 if not.
	 */
	bool operator>(CharacterContent& _character);

	/**
	 * @brief	Compare two CharacterContent by Character name.
	 * @pre	    two CharacterContent should be initialized.
	 * @param	_character	target Character for comparing.
	 * @return	return 1 if this.character < data.character, 0 if not.
	 */
	bool operator<(CharacterContent& _character);

	/**
	 * @brief	Compare two CharacterContent by Character name.
	 * @pre	    two CharacterContent should be initialized.
	 * @param	_character	target Character for comparing.
	 * @return	return 1 if this.character == data.character, 0 if not.
	 */
	bool operator==(CharacterContent& _character);

	/**
	 * @brief	Print record.
	 * @pre		CharacterContent class should be initialized.
	 * @post	Content record is on screen.
     * @param	cout	ostream instance
	 * @param	_character	target CharacterContent for printing.
	 */
	friend ostream& operator<<(ostream& cout, CharacterContent& _character) {
		cout << "\t[ Character name: " << _character.m_character;
		cout << ", Number of CreateTime with same character: " << _character.m_numOfCreateTime;
		cout << ", ";
		_character.DisplayAllCreateTime();
		cout << "]";

		return cout;
	}
};