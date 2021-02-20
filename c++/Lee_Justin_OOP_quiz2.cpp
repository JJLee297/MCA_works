/*
Program: ECET11 MP1 OOP Quiz 2
Student Name: Justin Lee
Date:  09/17/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Elevator {
private:
	int currentFloor = 1; 
public: 
	Elevator(int cfloor);
	void request(int newfloor);
};

Elevator::Elevator(int cfloor) {
	currentFloor = cfloor;
	cout << "Creating elevator on floor " << cfloor << endl; 
}

void Elevator::request(int newfloor) {
	bool deny = false;
	if (newfloor == 13 || newfloor > 66 || newfloor < 1 || newfloor == currentFloor) {
		cout << "Floor " << newfloor << " Request denied - remaining at current floor " << currentFloor << endl;
		deny = true;
	}	
	if (deny == false) 
		cout << "Floor " << newfloor << " request\nStarting at floor " << currentFloor << endl;
	if (currentFloor > newfloor && deny == false) {
		for (int i = 0; i < currentFloor - newfloor; ++i) {
			if (currentFloor - i - 1 != 13)
				cout << "Going Down - now at floor " << currentFloor - i - 1 << endl;
		}
		cout << "Stopping at floor " << newfloor << endl; 
		currentFloor = newfloor;
	}
	else if (currentFloor < newfloor && deny == false) {
		for (int i = 0; i < newfloor - currentFloor; ++i) {
			if (currentFloor + 1 + i != 13)
				cout << "Going Up - now at floor " << currentFloor + 1 + i << endl;
		}
		cout << "Stopping at floor " << newfloor << endl; 
		currentFloor = newfloor;
	}
}
int main()
{
	int n, initial, m, floor;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> initial; 
		Elevator buildingElevator(initial);
		cin >> m;
			for (int j = 0; j < m; ++j) {
				cin >> floor;
				buildingElevator.request(floor);
			}
	}
	system("pause");
}
