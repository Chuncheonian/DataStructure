#pragma once
#include <cstddef>

/**
 * Structure for NodeType to use in Linked structure.
 */
template <typename T>
struct NodeType {
	T			data;		// A data for each node.
	NodeType*	next;		// A node pointer to point succeed node.
};

/**
 * Sorted Singly Linkedlist class for managing items.
 */
template <typename T>
class SortedSinglyLinkedList {
private:
	NodeType<T>*	m_pList;		// Pointer for pointing a first node.
	NodeType<T>*	m_pCurPointer;	// Node pointer for pointing current node to use iteration.
	int				m_nLength;		// Number of node in the list.

public:
	/**
	 * default constructor.
	 */
	SortedSinglyLinkedList();     

	/**
	 * destructor.
	 */
	~SortedSinglyLinkedList();   

	/**
	 * @brief	Get number of elements in the list.
	 * @pre		None.
	 * @post	Function value = number of elements in list.
	 * @return	Number of elements in this list.
	 */
	int GetLength() const;

	/**
	 * @brief	Initialize list to empty state.
	 * @pre		None.
	 * @post	List is empty.
	 */
	void MakeEmpty();

	/**
	 * @brief	Initialize current pointer for an iteration through the list.
	 * @pre		None.
	 * @post	Current pointer is prior to list. current pointer has been initialized.
	 */
	void ResetList();

	/**
	 * @brief	Get the next element in list.
	 * @pre		Current pointer is defined. Element at current pointer is not last in list.
	 * @post	Current pointer is updated to next position. item is a copy of element at current pointer.
	 */
	void GetNextItem(T& _item);

	/**
	 * @brief	Add item into appropriate spot of this list.
	 * @pre		List is not full. item is not in list. 
	 * @post	Item is inserted in this list.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int Add(T _item);

	/**
	 * @brief	Delete item from this list.
	 * @pre		List is not empty. the item exists in list.
	 * @post	Item is deleted from this list.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int Delete(T _item);

	/**
	 * @brief	Retrieve list element whose key matches item's key (if present).
	 * @pre		Key member of item is initialized.
	 * @post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	 * @return	1 if any element's primary key matches with item's, otherwise 0.
	 */
	int Get(T& _item);

	/**
	 * @brief	Change value of item which is in this list.
	 * @pre		List is not empty. the item exists in list.
	 * @post	Item's value is changed.
	 * @return	1 if this function works well, otherwise 0.
	 */
	int Replace(T _item);

	void operator=(SortedSinglyLinkedList& _item);
};


// Class constructor
template <typename T>
SortedSinglyLinkedList<T>::SortedSinglyLinkedList() {
	m_nLength = 0;
	m_pList = nullptr;
	m_pCurPointer = nullptr;
}

// Class destructor
template <typename T>
SortedSinglyLinkedList<T>::~SortedSinglyLinkedList() {
	//리스트내의 모든 node 제거
	MakeEmpty();
}

// Get number of elements in the list.
template <typename T>
int SortedSinglyLinkedList<T>::GetLength() const {
	return m_nLength;
}

// Initialize list to empty state.
template <typename T>
void SortedSinglyLinkedList<T>::MakeEmpty() {
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;
	
	while (m_pList != nullptr)	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}
	
	m_nLength = 0;
}

// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedSinglyLinkedList<T>::ResetList() {
	// current pointer 초기화
	m_pCurPointer = nullptr;
}

// Gets the next element in list.
template <typename T>
void SortedSinglyLinkedList<T>::GetNextItem(T& _item) {
	// current pointer 이 nullptr이라면 처음 node를 가리킴.
	if (m_pCurPointer == nullptr)
		m_pCurPointer = m_pList;
	
	//current position 을 다음 노드로 이동
	else
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	_item = m_pCurPointer->data;
}


// Add item into this list.
template <typename T>
int SortedSinglyLinkedList<T>::Add(T _item) {
	ResetList();	// 리스트 초기화
	
	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = _item;
	node->next = nullptr;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
		m_pList = node;

	// list 에 node 가 하나 이상 존재하는 경우
	else {
		// 가장 마지막 node 로 이동 후 삽입
		while(1) {
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			//지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.
			if (m_pCurPointer->data > node->data) {
				//넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
				if (pre == nullptr) {
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}

				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == nullptr) {
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				break;
			}
		}
	}
	m_nLength++;

	return 1;
}

// Delete item from this list.
template <typename T>
int SortedSinglyLinkedList<T>::Delete(T _item) {
	bool moreToSearch, found;
	NodeType<T>* pre = nullptr;	// 변수 선언
	
	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != nullptr);	// 변수 초기화
	
	// 리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	while (moreToSearch && !found) {
		// 현재 가리키는 원소의 값과 item의 값이 일치할 때
		if (_item == m_pCurPointer->data) {
			found = true;	// 찾았으므로 found 값 변경
			if(pre == nullptr)
				m_pList = m_pCurPointer->next;	// 항목 이전에 다른 원소가 없을 때 항목의 다음 원소를 첫번째 원소로 한다.
			
			else {	// 이전의 원소의 다음 원소를 '가리키는 항목의 다음 원소'로 바꾼다.
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}	
			m_nLength--;	//리스트의 길이를 1 줄여준다.
		}
		else {	// 일치하지 않을 때 다음 원소를 가리킨다. 단, pre는 지금의 원소를 가리킨다.
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != nullptr);
		}
	}

	if (found)
		return 1;
	else
		return 0;	//삭제가 성공하면 1, 아니면 0을 리턴한다.
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedSinglyLinkedList<T>::Get(T& _item) {
	bool moreToSearch, found;
	NodeType<T>* location;	//변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	//변수 초기화
	
	while (moreToSearch && !found) {	//리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
		if (_item == location->data) {
			found = true;
			_item = location->data;
		}	//일치하는 항목을 찾았을 때 found의 값을 변경해주고 item에 해당 항목을 복사해준다.
		else {
			location = location->next;
			moreToSearch = (location != nullptr);
		}	//찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 nullptr이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if(found)
		return 1;
	else
		return 0;	//찾으면 1, 그렇지 못하면 0을 리턴한다.
}

// Change value of item which is in this list.
template <typename T>
int SortedSinglyLinkedList<T>::Replace(T _item) {
	bool moreToSearch, found;
	NodeType<T>* location;	// 변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);	// 변수 초기화
	
	while (moreToSearch && !found) {	// 리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
		if (_item == location->data) {
			found = true;
			location->data = _item;
		}	// 일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else {
			location = location->next;
			moreToSearch = (location != nullptr);
		}	// 찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 nullptr이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if(found)
		return 1;
	else
		return 0;	//수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}

template<typename T>
void SortedSinglyLinkedList<T>::operator=(SortedSinglyLinkedList& _item) {
	MakeEmpty();
	int len = _item.GetLength();
	_item.ResetList();

	for(int i = 0; i < len; i++) {
		T item;
		_item.GetNextItem(item);
		Add(item);
	}
}