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
	/**
	*	@brief	�⺻ ������
	*	@post	LinkedList�� ��� ��������� �ʱ�ȭ�Ѵ�.
	*/
	SortedLinkedListType();

	/**
	*	@brief	�Ҹ���
	*	@post	LinkedList�� �����Ҵ�� ��� ��ҵ��� �Ҵ� �����Ѵ�.
	*/
	~SortedLinkedListType();

	/**
	*	@brief	���� ������
	*	@post	������ �����ϴ� SortedLinkedListType�� ��ü�κ��� ��� ������ deep copy�Ѵ�.
	*/
	SortedLinkedListType(const SortedLinkedListType& list);

	/**
	*	@brief	LinkedList�� ���ο� ��带 �߰��Ѵ�.
	*	@pre	data�� �Է¹޴´�.
	*	@post	LinkedList�� ���ο� ��尡 �߰��ȴ�.
	*/
	void Insert(T& data);

	/**
	*	@brief	LinkedList���� Ư�� ��带 �����Ѵ�.
	*	@pre	Get�Լ��� �ߺ� data���� Node�� �˻��ؾ��Ѵ�.
	*	@post	LinkedList���� Ư�� ��尡 �����ȴ�.
	*/
	void Delete(T& data);

	/**
	*	@brief	LinkedList�� ��� ��ҵ��� �����Ѵ�.
	*	@pre	Get�Լ��� ������� data�� ���� Node�� �����ϴ��� �˻��ؾ��Ѵ�.
	*	@post	LinkedList�� ��� ��ҵ��� �����ȴ�.
	*/
	void MakeEmpty();

	/**
	*	@brief	LinkedList���� �ݺ��ڸ� �̵����� �ش� �ݺ��ڰ� ����Ű�� Node�� data�� �����Ѵ�.
	*	@pre	data�� �Է¹޴´�.
	*	@post	LinkedList���� �ݺ��ڸ� �̵��ǰ� �ش� �ݺ��ڰ� ����Ű�� Node�� data�� ���ŵȴ�.
	*	@return	�ݺ��ڰ� ������ ���ٸ� nullptr, �ƴ϶�� �ݺ��ڰ� ����Ű�� Node�� �����͸� ��ȯ�Ѵ�.
	*/
	NodeType<T>* GetNext(T& data);

	/**
	*	@brief	LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
	*	@pre	LinkedLIst�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	LinkedList�� �ݺ��ڰ� �ʱ�ȭ�ȴ�.
	*/
	void ResetList();

	/**
	*	@brief	LinkedList ���� ��� ������ ��ȯ�Ѵ�.
	*	@pre	LinkedList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	LinkedList ���� ��� ������ ��ȯ�ȴ�.
	*	@return	LinkedList ���� ��� ����
	*/
	int GetLength();

	/**
	*	@brief	LinkedList ���� ��尡 ������� �˻��Ѵ�.
	*	@pre	LinkedList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	LinkedList ���� ��尡 ������� �˻��ϰԵȴ�.
	*	@return	������� true, �ƴ϶�� false�� ��ȯ
	*/
	bool isEmpty();

	/**
	*	@brief	�޸𸮻� ��尡 �� �� �� �ִ��� �˻��Ѵ�.
	*	@pre	LinkedList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�޸𸮻� ��尡 �� �� �� �ִ��� �˻��ϰԵȴ�.
	*	@return	��á���� true, �ƴ϶�� false�� ��ȯ
	*/
	bool isFull();

	/**
	*	@brief	LinkedList�� ������ data�� ���� Node�� �����ϴ��� �˻��Ѵ�.
	*	@pre	data�� �Է¹޴´�.
	*	@post	LinkedList ���� ���� data�� ���� Node�� ���� ���θ� �˰� �ȴ�.
	*	@return	�����Ѵٸ� 1, �ƴ϶�� 0�� ��ȯ
	*/
	int Get(T& data);

private:
	NodeType<T>* m_head;			//LinkedList���� ���� �տ� ��ġ�� ��带 ����Ű�� ������
	NodeType<T>* m_tail;			//LinkedList���� ���� �ڿ� ��ġ�� ��带 ����Ű�� ������
	NodeType<T>* m_curPtr;			//LinkedList���� �����ϴ� ����� ������ �����ϴ� int�� ����
	int m_length;
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
	m_head->data = NULL;
	m_head->pre = nullptr;
	m_head->next = m_tail;
	m_tail->data = NULL;
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
void SortedLinkedListType<T>::Insert(T& data) {
	NodeType<T>* tempPtr = new NodeType<T>;
	tempPtr->data = data;

	ResetList();
	if (m_head->next == m_tail && m_tail->pre == m_head) {//node�� �Ѱ��� �������� ������
		tempPtr->pre = m_head;
		tempPtr->next = m_tail;
		m_head->next = tempPtr;
		m_tail->pre = tempPtr;
		m_length++;
	}
	else {
		if (data < m_head->next->data) {//node�� ������ ���� ������ ���� ���� ���� ������
			tempPtr->pre = m_head;
			tempPtr->next = m_head->next;
			m_head->next->pre = tempPtr;
			m_head->next = tempPtr;

			m_length++;
		}
		else if (data > m_tail->pre->data) {//node�� ������ ���� ������ ���� ū ���� ������
			tempPtr->next = m_tail;
			tempPtr->pre = m_tail->pre;
			m_tail->pre->next = tempPtr;
			m_tail->pre = tempPtr;

			m_length++;
		}
		else if (data - m_curPtr->next->data < m_tail->pre->data - data) {//node�� head�ʿ� �� ����ﶧ
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
		else if (data - m_curPtr->next->data > m_tail->pre->data - data) {//node�� tail�ʿ� �� ����ﶧ
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
	//while (m_curPtr->next != m_tail) {			//�������� Node�� �� �ڿ� �ٴ°� �ƴ� ���
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
	//m_curPtr->next->pre = tempPtr;				//�������� Node�� �� �ڿ� ���� ���
	//tempPtr->next = m_curPtr->next;
	//tempPtr->pre = m_curPtr;
	//m_curPtr->next = tempPtr;
	//m_length++;
}

//LinkedList���� Ư�� ��带 �����Ѵ�.
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
		if (m_head->next->data == m_tail->pre->data) {//node�� ���Ѱ��� �����Ҷ�
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
		else if (data - m_curPtr->next->data < m_tail->pre->data - data) { //data ���� tail���� head�ʿ� �� ����ﶧ
			while (m_curPtr->next != m_tail) {
				m_curPtr = m_curPtr->next;
				if (m_curPtr->data == data) {
					if (m_head->next->data == data) {//data ���� ���� ù��° node�϶�
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
		else if (data - m_curPtr->next->data > m_tail->pre->data - data) {//data ���� head���� tail�ʿ� �� ����ﶧ
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

//LinkedList�� �ݺ��ڸ� �ʱ�ȭ�Ѵ�.
template <typename T>
void SortedLinkedListType<T>::ResetList() {
	m_curPtr = m_head;
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
	if (m_head->next != m_tail && m_tail->pre != m_head) //node�� �Ѱ� �̻� �����Ҷ�
	{
		ResetList();
		/*if (m_length == 1)
			m_curPtr = m_curPtr->next;
		if (data == m_curPtr->data) {
			data = m_curPtr->data;
			return 1;
		}*/
		if (m_head->next->data == m_tail->pre->data) {//node�� ���Ѱ��� �����Ҷ�
			m_curPtr = m_curPtr->next;
			if (data == m_curPtr->data) {
				data = m_curPtr->data;
				return 1;
			}
		}
		else if (data - m_curPtr->next->data < m_tail->pre->data - data) {//data ���� tail���� head�ʿ� �� ����ﶧ
			while (m_curPtr->next != m_tail) {
				m_curPtr = m_curPtr->next;
				if (m_curPtr->data == data) {
					data = m_curPtr->data;
					return 1;
				}
			}
		}
		else if (data - m_curPtr->next->data > m_tail->pre->data - data) {//data ���� head���� tail�ʿ� �� ����ﶧ
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