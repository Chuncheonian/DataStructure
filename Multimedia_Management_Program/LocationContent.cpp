#include "LocationContent.h"

// Set location name from keyboard.
void LocationContent::SetNameFromKB() {
    cout << "\tLocation name : ";
	cin >> m_location;
}
	
// Set number of CreateTime.
void LocationContent::SetCountFromKB() {
    cout << "\tEvent number of CreateTime : ";
	cin >> m_numOfCreateTime;
}
	
// Set location record from keyboard.
void LocationContent::SetRecordFromKB() {
    SetNameFromKB();
    SetCountFromKB();
}

// Add new CreateTime into list.
void LocationContent::AddCreateTime(string _createTime) {
    m_createTimeList.Add(_createTime);
    m_numOfCreateTime++;
}

// Delete CreateTime into list.
int LocationContent::DeleteCreateTime(string _createTime) {
    if (m_createTimeList.Delete(_createTime)) {
        m_numOfCreateTime--;
        return 1;
    }
    else
        return 0;
}

// Display all elements in the CreateTime List on screen.
void LocationContent::DisplayAllCreateTime() {
    string tmp = "";

    cout << "Creation Time: ";

    m_createTimeList.ResetList();

    for (int i = 0; i < m_createTimeList.GetLength(); i++) {
        m_createTimeList.GetNextItem(tmp);
        cout << tmp << " -> ";
    }
}

// Bring masterlist as pass by reference and Display detail MultimediaContent records.
void LocationContent::SearchAtMasterList(SortedDoublyLinkedList<MultimediaContent>& _masterList) {
    MultimediaContent mainContent;
    string tmp = "";

    m_createTimeList.ResetList();

    if (!m_numOfCreateTime)
        cout << "\tNot Exist Creation Time in list.";
    
    else {
        for (int i = 0; i < m_createTimeList.GetLength(); i++) {
            m_createTimeList.GetNextItem(tmp);
            mainContent.SetTime(tmp);
            _masterList.Get(mainContent);
            cout << mainContent << endl;
        }
    }
}

// Compare two LocationContent by location name.
bool LocationContent::operator>(LocationContent& _location) {
    return (this->GetName() > _location.GetName());
}

// Compare two LocationContent by location name.
bool LocationContent::operator<(LocationContent& _location) {
    return (this->GetName() < _location.GetName());
}

// Compare two LocationContent by location name.
bool LocationContent::operator==(LocationContent& _location) {
    return (this->GetName() == _location.GetName());
}