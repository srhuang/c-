#include <iostream>
using namespace std;

template <class T>
void swaps(T& a1,T& a2)
{
	T tmp=a1;
	a1=a2;
	a2=tmp;
}

class A
{
public:
	int aaa;
	double bbb;
};

int main() 
{
	int a=10;
	int b=20;
	cout << "Before swap int : ";
	cout << '(' << a << ',' << b << ')' << endl;
	swaps(a,b);
	cout << "After swap int : ";
	cout << '(' << a << ',' << b << ')' << endl;

	double c = 9.8;
	double d = 3.14158;
	cout << "Before swap double : ";
	cout << '(' << c << ',' << d << ')' << endl;
	swaps(c,d);
	cout << "After swap double : ";
	cout << '(' << c << ',' << d << ')' << endl;

	A mA;
	mA.aaa = 1111;
	mA.bbb = 11.11;

	A mB;
	mB.aaa = 2222;
	mB.bbb = 22.22;

	cout << "Before swap Class A : ";
	cout << "mA=" << '(' << mA.aaa << ',' << mA.bbb << ')' <<"\t";
	cout << "mB=" << '(' << mB.aaa << ',' << mB.bbb << ')' << endl;
	swap(mA, mB);
	cout << "After swap Class A : ";
	cout << "mA=" << '(' << mA.aaa << ',' << mA.bbb << ')' <<"\t";
	cout << "mB=" << '(' << mB.aaa << ',' << mB.bbb << ')' << endl;
	return 0;
}