#include "MultimediaContent.h"

// Set content name from keyboard.
void MultimediaContent::SetNameFromKB() {
  cout << "\tContent name : ";
  cin >> m_contentName;
}

// Set content type from keyboard.
void MultimediaContent::SetTypeFromKB() {
  cout << "\tContent type(1: Music, 2: Photo, 3: Video) : ";
  cin >> m_contentType;
}

// Set content creation date and time from keyboard.
void MultimediaContent::SetTimeFromKB() {
  cout << "\tContent create time : ";
  cin >> m_createTime;
}

// Set character included in the content from keyboard.
void MultimediaContent::SetCharacterFromKB() {
  cout << "\tContent character : ";
  cin >> m_character;
}

// Set location included in the content from keyboard.
void MultimediaContent::SetLocationFromKB() {
  cout << "\tContent location : ";
  cin >> m_location;
}


// Set event name from keyboard.
void MultimediaContent::SetEventNameFromKB() {
  cout << "\tEvent name : ";
  cin >> m_eventName;
}

// // Set view number from keyboard.
// void MultimediaContent::SetViewFromKB() {
//   cout << "\tNumber of view : ";
//   cin >> m_viewNumber;
// }

// // Set condition from keyboard.
// void MultimediaContent::SetConditionFromKB() {
//     cout << "\tCondition(1. createTime, 2. contentName, 3. viewNumber) : ";
//     cin >> m_condition;
// }

// Set content record from keyboard.
void MultimediaContent::SetRecordFromKB() {
  SetNameFromKB();
  SetTypeFromKB();
  SetTimeFromKB();
  SetCharacterFromKB();
  SetLocationFromKB();
  SetEventNameFromKB();
  // SetViewFromKB();
  // SetConditionFromKB();
}

// // Read a record from file.
// int MultimediaContent::ReadDataFromFile(ifstream& fin) {
//   if (!fin) {
//     cout << "File Input Error" << endl;
//     return -1;
//   }
    
//   fin >> m_contentName;
//   fin >> m_contentType;
//   fin >> m_createTime;
//   fin >> m_character;
//   fin >> m_location;
//   fin >> m_eventName;
//   fin >> m_viewNumber;
//   return 1;
// }

// // Write a record into file.
// int MultimediaContent::WriteDataToFile(ofstream& fout) {
//   fout << m_contentName << " ";
//   fout << m_contentType << " ";
//   fout << m_createTime << " ";
//   fout << m_character << " ";
//   fout << m_location << " ";
//   fout << m_eventName << " ";
//   fout << m_viewNumber << " ";
//   fout << endl;

//   return 1;
// }