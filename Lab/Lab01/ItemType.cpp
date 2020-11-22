#include "ItemType.h"

// Set content name from keyboard.
void ItemType::SetNameFromKB() {
    cout << "\tName : ";
	cin >> contentName;
}

// Set content type from keyboard.
void ItemType::SetTypeFromKB() {
    cout << "\tType : ";
	cin >> contentType;
}

// Set content creation date and time from keyboard.
void ItemType::SetTimeFromKB() {
    cout << "\tTime : ";
	cin >> createTime;
}

// Set character included in the content from keyboard.
void ItemType::SetCharacterFromKB() {
    cout << "\tCharacter : ";
	cin >> character;
}

// Set event name from keyboard.
void ItemType::SetEventNameFromKB() {
    cout << "\tEventName : ";
	cin >> eventName;
}

// Set content record from keyboard.
void ItemType::SetRecordFromKB() {
    SetNameFromKB();
    SetTypeFromKB();
    SetTimeFromKB();
    SetCharacterFromKB();
    SetEventNameFromKB();
}

// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin) {
    fin >> contentName;
    fin >> contentType;
    fin >> createTime;
    fin >> character;
    fin >> eventName;

    return 1;
}

// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout) {
    fout << contentName << " ";
	fout << contentType << " ";
    fout << createTime << " ";
    fout << character << " ";
	fout << eventName;
	fout << endl;

	return 1;
}

// Compare two Itemtypes by content name
RelationType ItemType::CompareByName(const ItemType& data) {
    if (this->contentName > data.contentName)
        return GREATER;
    else if (this->contentName < data.contentName)
        return LESS;
    else
        return EQUAL;
}