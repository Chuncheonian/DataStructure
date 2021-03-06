#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * item information class.
 */
class StudentType{
protected:
	int     m_Id;			// student ID.
	string  m_sName;		// student name.
	string  m_sAddress;	    // student address. 
public:
	/**
	* default constructor.
	*/
	StudentType() {
		m_Id = -1;
		m_sName = "";
		m_sAddress = "";
	}

	/**
	 * destructor.
	 */
	~StudentType()	{}

	/**
	 * @brief	     Get student id.
	 * @pre	    Student id is set.
	 * @post	     None.
	 * @return	student id.
	 */
	int GetId() { return m_Id; }

	/**
	 * @brief	Get student name.
	 * @pre	    Student name is set.
	 * @post	None.
	 * @return	Student name.
	 */
	string GetName() { return m_sName; }

	/**
	 * @brief	Get student address
	 * @pre	    Student address is set.
	 * @post    None.
	 * @return	Student address.
	 */
	string GetAddress() { return m_sAddress; }

	/**
	 * @brief	Set student id.
	 * @pre	    None.
	 * @post    Student id is set.
	 * @param	inId	student id.
	 */
	void SetId(int inId) { m_Id = inId; }
	
	/**
	 * @brief	Set student name.
	 * @pre	    None.
	 * @post	student name is set.
	 * @param	inName	student name.
	 */
	void SetName(string inName) { m_sName = inName; }
	
	/**
	 * @brief	Set student address.
	 * @pre	    None.
	 * @post	student address is set.
	 * @param	inAddress	student address.
	 */
	void SetAddress(string inAddress) { m_sAddress = inAddress; }
	
	/**
	 * @brief	Set student record.
	 * @pre	    None.
	 * @post	student record is set.
	 * @param	inId	student id.
	 * @param	inName	student name.
	 * @param	inAddress	student address.
	 */
	void SetRecord(int inId, string inName, string inAddress) {
		SetId(inId);
		SetName(inName);
		SetAddress(inAddress);
	}

	/**
	 * @brief	Display student id on screen.
	 * @pre	    student id is set.
	 * @post	student id is on screen.
	 */
	void DisplayIdOnScreen() { cout << "\tID   : " << m_Id; }

	/**
	 * @brief	Display student name on screen.
	 * @pre	    Student name is set.
	 * @post	Student name is on screen.
	 */
	void DisplayNameOnScreen() { cout << "\tName : " << m_sName; }

	/**
	 * @brief	Display student address on screen.
	 * @pre	    Student address is set.
	 * @post	Student address is on screen.
	 */
	void DisplayAddressOnScreen() { cout << "\tAddress : " << m_sAddress; }

	/**
	 * @brief	Display an student record on screen.
	 * @pre	    Student record is set.
	 * @post	Student record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayIdOnScreen();
		DisplayNameOnScreen();
		DisplayAddressOnScreen();
	   cout << endl;
	}

	/**
	 * @brief	Set student id from keyboard.
	 * @pre	    None.
	 * @post	student id is set.
	 */
	void SetIdFromKB();

	/**
	 * brief	Set student name from keyboard.
	 * @pre	    None.
	 * @post	Student name is set.
	 */
	void SetNameFromKB();

	/**
	 * @brief	Set student address from keyboard.
	 * @pre	    None.
	 * @post	student address is set.
	 */
	void SetAddressFromKB();
	
	/**
	 * @brief	Set student record from keyboard.
	 * @pre	    None.
	 * @post	student record is set.
	 */
	void SetRecordFromKB();

	/**
	 * @brief	Read a record from file.
	 * @pre	    the target file is opened.
	 * @post	student record is set.
	 * @param	fin     file descriptor.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int ReadDataFromFile(ifstream& fin);

	/**
	 * @brief	Write a record into file.
	 * @pre	    the target file is opened. And the list should be initialized.
	 * @post	the target file is included the new student record.
	 * @param	fout	file descriptor.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int WriteDataToFile(ofstream& fout);
	
	/**
	 * @brief	Compare two item types by item id.
	 * @pre	    two item types should be initialized.
	 * @param	data	target item for comparing.
	 * @return	return 1 if this.id > data.id, 0 if not.
	 */
	bool operator>(StudentType& item);

	/**
	 * @brief	Compare two item types by item id.
	 * @pre	    two item types should be initialized.
	 * @param	data	target item for comparing.
	 * @return	return 1 if this.id > data.id, 0 if not.
	 */
	bool operator<(StudentType& item);

	/**
	 * @brief	Compare two item types by item id.
	 * @pre	    two item types should be initialized.
	 * @param	data	target item for comparing.
	 * @return	return 1 if this.id == data.id, 0 if not.
	 */
	bool operator==(StudentType& item);

	/**
	 * @brief	Print record.
	 * @pre		StudentType class should be initialized.
	 * @post	content record is on screen.
	 * @param	cout	ostream instance
	 * @param	_item	target StudentType for printing.
	 */
	friend ostream& operator<<(ostream& cout, const StudentType& _item) {
		cout << "\t[ Student Id: " << _item.m_Id;
		cout << ", Student Name: " << _item.m_sName;
		cout << ", Student Address: " << _item.m_sAddress << " ]";

		return cout;
	}

	/**
	 * @brief	Input record.
	 * @pre		none.
	 * @post	content record is initialized.
	 * @param	cin	    istream instance
	 * @param	_item	target StudentType for Input.
	 */
	friend istream& operator>>(istream& cin, StudentType& _item) {
		cout << "\n\tEnter student id: ";
		cin >> _item.m_Id;
		cout << "\tstudent name: ";
		cin >> _item.m_sName;
		cout << "\tEnter student address: ";
		cin >> _item.m_sAddress;

		return cin;
	}
};