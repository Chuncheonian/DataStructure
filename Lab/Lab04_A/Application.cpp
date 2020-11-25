#include "Application.h"

// Program driver.
void Application::Run() {
	while(1) {
		m_nCurCommand = GetCommand();

		switch(m_nCurCommand) {
		case 1:		// insert Student Record
			AddStudent();
			break;
		case 2:		// display all student records.
			DisplayAllStudent();
			break;
		case 3:		// make the list empty
			MakeEmpty();
			break;
		case 4:		// retrieves Student Record.
			SearchById_BinS();
			break;
		case 5:		// delete a Student Record.
			DeleteStudent();
			break;
		case 6:		// change value of an item
			ReplaceStudent();
			break;
		case 7:		// get data from data file
			ReadDataFromFile();
			break;
		case 8:		// put data to data file
			WriteDataToFile();
			break;
		case 9:		// insert Department Record.
			AddDept();
			break;
		case 10:	// display all department records.
			DisplayAllDept();
			break;
		case 11:	// insert a student ID into ID List in Department record.
			InsertStudentIntoDept();
			break;
		case 12:	// display detail student record in Department record.
			SearchStudentFromDept();
			break;
		case 0:		// quit
			return;
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
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Insert Item" << endl;
	cout << "\t   2 : Display all Item" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Delete Item" << endl;
	cout << "\t   6 : Update item" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file" << endl;
	cout << "\t   9 : Add Department" << endl;
	cout << "\t   10 : Display all department" << endl;
	cout << "\t   11 : Add Student Id to dept List" << endl;
	cout << "\t   12 : Search Students from dept" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//  Add new record into sorted list.
void Application::AddStudent() {			// case 1
	StudentType addItem;
	addItem.SetRecordFromKB();

	int status = masterList.Add(addItem);

	if (status == -1)
		cout << "\n\t--List is full--" << endl;
	else if (status == 0)
		cout << "\n\t--The content already exists--" << endl;
	else {
		cout << "\n\t<========ADD SUCCESS !===========>" << endl;
    	DisplayAllStudent();
	}
}

// Display all records in the list in screen.
void Application::DisplayAllStudent() {		// case 2
	StudentType data;

	cout << "\n\tCurrent Student list" << endl;

	masterList.ResetList();
	int length = masterList.GetLength();
	int curIndex = masterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1) {
		cout << data << endl;
		curIndex = masterList.GetNextItem(data);
	}
}

// Make empty list.
int Application::MakeEmpty() {				// case 3
	masterList.MakeEmpty();
	cout << "List is now empty.";
	return 0;
}

// Searching for same student ID by Binary search and Get the data.
void Application::SearchById_BinS() {		// case 4
	StudentType searchItem;
	searchItem.SetIdFromKB();

	if (masterList.Retrieve_BinS(searchItem)) {
		cout << "<============ Content Found !==========>" << endl;
		searchItem.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
	}
	else 
		cout << "<======== Content Not Found!==========>" << endl;
}

// get a student ID from keyboard and delete the rocord with same content name.
void Application::DeleteStudent() {		// case 5
	StudentType delItem;
	delItem.SetIdFromKB();

	int status = masterList.Delete(delItem);

	if (status == -1)
		cout << "\tList is empty" << endl;
	else if (status == 0)
		cout << "\tThe content doesn't exist" << endl;
	else {
		cout << "\t<========DELETE SUCCESS !===========>" << endl;
		DeleteStudentFromDept(delItem);
		DisplayAllStudent();
	}
}

// get a record from keyboard and replace the rocord with same record.
int Application::ReplaceStudent() {		// case 6
	cout << "\tEnter new content info" << endl;
	
	StudentType replaceItem;
	replaceItem.SetRecordFromKB();

	masterList.Replace(replaceItem);

	return 0;
}

// Add new record into list.
int Application::AddDept() {			// case 9
	DeptType dept;

	cout << "\tInput dept" << endl;
	dept.SetNameFromKB();	// 추가할 정보를 입력한다.
	depList.Add(dept);		// 리스트에 항목을 추가한다.
	DisplayAllDept();		// 리스트를 화면에 출력한다.

	return 1;
}

// Display all records in the list on screen.
void Application::DisplayAllDept() {	// case 10
	DeptType dept;

	depList.ResetList();	// 리스트 초기화
	cout << "\n\t--Current dept list--" << endl;
	// list의 모든 데이터를 화면에 출력
	for (int i = 0; i < depList.GetLength(); i++) {
		depList.GetNextItem(dept);
		dept.DisplayRecordOnScreen();
	}
}

// Add Student ID into ID List of Department Type.
void Application::InsertStudentIntoDept() {	// case 11
	StudentType	student;
	DeptType	dept;

	student.SetIdFromKB();
	dept.SetNameFromKB();

	// 학번하고 학과 이름 둘 다 리스트에 존재하고 그 정보 가지고 오기.
	if (masterList.Retrieve_BinS(student) && depList.Get(dept)) {
		dept.AddId(student.GetId());
		depList.Replace(dept);		// depList에 바뀐 정보 업데이트
		DisplayAllDept();
	}
	else {		// 학번, 학과 이름 둘 중 하나라도 리스트에 없는 경우
		cout << "\tNot Exist Record in list.";
		DisplayAllDept();
	}
}

// Search student ID from Deparment Record and Get student detail record.
void Application::SearchStudentFromDept() {		// case 12
	DeptType dept;
	dept.SetNameFromKB();

	// 정보 가지고 오기
	if (depList.Get(dept)) {
		dept.SearchAtMasterList(masterList);
	}
	else {
		cout << "\tNot Exist Department Name in list." << endl;
		DisplayAllDept();
	}
}

// Delete student ID into IdList in deptList.
int Application::DeleteStudentFromDept(StudentType& _student) {
	DeptType dept;
	int delId = _student.GetId();

	depList.ResetList();	// 리스트 초기화

	for (int i = 0; i < depList.GetLength(); i++) {
		depList.GetNextItem(dept);
		if (dept.DeleteId(delId)) {
			depList.Replace(dept);
			cout << "\n\tDeleted " << delId << " Successfully." << endl;
			return 1;
		}
	}

	// cout << "\tNot Exist Record in list.";
	cout << "\n\t" << delId << " is not found." << endl;
	return 0;
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName) {
	m_InFile.open(fileName);	// file open for reading.
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)
        return 0;
	else
        return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName) {
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)
        return 0;
	else
        return 1;
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {       // case 7
	StudentType data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof()) {
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		masterList.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllStudent();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {        // case 8
	StudentType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	masterList.ResetList();

	// list의 길이를 리턴받아 저장
	int length = masterList.GetLength();

	// iteration을 이용하여 모든 item 출력
	for (int i=0;i<length;i++) {
		masterList.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
        
		if (i!=length-1)
			m_OutFile << endl;
	}

	m_OutFile.close();	// file close

	return 1;
}