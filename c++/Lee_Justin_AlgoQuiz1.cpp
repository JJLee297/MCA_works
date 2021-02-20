/*
Program: ECET11 MP1 Algorithm Quiz 1
Student Name: Justin Lee
Date:  10/22/2020
*/

#include <iostream> 
#include <cmath>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
	int N; 
	int maxH[1000] = { 0 };
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int l, r, h;
		cin >> l >> r >> h;
		for (int k = l; k < r; ++k) {
			if (h > maxH[k]) {
				maxH[k] = h; 
			}
		}
	}
	for (int i = 0; i < 999; ++i) {
		if (maxH[i + 1] != maxH[i]) {
			cout << i + 1 << " " << maxH[1 + i] << "\n";
		}
	}
}
