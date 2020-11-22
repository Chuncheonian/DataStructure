#include "DeptType.h"

// Set department name from keyboard.
void DeptType::SetNameFromKB() {
	cout << "\tDepartment Name : ";
	cin >> m_dName;
}

// Set number of students from keyboard.
void DeptType::SetCountFromKB() {
	cout << "\tNumber of students : ";
	cin >> m_numOfStudent;
}

// // Set department record from keyboard.
// void DeptType::SetRecordFromKB() {
// 	SetNameFromKB();
// 	SetCountFromKB();
// }

// Read a record from file.
int DeptType::ReadDataFromFile(ifstream& fin) {
	fin >> m_dName;
	fin >> m_numOfStudent;
	return 1;
}

// Write a record into file.
int DeptType::WriteDataToFile(ofstream& fout) {
	fout << m_dName << " ";
	fout << m_numOfStudent;
	return 1;
}

// Compare two department types by department name.
bool DeptType::operator>(DeptType& item) {
	return (this->GetName() > item.GetName());
}	//return 1 if this.m_dName > data.m_dName, 0 if not.

// Compare two department types by department name.
bool DeptType::operator==(DeptType& item) {
	return (this->GetName() == item.GetName());
}	//return 1 if this.m_dName == data.m_dName, 0 if not.

// Add new student ID into list.
void DeptType::AddId(int _sId) {
	m_sIdList.Add(_sId);	// 리스트에 항목을 추가한다.
    m_numOfStudent++;
}

// Delete student ID into list.
int DeptType::DeleteId(int _sId) {
	if (m_sIdList.Delete(_sId)) {
		m_numOfStudent--;
		return 1;
	}
	else
		return 0;
}

// Display all records in the list on screen.
void DeptType::DisplayAllId() {
	int temp = 0;

	cout << "\tIds : ";

	m_sIdList.ResetList();	// 리스트 초기화
	// list의 모든 데이터를 화면에 출력
	for (int i = 0; i < m_sIdList.GetLength(); i++) {
		m_sIdList.GetNextItem(temp);
        cout << temp << " -> ";
	}
}

// Bring masterlist as pass by reference and Display detatil student records.
void DeptType::SearchAtMasterList(SortedList<StudentType>& _masterList) {
	StudentType student;
	int temp = 0;

	m_sIdList.ResetList();	// 리스트 초기화

	if (!m_numOfStudent)
		cout << "\tNot Exist Student ID in list.";
	
	else {
		// list의 모든 데이터를 화면에 출력
		for (int i = 0; i < m_sIdList.GetLength(); i++) {
			m_sIdList.GetNextItem(temp);
			student.SetId(temp);
			_masterList.Retrieve_BinS(student);
			cout << student << endl;
		}
	}
}
