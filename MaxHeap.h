#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 1000


template <class T>
class MaxHeap {
public:
	/**
	*	
	*/
    MaxHeap();				//Default constructor
	/**
	*	
	*/
    MaxHeap(int size);		//Constructor with size parameter for setting 
	/**
	*	
	*/
	~MaxHeap() {			//Default destructor calling MakeEmpty function to deallocate all existing dynamic allocation
        MakeEmpty();
    }
	
    bool IsEmpty();
	
	bool IsFull();

	
    int GetLength() const;
	
	void MakeEmpty();		//Deallocate all dynamic allocations
	
    int Add(T item);		//Add a parameter item to Heap 
	
	int Delete(T item);		// Delete an item that matches the parameter item id. If properly deleted return 1, if not return 0 
	
	T Pop();				// Pop the node root
	
	void RetrieveItem(T& item, bool& found);// find an item matching with parmater item id. If found found boolean turns true 
	
	void PrintHeap(ostream& os);

    void ReheapDown(int iparent, int ibottom);			// iparent variable as parent node, ibottom as key node. Heap down process using recursion
    void ReheapUp(int iroot, int ibottom);				// iparent variable as parent node, ibottom as key node. Heap up process using recursion
    void Delete(T item, bool& found, int iparent);		// 
    void Retrieve(T& item, bool& found, int iparent);	//
private:
    T* m_pHeap;				//
    int m_iLastNode;		//Last node number of current Heap
    int m_nMaxSize;			//Maximum number of producable Heap node
};
template <typename T>
MaxHeap<T>::MaxHeap() {
    m_iLastNode = 0;
    m_nMaxSize = MAXSIZE;
    m_pHeap = new T[m_nMaxSize];
}

template <typename T>
MaxHeap<T>::MaxHeap(int size) {
    m_iLastNode = 0;
    m_nMaxSize = size;
    m_pHeap = new T[m_nMaxSize];
}
template <typename T>
bool MaxHeap<T>::IsFull() {
    return (m_iLastNode == m_nMaxSize);
}

template <typename T>
bool MaxHeap<T>::IsEmpty() {
    return (m_iLastNode == 0);
}

template <typename T>
void MaxHeap<T>::MakeEmpty() {
    m_iLastNode = 0;
    m_pHeap = nullptr;
}

template <typename T>
int MaxHeap<T>::Add(T item) {
    m_pHeap[m_iLastNode++] = item;
    ReheapUp(0, m_iLastNode - 1);
    return 1;
}

template <typename T>
int MaxHeap<T>::Delete(T item) {
    bool found;
    int iparent = 0;
    Delete(item, found, iparent);

    return found;
}


template <typename T>
T MaxHeap<T>::Pop() {
    T temp;
    temp = m_pHeap[0];
    m_pHeap[0] = m_pHeap[m_iLastNode - 1];
    m_iLastNode--;
    ReheapDown(0, m_iLastNode - 1);
    return temp;

}
template <typename T>
void MaxHeap<T>::RetrieveItem(T& item, bool& found) {
    int iparent = 0;
    Retrieve(item, found, iparent);
}

template <typename T>
void MaxHeap<T>::PrintHeap(ostream& out) {
    for (int i = 0; i < m_iLastNode; i++)
        out << m_pHeap[i] << ' ';
}

template <typename T>
void MaxHeap<T>::ReheapDown(int iparent, int ibottom) {
    int maxChild, rightChild, leftChild;

    leftChild = iparent * 2 + 1;
    rightChild = iparent * 2 + 2;

    if (leftChild <= ibottom) {
        if (leftChild == ibottom)
            maxChild = leftChild;
        else {
            if (m_pHeap[leftChild] <= m_pHeap[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (m_pHeap[iparent] < m_pHeap[maxChild]) {
            swap(m_pHeap[iparent], m_pHeap[maxChild]);
            ReheapDown(maxChild, ibottom);
        }
    }
}

template <typename T>
void MaxHeap<T>::ReheapUp(int iparent, int ibottom) {
    int parent = 0;
    if (ibottom > iparent) {
        parent = (ibottom - 1) / 2;
        if (m_pHeap[parent] < m_pHeap[ibottom]) {
            swap(m_pHeap[parent], m_pHeap[ibottom]);
            ReheapUp(iparent, parent);
        }
    }
}

template <typename T>
void MaxHeap<T>::Delete(T item, bool& found, int iparent) {
    if (m_pHeap[iparent] == item) {
        m_pHeap[iparent] = m_pHeap[--m_iLastNode];
        ReheapDown(iparent, m_iLastNode - 1);
        found = true;
        return;
    }
    else
        Delete(item, found, ++iparent);
}

template <typename T>
void MaxHeap<T>::Retrieve(T& item, bool& found, int iparent) {
    if (iparent == m_iLastNode)
        return;

    if (item == m_pHeap[iparent]) {
        item = m_pHeap[iparent];
        found = true;
    }
    else
        Retrieve(item, found, iparent++);
}

template <typename T>
int MaxHeap<T>::GetLength()const {
    return m_iLastNode;
}
