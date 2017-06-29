#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;

class complex
{
public:
	double real;
	double imaginary;
	complex() { real = 0.0; imaginary = 0.0; }
	complex(double r, double i)
	{
		this->real = r;
		this->imaginary = i;
	}
	void print(ostream&)
	{
		cout << real << " + i*(" << imaginary << ')' << endl;
	}
	friend ostream& operator << (ostream&, const complex&);
	complex add(complex res)
	{
		res.real = real + res.real;
		res.imaginary = imaginary + res.imaginary;
		return res;
	}
	complex sub(complex res)
	{
		res.real = real - res.real;
		res.imaginary = imaginary - res.imaginary;
		return res;
	}
	complex mult(int c)
	{
		complex res(0, 0);
		res.real = real * c;
		res.imaginary = imaginary * c;
		return res;
	}
	complex div(int c)
	{
		complex res(0, 0);
		try
		{
			if (c == 0) throw c;
		}
		catch (int c)
		{
			cout << endl << "ERROR!!! You can't divide by zero" << endl;
			return res;
		}
		res.real = real / c;
		res.imaginary = imaginary / c;
		return res;
	}
};
ostream & operator<<(ostream & ciout, complex &numb)
{
	numb.print(ciout);
	return ciout;
}

int main(void)
{
	complex result(0, 0);
	cout << "a = ";
	complex complex_num(3, 2);
	cout << complex_num;
	cout << "b = ";
	complex plus(1, 9);
	cout << plus;
	cout << "a + b = ";
	result = complex_num.add(plus);
	cout << result;

	cout << "c = ";
	complex minus(3, 11);
	cout << minus;
	cout << "a - c = ";
	result = complex_num.sub(minus);
	cout << result;
	cout << "a*7 = ";
	result = complex_num.mult(7);
	cout << result;
	cout << "a/2 = ";
	result = complex_num.div(2);
	cout << result;
	_getch();
	system("pause");
	return 0;
}
