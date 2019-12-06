#pragma once
#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct NodeType
{
	T data;							//NodeType의 데이터
	NodeType<T>* pre = nullptr;		//이전 Node를 가리키는 포인터
	NodeType<T>* next = nullptr;	//다음 Node를 가리키는 포인터
};

template <typename T>
class SortedLinkedListType {
public:
	/**
	*	@brief	기본 생성자
	*	@post	LinkedList의 모든 멤버변수를 초기화한다.
	*/
	SortedLinkedListType();

	/**
	*	@brief	소멸자
	*	@post	LinkedList의 동적할당된 모든 요소들을 할당 해제한다.
	*/
	~SortedLinkedListType();

	/**
	*	@brief	복사 생성자
	*	@post	기존에 존재하던 SortedLinkedListType의 객체로부터 모든 노드들을 deep copy한다.
	*/
	SortedLinkedListType(const SortedLinkedListType& list);

	/**
	*	@brief	LinkedList에 새로운 노드를 추가한다.
	*	@pre	data를 입력받는다.
	*	@post	LinkedList에 새로운 노드가 추가된다.
	*/
	void Insert(T& data);

	/**
	*	@brief	LinkedList에서 특정 노드를 삭제한다.
	*	@pre	Get함수로 중복 data갖는 Node를 검사해야한다.
	*	@post	LinkedList에서 특정 노드가 삭제된다.
	*/
	void Delete(T& data);

	/**
	*	@brief	LinkedList의 모든 요소들을 삭제한다.
	*	@pre	Get함수로 지우려는 data를 갖는 Node가 존재하는지 검사해야한다.
	*	@post	LinkedList의 모든 요소들이 삭제된다.
	*/
	void MakeEmpty();

	/**
	*	@brief	LinkedList에서 반복자를 이동시켜 해당 반복자가 가리키는 Node의 data로 갱신한다.
	*	@pre	data를 입력받는다.
	*	@post	LinkedList에서 반복자를 이동되고 해당 반복자가 가리키는 Node의 data가 갱신된다.
	*	@return	반복자가 끝까지 갔다면 nullptr, 아니라면 반복자가 가리키는 Node의 포인터를 반환한다.
	*/
	NodeType<T>* GetNext(T& data);

	/**
	*	@brief	LinkedList의 반복자를 초기화한다.
	*	@pre	LinkedLIst가 초기화 되어있어야한다.
	*	@post	LinkedList의 반복자가 초기화된다.
	*/
	void ResetList();

	/**
	*	@brief	LinkedList 내의 노드 갯수를 반환한다.
	*	@pre	LinkedList가 초기화 되어있어야한다.
	*	@post	LinkedList 내의 노드 갯수가 반환된다.
	*	@return	LinkedList 내의 노드 갯수
	*/
	int GetLength();

	/**
	*	@brief	LinkedList 내의 노드가 비었는지 검사한다.
	*	@pre	LinkedList가 초기화 되어있어야한다.
	*	@post	LinkedList 내의 노드가 비었는지 검사하게된다.
	*	@return	비었으면 true, 아니라면 false를 반환
	*/
	bool isEmpty();

	/**
	*	@brief	메모리상에 노드가 더 들어갈 수 있는지 검사한다.
	*	@pre	LinkedList가 초기화 되어있어야한다.
	*	@post	메모리상에 노드가 더 들어갈 수 있는지 검사하게된다.
	*	@return	꽉찼으면 true, 아니라면 false를 반환
	*/
	bool isFull();

	/**
	*	@brief	LinkedList에 동일한 data를 가진 Node가 존재하는지 검사한다.
	*	@pre	data를 입력받는다.
	*	@post	LinkedList 내에 동일 data를 가진 Node의 존재 여부를 알게 된다.
	*	@return	존재한다면 1, 아니라면 0을 반환
	*/
	int Get(T& data);

private:
	NodeType<T>* m_head;			//LinkedList에서 제일 앞에 위치한 노드를 가리키는 포인터
	NodeType<T>* m_tail;			//LinkedList에서 제일 뒤에 위치한 노드를 가리키는 포인터
	NodeType<T>* m_curPtr;			//LinkedList내에 존재하는 노드의 갯수를 저장하는 int형 변수
	int m_length;
};

//LinkedList의 멤버변수들을 초기화한다.
template <typename T>
SortedLinkedListType<T>::SortedLinkedListType() {
	m_head = new NodeType<T>;
	m_tail = new NodeType<T>;
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = 0;
}

//기존에 존재하던 SortedLinkedListType의 객체로부터 모든 노드들을 deep copy한다.
template <typename T>
SortedLinkedListType<T>::SortedLinkedListType(const SortedLinkedListType& list) {
	m_head = new NodeType<T>;
	m_tail = new NodeType<T>;
	m_head->data = NULL;
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->data = NULL;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = list.m_length;
	/*
		list 내의 모든 노드에서 data만을 뽑아와 해당 SortedLinkedListType객체의 리스트를 구성한다.
	*/
	NodeType<T>* list_curPtr = list.m_head;
	while (list_curPtr->next != list.m_tail) {
		list_curPtr = list_curPtr->next;
		NodeType<T>* tempPtr = new NodeType<T>;
		tempPtr->data = list_curPtr->data;
		while (m_curPtr->next != m_tail)
			m_curPtr = m_curPtr->next;
		m_curPtr->next->pre = tempPtr;
		tempPtr->next = m_curPtr->next;
		tempPtr->pre = m_curPtr;
		m_curPtr->next = tempPtr;
	}
}

//LinkedList의 동적할당된 모든 요소들을 할당 해제한다.
template <typename T>
SortedLinkedListType<T>::~SortedLinkedListType() {
	MakeEmpty();
	delete m_head;
	delete m_tail;
}

//LinkedList에 새로운 노드를 추가한다.
template <typename T>
void SortedLinkedListType<T>::Insert(T& data) {
	NodeType<T>* tempPtr = new NodeType<T>;
	tempPtr->data = data;

	ResetList();
	if (m_head->next == m_tail && m_tail->pre == m_head) {//node가 한개도 존재하지 않을때
		tempPtr->pre = m_head;
		tempPtr->next = m_tail;
		m_head->next = tempPtr;
		m_tail->pre = tempPtr;
		m_length++;
	}
	else {
		if (data < m_head->next->data) {//node가 데이터 존재 노드들중 가장 작은 값을 가질때
			tempPtr->pre = m_head;
			tempPtr->next = m_head->next;
			m_head->next->pre = tempPtr;
			m_head->next = tempPtr;

			m_length++;
		}
		else if (data > m_tail->pre->data) {//node가 데이터 존재 노드들중 가장 큰 값을 가질때
			tempPtr->next = m_tail;
			tempPtr->pre = m_tail->pre;
			m_tail->pre->next = tempPtr;
			m_tail->pre = tempPtr;

			m_length++;
		}
		else if (data - m_curPtr->next->data < m_tail->pre->data - data) {//node가 head쪽에 더 가까울때
			while (m_curPtr->next != m_tail) {
				m_curPtr = m_curPtr->next;
				if (data > m_curPtr->data && data < m_curPtr->next->data) {
					tempPtr->pre = m_curPtr;
					tempPtr->next = m_curPtr->next;
					m_curPtr->next->pre = tempPtr;
					m_curPtr->next = tempPtr;

					m_length++;
					break;
				}
			}
		}
		else if (data - m_curPtr->next->data > m_tail->pre->data - data) {//node가 tail쪽에 더 가까울때
			m_curPtr = m_tail;
			while (m_curPtr->pre != m_head) {
				m_curPtr = m_curPtr->pre;
				if (data < m_curPtr->data && data > m_curPtr->pre->data) {
					tempPtr->pre = m_curPtr->pre;
					tempPtr->next = m_curPtr;
					m_curPtr->pre->next = tempPtr;
					m_curPtr->pre = tempPtr;

					m_length++;
					break;
				}
			}
		}
	}
	//while (m_curPtr->next != m_tail) {			//넣으려는 Node가 맨 뒤에 붙는게 아닌 경우
	//	m_curPtr = m_curPtr->next;
	//	if (m_curPtr->data > data) {
	//		m_curPtr->pre->next = tempPtr;
	//		tempPtr->pre = m_curPtr->pre;
	//		m_curPtr->pre = tempPtr;
	//		tempPtr->next = m_curPtr;
	//		m_length++;
	//		break;
	//	}
	//}
	//m_curPtr->next->pre = tempPtr;				//넣으려는 Node가 맨 뒤에 붙을 경우
	//tempPtr->next = m_curPtr->next;
	//tempPtr->pre = m_curPtr;
	//m_curPtr->next = tempPtr;
	//m_length++;
}

//LinkedList에서 특정 노드를 삭제한다.
template <typename T>
void SortedLinkedListType<T>::Delete(T& data) {
	if (m_head->next != m_tail && m_tail->pre != m_head)
	{
		NodeType<T>* temp;
		ResetList();
		/*if (m_length == 1)
			m_curPtr = m_curPtr->next;
		if (data == m_curPtr->data) {
			data = m_curPtr->data;
			return 1;
		}*/
		if (m_head->next->data == m_tail->pre->data) {//node가 단한개만 존재할때
			m_curPtr = m_curPtr->next;
			if (data == m_curPtr->data) {
				data = m_curPtr->data;
				temp = m_curPtr;
				m_curPtr = m_head;
				m_head->next = m_tail;
				m_tail->pre = m_head;
				delete temp;
				m_length--;
			}
		}
		else if (data - m_curPtr->next->data < m_tail->pre->data - data) { //data 값이 tail보다 head쪽에 더 가까울때
			while (m_curPtr->next != m_tail) {
				m_curPtr = m_curPtr->next;
				if (m_curPtr->data == data) {
					if (m_head->next->data == data) {//data 값이 가장 첫번째 node일때
						m_head->next = m_curPtr->next;
						m_curPtr->next->pre = m_head;
					}
					else {
						m_curPtr->next->pre = m_curPtr->pre;
						m_curPtr->pre->next = m_curPtr->next;
					}
					data = m_curPtr->data;
					temp = m_curPtr;
					m_curPtr = m_curPtr->next;
					delete temp;
					m_length--;
					break;
				}
			}
		}
		else if (data - m_curPtr->next->data > m_tail->pre->data - data) {//data 값이 head보다 tail쪽에 더 가까울때
			m_curPtr = m_tail;
			while (m_curPtr->pre != m_head) {
				m_curPtr = m_curPtr->pre;
				if (m_curPtr->data == data) {
					if (m_tail->pre->data == data) {
						m_tail->pre = m_curPtr->pre;
						m_curPtr->pre->next = m_tail;
					}
					else {
						m_curPtr->next->pre = m_curPtr->pre;
						m_curPtr->pre->next = m_curPtr->next;
					}
				}
				data = m_curPtr->data;
				temp = m_curPtr;
				m_curPtr = m_curPtr->pre;
				delete temp;
				m_length--;
				break;
			}
		}
	}
	/*m_curPtr = m_head;
	while (m_curPtr->next != m_tail) {
		m_curPtr = m_curPtr->next;
		if (m_curPtr->data == data) {
			m_curPtr->next->pre = m_curPtr->pre;
			m_curPtr->pre->next = m_curPtr->next;
			delete m_curPtr;
			m_length--;
			return;
		}
	}*/
}

//LinkedList의 모든 요소들을 삭제한다.
template <typename T>
void SortedLinkedListType<T>::MakeEmpty() {
	while (m_tail->pre != m_head) {
		m_curPtr = m_tail->pre;
		m_curPtr->next->pre = m_curPtr->pre;
		m_curPtr->pre->next = m_curPtr->next;
		delete m_curPtr;
	}
	m_length = 0;
}

//LinkedList에서 반복자를 이동시켜 해당 반복자가 가리키는 Node의 data로 갱신한다.
template <typename T>
NodeType<T>* SortedLinkedListType<T>::GetNext(T& data) {
	if (m_curPtr->next != m_tail) {
		m_curPtr = m_curPtr->next;
		data = m_curPtr->data;
		return m_curPtr;
	}
	else {
		m_curPtr = m_head;
		return nullptr;
	}
}

//LinkedList의 반복자를 초기화한다.
template <typename T>
void SortedLinkedListType<T>::ResetList() {
	m_curPtr = m_head;
}

//LinkedList 내의 노드 갯수를 반환한다.
template <typename T>
int SortedLinkedListType<T>::GetLength() {
	return m_length;
}

//LinkedList 내의 노드가 비었는지 검사한다.
template <typename T>
bool SortedLinkedListType<T>::isEmpty() {
	return (m_length == 0);
}

//메모리상에 노드가 더 들어갈 수 있는지 검사한다.
template <typename T>
bool SortedLinkedListType<T>::isFull() {
	NodeType<T>* tempPtr;
	try
	{
		tempPtr = new NodeType<T>;
		delete tempPtr;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

//LinkedList에 동일한 data를 가진 Node가 존재하는지 검사한다.
template <typename T>
int SortedLinkedListType<T>::Get(T& data) {	
	if (m_head->next != m_tail && m_tail->pre != m_head) //node가 한개 이상 존재할때
	{
		ResetList();
		/*if (m_length == 1)
			m_curPtr = m_curPtr->next;
		if (data == m_curPtr->data) {
			data = m_curPtr->data;
			return 1;
		}*/
		if (m_head->next->data == m_tail->pre->data) {//node가 단한개만 존재할때
			m_curPtr = m_curPtr->next;
			if (data == m_curPtr->data) {
				data = m_curPtr->data;
				return 1;
			}
		}
		else if (data - m_curPtr->next->data < m_tail->pre->data - data) {//data 값이 tail보다 head쪽에 더 가까울때
			while (m_curPtr->next != m_tail) {
				m_curPtr = m_curPtr->next;
				if (m_curPtr->data == data) {
					data = m_curPtr->data;
					return 1;
				}
			}
		}
		else if (data - m_curPtr->next->data > m_tail->pre->data - data) {//data 값이 head보다 tail쪽에 더 가까울때
			m_curPtr = m_tail;
			while (m_curPtr->pre != m_head) {
				m_curPtr = m_curPtr->pre;
				if (m_curPtr->data == data) {
					data = m_curPtr->data;
					return 1;
				}
			}
		}
	}
	else
		return 0;

	return 0;
}