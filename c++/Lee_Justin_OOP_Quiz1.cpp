/*
Program: ECET11 MP1 OOP Quiz 1
Student Name: Justin Lee
Date:  09/10/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
	int month;
	int day;
	int year; 
	bool isLeapYear(); 
	bool leapYear;
public: 
	void setDate(int m, int d, int yr);
	void showDate();
	void showYearStatus(); 
};

void Date::setDate(int m, int d, int yr) {
	leapYear = false; 
	if (2000 <= yr && yr <= 9999) {
		year = yr;
	}
	else {
		year = 2000; 
	}
	if (year % 4 == 0) {
		leapYear = true;
		if (year % 100 == 0) {
			leapYear = false;
			if (year % 400 == 0)
				leapYear = true;
		}
	}
	if (0 < m && m < 13)
		month = m;
	else
		month = 1;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (1 < d && d < 32)
			day = d;
		else
			day = 1;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (0 < d && d < 31)
			day = d;
		else
			day = 1;
	}
	if (leapYear == true && month == 2) {
		day = 1;
		if (0 < d && d < 30) {
			day = d;
		}
	}
	if (leapYear == false && month == 2) {
		if (0 < d && d < 29)
			day = d;
		else
			day = 1; 
	}
}

void Date::showDate() {
	cout << setfill('0') << setw(2) << month << "/";
	cout << setfill('0') << setw(2) << day << "/";
	cout << setfill('0') << setw(2) << year % 100;
}

void Date::showYearStatus() {
	if (leapYear == true)
		cout << "leap year";
	if (leapYear == false)
		cout << "not a leap year"; 
}

bool Date::isLeapYear() {
	leapYear = false; 
	if (year % 4 == 0) {
		leapYear = true;
	}
	if (year % 100 == 0) {
		leapYear = false;
		if (year % 400 == 0) {
			leapYear = true; 
		}
	}
	return leapYear; 
}
