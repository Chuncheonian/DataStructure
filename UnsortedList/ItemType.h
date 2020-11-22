#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Item information class.
 */
class ItemType{
protected:
	int     m_id;			// student ID.
	string	m_name;
	string  m_address;	    // student address. 
public:
	/**
	 * default constructor.
	 */
	ItemType() {
		m_id = -1;
		m_name = "";
		m_address = "";
	}

	/**
	 * Overloading Constructor.
	 */
	ItemType(int _id) {
		m_id = _id;
		m_name = "";
		m_address = "";
	}

	/**
	 * default destructor.
	 */
	~ItemType() {}

	/**
	 * @brief	Get student id.
	 * @pre		Student id is set.
	 * @post	None.
	 * @return	student id.
	 */
	int GetId() { return m_id; }

	/**
	 * @brief	Get student name.
	 * @pre	    Student name is set.
	 * @post	None.
	 * @return	Student name.
	 */
	string GetName() { return m_name; }

	/**
	 * @brief	Get student address
	 * @pre	    Student address is set.
	 * @post    None.
	 * @return	Student address.
	 */
	string GetAddress() { return m_address; }

	/**
	 * @brief	Set student id.
	 * @pre	    None.
	 * @post    Student id is set.
	 * @param	_id	student id.
	 */
	void SetId(int _id) { m_id = _id; }
	
	/**
	 * @brief	Set student name.
	 * @pre	    None.
	 * @post	Student name is set.
	 * @param	_name	Student name.
	 */
	void SetName(string _name) { m_name = _name; }
	
	/**
	 * @brief	Set student address.
	 * @pre	    None.
	 * @post	Sudent address is set.
	 * @param	_address	Student address.
	 */
	void SetAddress(string _address) { m_address = _address; }
	
	/**
	 * @brief	Set student record.
	 * @pre	    None.
	 * @post	student record is set.
	 * @param	_id			student id.
	 * @param	_name		student name.
	 * @param	_address	student address.
	 */
	void SetRecord(int _id, string _name, string _address) {
		SetId(_id);
		SetName(_name);
		SetAddress(_address);
	}

	/**
	 * @brief	Display student id on screen.
	 * @pre	    student id is set.
	 * @post	student id is on screen.
	 */
	void DisplayIdOnScreen() { cout << "\tID : " << m_id; }

	/**
	 * @brief	Display student name on screen.
	 * @pre	    Student name is set.
	 * @post	Student name is on screen.
	 */
	void DisplayNameOnScreen() { cout << "\tName : " << m_name; }

	/**
	 * @brief	Display student address on screen.
	 * @pre	    Student address is set.
	 * @post	Student address is on screen.
	 */
	void DisplayAddressOnScreen() { cout << "\tAddress : " << m_address; }

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
	bool operator>(ItemType& _item);

	/**
	 * @brief	Compare two item types by item id.
	 * @pre	    two item types should be initialized.
	 * @param	data	target item for comparing.
	 * @return	return 1 if this.id > data.id, 0 if not.
	 */
	bool operator<(ItemType& _item);

	/**
	 * @brief	Compare two item types by item id.
	 * @pre	    two item types should be initialized.
	 * @param	data	target item for comparing.
	 * @return	return 1 if this.id == data.id, 0 if not.
	 */
	bool operator==(ItemType& _item);

	/**
	 * @brief	Assign content record to another.
	 * @pre		Right ItemType class should be initialized.
	 * @post	Content record in left ItemType class is set.
	 * @param	data	target ItemType for assigning.
	 */
    ItemType operator=(const ItemType& _item);

	/**
	 * @brief	Print record.
	 * @pre		ItemType class should be initialized.
	 * @post	Content record is on screen.
	 * @param	cout	ostream instance
	 * @param	_item	target ItemType for printing.
	 */
	friend ostream& operator<<(ostream& cout, const ItemType& _item) {
		cout << "\t[ Student Id: " << _item.m_id;
		cout << ", Student Name: " << _item.m_name;
		cout << ", Student Address: " << _item.m_address << " ]";
        cout << endl;
		return cout;
	}

	/**
	 * @brief	Input record.
	 * @pre		None.
	 * @post	Content record is initialized.
	 * @param	cin	    istream instance
	 * @param	_item	target ItemType for Input.
	 */
	friend istream& operator>>(istream& cin, ItemType& _item) {
		cout << "\n\tEnter Student Id: ";
		cin >> _item.m_id;
		cout << "\tEnter Student Name: ";
		cin >> _item.m_name;
		cout << "\tEnter Student Address: ";
		cin >> _item.m_address;

		return cin;
	}
};