/*
Justin Lee
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class GradeList {
private:
	int level;
	float grade;
	int gradeTable[4][5] = {0};
	void setTable();
public:
	GradeList();
	void setGrade(int, float);
	void displayTable();
};
void GradeList::setTable()
{
	int row = level - 9;
	int column;
	if (grade >= 89.5) {
		column = 0;
	}
	else if (grade >= 79.5) {
		column = 1;
	}
	else if (grade >= 69.5) {
		column = 2;
	}
	else if (grade >= 64.9) {
		column = 3;
	}
	else if (grade < 64.9) {
		column = 4;
	}
	gradeTable[row][column]++;
}
GradeList::GradeList()
{
	gradeTable[4][5] = { 0 };
}
void GradeList::setGrade(int L, float G)
{
	level = L;
	if (L >= 13 || L <= 8) {
		level = 12;
	}
	grade = G;
	if (G > 100 || G < 0) {
		grade = 0;
	}
	setTable();
}
void GradeList::displayTable()
{
	cout << "           A   B   C   D   F" << endl;
	cout << "GRADE 9:" << setw(3) << gradeTable[0][0] << "|" <<
		setw(3) << gradeTable[0][1] << "|" << 
		setw(3) << gradeTable[0][2] << "|" << 
		setw(3) << gradeTable[0][3] << "|" << 
		setw(3) << gradeTable[0][4] << "|" << endl;
	cout << "GRADE 10:" << setw(3) << gradeTable[1][0] << "|" <<
		setw(3) << gradeTable[1][1] << "|" << setw(3) << gradeTable[1][2] <<
		"|" << setw(3) << gradeTable[1][3] << "|" << setw(3) << gradeTable[1]
		[4] << "|" << endl;
	cout << "GRADE 11:" << setw(3) << gradeTable[2][0] << "|" <<
		setw(3) << gradeTable[2][1] << "|" << setw(3) << gradeTable[2][2] <<
		"|" << setw(3) << gradeTable[2][3] << "|" << setw(3) << gradeTable[2]
		[4] << "|" << endl;
	cout << "GRADE 12:" << setw(3) << gradeTable[3][0] << "|" <<
		setw(3) << gradeTable[3][1] << "|" << setw(3) << gradeTable[3][2] <<
		"|" << setw(3) << gradeTable[3][3] << "|" << setw(3) << gradeTable[3]
		[4] << "|" << endl;
}
