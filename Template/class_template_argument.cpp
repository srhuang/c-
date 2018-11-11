#include <iostream>
using namespace std;

template<class T, int size>
class myStack
{
public:
	myStack(); 

	~myStack()
	{
		delete stack_p;
	}

	bool push (const T&);
	bool pop (T&);

	bool isEmpty() const //const function could NOT change any member
	{
		return (-1 == top);
	}

	bool isFull() const
	{

		return (top == size-1);
	}

private:
	int top;
	T *stack_p;

};

//Implementation
template<class T, int size>
myStack<T, size>::myStack()
{
	top = -1;
	stack_p = new T[size];
}

template<class T, int size>
bool myStack<T, size>::push (const T &value)
{
	if ( ! isFull())
	{
		stack_p[++top] = value;
		return true;
	}

	return false;
}

template<class T, int size>
bool myStack<T, size>::pop (T &value)
{
	if ( ! isEmpty())
	{
		value = stack_p[top--];
		return true;
	}

	return false;

}

int main ()
{
	myStack<int, 20> AAA;

	cout << "Pushing INT into myStack..." << endl;
	int a = 0;
	while ( AAA.push(a))
	{
		cout << a << ' ';
		a++;
	}
	cout << endl;

	cout << "Poping INT from myStack..." << endl;
	while (AAA.pop(a))
	{
		cout << a << ' ';
	}
	cout << endl;

	

}