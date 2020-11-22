#include "Application.h"

// Program driver.
void Application::Run() {
    while(1) {
        m_command = GetCommand();

        switch(m_command) {
            case 1:
                AddContents();
                break;
            case 2:
                DeleteContents();
                break;
            case 3:
                ReplaceContents();
                break;
            case 4:
                RetrieveContents();
                break;
            case 5:
                DisplayAllContents();
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
	    	case 9:
                AddFC();       
                break;
		    case 10:
			    DeleteFC();
			    break;
            case 11:
			    DisplayAllFC();
			    break;
            case 12:
			    DisplayDetailFC();
			    break;
            case 13:
                DisplayEventList();
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
	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : Add content" << endl;
	cout << "\t   2 : Delete content" << endl;
	cout << "\t   3 : Replace content" << endl;
	cout << "\t   4 : Search content" << endl;
	cout << "\t   5 : Print all content on screen" << endl;
    cout << "\t   6 : Make empty list" << endl;
    cout << "\t   7 : Get from file " << endl;
    cout << "\t   8 : Save item " << endl;
    cout << "\t   9 : Add favorite content" << endl;
    cout << "\t   10 : Delete favorite content" << endl;
    cout << "\t   11 : Print all favorite content on screen" << endl;
    cout << "\t   12 : Print Detail content on screen " << endl;
    cout << "\t   13 : Print Event content on screen " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Add new record into list.
int Application::AddContents() {
    if (m_listMC.IsFull()) {
        cout << "List is full" << endl;
        return 0;
    }

    MultimediaContent selectItem;
    
    cin >> selectItem;
    m_listMC.Add(selectItem);
    m_event.AddMC(selectItem);      // input information of event class.
    
    DisplayAllContents();
    return 1;
}

// Get a content name from keyboard and delete the rocord with same content name.
int Application::DeleteContents() {
    MultimediaContent selectItem;
    selectItem.SetNameFromKB();

    if (m_listMC.Delete(selectItem)) {
        m_event.DeleteMC(selectItem);       // Delete information of event class 
        cout << "\n\tDeletion worked.";
		return 1;
    }
    else {
        cout << "\n\tNot exist the content name in list.";
		return 0;
    }
}

// Get a record from keyboard and Replace the rocord with same record.
int Application::ReplaceContents() {
    MultimediaContent selectItem;
    selectItem.SetNameFromKB();
    if (m_listMC.Replace(selectItem) == -1) {
        cout << "\n\tNot exist the content name in list";
		return 0;
    }
    else {
        cout << "\n\tReplacing worked";
		return 1;
    }
}

// Get a content name from keyboard and Display a record with input content name.
int Application::RetrieveContents() {
    MultimediaContent selectItem;
    selectItem.SetNameFromKB();

    if (m_listMC.Get(selectItem) != -1) {
        cout << selectItem;
		return 1;
    }
    else {
        cout << "\n\tNot exist the content name in list.";
		return 0;
    }
}

// Display all records in the list in screen.
void Application::DisplayAllContents() {
    MultimediaContent data;

	cout << "\n\tCurrent list" << endl;

	m_listMC.ResetList();
	int length = m_listMC.GetLength();
	int curIndex = m_listMC.GetNextItem(data);

	while(curIndex < length && curIndex != -1) {
        cout << data << endl;
		curIndex = m_listMC.GetNextItem(data);
	}
}

// Make list empty.
void Application::MakeEmpty() {
    m_listMC.MakeEmpty();
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName) {
    m_inFile.open(fileName);
    
    if (!m_inFile)
        return 0;
    else
        return 1;
}

// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName) {
    m_outFile.open(fileName);

    if (!m_outFile)
        return 0;
    else
        return 1;
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile() {
    int index = 0;
	MultimediaContent data;
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if(!OpenInFile(filename))
		return 0;

	while (!m_inFile.eof()) {
		data.ReadDataFromFile(m_inFile);

		if (m_inFile.eof())
            break;
		m_listMC.Add(data);
	}

	m_inFile.close();

	DisplayAllContents();

	return 1;
}

// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile() {
    MultimediaContent data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if(!OpenOutFile(filename))
		return 0;

	m_listMC.ResetList();

	int length = m_listMC.GetLength();
	int curIndex = m_listMC.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_outFile);
		curIndex = m_listMC.GetNextItem(data);
	}

	m_outFile.close();

	return 1;
}

// Add new record into listFC.
int Application::AddFC() {
    FavoriteContent selectItem;
    MultimediaContent tmpItem;

    cin >> selectItem;
    tmpItem.SetName(selectItem.GetName());

    if (m_listMC.Get(tmpItem) == -1) {
        cout << "<============ NOT FOUND ITEM !==========>" << endl;
        return 0;
    }

    m_listFC.EnQue(selectItem);

    cout << "\n\tCurrent list" << endl;
    DisplayAllFC();
    return 1;
}

// Get a content name from keyboard and delete the rocord with same content name.
int Application::DeleteFC() {
    FavoriteContent selectItem;
    selectItem.SetNameFromKB();

    if (m_listFC.Delete(selectItem)) {
        cout << "\n\tDeletion worked.";
        cout << "\n\n\tCurrent list" << endl;
        DisplayAllFC();
		return 1;
    }
    else {
        cout << "\n\tNot exist the content name in list.";
		return 0;
    }
}

// Display all records in the listFC in screen.
void Application::DisplayAllFC() {
    m_listFC.Print();
}

// Display detail information of the specific record in screen.
void Application::DisplayDetailFC() {
    FavoriteContent selectItem;
    MultimediaContent tmpItem;

    selectItem.SetNameFromKB();
    if (m_listFC.Search(selectItem) != -1) {
        tmpItem.SetName(selectItem.GetName());
        m_listMC.Get(tmpItem);
        cout << "\n\tCurrent list" << endl;
        cout << tmpItem;
    }
    else
        cout << "\n\tNot exist the FC in list" << endl;
}

// Display all informations of the event class in screen.
void Application::DisplayEventList() {
    cout << "\n\tCurrent Event List" << endl;
    cout << m_event;
}