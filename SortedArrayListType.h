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
	*	기본 생성자
	*/
	SortedArrayList() {
		m_length = 0;
		m_curPos = -1;
	}

	//리스트의 반복자를 갱신(다음 데이터를 가리키도록)
	int GetNextVoca(T& voca) {
		m_curPos++;	// list pointer 증가
		if (m_curPos >= m_length)	// end of list이면 -1을 리턴
			return -1;

		voca = m_AllvocalList[m_curPos];	// 현재 list pointer의 레코드를 복사
		return m_curPos;
	}

	//리스트의 반복자를 초기화
	int ResetList() {
		m_curPos = -1;
		return 1;
	}

	//리스트에서 입력받은 인자가 존재하는지 검색
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

	// 리스트에 데이터를 추가
	void InsertVoca(T& voca) {
		T tempVoca;
		ResetList();
		while (GetNextVoca(tempVoca) != -1) {
			if ((tempVoca > voca)) {	//넣으려는 값이 배열 속 데이터보다 작다면 그 상태의 m_curPos에서 고정시킴
				break;
			}
		}
		for (int i = m_length; i > m_curPos; i--) {
			m_AllvocalList[i] = m_AllvocalList[i - 1];
		}
		m_AllvocalList[m_curPos] = voca;
		m_length++;


	}

	// 반복자가 가리키는 데이터의 포인터를 반환한다.
	T* GetCurPtr() {
		return &m_AllvocalList[m_curPos];
	}

	/**
	*	@brief	인자와 동일한 인덱스에 위치한 데이터를 포인터형으로 반환한다.
	*	@pre	i가 m_length를 넘으면 안된다.
	*	@post	없음
	*	@param	int i
	*	@return	m_AllVocaList의 i번째 데이터
	*/
	T GetIndexOfData(int i) {
		return (m_AllvocalList[i]);
	}

private:
	T m_AllvocalList[MAXSIZE];	//리스트
	int m_curPos;				//리스트의 반복자
	int m_length;				//리스트 내에 존재하는 데이터의 갯수
};