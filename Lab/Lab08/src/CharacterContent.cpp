#include "CharacterContent.h"

// Set Character name from keyboard.
void CharacterContent::SetNameFromKB() {
    cout << "\tCharacter name : ";
	cin >> m_character;
}

// Set number of CreateTime.
void CharacterContent::SetCountFromKB() {
    cout << "\tEvent number of CreateTime : ";
	cin >> m_numOfCreateTime;
}
	
// Set Character record from keyboard.
void CharacterContent::SetRecordFromKB() {
    SetNameFromKB();
    SetCountFromKB();
}

// Add new CreateTime into list.
void CharacterContent::AddCreateTime(string _createTime) {
    m_createTimeList.Add(_createTime);
    m_numOfCreateTime++;
}

// Delete CreateTime into list.
int CharacterContent::DeleteCreateTime(string _createTime) {
    if (m_createTimeList.Delete(_createTime)) {
        m_numOfCreateTime--;
        return 1;
    }
    else
        return 0;
}


// Display all elements in the CreateTime List on screen.
void CharacterContent::DisplayAllCreateTime() {
    string tmp = "";

    cout << "Creation Time: ";

    m_createTimeList.ResetList();

    for (int i = 0; i < m_createTimeList.GetLength(); i++) {
        m_createTimeList.GetNextItem(tmp);
        cout << tmp << " -> ";
    }
}

// Bring masterlist as pass by reference and Display detail MultimediaContent records.
void CharacterContent::SearchAtMasterList(BinarySearchTree<MultimediaContent>& _masterList) {
    MultimediaContent mainContent;
    string tmp = "";
    bool found;
    m_createTimeList.ResetList();

    if (!m_numOfCreateTime)
        cout << "\tNot Exist Creation Time in list.";
    
    else {
        for (int i = 0; i < m_createTimeList.GetLength(); i++) {
            m_createTimeList.GetNextItem(tmp);
            mainContent.SetTime(tmp);
            _masterList.RetrieveItem(mainContent, found);
            cout << mainContent << endl;
        }
    }
}

// Compare two CharacterContent by Character name.
bool CharacterContent::operator>(CharacterContent& _character) {
    return (this->GetName() > _character.GetName());
}

// Compare two CharacterContent by Character name.
bool CharacterContent::operator<(CharacterContent& _character) {
    return (this->GetName() < _character.GetName());
}

// Compare two CharacterContent by Character name.
bool CharacterContent::operator==(CharacterContent& _character) {
    return (this->GetName() == _character.GetName());
}