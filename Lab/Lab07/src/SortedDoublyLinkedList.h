#pragma once

#include "MultimediaContent.h"
#include "DoublyIterator.h"
/**
 * Structure for NodeType to use in Linked structure.
 */

template <typename T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType {
	T				data;	// A data for each node.
	DoublyNodeType*	prev;	// A node pointer of previous node.
	DoublyNodeType*	next;	// A node pointer of next node.
};


/**
 * Single sorted list class for managing items.
 */
template <typename T>
class SortedDoublyLinkedList{
	friend class DoublyIterator<T>;

private:
	DoublyNodeType<T>*	m_pFirst;	// Pointer for pointing a first node.
	DoublyNodeType<T>*	m_pLast;	// Last node.
	int					m_nLength;	// Number of node in the list.

public:
	/**
	 * default constructor.
	 */
	SortedDoublyLinkedList();     

	/**
	 * destructor.
	 */
	~SortedDoublyLinkedList();   

	/**
	 * @brief	Determine whether the list is full.
	 * @pre		List has been initialized.
	 * @post	None.
	 * @return	If there is not memory left, throws bad_alloc exception and return true, otherwise false.
	 */
	bool IsFull();

	/**
	 * @brief	Determine whether the list is empty.
	 * @pre		List has been initialized.
	 * @post	None.
	 * @return	Return true if the list is empty, otherwise false.
	 */
	bool IsEmpty();
	
	/**
	 * @brief	Initialize list to empty state.
	 * @pre		None.
	 * @post	List is empty, All items have been deallocated.
	*/
	void MakeEmpty();

	/**
	 * @brief	Get number of elements in the list.
	 * @pre		None.
	 * @post	Function value = number of elements in list.
	 * @return	Number of elements in this list.
	 */
	int GetLength() const;

	/**
	 * @brief	Add item into this list.
	 * @pre		List is not full. Item is not in list. 
	 * @post	Item is inserted in this list.
	 * @return	Return 1 if this function works well, otherwise return 0.
	 */
	int Add(T& _item);

	/**
	 * @brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 삭제함.
	 * @pre		리스트가 존재/초기화 완료되어있는 상태여야 함.
	 * @post	일치하는 데이터가 리스트에 있을 경우 삭제됨.
	 * @param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	 * @return 삭제할 일치하는 데이터가 있으면 삭제 후 1, 없으면 0을 리턴.
	 */
	int Delete(T _item);

	/**
	 * @brief	Retrieve list element whose key matches item's key (if present).
	 * @pre		Key member of item is initialized.
	 * @post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	 * @return	Return 1 if any element's primary key matches with item's, otherwise return 0.
	 */
	int Get(T& _item);

	/**
	 * @brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 새로 채워넣음.
	 * @pre		리스트가 존재/초기화 완료되어있는 상태여야 함.
	 * @post	일치하는 데이터가 리스트에 있을 경우 새로운 데이터로 교체됨.
	 * @param	_item	primary key가 반드시 포함되어 있는 ItemType 객체.
	 */
	int Replace(T _item);
};


// Class constructor
template <typename T>
SortedDoublyLinkedList<T>::SortedDoublyLinkedList() {
	m_nLength = 0;
	m_pFirst = nullptr;
	m_pLast = nullptr;
}


// Class destructor
template <typename T>
SortedDoublyLinkedList<T>::~SortedDoublyLinkedList() {
	//리스트내의 모든 node 제거
	MakeEmpty();
}

// Determines whether the list is full.
// 개수제한은 없지만, 실제 메모리가 가득 차서 더 이상 할당이 불가능한 경우 시스템 예외 처리
template <typename T>
bool SortedDoublyLinkedList<T>::IsFull() {
	try {
		DoublyNodeType<T>* temp = nullptr;	// if there is not memory left, temp would not be initialized as NULL and
		delete temp;					// deleting temp(pointer) could not be executed.
		return false;
	}
	catch (bad_alloc& e_ba) {
		cerr << "bad_alloc exception caught : " << e_ba.what() << endl;
		return true;
	}
}

// Determines whether the list is empty.
template <typename T>
bool SortedDoublyLinkedList<T>::IsEmpty() 	{
	return (m_pFirst == nullptr);
}

// Initialize list to empty state.
template <typename T>
void SortedDoublyLinkedList<T>::MakeEmpty() {

	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	DoublyNodeType<T>* tempPtr;
	DoublyIterator<T> iter(*this);
	
	while (iter.NotNull()) {
		tempPtr = iter.m_pCurPointer;
		iter.Next();
		delete tempPtr;
	}
	
	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SortedDoublyLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int SortedDoublyLinkedList<T>::Add(T& item) {
	if (IsFull())
		return -1;

	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	DoublyIterator<T> iter(*this);

	node->data = item;
	node->prev = nullptr;
	node->next = nullptr;

	// 비어있는 경우
	if (m_pFirst == nullptr) {
		m_pFirst = node;
		m_pLast = m_pFirst;
	}
	
	// 1개 이상
	else {
		DoublyNodeType<T>* pNode;	// iterator에서 나오는 데이터 객체
		while (iter.NotNull()) {
			pNode = iter.m_pCurPointer;

			if (node->data < pNode->data) { // 넣으려고 하는게 더 작음
				node->next = pNode;
				
				if (pNode == m_pFirst)  // 맨 앞
					m_pFirst = node;
				
				else {  // 중간
					node->prev = pNode->prev;
					node->prev->next = node;
				}
				
				pNode->prev = node;
				break;
			}

			else if (node->data == pNode->data)
				return 0;

			else {
				if (!iter.NextNotNull()) {	// 맨 뒤
					pNode->next = node;
					node->prev = pNode;
					m_pLast = node;
					break;
				}
				else
					iter.Next();
			}
		}
	}
	m_nLength++;
	return 1;
}

// 특정 요소를 찾아 삭제하는 함수
template <typename T>
int SortedDoublyLinkedList<T>::Delete(T _item) {
	if (IsEmpty())
		return -1;

	DoublyIterator<T> iter(*this);

	for (int i = 0; i < m_nLength; i++) {
		if (_item == iter.m_pCurPointer->data) {	// 리스트에서 삭제할 원소를 찾은 경우
			DoublyNodeType<T>* pNode = new DoublyNodeType<T>;
			pNode = iter.m_pCurPointer;

			if (pNode->next == nullptr && pNode->prev == nullptr) {     // 리스트 안에 원소가 하나일 경우
				m_pFirst = nullptr;
				m_pLast = nullptr;
			}

			else if (pNode->next != nullptr && pNode->prev != nullptr) {    // 삭제 할 원소가 리스트의 중간에 있는 경우
				pNode = iter.m_pCurPointer;
				iter.Next();
				pNode->prev->next = iter.m_pCurPointer;
				iter.m_pCurPointer->prev = pNode->prev;
			}

			else if (pNode->next == nullptr) {		// 삭제 할 원소가 리스트의 끝에 있는 경우
				pNode->prev->next = nullptr;
				m_pLast = pNode->prev;
			}
			
			else if (pNode->prev == nullptr) {		// 삭제 할 원소가 리스트의 처음에 있는 경우
				pNode->next->prev = nullptr;
				m_pFirst = pNode->next;
			}             

			delete pNode;
			m_nLength--;
			return 1;
		}
		
		else	// 리스트에서 삭제할 원소를 찾지 못한 경우
			iter.Next();
	}

	return 0;
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedDoublyLinkedList<T>::Get(T& _item) {
	DoublyIterator<T> iter(*this);

	while (iter.NotNull()) {
		if (_item == iter.m_pCurPointer->data) {
			_item = iter.m_pCurPointer->data;
			return 1;
		}
		else
			iter.Next();
	}
	return 0;
}

// 특정 요소를 찾아 새로운 내용으로 대치시키는 함수
template <typename T>
int SortedDoublyLinkedList<T>::Replace(T _item) {
	DoublyIterator<T> iter(*this);

	while (iter.NotNull()) {
		if (_item == iter.m_pCurPointer->data) {
			iter.m_pCurPointer->data = _item;
			return 1;
		}
		else
			iter.Next();
	}
	return 0;
}