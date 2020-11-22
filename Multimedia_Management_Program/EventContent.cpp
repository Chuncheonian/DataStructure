#include "EventContent.h"

// Set event name from keyboard.
void EventContent::SetNameFromKB() {
    cout << "\tEvent name : ";
	cin >> m_name;
}

// Set event description from keyboard.
void EventContent::SetDescriptionFromKB() {
    cout << "\tEvent Description : ";
	cin >> m_description;
}


// Set number of CreateTime.
void EventContent::SetCountFromKB() {
    cout << "\tEvent number of CreateTime : ";
	cin >> m_numOfCreateTime;
}

// Set Event record from keyboard.
void EventContent::SetRecordFromKB() {
    SetNameFromKB();
    SetDescriptionFromKB();
    SetCountFromKB();
}

// Add new CreateTime into list.
void EventContent::AddCreateTime(string _createTime) {
    m_createTimeList.Add(_createTime);
    m_numOfCreateTime++;
}

// Delete CreateTime into list.
int EventContent::DeleteCreateTime(string _createTime) {
    if (m_createTimeList.Delete(_createTime)) {
        m_numOfCreateTime--;
        return 1;
    }
    else
        return 0;
}

// Display all elements in the createTime List on screen.
void EventContent::DisplayAllCreateTime() {
    string tmp = "";

    cout << "Creation Time: ";

    m_createTimeList.ResetList();

    for (int i = 0; i < m_createTimeList.GetLength(); i++) {
        m_createTimeList.GetNextItem(tmp);
        cout << tmp << " -> ";
    }
}

// Bring masterlist as pass by reference and Display detail MultimediaContent records.
void EventContent::SearchAtMasterList(SortedDoublyLinkedList<MultimediaContent>& _masterList) {
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

// Compare two EventContent by event name.
bool EventContent::operator>(EventContent& _event) {
    return (this->GetName() > _event.GetName());
}

// Compare two EventContent by event name.
bool EventContent::operator<(EventContent& _event) {
    return (this->GetName() < _event.GetName());
}

// Compare two EventContent by event name.
bool EventContent::operator==(const EventContent& _event) {
    return (this->GetName() == _event.GetName());
}