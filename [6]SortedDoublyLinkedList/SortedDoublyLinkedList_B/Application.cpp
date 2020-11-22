#include "Application.h"

// Program driver.
void Application::Run() {
	while(1) {
		m_command = GetCommand();

		switch(m_command) {
		case 1:		// inset item
			InsertItem();
			break;
		case 2:		// retrieves item
			DisplayAll();
			break;
		case 3:
			RetrieveItem();
			break;
		case 4:
			ReplaceItem();
			break;
		case 5:
			DeleteItem();
			break;
		case 0:	// quit
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
	cout << "\t   3 : Retrieve Item" << endl;
	cout << "\t   4 : Update Item" << endl;
	cout << "\t   5 : Delete Item" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::InsertItem() {
	ItemType item;
    cin >> item;
	
    int status = m_list.Add(item);

    if (status == 0) {
		cout << "\n\tAlready has same ID! Try Again!" << endl;
        return 0;
    }

    else {
		cout << "\n\t<========ADD SUCCESS !===========>" << endl;
	    DisplayAll();
	    return 1;
    }
}


// Display all records in the list on screen.
void Application::DisplayAll() {
	ItemType data;
	DoublyIterator<ItemType> iter(m_list);
	cout << "\n\tCurrent list" << endl;

	while (iter.NotNull()) {
		iter.GetCurrentNode().data.DisplayRecordOnScreen();
		iter.Next();
	}
}


// Retrieve item in the list.
int Application::RetrieveItem() {
	ItemType item;
	cout << "Enter a item for search (primary key) : ";
	//cin >> item;
	item.SetIdFromKB();

	if(m_list.Get(item))
	{
		cout << "Target item exists in the list." << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	else
	{
		cout << "Target item is not in the list." << endl;
		return 0;
	}
}

// ����
int Application::DeleteItem() {
	if (m_list.IsEmpty()) {
		cout << "List is empty..." << endl;
		return 0;
	}
	ItemType target;
	target.SetIdFromKB();
	if (m_list.Delete(target)) {
		DisplayAll();

		return 1;
	}
	else {
		cout << "Target item is not in the list." << endl;

		return 0;
	}

	

}

// ����(������Ʈ)
int Application::ReplaceItem() {

	ItemType target;
	target.SetIdFromKB();
	if (m_list.Get(target)) {
		cout << "\n\tNew data: " << endl;
		target.SetNameFromKB();
		target.SetAddressFromKB();
		m_list.Replace(target);
		DisplayAll();

		return 1;
	}
	else {
		cout << "Target item is not in the list." << endl;
		return 0;
	}

}