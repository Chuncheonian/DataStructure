#include "ItemType.h"

// Set content name from keyboard.
void ItemType::SetNameFromKB() {
    cout << "\tContent name : ";
	cin >> m_contentName;
}

// Set content type from keyboard.
void ItemType::SetTypeFromKB() {
    cout << "\tContent type(ex> 1:Photo, 2:Panorama, 3: Video) : ";
	cin >> m_contentType;
}

// Set content creation date and time from keyboard.
void ItemType::SetTimeFromKB() {
    cout << "\tContent time : ";
	cin >> m_createTime;
}

// Set character included in the content from keyboard.
void ItemType::SetCharacterFromKB() {
    cout << "\tContent character : ";
	cin >> m_character;
}

// Set content Category from keyboard.
void ItemType::SetCategoryFromKB() {
    cout << "\tContent Category(ex> 1:Portrait, 2:Location, 3: Video) : ";
	cin >> m_contentCategory;
}

// Set event name from keyboard.
void ItemType::SetEventNameFromKB() {
    cout << "\tEvent name : ";
	cin >> m_eventName;
}

// Set event description from keyboard.
void ItemType::SetEventDescriptionFromKB() {
    cout << "\tEvent Description : ";
	cin >> m_eventDescription;
}

// Set content record from keyboard.
void ItemType::SetRecordFromKB() {
    SetNameFromKB();
    SetTypeFromKB();
    SetTimeFromKB();
    SetCharacterFromKB();
    SetCategoryFromKB();
    SetEventNameFromKB();
    SetEventDescriptionFromKB();
    SetContents();
}

// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin) {
    if (!fin) {
		cout << "File Input Error" << endl;
		return -1;
	}
    
	fin >> m_contentName;
	fin >> m_contentType;
	fin >> m_createTime;
    fin >> m_character;
    fin >> m_contentCategory;
    fin >> m_eventName;
    fin >> m_eventDescription;
    SetContents();
    
	return 1;
}

// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_contentName << " ";
	fout << m_contentType << " ";
    fout << m_createTime << " ";
    fout << m_character << " ";
    fout << m_contentCategory << " ";
    fout << m_eventName << " ";
    fout << m_eventDescription << " ";
	fout << endl;

	return 1;
}