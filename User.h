#pragma once
#include "VocaType.h"
#include "SimpleVocaType.h"
#include "SortedLinkedListType.h"
#include "QueueType.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//Enumeration for distinguishing USER or ADMIN
enum permission
{
	USER = 1,	//Set USER account as 1
	ADMIN = 2	//Set ADMIN account as 2
};


class UserType {
public:
	UserType();			//Default constructor
	~UserType() {}		//Default destructor

	bool operator<(const UserType& person);			//Comparing between current and parameter class member id. Return 1 if current class id is smaller, 0 if bigger 
	bool operator>(const UserType& person);			//Comparing between current and parameter class member id. Return 1 if current class id is larger, 0 if smaller
	bool operator==(const UserType& person);		//Comparing between current and parameter class member id. Return 1 if current class id is same, 0 if not same 
	
	void SetId(string id);							//Set the class member id from parameter string
	void SetPassword(string pw);					//Set the class password id from parameter string
	void SetName(string name);						//Set the class name id from parameter string
	void SetRecord(string id, string pw, string name, int status);		//Set all the class member from parameter
	void SetDate();									//Set the class data id from parameter string
	void SetStatus(int status);						//Set the class status id from parameter string
	void SetTestScore(int testScore);				//Set the class test score id from parameter string
	void SetLearnLevel(int learnLevel);				//Set the class current Learn Level id from parameter string

	string GetId();									//Return class member ID
	string GetPassword();							//Return class member Password
	string GetName();								//Return class member Name
	int GetLearnLevel();							//Return class member Learn Level
	int GetTestScore();								//Return class member Test Score
	int GetStatus();								//Return class member Status

	void SetIdFromKB();								//Set the class ID id by keyboard
	void SetPwFromKB();								//Set the class Password id by keyboard
	void SetNameFromKB();							//Set the class Name id by keyboard
	void SetRecordFromKB();							//Set the class Record id by keyboard
	SortedLinkedListType<SimpleVocaType>* GetList();	//Set the class ID id by keyboard
	Queue<SimpleVocaType>* GetQueue();				//Get User's most recent search list as a Queue
	const string currentDateTime();					//Get current date and time as "YyyymmddhhMMSS" form

	void DisplayId();								//Display the class ID
	void DisplayName();								//Display the class Name
	void DisplayPassword();							//Display the class Password
	void DisplayTestScore();						//Display the class Test socre
	void DisplayLearnLevel();						//Display the class Learn level
	void DisplayLogTime();							//Display the class Log time
	void DisplayStatus();							//Display the class current status
	void DisplayAll();								//Display the class all member variables

	int AddVoca(SimpleVocaType& simpleVoca);		//Add a vocabulary to User vocabulary list. Return 1 if added, 0 if failed
	int DeleteVoca(SimpleVocaType& simplevoca);		//Delete a vocabulary. Return 1 if deleted 0 if failed
	void DisplayVoca();								//Display all User vocabulary in order
	void DisplayVocaReverse();						//Display all User vocabulary in reverse order
	void DeleteAllVoca();							//Delete all currently existing User Vocabulary

private:
	string m_id;									//User Id
	string m_name;									//User name
	string m_password;								//User password
	string m_recentLoginTime;						//User Most recent login time
	int m_testScore;								//Word test score
	int m_learnLevel;								//User current Learn Level
	SortedLinkedListType<SimpleVocaType> m_MyVocaList;			//Sorted Linked list using vocabulary list member containing VocaType pointer SimpleVocaType class
	Queue<SimpleVocaType> m_recentSearchList;					//Queue using vocabulary list member containing VocaType pointer SimpleVocaType class
	int m_status;									// User Permission integer( 1 or 2 ) for checking User or Admin
};
