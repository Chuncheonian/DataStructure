#include "FavoritePhotoContent.h"

// Set content name from keyboard.
void FavoritePhotoContent::SetNameFromKB() {
    cout << "\tContent name : ";
	cin >> m_contentName;
}


// Set content creation date and time from keyboard.
void FavoritePhotoContent::SetTimeFromKB() {
    cout << "\tContent create time : ";
	cin >> m_createTime;
}


// Set character included in the content from keyboard.
void FavoritePhotoContent::SetCharacterFromKB() {
    cout << "\tContent character : ";
	cin >> m_character;
}


// Set location included in the content from keyboard.
void FavoritePhotoContent::SetLocationFromKB() {
    cout << "\tContent location : ";
	cin >> m_location;
}

// Set event name from keyboard.
void FavoritePhotoContent::SetEventNameFromKB() {
    cout << "\tEvent name : ";
	cin >> m_eventName;
}


// Set condition from keyboard.
void FavoritePhotoContent::SetConditionFromKB() {
    cout << "\tCondition(1. createTime, 2. contentName, 3. viewNumber) : ";
    cin >> m_condition;
}


// Set content record from keyboard.
void FavoritePhotoContent::SetRecordFromKB() {
    SetNameFromKB();
    SetTimeFromKB();
    SetCharacterFromKB();
    SetLocationFromKB();
    SetEventNameFromKB();
    SetConditionFromKB();
}

// Assign content record to another.
void FavoritePhotoContent::operator=(const FavoritePhotoContent& _data) {
	m_contentName = _data.m_contentName;
	m_createTime = _data.m_createTime;
    m_character = _data.m_character;
    m_location = _data.m_location;
	m_eventName = _data.m_eventName;
	m_condition = _data.m_condition;
	m_viewNumber = _data.m_viewNumber;
}

// Compare corresponding condition in two FavoritePhotoContent class
bool FavoritePhotoContent::operator==(const FavoritePhotoContent& _data) {
	switch (m_condition) {
		case 1:	// createTime Condition
			return (m_createTime == _data.m_createTime);
		case 2:	// Content Name Condition
			return (m_contentName == _data.m_contentName);
		case 3:	// Number if view Condition
			return (m_viewNumber == _data.m_viewNumber);
		default:
			return false;
	}
}

// Compare two FavoritePhotoContent by member variable corresponding Condition.
bool FavoritePhotoContent::operator<(FavoritePhotoContent& _data) {
	switch (m_condition) {
		case 1:// createTime Condition
			return (m_createTime < _data.m_createTime);
		case 2:// Content Name Condition
			return (m_contentName < _data.m_contentName);
		case 3:// Number if view Condition
			return (m_viewNumber < _data.m_viewNumber);
		default:
			return false;
	}
}

// Compare two FavoritePhotoContent by member variable corresponding Condition.
bool FavoritePhotoContent::operator>(FavoritePhotoContent& _data) {
	switch (m_condition) {
		case 1:	// createTime Condition
			return (m_createTime > _data.m_createTime);
		case 2:	// Content Name Condition
			return (m_contentName > _data.m_contentName);
		case 3:	// Number if view Condition
			return (m_viewNumber > _data.m_viewNumber);
		default:
			return false;
	}
}