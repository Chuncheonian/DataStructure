#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"

// Photo Content information class
class PhotoContent : public MultimediaContent {
private:
  string m_resolution;      // Photo Resolution
  string m_shootingDevice;  // Shooting Device

public:
  // default constructor.
  PhotoContent() {
    m_resolution = "";
    m_shootingDevice = "";
  }

  // PhotoContent(MultimediaContent &_mc) {
  //   SetName(_mc.GetName());
  //   SetTime(_mc.GetTime());
  //   SetCharacter(_mc.GetCharacter());
  //   SetLocation(_mc.GetLocation());
  //   SetEventName(_mc.GetEventName());
  //   m_condition = 1;
  //   m_viewNumber = 0;
  // }

  // default destructor.
  ~PhotoContent() {}

  void Play() override {
    DisplayRecordOnScreen();
    cout << endl;
  }

  /**
   * @brief   Get resolution
   * @pre     resolution is set
   * @post    None.
   * @return  resolution
   */
  string GetResolution() const { return m_resolution; }

  /**
   * @brief   Get shootingDevice
   * @pre     shootingDevice is set
   * @post    None.
   * @return  shootingDevice
   */
  string GetShootingDevice() const { return m_shootingDevice; }



  /**
   * @brief   Set resolution/
   * @pre     None.
   * @post    resolution is set.
   * @param   _resolution resolution
   */
  void SetResolution(string _resolution) { m_resolution = _resolution; }

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
   * @param   _resolution     resolution
   * @param   _shootingDevice shootingDevice
   */
  void SetRecord(string _resolution, string _shootingDevice) {
    SetResolution(_resolution);
    SetShootingDevice(_shootingDevice);
  }

  /**
   * @brief   Display resolution on screen.
   * @pre     resolution is set.
   * @post    resolution is on screen.
   */
  void DisplayResolutionOnscreen() { cout << "\tResolution: " << m_resolution; }

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
    cout << ", Resolution: " << m_resolution;
    cout << ", Shooting Device: " << m_shootingDevice << " ]";
  }

  /**
   * @brief   Set resolution from keyboard.
   * @pre     None.
   * @post    resolution is set.
   */
  void SetResolutionFromKB();

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
   * @pre     right PhotoContent class should be initialized.
   * @post    content record in left PhotoContent class is set.
   * @param   _data target PhotoContent for assigning.
   */
  void operator=(const PhotoContent &_data);

  /**
   * @brief   Compare corresponding condition in two PhotoContent class
   * @pre     Two PhotoContent class should be initialized.
   * @post    None.
   * @param   _data target PhotoContent for comparing.	
   * @return  Return true If Two member variables corresponding Condition are the same, Otherwise return false.
   */
  bool operator==(const PhotoContent &_data);

  /**
   * @brief   Compare two PhotoContent by member variable corresponding Condition.
   * @pre     Two PhotoContent should be initialized.
   * @param   data  target item for comparing.
   * @return  Return true If member variable corresponding Condition is smaller than member variable of _data, Otherwise return false.
   */
  bool operator<(PhotoContent &_data);

  /**
   * @brief   Compare two PhotoContent by member variable corresponding Condition.
   * @pre     Two PhotoContent should be initialized.
   * @param   data  target item for comparing.
   * @return  Return true If member variable corresponding Condition is bigger than member variable of _data, Otherwise return false.
   */
  bool operator>(PhotoContent &_data);

  /**
   * @brief   Print record.
   * @pre     PhotoContent class should be initialized.
   * @post    content record is on screen.
   * @param   cout  ostream instance
   * @param   _data target PhotoContent for printing.
   */
  friend ostream& operator<<(ostream &cout, const PhotoContent &_data) {
    cout << "\t[ Content name: " << _data.GetName();
    // cout << ", Content type: " << _data.m_contentType;
    // cout << ", Create time: " << _data.m_createTime;
    // cout << ", Character: " << _data.m_character;
    // cout << ", location: " << _data.m_location;
    // cout << ", Event name: " << _data.m_eventName;
    // cout << ", Number of view: " << _data.m_viewNumber;
    // cout << ", Condition(1. createTime, 2. contentName, 3. viewNumber): " << _data.m_condition;
    // cout << ", Resolution: " << _data.m_resolution;
    // cout << ", Shooting Device: " << _data.m_shootingDevice << " ]";
    return cout;
  }

  /**
   * @brief   Input record.
   * @pre     None.
   * @post    content record is initialized.
   * @param   cin   istream instance
   * @param   _item target PhotoContent for Input.
   */
  friend istream& operator>>(istream& cin, PhotoContent& _item) {
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
    cout << "\tEnter resolution: ";
    cin >> _item.m_resolution;
    cout << "\tEnter Shooting Device: ";
    cin >> _item.m_shootingDevice;
    return cin;
  }
};