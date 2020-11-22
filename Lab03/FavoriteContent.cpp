#include "FavoriteContent.h"

// Set content name from keyboard.
void FavoriteContent::SetNameFromKB() {
    cout << "\tContent name : ";
	cin >> m_contentName;
}

// Set content type from keyboard.
void FavoriteContent::SetTypeFromKB() {
    cout << "\tContent type(ex> 1:Photo, 2:Panorama, 3: Video) : ";
	cin >> m_contentType;
}

// Set content creation date and time from keyboard.
void FavoriteContent::SetTimeFromKB() {
    cout << "\tContent time : ";
	cin >> m_createTime;
}

// Set content category from keyboard.
void FavoriteContent::SetCategoryFromKB() {
    cout << "\tContent Category(ex> 1:Portrait, 2:Location, 3: Video) : ";
	cin >> m_contentCategory;
}

// Set content record from keyboard.
void FavoriteContent::SetRecordFromKB() {
    SetNameFromKB();
    SetTypeFromKB();
    SetTimeFromKB();
    SetCategoryFromKB();
}

// Read a record from file.
int FavoriteContent::ReadDataFromFile(ifstream& fin) {
    if (!fin) {
		cout << "File Input Error" << endl;
		return -1;
	}
    
	fin >> m_contentName;
	fin >> m_contentType;
	fin >> m_createTime;
    fin >> m_contentCategory;

	return 1;
}

// Write a record into file.
int FavoriteContent::WriteDataToFile(ofstream& fout) {
	fout << m_contentName << " ";
	fout << m_contentType << " ";
    fout << m_createTime << " ";
    fout << m_contentCategory << " ";
	fout << endl;

	return 1;
}