#pragma once
#include<iostream>
using namespace std;

#define maxQueue 200

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/
class FullQueue
{
public:
	/**
	*	@brief	Display a message for full queue on screen.
	*/
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};


/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue
{
public:
	/**
	*	@brief	Display a message for empty queue on screen.
	*/
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};


template <typename T>					
class Queue {
public:
	Queue();							//Constructor
	int GetLength();					//Returns the number of remaining vocabularies
	void enQueue(T& voca);				//Add vocabulary to the queue
	int deQueue(T& voca);				//Delete vocabulary from the queue
	bool isFull();						//Check if the the queue is full
	bool isEmpty();						//Check if the queue is empty
	void MakeEmpty();					//Make the current Queue empty
	void ResizeQueue(int i);			//Change the current size of the queue
private:
	T* m_LearnVocaList;					//template data type pointer for having 200 sized array
	int m_iFront;						//Front part of Queue
	int m_iRear;						//Rear part of queue
	int m_length;						//Current inserted data inside the queue
	int m_MaxSize;						//Maximum size of the queue
};

//생성자
template <typename T>
Queue<T>::Queue() {
	m_LearnVocaList = new T[maxQueue + 1];
	m_MaxSize = maxQueue + 1;
	m_iFront = maxQueue;
	m_iRear = maxQueue;
	m_length = 0;
}

//학습단어 목록이 꽉 찼는지 검사한다.
template <typename T>
bool Queue<T>::isFull() {
	return(m_iFront == ((m_iRear + 1) % m_MaxSize));
}

//학습단어 목록이 비었는지 검사한다.
template <typename T>
bool Queue<T>::isEmpty() {
	return(m_iFront == m_iRear);
}

//학습단어 목록을 비운다.
template <typename T>
void Queue<T>::MakeEmpty() {
	m_iFront = maxQueue;
	m_iRear = maxQueue;
	m_length = 0;
	return;
}

//학습단어 목록에 단어를 추가한다.
template <typename T>
void Queue<T>::enQueue(T& item) {
	if (isFull()) {
		//throw FullQueue();
		T dummy;
		deQueue(dummy);
		enQueue(item);
	}
	else {
		m_iRear = (m_iRear + 1) % m_MaxSize;
		m_LearnVocaList[m_iRear] = item;
		//cout << "\t\nenQueue 성공\n";
		m_length++;
	}
	return;
}

//학습단어 목록에서 단어를 추출한다.
template <typename T>
int Queue<T>::deQueue(T& item) {
	if (isEmpty()) {
		//throw EmptyQueue();
		return 0;
	}
	else {
		m_iFront = (m_iFront + 1) % m_MaxSize;
		item = m_LearnVocaList[m_iFront];
		m_length--;
		return 1;
	}
}

//학습단어 목록에서 남아있는 단어 갯수를 반환
template <typename T>
int Queue<T>::GetLength() {
	return m_length;
}

template <typename T>
void Queue<T>::ResizeQueue(int i) {
	delete[] m_LearnVocaList;
	m_LearnVocaList = new T[i + 1];
	m_MaxSize = i + 1;
	m_iFront = i;
	m_iRear = i;
	m_length = 0;
}
