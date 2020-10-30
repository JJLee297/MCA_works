/*
Justin Lee
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int counter1 = 0;
		bool count1 = true;
		bool count0 = true; 
		int counter0 = 0;
		int input;
		for (int j = 0; j < 32; j++) {
			cin >> input;
			if (input == 1) {
				if (count1 == true)
					counter1++;
				else {
					if (counter1 != 0)
						cout << counter1 << ":1 ";
					counter1 = 1;
				}
				count1 = true;
				count0 = false;
			}
			if (input == 0) {
				if (count0 == true)
					counter0++;
				else {
					if (counter0 != 0)
						cout << counter0 << ":0 ";
					counter0 = 1;
				}
				count1 = false;
				count0 = true; 
			}
		}
	}
	system("pause"); 
}