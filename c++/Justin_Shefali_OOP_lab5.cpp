/*
Justin Lee & Shefali Aswathi OOP Lab 5
*/
#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
private:
	int a, b, c, d, e; 
public:
	Polynomial() {
		
	};
	void set(int a1, int b1, int c1, int d1, int e1);
	int get(int);
	void display() {
		bool firstterm = false; 
		int arr[5] = { a, b, c, d, e };
		if (a > 0) {
			firstterm = true;
			if (a != 1)
				cout << a << " x^4";
			else
				cout << "x^4";
		}
		else if (a < 0) {
			firstterm = true; 
			if (a != -1)
				cout << " - " << abs(a) << " x^4";
			else
				cout << " - x^4";
		}
		if (b > 0) {
			if (firstterm == false && b != 1)
				cout << b << " x^3";
			else if (b != 1 && firstterm == true)
				cout << " + " << b << " x^3";
			else
				cout << " + x^3";
			firstterm = true; 
		}
		else if (b < 0) {
			if (b != -1)
				cout << " - " << abs(b) << " x^3";
			else
				cout << " - x^3";
		}
		if (c > 0) {
			if (firstterm == false && c != 1)
				cout << c << " x^2";
			else if (c != 1)
				cout << " + " << c << " x^2";
			else
				cout << " + x^2";
			firstterm = true; 
		}
		else if (c < 0) {
			if (c != -1)
				cout << " - " << abs(c) << " x^2";
			else
				cout << " - x^2";
		}
		if (d > 0) {
			if (firstterm == false && d != 1)
				cout << d << " x";
			else if (d != 1)
				cout << " + " << d << " x";
			else
				cout << " + x";
			firstterm = true;
		}
		else if (d < 0) {
			if (d != -1)
				cout << " - " << abs(d) << " x";
			else
				cout << " - x";
		}
		if (e > 0) {
			if (firstterm == false)
				cout << e;
			else 
				cout << " + " << e; 
		}
		else if (e < 0) {
			cout << " - " << abs(e); 
		}
	}
	Polynomial operator+(const Polynomial& p) {
		Polynomial newt;
		newt.a = this->a + p.a;
		newt.b = this->b + p.b;
		newt.c = this->c + p.c;
		newt.d = this->d + p.d;
		newt.e = this->e + p.e;
		return newt; 
	}
	Polynomial operator-(const Polynomial& p) {
		Polynomial newt;
		newt.a = this->a - p.a;
		newt.b = this->b - p.b;
		newt.c = this->c - p.c;
		newt.d = this->d - p.d;
		newt.e = this->e - p.e;
		return newt;
	}
	Polynomial operator+=(const Polynomial& p) {
		this->a += p.a; 
		this->b += p.b;
		this->c+= p.c;
		this->d += p.d;
		this->e += p.e;
		return *this; 
	}
	Polynomial operator*(const Polynomial& p) {
		Polynomial newt;
		newt.c = this->d * p.d;
		newt.d = (this->e * p.d) + (this->d * p.e);
		newt.e = (this->e * p.e);
		newt.a = 0;
		newt.b = 0; 
		return newt;
	}
};

int Polynomial::get(int j) {
	if (j == 0)
		return e;
	if (j == 1)
		return d;
	if (j == 2)
		return c;
	if (j == 3)
		return b;
	if (j == 4)
		return a;
}
void Polynomial::set(int a1, int b1, int c1, int d1, int e1) {
	a = a1;
	b = b1;
	c = c1;
	d = d1;
	e = e1; 
}


int main() {

		Polynomial poly;
		Polynomial poly2; 
		cout << "Enter First Polynomial: ";
		int a, b, c, d, e, a1, b1, c1, d1, e1; 
		cin >> a >> b >> c >> d >> e; 
		poly.set(a, b, c, d, e);
		cout << "P1: ";
		poly.display();
		cout << "\nEnter Second Polynomial: ";
		cin >> a1 >> b1 >> c1 >> d1 >> e1;
		poly2.set(a1, b1, c1, d1, e1);
		cout << "P2: ";
		poly2.display();
		cout << "\nP1 + P2: ";
		(poly + poly2).display();
		cout << "\nP1 - P2: ";
		(poly - poly2).display();
		cout << "\nP1 += P2: ";
		(poly += poly2).display();
		cout << "\nP1 * P2: P1 & P2 must be BINOMIALS" << endl;
		cout << "Enter First binomial:";
		cin >> d >> e;
		poly.set(0, 0, 0, d, e);
		cout << "\nEnter Second binomial:";
		cin >> d1 >> e1;
		poly2.set(0, 0, 0, d1, e1);
		cout << "P1 * P2: ";
		(poly*poly2).display();
		cout << endl;
}
