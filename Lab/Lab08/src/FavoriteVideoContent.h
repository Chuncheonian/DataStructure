#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"

// Favorite Video Content information class
class FavoriteVideoContent {
protected:
	string  m_contentName;      // content name
	string  m_createTime;       // content creation date and time
	string  m_character;        // character included in the content
	string  m_location;         // location included in the content.
	string  m_eventName;        // event name

	int		m_condition;		// Member Variable for Rearranging all record of FavoritVideoList. (1. createTime, 2. contentName, 3. viewNumber)
	int		m_viewNumber;		// view number.

public:
	// default constructor.
	FavoriteVideoContent() {
		m_contentName = "";
		m_createTime = "";
		m_character = "";
		m_location = "";
		m_eventName = "";
		m_condition = 1;
		m_viewNumber = 1;
	}

	FavoriteVideoContent(MultimediaContent& _mc) {
		SetName(_mc.GetName());
		SetTime(_mc.GetTime());
		SetCharacter(_mc.GetCharacter());
		SetLocation(_mc.GetLocation());
		SetEventName(_mc.GetEventName());
		m_condition = 1;
		m_viewNumber = 1;
	}

	// default destructor.
	~FavoriteVideoContent() {}

	/**
	 * @brief	Get content file name
	 * @pre 	Content file name is set
	 * @post	None
	 * @return  Content file name
	 */
	string GetName() const { return m_contentName; }

	/**
	 * @brief	Get content creation date and time
	 * @pre	    Content creation date and time is set
	 * @post	None.
	 * @return  Content creation date and time
	 */  
	string GetTime() const { return m_createTime; }

	/**
	  * @brief	Get character included in the content
	  * @pre	Character included in the content is set
	  * @post	None.
	  * @return Character included in the content
	  */  
	string GetCharacter() const { return m_character; }

	/**
	  * @brief	Get location included in the content
	  * @pre	location included in the content is set
	  * @post	None.
	  * @return location included in the content
	  */  
	string GetLocation() const { return m_character; }

	/**
	 * @brief	Get event name
	 * @pre		Event name is set
	 * @post	None.
	 * @return	Event name
	 */   
	string GetEventName() const { return m_eventName; }

	/**
	 * @brief	Get condition.
	 * @pre		Condition is set
	 * @post	None.
	 * @return	Condition
	 */   
	int GetCondition() const { return m_condition; }

	/**
	 * @brief	Get number of view.
	 * @pre		Number of view is set
	 * @post	None.
	 * @return	Number of view
	 */   
	int GetViewNumber() const { return m_viewNumber; }

	/**
	 * @brief	Set content file name.
	 * @pre		none.
	 * @post	content file name is set.
	 * @param	_contentName	content file name.
	 */
	void SetName(string _contentName) { m_contentName = _contentName; }

	/**
	 * @brief	Set content creation date and time
	 * @pre		none.
	 * @post	content creation date and time is set.
	 * @param	_createTime	content creation date and time
	 */
	void SetTime(string _createTime) { m_createTime = _createTime; }

	/**
	 * @brief	Set character included in the content
	 * @pre		None.
	 * @post	Character included in the content is set.
	 * @param	_character	cCaracter included in the content
	 */
	void SetCharacter(string _character) { m_character = _character; }

	/**
	 * @brief	Set location included in the content
	 * @pre		None.
	 * @post	Location included in the content is set.
	 * @param	_location	Location included in the content
	 */
	void SetLocation(string _location) { m_location = _location; }

	/**
	 * @brief	Set event name.
	 * @pre		None.
	 * @post	Event name is set.
	 * @param	_eventName	event name
	 */    
	void SetEventName(string _eventName) { m_eventName = _eventName; }

	/**
	 * @brief	Set Member Variable for Rearranging.
	 * @pre		None.
	 * @post	Condition is set.
	 * @param	_condition	Member Variable for Rearranging.
	 */    
	void SetCondition(int _condition) { m_condition = _condition; }

	/**
	 * @brief	Set Number of View.
	 * @pre		None.
	 * @post	Number of View is set.
	 * @param	_viewNumber	Number of View.
	 */    
	void SetViewNumber(int _viewNumber) { m_viewNumber = _viewNumber; }

	/**
	 * @brief	Set content record.
	 * @pre		None.
	 * @post	Content record is set.
	 * @param	_contentName    content file Name
	 * @param	_createTime     content creation date and time
	 * @param	_character      character included in the content
	 * @param	_location		location included in the content
	 * @param	_eventName		event name
	 * @param	_condition		Member Variable for Rearranging
	 * @param	_viewNumber		Number of View
	 */ 
	void SetRecord(string _contentName, string _createTime, string _character, string _location, string _eventName, int _condition, int _viewNumber) {
		SetName(_contentName);
		SetTime(_createTime);
		SetCharacter(_character);
		SetLocation(_location);
		SetEventName(_eventName);
		SetCondition(_condition);
		SetViewNumber(_viewNumber);
	}

	/**
	 * @brief	Set content record.
	 * @pre		None.
	 * @post	Content record is set.
	 * @param	_mc    MultimediaContent instance
	 */ 
	void SetRecordMC(MultimediaContent& _mc) {
		SetName(_mc.GetName());
		SetTime(_mc.GetTime());
		SetCharacter(_mc.GetCharacter());
		SetLocation(_mc.GetLocation());
		SetEventName(_mc.GetEventName());
	}

	/**
	 * @brief	Display content name on screen.
	 * @pre		content name is set.
	 * @post	content name is on screen.
	 */ 
	void DisplayNameOnscreen() { cout << "\tContent Name: " << m_contentName; }

	/**
	 * @brief	Display content creation date and time on screen.
	 * @pre	    content creation date and time are set.
	 * @post	content creation date and time are on screen.
	 */   
	void DisplayTimeOnscreen() { cout << "\tContent create Time: " << m_createTime; }

	/**
	 * @brief	Display character included in the content on screen
	 * @pre		character included in the content is set.
	 * @post	character included in the content is on screen.
	 */
    void DisplayCharacterOnscreen() { cout << "\tContent character: " << m_character; }

	/**
	 * @brief	Display location included in the content on screen
	 * @pre		location included in the content is set.
	 * @post	location included in the content is on screen.
	 */
    void DisplayLocationOnscreen() { cout << "\tContent location: " << m_location; }

	/**
	 * @brief	Display event name on screen
	 * @pre		event name is set.
	 * @post	event name is on screen
	 */
    void DisplayEventNameOnscreen() { cout << "\tEvent name: " << m_eventName; }

	/**
	 * @brief	Display condition on screen
	 * @pre		Condition is set.
	 * @post	Condition is on screen.
	 */
    void DisplayConditionOnscreen() { cout << "\tCondition(1. createTime, 2. contentName, 3. viewNumber): " << m_condition; }

	/**
	 * @brief	Display Number of View on screen
	 * @pre		Number of View is set.
	 * @post	Number of View is on screen
	 */
    void DisplayViewOfNumberOnscreen() { cout << "\tNumber of view: " << m_viewNumber; }

	/**
	 * @brief	Display a content record on screen.
	 * @pre 	content record is set.
	 * @post	content record is on screen.
	 */
	void DisplayRecordOnScreen() {
		DisplayNameOnscreen();
		DisplayTimeOnscreen();
		DisplayCharacterOnscreen();
		DisplayLocationOnscreen();
		DisplayEventNameOnscreen();
		DisplayConditionOnscreen();
		DisplayViewOfNumberOnscreen();

		cout << endl;
	}

	/**
	 * @brief	Set content name from keyboard.
	 * @pre 	None.
	 * @post	content name is set.
	 */  
	void SetNameFromKB();

	/**
	 * @brief	Set content creation date and time from keyboard.
	 * @pre 	None.
	 * @post	content creation date and time are set.
	 */	
	void SetTimeFromKB();

	/**
	 * @brief	Set character included in the content from keyboard.
	 * @pre		None.
	 * @post	character included in the content is set.
	 */	
    void SetCharacterFromKB();

	/**
	 * @brief	Set location included in the content from keyboard.
	 * @pre		None.
	 * @post	Location included in the content is set.
	 */	
    void SetLocationFromKB();

	/**
	 * @brief	Set event name from keyboard.
	 * @pre		None.
	 * @post	event name is set.
	 */	
    void SetEventNameFromKB();

	/**
	 * @brief	Set condition from keyboard.
	 * @pre		None.
	 * @post	condition is set.
	 */	
    void SetConditionFromKB();

	/**
	 * @brief	Set content record from keyboard.
	 * @pre	    None.
	 * @post	content record is set.
	 */	
	void SetRecordFromKB();

	/**
	 * @brief	Assign content record to another.
	 * @pre		right FavoriteVideoContent class should be initialized.
	 * @post	content record in left FavoriteVideoContent class is set.
	 * @param	_data	target FavoriteVideoContent for assigning.
	 */
	void operator=(const FavoriteVideoContent& _data);

	/**
	 * @brief	Compare corresponding condition in two FavoriteVideoContent class
	 * @pre		Two FavoriteVideoContent class should be initialized.
	 * @post	None.
	 * @param	_data	target FavoriteVideoContent for comparing.	
	 * @return	Return true If Two member variables corresponding Condition are the same, Otherwise return false.
	 */    
	bool operator==(const FavoriteVideoContent& _data);

	/**
	 * @brief	Compare two FavoriteVideoContent by member variable corresponding Condition.
	 * @pre	    Two FavoriteVideoContent should be initialized.
	 * @param	data	target item for comparing.
	 * @return	Return true If member variable corresponding Condition is smaller than member variable of _data, Otherwise return false.
	 */
	bool operator<(FavoriteVideoContent& _data);

	/**
	 * @brief	Compare two FavoriteVideoContent by member variable corresponding Condition.
	 * @pre	    Two FavoriteVideoContent should be initialized.
	 * @param	data	target item for comparing.
	 * @return	Return true If member variable corresponding Condition is bigger than member variable of _data, Otherwise return false.
	 */
	bool operator>(FavoriteVideoContent& _data);

	/**
	 * @brief	Print record.
	 * @pre		FavoriteVideoContent class should be initialized.
	 * @post	content record is on screen.
	 * @param	cout	ostream instance
	 * @param	_data	target FavoriteVideoContent for printing.
	 */
	friend ostream& operator<<(ostream& cout, const FavoriteVideoContent& _data) {
		cout << "\t[ Content name: " << _data.m_contentName;
		cout << ", Create time: " << _data.m_createTime;
		cout << ", Character: " << _data.m_character;
		cout << ", Location: " << _data.m_location;
		cout << ", Event name: " << _data.m_eventName;
		cout << ", Condition(1. createTime, 2. contentName, 3. viewNumber): " << _data.m_condition;
		cout << ", Number of View: " << _data.m_viewNumber << " ]";
		return cout;
	}
};