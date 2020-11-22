#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Relation between two items.
enum RelationType {LESS, GREATER, EQUAL};

// item information class
class ItemType {
protected:
    string contentName;       // content file Name
    int contentType;       // content type
    string createTime;       // content creation date and time
    string character;     // character included in the content
    string eventName;       // event name
public:
    /**
     * @brief   default constructor
     */
    ItemType() {
        contentName = "";
        contentType = -1;
        createTime = "";
        character = "";
        eventName = "";
    }

    /**
     * @brief   default destructor.
     */
    ~ItemType() {}

    /**
	 * @brief	Get content file name
	 * @pre	content file name is set
	 * @post	none
	 * @return content file name
	 */
    string GetName() const { return contentName; }

	/**
	 * @brief	Get content type
	 * @pre	content type is set
	 * @post	none
	 * @return content type
	 */
    int GetType() const { return contentType; }

	/**
	 * @brief	Get content creation date and time
	 * @pre		content creation date and time is set
	 * @post	none
	 * @return 	content creation date and time
    */
    string GetTime() const { return createTime; }

	/**
	 * @brief	Get character included in the content
	 * @pre		character included in the content is set
	 * @post	none
	 * @return 	character included in the content
	 */
    string GetCharacter() const { return character; }

	/**
	 * @brief	Get event name
	 * @pre		event name is set
	 * @post	none
	 * @return 	event name
	 */
    string GetEventName() const { return eventName; }

	/**
	 * @brief	Set content file name.
	 * @pre		none.
	 * @post	content file name is set.
	 * @param	_name	content file name.
	 */
    void SetName(string _name) { contentName = _name; }

	/**
	 * @brief	Set content type
	 * @pre		none.
	 * @post	content type is set.
	 * @param	_type	content type
	 */
    void SetType(int _type) { contentType = _type; }

	/**
	 * @brief	Set content creation date and time
	 * @pre		none.
	 * @post	content creation date and time is set.
	 * @param	_time	content creation date and time
	 */
    void SetTime(string _time) { createTime = _time; }

	/**
	 * @brief	Set character included in the content
	 * @pre		none.
	 * @post	character included in the content is set.
	 * @param	_character	character included in the content
	 */
    void SetCharacter(string _character) { character = _character; }

	/**
	 * @brief	Set event name.
	 * @pre		none.
	 * @post	event name is set.
	 * @param	_eventName	event name
	 */
    void SetEventName(string _eventName) { eventName = _eventName; }

	/**
	 * @brief	Set content record.
	 * @pre		none.
	 * @post	content recort is set.
	 * @param	_name	content file Name
	 * @param	_type	content type
	 * @param	_time	content creation date and time
	 * @param	_character	character included in the content
	 * @param	_eventName	event name
	 */ 
    void SetRecord(string _name, int _type, string _time, string _character, string _eventName) {
        SetName(_name);
        SetType(_type);
        SetTime(_time);
        SetCharacter(_character);
        SetEventName(_eventName);
    }

	/**
	 * @brief	Display content name on screen.
	 * @pre		content name is set.
	 * @post	content name is on screen.
	 */ 
    void DisplayNameOnScreen() { cout << "\tName   : " << contentName; }

	/**
	 * @brief	Display content type on screen
	 * @pre	content type is set
	 * @post	content type is on screen
	 */
	void DisplayTypeOnScreen() { cout << "\tType : " << contentType; }

	/**
	 * @brief	Display content creation date and time on screen.
	 * @pre	content creation date and time are set.
	 * @post	content creation date and time are on screen.
	 */
	void DisplayTimeOnScreen() { cout << "\tTime : " << createTime; }
    
	/**
	 * @brief	Display character included in the content on screen
	 * @pre		character included in the content is set.
	 * @post	character included in the content is on screen.
	 */
    void DisplayCharacterOnScreen() { cout << "\tCharacter : " << character; }

	/**
	 * @brief	Display  eventName name on screen
	 * @pre		eventName name is set.
	 * @post	eventName name is on screen
	 */
    void DisplayEventNameOnScreen() { cout << "\tEvent name : " << eventName; }

	/**
	 * @brief	Display an content record on screen.
	 * @pre	content record is set.
	 * @post	content record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnScreen();
		DisplayTypeOnScreen();
		DisplayTimeOnScreen();
        DisplayCharacterOnScreen();
        DisplayEventNameOnScreen();
		cout << endl;
	}

	/**
	 * @brief	Set content name from keyboard.
	 * @pre		none.
	 * @post	content name is set.
	 */
    void SetNameFromKB();

	/**
	 * @brief	Set content type from keyboard.
	 * @pre		none.
	 * @post	content type is set.
	 */
    void SetTypeFromKB();

	/**
	 * @brief	Set content creation date and time from keyboard.
	 * @pre		none.
	 * @post	content creation date and time are set.
	 */	
    void SetTimeFromKB();

	/**
	 * @brief	Set character included in the content from keyboard.
	 * @pre		none.
	 * @post	character included in the content is set.
	 */	
    void SetCharacterFromKB();

	/**
	 * @brief	Set event name from keyboard.
	 * @pre		none.
	 * @post	event name is set.
	 */	
    void SetEventNameFromKB();

	/**
	 * @brief	Set content record from keyboard.
	 * @pre		none.
	 * @post	content record is set.
	 */	
    void SetRecordFromKB();

	/**
	 * @brief	Read a record from file.
	 * @pre		the target file is opened.
	 * @post	content record is set
	 * @param	fin	file descriptor.
	 * @return	return 1 if this function works well,
	 * 			otherwise return 0.
	 */ 
    int ReadDataFromFile(ifstream& fin);

	/**
	 * @brief	Write a record into file.
	 * @pre	the target file is opened. And the list should be initialized.
	 * @post	the target file is included the new student record.
	 * @param	fout	file descriptor.
	 * @return	return 1 if this function works well,
	 * 			otherwise return 0.
	 */
    int WriteDataToFile(ofstream& fout);

	/**
	 * @brief	Compare two Itemtypes by content name
	 * @pre		two Itemtypes should be initialized.
	 * @post	the taerget file is included the new content record.
	 * @param	data	target item for comparing.
	 * @return	return LESS if this->contentName < data->contentName,
	 * 			return GREATER if this->contentName > data->contentName,
	 * 			oterwise return EQUAL.
	 */
    RelationType CompareByName(const ItemType& data);

	/**
	 * @brief	Compare content name in two Itemtype class
	 * @pre		two Itemtype class should be initialized.
	 * @post	none.
	 * @param	data	target Itemtype for comparing.	
	 * @return	return true if this->contentName == data->contentName,
	 * 			otherwise return false.
	 */
    bool operator==(const ItemType& data) {
        if (contentName == data.contentName)
            return true;
        else
            return false;
    }

	/**
	 * @brief	Assign content record to another.
	 * @pre		right ItemType class should be initialized.
	 * @post	content record in left ItemType class is set.
	 * @param	data	target ItemType for assigning.
	 */
    void operator=(const ItemType& data) {
        contentName = data.contentName;
        contentType = data.contentType;
        createTime = data.createTime;
        character = data.character;
        eventName = data.eventName;
    }
};