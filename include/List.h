/*
Copyright (C) 2020 by Shriram Ravindranathan

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

/*! \mainpage DataStructuresLibrary Documentation
 *
 * \section intro_sec Introduction
 *
 * This is a sample project that we created just to get accustomed to open source
 * development and working together on code as a team. This repository consists
 * of various data structures like List, Stack, etc.. implemented in c++. The main
 * aim of this project was to familiarize everyone with git and collaborating on a
 * project as a team so the implementation side of these data structures might not
 * be as robust as some of the other alternatives
 *
 * \section install_sec Installation
 * All the data structures implemented in this repository may be compiled into
 * a statically linked library (DSL.a) to be used in other projects
 *
 * \subsection step1 Step 1:Cloning the repository
 * To use this library first clone the repository using the command
 * <code> git clone https://github.com/notshriram/DataStructuresLibrary.git</code>
 *
 * \subsection step2 Step 2: Creating the statically linked library
 * A statically linked version of this library can be obtained by running <code>make DSL.a</code>
 * in the root directory
 */

#pragma once
#ifndef _LIST_H_
#define _LIST_H_

 /**
  * The <code>List</code> class represents the linked list data structure
  *
  * @tparam Object type for the data contained in the list
  */

template <class Object>
class List
{
private:
	struct Node {
		Object data;
		Node* prev;
		Node* next;
		Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr) :data(d), prev(p), next(n) {}
	};
public:
	class const_iterator
	{
	protected:
		Node* current;
		Object& retrieve() const { return current->data; }
		const_iterator(Node* p) :current(p) {}
		friend class List<Object>;
	public:
		const_iterator() :current(nullptr) {}
		const Object& operator*() const { return retrieve(); }
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		bool operator==(const const_iterator& rhs)const { return current == rhs.current; }
		bool operator!=(const const_iterator& rhs)const { return !(*this == rhs); }
	};
	class iterator : public const_iterator
	{
	public:
		iterator() {}
		Object& operator*() { return retreive(); }
		const Object& operator*() const
		{
			return const_iterator::operator*();
		}
		iterator& operator++() 
		{
			current = current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	protected:
		iterator(Node* p) :const_iterator(p) {}
		friend class List<Object>
	};
public:
	/**
	 * Default Constructor for the class List
	 *
	 */
	List();
	/**
	 * Copy Constructor for the class List
	 *
	 * @param[in] rhs the object of the class List which is to be copied
	 */
	List(const List& rhs);
	/**
	 * Default Destructor for the class List
	 *
	 */
	~List();

	/**
	 * returns an iterator to the first element in the List
	 *
	 *@return iterator to first element
	 *
	 */
	iterator begin() {}
	/**
	 * returns an const iterator to the first element in the List
	 *
	 *@return iterator to first element
	 */
	const_iterator begin() const {}
	/**
	 * returns an iterator to the last element in the List
	 *
	 *@return iterator to last element
	 */
	iterator end() {}
	/**
	 * returns an const iterator to the last element in the List
	 *
	 *@return iterator to last element
	 */
	const_iterator end() const {}
	/**
	 * returns the size of the list 
	 *
	 *@return the size of the list 
	 */
	int size() const {}
	/**
	* checks whether the list is empty
	*
	*@return true if the list is empty false otherwise
	*/
	bool empty() const { return size() == 0; }
	/**
	 * Clears all the elements in the list
	 *
	 */
	void clear() {
		while (!empty)pop_front();
	}
	/**
	 *returns the value of the first element of the list
	 *
	 *@return the value of the first element
	 */
	Object& front() { return *begin(); }
	/**
	 *returns the value of the first element of the list
	 *
	 *@return the value of the first element
	 */
	const Object& front() const { return *--end(); }
	/**
	 *returns the value of the last element of the list
	 *
	 *@return the value of the last element
	 */
	Object& back() { return *begin(); }
	/**
	 *returns the value of the last element of the list
	 *
	 *@return the value of the last element
	 */
	const Object& back() const { return *--end(); }
	/**
	 *Appends the element to the front of the linked list
	 */
	void push_front(const Object& x) {};
	/**
	 *Appends the element to the back of the linked list
	 */
	void push_back(const Object& x) {};
	/**
	 *removes the first element of the linked list
	 */
	void pop_front(const Object& x) {};
	/**
	 *removes the last element from the back of the linked list
	 */
	void pop_back(const Object& x) {};
	/**
	 *inserts the element at the location of the iterator
	 */
	iterator insert(iterator itr, const Object& x) {}
	/**
	 *deletes the element at the iterator
	 */
	iterator erase(iterator itr) {}
	/**
	 *deletes the element in the range start to end
	 */
	iterator erase(iterator start, iterator end) {}

private:
	int theSize;
	Node* head;
	Node* tail;
	void init() {}
};

#endif
