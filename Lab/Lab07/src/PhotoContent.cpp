#include "PhotoContent.h"

// Set resolution from keyboard.
void PhotoContent::SetResolutionFromKB() {
  cout << "\tResolution : ";
  cin >> m_resolution;
}

// Set shooting device from keyboard.
void PhotoContent::SetShootingDeviceFromKB() {
  cout << "\tShooting Device : ";
  cin >> m_shootingDevice;
}

// Set content record from keyboard.
void PhotoContent::Read() {
  MultimediaContent::SetRecordFromKB();
  SetResolutionFromKB();
  SetShootingDeviceFromKB();
}

// Assign content record to another.
void PhotoContent::operator=(const PhotoContent& _data) {
  m_contentName = _data.m_contentName;
  m_contentType = _data.m_contentType;
  m_createTime = _data.m_createTime;
  m_character = _data.m_character;
  m_location = _data.m_location;
  m_eventName = _data.m_eventName;
  m_viewNumber = _data.m_viewNumber;
  m_condition = _data.m_condition;
  m_resolution = _data.m_resolution;
  m_shootingDevice = _data.m_shootingDevice;
}

// Compare corresponding condition in two PhotoContent class
bool PhotoContent::operator==(const PhotoContent& _data) {
  switch (m_condition) {
    case 1: // createTime Condition
      return (m_createTime == _data.m_createTime);
    case 2: // Content Name Condition
      return (m_contentName == _data.m_contentName);
    case 3: // Number if view Condition
      return (m_viewNumber == _data.m_viewNumber);
    default:
      return false;
  }
}

// Compare two PhotoContent by member variable corresponding Condition.
bool PhotoContent::operator<(PhotoContent& _data) {
  switch (m_condition) {
    case 1: // createTime Condition
      return (m_createTime < _data.m_createTime);
    case 2: // Content Name Condition
      return (m_contentName < _data.m_contentName);
    case 3: // Number if view Condition
      return (m_viewNumber < _data.m_viewNumber);
    default:
      return false;
  }
}

// Compare two PhotoContent by member variable corresponding Condition.
bool PhotoContent::operator>(PhotoContent& _data) {
  switch (m_condition) {
    case 1: // createTime Condition
      return (m_createTime > _data.m_createTime);
    case 2: // Content Name Condition
      return (m_contentName > _data.m_contentName);
    case 3: // Number if view Condition
      return (m_viewNumber > _data.m_viewNumber);
    default:
      return false;
  }
}