/*
Program: ECET11 MP1 OOP Quiz 5
Student Name: Justin Lee
Date:  10/7/2020
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Anagram{
private:
	string wordS = "";
	string wordR = "";
	string temp = "";
	string realWordR = "";
	bool processWords();
public: 
	void setWordR(string str1);
	void setWordS(string str2);
	void check4Anagramity();
};

void Anagram::setWordR(string str1) {
	wordR = str1;
	realWordR = str1;
}

void Anagram::setWordS(string str2) {
	wordS = str2; 
}

bool Anagram::processWords() {
	if (wordS.length() != wordR.length()) {
		return false;
	}
	temp = wordS; 
	for (int i = 0; i < wordS.length(); ++i) {
		for (int j = 0; j < wordR.length(); ++j) {
			if (wordS[i] == wordR[j]) {
				temp = "";
				for (int k = 0; k < wordR.length(); ++k) {
					if (k != j)
						temp += wordR[k];
				}
				wordR = temp; 
				break;
			}
			if(j == temp.length() - 1) {
				return false; 
			}
		}
	}
	return true; 
}

void Anagram::check4Anagramity() {
	if (processWords() == 1)
		cout << wordS << " " << realWordR << " " << "true" << endl; 
	else 
		cout << wordS << " " << realWordR << " " << "false" << endl;
}
