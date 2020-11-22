#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

#include "ItemType.h"
#include "CircularQue.h"

class Application{
private:
	ifstream				m_inFile;       // input file descriptor.
	ofstream				m_outFile;      // output file descriptor.
	int						m_command;		// current command number.
	
	CircularQue<ItemType> m_Queue;			// content list.

public:
    // default constructor.
    Application() {
        m_command = 0;
    }

    // default destructor.
    ~Application() {}

	/**
     * @brief   Program driver.
     * @pre     Program is started
     * @post    Program is finished.
     */
    void Run();

    /**
     * @brief   Display command on screen and get a input from keyboard.
     * @pre     None.
     * @post    None.
     * @return  User's command.
     */
    int GetCommand();

	/**
	 * @brief   Add new record into queue.
	 * @pre     Queue should be initialized.
	 * @post    New record is added into the queue.
	 */
	void EnQueItem();

	/**
	 * @brief   Delete foremost record into queue.
	 * @pre     Queue should be initialized.
	 * @post    Foremost record is deleted into the queue.
	 */
	void DeQueItem();

	int CheckEmpty();

	int CheckFull();

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
	 * @brief   Get a PK of ItemType from keyboard and Delete the rocord with same PK.
	 * @pre     Queue should be initialized.
	 * @post    Record is deleted into the Queue.
	 */
	void DeleteItem();

	/**
	 * @brief   Get a student ID from keyboard and Display a record with input student ID.
	 * @pre     List should be initialized.
	 * @post    None.
	 */
	void Search();

	/**
	 * @brief   Get a Primary Key from keyboard and Replace the rocord with same Primary Key.
	 * @pre     List should be initialized.
	 * @post    Record is replaced into the list.
	 */
	void Replace();
};