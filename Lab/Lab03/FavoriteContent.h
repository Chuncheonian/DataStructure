#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Favorite item information class
class FavoriteContent {
protected:
    string m_contentName;   // content file name
    int m_contentType;      // content type
    string m_createTime;    // content creation date and time
    int m_contentCategory;  // content category
    
public:

    // default constructor.
    FavoriteContent() {
        m_contentName = "";
        m_contentType = -1;
        m_createTime = "";
        m_contentCategory = -1;
    }

    // default destructor.
    ~FavoriteContent() {}

    /**
     * @brief	Get content file name
     * @pre 	content file name is set
     * @post	none
     * @return content file name
     */
    string GetName() const { return m_contentName; }

    /**
     * @brief	Get content type
     * @pre	    content type is set
     * @post	none
     * @return content type
     */
    int GetType() const { return m_contentType; }

	/**
     * @brief	Get content creation date and time
     * @pre	    content creation date and time is set
     * @post	none
     * @return  content creation date and time
     */  
    string GetTime() const { return m_createTime; }

    /**
     * @brief	Get content category
     * @pre	    content category is set
     * @post	none
     * @return   content category
     */
    int GetCategory() const { return m_contentCategory; }

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
	 * @brief	Set content category
	 * @pre		none.
	 * @post	content category is set.
	 * @param	_contentCategory	content category
	 */
    void SetCategory(int _contentCategory) { m_contentCategory = _contentCategory; }

    /**
	 * @brief	Set content record.
	 * @pre		none.
	 * @post	content record is set.
	 * @param	_contentName	    content file Name
	 * @param	_contentType	    content type
	 * @param	_createTime	    content creation date and time
     * @param   _contentCategory    content category
	 */ 
    void SetRecord(string _contentName, int _contentType, string _createTime, string _character, int _contentCategory, string _eventName) {
        SetName(_contentName);
        SetType(_contentType);
        SetTime(_createTime);
        SetCategory(_contentCategory);
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
     * @brief	Display content creation date and time on screen.
     * @pre	    content creation date and time are set.
     * @post	content creation date and time are on screen.
     */   
    void DisplayTimeOnscreen() { cout << "\tContent create Time: " << m_createTime; }

	/**
	 * @brief	Display content category on screen
	 * @pre		content category is set.
	 * @post	content category is on screen
	 */
    void DisplayCategoryOnscreen() { cout << "\tContent category: " << m_contentCategory; }

    /**
     * @brief	Display a content record on screen.
     * @pre 	content record is set.
     * @post	content record is on screen.
     */
    void DisplayRecordOnScreen() {
        DisplayNameOnscreen();
        DisplayTypeOnscreen();
        DisplayTimeOnscreen();
        DisplayCategoryOnscreen();
        cout << endl;
    }

	/**
     * @brief	Set content name from keyboard.
     * @pre 	none.
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
     * @pre 	none.
     * @post	content creation date and time are set.
     */	
    void SetTimeFromKB();

	/**
     * @brief	Set content category from keyboard.
     * @pre	    none.
     * @post	content category is set.
     */	
    void SetCategoryFromKB();

	/**
     * @brief	Set content record from keyboard.
     * @pre	    none.
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
     * @pre	    the target file is opened. And the list should be initialized.
     * @post	the target file is included the new student record.
     * @param	fout	file descriptor.
     * @return	return 1 if this function works well, otherwise 0.
     */
    int WriteDataToFile(ofstream& fout);

	/**
	 * @brief	Compare content name in two FavoriteContent class
	 * @pre		two FavoriteContent class should be initialized.
	 * @post	none.
	 * @param	data	target FavoriteContent for comparing.	
	 * @return	return true if this->m_contentName == data->m_contentName,
	 * 			otherwise return false.
	 */    
    bool operator==(const FavoriteContent& data) {
        if (m_contentName == data.m_contentName)
            return true;
        else
            return false;
    }

	/**
	 * @brief	Assign content record to another.
	 * @pre		right FavoriteContent class should be initialized.
	 * @post	content record in left FavoriteContent class is set.
	 * @param	data	target FavoriteContent for assigning.
	 */
    void operator=(const FavoriteContent& data) {
        m_contentName = data.m_contentName;
        m_contentType = data.m_contentType;
        m_createTime = data.m_createTime;
        m_contentCategory = data.m_contentCategory;
    }

	/**
	 * @brief	Print record.
	 * @pre		FavoriteContent class should be initialized.
	 * @post	content record is on screen.
     * @param	cout	ostream instance
	 * @param	_item	target FavoriteContent for printing.
	 */
    friend ostream& operator<<(ostream& cout, const FavoriteContent& _item) {
	    cout << "\t[ Name: " << _item.GetName() << ", Type: " << _item.GetType() << ", Create time: " << _item.GetTime() << ", Category: " << _item.GetCategory() << " ]" << endl;
	    return cout;
    }

	/**
	 * @brief	Input record.
	 * @pre		none.
	 * @post	content record is initialized.
     * @param	cin	    istream instance
	 * @param	_item	target FavoriteContent for Input.
	 */
    friend istream& operator>>(istream& cin, FavoriteContent& _item) {
	    cout << "\n\tEnter Name: ";
	    cin >> _item.m_contentName;
        cout << "\tEnter Type: ";
	    cin >> _item.m_contentType;
        cout << "\tEnter Create time: ";
	    cin >> _item.m_createTime;
        cout << "\tEnter Category: ";
	    cin >> _item.m_contentCategory;

	    return cin;
    }
};