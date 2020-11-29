#include "FavoriteVideoContent.h"


// Set content name from keyboard.
void FavoriteVideoContent::SetNameFromKB() {
    cout << "\tContent name : ";
	cin >> m_contentName;
}

// Set content creation date and time from keyboard.
void FavoriteVideoContent::SetTimeFromKB() {
    cout << "\tContent create time : ";
	cin >> m_createTime;
}

// Set character included in the content from keyboard.
void FavoriteVideoContent::SetCharacterFromKB() {
    cout << "\tContent character : ";
	cin >> m_character;
}

// Set location included in the content from keyboard.
void FavoriteVideoContent::SetLocationFromKB() {
    cout << "\tContent location : ";
	cin >> m_location;
}

// Set event name from keyboard.
void FavoriteVideoContent::SetEventNameFromKB() {
    cout << "\tEvent name : ";
	cin >> m_eventName;
}

// Set condition from keyboard.
void FavoriteVideoContent::SetConditionFromKB(){
    cout << "\tCondition(1. createTime, 2. contentName, 3. viewNumber) : ";
    cin >> m_condition;
}

// Set content record from keyboard.
void FavoriteVideoContent::SetRecordFromKB() {
    SetNameFromKB();
    SetTimeFromKB();
    SetCharacterFromKB();
    SetLocationFromKB();
    SetEventNameFromKB();
    SetConditionFromKB();
}

// Assign content record to another.
void FavoriteVideoContent::operator=(const FavoriteVideoContent& _data) {
	m_contentName = _data.m_contentName;
	m_createTime = _data.m_createTime;
    m_character = _data.m_character;
	m_location = _data.m_location;
	m_eventName = _data.m_eventName;
	m_condition = _data.m_condition;
	m_viewNumber = _data.m_viewNumber;
}

// Compare corresponding condition in two FavoriteVideoContent class
 bool FavoriteVideoContent::operator==(const FavoriteVideoContent& _data) {
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

// Compare two FavoriteVideoContent by member variable corresponding Condition.
bool FavoriteVideoContent::operator<(FavoriteVideoContent& _data) {
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

// Compare two FavoriteVideoContent by member variable corresponding Condition.
bool FavoriteVideoContent::operator>(FavoriteVideoContent& _data) {
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