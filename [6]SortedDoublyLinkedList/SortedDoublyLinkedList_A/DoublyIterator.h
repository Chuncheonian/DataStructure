#pragma once
#include "SortedDoublyLinkedList.h"

template<typename T>
struct DoublyNodeType;	// 선언

template<typename T>
class SortedDoublyLinkedList;	// 선언

template <class T>
class DoublyIterator{
	friend class SortedDoublyLinkedList<T>;

private:
	const SortedDoublyLinkedList<T>		&m_List;
	DoublyNodeType<T>					*m_pCurPointer;

public:
	DoublyIterator(const SortedDoublyLinkedList<T>& list)
	: m_List(list), m_pCurPointer(list.m_pFirst) {}

	/**
     * @brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
     * @pre	Iterator has been initialized.
     * @post	None.
     * @return	nullptr true, otherwise false.
     */
	bool NotNull();

	/**
     * @brief	현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
     * @pre	Iterator has been initialized.
     * @post	None.
     * @return	nullptr true, otherwise false.
     */
	bool NextNotNull();

	/**
     * @brief	Get first data of the list.
     * @pre	Iterator has been initialized.
     * @post	Current pointer is moved to the first node.
     * @return	Return first data of the list.
     */
	T First();

	/**
     * @brief	Get next data of the current pointer.
     * @pre	Iterator has been initialized.
     * @post	Current pointer is moved to the next node.
     * @return	Return next data of the list.
     */
	T Next();

	/**
     * @brief	Get current data of the list and go to the next node. 현재 노드. 객체반환은 return by value
     * @pre	Iterator has been initialized.
     * @post	Current pointer is moved to next node.
     * @return	Return current data of the list.
     */
	DoublyNodeType<T> GetCurrentNode();
};


template <class T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr)
		return false;
	else
		return true;
}

template <class T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->next == nullptr)
		return false;
	else;
		return true;
}

template <class T>
T DoublyIterator<T>::First() {
	return m_List.m_pFirst->data;
}

template <class T>
T DoublyIterator<T>::Next() {
	m_pCurPointer = m_pCurPointer->next;

	return m_pCurPointer->data;
}

template <class T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode() {
	return *m_pCurPointer;
}