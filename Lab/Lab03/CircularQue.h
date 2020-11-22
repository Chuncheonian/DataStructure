#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "MultimediaContent.h"
#include "FavoriteContent.h"

#define MAXQUEUE 10

// Exception class thrown by Push when queue is full.
class FullQue{
public:
    void print() {
        cout << "\tQueue is Full" << endl;
    }
};

// Exception class thrown by Pop when queue is empty.
class EmptyQue{
public:
    void print() {
        cout << "\tQueue is Empty" << endl;
    }
};

// Circular Queue class
template <class RecordType>         // declare template for generic data.
class CircularQue{
private:
    int         m_front;            // front index of the Circular Queue.
    int         m_rear;             // rear index of the Circular Queue.
    int         m_maxQue;           // maximun size of the Circular Queue.
    int         m_curPointer;       // current item pointer for iteration operator
    RecordType* m_pItems;           // Dynamic Queue

public:
    /**
     * @brief   Dynamic Queue allocation corresponding MAXQUEUE size
     * @pre     none.
     * @post    Create Queue.
     */
    CircularQue();

    /**
     * @brief   Dynamic Queue allocation corresponding parameter size
     * @pre     exist parameter.
     * @post    Create Queue.
     * @param   max     queue size
     */
    CircularQue(int max);

    /**
     * @brief   default destructor
     * @pre     none.
     * @post    Dynamic Queue deallocation
     */
    ~CircularQue();

	/**
	 * @brief   Check whether capacity of queue is full.
	 * @pre     Queue should be initialized.
	 * @post    none.
	 * @return  return true if queue capacity reached to the upper bound,
	 *          oterwise return false.
	 */
    bool IsFull();

	/**
	 * @brief   Check whether capacity of queue is empty.
	 * @pre     Queue should be initialized.
	 * @post    None.
	 * @return  Return true if m_length == 0,
	 *          Oterwise return false.
	 */
    bool IsEmpty();

	/**
	 * @brief   Make queue empty.
	 * @pre     Queue should be initialized.
	 * @post    Clear queue.
	 */
    void MakeEmpty();

	/**
	 * @brief   Add a new record into Circular queue.
	 * @pre     Queue should be initialized.
	 * @post    Added the new record into the queue. and m_rear++, Oterwise throw FullQue Exception class.
	 * @param   _item    new item
	 * @return  Return 1 if this function works well,
	 *          Return 0 if a record already exists,
	 */
    int EnQue(RecordType _item);

	/**
	 * @brief   Delete existing a record.
	 * @pre     Queue should be initialized.
	 * @post    Delete the record into the queue and m_rear--, Otherwise throw EmptyQue Exception class.
	 * @param   _item    The record to want to delete.
	 */
    void DeQue(RecordType& _item);

    /**
     * @brief   Print all the items in the Circular Queue on screen
     * @pre     Queue should be initialized.
     * @post    None.
     */
    void Print();

    // Queue List Functions

    /**
	 * @brief   Set iterator to point to m_front
	 * @pre     Queue should be initialized.
	 * @post    iterator == m_front.
	 */
    void ResetList();

	/**
	 * @brief   Move iterator to the next item in queue and Get the item.
	 * @pre     Queue and queue iterator should not be initialized.
	 * @post    Iterator is moved to next item.
	 * @param   _item    get current iterator's item. it does not need to be initialized.
	 * @return  Return -1 if queue is empty,
     *          Return 0 else if is end of list,
	 *          Oterwise return 1
	 */
    int GetNextItem(RecordType& _item);

	/**
	 * @brief   Delete existing a record.
	 * @pre     RecordType should be initialized.
	 * @post    Delete the record into the queue and m_rear--.
	 * @param   _item    The record to want to delete.
	 * @return  Return 1 if the item to be deleted is in the queue,
	 *          Oterwise return 0.
	 */
    int Delete(RecordType _item);

	/**
	 * @brief   Search for same variable and Get the data.
	 * @pre     Two RecordType should be initialized.
	 * @post    Get the record
	 * @param   _item    The record to want to find
	 * @return  Return index of searched item if record with same variable is set,
	 *          Otherwise return -1.
	 */
    int Search(RecordType& _item);

	/**
	 * @brief   Search for same record and Replace record with input record.
	 * @pre     RecordType should be initialized.
	 * @post    none.
	 * @param   _item    replace record
	 * @return  return m_curPointer if two record are the same,
	 *          oterwise return -1.
	 */
    int Replace(RecordType _item);
};

// Dynamic allocation corresponding MAXQUEUE size
template <class RecordType>
CircularQue<RecordType>::CircularQue() {
    m_maxQue = MAXQUEUE + 1;
    m_front = m_maxQue - 1;
    m_rear = m_maxQue - 1;
    m_curPointer = -1;
    m_pItems = new RecordType[m_maxQue];
}

// Dynamic allocation corresponding parameter size
template <class RecordType>
CircularQue<RecordType>::CircularQue(int max) {
    m_maxQue = max + 1;
    m_front = m_maxQue - 1;
    m_rear = m_maxQue - 1;
    m_curPointer = -1;
    m_pItems = new RecordType[m_maxQue];
}

// default destructor
template <class RecordType>
CircularQue<RecordType>::~CircularQue() {
    delete[] m_pItems;
}

// Check whether capacity of queue is full.
template <class RecordType>
bool CircularQue<RecordType>::IsFull() {
    return ( (m_rear + 1) % m_maxQue == m_front);
}

// Check whether capacity of queue is empty.
template <class RecordType>
bool CircularQue<RecordType>::IsEmpty() {
    return (m_front == m_rear);
}

// Make queue empty.
template <class RecordType>
void CircularQue<RecordType>::MakeEmpty() {
    m_front = m_rear;
}

// Add a new record into Circular queue.
template <class RecordType>
int CircularQue<RecordType>::EnQue(RecordType _item) {
    if (IsFull())
        throw FullQue();

    else {
        if (Search(_item))
            return 0;
        
        else {
            m_rear = (m_rear + 1) % m_maxQue;
            m_pItems[m_rear] = _item;
            return 1;
        }
    }
}

// Delete existing a record.
template <class RecordType>
void CircularQue<RecordType>::DeQue(RecordType& _item) {
    if (IsEmpty())
        throw EmptyQue();
    else {
        m_front = (m_front + 1) % m_maxQue;
        _item = m_pItems[m_front];
    }
}

// Print all the items in the Circular Queue on screen
template <class RecordType>
void CircularQue<RecordType>::Print() {
    if (IsEmpty())
        cout << "\tIt is empty!";
    else {
        int first = m_front;
        int last = m_rear;
        while (first != last) {
            first = (first + 1) % m_maxQue;
            cout << m_pItems[first];
            cout << ", ";
        }
    }
}

// Queue List Functions

// Set iterator to point to m_front
template <class RecordType>
void CircularQue<RecordType>::ResetList() {
    m_curPointer = m_front;
}

// Move iterator to the next item in queue and Get the item.
template <class RecordType>
int CircularQue<RecordType>::GetNextItem(RecordType& _item) { // empty가 아니면 pointer를 증가시키고 pointe가 가리키는 item과 true를 리턴
    if (IsEmpty()) {
        cout << "\t%% End of Queue %%" << endl;
        return -1;
    }

    m_curPointer = (m_curPointer + 1) % m_maxQue;
    _item = m_pItems[m_curPointer];
    if (m_curPointer == m_rear) {
        ResetList();
        return 0;
    }
    return 1;
}

// Delete existing a record.
template <class RecordType>
int CircularQue<RecordType>::Delete(RecordType _item) {
    int delIndex = Search(_item);
    if (delIndex != -1) { // exist delete item in lust.
        while (delIndex != m_rear) {
            m_pItems[delIndex] = m_pItems[(delIndex + 1) % m_maxQue];
            delIndex = (delIndex + 1) % m_maxQue;
        }
        m_rear = (m_rear - 1) % m_maxQue;
        return 1;
    }
    else 
        return 0;
}

// Search for same variable and Get the data.
template <class RecordType>
int CircularQue<RecordType>::Search(RecordType& _item) {
    RecordType curItem;
    ResetList();
    GetNextItem(curItem);

    while (m_rear == m_curPointer) {
        if (_item == curItem) {
            _item = curItem;
            return 1;
        }
        GetNextItem(curItem);
    }
    return 0;
}  

// Search for same record and Replace record with input record.
template <class RecordType>
int CircularQue<RecordType>::Replace(RecordType _item) {
    RecordType curItem;
    ResetList();
    GetNextItem(curItem);

    while (m_rear == m_curPointer) {
        if (_item == curItem) {
            m_pItems[m_curPointer] = _item;
            return 1;
        }
        GetNextItem(curItem);
    }
    return 0;
}