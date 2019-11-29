#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include<ios>
#include "QueueType.h"
#include "StackType.h"
#include "VocaType.h"
#include "SimpleVocaType.h"
#include "SortedArrayListType.h"
#include "SortedLinkedListType.h"
#define FILENAMESIZE 1024
using namespace std;


class Application {
	SortedArrayList<VocaType> m_AllVocaList;			//영어 단어 검색
	SortedLinkedListType<SimpleVocaType> m_MyVocaList;	//내 단어장 리스트
	SortedArrayList<SimpleVocaType> m_AllSimpleList;	//전체 간단 단어 리스트
	StackType<SimpleVocaType> m_TestVocaList;			//영어단어 테스트용 단어리스트
	Queue<SimpleVocaType> m_LearnVocaList;				//학습용 단어리스트
	int m_LearnLevel;									//학습레벨
	int m_command;										//사용자 명령
	ifstream m_InFile;									//입력용 파일 descriptor
	ofstream m_OutFile;									//출력용 파일 descriptor

public:
	/**
	*	기본 생성자.
	*/
	Application() {
		m_command = -1;
		m_LearnLevel = 0;
	}
	/**
	*	@brief
	*	@pre	없음
	*	@post   선택 기능이 종료된다.
	*/
	void Run();

	/**
	*	@brief	내 단어장 관리 driver
	*	@pre	없음
	*	@post	내 단어장 관리기능이 종료된다.
	*/
	void RunManageMyVocaList();
	/**
	*	@brief	화면에 5가지 기능의 명령어 목록을 출력하고 키보드로 선택된 명령을 입력받는다.
	*	@pre	없음
	*	@post	없음
	*	@return	command
	*/
	int GetCommand();
	/**
	*	@brief	화면에 영어단어 학습레벨을 출력하고 키보드로 선택된 학습레벨을 입력받는다.
	*	@pre	none.
	*	@post	none.
	*	@return	m_command
	*/
	int GetCommandLearnLevel();
	/**
	*	@brief	화면에 내 단어장 관리 명령어 목록을 출력하고 키보드로 선택된 명령을 입력받는다.
	*	@pre	없음
	*	@post	없음
	*	@return	m_command
	*/
	int GetCommandMyVocaList();
	/**
	*	@brief	영어단어 검색기능 driver
	*	@pre	없음
	*	@post	영어단어 검색기능이 종료
	*/
	void SearchVoca();
	/**
	*	@brief	영어단어 테스트기능 driver
	*	@pre	없음
	*	@post	영어단어 테스트기능이 종료
	*/
	void TestVoca();
	/**
	*	@brief	영어단어 학습기능 driver
	*	@pre	없음
	*	@post	영어단어 학습기능이 종료
	*/
	void LearnVoca();
	/**
	*	@brief	내 단어장 리스트에 영어단어를 추가한다.
	*	@pre	내 단어장 리스트가 초기화 되어있어야한다.
	*	@post	내 단어장 리스트에 영어단어가 추가된다.
	*	@return	추가에 성공하면 1, 그렇지 않으면 0을 반환
	*/
	void AddMyVoca();

	/**
	*	@brief	영어단어 학습을 시작한다.
	*	@pre	m_LearnList가 초기화 되어있어야한다.
	*	@post	영어단어 학습이 시작된다.
	*/
	void LearnLevel(int c);

	/**
	*	@brief	영어단어 200개에 대한 학습을 반복한다.
	*	@pre	m_LearnVocaList가 초기화 되어있어야한다.
	*	@post	영어단어 200개에 대한 학습이 반복된다.
	*	@return	반복 성공시 1, 아니면 0을 반환
	*/
	int ExecuteLearn();

	/**
	*	@brief	사용자의 학습레벨을 반환한다.
	*	@pre	사용자의 학습레벨이 초기화 되어있어야한다.
	*	@post	없음
	*	@return	m_LearnLevel;
	*/
	int GetLearnLevel();

	/**
	*	@brief	내 단어장 리스트에서 특정 영어단어를 삭제한다.
	*	@pre	내 단어장 리스트가 초기화 되어있어야한다.
	*	@post	내 단어장 리스트에서 특정 영어단어가 삭제된다.
	*	@return 삭제에 성공하면 1, 그렇지 않으면 0을 반환
	*/
	void DeleteMyVoca();

	/**
	*	@brief	텍스트 파일로부터 단어와 뜻을 불러온다.
	*	@pre	없음
	*	@post	m_AllVocaList에 VocaType item이 저장된다.
	*/
	void InitWordBook();

	/**
	*	@brief	내 단어장 리스트의 모든 영어단어를 화면에 출력한다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayMyVoca();

};

void Application::Run() {
	while (1) {
		m_command = GetCommand();
		switch (m_command) {
		case 1: // 영어단어 검색
			SearchVoca();
			break;
		case 2: // 단어테스트
			TestVoca();
			break;
		case 3: // 학습하기
			LearnVoca();
			break;
		case 4: // 나만의 단어장
			RunManageMyVocaList();
			break;
		case 0:
			cout << "종료합니다.." << endl;
			return;
		default:
			cout << "Caution" << endl;
			break;
		}
	}
}


//내 단어장 관리 driver
void Application::RunManageMyVocaList() {
	while (1)
	{
		m_command = GetCommandMyVocaList();

		switch (m_command)
		{
		case 1:		// 내 단어장 리스트에 영어단어를 추가한다.
			AddMyVoca();
			break;
		case 2:		// 내 단어장 리스트에서 특정 영어단어를 삭제한다.
			DeleteMyVoca();
			break;
		case 3:		// 내 단어장의 모든 영어단어를 화면에 출력한다.
			DisplayMyVoca();
			break;
		case 4:		// 내 단어장에 있는 모든 영어단어를 내 단어장 리스트에서 삭제한다.
			m_MyVocaList.MakeEmpty();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
		}
	}
}

int Application::GetCommand() {
	int c;
	cout << endl << endl;
	cout << "\t****************************" << endl << endl;
	cout << "\t    1. 영어단어 검색" << endl;
	cout << "\t    2. 단어테스트" << endl;
	cout << "\t    3. 학습하기" << endl;
	cout << "\t    4. 나만의 단어장" << endl;
	cout << "\t    0. 나가기" << endl << endl;
	cout << "\t****************************" << endl << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> c;
	cout << endl;
	return c;
}

int Application::GetCommandLearnLevel() {
	int command;
	cout << endl << endl;
	cout << "\t---Select Learn Level -- Command ----- " << endl;
	cout << "\t   1 : Level1(001~200)" << endl;
	cout << "\t   2 : Level2(201~400)" << endl;
	cout << "\t   3 : Level3(401~600)" << endl;
	cout << "\t   4 : Level4(601~800)" << endl;
	cout << "\t   5 : Level5(801~1000)" << endl;
	cout << "\t   0 : 나가기" << endl;

	cout << endl << "\t Choose a Level--> ";
	cin >> command;
	cout << endl;

	return command;
}

//화면에 내 단어장 관리 명령어 목록을 출력하고 키보드로 선택된 명령을 입력받는다.
int Application::GetCommandMyVocaList() {
	int command;
	cout << endl << endl;
	cout << "\t -------내 단어장 관리------- " << endl;
	cout << "\t   1 : 단어 추가" << endl;
	cout << "\t   2 : 단어 삭제" << endl;
	cout << "\t   3 : 단어 조회" << endl;
	cout << "\t   4 : 전체 삭제" << endl;
	cout << "\t   0 : 나가기" << endl;

	cout << endl << "\t Choose a Command Number--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::SearchVoca() {
	VocaType Item;
	Item.SetEnglishFromKB();
	m_AllVocaList.ResetList();

	//영어 단어 프로그램에 찾는 영어단어가 존재하지않을 경우
	if (!m_AllVocaList.Get(Item)) {
		cout << "\n\t검색한 영어단어는 프로그램 내에 존재하지 않습니다." << endl;
	}
	//영어 단어 프로그램에 찾는 영어단어가 존재할 경우
	else {
		Item.DisplayKorean();
	}
}

void Application::TestVoca() {
	//  프로그램이 단어를 임의로 선정하여 사용자의 단어암기 수준을 테스트하는 함수
	SimpleVocaType simpleTempVoca;
	m_AllSimpleList.ResetList();
	srand(time(NULL));
	int randArr[50];
	for (int i = 0; i < 50; i++) {									//0~999의 범위에서 50개를 랜덤으로 차출해서 
																	//배열 randArr[]에 넣는다.
		randArr[i] = rand() % 1000; //0~999의 범위
		for (int j = 0; j < i; j++) {
			if (randArr[j] == randArr[i]) {
				i--;
				break;
			}
		}
	}
	//배열 randArr[]에 속한 숫자들에 대응하는 배열의 데이터들을
	//단어 테스트용 스택에 넣는다.
	for (int i = 0; i < 50; i++) {
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(randArr[i]);
		m_TestVocaList.push(simpleTempVoca);
	}

	int count = 1, correct = 0, incorrect = 0;
	string English;
	if (m_TestVocaList.isEmpty())
		Run();
	else {
		cout.precision(3); //숫자 자릿수가 3개까지만 출력되게 설정
		while (1) {
			if (m_TestVocaList.getLength() == 0)
				break;
			cout << "\t단어테스트 ( " << count << "/ 50 ) => 정답 : " << correct << " 오답 : " << incorrect << endl;

			m_TestVocaList.pop(simpleTempVoca);
			simpleTempVoca.GetPtr()->DisplayCorrectPercent();
			simpleTempVoca.GetPtr()->DisplayKorean();
			cout << "\n\t0. 나가기 " << endl;
			cout << "\n\t->"; cin >> English; cout << endl;
			if (English == "0") {
				cout << endl << "\t<<결과>> 정답 : " << correct << " 오답 : " << incorrect << " 점수 : " << correct * 2 << "점 " << endl;
				m_TestVocaList.MakeEmpty();
				return;
			}
			else if (simpleTempVoca.GetPtr()->GetEnglish().compare(English) != 0) {
				incorrect++;
				count++;
				English = simpleTempVoca.GetPtr()->GetEnglish();
				cout << "\t오답!! (" << English << ")" << endl << endl;
				simpleTempVoca.GetPtr()->PlusWrong();
			}
			else {
				correct++;
				count++;
				simpleTempVoca.GetPtr()->PlusCorrect();
				cout << "\t정답!!" << endl << endl;
			}
		}
		ios_base::fmtflags f(cout.flags()); //precision 출력설정 초기화
		cout << endl << "\t<<결과>> 정답 : " << correct << " 오답 : " << incorrect << " 점수 : " << correct * 2 << "점 " << endl;
	}
}

//영어단어 학습기능 driver
void Application::LearnVoca() {
	while (1)
	{
		m_command = GetCommandLearnLevel();
		if (m_command == 0) {
			return;
		}
		else if (m_command >= 1 && m_command <= 5) {
			LearnLevel(m_command);
		}
		else {
			cout << "\tIllegal selection...\n";
		}
	}
}

void Application::LearnLevel(int c) {
	if (m_LearnLevel < c - 1) {
		cout << "\n\tLevel" << m_LearnLevel + 1 << "부터 학습해주세요.\n";
		return;
	}
	SimpleVocaType simpleTempVoca;
	m_LearnVocaList.MakeEmpty();
	m_AllSimpleList.ResetList();
	srand(time(NULL));
	int randArr[200];
	for (int i = 0; i < 200; i++) {
		randArr[i] = rand() % 200 + (((c - 1) * 200));	//c는 선택된 레벨이다. c가 1이면 0~199 index에 위치한 데이터
		for (int j = 0; j < i; j++) {					//					   c가 2면 200~399 index에 위치한 데이터
			if (randArr[j] == randArr[i]) {
				i--;
				break;
			}
		}
	}
	// m_LearnVocaList에 m_id 1~200에 해당하는 VocaType을 enQueue한다.
	for (int i = 0; i < 200; i++) {
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(randArr[i]);	//0~199의 인덱스에 위치한 데이터가 무작위로 
		m_LearnVocaList.enQueue(simpleTempVoca);						//학습용 큐에 채워진다.
	}

	//위에서 정해진 영어단어 200개에 대한 학습을 반복한다.
	ExecuteLearn();														//위에서 채워진 학습용 큐에 대한 반복학습이 시작된다.
}

//영어단어 200개에 대한 학습을 반복한다.
int Application::ExecuteLearn() {
	string tempString;
	SimpleVocaType simpleTempVoca;

	// m_LearnVocaList에 VocaType이 전부 없어지기 전까지 반복학습 시작
	while (m_LearnVocaList.GetLength() != 0)
	{
		m_LearnVocaList.deQueue(simpleTempVoca);
		simpleTempVoca.GetPtr()->DisplayKorean();
		cout << "\t해당하는 단어입력(중간퇴장: Y): ";
		cin >> tempString;
		if (simpleTempVoca.GetPtr()->GetEnglish().compare(tempString) != 0)	//오답일 경우
		{
			if (tempString == "Y")	//나가고 싶을 경우
			{
				cout << "\n\tLevel" << m_LearnLevel + 1 << "을 포기합니다.\n";
				m_LearnVocaList.MakeEmpty();
				return 0;
			}
			m_LearnVocaList.enQueue(simpleTempVoca);
			tempString = simpleTempVoca.GetPtr()->GetEnglish();
			cout << "\t오답(" << tempString << "), 남은 학습단어: " << m_LearnVocaList.GetLength() << "개" << endl;
		}
		else
		{													//정답일 경우
			cout << "\t정답, 남은 학습단어: " << m_LearnVocaList.GetLength() << "개" << endl;
		}
	}
	cout << "\n\tLevel" << m_LearnLevel + 1 << "단계를 학습 완료했습니다.\n";
	if (m_LearnLevel < 4)
		m_LearnLevel++;
	return 1;
}
int Application::GetLearnLevel() {
	return m_LearnLevel;
}

//내 단어장 리스트에 영어단어를 추가한다.
void Application::AddMyVoca() {
	VocaType tempVoca;
	SimpleVocaType simpleTempVoca;

	cout << "\n\t내 단어장 리스트에 추가하려는 영어단어 검색: ";
	tempVoca.SetEnglishFromKB();
	if (m_AllVocaList.Get(tempVoca)) {		//영어단어 프로그램에 검색한 영어단어가 존재하는지 검사
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(tempVoca.GetId() - 1);
		if (!m_MyVocaList.Get(simpleTempVoca)) {	//내 단어장 리스트에 추가하려는 영어단어가 존재하는지 검사
			m_MyVocaList.Insert(simpleTempVoca);
			cout << "\n\t내 단어장 리스트 업데이트 완료\n";
		}
		else {								//내 단어장 리스트에 이미 존재하는 영어단어일 경우
			cout << "\n\t해당 단어는 내 단어장 리스트 이미 존재\n";
		}
	}
	else {									//영어단어 프로그램에 존재하지 않는 영어단어일 경우
		cout << "\n\t해당 단어는 영어단어 프로그램에 존재하지 않습니다.\n";
	}
}

//내 단어장 리스트에서 특정 영어단어를 삭제한다.
void Application::DeleteMyVoca() {
	VocaType tempVoca;
	SimpleVocaType simpleTempVoca;

	cout << "\n\t내 단어장 리스트에서 삭제하려는 영어단어 입력: ";
	tempVoca.SetEnglishFromKB();
	if (m_AllVocaList.Get(tempVoca)) {				//프로그램에 삭제하려는 영어단어가 존재하는지 검사
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(tempVoca.GetId() - 1);
		if (m_MyVocaList.Get(simpleTempVoca)) {		//내 단어장 리스트에 삭제하려는 영어단어가 존재하는 검사
			m_MyVocaList.Delete(simpleTempVoca);
			cout << "\n\t내 단어장 리스트 업데이트 완료\n";
		}
		else {										//내 단어장 리스트에 삭제하려는 영어단어가 존재하지 않는 경우
			cout << "\n\t해당 단어는 내 단어장 리스트에 존재하지 않음\n";
		}
	}
	else {											//프로그램에 삭제하려는 영어단어가 존재하지 않는 경우
		cout << "\n\t해당 단어는 프로그램에 존재하지 않음\n";
	}
}


void Application::InitWordBook() {
	m_InFile.open("WordFile.txt");
	VocaType item;							//Item 삽입할 영단어 정보를 담을 VocaType 객체
	SimpleVocaType simpleItem;				//읽어온 데이터가 담긴 item 객체를 SimpleVocaType 객체인자로 넘겨줌
	m_AllVocaList.ResetList();

	//파일로부터 voca정보를 불러와서 m_AllVocaList를 구성한다.
	while (!m_InFile.eof()) {
		item.ReadDataFromFile(m_InFile);
		m_AllVocaList.InsertVoca(item);//현재 포인터 위치에 읽어온 데이터가 담긴 item 객체를 인자 보냄
	}
	m_InFile.close();

	//m_AllSimpleList를 1000개의 Voca 객체 정보로 구성한다.
	m_AllVocaList.ResetList();
	while (m_AllVocaList.GetNextVoca(item) != -1) {		//m_AllVocaList의 모든 요소를 m_AllSimpleList에 복사하는 과정

		simpleItem.SetPtr(m_AllVocaList.GetCurPtr());	//  m_AllVocaList.GetCurPtr()로 단어리스트 속 각 요소의 포인터를 뽑아온다.
														// ( while문의 GetNextVoca()는 리스트 내의 모든 요소에 접근하기 위한 반복역할)

		m_AllSimpleList.InsertVoca(simpleItem);			// m_AllVocaList의 각요소의 포인터를 갖고있는 
														//simpleItem을 m_AllSimpleList에 넣는다.
	}

}

//내 단어장 리스트의 모든 영어단어를 화면에 출력한다.
void Application::DisplayMyVoca() {
	if (m_MyVocaList.GetLength() == 0) {
		cout << "\n\t단어장이 비어있습니다.\n";
	}
	else {
		cout << "\n\t현재 내 단어장 리스트(" << m_MyVocaList.GetLength() << ")개" << endl;

		m_MyVocaList.ResetList();
		SimpleVocaType simpleTempVoca;

		while (m_MyVocaList.GetNext(simpleTempVoca) != nullptr)
		{
			simpleTempVoca.GetPtr()->DisplayVoca();
		}
	}
}