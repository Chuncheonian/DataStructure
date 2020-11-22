#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"
#include "UnsortedList.h"

#define FILENAMESIZE 1024

/**
 * Application class for item management simply.
 */
class Application {
private:
	ifstream		m_inFile;		// input file descriptor.
	ofstream		m_outFile;		// output file descriptor.
	int				m_command;		// current command number.

	UnsortedList	m_list;			// student list.

public:
	/**
	 * @brief   default constructor.
	 */
	Application() {
		m_command = 0;
	}

	/**
	 * @brief	default destructor.
	 */
	~Application() {}

	/**
	 * @brief   Program driver.
	 * @pre     Program is started
	 * @post    Program is finished.
	 */
	void Run();

	/**
	 * @brief   Display command on screen and Get a input from keyboard.
	 * @pre     None.
	 * @post    None.
	 * @return  User's command.
	 */
	int GetCommand();

	/**
	 * @brief   Add new record into list.
	 * @pre     List should be initialized.
	 * @post    New record is added into the list.
	 */
	void AddItem();

	/**
	 * @brief   Get a student ID from keyboard and Delete the rocord with same student ID.
	 * @pre     List should be initialized.
	 * @post    Record is deleted into the list.
	 */
	void DeleteItem();

	/**
	 * @brief   Get a Primary Key from keyboard and Replace the rocord with same Primary Key.
	 * @pre     List should be initialized.
	 * @post    Record is replaced into the list.
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int Replace();

	/**
	 * @brief   Get a student ID from keyboard and Display a record with input student ID.
	 * @pre     List should be initialized.
	 * @post    None.
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int RetrieveStudent();

	/**
	 * @brief   Display all records in the list in screen.
	 * @pre     None.
	 * @post    None.
	 */
	void DisplayAllItem();

	/**
	 * @brief   Make list empty.
	 * @pre     None.
	 * @post    Clear list.
	 */
	void MakeEmpty();

	/**
	 * @brief	Open a file by file descriptor as an input file.
	 * @pre     A file for reading is exist
	 * @post    Open the file for reading
	 * @param   fileName    a filename to open for reading.
	 * @return  return 1 if this funcion works well,
	 *          oterwise return 0.
	 */
	int OpenInFile(char* fileName);

	/**
	 * @brief	Open a file by file descriptor as an output file.
	 * @pre	list should be initialized.
	 * @post	open the file for writing.
	 * @param	fileName	a filename to open for writing.
	 * @return	return 1 if this function works well, otherwise 0.
	 */    
	int OpenOutFile(char* fileName);

	/**
	 * @brief	Open a file as a read mode, read all data on the file, and set list by the data.
	 * @pre	    The file is not opened.
	 * @post	list holds all records from the file.
	 * @return	return 1 if this function works well,
	 *          otherwise return 0.
	 */
	int ReadDataFromFile();

	/**
	 * @brief	Open a file as a write mode, and write all data into the file,
	 * @pre	The file is not opened.
	 * @post	the list is stored in the output file.
	 * @return	return 1 if this function works well,
	 *          otherwise return 0.
	 */
	int WriteDataToFile();
};