#include "Application.h"

// Program driver.
void Application::Run() {
	while(1) {
		m_command = GetCommand();

		switch(m_command) {
		case 1:		// Add new record into masterList.
			AddContents();
			break;
		case 2:		// Get a createTime from keyboard and delete the rocord with same create Time.
			DeleteContents();
			break;
		case 3:		// Get a record from keyboard and Replace the rocord with same record.
			ReplaceContents();
			break;
		case 4:		// Get a create time from keyboard and Display a record with input create time.
			RetrieveContents();
			break;
		case 5:		// Display all MultimediaContents in the list in screen.
			DisplayAllContents();
			break;
		case 6:		// Make all list empty.
			MakeEmpty();
			break;
		// case 7:		// get data from data file
		// 	ReadDataFromFile();
		// 	break;
		// case 8:		// put data to data file
		// 	WriteDataToFile();
		// 	break;
		// case 9:		// Search MultiContent Record by combining one or more Primary KEYs.
		// 	SearchMCFromPks();
		// 	break;
		case 0:		// quit
			return;
			
		case 11:		// Add new record into favoritedphotolist or favoritevideolist.
			AddFavoriteContent();
			break;
		case 12:		// Get a create time from keyboard and Delete the rocord with same create time.
			DeleteFavoriteContent();
			break;
		case 13:		// Get the list want to see from keyboard and Display all records in the corresponding list in screen.
			DisplayAllFavoriteContent();
			break;
		case 14:		// Display detail information of the specific record in screen.
			DisplayDetailFC();
			break;
		case 15:		// Get the condition by keyboard and Rearrange order of FavoriteContent elements.
			RearrangeFC();
			break;

		case 21:		// Display all Character record in the list on screen.
			DisplayAllCharacter();
			break;
		case 22:		// Search createTime from Location Record and Get detail content records.
			SearchMCFromCharacter();
			break;

		case 31:		// Display all Location record in the list on screen.
			DisplayAllLocation();
			break;
		case 32:		// Search createTime from Location Record and Get detail content records.
			SearchMCFromLocation();
			break;

		case 41:		// Display all Event record in the list on screen.
			DisplayAllEvent();
			break;
		case 42:		// Search createTime from Event Record and Get detail content records.
			SearchMCFromEvent();
			break;
		
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}	
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t   ----- Main Command ----- " << endl;
	cout << "\t   1 : Insert content" << endl;
	cout << "\t   2 : Delete content" << endl;
	cout << "\t   3 : Update content" << endl;
	cout << "\t   4 : Search content by Content creation time" << endl;
	cout << "\t   5 : Display all content" << endl;
	cout << "\t   6 : Make empty list" << endl;
	// cout << "\t   7 : Get from file" << endl;
	// cout << "\t   8 : Put to file" << endl;
	// cout << "\t   9 : Search content by combining keys" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << "\t   ----- Favorite Command ----- " << endl;
	cout << "\t   11 : Add favorite content" << endl;
	cout << "\t   12 : Delete favorite content" << endl;
	cout << "\t   13 : Display all favorite content" << endl;
	cout << "\t   14 : Display detail favorite content on screen" << endl;
	cout << "\t   15 : Rerrange Favorite Content's order" << endl;
	
	cout << "\t   ----- Character Command ----- " << endl;
	cout << "\t   21 : Display all Character content" << endl;
	cout << "\t   22 : Display detail character content on screen" << endl;

	cout << "\t   ----- Location Command ----- " << endl;
	cout << "\t   31 : Display all Location content" << endl;
	cout << "\t   32 : Display detail location content on screen" << endl;

	cout << "\t   ----- Event Command ----- " << endl;
	cout << "\t   41 : Display all Event content" << endl;
	cout << "\t   42 : Display detail event content on screen" << endl;
	
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new record into masterList.
int Application::AddContents() {
	MultimediaContent mainContent;
	cin >> mainContent;
  
  if (m_masterList.IsFull()) {    // masterList 안이 꽉 찰 경우
		cout << "\n\tList is full" << endl;
		return -1;
	}

	else {  // masterList에 추가
    m_masterList.Add(mainContent);
		
    // characterlist, locationlist, eventlist에 추가
		AddCharacter(mainContent);
		AddLocation(mainContent);
		AddEvent(mainContent);

		DisplayAllContents();
		cout << "\n\t<========ADD SUCCESS !===========>" << endl;
		return 1;
	}
}

// Get a createTime from keyboard and delete the rocord with same create Time.
int Application::DeleteContents() {
	MultimediaContent mainContent;
	mainContent.SetTimeFromKB();
  
  bool found;
	m_masterList.RetrieveItem(mainContent, found);
	
  if (m_masterList.IsEmpty()) { // masterList 안이 비어있을 경우
		cout << "\tList is empty" << endl;
		return -1;
  }

  if (found == false) { // masterList에 없는 경우
		cout << "\tThe content doesn't exist" << endl;
		return 0;
  }

  // masterlist에서 제거
  m_masterList.DeleteItem(mainContent);

	// characterlist, locationlist, eventlist에서 삭제
	DeleteMCFromCharacter(mainContent);
	DeleteMCFromLocation(mainContent);
	DeleteMCFromEvent(mainContent);

	// favoritephotolist,favoritevideolist에서 삭제
	FavoritePhotoContent photoContent;
	FavoriteVideoContent videoContent;
	photoContent.SetTime(mainContent.GetTime());
	videoContent.SetTime(mainContent.GetTime());
		
	if (m_favoritePhotoList.Retrieve_BinS(photoContent))	// favoritephotolist에 있으면 삭제
		m_favoritePhotoList.Delete(photoContent);
	if (m_favoriteVideoList.Retrieve_BinS(videoContent))	// favoritevideolist에 있으면 삭제
		m_favoriteVideoList.Delete(videoContent);

	DisplayAllContents();
	cout << "\t<========DELETE SUCCESS !===========>" << endl;
	return 1;
}

// Get a record from keyboard and Replace the rocord with same record.
int Application::ReplaceContents() {
	MultimediaContent oldMC;
	MultimediaContent mainContent;
	FavoritePhotoContent photoContent;
	FavoriteVideoContent videoContent;


	mainContent.SetTimeFromKB();
	photoContent.SetTime(mainContent.GetTime());
	videoContent.SetTime(mainContent.GetTime());
  bool found;
  m_masterList.RetrieveItem(mainContent, found);
	
  // masterlist에 존재하는 경우
	if (found == true) {
		oldMC = mainContent;
		mainContent.SetNameFromKB();
		mainContent.SetTypeFromKB();
		mainContent.SetCharacterFromKB();
		mainContent.SetLocationFromKB();
		mainContent.SetCategoryFromKB();
		mainContent.SetEventNameFromKB();
		mainContent.SetEventDescriptionFromKB();
		mainContent.SetContents();
		m_masterList.UpdateItem(mainContent);	// masterlist에 교체 완료
		
		// favoritephotolist에서 변경 작업
		if (m_favoritePhotoList.Retrieve_BinS(photoContent)) {
			if (mainContent.GetType() == 2) {	// photo -> video인 경우
				m_favoritePhotoList.Delete(photoContent);
				videoContent.SetRecordMC(mainContent);
				videoContent.SetCondition(photoContent.GetCondition());
				videoContent.SetViewNumber(photoContent.GetViewNumber());
				m_favoriteVideoList.Add(videoContent);
			}
			else {	// 타입이 변경되지 않은 경우
				photoContent.SetRecordMC(mainContent);
				m_favoritePhotoList.Replace(photoContent);
			}
		}

		// favoritevideolist에서 변경 작업
		if (m_favoriteVideoList.Retrieve_BinS(videoContent)) {
			if (mainContent.GetType() == 1) {	// video -> photo인 경우
				m_favoriteVideoList.Delete(videoContent);
				photoContent.SetRecordMC(mainContent);
				photoContent.SetCondition(videoContent.GetCondition());
				photoContent.SetViewNumber(videoContent.GetViewNumber());
				m_favoritePhotoList.Add(photoContent);
			}
			else {	// 타입이 변경되지 않은 경우
				videoContent.SetRecordMC(mainContent);
				m_favoriteVideoList.Replace(videoContent);
			}
		}

		// specific class modification
		if (oldMC.GetCharacter() != mainContent.GetCharacter()) {
			DeleteMCFromCharacter(oldMC);
			AddCharacter(mainContent);
		}

		if (oldMC.GetLocation() != mainContent.GetLocation()) {
			DeleteMCFromLocation(oldMC);
			AddLocation(mainContent);
		}

		if (oldMC.GetEventName() != mainContent.GetEventName()) {
			DeleteMCFromEvent(oldMC);
			AddEvent(mainContent);
		}

		cout << "\n\tReplacing worked";		// 모든 변경사항 변경 완료
		DisplayAllContents();

		return 1;
	}
	cout << "\n\tNot exist the Primary Key in list";
	return 0;
}

// Get a create time from keyboard and Display a record with input create time.
void Application::RetrieveContents() {
	MultimediaContent mainContent;
	mainContent.SetTimeFromKB();

  bool found;
  m_masterList.RetrieveItem(mainContent, found);
  if (found == true) {
		cout << "<============ Content Found !==========>" << endl;
		cout << mainContent << endl;
		cout << "<====================================>" << endl;
	}
	else 
		cout << "<======== Content Not Found!==========>" << endl;
}

// Display all MultimediaContents in the list in screen.
void Application::DisplayAllContents() {

	cout << "\n\t--Current list--" << endl;
  m_masterList.PrintTree(cout);
}

// Make masterList empty.
void Application::MakeEmpty() {
	m_masterList.MakeEmpty();
	
	m_favoritePhotoList.MakeEmpty();
	m_favoriteVideoList.MakeEmpty();

	m_characterList.MakeEmpty();
	m_locationList.MakeEmpty();
	m_eventList.MakeEmpty();

	cout << "List is now empty.";
}

// // Open a file by file descriptor as an input file.
// int Application::OpenInFile(char *fileName) {
// 	m_inFile.open(fileName);	// file open for reading.
	
// 	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
// 	if (!m_inFile)
// 		return 0;
// 	else
// 		return 1;
// }

// // Open a file by file descriptor as an output file.
// int Application::OpenOutFile(char *fileName) {
// 	m_outFile.open(fileName);	// file open for writing.

// 	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
// 	if (!m_outFile)
// 		return 0;
// 	else
// 		return 1;
// }

// // Open a file as a read mode, Read all data on the file, and Set list by the data.
// int Application::ReadDataFromFile() {
// 	int index = 0;
// 	MultimediaContent mainContent;	// 읽기용 임시 변수
	
// 	char filename[FILENAMESIZE];
// 	cout << "\n\tEnter Input file Name : ";
// 	cin >> filename;

// 	// file open, open error가 발생하면 0을 리턴
// 	if (!OpenInFile(filename))
// 		return 0;

// 	// 파일의 모든 내용을 읽어 list에 추가
// 	while (!m_inFile.eof()) {
// 		// array에 학생들의 정보가 들어있는 structure 저장
// 		mainContent.ReadDataFromFile(m_inFile);
// 		m_masterList.Add(mainContent);
// 	}

// 	m_inFile.close();	// file close

// 	// 현재 list 출력
// 	DisplayAllContents();

// 	return 1;
// }

// // Open a file as a write mode, and Write all data into the file,
// int Application::WriteDataToFile() {
// 	MultimediaContent mainContent;	// 쓰기용 임시 변수
	
// 	char filename[FILENAMESIZE];
// 	cout << "\n\tEnter Output file Name : ";
// 	cin >> filename;

// 	// file open, open error가 발생하면 0을 리턴
// 	if (!OpenOutFile(filename))
// 		return 0;

// 	DoublyIterator<MultimediaContent> iter(m_masterList);

// 	// iteration을 이용하여 모든 item 출력
// 	while (iter.NotNull()) {
// 		mainContent.WriteDataToFile(m_outFile);
// 		mainContent = iter.Next();
// 	}

// 	m_outFile.close();	// file close

// 	return 1;
// }


// //  @@ Favorite-Content Functions @@

// Check if record is a picture or video and Add new record into corresponding list (FavoritePhotoList or FavoriteVideoList).
int Application::AddFavoriteContent() {
	MultimediaContent mainContent;
	mainContent.SetTimeFromKB();
	bool found;
  m_masterList.RetrieveItem(mainContent, found);

	if (found == false) {
		cout << "\n\tNot exist the Primary Key in list";
		return 0;
	}

	if (mainContent.GetType() == 1) {   // Type == Photo
		FavoritePhotoContent photoContent(mainContent);	// photoContent 변수 세팅

		if (m_favoritePhotoList.GetLength() >= 1) {	// FavoritePhotoList에 이미 컨텐츠가 존재하면 m_condition 일치하게 만들기
			FavoritePhotoContent temp;
			m_favoritePhotoList.ResetList();
			m_favoritePhotoList.GetNextItem(temp);
			photoContent.SetCondition(temp.GetCondition());
		}

		int status = m_favoritePhotoList.Add(photoContent);

		if (status == 0) {
			cout << "\n\tThe content already exists" << endl;
			return 0;
		}
		else if (status == 1)
			cout << "\n\t<========ADD SUCCESS !===========>" << endl;
	}

	else if (mainContent.GetType() == 2) {   // Type == Video
		FavoriteVideoContent videoContent(mainContent);	// videoContent 변수 세팅

		if (m_favoriteVideoList.GetLength() >= 1) {		// FavoriteVideoList에 이미 컨텐츠가 존재하면 m_condition 일치하게 만들기
			FavoriteVideoContent temp;
			m_favoriteVideoList.ResetList();
			m_favoriteVideoList.GetNextItem(temp);
			videoContent.SetCondition(temp.GetCondition());
		}

		int status = m_favoriteVideoList.Add(videoContent);

		if (status == 0) {
			cout << "\n\tThe content already exists" << endl;
			return 0;
		}
		else if (status == 1)
			cout << "\n\t<========ADD SUCCESS !===========>" << endl;
	}

	return 1;
}

// Get a create time from keyboard and Delete the rocord with same create time.
int Application::DeleteFavoriteContent() {
	MultimediaContent mainContent;
	mainContent.SetTimeFromKB();
	
  bool found;
  m_masterList.RetrieveItem(mainContent, found);
	if (found == false) {
		cout << "\n\tNot exist the Primary Key in list";
		return 0;
	}
	
	if (mainContent.GetType() == 1) {   // Type == Photo
		FavoritePhotoContent photoContent;
		photoContent.SetTime(mainContent.GetTime());
		
		int status = m_favoritePhotoList.Delete(photoContent);

		if (status == -1) {
			cout << "\tList is empty" << endl;
			return -1;
		}
		else if (status == 0) {
			cout << "\tThe content doesn't exist" << endl;
			return 0;
		}

		else {
			cout << "\t<========DELETE SUCCESS !===========>" << endl;
			return 1;
		}
	}
	
	else if (mainContent.GetType() == 2) {   // Type == Video
		FavoriteVideoContent videoContent;
		videoContent.SetTime(mainContent.GetTime());

		int status = m_favoriteVideoList.Delete(videoContent);

		if (status == -1) {
			cout << "\tList is empty" << endl;
			return -1;
		}

		else if (status == 0) {
			cout << "\tThe content doesn't exist" << endl;
			return 0;
		}

		else {
			cout << "\t<========DELETE SUCCESS !===========>" << endl;
			return 1;
		}
	}
	return 1;
}

// Get the list want to see from keyboard and Display all records in the corresponding list in screen.
void Application::DisplayAllFavoriteContent() {
	cout << "\n\t--Current Favorite Photo list--" << endl;

	m_favoritePhotoList.ResetList();
	int length = m_favoritePhotoList.GetLength();

	for (int i = 0; i < length; i++) {
		FavoritePhotoContent photoContent;
		m_favoritePhotoList.GetNextItem(photoContent);
		photoContent.SetViewNumber(photoContent.GetViewNumber() + 1);	// 조회 수 1 증가
		m_favoritePhotoList.Replace(photoContent);	// 조회 수 1 증가 된 photoContent를 favoritePhotoList에 업데이트
		cout << photoContent << endl;	// 출력
	}

	cout << "\n\t--Current Favorite Video list--" << endl;
	
	m_favoriteVideoList.ResetList();
	length = m_favoriteVideoList.GetLength();
	
	for (int i = 0; i < length; i++) {
		FavoriteVideoContent videoContent;
		m_favoriteVideoList.GetNextItem(videoContent);
		videoContent.SetViewNumber(videoContent.GetViewNumber() + 1);	// 조회 수 1 증가
		m_favoriteVideoList.Replace(videoContent);	// 조회 수 1 증가 된 videoContent를 favoriteVideoList에 업데이트
		cout << videoContent << endl;	// 출력
	}
}

// Display detail information of the specific record in screen.
void Application::DisplayDetailFC() {
	MultimediaContent mainContent;
	mainContent.SetTimeFromKB();
	
  bool found;
  m_masterList.RetrieveItem(mainContent, found);
	
  if (found == false)
		cout << "\n\tNot exist the Primary Key in list";

	if (mainContent.GetType() == 1) {   // Type == Photo
		FavoritePhotoContent photoContent;
		photoContent.SetTime(mainContent.GetTime());
		
		if (m_favoritePhotoList.Retrieve_BinS(photoContent)) {
			photoContent.SetViewNumber(photoContent.GetViewNumber() + 1);	// 조회 수 1 증가
			m_favoritePhotoList.Replace(photoContent);		// 조회 수 1 증가 된 photoContent를 favoritePhotoList에 업데이트
			mainContent.SetTime(photoContent.GetTime());
			m_masterList.RetrieveItem(mainContent, found);
			cout << "\n\tCurrent list" << endl;
			cout << mainContent;	// 출력
		}
		else
			cout << "\n\tNot exist in Favorite Photo list" << endl;
	}

	else if (mainContent.GetType() == 2) {   // Type == Photo
		FavoriteVideoContent videoContent;
		videoContent.SetTime(mainContent.GetTime());
		
		if (m_favoriteVideoList.Retrieve_BinS(videoContent)) {
			videoContent.SetViewNumber(videoContent.GetViewNumber() + 1);	// 조회 수 1 증가
			m_favoriteVideoList.Replace(videoContent);	// 조회 수 1 증가 된 videoContent를 favoriteVideoList에 업데이트
			mainContent.SetTime(videoContent.GetTime());
			m_masterList.RetrieveItem(mainContent, found);
			cout << "\n\tCurrent list" << endl;
			cout << mainContent;	// 출력
		}
		else
			cout << "\n\tNot exist in Favorite Video list" << endl;
	}
}
	
// Get the condition by keyboard and Rearrange order of FavoriteContent elements.
void Application::RearrangeFC() {
	int listType;
	int condition;
	cout << "\n\tChoose the list Rearranging (1. Favorite Photo List, 2. Favorite Video List) : ";
	cin >> listType;

	if (listType == 1) {	// Type -> Photo
		SortedList<FavoritePhotoContent> tmpPhotoList = m_favoritePhotoList;	// Favorite Photo Content List.
		int length = m_favoritePhotoList.GetLength();
		
		m_favoritePhotoList.MakeEmpty();
		tmpPhotoList.ResetList();

		cout << "\n\tEnter the condition to see in what order (1. createTime, 2. contentName, 3. viewNumber) : ";
		cin >> condition;

		if (!(condition == 1 || condition == 2 || condition == 3)) {	// 1, 2, 3 외의 숫자를 입력한 경우
			cout << "\n\tEnter 1 or 2 or 3" << endl;
			return;
		}
		
		for (int i = 0; i < length; i++) { 
			FavoritePhotoContent photoContent;
			tmpPhotoList.GetNextItem(photoContent);
			photoContent.SetCondition(condition);
			m_favoritePhotoList.Add(photoContent);
		}
		DisplayAllFavoriteContent();
		cout << "\n\t<========Modification SUCCESS !===========>" << endl;
	}

	else if (listType == 2) {	// Type -> Video
		SortedList<FavoriteVideoContent> tmpVideoList = m_favoriteVideoList;	// Favorite Video Content List.
		int length = m_favoriteVideoList.GetLength();

		m_favoriteVideoList.MakeEmpty();
		tmpVideoList.ResetList();

		cout << "\n\tEnter the condition to see in what order (1. createTime, 2. contentName, 3. viewNumber) : ";
		cin >> condition;
	
		if (!(condition == 1 || condition == 2 || condition == 3)) {	// 1, 2, 3 외의 숫자를 입력한 경우
			cout << "\n\tEnter 1 or 2 or 3" << endl;
			return;
		}

		for (int i = 0; i < length; i++) { 
			FavoriteVideoContent videoContent;
			tmpVideoList.GetNextItem(videoContent);
			videoContent.SetCondition(condition);
			m_favoriteVideoList.Add(videoContent);
		}
		DisplayAllFavoriteContent();
		cout << "\n\t<========Modification SUCCESS !===========>" << endl;
	}

	else	// 1, 2 외의 숫자를 입력한 경우
		cout << "\n\tEnter 1 or 2" << endl;
}


//  @@ Character Functions @@

// Display all Character record in the list on screen.
void Application::DisplayAllCharacter() {
	CharacterContent character;

	m_characterList.ResetList();
	cout << "\n\t--Current Character list--" << endl;

	for (int i = 0; i < m_characterList.GetLength(); i++) {
		m_characterList.GetNextItem(character);
		cout << character << endl;
	}
}

// Add CreateTime into CreateTime List of CharacterContent.
void Application::AddCharacter(MultimediaContent& _mainContent) {
	CharacterContent character;
	character.SetName(_mainContent.GetCharacter());
		
	if (!m_characterList.Get(character)) {	// chracterlist안에 같은 character name이 존재하지 않은 경우
		character.AddCreateTime(_mainContent.GetTime());
		m_characterList.Add(character);	// character name 신규 추가
	}

	else {	// chracterlist안에 이미 같은 character name이 존재하는 경우
		character.AddCreateTime(_mainContent.GetTime());
		m_characterList.Replace(character);	// 변경된 사항 characterList에 업데이트
	}
}

// Search createTime from Location Record and Get detail content records.
void Application::SearchMCFromCharacter() {
	CharacterContent character;
	character.SetNameFromKB();

	if (m_characterList.Get(character)) {
		character.SearchAtMasterList(m_masterList);	// 디테일 정보 출력
	}
	else {
		cout << "\tNot Exist Character in list." << endl;
		DisplayAllCharacter();
	}
}

// Delete createTime into CreateTime List of CharacterContent.
void Application::DeleteMCFromCharacter(MultimediaContent& _mainContent) {
	CharacterContent character;
	character.SetName(_mainContent.GetCharacter());

	if (m_characterList.Get(character)) {
		if (character.GetCount() == 1) {	// characterList에 같은 character가 하나인 경우
			m_characterList.Delete(character);
		}
		else {	// characterList에 같은 character가 둘 이상인 경우
			character.DeleteCreateTime(_mainContent.GetTime());
			m_characterList.Replace(character);	// 변경된 사항 characterList에 업데이트
		}
	}
}

//  @@ Location Functions @@

// Display all Location record in the list on screen.
void Application::DisplayAllLocation() {
	LocationContent location;

	m_locationList.ResetList();
	cout << "\n\t--Current Location list--" << endl;

	for (int i = 0; i < m_locationList.GetLength(); i++) {
		m_locationList.GetNextItem(location);
		cout << location << endl;
	}
}

// Add CreateTime into CreateTime List of LocationContent.
void Application::AddLocation(MultimediaContent& _mainContent) {
	LocationContent location;
	location.SetName(_mainContent.GetLocation());

	if (!m_locationList.Get(location)) {	// locationlist안에 같은 location이 존재하지 않은 경우
		location.AddCreateTime(_mainContent.GetTime());
		m_locationList.Add(location);	// location 신규 추가
	}

	else {		// locationlist안에 이미 같은 location이 존재하는 경우
		location.AddCreateTime(_mainContent.GetTime());
		m_locationList.Replace(location);	// 변경된 사항 locationlist 업데이트
	}
}

// Search createTime from Location Record and Get detail content records.
void Application::SearchMCFromLocation() {
	LocationContent location;
	location.SetNameFromKB();

	if (m_locationList.Get(location)) {
		location.SearchAtMasterList(m_masterList);	// 디테일 정보 출력
	}
	else {
		cout << "\tNot Exist Location in list." << endl;
		DisplayAllLocation();
	}
}

// Delete createTime into CreateTime List of LocationContent.
void Application::DeleteMCFromLocation(MultimediaContent& _mainContent) {
	LocationContent location;
	location.SetName(_mainContent.GetLocation());

	if (m_locationList.Get(location)) {
		if (location.GetCount() == 1)	// locationList에 같은 location가 하나인 경우
			m_locationList.Delete(location);
		
		else {		// locationList에 같은 location가 둘 이상인 경우
			location.DeleteCreateTime(_mainContent.GetTime());
			m_locationList.Replace(location);	// 변경된 사항 locationlist 업데이트
		}
	}
}

//  @@ Event Functions @@

// Display all Event record in the list on screen.
void Application::DisplayAllEvent() {
	EventContent event;

	m_eventList.ResetList();
	cout << "\n\t--Current Event list--" << endl;

	for (int i = 0; i < m_eventList.GetLength(); i++) {
		m_eventList.GetNextItem(event);
		cout << event << endl;
	}
}

// Add CreateTime into CreateTime List of EventContent.
void Application::AddEvent(MultimediaContent& _mainContent) {
	EventContent event;
	event.SetRecord(_mainContent.GetEventName(), _mainContent.GetEventDescription());
		
	if (!m_eventList.Get(event)) {	// evnetList안에 같은 event가 존재하지 않은 경우
		event.AddCreateTime(_mainContent.GetTime());
		m_eventList.Add(event);	// event 신규 추가
	}

	else {	// evnetList안에 이미 같은 event가 존재하는 경우
		event.AddCreateTime(_mainContent.GetTime());
		m_eventList.Replace(event);		// 변경된 사항 evnetList 업데이트
	}
}

// Search createTime from Event Record and Get detail content records.
void Application::SearchMCFromEvent() {
	EventContent event;
	event.SetNameFromKB();

	if (m_eventList.Get(event)) {
		event.SearchAtMasterList(m_masterList);		// 디테일 정보 출력
	}
	else {
		cout << "\tNot Exist Event in list." << endl;
		DisplayAllEvent();
	}
}

// Delete createTime into CreateTime List of EventContents.
void Application::DeleteMCFromEvent(MultimediaContent& _mainContent) {
	EventContent event;
	event.SetName(_mainContent.GetEventName());

	if (m_eventList.Get(event)) {
		if (event.GetCount() == 1)		// eventList에 같은 event가 하나인 경우
			m_eventList.Delete(event);
		
		else {		// eventList에 같은 event가 둘 이상인 경우
			event.DeleteCreateTime(_mainContent.GetTime());
			m_eventList.Replace(event);		// 변경된 사항 evnetList 업데이트
		}
	}
}

//	Search content by combining one or more keys

// // Search MultiContent Record by combining one or more Primary KEYs.
// void Application::SearchMCFromPks() {
// 	MultimediaContent   mainContent;
// 	CharacterContent    character;
// 	LocationContent     location;
// 	EventContent        event;

// 	UnsortedList<string> inputKeyList;
// 	SortedSinglyLinkedList<MultimediaContent> tmpList;

// 	string inputKey = "";
// 	int countKey = 0;

// 	// 키 입력 받기
// 	while (1) {
// 		cout << "\n\tInput Searching Keys (Quit 'q'): ";
// 		cin >> inputKey;
// 		if (inputKey == "q")
// 			break;
// 		countKey++;
// 		inputKeyList.Add(inputKey);
// 	}

// 	// 입력 된 키의 종류(character, location, event) 확인하기
// 	for (int i = 0; i < countKey; i++) {
// 		character.SetName(inputKeyList[i]);
// 		location.SetName(inputKeyList[i]);
// 		event.SetName(inputKeyList[i]);

// 		if (m_characterList.Get(character))
// 			mainContent.SetCharacter(character.GetName());

// 		if (m_locationList.Get(location))
// 			mainContent.SetLocation(location.GetName());

// 		if (m_eventList.Get(event))
// 			mainContent.SetEventName(event.GetName());
// 	}

// 	bool isFind = false;
// 	cout << "\n\t<====================================>" << endl;
	
// 	if (countKey == 1) {	// 입력된 키가 하나인 경우
// 		if (searchKeyFromCharacter(mainContent, tmpList, 1))		// 키가 character인지?
// 			isFind = true;
		
// 		else if (searchKeyFromLocation(mainContent, tmpList, 1))	// 키가 location인지?
// 			isFind = true;

// 		else if (searchKeyFromEvent(mainContent, tmpList, 1))		// 키가 event인지?
// 			isFind = true;
// 	}

// 	else if (countKey == 2) {	// 입력된 키가 두개인 경우
// 		if (searchKeyFromCharacter(mainContent,tmpList, 1)) {		// 키가 character인지?

// 			if (searchKeyFromLocation(mainContent, tmpList, 0))		// 키가 character이고 location인지?
// 				isFind = true;
			
// 			else if (searchKeyFromEvent(mainContent, tmpList, 0))	// 키가 character이고 event인지?
// 				isFind = true;
// 		}

// 		else if (searchKeyFromLocation(mainContent, tmpList, 1))	// 키가 location인지?

// 			if (searchKeyFromEvent(mainContent, tmpList, 0))		// 키가 location이고 event인지?
// 				isFind = true;
// 	}

// 	else if (countKey == 3) {		// 입력된 키가 세 개인 경우
// 		if (searchKeyFromCharacter(mainContent, tmpList, 1))		// 키가 character인지?
// 			if (searchKeyFromLocation(mainContent, tmpList, 0))		// 키가 character이고 location인지?
// 				if (searchKeyFromEvent(mainContent, tmpList, 0))	// 키가 character, location이고 event인지?
// 					isFind = true;
// 	}

// 	if (isFind) {
// 		MultimediaContent tmp;
// 		tmpList.ResetList();

// 		for (int i = 0; i < tmpList.GetLength(); i++) {		// 같은 키를 포함하는 MultimediaContent 정보 출력
// 			tmpList.GetNextItem(tmp);
// 			cout << tmp << endl;
// 		}

// 		cout << "\t<============I FOUND CONTENT !==========>" << endl;
// 	}

// 	else
// 		cout << "\n\t<========I CAN'T FIND CONTENT !==========>" << endl;
// }

// // Search MultiContent Record with PK of Character Class
// bool Application::searchKeyFromCharacter(MultimediaContent& _mc, SortedSinglyLinkedList<MultimediaContent>& _list, bool _condition) {
// 	bool isFind = false;
	
// 	DoublyIterator<MultimediaContent> iter(m_masterList);
	
// 	// masterList 한바퀴 돌기
// 	while (iter.NotNull()) {
// 		if (_mc.GetCharacter().find(iter.GetCurrentNode().data.GetCharacter(),0) != -1) {// 동일한 character인 경우
// 			MultimediaContent tmp = iter.GetCurrentNode().data;
// 			_list.Add(tmp);		// _list에 추가
// 			isFind = true;
// 		}
// 		iter.Next();
// 	}
	
// 	if (isFind)
// 		return true;
// 	else
// 		return false;
// }

// // Search MultiContent Record with PK of Location Class
// bool Application::searchKeyFromLocation(MultimediaContent& _mc, SortedSinglyLinkedList<MultimediaContent>& _list, bool _condition) {
// 	bool isFind = false;
	
// 	if (_condition) {	// 그 전에 키를 파악하지 못한 경우
// 		DoublyIterator<MultimediaContent> iter(m_masterList);
		
// 		// masterList 한바퀴 돌기
// 		while (iter.NotNull()) {
// 			if (_mc.GetLocation().find(iter.GetCurrentNode().data.GetLocation(),0) != -1) {	// 동일한 Location인 경우
// 				MultimediaContent tmp = iter.GetCurrentNode().data;
// 				_list.Add(tmp);		// _list에 추가
// 				isFind = true;
// 			}
// 			iter.Next();
// 		}
// 	}

// 	else {	// 그 전에 다른 키가 존재하여 파악한 경우
// 		MultimediaContent mainContent;
// 		SortedSinglyLinkedList<MultimediaContent> tmpList;
// 		_list.ResetList();
		
// 		for (int i = 0; i < _list.GetLength(); i++) {	// _list 한바퀴 돌기
// 			_list.GetNextItem(mainContent);

// 			if (_mc.GetLocation() == mainContent.GetLocation()) {	// 동일한 Location인 경우
// 				tmpList.Add(mainContent);	// tmpList에 추가
// 				isFind = true;
// 			}
// 		}
// 		_list = tmpList;	// tmpList를 _List에 할당
// 	}

// 	if (isFind)
// 		return true;
// 	else
// 		return false;
// }

// // Search MultiContent Record with PK of Event Class
// bool Application::searchKeyFromEvent(MultimediaContent& _mc, SortedSinglyLinkedList<MultimediaContent>& _list, bool _condition) {
// 	bool isFind = false;
	
// 	if (_condition) {	// 그 전에 키를 파악하지 못한 경우
// 		DoublyIterator<MultimediaContent> iter(m_masterList);
		
// 		// masterList 한바퀴 돌기
// 		while (iter.NotNull()) {	
// 			if (_mc.GetEventName().find(iter.GetCurrentNode().data.GetEventName(),0) != -1) {	// 동일한 Event인 경우
// 				MultimediaContent tmp = iter.GetCurrentNode().data;
// 				_list.Add(tmp);		// _list에 추가
// 				isFind = true;
// 			}
// 			iter.Next();
// 		}
// 	}
	
// 	else {	// 그 전에 다른 키가 존재하여 파악한 경우
// 		MultimediaContent mainContent;
// 		SortedSinglyLinkedList<MultimediaContent> tmpList;
// 		_list.ResetList();
		
// 		for (int i = 0; i < _list.GetLength(); i++) {	// _list 한바퀴 돌기
// 			_list.GetNextItem(mainContent);

// 			if (_mc.GetEventName() == mainContent.GetEventName()) {	// 동일한 Event인 경우
// 				tmpList.Add(mainContent);	// tmpList에 추가
// 				isFind = true;
// 			}
// 		}
// 		_list = tmpList;	// tmpList를 _List에 할당
// 	}

// 	if (isFind)
// 		return true;
// 	else
// 		return false;
// }