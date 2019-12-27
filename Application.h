#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "QueueType.h"
#include "StackType.h"
#include "VocaType.h"
#include "SimpleVocaType.h"
#include "SortedArrayListType.h"
#include "SortedLinkedListType.h"
#include "User.h"
#include "SimpleUserType.h"
#include "SimpleUserType2.h"
#include "MaxHeap.h"
#include "UnsortedLinkedListType.h"
#define FILENAMESIZE 1024

using namespace std;

class Application {
public:
	Application();					//Default constructor
	void Run();						//Run the main program
	void LogIn();					//Do login before starting the program
	int GetCommand();				//Get user input from the main program
	int GetCommandLogIn();			//Get user input learn vocabulary program
	int GetCommandManageUser();		// Get user info from User Manage program
	/**
	*	@brief      유저의 로그인 정보를 입력받고 정보가 적합한지 검사하고 권한을 분류한다.
	*	@pre	        유저리스트가 초기화되어있어야한다.
	*	@post       m_curUser가 로그인한 유저를 가리키게 된다.
	*	@return     로그인에 실패하면 0, 일반 유저 로그인에 성공하면 1, 관리자 로그인에 성공하면 2를 반환한다.
	*/
	int VerifyLogIn();				//Verify the user login
	void LogOut();					//User Logs out from the program
	void CreateUser();				//Add user
	void DeleteUser();				//Delete user
	void CheckAllUser();			//Display all current user info
	void EditUser();				//Edit user info
	void ShowRanker();				//Display Rankings of users by test score
	void CheckMyInfo();				//Display the current user info
	void EditMyInfo();				//Edit the current user info
	void SearchVoca();			    //Search for vocabulary
	void TestVoca();				//Take a English Vocabulary test
	void LearnVoca();				//Execute Learn Vocabulary program
	int GetCommandLearnLevel();	    //Get user input from learn vocabulary program
	void SetLearnList(int level);	//Learn Vocabulary program gets filled by the parameter level
	int ExecuteLearn();			    //Execute Learning program 
	void ManageMyVocaList();		//Manage my vocabulary list
	int GetCommandMyVocaList();	    //Get user input from My vocabulary list
	void AddMyVoca();				//Add a vocabualry from my vocabulary list
	void DeleteMyVoca();			//Delete a vocabulary from my vocabulary list
	void InitWordBook();			//Initialize the Wordbook from txt file
private:
	int m_command;										//user command
	SortedArrayList<VocaType> m_AllVocaList;			//All 1000 vocabulary list
	SortedArrayList<SimpleVocaType> m_AllSimpleList;	//Simple vocabulary list using pointer
	StackType<SimpleVocaType> m_TestVocaList;			//Simple vocabulary list for test
	Queue<SimpleVocaType> m_LearnVocaList;				//Simple vocabulary list for learning
	ifstream m_InFile;									//Input file descriptor
	ofstream m_OutFile;									//Output file descriptor
	UnsortedLinkedList<UserType> m_AllUserList;			//All User list
	SortedArrayList<SimpleUserType2> m_AllSimpleUList;	//All Simple version 
	UserType* m_curUser;								//Current logged in user
	//SortedArrayList<SimpleUserType> m_RankerList;     //Ranker list from total current user 
};
