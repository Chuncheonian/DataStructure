#pragma once

#include "ItemType.h"
#include "DoublyIterator.h"

#define min ItemType(INT_MIN)
#define max ItemType(INT_MAX)

template <class T>
class DoublyIterator;

template <class T>
struct DoublyNodeType {
	T				data;
	DoublyNodeType	*prev;
	DoublyNodeType	*next;
};

template <class T>
class SortedDoublyLinkedList {
	friend class DoublyIterator<T>;

private:
	DoublyNodeType<T>	*m_pFirst;
	DoublyNodeType<T>	*m_pLast;
	int					m_nLendgth;

public:
	/**
	 * default constructor.
	 */
	SortedDoublyLinkedList();

    /**
	 * default destructor.
	 */
	~SortedDoublyLinkedList();

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
	 * @post	List is empty.
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
	int Add(T _item);

	/**
	 * @brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 삭제함.
	 * @pre		리스트가 존재/초기화 완료되어있는 상태여야 함.
	 * @post	일치하는 데이터가 리스트에 있을 경우 삭제됨.
	 * @param	data	primary key가 반드시 포함되어 있는 ItemType 객체.
	 * @return 삭제할 일치하는 데이터가 있으면 삭제 후 1, 없으면 0을 리턴.
	 */
	int Delete(T _item);

	/**
	 * @brief	Primary key(학번)를 바탕으로 검색하여 해당하는 정보를 새로 채워넣음.
	 * @pre		리스트가 존재/초기화 완료되어있는 상태여야 함.
	 * @post	일치하는 데이터가 리스트에 있을 경우 새로운 데이터로 교체됨.
	 * @param	_item	primary key가 반드시 포함되어 있는 ItemType 객체.
	 */
	int Replace(T _item);

	/**
	 * @brief	Retrieve list element whose key matches item's key (if present).
	 * @pre		Key member of item is initialized.
	 * @post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	 * @return	Return 1 if any element's primary key matches with item's, otherwise return 0.
	 */
	int Get(T& _item);

	SortedDoublyLinkedList<T> operator=(SortedDoublyLinkedList& _item);
};

template <class T>
SortedDoublyLinkedList<T>::SortedDoublyLinkedList() {
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->prev = nullptr;
	m_pFirst->data = min;
	m_pFirst->next = m_pLast;

	m_pLast->prev = nullptr;
	m_pLast->data = max;
	m_pLast->next = nullptr;

	m_nLendgth = 0;
}

template <class T>
SortedDoublyLinkedList<T>::~SortedDoublyLinkedList() {
	delete m_pFirst;
	delete m_pLast;
}

template <class T>
bool SortedDoublyLinkedList<T>::IsEmpty() {
	return (m_nLendgth == 0);
}

template <class T>
void SortedDoublyLinkedList<T>::MakeEmpty() {
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> iter(*this);
	iter.Next();

	while (iter.NextNotNull()) {
		pItem = iter.m_pCurPointer;
		iter.Next();
		delete pItem;
	}

	m_pFirst->prev = nullptr;
	m_pFirst->next = m_pLast;

	m_pLast->prev = m_pFirst;
	m_pLast->next = nullptr;

	return;
}

template <class T>
int SortedDoublyLinkedList<T>::GetLength() const {
	return m_nLendgth;
}

template <class T>
int SortedDoublyLinkedList<T>::Add(T _item) {
	DoublyIterator<T> iter(*this);
	iter.Next();

	DoublyNodeType<T> *pItem = new DoublyNodeType<T>;

	if (IsEmpty()) {
		pItem->prev = m_pFirst;
		pItem->data = _item;
		pItem->next = m_pLast;

		m_pFirst->next = pItem;
		m_pLast->prev = pItem;

		m_nLendgth++;
		return 1;
	}

	else {
		while(1) {
			if (_item < iter.m_pCurPointer->data) {
				pItem->prev = iter.m_pCurPointer->prev;
				pItem->data = _item;
				pItem->next = iter.m_pCurPointer;

				iter.m_pCurPointer->prev->next = pItem;
				iter.m_pCurPointer->prev = pItem;
				m_nLendgth++;
				return 1;
			}

			else if (_item == iter.m_pCurPointer->data)
				return 0;

			else
				iter.Next();
		}
	}
}

template <class T>
int SortedDoublyLinkedList<T>::Delete(T _item) {
	if (m_nLendgth == 0)
		return -1;
	
	DoublyIterator<T> iter(*this);
	iter.Next();

	while (iter.m_pCurPointer != m_pLast) {
		if (iter.m_pCurPointer->data == _item) {
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = iter.m_pCurPointer;
			iter.Next();
			pItem->prev->next = iter.m_pCurPointer;
			iter.m_pCurPointer->prev = pItem->prev;
			delete pItem;
			m_nLendgth--;
			return 1;
		}
		else
			iter.Next();
	}
	return 0;
}

template <class T>
int SortedDoublyLinkedList<T>::Replace(T _item) {
	DoublyIterator<T> iter(*this);
	iter.Next();

	while (iter.m_pCurPointer != m_pLast) {
		if (iter.m_pCurPointer->data == _item) {
			iter.m_pCurPointer->data = _item;
			return 1;
		}
		else
			iter.Next();
	}
	return 0;
}

template <class T>
int SortedDoublyLinkedList<T>::Get(T& _item) {
	DoublyIterator<T> iter(*this);
	iter.Next();

	while (iter.m_pCurPointer != m_pLast) {
		if (iter.m_pCurPointer->data == _item) {
			_item = iter.m_pCurPointer->data;
			return 1;
		}
		else
			iter.Next();
	}
	return 0;
}

template <class T>
SortedDoublyLinkedList<T> SortedDoublyLinkedList<T>::operator=(SortedDoublyLinkedList& _item) {
    MakeEmpty();

	DoublyIterator<T> iterThis(*this);
	DoublyIterator<T> iterItem(*_item);
	iterThis.Next();
	iterItem.Next();

	while (iterItem.NextNotNull()) {
		DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
		pItem->data = iterItem.m_pCurPointer;

		iterThis.mCurPointer->prev->next = pItem;
		pItem->prev = iterThis.mCurPointer->prev;
		
		pItem->next = iterThis.mCurPointer;
		iterThis.mCurPointer->prev = pItem;
		delete pItem;
		iterItem.Next();
	}
	return (*this);
}