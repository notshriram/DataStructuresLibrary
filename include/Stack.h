/*
Copyright (C) 2020 by Sriram Madduri

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef STACK_H
#define STACK_H
#include<iostream>

using namespace std;

/**
 * The <code>node</code> class represents structure of node
 */

template <class E>
class node
{
	public:
		E data;
		node<E> *pointerToNext;
};

/**
 * The <code>stack</code> class represents structure of node
 */

template <class E>
class stack
{
	public:
		node<E> *Top;

		/**
		 * Default constructor for stack
		 */

		stack()
		{
			Top=NULL;
		}

		/**
		 * Pushes a new element into stack
		 */

		void push(E input);

		/**
		 * Pops the top element of stack
		 */

		void pop();

		/**
		 * Displays the whole stack
		 */

		void viewStack();

		/**
		 * Displays the top element of stack
		 */	

		void peek();
};

//Pop method
template <class E>
void stack<E>::pop()
{
	if(Top!=NULL)
	{

		cout<<"The popped element is "<< Top->data <<endl;
    	Top = Top->pointerToNext;

	}
	else
	{
		cout<<"ERROR: Stack underflow/Stack is empty."<<endl;
	}

}

//Push method
template <class E>
void stack<E>::push(E input)
{
	node<E> *newNode=new node<E>; 
	newNode->data = input; 
	newNode->pointerToNext = Top; 
	Top = newNode;
	cout<<newNode->data<<" is pushed into stack."<<endl;

}

//Peek method
template <class E>
void stack<E>::peek()
{
	
	cout<<Top->data<<" is on the top."<<endl;

}


//viewStack method
template <class E>
void stack<E>::viewStack()
{
	node<E> *current;

	if(Top!=NULL)
	{
		current = Top; 
     	cout<<"STACK: ";
     	while (current != NULL) 
     	{ 
     		cout<< current->data <<" "; 
     		current = current->pointerToNext;
     	}

	}
   else 
   {
   		cout<<"Empty stack, nothing to display";
   }   
   cout<<endl;

}

#endif