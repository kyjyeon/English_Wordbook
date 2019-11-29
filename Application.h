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
	SortedArrayList<VocaType> m_AllVocaList;			//���� �ܾ� �˻�
	SortedLinkedListType<SimpleVocaType> m_MyVocaList;	//�� �ܾ��� ����Ʈ
	SortedArrayList<SimpleVocaType> m_AllSimpleList;	//��ü ���� �ܾ� ����Ʈ
	StackType<SimpleVocaType> m_TestVocaList;			//����ܾ� �׽�Ʈ�� �ܾ��Ʈ
	Queue<SimpleVocaType> m_LearnVocaList;				//�н��� �ܾ��Ʈ
	int m_LearnLevel;									//�н�����
	int m_command;										//����� ���
	ifstream m_InFile;									//�Է¿� ���� descriptor
	ofstream m_OutFile;									//��¿� ���� descriptor

public:
	/**
	*	�⺻ ������.
	*/
	Application() {
		m_command = -1;
		m_LearnLevel = 0;
	}
	/**
	*	@brief
	*	@pre	����
	*	@post   ���� ����� ����ȴ�.
	*/
	void Run();

	/**
	*	@brief	�� �ܾ��� ���� driver
	*	@pre	����
	*	@post	�� �ܾ��� ��������� ����ȴ�.
	*/
	void RunManageMyVocaList();
	/**
	*	@brief	ȭ�鿡 5���� ����� ��ɾ� ����� ����ϰ� Ű����� ���õ� ����� �Է¹޴´�.
	*	@pre	����
	*	@post	����
	*	@return	command
	*/
	int GetCommand();
	/**
	*	@brief	ȭ�鿡 ����ܾ� �н������� ����ϰ� Ű����� ���õ� �н������� �Է¹޴´�.
	*	@pre	none.
	*	@post	none.
	*	@return	m_command
	*/
	int GetCommandLearnLevel();
	/**
	*	@brief	ȭ�鿡 �� �ܾ��� ���� ��ɾ� ����� ����ϰ� Ű����� ���õ� ����� �Է¹޴´�.
	*	@pre	����
	*	@post	����
	*	@return	m_command
	*/
	int GetCommandMyVocaList();
	/**
	*	@brief	����ܾ� �˻���� driver
	*	@pre	����
	*	@post	����ܾ� �˻������ ����
	*/
	void SearchVoca();
	/**
	*	@brief	����ܾ� �׽�Ʈ��� driver
	*	@pre	����
	*	@post	����ܾ� �׽�Ʈ����� ����
	*/
	void TestVoca();
	/**
	*	@brief	����ܾ� �н���� driver
	*	@pre	����
	*	@post	����ܾ� �н������ ����
	*/
	void LearnVoca();
	/**
	*	@brief	�� �ܾ��� ����Ʈ�� ����ܾ �߰��Ѵ�.
	*	@pre	�� �ܾ��� ����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�� �ܾ��� ����Ʈ�� ����ܾ �߰��ȴ�.
	*	@return	�߰��� �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	void AddMyVoca();

	/**
	*	@brief	����ܾ� �н��� �����Ѵ�.
	*	@pre	m_LearnList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	����ܾ� �н��� ���۵ȴ�.
	*/
	void LearnLevel(int c);

	/**
	*	@brief	����ܾ� 200���� ���� �н��� �ݺ��Ѵ�.
	*	@pre	m_LearnVocaList�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	����ܾ� 200���� ���� �н��� �ݺ��ȴ�.
	*	@return	�ݺ� ������ 1, �ƴϸ� 0�� ��ȯ
	*/
	int ExecuteLearn();

	/**
	*	@brief	������� �н������� ��ȯ�Ѵ�.
	*	@pre	������� �н������� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	m_LearnLevel;
	*/
	int GetLearnLevel();

	/**
	*	@brief	�� �ܾ��� ����Ʈ���� Ư�� ����ܾ �����Ѵ�.
	*	@pre	�� �ܾ��� ����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�� �ܾ��� ����Ʈ���� Ư�� ����ܾ �����ȴ�.
	*	@return ������ �����ϸ� 1, �׷��� ������ 0�� ��ȯ
	*/
	void DeleteMyVoca();

	/**
	*	@brief	�ؽ�Ʈ ���Ϸκ��� �ܾ�� ���� �ҷ��´�.
	*	@pre	����
	*	@post	m_AllVocaList�� VocaType item�� ����ȴ�.
	*/
	void InitWordBook();

	/**
	*	@brief	�� �ܾ��� ����Ʈ�� ��� ����ܾ ȭ�鿡 ����Ѵ�.
	*	@pre	����
	*	@post	����
	*/
	void DisplayMyVoca();

};

void Application::Run() {
	while (1) {
		m_command = GetCommand();
		switch (m_command) {
		case 1: // ����ܾ� �˻�
			SearchVoca();
			break;
		case 2: // �ܾ��׽�Ʈ
			TestVoca();
			break;
		case 3: // �н��ϱ�
			LearnVoca();
			break;
		case 4: // ������ �ܾ���
			RunManageMyVocaList();
			break;
		case 0:
			cout << "�����մϴ�.." << endl;
			return;
		default:
			cout << "Caution" << endl;
			break;
		}
	}
}


//�� �ܾ��� ���� driver
void Application::RunManageMyVocaList() {
	while (1)
	{
		m_command = GetCommandMyVocaList();

		switch (m_command)
		{
		case 1:		// �� �ܾ��� ����Ʈ�� ����ܾ �߰��Ѵ�.
			AddMyVoca();
			break;
		case 2:		// �� �ܾ��� ����Ʈ���� Ư�� ����ܾ �����Ѵ�.
			DeleteMyVoca();
			break;
		case 3:		// �� �ܾ����� ��� ����ܾ ȭ�鿡 ����Ѵ�.
			DisplayMyVoca();
			break;
		case 4:		// �� �ܾ��忡 �ִ� ��� ����ܾ �� �ܾ��� ����Ʈ���� �����Ѵ�.
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
	cout << "\t    1. ����ܾ� �˻�" << endl;
	cout << "\t    2. �ܾ��׽�Ʈ" << endl;
	cout << "\t    3. �н��ϱ�" << endl;
	cout << "\t    4. ������ �ܾ���" << endl;
	cout << "\t    0. ������" << endl << endl;
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
	cout << "\t   0 : ������" << endl;

	cout << endl << "\t Choose a Level--> ";
	cin >> command;
	cout << endl;

	return command;
}

//ȭ�鿡 �� �ܾ��� ���� ��ɾ� ����� ����ϰ� Ű����� ���õ� ����� �Է¹޴´�.
int Application::GetCommandMyVocaList() {
	int command;
	cout << endl << endl;
	cout << "\t -------�� �ܾ��� ����------- " << endl;
	cout << "\t   1 : �ܾ� �߰�" << endl;
	cout << "\t   2 : �ܾ� ����" << endl;
	cout << "\t   3 : �ܾ� ��ȸ" << endl;
	cout << "\t   4 : ��ü ����" << endl;
	cout << "\t   0 : ������" << endl;

	cout << endl << "\t Choose a Command Number--> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::SearchVoca() {
	VocaType Item;
	Item.SetEnglishFromKB();
	m_AllVocaList.ResetList();

	//���� �ܾ� ���α׷��� ã�� ����ܾ ������������ ���
	if (!m_AllVocaList.Get(Item)) {
		cout << "\n\t�˻��� ����ܾ�� ���α׷� ���� �������� �ʽ��ϴ�." << endl;
	}
	//���� �ܾ� ���α׷��� ã�� ����ܾ ������ ���
	else {
		Item.DisplayKorean();
	}
}

void Application::TestVoca() {
	//  ���α׷��� �ܾ ���Ƿ� �����Ͽ� ������� �ܾ�ϱ� ������ �׽�Ʈ�ϴ� �Լ�
	SimpleVocaType simpleTempVoca;
	m_AllSimpleList.ResetList();
	srand(time(NULL));
	int randArr[50];
	for (int i = 0; i < 50; i++) {									//0~999�� �������� 50���� �������� �����ؼ� 
																	//�迭 randArr[]�� �ִ´�.
		randArr[i] = rand() % 1000; //0~999�� ����
		for (int j = 0; j < i; j++) {
			if (randArr[j] == randArr[i]) {
				i--;
				break;
			}
		}
	}
	//�迭 randArr[]�� ���� ���ڵ鿡 �����ϴ� �迭�� �����͵���
	//�ܾ� �׽�Ʈ�� ���ÿ� �ִ´�.
	for (int i = 0; i < 50; i++) {
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(randArr[i]);
		m_TestVocaList.push(simpleTempVoca);
	}

	int count = 1, correct = 0, incorrect = 0;
	string English;
	if (m_TestVocaList.isEmpty())
		Run();
	else {
		cout.precision(3); //���� �ڸ����� 3�������� ��µǰ� ����
		while (1) {
			if (m_TestVocaList.getLength() == 0)
				break;
			cout << "\t�ܾ��׽�Ʈ ( " << count << "/ 50 ) => ���� : " << correct << " ���� : " << incorrect << endl;

			m_TestVocaList.pop(simpleTempVoca);
			simpleTempVoca.GetPtr()->DisplayCorrectPercent();
			simpleTempVoca.GetPtr()->DisplayKorean();
			cout << "\n\t0. ������ " << endl;
			cout << "\n\t->"; cin >> English; cout << endl;
			if (English == "0") {
				cout << endl << "\t<<���>> ���� : " << correct << " ���� : " << incorrect << " ���� : " << correct * 2 << "�� " << endl;
				m_TestVocaList.MakeEmpty();
				return;
			}
			else if (simpleTempVoca.GetPtr()->GetEnglish().compare(English) != 0) {
				incorrect++;
				count++;
				English = simpleTempVoca.GetPtr()->GetEnglish();
				cout << "\t����!! (" << English << ")" << endl << endl;
				simpleTempVoca.GetPtr()->PlusWrong();
			}
			else {
				correct++;
				count++;
				simpleTempVoca.GetPtr()->PlusCorrect();
				cout << "\t����!!" << endl << endl;
			}
		}
		ios_base::fmtflags f(cout.flags()); //precision ��¼��� �ʱ�ȭ
		cout << endl << "\t<<���>> ���� : " << correct << " ���� : " << incorrect << " ���� : " << correct * 2 << "�� " << endl;
	}
}

//����ܾ� �н���� driver
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
		cout << "\n\tLevel" << m_LearnLevel + 1 << "���� �н����ּ���.\n";
		return;
	}
	SimpleVocaType simpleTempVoca;
	m_LearnVocaList.MakeEmpty();
	m_AllSimpleList.ResetList();
	srand(time(NULL));
	int randArr[200];
	for (int i = 0; i < 200; i++) {
		randArr[i] = rand() % 200 + (((c - 1) * 200));	//c�� ���õ� �����̴�. c�� 1�̸� 0~199 index�� ��ġ�� ������
		for (int j = 0; j < i; j++) {					//					   c�� 2�� 200~399 index�� ��ġ�� ������
			if (randArr[j] == randArr[i]) {
				i--;
				break;
			}
		}
	}
	// m_LearnVocaList�� m_id 1~200�� �ش��ϴ� VocaType�� enQueue�Ѵ�.
	for (int i = 0; i < 200; i++) {
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(randArr[i]);	//0~199�� �ε����� ��ġ�� �����Ͱ� �������� 
		m_LearnVocaList.enQueue(simpleTempVoca);						//�н��� ť�� ä������.
	}

	//������ ������ ����ܾ� 200���� ���� �н��� �ݺ��Ѵ�.
	ExecuteLearn();														//������ ä���� �н��� ť�� ���� �ݺ��н��� ���۵ȴ�.
}

//����ܾ� 200���� ���� �н��� �ݺ��Ѵ�.
int Application::ExecuteLearn() {
	string tempString;
	SimpleVocaType simpleTempVoca;

	// m_LearnVocaList�� VocaType�� ���� �������� ������ �ݺ��н� ����
	while (m_LearnVocaList.GetLength() != 0)
	{
		m_LearnVocaList.deQueue(simpleTempVoca);
		simpleTempVoca.GetPtr()->DisplayKorean();
		cout << "\t�ش��ϴ� �ܾ��Է�(�߰�����: Y): ";
		cin >> tempString;
		if (simpleTempVoca.GetPtr()->GetEnglish().compare(tempString) != 0)	//������ ���
		{
			if (tempString == "Y")	//������ ���� ���
			{
				cout << "\n\tLevel" << m_LearnLevel + 1 << "�� �����մϴ�.\n";
				m_LearnVocaList.MakeEmpty();
				return 0;
			}
			m_LearnVocaList.enQueue(simpleTempVoca);
			tempString = simpleTempVoca.GetPtr()->GetEnglish();
			cout << "\t����(" << tempString << "), ���� �н��ܾ�: " << m_LearnVocaList.GetLength() << "��" << endl;
		}
		else
		{													//������ ���
			cout << "\t����, ���� �н��ܾ�: " << m_LearnVocaList.GetLength() << "��" << endl;
		}
	}
	cout << "\n\tLevel" << m_LearnLevel + 1 << "�ܰ踦 �н� �Ϸ��߽��ϴ�.\n";
	if (m_LearnLevel < 4)
		m_LearnLevel++;
	return 1;
}
int Application::GetLearnLevel() {
	return m_LearnLevel;
}

//�� �ܾ��� ����Ʈ�� ����ܾ �߰��Ѵ�.
void Application::AddMyVoca() {
	VocaType tempVoca;
	SimpleVocaType simpleTempVoca;

	cout << "\n\t�� �ܾ��� ����Ʈ�� �߰��Ϸ��� ����ܾ� �˻�: ";
	tempVoca.SetEnglishFromKB();
	if (m_AllVocaList.Get(tempVoca)) {		//����ܾ� ���α׷��� �˻��� ����ܾ �����ϴ��� �˻�
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(tempVoca.GetId() - 1);
		if (!m_MyVocaList.Get(simpleTempVoca)) {	//�� �ܾ��� ����Ʈ�� �߰��Ϸ��� ����ܾ �����ϴ��� �˻�
			m_MyVocaList.Insert(simpleTempVoca);
			cout << "\n\t�� �ܾ��� ����Ʈ ������Ʈ �Ϸ�\n";
		}
		else {								//�� �ܾ��� ����Ʈ�� �̹� �����ϴ� ����ܾ��� ���
			cout << "\n\t�ش� �ܾ�� �� �ܾ��� ����Ʈ �̹� ����\n";
		}
	}
	else {									//����ܾ� ���α׷��� �������� �ʴ� ����ܾ��� ���
		cout << "\n\t�ش� �ܾ�� ����ܾ� ���α׷��� �������� �ʽ��ϴ�.\n";
	}
}

//�� �ܾ��� ����Ʈ���� Ư�� ����ܾ �����Ѵ�.
void Application::DeleteMyVoca() {
	VocaType tempVoca;
	SimpleVocaType simpleTempVoca;

	cout << "\n\t�� �ܾ��� ����Ʈ���� �����Ϸ��� ����ܾ� �Է�: ";
	tempVoca.SetEnglishFromKB();
	if (m_AllVocaList.Get(tempVoca)) {				//���α׷��� �����Ϸ��� ����ܾ �����ϴ��� �˻�
		simpleTempVoca = m_AllSimpleList.GetIndexOfData(tempVoca.GetId() - 1);
		if (m_MyVocaList.Get(simpleTempVoca)) {		//�� �ܾ��� ����Ʈ�� �����Ϸ��� ����ܾ �����ϴ� �˻�
			m_MyVocaList.Delete(simpleTempVoca);
			cout << "\n\t�� �ܾ��� ����Ʈ ������Ʈ �Ϸ�\n";
		}
		else {										//�� �ܾ��� ����Ʈ�� �����Ϸ��� ����ܾ �������� �ʴ� ���
			cout << "\n\t�ش� �ܾ�� �� �ܾ��� ����Ʈ�� �������� ����\n";
		}
	}
	else {											//���α׷��� �����Ϸ��� ����ܾ �������� �ʴ� ���
		cout << "\n\t�ش� �ܾ�� ���α׷��� �������� ����\n";
	}
}


void Application::InitWordBook() {
	m_InFile.open("WordFile.txt");
	VocaType item;							//Item ������ ���ܾ� ������ ���� VocaType ��ü
	SimpleVocaType simpleItem;				//�о�� �����Ͱ� ��� item ��ü�� SimpleVocaType ��ü���ڷ� �Ѱ���
	m_AllVocaList.ResetList();

	//���Ϸκ��� voca������ �ҷ��ͼ� m_AllVocaList�� �����Ѵ�.
	while (!m_InFile.eof()) {
		item.ReadDataFromFile(m_InFile);
		m_AllVocaList.InsertVoca(item);//���� ������ ��ġ�� �о�� �����Ͱ� ��� item ��ü�� ���� ����
	}
	m_InFile.close();

	//m_AllSimpleList�� 1000���� Voca ��ü ������ �����Ѵ�.
	m_AllVocaList.ResetList();
	while (m_AllVocaList.GetNextVoca(item) != -1) {		//m_AllVocaList�� ��� ��Ҹ� m_AllSimpleList�� �����ϴ� ����

		simpleItem.SetPtr(m_AllVocaList.GetCurPtr());	//  m_AllVocaList.GetCurPtr()�� �ܾ��Ʈ �� �� ����� �����͸� �̾ƿ´�.
														// ( while���� GetNextVoca()�� ����Ʈ ���� ��� ��ҿ� �����ϱ� ���� �ݺ�����)

		m_AllSimpleList.InsertVoca(simpleItem);			// m_AllVocaList�� ������� �����͸� �����ִ� 
														//simpleItem�� m_AllSimpleList�� �ִ´�.
	}

}

//�� �ܾ��� ����Ʈ�� ��� ����ܾ ȭ�鿡 ����Ѵ�.
void Application::DisplayMyVoca() {
	if (m_MyVocaList.GetLength() == 0) {
		cout << "\n\t�ܾ����� ����ֽ��ϴ�.\n";
	}
	else {
		cout << "\n\t���� �� �ܾ��� ����Ʈ(" << m_MyVocaList.GetLength() << ")��" << endl;

		m_MyVocaList.ResetList();
		SimpleVocaType simpleTempVoca;

		while (m_MyVocaList.GetNext(simpleTempVoca) != nullptr)
		{
			simpleTempVoca.GetPtr()->DisplayVoca();
		}
	}
}