#include "Application.h"

// Program driver.
void Application::Run() {
    while(1) {
        m_command = GetCommand();
        switch (m_command) {
            case 1:
                AddItem();
                break;
            case 2:
                DeleteItem();
                break;
            case 3:
                Replace();
                break;
            case 4:
                RetrieveStudent();
                break;
            case 5:
                DisplayAllItem();
                break;
            case 6:
                MakeEmpty();
                break;
            case 7:
                ReadDataFromFile();
                break;
            case 8:
                WriteDataToFile();
                break;
            case 0:
                return;
            default:
                cout << "\tIllegal selection...\n";
                break;
        }
    }           
}

// Display command on screen and Get a input from keyboard.
int Application::GetCommand() {
    int command;
	cout << endl << endl;
	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item" << endl; 
	cout << "\t   5 : Print all on screen " << endl;
    cout << "\t   6 : Make empty list " << endl; 
    cout << "\t   7 : Get from file " << endl; 
    cout << "\t   8 : Save item " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new record into list.
void Application::AddItem() {		// case 1
	ItemType selectItem;
	selectItem.SetRecordFromKB();
	
	int status = m_list.Add(selectItem);

	if (status == -1)
        cout << "\n\tList is full" << endl;
	
	else if (status == 0)
        cout << "\n\tExist the student ID in list";

	else if (status == 1)
		cout << "\n\t<========ADD SUCCESS !===========>" << endl;
	
	DisplayAllItem();
}

// Get a PK from keyboard and Delete the rocord with same PK.
void Application::DeleteItem() {	// case 2
	ItemType selectItem;
	selectItem.SetNameFromKB();

	int status = m_list.Delete(selectItem);

	if (status == -1)
		cout << "\tList is Empty. Add new data and Try again." << endl;

	else if (status == 0)
		cout << "\n\tNot exist the student ID in list";

	else if (status == 1)
		cout << "\t<========DELETE SUCCESS !===========>" << endl;

	DisplayAllItem();
}

// Get a Primary Key from keyboard and Replace the rocord with same Primary Key.
int Application::Replace() {		// case 3
	ItemType selectItem;
	selectItem.SetNameFromKB();

	if (m_list.Get(selectItem)) {
		selectItem.SetTypeFromKB();
		selectItem.SetTimeFromKB();
		selectItem.SetCharacterFromKB();
		selectItem.SetEventNameFromKB();
		m_list.Replace(selectItem);
		cout << "\n\tReplacing worked";
		DisplayAllItem();

		return 1;
	}

	cout << "\n\tNot exist the Primary Key in list";
	return 0;
}

// Get a student ID from keyboard and Display a record with input student ID.
int Application::RetrieveStudent() {	// case 4
	ItemType selectItem;
	selectItem.SetNameFromKB();

	if (m_list.Get(selectItem)) {
		selectItem.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\n\tNot exist the student ID in list";
		return 0;
	}
}

// Display all records in the list in screen.
void Application::DisplayAllItem() {	// case 5
    ItemType data;

	cout << "\n\tCurrent list" << endl;

	m_list.ResetList();
	int length = m_list.GetLength();
	int curIndex = m_list.GetNextItem(data);

	while(curIndex < length && curIndex != -1) {
		data.DisplayRecordOnScreen();
		curIndex = m_list.GetNextItem(data);
	}
}

// Make list empty.
void Application::MakeEmpty() {			// case 6
	m_list.MakeEmpty();
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName) {
    m_inFile.open(fileName);

    if (!m_inFile)
		return 0;
    else
		return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName) {
  	m_outFile.open(fileName);

	if(!m_outFile)
		return 0;
	else
		return 1;
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {		// case 7
	int index = 0;
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;
	
	while (!m_inFile.eof()) {
		data.ReadDataFromFile(m_inFile);

		if (m_inFile.eof())
			break;

		m_list.Add(data);
	}

	m_inFile.close();
	DisplayAllItem();

	return 1;
}

// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {		// casae 8
	ItemType data;
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	m_list.ResetList();
	
	int length = m_list.GetLength();
	int curIndex = m_list.GetNextItem(data);
	while(curIndex < length && curIndex != -1) {
		data.WriteDataToFile(m_outFile);
		curIndex = m_list.GetNextItem(data);
	}

	m_outFile.close();
	return 1;
}
