#include <iostream>
#include <string>
#include <fstream>

#include "VocaType.h"
using namespace std;

#define MAXSIZE 1000

template<class T>
class SortedArrayList {
public:
	/**
	*	�⺻ ������
	*/
	SortedArrayList() {
		m_length = 0;
		m_curPos = -1;
	}

	//����Ʈ�� �ݺ��ڸ� ����(���� �����͸� ����Ű����)
	int GetNextVoca(T& voca) {
		m_curPos++;	// list pointer ����
		if (m_curPos >= m_length)	// end of list�̸� -1�� ����
			return -1;

		voca = m_AllvocalList[m_curPos];	// ���� list pointer�� ���ڵ带 ����
		return m_curPos;
	}

	//����Ʈ�� �ݺ��ڸ� �ʱ�ȭ
	int ResetList() {
		m_curPos = -1;
		return 1;
	}

	//����Ʈ���� �Է¹��� ���ڰ� �����ϴ��� �˻�
	int Get(T& voca) {
		if (m_length > 0)
		{
			ResetList();
			int head = 0;
			int tail = m_length - 1;

			while (head <= tail)
			{
				m_curPos = (tail + head) / 2;
				if (voca == m_AllvocalList[m_curPos]) {
					voca = m_AllvocalList[m_curPos];
					return 1;
				}
				else if (voca > m_AllvocalList[m_curPos]) {
					head = m_curPos + 1;
				}
				else if (voca < m_AllvocalList[m_curPos]) {
					tail = m_curPos - 1;
				}
			}
		}
		else
			return 0;

		return 0;
	}

	// ����Ʈ�� �����͸� �߰�
	void InsertVoca(T& voca) {
		T tempVoca;
		ResetList();
		while (GetNextVoca(tempVoca) != -1) {
			if ((tempVoca > voca)) {	//�������� ���� �迭 �� �����ͺ��� �۴ٸ� �� ������ m_curPos���� ������Ŵ
				break;
			}
		}
		for (int i = m_length; i > m_curPos; i--) {
			m_AllvocalList[i] = m_AllvocalList[i - 1];
		}
		m_AllvocalList[m_curPos] = voca;
		m_length++;


	}

	// �ݺ��ڰ� ����Ű�� �������� �����͸� ��ȯ�Ѵ�.
	T* GetCurPtr() {
		return &m_AllvocalList[m_curPos];
	}

	/**
	*	@brief	���ڿ� ������ �ε����� ��ġ�� �����͸� ������������ ��ȯ�Ѵ�.
	*	@pre	i�� m_length�� ������ �ȵȴ�.
	*	@post	����
	*	@param	int i
	*	@return	m_AllVocaList�� i��° ������
	*/
	T GetIndexOfData(int i) {
		return (m_AllvocalList[i]);
	}

private:
	T m_AllvocalList[MAXSIZE];	//����Ʈ
	int m_curPos;				//����Ʈ�� �ݺ���
	int m_length;				//����Ʈ ���� �����ϴ� �������� ����
};