#pragma once
#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct NodeType
{
	T data;							//NodeType�� ������
	NodeType<T>* pre = nullptr;		//���� Node�� ����Ű�� ������
	NodeType<T>* next = nullptr;	//���� Node�� ����Ű�� ������
};

template <typename T>
class SortedLinkedListType {
public:
	/*
	*	@brief	Default constructor
	*/
	SortedLinkedListType();

	/**
	*	@brief	Destructor
	*	@post	Deallocate all dynamic allocation in LinkedList
	*/
	~SortedLinkedListType();

	/**
	*	@brief	Copy constructor
	*	@post	������ �����ϴ� SortedLinkedListType�� ��ü�κ��� ��� ������ deep copy�Ѵ�.
	*/
	SortedLinkedListType(const SortedLinkedListType& list);

	/**
	*	@brief	Add a new node to LinkedList
	*	@pre	Get data input
	*	@post	Add new node to linkedList
	*   @return If node is added return 1, if not return 0
	*/
	int Insert(T& data);

	/**
	*	@brief	Delete a node containing parameter data info inside LinkedList.
	*	@pre	Check duplicate data using Get function
	*	@post	Certain node is deleted
	*   @return If node is deleted return 1, if not return 0
	*/
	int Delete(T& data);

	/**
	*    @brief   Replace a certain node inside LinkedList to contain different info 
	*    @pre    Check duplicate data using Get function
	*    @post    Certain node is replaced
	*/
	void Replace(const T& data);

	/**
	*	@brief	Delete all instance inside the list
	*	@pre	Check if the node exsits using Get function
	*	@post	All list nodes are deleted
	*/
	void MakeEmpty();

	/**
	*	@brief	Move the iterator to have the next data 
	*	@pre	Get data input
	*	@post	Iterator is moved and the data is renewed to the next node
	*	@return	if it is null pointer return 0, if not return the current pointed node
	*/
	NodeType<T>* GetNext(T& data);

	//LinkedList�� �ݺ��ڸ� pre�������� �̵���Ű�� �׶� ����Ű�� Node�� data�� ��ȯ�Ѵ�.
	NodeType<T>* GetPre(T& data);

	/**
	*	@brief	LinkedList iterator must be initialized
	*	@pre	LinkedLIst must be initialized
	*	@post	LinkedList�� iterator turned to default setting
	*/
	void ResetList();

	//initialize the LinkedList iterator to circulate to pre direction.
	void ResetListForGetPre();

	/**
	*	@brief	Return number of nodes inside LinkedList .
	*	@pre	LinkedList must be initialized.
	*	@post	Total number of nodes inside LinkedList is returned.
	*	@return	Node number of from linkedlist
	*/
	int GetLength();

	/**
	*	@brief	Check if the LinkedList is empty
	*	@pre	LinkedList must be initialized.
	*	@post	Check if the LinkedList is empty.
	*	@return	if empty return true, if not return false
	*/
	bool isEmpty();

	/**
	*	@brief	Check if it is possible to allocate more nodes to memory
	*	@pre	LinkedList must be initialized
	*	@post	Check if it is possible to allocate more nodes to memory.
	*	@return	if full return true, if not return false
	*/
	bool isFull();

	/**
	*	@brief	Search for matching data inside list with parameter data.
	*	@pre	Get input from data.
	*	@post	Know if the finding data item exists inside the list.
	*	@return	if exists return true, if not return false
	*/
	int Get(T& data);

	//Check rear data if parameter data matches with it. return 1 if matched, if not return 0
	int CheckBack(T& data);
	
	//Insert after current rear data if parameter data is bigger than rear data. return 1 if inserted, if not return 0
	int InsertTail(T& data);

	//Delete rear data if parameter data matches with it. return 1 if deleted, if not return 0
	int DeleteTail(T& data);

	// Return data that current pointer is pointing
	T* GetCurPtr() {
		return &(m_curPtr->data);
	}

	/*
	*	@brief	Deep copy Constructor 
	*	@pre	Not executed if array list is empty or is maxsize
	*	@post	Size of the array list decreases 500
	*/
	SortedLinkedListType<T>& operator=(const SortedLinkedListType<T>& list);

private:
	NodeType<T>* m_head;			//Pointer for pointing front node of the list
	NodeType<T>* m_tail;			//Pointer for pointing rear node of the list
	NodeType<T>* m_curPtr;			//Current node location pointer
	int m_length;					//Current total length of node
};

//LinkedList�� ����������� �ʱ�ȭ�Ѵ�.
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

//������ �����ϴ� SortedLinkedListType�� ��ü�κ��� ��� ������ deep copy�Ѵ�.
template <typename T>
SortedLinkedListType<T>::SortedLinkedListType(const SortedLinkedListType& list) {
	m_head = new NodeType<T>;
	m_tail = new NodeType<T>;
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = list.m_length;
	/*
		list ���� ��� ��忡�� data���� �̾ƿ� �ش� SortedLinkedListType��ü�� ����Ʈ�� �����Ѵ�.
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

//LinkedList�� �����Ҵ�� ��� ��ҵ��� �Ҵ� �����Ѵ�.
template <typename T>
SortedLinkedListType<T>::~SortedLinkedListType() {
	MakeEmpty();
	delete m_head;
	delete m_tail;
}

//LinkedList�� ���ο� ��带 �߰��Ѵ�.
template <typename T>
int SortedLinkedListType<T>::Insert(T& data) {
	if (isFull()) {
		return 0;
	}
	else if (InsertTail(data)) {
		return 1;
	}
	else {
		NodeType<T>* tempPtr = new NodeType<T>;
		tempPtr->data = data;

		m_curPtr = m_head;
		while (m_curPtr->next != m_tail) {            //�������� Node�� �� �ڿ� �ٴ°� �ƴ� ���
			m_curPtr = m_curPtr->next;
			if (m_curPtr->data > data) {
				m_curPtr->pre->next = tempPtr;
				tempPtr->pre = m_curPtr->pre;
				m_curPtr->pre = tempPtr;
				tempPtr->next = m_curPtr;
				m_length++;
				return 1;
			}
		}
		return 0;
	}
}

//LinkedList���� Ư�� ��带 �����Ѵ�.
template <typename T>
int SortedLinkedListType<T>::Delete(T& data) {
	if (isEmpty()) {
		return 0;
	}
	else if (DeleteTail(data)) {
		return 1;
	}
	else {
		m_curPtr = m_head;
		while (m_curPtr->next != m_tail) {
			m_curPtr = m_curPtr->next;
			if (m_curPtr->data == data) {
				m_curPtr->next->pre = m_curPtr->pre;
				m_curPtr->pre->next = m_curPtr->next;
				delete m_curPtr;
				m_length--;
				return 1;
			}
		}
		return 0;
	}
}

//LinkedList���� Ư�� ��带 �����Ѵ�.
template <typename T>
void SortedLinkedListType<T>::Replace(const T& data) {
	m_curPtr = m_head;
	while (m_curPtr->next != m_tail) {
		m_curPtr = m_curPtr->next;
		if (m_curPtr->data == data) {
			m_curPtr->data = data;
			return;
		}
	}
}

//LinkedList�� ��� ��ҵ��� �����Ѵ�.
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

//LinkedList���� �ݺ��ڸ� �̵����� �ش� �ݺ��ڰ� ����Ű�� Node�� data�� �����Ѵ�.
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

template <typename T>
NodeType<T>* SortedLinkedListType<T>::GetPre(T& data) {
	if (m_curPtr->pre != m_head) {
		m_curPtr = m_curPtr->pre;
		data = m_curPtr->data;
		return m_curPtr;
	}
	else {
		m_curPtr = m_tail;
		return nullptr;
	}
}



//LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
template <typename T>
void SortedLinkedListType<T>::ResetList() {
	m_curPtr = m_head;
}

//LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
template <typename T>
void SortedLinkedListType<T>::ResetListForGetPre() {
	m_curPtr = m_tail;
}

//LinkedList ���� ��� ������ ��ȯ�Ѵ�.
template <typename T>
int SortedLinkedListType<T>::GetLength() {
	return m_length;
}

//LinkedList ���� ��尡 ������� �˻��Ѵ�.
template <typename T>
bool SortedLinkedListType<T>::isEmpty() {
	return (m_length == 0);
}

//�޸𸮻� ��尡 �� �� �� �ִ��� �˻��Ѵ�.
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

//LinkedList�� ������ data�� ���� Node�� �����ϴ��� �˻��Ѵ�.
template <typename T>
int SortedLinkedListType<T>::Get(T& data) {
	if (m_length == 0) {
		return 0;
	}
	else if (CheckBack(data)){
		return 1;
	}
	else {
		m_curPtr = m_head;
		while (m_curPtr->next != m_tail) {
			m_curPtr = m_curPtr->next;
			if (m_curPtr->data == data) {
				data = m_curPtr->data;
				return 1;
			}
		}
	}
	return 0;
}

template <typename T>
int SortedLinkedListType<T>::CheckBack(T& data) {
	if (m_length == 0) {
		return 0;
	}
	else if(m_tail->pre->data == data) {
		data = m_tail->pre->data;
		return 1;
	}
	else {
		return 0;
	}
}

template <typename T>
int SortedLinkedListType<T>::InsertTail(T& data) {
	if (isFull()) {
		return 0;
	}
	else {
		if (m_length == 0 || m_tail->pre->data < data) {
			NodeType<T>* temp = new NodeType<T>;
			temp->data = data;
			
			temp->next = m_tail;
			temp->pre = m_tail->pre;
			m_tail->pre->next = temp;
			m_tail->pre = temp;

			m_length++;
			return 1;
		}
		else {
			return 0;
		}
	}
}


template <typename T>
int SortedLinkedListType<T>::DeleteTail(T& data) {
	if (m_length == 0) {
		return 0;
	}
	else if (m_tail->pre->data == data) {
		m_curPtr = m_tail->pre;
		m_curPtr->pre->next = m_tail;
		m_tail->pre = m_curPtr->pre;
		m_length--;
		delete m_curPtr;
		m_curPtr = nullptr;
		return 1;
	}
	else {
		return 0;
	}
}

//���Կ����� �����ε�
template <typename T>
SortedLinkedListType<T>& SortedLinkedListType<T>::operator=(const SortedLinkedListType<T>& list) {
	MakeEmpty();
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->next = nullptr;
	m_tail->pre = m_head;
	m_curPtr = m_head;
	m_length = list.m_length;
	/*
		list ���� ��� ��忡�� data���� �̾ƿ� �ش� SortedLinkedListType��ü�� ����Ʈ�� �����Ѵ�.
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
	return *this;
}



