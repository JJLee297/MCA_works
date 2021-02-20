/*
Program: ECET11 MP1 Algorithm Quiz 3
Student Name: Justin Lee
Date:  10/28/2020
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
		int order;
		cin >> order;
		int firstterm = 0;
		int coearr[32] = { 0 };
		for (int k = 0; k < order; ++k) {
			int coe;
			cin >> coe; 
			coearr[k] = coe; 
		}
		for (int k = 0; k < order; ++k) {
			if (coearr[k] != 0) {
				firstterm = k;
				break;
			}
		}
		int order2 = order - 1 - firstterm;
		if (coearr[firstterm] != 1 && coearr[firstterm] > 0) {
			if (order2 != 1 && order2 != 0)
				cout << coearr[firstterm] << "x^" << order2;
			if (order2 == 1) 
				cout << coearr[firstterm] << "x";
			if (order2 == 0)
				cout << coearr[firstterm];
		}
		if (coearr[firstterm] == 1) {
			if (order2 != 1 && order2 != 0)
				cout << "x^" << order2;
			if (order2 == 1)
				cout << "x";
			if (order2 == 0)
				cout << coearr[firstterm];
		}
		if (coearr[firstterm] != -1 && coearr[firstterm] < 0) {
			if (order2 != 1 && order2 != 0)
				cout << coearr[firstterm] << "x^" << order2;
			if (order2 == 1)
				cout << coearr[firstterm] << "x";
			if (order2 == 0)
				cout << coearr[firstterm];
		}
		if (coearr[firstterm] == -1) {
			if (order2 != 1 && order2 != 0)
				cout << "-" << "x^" << order2;
			if (order2 == 1)
				cout << "-" << "x";
			if (order2 == 0)
				cout << coearr[firstterm];
		}
		for (int k = firstterm + 1; k < order; ++k) {
			if (coearr[k] == 0) {
				continue;
			}
			if (coearr[k] < 0 && coearr[k] != -1) {
				if (order - k - 1 != 1 && order - k - 1 != 0)
					cout << coearr[k] << "x^" << order - k - 1; 
				else if (order - k - 1 == 1) {
					cout << coearr[k] << "x";
				}
				else 
					cout << coearr[k];
			}
			if (coearr[k] == -1) {
				if (order - k - 1 != 1 && order - k - 1 != 0)
					cout << "-" << "x^" << order - k - 1;
				else if (order - k - 1 == 1) {
					cout << "-" << "x";
				}
				else
					cout << coearr[k];
			}
			if (coearr[k] > 0 && coearr[k] != 1) {
				if (order - k - 1 != 1 && order - k - 1 != 0)
					cout << "+" << coearr[k] << "x^" << order - k - 1;
				else if (order - k - 1 == 1) {
					cout << "+" << coearr[k] << "x";
				}
				else
					cout << "+" << coearr[k];
			}
			if (coearr[k] == 1) {
				if (order - k - 1 != 1 && order - k - 1 != 0)
					cout << "+" << "x^" << order - k - 1;
				else if (order - k - 1 == 1) {
					cout << "+" << "x";
				}
				else
					cout << "+" << coearr[k];
			}
		}
		cout << "\n";
	}
}
