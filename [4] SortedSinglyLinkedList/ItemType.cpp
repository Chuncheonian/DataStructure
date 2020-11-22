#include "ItemType.h"

// Set student id from keyboard.
void ItemType::SetIdFromKB() {
	cout << "\tID : ";
	cin >> m_id;
}

// Set student name from keyboard.
void ItemType::SetNameFromKB() {
	cout << "\tName : ";
	cin >> m_name;
}

// Set student address from keyboard.
void ItemType::SetAddressFromKB() {
	cout << "\tAddress : ";
	cin >> m_address;
}

// Set student record from keyboard.
void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_id;
	fin >> m_name;
	fin >> m_address;
	return 1;
};

// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << m_id << " ";
	fout << m_name << " ";
	fout << m_address;
	fout << endl;
	return 1;
}

// Compare two item types by item id.
bool ItemType::operator>(ItemType& _item) {
	return (this->GetId() > _item.GetId());
}	// return 1 if this.id > data.id, 0 if not.

// Compare two item types by item id.
bool ItemType::operator<(ItemType& _item) {
	return (this->GetId() < _item.GetId());
}	// return 1 if this.id < data.id, 0 if not.

// Compare two item types by item id.
bool ItemType::operator==(ItemType& _item) {
	return (this->GetId() == _item.GetId());
}	// return 1 if this.id == data.id, 0 if not.

// Assign content record to another.
ItemType ItemType::operator=(const ItemType& _item) {
        m_id = _item.m_id;
        m_name = _item.m_name;
        m_address = _item.m_address;

		return (*this);
	}