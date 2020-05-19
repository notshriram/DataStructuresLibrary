/*
Copyright (C) 2020 by Madduri Sriram

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
#include<string>
#include<iostream>

using namespace std;


#define MAX 500

/**
 * The <code>Stack</code> class represents the data structure stack
 */


class Stack
{

	public:

		int pointer;
		int StackArray[MAX];

		/**
		 * Default constructor for Stack
		 */

		Stack();


		/**
		 * Pushes a new element into Stack
		 */
		void push();
		

		/**
		 * Pops the top most element off the Stack
		 */
		void pop();
		

		/**
		 * Displays all the elements of the Stack
		 */
		void viewStack();
		


		/**
		 * Displays the top most element of Stack
		 */
		void top();
		

};

#endif