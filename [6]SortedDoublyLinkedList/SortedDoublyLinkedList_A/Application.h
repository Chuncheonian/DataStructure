#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"
#include "SortedDoublyLinkedList.h"


#define FILENAMESIZE 1024

/**
 * 아이템을 관리하기 위한 Application 클래스.
 */
class Application {
private:
	ifstream							m_InFile;		// input file descriptor.
	ofstream							m_OutFile;		// output file descriptor.
	int									m_Command;		// current command number
	SortedDoublyLinkedList<ItemType>	m_List;			// 아이템 리스트.

public:
	/**
	 * default constructor.
	 */
	Application() {
		m_Command = 0;
	}
	
	/**
	 * destructor.
	 */
	~Application() {}

	/**
	 * @brief	Program driver.
	 * @pre	    program is started.
	 * @post	program is finished.
	 */
	void Run();

	/**
	 * @brief	Display command on screen and get a input from keyboard.
	 * @pre     None.
	 * @post	None.
	 * @return	User's command.
	 */
	int GetCommand();

    /**
     * @brief   Add new record into sorted list.
     * @pre     List should be initialized.
     * @post    New record is added into the sorted list.
     */
    void AddItem();

    /**
     * @brief   Display all records in the list in screen.
     * @pre     None.
     * @post    None.
     */
    void DisplayAllItem();

	/**
	 * @brief	입력받은 ID로 아이템 정보를 찾아내어 스크린에 출력한다.
	 * @pre		리스트에 아이템들의 정보가 저장되어 있다.
	 * @post	리스트에서 아이템을 찾아 출력한다.
	 * @return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	 */
	void SearchItemByID();

	/**
	 * @brief	Make empty list.
	 * @pre     None.
	 * @post	Make empty list in this member.
	 */
	void MakeEmptyList();
	
    /**
     * @brief   Get a student ID from keyboard and delete the rocord with same student ID.
     * @pre     List should be initialized.
     * @post    record is deleted into the list.
     */
    void DeleteItem();
	
	/**
	 * @brief	입력받은 ID로 아이템 정보를 찾아내어 수정한다.
	 * @pre	리스트에 아이템들의 정보가 저장되어 있다.
	 * @post	리스트에서 아이템을 찾아 정보를 수정한다.
	 * @return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
	 */
	void UpdateInfo();

	/**
	 * @brief	이름을 입력받아 그 정보를 반환한다.
	 * @pre	없음.
	 * @post	이름을 입력받은 정보가 반환된다.
	 * @return	입력된 이름의 객체를 반환한다.
	 */
	ItemType RetreiveRecordByName();

	/**
	 * @brief	이름을 입력받아 같은 이름을 가지느 모든 아이템들을 출력한다.
	 * @pre	이름을 입력받는다.
	 * @post	리스트에서 같은 이름을 가진 모든 아이템들이 출력된다.
	 */
	void SearchByName(ItemType target);

	/**
	 * @brief	Open a file by file descriptor as an input file.
	 * @pre	    A file for reading is exist.
	 * @post	Open the file for reading.
	 * @param	fileName	a filename to open for reading.
	 * @return	return 1 if this function works well, Otherwise 0.
	 */
	int OpenInFile(char *fileName);

	/**
	 * @brief	Open a file by file descriptor as an output file.
	 * @pre	    List should be initialized.
	 * @post	Open the file for writing.
	 * @param	fileName	a filename to open for writing.
	 * @return	Return 1 if this function works well, Otherwise 0.
	 */
	int OpenOutFile(char *fileName);

	/**
	 * @brief	Open a file as a read mode, read all data on the file, and set list by the data.
	 * @pre	    The file is not opened.
	 * @post	List holds all records from the file.
	 * @return	Return 1 if this function works well, Otherwise 0.
	 */
	int ReadDataFromFile();

	/**
	 * @brief	Open a file as a write mode, and write all data into the file,
	 * @pre 	The file is not opened.
	 * @post	The list is stored in the output file.
	 * @return	Return 1 if this function works well, Otherwise 0.
	 */
	int WriteDataToFile();
};