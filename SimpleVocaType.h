#include "VocaType.h"

#pragma once
class SimpleVocaType {
public:

	//Default constuctor
	SimpleVocaType() {
		m_ptr = nullptr;
	}

	//Set the pointer member to point parameter address
	void SetPtr(VocaType* ptr) {
		m_ptr = ptr;
	}

	//return current pointer address.
	VocaType* GetPtr() {
		return m_ptr;
	}

	//Compare between current class Vocatype pointer value id and parameter VocaType pointer value. If larger return true, if smaller return false
	bool operator < (SimpleVocaType& s_voca) {
		return (m_ptr->GetId() < s_voca.GetPtr()->GetId());
	}

	//Compare between current class Vocatype pointer value id and parameter VocaType pointer value. If larger return false, if smaller return true
	bool operator > (SimpleVocaType& s_voca) {
		return (m_ptr->GetId() > s_voca.GetPtr()->GetId());
	}

	//Compare between current class Vocatype pointer value id and parameter VocaType pointer value. If same return true, if different return false
	bool operator == (SimpleVocaType& s_voca) {
		return (m_ptr->GetId() == s_voca.GetPtr()->GetId());
	}

	//m_id 값을 초기화한다.
	/*
	void SetId(int id) {
		m_id = id;
	}
	*/

	//m_id를 반환한다.
	/*
	int GetId() {
		return m_id;
	}
	*/

private:
	//int m_id;				//SimpleVoca의 고유 id값
	VocaType* m_ptr;		//Pointer variable of SimplaVoca class
};