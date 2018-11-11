#include <iostream>
using namespace std;

//partial specialization
template<class T1, class T2>
class myClass
{
public:
	myClass(T1 a);

	T1 add (const T2 a)
	{
		return (value+a);
	}

	T1 getValue()
	{
		return value;
	}

private:
	T1 value;

};

template<class T1, class T2>
myClass<T1, T2>::myClass(T1 a)
{
	value = a;
}

//partial specialization
template<class T>
class myClass<T, float>
{
public:
	myClass(T a);

	T add (const float a)
	{
		return (value);
	}

	double add(const double a)
	{
		return (value+a*2);
	}

	T getValue()
	{
		return value;
	}

private:
	T value;

};
template<class T>
myClass<T, float>::myClass(T a)
{
	value = a;
}


int main()
{
	cout << "Testing Generic class..." << endl;
	myClass<double, int> AAA(9.8);
	cout << AAA.getValue() << endl;
	cout << AAA.add(4) << endl;
	//cout << AAA.add(4.3) << endl; //will be error

	cout << "Testing Partial specialization..." << endl;
	myClass<int, float> BBB(5);
	cout << BBB.getValue() << endl;
	cout << BBB.add(4.3) << endl;

	cout << "Testing member function specialization..." << endl;
	double b = 9.8;
	cout << BBB.getValue() << endl;
	cout << BBB.add(b) << endl;

}