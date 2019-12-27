#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class VocaType {
public:
	VocaType();												//Default constructor setting member variables
	int GetId();											//return member id
	string GetEnglish();									//return English word
	string GetKorean();										//return Korean meaning of English
	double GetCorrect();									//return number of correct test answers the user made 
	double GetWrong();										//return number of wrong test answers the user made
	double GetCorrectPercent();								//return user's test answer correctness percentage by calculating correct and wrong answers 
	void PlusCorrect();										//Increase m_correct member variable
	void PlusWrong();										//Increase m_wrong member variable
	void SetId(int id);										//Set id
	void SetEnglish(string english);						//Set English.
	void SetKorean(string korean);							//Set Korean.
	void SetVoca(int id, string english, string korean);	//Set id, english, korean
	void SetIdFromKB();										//Set id from keyboard.
	void SetEnglishFromKB();								//Set English from.
	void SetKoreanFromKB();									//Set Korean meaning input from keyboard
	void SetVocaFromKB();									//Set id, spelling, Korean meaning
	void DisplayId();										//Display member id.
	void DisplayEnglish();									//Display member English.
	void DisplayKorean();									//Display member Korean.
	void DisplayVoca();										//Display member id, English, Korean.
	void DisplayCorrectPercent();							//Display test score correct percentage
	bool operator<(const VocaType& voca);					//Compare between current class Vocatype pointer value id and parameter VocaType pointer value. If smaller return true, if larger return false
	bool operator>(const VocaType& voca);					//Compare between current class Vocatype pointer value id and parameter VocaType pointer value. If larger return true, if smaller return false
	bool operator==(const VocaType& voca);					//Compare between current class Vocatype pointer value id and parameter VocaType pointer value. If same return true, if different return false
	int ReadDataFromFile(ifstream& fin);					//Copy VocaType data from input file descriptor.Copying from id, english, korean member order
	int WriteDataToFile(ofstream& fout);					//Write VocaType data to output file descriptor 

private:
	int m_id;												//English word id
	string m_english;										//Spelling of English word, key value for myVocaList and also for searching
	string m_korean;										//English word Korean meaning
	double m_correct;										//number of correct test answers the user made
	double m_wrong;											//number of wrong test answers the user made
};