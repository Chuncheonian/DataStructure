#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "StudentType.h"
#include "DeptType.h"
#include "SortedList.h"
#include "SortedLinkedList.h"

/**
 * item information class.
 */
class DeptType{
protected:
	string					m_dName;			// Department name.
	int						m_numOfStudent;		// Number of Students with same Department name.
	SortedLinkedList<int>	m_sIdList;			// Student ID List.
public:
	/**
	 * default constructor.
	 */
	DeptType() {
		m_dName = "";
		m_numOfStudent = 0;
	}

	/**
	 * destructor.
	 */
	~DeptType()	{

	}

	/**
	 * @brief	Get Department name.
	 * @pre	    Department name is set.
	 * @post	None.
	 * @return	Department name.
	 */
	string GetName() { return m_dName; }

	/**
	 * @brief	Get number of students.
	 * @pre	    Number of students is set.
	 * @post	None.
	 * @return	Number of students.
	 */
	int GetCount() { return m_numOfStudent; }

	/**
	 * @brief	Set Department name.
	 * @pre	    None.
	 * @post	Department name is set.
	 * @param	_dName	Department name.
	 */
	void SetName(string _dName) { m_dName = _dName; }

	/**
	 * @brief	Set number of students.
	 * @pre	    None.
	 * @post	Number of students is set.
	 * @param	_numOfStudent	Number of students.
	 */
	void SetCount(int _numOfStudent) { m_numOfStudent = _numOfStudent; }
	
	/**
	 * @brief	Set department record.
	 * @pre	    None.
	 * @post	Department record is set.
	 * @param	_dName	Department name.
	 * @param	_numOfStudent	Number of students.
	 */
	void SetRecord(string _dName, int _numOfStudent) {
		SetName(_dName);
		SetCount(_numOfStudent);
	}

	/**
	 * @brief	Display department name on screen.
	 * @pre	    Department name is set.
	 * @post	Department name is on screen.
	 */
	void DisplayNameOnScreen() { cout << "\tName : " << m_dName; }
	
	/**
	 * @brief	Display number of students on screen.
	 * @pre	    Number of students is set.
	 * @post	Number of students is on screen.
	 */
	void DisplayCountOnScreen() { cout << "\tNumber of Students : " << m_numOfStudent; }

	/**
	 * @brief	Display an department record on screen.
	 * @pre	    Department record is set.
	 * @post	Department record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayCountOnScreen();
		DisplayAllId();
		cout << endl;
	}

	/**
	 * @brief	Set department name from keyboard.
	 * @pre	    None.
	 * @post	Department name is set.
	 */
	void SetNameFromKB();
	
	/**
	 * @brief	Set number of students from keyboard.
	 * @pre	    None.
	 * @post	Number of students is set.
	 */
	void SetCountFromKB();
	
	// /**
	//  * @brief	Set department record from keyboard.
	//  * @pre	    None.
	//  * @post	Department record is set.
	//  */
	// void SetRecordFromKB();

	/**
	 * @brief	Read a record from file.
	 * @pre	    the target file is opened.
	 * @post	Department record is set.
	 * @param	fin     file descriptor.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int ReadDataFromFile(ifstream& fin);

	/**
	 * @brief	Write a record into file.
	 * @pre	    the target file is opened. And the list should be initialized.
	 * @post	the target file is included the new department record.
	 * @param	fout	file descriptor.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int WriteDataToFile(ofstream& fout);
	
	/**
	 * @brief	Compare two department types by department name.
	 * @pre	    two department types should be initialized.
	 * @param	data	target department for comparing.
	 * @return	return 1 if this.m_dName > data.m_dName, 0 if not.
	 */
	bool operator>(DeptType& item);

	/**
	 * @brief	Compare two department types by department name.
	 * @pre	    two department types should be initialized.
	 * @param	data	target department for comparing.
	 * @return	return 1 if this.m_dName == data.m_dName, 0 if not.
	 */
	bool operator==(DeptType& item);

	/**
     * @brief	Add new student ID into list.
     * @pre     list should be initialized.
     * @post	new record is added into the list and number of students++.
     */
	void AddId(int _sId);

	/**
	 * @brief	Delete student ID into list.
	 * @pre		list should be not empty.
	 * @post	record is deleted into the list. and number of students--.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int DeleteId(int _sId);

	/**
     * @brief	Display all student ID in the list on screen.
     * @pre     None.
     * @post	None.
     */
	void DisplayAllId();

	/**
	 * @brief	Bring masterlist as pass by reference and Display detatil student records.
	 * @pre		Exist department name.
	 * @post	None.
	 */
	void SearchAtMasterList(SortedList<StudentType>& _masterList);
};