#pragma once
#include  <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"
#include "SortedList.h"

#define FILENAMESIZE 1024

/**
 * Application class for item management simply.
 */
class Application{
private:
    ifstream        m_InFile;       // input file descriptor.
    ofstream        m_OutFile;      // output file descriptor.
    int             m_Command;      // current command number.
    
    SortedList      m_List;         // content list.

public:
    // default constructor.
    Application() {
        m_Command = 0;
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
     * @brief   Add new record into sorted list.
     * @pre     List should be initialized.
     * @post    New record is added into the sorted list.
     */
    void AddContent();

    /**
     * @brief   Get a PK from keyboard and delete the rocord with same PK.
     * @pre     List should be initialized.
     * @post    Record is deleted into the list.
     */
    void DeleteContent();
    
    /**
     * @brief   Get a Primary Key from keyboard and Replace the rocord with same Primary Key.
     * @pre     List should be initialized.
     * @post    Record is replaced into the list.
     * @return  Return 1 if this function works well,
     *          Oterwise return 0.
     */
    int ReplaceContent();

    /**
     * @brief   Searching for same content Name by Sequential search and Get the data.
     * @pre     None.
     * @post    Print a record.
     */
    void SearchByName_SeqS();
    
    /**
     * @brief   Searching for same content Name by Binary search and Get the data.
     * @pre     None.
     * @post    Print a record.
     */
    void SearchByName_BinS();

    /**
     * @brief   Get a address from keyboard and Display a record with input address.
     * @pre     Add data.
     * @post    Print records.
     * @return  Return 1 if this function works well,
     *          Oterwise return 0.
     */
    int SearchByAddress();

    /**
     * @brief   Get a address from keyboard and display a record with input address.
     * @pre     Add data.
     * @post    Print a record.
     * @return  Return 1 if this function works well,
     *          Oterwise return 0.
     */
    int SearchAllContentByAddress(ItemType& data);

    /**
     * @brief   Display all records in the list in screen.
     * @pre     None.
     * @post    None.
     */
    void DisplayAllContent();

    /**
     * @brief	Open a file by file descriptor as an input file.
     * @pre     a file for reading is exist
     * @post    open the file for reading
     * @param   fileName    a filename to open for reading.
     * @return return 1 if this funcion works well,
     *          oterwise return 0.
     */
    int OpenInFile(char* fileName);

	/**
     * @brief	Open a file by file descriptor as an output file.
     * @pre	    list should be initialized.
     * @post	open the file for writing.
     * @param	fileName	a filename to open for writing.
     * @return	return 1 if this function works well,
     *          otherwise return 0.
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
     * @pre	    The file is not opened.
     * @post	the list is stored in the output file.
     * @return	return 1 if this function works well,
     *          otherwise return 0.
     */
    int WriteDataToFile();
};
