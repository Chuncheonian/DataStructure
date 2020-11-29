#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// item information class
class MultimediaContent {
protected:
  string  m_contentName;    // content file name
  int     m_contentType;    // content type
  string  m_createTime;     // content creation date and time (Primary KEY)
  string  m_character;      // character included in the content
  string  m_location;       // location included in the content.
  string  m_eventName;      // event name
  int     m_viewNumber;     // view number.
  int     m_condition;      // Member Variable for Rearranging all record. (1. createTime, 2. contentName, 3. viewNumber)
public:
  // default constructor.
  MultimediaContent() {
    SetRecord("", 0, "", "", "", "", 0, 1);
  }

  // default destructor.
  virtual ~MultimediaContent() {}

  virtual void Play() = 0;

  virtual void Read() = 0;
  /**
   * @brief	Get content file name
   * @pre		Content file name is set
   * @post	None.
   * @return 	Content file name
   */
  string GetName() const { return m_contentName; }

  /**
   * @brief   Get content type
   * @pre     content type is set
   * @post    None
   * @return  content type
   */
  int GetType() const { return m_contentType; }

  /**
   * @brief   Get content creation date and time
   * @pre     Content creation date and time is set
   * @post    None.
   * @return  Content creation date and time
   */   
  string GetTime() const { return m_createTime; }

  /**
   * @brief   Get character included in the content
   * @pre     character included in the content is set
   * @post    None.
   * @return  character included in the content
   */
  string GetCharacter() const { return m_character; }

  /**
   * @brief   Get location included in the content
   * @pre     location included in the content is set
   * @post    None.
   * @return  location included in the content
   */  
  string GetLocation() const { return m_location; }

  /**
   * @brief   Get event name
   * @pre     Event name is set
   * @post    None
   * @return  Event name
   */
  string GetEventName() const { return m_eventName; }

  /**
   * @brief   Get view number
   * @pre     view number is set
   * @post    None
   * @return  view number
   */
  int GetView() const { return m_viewNumber; }

  /**
   * @brief   Get condition.
   * @pre     Condition is set
   * @post    None.
   * @return  Condition
   */
  int GetCondition() const { return m_condition; }

  /**
   * @brief   Set content file name.
   * @pre     None.
   * @post    Content file name is set.
   * @param   _contentName  content file name.
   */
  void SetName(string _contentName) { m_contentName = _contentName; }

  /**
   * @brief   Set content type
   * @pre     None.
   * @post    Content type is set.
   * @param _contentType  Content type
   */
  void SetType(int _contentType) { m_contentType = _contentType; }

  /**
   * @brief   Set content creation date and time
   * @pre     None.
   * @post    Content creation date and time is set.
   * @param   _createTime Creation date and time
   */
  void SetTime(string _createTime) { m_createTime = _createTime; }

  /**
   * @brief   Set character included in the content
   * @pre     None.
   * @post    Character included in the content is set.
   * @param   _character  Character included in the content
   */
  void SetCharacter(string _character) { m_character = _character; }

  /**
   * @brief   Set location included in the content
   * @pre     None.
   * @post    Location included in the content is set.
   * @param   _location Location included in the content
   */
  void SetLocation(string _location) { m_location = _location; }

  /**
   * @brief   Set event name.
   * @pre     None.
   * @post    Event name is set.
   * @param   _eventName  event name
   */
  void SetEventName(string _eventName) { m_eventName = _eventName; }

  /**
   * @brief   Set view number
   * @pre     None.
   * @post    view number is set.
   * @param   _viewNumber view number
   */
  void SetView(int _viewNumber) { m_viewNumber = _viewNumber; }

  /**
   * @brief   Set Member Variable for Rearranging.
   * @pre     None.
   * @post    Condition is set.
   * @param   _condition  Member Variable for Rearranging.
   */
  void SetCondition(int _condition) { m_condition = _condition; }

  /**
   * @brief   Set content record.
   * @pre     None.
   * @post    content record is set.
   * @param   _contentNamecontent file Name
   * @param   _contentType        content type
   * @param   _createTime         content creation date and time
   * @param   _character          character included in the content
   * @param   _location           location included in the content
   * @param   _eventName          event name
   * @param   _viewNumber         view number
   * @param   _condition      Member Variable for Rearranging.
   */
  void SetRecord(string _contentName, int _contentType, string _createTime, string _character, string _location, string _eventName, int _viewNumber, int _condition) {
    SetName(_contentName);
    SetType(_contentType);
    SetTime(_createTime);
    SetCharacter(_character);
    SetLocation(_location);
    SetEventName(_eventName);
    SetView(_viewNumber);
    SetCondition(_condition);
  }

  /**
   * @brief   Display content name on screen.
   * @pre     Content name is set.
   * @post    Content name is on screen.
   */ 
  void DisplayNameOnscreen() { cout << "\tContent Name: " << m_contentName; }

  /**
   * @brief   Display content type on screen
   * @pre     content type is set
   * @post    content type is on screen
   */
  void DisplayTypeOnscreen() { cout << "\tContent Type: " << m_contentType; }

  /**
   * @brief   Display content creation date and time on screen.
   * @pre     content creation date and time are set.
   * @post    content creation date and time are on screen.
   */
    void DisplayTimeOnscreen() { cout << "\tContent create Time: " << m_createTime; }

  /**
   * @brief   Display character included in the content on screen
   * @pre     character included in the content is set.
   * @post    character included in the content is on screen.
   */
    void DisplayCharacterOnscreen() { cout << "\tContent character: " << m_character; }

  /**
   * @brief   Display location included in the content on screen
   * @pre     location included in the content is set.
   * @post    location included in the content is on screen.
   */
  void DisplayLocationOnscreen() { cout << "\tContent location: " << m_location; }

  /**
   * @brief   Display event name on screen
   * @pre     event name is set.
   * @post    event name is on screen
   */
  void DisplayEventNameOnscreen() { cout << "\tEvent name: " << m_eventName; }

  /**
   * @brief   Display view number on screen
   * @pre     view number is set.
   * @post    view number is on screen
   */
  void DisplayViewOnscreen() { cout << "\tNumber of view: " << m_viewNumber; }

/**
   * @brief   Display condition on screen
   * @pre     Condition is set.
   * @post    Condition is on screen.
   */
  void DisplayConditionOnscreen() { cout << "\tCondition(1. createTime, 2. contentName, 3. viewNumber): " << m_condition; }

  /**
   * @brief   Display a content record on screen.
   * @pre     content record is set.
   * @post    content record is on screen.
   */
  void DisplayRecordOnScreen() {
    // DisplayNameOnscreen();
    // DisplayTypeOnscreen();
    // DisplayTimeOnscreen();
    // DisplayCharacterOnscreen();
    // DisplayLocationOnscreen();
    // DisplayEventNameOnscreen();
    // DisplayViewOnscreen();
    // DisplayConditionOnscreen();
    cout << "\t[ Content name: " << m_contentName;
    cout << ", Content type: " << m_contentType;
    cout << ", Create time: " << m_createTime;
    cout << ", Character: " << m_character;
    cout << ", location: " << m_location;
    cout << ", Event name: " << m_eventName;
    cout << ", Number of view: " << m_viewNumber;
    cout << ", Condition(1. createTime, 2. contentName, 3. viewNumber): " << m_condition;
  }

  /**
   * @brief   Set content name from keyboard.
   * @pre     None.
   * @post    content name is set.
   */
  void SetNameFromKB();

  /**
   * @brief   Set content type from keyboard.
   * @pre     None.
   * @post    content type is set.
   */
  void SetTypeFromKB();

  /**
   * @brief   Set content creation date and time from keyboard.
   * @pre     None.
   * @post    content creation date and time are set.
   */
  void SetTimeFromKB();

  /**
   * @brief   Set character included in the content from keyboard.
   * @pre     None.
   * @post    character included in the content is set.
   */
  void SetCharacterFromKB();

  /**
   * @brief   Set location included in the content from keyboard.
   * @pre     None.
   * @post    Location included in the content is set.
   */	
  void SetLocationFromKB();

  /**
   * @brief   Set event name from keyboard.
   * @pre     None.
   * @post    event name is set.
   */
  void SetEventNameFromKB();

  /**
   * @brief   Set view number from keyboard.
   * @pre     None.
   * @post    view number is set.
   */
  void SetViewFromKB();

  /**
   * @brief   Set condition from keyboard.
   * @pre     None.
   * @post    condition is set.
   */
  void SetConditionFromKB();

  /**
   * @brief   Set content record from keyboard.
   * @pre     None.
   * @post    content record is set.
   */
  void SetRecordFromKB();

  // /**
  //  * @brief   Read a record from file.
  //  * @pre     the target file is opened.
  //  * @post    content record is set
  //  * @param   fin file descriptor.
  //  * @return  return 1 if this function works well, otherwise 0.
  //  */
  // int ReadDataFromFile(ifstream& fin);

  // /**
  //  * @brief   Write a record into file.
  //  * @pre     the target file is opened. And the list should be initialized.
  //  * @post    the target file is included the new student record.
  //  * @param   fout  file descriptor.
  //  * @return  return 1 if this function works well, otherwise 0.
  //  */
  // int WriteDataToFile(ofstream& fout);

//   /**
//    * @brief   Compare content create time in two MultimediaContent class
//    * @pre     two MultimediaContent class should be initialized.
//    * @post    None.
//    * @param   data  target MultimediaContent for comparing.
//    * @return  return true if this->m_createTime == data->m_createTime,
//    *          otherwise return false.
//    */
//   bool operator==(const MultimediaContent& data) {
//     return (m_createTime == data.m_createTime);
//   }

//   /**
//    * @brief   Compare content create time in two MultimediaContent class
//    * @pre     Two MultimediaContent class should be initialized.
//    * @post    None.
//    * @param   data  target MultimediaContent for comparing.	
//    * @return  return true if this->m_createTime < data->m_createTime,
//    *          otherwise return false.
//    */
//   bool operator<(const MultimediaContent& data) {
//     return (m_createTime < data.m_createTime);
//   }

//   /**
//    * @brief   Compare content create time in two MultimediaContent class
//    * @pre     two MultimediaContent class should be initialized.
//    * @post    None.
//    * @param   data  target MultimediaContent for comparing.	
//    * @return  return true if this->m_createTime > data->m_createTime,
//    *          otherwise return false.
//    */
//   bool operator>(const MultimediaContent& data) {
//     return (m_createTime > data.m_createTime);
//   }

//   /**
//    * @brief   Assign content record to another.
//    * @pre     right MultimediaContent class should be initialized.
//    * @post    content record in left MultimediaContent class is set.
//    * @param   data  target MultimediaContent for assigning.
//    */
//   void operator=(const MultimediaContent& data) {
//     m_contentName = data.m_contentName;
//     m_contentType = data.m_contentType;
//     m_createTime = data.m_createTime;
//     m_character = data.m_character;
//     m_location = data.m_location;
//     m_eventName = data.m_eventName;
//     m_viewNumber = data.m_viewNumber;
//     m_condition = data.m_condition;
//   }

//   /**
//    * @brief   Print record.
//    * @pre     MultimediaContent class should be initialized.
//    * @post    content record is on screen.
//    * @param   cout  ostream instance
//    * @param   _item target MultimediaContent for printing.
//    */
//   friend ostream& operator<<(ostream& cout, const MultimediaContent& _item) {
//     cout << "\t[ Content name: " << _item.m_contentName;
//     cout << ", Content type: " << _item.m_contentType;
//     cout << ", Create time: " << _item.m_createTime;
//     cout << ", Character: " << _item.m_character;
//     cout << ", location: " << _item.m_location;
//     cout << ", Event name: " << _item.m_eventName;
//     cout << ", Number of view: " << _item.m_viewNumber;
//     cout << ", Condition(1. createTime, 2. contentName, 3. viewNumber): " << _item.m_condition << " ]";

//     return cout;
//   }

//   /**
//    * @brief   Input record.
//    * @pre     None.
//    * @post    content record is initialized.
//    * @param   cin   istream instance
//    * @param   _item target MultimediaContent for Input.
//    */
//   friend istream& operator>>(istream& cin, MultimediaContent& _item) {
//     cout << "\n\tEnter content name: ";
//     cin >> _item.m_contentName;
//     cout << "\tEnter content type(ex> 1: Photo, 2: Video):";
//     cin >> _item.m_contentType;
//     cout << "\tEnter create time: ";
//     cin >> _item.m_createTime;
//     cout << "\tEnter character: ";
//     cin >> _item.m_character;
//     cout << "\tEnter location: ";
//     cin >> _item.m_location;
//     cout << "\tEnter event name: ";
//     cin >> _item.m_eventName;
//     cout << "\tEnter number of view: ";
//     cin >> _item.m_viewNumber;
//     return cin;
//   }
};