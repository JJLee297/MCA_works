/*
Program: ECET11 MP1 OOP Line Quiz
Student Name: Justin Lee
Date:  10/29/2020
*/

#include <iostream> 
#include <cmath>
#include <algorithm> 
#include <vector>
using namespace std;

class LineType {
private:
	int xCoeff;
	int yCoeff;
	int constTerm;
	double slope; 
	bool isEpic; 
public:
	void setLine(int a, int b, int c);
	bool operator/(const LineType& line) {
		if (this->slope == line.slope && this->isEpic == false && line.isEpic == false) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator|(const LineType& line) {
		if (this->isEpic == false && line.isEpic == false) {
			if (this->slope * line.slope == -1) {
				return true;
			}
		}
		return false; 
	}
	void pointOfIntersection(const LineType& line) {
		double det = this->xCoeff*line.yCoeff - line.xCoeff*this->yCoeff;
		double xx = (line.yCoeff * this->constTerm - this->yCoeff * line.constTerm) / det;
		double yy = (this->xCoeff * line.constTerm - line.xCoeff * this->constTerm) / det;
		int xxx = xx * 1000;
		float newX = 0;
		float newY = 0;
		double what = 100;
		if (xxx % 10 >= 5) {
			newX = (double) ((int)(xx * 100 + 0.5)) / what;
		}
		else {
			newX = (double) ((int)(xx * 100)) / what;
		}
		int yyy = yy * 1000;
		if (yyy % 10 >= 5) {
			newY = (double) ((int)(yy * 100 + 0.5)) / what;
		}
		else {
			newY = (double) ((int)(yy * 100)) / what;
		}
		if (newX * 10 == (int)(newX * 10) && newX - (int)newX != 0)
			cout << "(" << newX << "0, ";
		else 
			cout << "(" << newX << ", ";
		if (newY * 10 == (int)(newY * 10) && newY - (int)newY != 0)
			cout << newY << "0)" << endl;
		else
			cout << newY << ")" << endl;
		
		//cout << newY * 10 << " " << (int)(newY * 10) << " " << newY << " " << (int)newY << endl;
	}
	void displayOutput(const LineType& line) {
		if (this->xCoeff != 1) {
			cout << this->xCoeff << "x ";
		}
		else {
			cout << "x ";
		}
		if (this->yCoeff > 0 && this->yCoeff != 1) {
			cout << "+ " << this->yCoeff << "y = " << this->constTerm;
		}
		if (this->yCoeff == 1) {
			cout << "+ " << "y = " << this->constTerm;
		}
		if (this->yCoeff < 0 && this->yCoeff != -1) {
			cout << "- " << abs(this->yCoeff) << "y = " << this->constTerm;
		}
		if (this->yCoeff == -1) {
			cout << "- " << "y = " << this->constTerm;
		}
		cout << ", ";
		if (line.xCoeff != 1) {
			cout << line.xCoeff << "x ";
		}
		else {
			cout << "x ";
		}
		if (line.yCoeff > 0 && line.yCoeff != 1) {
			cout << "+ " << line.yCoeff << "y = " << line.constTerm;
		}
		if (line.yCoeff == 1) {
			cout << "+ " << "y = " << line.constTerm;
		}
		if (line.yCoeff < 0 && line.yCoeff != -1) {
			cout << "- " << abs(line.yCoeff) << "y = " << line.constTerm;
		}
		if (line.yCoeff == -1) {
			cout << "- " << "y = " << line.constTerm;
		}
		cout << ", ";
	}
};

void LineType::setLine(int a, int b, int c) {
	xCoeff = a;
	yCoeff = b;
	constTerm = c;
	isEpic = false;
	if (b != 0) {
		slope = (double)-a / (double)b;
	}
	if (b == 0) {
		slope = 99;
		isEpic = true;
	}
}
