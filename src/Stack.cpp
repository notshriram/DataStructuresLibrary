#include <iostream>
#include "Stack.h"

using namespace std;

#define MAX 500

//Initialising Stack
Stack::Stack()
{
	pointer = -1;
};

//Push functionality - Adds the element in LastInFirstOut(LIFO) fashion
void Stack::push()
{
	if (pointer>MAX-1)
		{
		cout<<"Stack is full (error type:overflow)"<<endl;
		}
	else
		{
			int userInput;
			cout<<"Enter the element to be added: ";
        	cin>>userInput;
			StackArray[++pointer]=userInput;
			cout<<"Element "<<userInput<<" sucessfully added"<<endl;
		}
};

//Pop functionality - Removes the element in LastInFirstOut(LIFO) fashion
void Stack::pop()
{
	if (pointer<0)
	{
		cout<<"Stack is empty (error type:underflow)"<<endl;
	}
	else
	{
		int poppedElement = StackArray[pointer--]; 
    	cout<<poppedElement<<" has been popped"<<endl;
	}
};

//View functionality - Views all the elements in the Stack
void Stack::viewStack()
{
	if(pointer<0)
	{
		cout<<"The Stack is empty"<<endl;
	}
	else
	{
		cout<<"The Stack is: ";
		for (int i = pointer; i>=0; i--)
		{
			cout<<StackArray[i]<<" ";
		}
		cout<<endl<<endl;
	}
};


//Top funtionality - Tells us the top most element
void Stack::top()
{
	cout<<"The top element is: "<<StackArray[pointer]<<endl;
};