#include "Application.h"

// Program driver.
void Application::Run() {
	while (1) {
		m_Command = GetCommand();

		switch (m_Command) {
		    case 1:		// read a record and add to list.
			    AddContent();
			    break;
		    case 2:		// delete
			    DeleteContent();
			    break;
		    case 3:		// replace
			    ReplaceContent();
			    break;
		    case 4:		// search content name by sequential search.
			    SearchByName_SeqS();
			    break;
		    case 5:		// search content name by binary search.
			    SearchByName_BinS();
			    break;
		    case 6:		// search by character.
                SearchByCharacter();
			    break;
		    case 7:		// display all the records in list on screen.
			    DisplayAllContent();
			    break;
		    case 8:		// make empty list.
			    m_List.MakeEmpty();
			    break;
		    case 9:		// load list data from a file.
			    ReadDataFromFile();
			    break;
		    case 10:	// save list data into a file.
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

// Display command on screen and get a input from keyboard.
int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add content" << endl;
	cout << "\t   2 : Delete content" << endl;
	cout << "\t   3 : Replace content" << endl;
	cout << "\t   4 : Search content by Name(SS)" << endl;
	cout << "\t   5 : Search content by Name(BS)" << endl;
	cout << "\t   6 : Search content by Character" << endl;
	cout << "\t   7 : Print all on screen" << endl;
	cout << "\t   8 : Make empty list" << endl;
	cout << "\t   9 : Get from file" << endl;
	cout << "\t   10 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}
 
// Add new record into sorted list.
void Application::AddContent() {	// case 1
	ItemType selectItem;
	selectItem.SetRecordFromKB();

	int status = m_List.Add(selectItem);

	if (status == -1)
		cout << "\n\tList is full" << endl;

	else if (status == 0)
		cout << "\n\tThe content already exists" << endl;

	else if (status == 1)
		cout << "\n\t<========ADD SUCCESS !===========>" << endl;

    DisplayAllContent();
}

// Get a PK from keyboard and Delete the rocord with same PK.
void Application::DeleteContent() {		// case 2
	ItemType selectItem;
	selectItem.SetNameFromKB();

	int status = m_List.Delete(selectItem);

	if (status == -1)
		cout << "\tList is empty" << endl;

	else if (status == 0)
		cout << "\tThe content doesn't exist" << endl;

	else if (status == 1)
		cout << "\t<========DELETE SUCCESS !===========>" << endl;
	
	DisplayAllContent();
}

// Get a Primary Key from keyboard and Replace the rocord with same Primary Key.
int Application::ReplaceContent() {		// case 3
	ItemType selectItem;
	selectItem.SetNameFromKB();
	
	if (m_List.Retrieve_BinS(selectItem)) {
	    selectItem.SetTypeFromKB();
    	selectItem.SetTimeFromKB();
    	selectItem.SetCharacterFromKB();
    	selectItem.SetCategoryFromKB();
    	selectItem.SetEventNameFromKB();
    	selectItem.SetEventDescriptionFromKB();
		m_List.Replace(selectItem);
		cout << "\n\tReplacing worked";
		DisplayAllContent();

		return 1;
	}
	cout << "\n\tNot exist the Primary Key in list";
	return 0;
}

// Searching for same content Name by Sequential search and Get the data.
void Application::SearchByName_SeqS() {		// case 4
	ItemType searchItem;
	searchItem.SetNameFromKB();

	if (m_List.Retrieve_SeqS(searchItem)) {
		cout << "\n\t<============ Content Found !==========>" << endl;
		searchItem.DisplayRecordOnScreen();
		cout << "\t<====================================>" << endl;
	}
	else {
		cout << "\n\t<======== Content Not Found!==========>" << endl;
	}
}

// Searching for same content Name by Binary search and Get the data.
void Application::SearchByName_BinS() {		// case 5
	ItemType searchItem;
	searchItem.SetNameFromKB();

	if (m_List.Retrieve_BinS(searchItem)) {
		cout << "\n\t<============ Content Found !==========>" << endl;
		searchItem.DisplayRecordOnScreen();
		cout << "\t<====================================>" << endl;
	}
	else 
		cout << "\n\t<======== Content Not Found!==========>" << endl;
}

// Get a character from keyboard and Display a record with input character. 
int Application::SearchByCharacter() {		// case 6
	ItemType item;
	item.SetCharacterFromKB();

	if (SearchAllContentByCharacter(item))
		return 1;
	return 0;
}

// get a character from keyboard and display a record with input character.
int Application::SearchAllContentByCharacter(ItemType& data) {
	ItemType tmp;
	int result = 0;

	m_List.ResetList();
	while (m_List.GetNextItem(tmp) != -1) {
		if (tmp.GetCharacter() == data.GetCharacter()) {
			if (result == 0)
				cout << "<============I FOUND CONTENT !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;
		}
	}
	if (result)
		cout << "<====================================>" << endl;
	else
		cout << "<========I CAN'T FIND CONTENT !==========>" << endl;
	return result;
}

// Display all records in the list in screen.
void Application::DisplayAllContent() {		// case 7
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);

	while (curIndex < length && curIndex != -1) {
		cout << data << endl;
		curIndex = m_List.GetNextItem(data);
	}
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);

	if (!m_InFile)
        return 0;	// file open fail
	else
        return 1;	// file open success
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);

	if (!m_OutFile)
        return 0;	// file open fail
	else
        return 1;	// file open success
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {		// case 9
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_InFile.eof()) {
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();

    DisplayAllContent();
	return 1;
}

// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {		// case 10
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	m_List.ResetList();

	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1) {
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();
	return 1;
}