#include "Application.h"

void Application::Run() {
    while(1) {
        try {
			m_command = GetCommand();
			switch (m_command) {
				case 1:		// 추가.
					EnQueItem();
					break;
				case 2:		//삭제.
					DeQueItem();
					break;
				case 3:		// Is Empty?
					CheckEmpty();
					break;
				case 4:		// Is Full?
					CheckFull();
					break;
				case 5:		// Print all the elements in the stack.
					DisplayAllItem();
					break;
				case 6:		// Print all the elements in the stack.
					MakeEmpty();
					break;
				case 7:		
					DeleteItem();
					break;
				case 8:
					Search();
					break;
				case 9:
					Replace();
					break;
				case 0:
					return;
				default:
					cout << "\tIllegal selection...\n";
					break;
			}
		}
        
		catch (FullQue e) {
            e.print();
		}

    	catch (EmptyQue e) {
			e.print();
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t--- ID - Command -----" << endl;
	cout << "\t    1. Enqueue content" << endl;
	cout << "\t    2. Dequeue content" << endl;
	cout << "\t    3. Is Empty?" << endl;
	cout << "\t    4. Is Full?" << endl;
	cout << "\t    5. Print all content on screen" << endl;
	cout << "\t    6. Make Empty"<<endl;
	cout << "\t    7. Delete content" << endl;
	cout << "\t    8. Search content" << endl;
	cout << "\t    9. Replace content" << endl;
	cout << "\t    0. Quit" << endl << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::EnQueItem() {			// case 1
	ItemType item;    
	cin >> item;

    int status = m_Queue.EnQue(item);

	if (status == 0)
		cout << "\n\tThe content already exists" << endl;
        
	else if (status == 1)
		cout << "\n\t<========EnQue SUCCESS !===========>" << endl;
		
	DisplayAllItem();
}

void Application::DeQueItem() {			// case 2
    ItemType item;

	m_Queue.DeQue(item);

    cout << "\tDequeue Element: " << item << endl << endl;
	cout << "\n\t<========DeQue SUCCESS !===========>" << endl;
    
	DisplayAllItem();
}

int Application::CheckEmpty() {			// case 3
    if (m_Queue.IsEmpty()) {
        cout << "\tQueue is empty." << endl << endl;
        return 1;
    }
    else {
        cout << "\tQueue isn't empty" << endl << endl;
        return 0;
    }
}

int Application::CheckFull() {			// case 4
    if (m_Queue.IsFull()) {
        cout << "\tQueue is full" << endl << endl;
        return 1;
    }
    else {
        cout << "\tQueue isn't full" << endl << endl;
        return 0;
    }
}

void Application::DisplayAllItem() {	// case 5
    cout << "\n\t--Current list--" << endl;
	m_Queue.Print();
}

void Application::MakeEmpty() {			// case 6
    m_Queue.MakeEmpty();
    DisplayAllItem();
}

void Application::DeleteItem() {		// case 7
    ItemType item;
    item.SetIdFromKB();

	int status = m_Queue.Delete(item);

	if (status == -1)
		cout << "\tList is empty" << endl;

	else if (status == 0)
		cout << "\tThe content doesn't exist" << endl;

	else if (status == 1)
        cout << "\n\tDeletion worked." << endl;;
    
	DisplayAllItem();
}

// Searching for same PK and Get the data.
void Application::Search() {			// case 8
	ItemType item;
    item.SetIdFromKB();

	if (m_Queue.Search(item)) {
		cout << "<============ Content Found !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
	}
	else
		cout << "<======== Content Not Found!==========>" << endl;
}

// Get a Primary Key from keyboard and Replace the rocord with same Primary Key.
void Application::Replace() {			// case 9
	ItemType item;
	item.SetIdFromKB();

	if (m_Queue.Search(item)) {
		item.SetNameFromKB();
		item.SetAddressFromKB();
		m_Queue.Replace(item);
		cout << "\n\tReplacing worked";
		DisplayAllItem();
	}

	else
		cout << "\n\tNot exist the Primary Key in queue";
}