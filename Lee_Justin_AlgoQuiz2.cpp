/*
Program: ECET11 MP1 Algorithm Quiz 2
Student Name: Justin Lee
Date:  10/26/2020
*/

#include <iostream> 
#include <cmath>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
	int j;
	cin >> j;
	for (int i = 0; i < j; ++i) {
		int N, testN, outputN;
		cin >> N;
		testN = N;
		outputN = N;
		for (int k = 0; k < 50; k++) {
			int reverseN = 0;
			int dg = 0;
			do
			{
				dg = testN % 10;
				reverseN = (reverseN * 10) + dg;
				testN = testN / 10;
			} while (testN != 0);
			if (reverseN != N) {
				N += reverseN;
				testN = N;
			}
			if (reverseN == N) {
				cout << outputN << " " << reverseN << endl; 
				break;
			}
			if (k == 49) {
				cout << "TOO MANY INTERATIONS" << endl;
				break;
			}
		}
	}
	//system("pause");
}