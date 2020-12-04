#include "MusicContent.h"

// Set album from keyboard.
void MusicContent::SetAlbumFromKB() {
  cout << "\tAlbum : ";
  cin >> m_album;
}

// Set genre from keyboard.
void MusicContent::SetGenreFromKB() {
  cout << "\tGenre : ";
  cin >> m_genre;
}

// Set content record from keyboard.
void MusicContent::Read() {
  SetRecordFromKB();
  SetGenreFromKB();
}

// Assign content record to another.
void MusicContent::operator=(const MusicContent& _data) {
  m_contentName = _data.m_contentName;
  m_contentType = _data.m_contentType;
  m_createTime = _data.m_createTime;
  m_character = _data.m_character;
  m_location = _data.m_location;
  m_eventName = _data.m_eventName;
  m_viewNumber = _data.m_viewNumber;
  m_condition = _data.m_condition;
  m_album = _data.m_album;
  m_genre = _data.m_genre;
}

// Compare corresponding condition in two MusicContent class
bool MusicContent::operator==(const MusicContent& _data) {
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

// Compare two MusicContent by member variable corresponding Condition.
bool MusicContent::operator<(MusicContent& _data) {
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

// Compare two MusicContent by member variable corresponding Condition.
bool MusicContent::operator>(MusicContent& _data) {
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