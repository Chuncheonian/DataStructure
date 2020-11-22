#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Main Item Type.
#include "MultimediaContent.h"

// Favorite Item Type.
#include "FavoritePhotoContent.h"
#include "FavoriteVideoContent.h"

// Specific Item Type.
#include "CharacterContent.h"
#include "LocationContent.h"
#include "EventContent.h"

// Data Structure.
#include "UnsortedList.h"
#include "SortedList.h"
#include "SortedSinglyLinkedList.h"
#include "SortedDoublyLinkedList.h"

#define FILENAMESIZE 1024

// Application Class for item management simply.
class Application {
private:
	ifstream									m_inFile;				// input file descriptor.
	ofstream									m_outFile;				// output file descriptor.
	int											m_command;				// current command number.

	SortedDoublyLinkedList<MultimediaContent>	m_masterList;			// Multimedia Content List.
	
	SortedList<FavoritePhotoContent>			m_favoritePhotoList;	// Favorite Photo Content List.
	SortedList<FavoriteVideoContent>			m_favoriteVideoList;	// Favorite Video Content List.

	SortedSinglyLinkedList<CharacterContent>	m_characterList;		// Character Content List.
	SortedSinglyLinkedList<LocationContent>		m_locationList;			// Location Content List.
	SortedSinglyLinkedList<EventContent>		m_eventList;			// Event Content List.
	
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
	 * @brief   Display command on screen and Get a input from keyboard.
	 * @pre     None.
	 * @post    None.
	 * @return  User's command.
	 */
	int GetCommand();


	//  @@ Multi-Content Functions @@

	/**
	 * @brief   Add new record into masterList.
	 * @pre     masterList should be initialized.
	 * @post    new record is added into the masterlist, and
	 * 			If new event name is input, It is added to the eventList with Primary Key of MC, else If it already exists, add the Primary Key of MC to the eventList.
	 * 			If new character is input, It is added to the characterList with Primary Key of MC, else If it already exists, add the Primary Key of MC to the characterList.
	 *			If new location is input, It is added to the locationList with Primary Key of MC, else If it already exists, add the Primary Key of MC to the locationList.
	 * @return  return 1 if this function works well,
	 *          oterwise return 0.
	 */
	int AddContents();

	/**
	 * @brief   Get a createTime from keyboard and delete the rocord with same create Time.
	 * @pre     masterList should be initialized.
	 * @post    Record is deleted into the list, and
	 * 			Delete CreateTime (Primary Key of MC) into createTime List in eventList, and
	 * 			Delete CreateTime (Primary Key of MC) into createTime List in characterList, and
	 * 			Delete CreateTime (Primary Key of MC) into createTime List in locationList, and
	 * 			If delete record exists favoritePhotoList or favoriteVideoList, It is deleted to the corresponding List.
	 * @return  return 1 if this function works well,
	 *          oterwise return 0.
	 */
	int DeleteContents();

	/**
	 * @brief   Get a record from keyboard and Replace the rocord with same record.
	 * @pre     masterList should be initialized.
	 * @post    Record is replaced into the list.
	 * @return  Return 1 if this function works well,
	 *          Oterwise return 0.
	 */
	int ReplaceContents();

	/**
	 * @brief   Get a create time from keyboard and Display a record with input create time.
	 * @pre     masterList should be initialized.
	 * @post    None.
	 */
	void RetrieveContents();

	/**
	 * @brief   Display all MultimediaContents in the list in screen.
	 * @pre     None.
	 * @post    None.
	 */
	void DisplayAllContents();

	/**
	 * @brief   Make all list empty.
	 * @pre     None.
	 * @post    Clear all list.
	 */
	void MakeEmpty();

	/**
	 * @brief	Open a file by file descriptor as an input file.
	 * @pre     a file for reading is exist
	 * @post    Open the file for reading
	 * @param   fileName    a filename to open for reading.
	 * @return  Return 1 if this funcion works well,
	 *          Oterwise return 0.
	 */
	int OpenInFile(char *fileName);

	/**
	 * @brief	Open a file by file descriptor as an output file.
	 * @pre	    List should be initialized.
	 * @post	Open the file for writing.
	 * @param	fileName	a filename to open for writing.
	 * @return	Return 1 if this function works well, otherwise 0.
	 */   
	int OpenOutFile(char *fileName);

	/**
	 * @brief	Open a file as a read mode, Read all data on the file, and Set list by the data.
	 * @pre	    The file is not opened.
	 * @post	List holds all records from the file.
	 * @return	Return 1 if this function works well,
	 *          Otherwise return 0.
	 */
	int ReadDataFromFile();

	/**
	 * @brief	Open a file as a write mode, and Write all data into the file,
	 * @pre	    The file is not opened.
	 * @post	The list is stored in the output file.
	 * @return	Return 1 if this function works well,
	 *          Otherwise return 0.
	 */
	int WriteDataToFile();


	//  @@ Favorite-Content Functions @@

	/**
	 * @brief   Check if record is a picture or video and Add new record into corresponding list (FavoritePhotoList or FavoriteVideoList).
	 * @pre     List should be initialized.
	 * @post    New record is added into the corresponding list (FavoritePhotoList or FavoriteVideoList).
	 * @return  Return 1 if this function works well, Oterwise return 0.
	 */
	int AddFavoriteContent();

	/**
	 * @brief   Get a create time from keyboard and Delete the rocord with same create time.
	 * @pre     List should be initialized.
	 * @post    record is deleted into the corresponding list.
	 * @return  Return 1 if this function works well, Oterwise return 0.
	 */
	int DeleteFavoriteContent();

	/**
	 * @brief   Get the list want to see from keyboard and Display all records in the corresponding list in screen.
	 * @pre     None.
	 * @post    None.
	 */
	void DisplayAllFavoriteContent();

	/**
	 * @brief   Display detail information of the specific record in screen.
	 * @pre     MultimediaContent and FavoriteContent both should be initialized.
	 * @post    None.
	 */
	void DisplayDetailFC();
	
	/**
	 * @brief	Get the condition by keyboard and Rearrange order of FavoriteContent elements.
	 * @pre		List should be initialized.
	 * @post	FavoriteList changes the order of elements.
	 */
	void RearrangeFC();


	//  @@ Character Functions @@

	/**
	 * @brief	Display all Character record in the list on screen.
	 * @pre     None.
	 * @post	None.
	 */
	void DisplayAllCharacter();

	/**
	 * @brief	Add CreateTime into CreateTime List of CharacterContent.
	 * @pre		masterList and characterList should be initialized.
	 * @post	new createTime is added into CreateTime List of CharacterContent.
	 */
	void AddCharacter(MultimediaContent& _mainContent);

	/**
	 * @brief	Search createTime from Location Record and Get detail content records.
	 * @pre		masterList and characterList should be initialized.
	 * @post	Display detail content Records.
	 */
	void SearchMCFromCharacter();

	/**
	 * @brief	Delete createTime into CreateTime List of CharacterContent.
	 * @pre		List should be not empty.
	 * @post	createTime is deleted into the CreateTime List of CharacterContent.
	 */
	void DeleteMCFromCharacter(MultimediaContent& _mainContent);


	// //  @@ Location Functions @@

	/**
	 * @brief	Display all Location record in the list on screen.
	 * @pre     None.
	 * @post	None.
	 */
	void DisplayAllLocation();

	/**
	 * @brief	Add CreateTime into CreateTime List of LocationContent.
	 * @pre		masterList and locationList should be initialized.
	 * @post	new createTime is added into CreateTime List of LocationContent.
	 */
	void AddLocation(MultimediaContent& _mainContent);

	/**
	 * @brief	Search createTime from Location Record and Get detail content records.
	 * @pre		masterList and locationList should be initialized.
	 * @post	Display detail content Records.
	 */
	void SearchMCFromLocation();

	/**
	 * @brief	Delete createTime into CreateTime List of LocationContent.
	 * @pre		List should be not empty.
	 * @post	createTime is deleted into the CreateTime List of LocationContent.
	 */
	void DeleteMCFromLocation(MultimediaContent& _mainContent);


	//  @@ Event Functions @@

	/**
	 * @brief	Display all Event record in the list on screen.
	 * @pre     None.
	 * @post	None.
	 */
	void DisplayAllEvent();

	/**
	 * @brief	Add CreateTime into CreateTime List of EventContent.
	 * @pre		masterList and eventList should be initialized.
	 * @post	new createTime is added into CreateTime List of EventContents.
	 */
	void AddEvent(MultimediaContent& _mainContent);

	/**
	 * @brief	Search createTime from Event Record and Get detail content records.
	 * @pre		masterList and eventList should be initialized.
	 * @post	Display detail content Records.
	 */
	void SearchMCFromEvent();

	/**
	 * @brief	Delete createTime into CreateTime List of EventContents.
	 * @pre		List should be not empty.
	 * @post	createTime is deleted into the CreateTime List of EventContents.
	 */
	void DeleteMCFromEvent(MultimediaContent& _mainContent);


	//	Search content by combining one or more keys

	/**
	 * @brief	Search MultiContent Record by combining one or more Primary KEYs.
	 * @pre		masterList and characterList and locationList and eventList should be initialized.
	 * @post	Display detail content Records.
	 */
	void SearchMCFromPks();

	/**
	 * @brief	Search MultiContent Record with PK of Character Class
	 * @pre		masterList and characterList and locationList and eventList should be initialized.
	 * @post	return List with MultiContent Record with PK of Character Class.
     * @return  Return 1, the function is well, otherwise Return 0.
	 */
	bool searchKeyFromCharacter(MultimediaContent& _mc, SortedSinglyLinkedList<MultimediaContent>& _mcList, bool _condition);

	/**
	 * @brief	Search MultiContent Record with PK of Location Class
	 * @pre		masterList and characterList and locationList and eventList should be initialized.
	 * @post	return List with MultiContent Record with PK of Location Class.
     * @return  Return 1, the function is well, otherwise Return 0.
	 */
	bool searchKeyFromLocation(MultimediaContent& _mc, SortedSinglyLinkedList<MultimediaContent>& _mcList, bool _condition);

	/**
	 * @brief	Search MultiContent Record with PK of Event Class
	 * @pre		masterList and characterList and locationList and eventList should be initialized.
	 * @post	return List with MultiContent Record with PK of Event Class.
     * @return  Return 1, the function is well, otherwise Return 0.
	 */
	bool searchKeyFromEvent(MultimediaContent& _mc, SortedSinglyLinkedList<MultimediaContent>& _mcList, bool _condition);
};