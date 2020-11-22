#pragma once
#include <iostream>
using namespace std;

#include "ItemType.h"
#include "SortedDoublyLinkedList.h"


/**
 * application class for item management simply.
 */
class Application {
private:
	int									m_command;		// current command number
	SortedDoublyLinkedList<ItemType>	m_list;			// Linked-list for ItemType.
	
public:
	/**
	 * default constructor.
	 */
	Application() {
		m_command = 0;
	}

	/**
	 * destructor.
	 */
	~Application() {}
	
	/**
	 * @brief	Program driver.
	 * @pre	program is started.
	 * @post	program is finished.
	 */
	void Run();

	/**
	 * @brief	Display command on screen and get a input from keyboard.
	 * @pre	None.
	 * @post	None.
	 * @return	User's command.
	 */
	int GetCommand();

	/**
	 * @brief	Add new record into list.
	 * @pre	List should be initialized.
	 * @post	New record is added into the list.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int InsertItem();

	/**
	 * @brief	Delete record into list.
	 * @pre	list should be not empty.
	 * @post	record is deleted into the list.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int DeleteItem();

	/**
	 * @brief	Display all records in the list on screen.
	 * @pre	None.
	 * @post	None.
	 */
	void DisplayAll();

	/**
	 * @brief	Make empty list.
	 * @pre	None.
	 * @post	Make empty list in this member.
	 */
	int MakeEmpty();

	/**
	 * @brief	Retrieve item in the list.
	 * @pre	None.
	 * @post	None.
	 * @return	1 if the target item is exist in the list, otherwise 0.
	 */
	int RetrieveItem();


	/**
	 * @brief	Primary key(�й�)�� �޾� �˻��Ͽ� �ش� ������ ����.
	 * @pre	����Ʈ�� �ʱ�ȭ�Ǿ��־�� ��.
	 * @post	������� �ִ� ��� ������ ������ �Է¹޾� �����ϰ�, ���� ���� ���ٰ� ���.
	 */
	int ReplaceItem();
};