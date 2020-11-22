#include "StudentType.h"

// Set student id from keyboard.
void StudentType::SetIdFromKB() {
	cout << "\tID : ";
	cin >> m_Id;
}

// Set student name from keyboard.
void StudentType::SetNameFromKB() {
	cout << "\tName : ";
	cin >> m_sName;
}

// Set student address from keyboard.
void StudentType::SetAddressFromKB() {
	cout << "\tAddress : ";
	cin >> m_sAddress;
}

// Set student record from keyboard.
void StudentType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

// Read a record from file.
int StudentType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sAddress;
	return 1;
};

// Write a record into file.
int StudentType::WriteDataToFile(ofstream& fout) {
	fout << m_Id << " ";
	fout << m_sName << " ";
	fout << m_sAddress;
	return 1;
}

// Compare two item types by item id.
bool StudentType::operator>(StudentType& item) {
	return (this->GetId() > item.GetId());
}	// return 1 if this.id > data.id, 0 if not.

// Compare two item types by item id.
bool StudentType::operator<(StudentType& item) {
	return (this->GetId() < item.GetId());
}	// return 1 if this.id < data.id, 0 if not.

// Compare two item types by item id.
bool StudentType::operator==(StudentType& item) {
	return (this->GetId() == item.GetId());
}	// return 1 if this.id == data.id, 0 if not.