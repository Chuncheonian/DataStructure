#include "VideoContent.h"

// Set playTime from keyboard.
void VideoContent::SetPlayTimeFromKB() {
  cout << "\tPlayTime : ";
  cin >> m_playTime;
}

// Set shooting device from keyboard.
void VideoContent::SetShootingDeviceFromKB() {
  cout << "\tShooting Device : ";
  cin >> m_shootingDevice;
}

// Set content record from keyboard.
void VideoContent::Read() {
  MultimediaContent::SetRecordFromKB();
  SetPlayTimeFromKB();
  SetShootingDeviceFromKB();
}

// Assign content record to another.
void VideoContent::operator=(const VideoContent& _data) {
  m_contentName = _data.m_contentName;
  m_contentType = _data.m_contentType;
  m_createTime = _data.m_createTime;
  m_character = _data.m_character;
  m_location = _data.m_location;
  m_eventName = _data.m_eventName;
  m_viewNumber = _data.m_viewNumber;
  m_condition = _data.m_condition;
  m_playTime = _data.m_playTime;
  m_shootingDevice = _data.m_shootingDevice;
}

// Compare corresponding condition in two VideoContent class
bool VideoContent::operator==(const VideoContent& _data) {
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

// Compare two VideoContent by member variable corresponding Condition.
bool VideoContent::operator<(VideoContent& _data) {
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

// Compare two VideoContent by member variable corresponding Condition.
bool VideoContent::operator>(VideoContent& _data) {
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