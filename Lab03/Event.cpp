#include "Event.h"

// Set event name from keyboard.
void Event::SetNameFromKB() {
    cout << "\tEvent name : ";
	cin >> m_name;
}

// Set event description from keyboard.
void Event::SetDescriptionFromKB() {
    cout << "\tEvent Description : ";
	cin >> m_description;
}

// Set ccount MC from keyboard.
void Event::SetCountMCFromKB() {
    cout << "\tMC count : ";
	cin >> m_countMC;
}

// Set content record from keyboard.
void Event::SetRecordFromKB() {
    SetNameFromKB();
    SetDescriptionFromKB();
    SetCountMCFromKB();
}

// Add content Name of MC with same event into list.
void Event::AddMC(MultimediaContent _item) {
    m_name = _item.GetEventName();
    m_description = _item.GetEventDescription();
    m_pQueMC.EnQue(_item.GetName());
    m_countMC++;
}

// delete content Name.
void Event::DeleteMC(MultimediaContent _item) {
    m_pQueMC.Delete(_item.GetName());
    m_countMC--;
    cout << "\n\tDeletion worked.";
}