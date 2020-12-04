#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"

// Photo Content information class
class VideoContent : public MultimediaContent {
private:
  int   m_playTime;         // Photo playTime
  string m_shootingDevice;  // Shooting Device

public:
  // default constructor.
  VideoContent() {
    m_playTime = 0;
    m_shootingDevice = "";
  }

  // VideoContent(MultimediaContent &_mc) {
  //   SetName(_mc.GetName());
  //   SetTime(_mc.GetTime());
  //   SetCharacter(_mc.GetCharacter());
  //   SetLocation(_mc.GetLocation());
  //   SetEventName(_mc.GetEventName());
  //   m_condition = 1;
  //   m_viewNumber = 0;
  // }

  // default destructor.
  ~VideoContent() {}

  void Play() override {
    DisplayRecordOnScreen();
    cout << endl;
  }

  /**
   * @brief   Get playTime
   * @pre     playTime is set
   * @post    None.
   * @return  playTime
   */
  int GetPlayTime() const { return m_playTime; }

  /**
   * @brief   Get shootingDevice
   * @pre     shootingDevice is set
   * @post    None.
   * @return  shootingDevice
   */
  string GetShootingDevice() const { return m_shootingDevice; }

  /**
   * @brief   Set playTime
   * @pre     None.
   * @post    playTime is set.
   * @param   _playTime playTime
   */
  void SetPlayTime(int _playTime) { m_playTime = _playTime; }

  /**
   * @brief   Set shootingDevice
   * @pre     None.
   * @post    shootingDevice is set.
   * @param   _shootingDevice shootingDevice
   */
  void SetShootingDevice(string _shootingDevice) { m_shootingDevice = _shootingDevice; }

  /**
   * @brief   Set content record.
   * @pre     None.
   * @post    Content record is set.
   * @param   _playTime     playTime
   * @param   _shootingDevice shootingDevice
   */
  void SetRecord(int _playTime, string _shootingDevice) {
    SetPlayTime(_playTime);
    SetShootingDevice(_shootingDevice);
  }

  /**
   * @brief   Display playTime on screen.
   * @pre     playTime is set.
   * @post    playTime is on screen.
   */
  void DisplayPlayTimeOnscreen() { cout << "\tPlayTime: " << m_playTime; }

  /**
   * @brief   Display shooting device on screen.
   * @pre     shooting deviceare set.
   * @post    shooting device are on screen.
   */
  void DisplayShootingDeviceOnscreen() { cout << "\tShooting Device: " << m_shootingDevice; }

  /**
   * @brief   Display a content record on screen.
   * @pre     content record is set.
   * @post    content record is on screen.
   */
  void DisplayRecordOnScreen() {
    MultimediaContent::DisplayRecordOnScreen();
    DisplayPlayTimeOnscreen();
    DisplayShootingDeviceOnscreen();
  }

  /**
   * @brief   Set playTime from keyboard.
   * @pre     None.
   * @post    playTime is set.
   */
  void SetPlayTimeFromKB();

  /**
   * @brief   Set shooting device from keyboard.
   * @pre     None.
   * @post    shooting device are set.
   */
  void SetShootingDeviceFromKB();

  /**
   * @brief   Set content record from keyboard.
   * @pre     None.
   * @post    content record is set.
   */
  void Read() override;

  /**
   * @brief   Assign content record to another.
   * @pre     right VideoContent class should be initialized.
   * @post    content record in left VideoContent class is set.
   * @param   _data target VideoContent for assigning.
   */
  void operator=(const VideoContent &_data);

  /**
   * @brief   Compare corresponding condition in two VideoContent class
   * @pre     Two VideoContent class should be initialized.
   * @post    None.
   * @param   _data target VideoContent for comparing.	
   * @return  Return true If Two member variables corresponding Condition are the same, Otherwise return false.
   */
  bool operator==(const VideoContent &_data);

  /**
   * @brief   Compare two VideoContent by member variable corresponding Condition.
   * @pre     Two VideoContent should be initialized.
   * @param   data  target item for comparing.
   * @return  Return true If member variable corresponding Condition is smaller than member variable of _data, Otherwise return false.
   */
  bool operator<(VideoContent &_data);

  /**
   * @brief   Compare two VideoContent by member variable corresponding Condition.
   * @pre     Two VideoContent should be initialized.
   * @param   data  target item for comparing.
   * @return  Return true If member variable corresponding Condition is bigger than member variable of _data, Otherwise return false.
   */
  bool operator>(VideoContent &_data);

  /**
   * @brief   Print record.
   * @pre     VideoContent class should be initialized.
   * @post    content record is on screen.
   * @param   cout  ostream instance
   * @param   _data target VideoContent for printing.
   */
  friend ostream &operator<<(ostream &cout, const VideoContent &_data) {
    cout << "\t[ Content name: " << _data.m_contentName;
    cout << ", Content type: " << _data.m_contentType;
    cout << ", Create time: " << _data.m_createTime;
    cout << ", Character: " << _data.m_character;
    cout << ", location: " << _data.m_location;
    cout << ", Event name: " << _data.m_eventName;
    cout << ", Number of view: " << _data.m_viewNumber;
    cout << ", Condition(1. createTime, 2. contentName, 3. viewNumber): " << _data.m_condition;
    cout << ", PlayTime: " << _data.m_playTime;
    cout << ", Shooting Device: " << _data.m_shootingDevice << " ]";
    return cout;
  }

  /**
   * @brief   Input record.
   * @pre     None.
   * @post    content record is initialized.
   * @param   cin   istream instance
   * @param   _item target VideoContent for Input.
   */
  friend istream& operator>>(istream& cin, VideoContent& _item) {
    cout << "\n\tEnter content name: ";
    cin >> _item.m_contentName;
    cout << "\tEnter content type(ex> 1: Photo, 2: Video):";
    cin >> _item.m_contentType;
    cout << "\tEnter create time: ";
    cin >> _item.m_createTime;
    cout << "\tEnter character: ";
    cin >> _item.m_character;
    cout << "\tEnter location: ";
    cin >> _item.m_location;
    cout << "\tEnter event name: ";
    cin >> _item.m_eventName;
    cout << "\tEnter number of view: ";
    cin >> _item.m_viewNumber;
    cout << "\tEnter PlayTime: ";
    cin >> _item.m_playTime;
    cout << "\tEnter Shooting Device: ";
    cin >> _item.m_shootingDevice;
    return cin;
  }
};