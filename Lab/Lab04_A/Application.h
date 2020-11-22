#pragma once
#include <iostream>
using namespace std;

#include "StudentType.h"
#include "DeptType.h"
#include "SortedList.h"
#include "SortedLinkedList.h"

#define FILENAMESIZE 1024

/**
 * application class for item management simply.
 */
class Application {
private:
	ifstream					m_InFile;		// input file descriptor.
	ofstream					m_OutFile;		// output file descriptor.
	SortedList<StudentType>		masterList;		// Sorted Array-list for StudentType.
	SortedLinkedList<DeptType>	depList;		// Sorted Linked-list for DeptType.
	int                     	m_nCurCommand;	// current command number
public:
	/**
	 * default constructor.
	 */
	Application() {
		m_nCurCommand = 0;
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
     * @pre     list should be initialized.
     * @post    new record is added into the sorted list.
     */
    void AddStudent();

    /**
     * @brief   Display all records in the list in screen.
     * @pre     None.
     * @post    None.
     */
    void DisplayAllStudent();

	/**
	 * @brief	Make empty list.
	 * @pre     None.
	 * @post	Make empty list in this member.
	 */
	int MakeEmpty();

    /**
     * @brief   Searching for same Student ID by Binary search and Get the data.
     * @pre     None.
     * @post    Print a record.
     */
    void SearchById_BinS();

    /**
     * @brief   Get a student ID from keyboard and delete the rocord with same student ID.
     * @pre     list should be initialized.
     * @post    record is deleted into the list.
     */
    void DeleteStudent();
    
    /**
     * @brief   Get a record from keyboard and replace the rocord with same record.
     * @pre     list should be initialized.
     * @post    record is replaced into the list.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
    int ReplaceStudent();

	// Application related to Department list. 

	/**
	 * @brief	Add new record into list.
	 * @pre     list should be initialized.
	 * @post	new record is added into the list.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int AddDept();

	/**
	 * @brief	Display all department record in the list on screen.
	 * @pre     None.
	 * @post	None.
	 */
	void DisplayAllDept();

	/**
	 * @brief	Add Student ID into ID List of Department Type.
	 * @pre		masterList and deptList should be initialized.
	 * @post	new student ID is added into IdList of DeptType.
	 */
	void InsertStudentIntoDept();

	/**
	 * @brief	Search student ID from Deparment Record and Get student detail record.
	 * @pre		masterList and deptList should be initialized.
	 * @post	Display detail student Records.
	 */
	void SearchStudentFromDept();

	/**
	 * @brief	Delete student ID into IdList in deptList.
	 * @pre		List should be not empty.
	 * @post	student ID is deleted into the IdList in deptList.
	 * @return	1 if this function works well, Otherwise 0.
	 */
	int DeleteStudentFromDept(StudentType& _student);

    /**
	 * @brief	Open a file by file descriptor as an input file.
	 * @pre	    A file for reading is exist.
	 * @post	open the file for reading.
	 * @param	fileName	a filename to open for reading.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int OpenInFile(char *fileName);

	/**
	 * @brief	Open a file by file descriptor as an output file.
	 * @pre	    List should be initialized.
	 * @post	open the file for writing.
	 * @param	fileName	a filename to open for writing.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int OpenOutFile(char *fileName);

	/**
	 * @brief	Open a file as a read mode, read all data on the file, and set list by the data.
	 * @pre	    The file is not opened.
	 * @post	list holds all records from the file.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int ReadDataFromFile();

	/**
	 * @brief	Open a file as a write mode, and write all data into the file,
	 * @pre 	The file is not opened.
	 * @post	the list is stored in the output file.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
	int WriteDataToFile();
};