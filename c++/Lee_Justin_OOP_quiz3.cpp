/*
Program: ECET11 MP1 OOP Quiz 3
Student Name: Justin Lee
Date:  09/25/2020
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Password {
private:
	bool ch; 
	string password;
	int strength;
	int sumDigits = 0;
	int digits = 0;
	bool passwordLength();
	bool passwordCase();
	bool passwordDigit();
public: 
	void setPassword(string pwd);
	bool checkPassword();
	int getStrength(); 
};

void Password::setPassword(string pwd) {
	password = pwd; 
}

bool Password::passwordLength() {
	if (password.length() >= 6) {
		return true;
	}
	else
		return false; 
}

bool Password::passwordCase() {
	for (int i = 0; i < password.length(); ++i) {
		if (isupper(password[i])) {
			return true; 
		}
	}
	return false; 
}

bool Password::passwordDigit() {
	sumDigits = 0;
	ch = true;
	digits = 0;
	for (int i = 0; i < password.length(); ++i) {
		if (password[i] == '1' || password[i] == '2' || password[i] == '3' || password[i] == '4' || password[i] == '5' || password[i] == '6'
			|| password[i] == '7' || password[i] == '8' || password[i] == '9' || password[i] == '0') {
			if (i == 0) {
				ch = false;
			}
			sumDigits += password[i] - '0';
			digits++; 
		}
	}
	if (ch == true && digits == 0)
		return false; 
	if (ch == true) {
		return true;
	}
	return false;
}

bool Password::checkPassword() {
	if (passwordCase() == true && passwordDigit() == true && passwordLength() == true) {
		strength = 10 * (password.length() + sumDigits * digits);
		return true;
	}
	strength = 10 * (password.length() + sumDigits * digits);
	return false;
}

int Password::getStrength() {
	return strength;
}
