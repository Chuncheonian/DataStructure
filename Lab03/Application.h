#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "FavoriteContent.h"
#include "Event.h"

#include "UnsortedList.h"
#include "SortedList.h"
#include "CircularQue.h"

#define FILENAMESIZE 1024

// application class for item management simply.
class Application {
private:
    ifstream                            m_inFile;       // input file descriptor.
    ofstream                            m_outFile;      // output file descriptor.
    int                                 m_command;      // current command number.

    UnsortedList<MultimediaContent>     m_listMC;       // multimedia content list.
    CircularQue<FavoriteContent>        m_listFC;       // favorite content queue.
    Event                               m_event;        // event class instance

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
     * @pre     none.
     * @post    none.
     * @return  user's command.
     */
    int GetCommand();

    /**
     * @brief   Add new record into list.
     * @pre     list should be initialized.
     * @post    new record is added into the list.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
	int AddContents();

    /**
     * @brief   Get a content name from keyboard and delete the rocord with same content name.
     * @pre     list should be initialized.
     * @post    record is deleted into the list.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
    int DeleteContents();

    /**
     * @brief   Get a record from keyboard and Replace the rocord with same record.
     * @pre     list should be initialized.
     * @post    record is replaced into the list.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
    int ReplaceContents();

    /**
     * @brief   Get a content name from keyboard and Display a record with input content name.
     * @pre     list should be initialized.
     * @post    none.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
    int RetrieveContents();

    /**
     * @brief   Display all records in the list in screen.
     * @pre     none.
     * @post    none.
     */
    void DisplayAllContents();

    /**
     * @brief   Make list empty.
     * @pre     none.
     * @post    clear list.
     */
    void MakeEmpty();

    /**
     * @brief	Open a file by file descriptor as an input file.
     * @pre     a file for reading is exist
     * @post    Open the file for reading
     * @param   fileName    a filename to open for reading.
     * @return  return 1 if this funcion works well,
     *          oterwise return 0.
     */
	int OpenInFile(char *fileName);

	/**
     * @brief	Open a file by file descriptor as an output file.
     * @pre	    list should be initialized.
     * @post	Open the file for writing.
     * @param	fileName	a filename to open for writing.
     * @return	return 1 if this function works well, otherwise 0.
     */   
	int OpenOutFile(char *fileName);

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
     * @pre	    The file is not opened.
     * @post	the list is stored in the output file.
     * @return	return 1 if this function works well,
     *          otherwise return 0.
     */
    int WriteDataToFile();

    /**
     * @brief   Add new record into listFC.
     * @pre     list should be initialized.
     * @post    new record is added into the listFC.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
    int AddFC();

    /**
     * @brief   Get a content name from keyboard and delete the rocord with same content name.
     * @pre     list should be initialized.
     * @post    record is deleted into the list.
     * @return  return 1 if this function works well,
     *          oterwise return 0.
     */
    int DeleteFC();

    /**
     * @brief   Display all records in the listFC in screen.
     * @pre     none.
     * @post    none.
     */
    void DisplayAllFC();

    /**
     * @brief   Display detail information of the specific record in screen.
     * @pre     FC, MC both are initialized.
     * @post    none.
     */
    void DisplayDetailFC();
    
    /**
     * @brief   Display all informations of the event class in screen.
     * @pre     event class should be initialized.
     * @post    none.
     */
    void DisplayEventList();
};