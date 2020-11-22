#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// item information class
class MultimediaContent {
protected:
    string		m_contentName;			// content file name
    int			m_contentType;			// content type
    string		m_createTime;			// content creation date and time
    string		m_character;			// character included in the content
    int			m_contentCategory;		// content category 
    string		m_eventName;			// event name
	string		m_eventDescription;		// event description
    string		m_contents;				// contents

public:
	// default constructor.
    MultimediaContent() {
        m_contentName = "";
        m_contentType = 0;
        m_createTime = "";
        m_character = "";
        m_contentCategory = 0;
        m_eventName = "";
		m_eventDescription = "";
        m_contents = "";
    }

	// default destructor.
    ~MultimediaContent() {}

    /**
	 * @brief	Get content file name
	 * @pre		content file name is set
	 * @post	none
	 * @return 	content file name
	 */
    string GetName() const { return m_contentName; }

    /**
	 * @brief	Get content type
	 * @pre		content type is set
	 * @post	none
	 * @return	content type
	 */
    int GetType() const { return m_contentType; }

	/**
	 * @brief	Get content creation date and time
	 * @pre		content creation date and time is set
	 * @post	none
	 * @return	content creation date and time
	 */   
    string GetTime() const { return m_createTime; }

	/**
	  * @brief	Get character included in the content
	  * @pre	character included in the content is set
	  * @post	none
	  * @return character included in the content
	  */  
    string GetCharacter() const { return m_character; }

    /**
	 * @brief	Get content category
	 * @pre		content category is set
	 * @post	none
	 *  @return content category
    */
    int GetCategory() const { return m_contentCategory; }

    /**
	 * @brief	Get event name
	 * @pre		event name is set
	 * @post	none
	 * @return	event name
	 */   
    string GetEventName() const { return m_eventName; }

    /**
     * @brief	Get event description
     * @pre	    event description is set
     * @post	none
     * @return  event description
     */
    string GetEventDescription() const { return m_eventDescription; }

	/**
	 * @brief	Get contents
	 * @pre		contents is set
	 * @post	none
	 * @return 	contents
	 */
    string GetContents() const { return m_contents; }

	/**
	 * @brief	Set content file name.
	 * @pre		none.
	 * @post	content file name is set.
	 * @param	_contentName	content file name.
	 */
    void SetName(string _contentName) { m_contentName = _contentName; }

	/**
	 * @brief	Set content type
	 * @pre		none.
	 * @post	content type is set.
	 * @param	_contentType	content type
	 */
    void SetType(int _contentType) { m_contentType = _contentType; }

	/**
	 * @brief	Set content creation date and time
	 * @pre		none.
	 * @post	content creation date and time is set.
	 * @param	_createTime	content creation date and time
	 */
    void SetTime(string _createTime) { m_createTime = _createTime; }

	/**
	 * @brief	Set character included in the content
	 * @pre		none.
	 * @post	character included in the content is set.
	 * @param	_character		character included in the content
	 */
    void SetCharacter(string _character) { m_character = _character; }

	/**
	 * @brief	Set content category
	 * @pre		none.
	 * @post	content category is set.
	 * @param	_contentCategory	content category
	 */
    void SetCategory(int _contentCategory) { m_contentCategory = _contentCategory; }

	/**
	 * @brief	Set event name.
	 * @pre		none.
	 * @post	event name is set.
	 * @param	_eventName	event name
	 */    
    void SetEventName(string _eventName) { m_eventName = _eventName; }

	/**
	 * @brief	Set event description
	 * @pre		none.
	 * @post	event description is set.
	 * @param	_eventDescription	event description
	 */
    void SetEventDescription(string _eventDescription) { m_eventDescription = _eventDescription; }

 	/**
	 * @brief	Set m_contents
	 * @pre		m_contentName, m_contentType, m_createTime, m_character, m_contentCategory, m_eventName are set.
	 * @post	m_contents is set.
	 */      
    void SetContents() {
        m_contents = m_contentName + " " + to_string(m_contentType) + " " + m_createTime + " " + m_character + " " + to_string(m_contentCategory) + " " + m_eventName;
    }

    /**
	 * @brief	Set content record.
	 * @pre		none.
	 * @post	content record is set.
	 * @param	_contentName	    content file Name
	 * @param	_contentType	    content type
	 * @param	_createTime			content creation date and time
	 * @param	_character			character included in the content
     * @param   _contentCategory    content category
	 * @param	_eventName			event name
	 * @param	_eventDescription	event description
	 */ 
    void SetRecord(string _contentName, int _contentType, string _createTime, string _character, int _contentCategory, string _eventName, string _eventDescription) {
        SetName(_contentName);
        SetType(_contentType);
        SetTime(_createTime);
        SetCharacter(_character);
        SetCategory(_contentCategory);
        SetEventName(_eventName);
		SetEventDescription(_eventDescription);
        SetContents();
    }

	/**
	 * @brief	Display content name on screen.
	 * @pre		content name is set.
	 * @post	content name is on screen.
	 */ 
    void DisplayNameOnscreen() { cout << "\tContent Name: " << m_contentName; }

	/**
	*	@brief	Display content type on screen
	*	@pre	content type is set
	*	@post	content type is on screen
	*/
    void DisplayTypeOnscreen() { cout << "\tContent Type: " << m_contentType; }

	/**
	*	@brief	Display content creation date and time on screen.
	*	@pre	content creation date and time are set.
	*	@post	content creation date and time are on screen.
	*/    
    void DisplayTimeOnscreen() { cout << "\tContent create Time: " << m_createTime; }

	/**
	 * @brief	Display character included in the content on screen
	 * @pre		character included in the content is set.
	 * @post	character included in the content is on screen.
	 */
    void DisplayCharacterOnscreen() { cout << "\tContent character: " << m_character; }

	/**
	 * @brief	Display content category on screen
	 * @pre		content category is set.
	 * @post	content category is on screen
	 */
    void DisplayCategoryOnscreen() { cout << "\tContent category: " << m_contentCategory; }

	/**
	 * @brief	Display event name on screen
	 * @pre		event name is set.
	 * @post	event name is on screen
	 */
    void DisplayEventNameOnscreen() { cout << "\tEvent name: " << m_eventName; }

	/**
     * @brief	Display event description on screen
     * @pre		event description is set
     * @post	event description is on screen
     */
    void DisplayEventDescriptionOnscreen() { cout << "\tEvent description: " << m_eventDescription; }

	/**
	 * @brief	Display contents on screen
	 * @pre		contents is set.
	 * @post	contents is on screen
	 */
    void DisplayContentsOnscreen() { cout << "\tContents: " << m_contents; }
    
    /**
	 * @brief	Display a content record on screen.
	 * @pre		content record is set.
	 * @post	content record is on screen.
	 */
    void DisplayRecordOnScreen() {
        DisplayNameOnscreen();
        DisplayTypeOnscreen();
        DisplayTimeOnscreen();
        DisplayCharacterOnscreen();
        DisplayCategoryOnscreen();
        DisplayEventNameOnscreen();
		DisplayEventDescriptionOnscreen();
        DisplayContentsOnscreen();

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
	  * @pre	none.
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
	 * @brief	Set content category from keyboard.
	 * @pre		none.
	 * @post	content category is set.
	 */	
    void SetCategoryFromKB();

	/**
	 * @brief	Set event name from keyboard.
	 * @pre		none.
	 * @post	event name is set.
	 */	
    void SetEventNameFromKB();

 	/**
      * @brief	Set event description from keyboard.
      * @pre	none.
      * @post	event description is set.
      */ 
    void SetEventDescriptionFromKB();

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
	 * @return	return 1 if this function works well, otherwise 0.
	 */ 
    int ReadDataFromFile(ifstream& fin);

	/**
	 * @brief	Write a record into file.
	 * @pre		the target file is opened. And the list should be initialized.
	 * @post	the target file is included the new student record.
	 * @param	fout	file descriptor.
	 * @return	return 1 if this function works well, otherwise 0.
	 */
    int WriteDataToFile(ofstream& fout);

	/**
	 * @brief	Compare content name in two MultimediaContent class
	 * @pre		two MultimediaContent class should be initialized.
	 * @post	none.
	 * @param	data	target MultimediaContent for comparing.	
	 * @return	return true if this->m_contentName == data->m_contentName,
	 * 			otherwise return false.
	 */    
    bool operator==(const MultimediaContent& data) {
        if (m_contentName == data.m_contentName)
            return true;
        else
            return false;
    }

	/**
	 * @brief	Assign content record to another.
	 * @pre		right MultimediaContent class should be initialized.
	 * @post	content record in left MultimediaContent class is set.
	 * @param	data	target MultimediaContent for assigning.
	 */
    void operator=(const MultimediaContent& data) {
        m_contentName = data.m_contentName;
        m_contentType = data.m_contentType;
        m_createTime = data.m_createTime;
        m_character = data.m_character;
        m_contentCategory = data.m_contentCategory;
        m_eventName = data.m_eventName;
		m_eventDescription = data.m_eventDescription;
        m_contents = data.m_contents;
	}

	/**
	 * @brief	Print record.
	 * @pre		MultimediaContent class should be initialized.
	 * @post	content record is on screen.
     * @param	cout	ostream instance
	 * @param	_item	target MultimediaContent for printing.
	 */
	friend ostream& operator<<(ostream& cout, const MultimediaContent& _item) {
		cout << "\t[ Content name: " << _item.m_contentName;
		cout << ", Content type: " << _item.m_contentType;
		cout << ", Create time: " << _item.m_createTime;
		cout << ", Character: " << _item.m_character;
		cout << ", Content category: " << _item.m_contentCategory;
		cout << ", Event name: " << _item.m_eventName;
		cout << ", Event description: " << _item.m_eventDescription;
		cout << ", Contents: " << _item.m_contents << " ]";

		return cout;
	}

	/**
	 * @brief	Input record.
	 * @pre		none.
	 * @post	content record is initialized.
     * @param	cin	    istream instance
	 * @param	_item	target MultimediaContent for Input.
	 */
	friend istream& operator>>(istream& cin, MultimediaContent& _item) {
		cout << "\n\tEnter content name: ";
		cin >> _item.m_contentName;
    	cout << "\tEnter content type(ex> 1:Photo, 2:Panorama, 3: Video):";
		cin >> _item.m_contentType;
    	cout << "\tEnter create time: ";
		cin >> _item.m_createTime;
		cout << "\tEnter character: ";
		cin >> _item.m_character;
		cout << "\tEnter content category(ex> 1:Portrait, 2:Location, 3: Video): ";
		cin >> _item.m_contentCategory;
		cout << "\tEnter event name: ";
		cin >> _item.m_eventName;
		cout << "\tEnter event description: ";
		cin >> _item.m_eventDescription;

		_item.SetContents();
		return cin;
	}
};