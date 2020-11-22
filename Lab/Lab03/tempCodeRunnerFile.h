	/**
	 * @brief	Print record.
	 * @pre		MultimediaContent class should be initialized.
	 * @post	content record is on screen.
     * @param	cout	ostream instance
	 * @param	_item	target MultimediaContent for printing.
	 */
	friend ostream& operator<<(ostream& cout, const MultimediaContent& _item) {
		cout << "\t[ Content name: " << _item.m_contentName;
		cout << ", Content type: " << _item.m_contentType;
		cout << ", Create time: " << _item.m_createTime;
		cout << ", Character: " << _item.m_character;
		cout << ", Content category: " << _item.m_contentCategory;
		cout << ", Event name: " << _item.m_eventName;
		cout << ", Event description: " << _item.m_eventDescription;
		cout << ", Contents: " << _item.m_contents << " ]";

		return cout;
	}

	/**
	 * @brief	Input record.
	 * @pre		none.
	 * @post	content record is initialized.
     * @param	cin	    istream instance
	 * @param	_item	target MultimediaContent for Input.
	 */
	friend istream& operator>>(istream& cin, MultimediaContent& _item) {
		cout << "\n\tEnter content name: ";
		cin >> _item.m_contentName;
    	cout << "\tEnter content type(ex> 1:Photo, 2:Panorama, 3: Video):";
		cin >> _item.m_contentType;
    	cout << "\tEnter create time: ";
		cin >> _item.m_createTime;
		cout << "\tEnter character: ";
		cin >> _item.m_character;
		cout << "\tEnter content category(ex> 1:Portrait, 2:Location, 3: Video): ";
		cin >> _item.m_contentCategory;
		cout << "\tEnter event name: ";
		cin >> _item.m_eventName;
		cout << "\tEnter event description: ";
		cin >> _item.m_eventDescription;

		_item.SetContents();
		return cin;
	}