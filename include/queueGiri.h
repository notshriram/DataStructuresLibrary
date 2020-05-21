/*
Copyright (C) 2020 by Giri Nithin

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

#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

/**
 * The <code>node</code> class represents structure of node
 */

template <class t>
class node							//node class which contains the structure of the node
{
 public:
  t data;							//data variable to hold the value of the entered number
  node<t> *next;					//next pointer which points to the next variable int the queue
};



/**
 * The <code>queue</code> class represents the data structure queue
 */


template<class t>
class queue							//queue class for cointaining the methods ie enqueue and dequeue along with display method
{
 
 public:
  node<t> *front;					//2 pointers front and rear and declared
  node<t> *rear;					//insertion from the rear pointer and deletion from front pointer
 

 /**
  * Default constructor for Queue
  */	
  queue();

/**
  * Pushes an new element into queue
  */

  void enqueue(t);

/**
  * Pop an first element from queue
  */
  
  t dequeue ();

/**
  * Displays the whole queue
  */
  
  void display();
  
};

template<class t>
queue<t>::queue()					//constructor declaration for initial conditions	
{									//ie front and rear must point to null initially
	front = NULL;
	rear  = NULL; 
}

template<class t>
void queue<t>::enqueue(t val)     //enqueue method defination
{
	node<t> *ptr=new node<t>;	//creating a node ptr which hold the entered value passed as an argument
	ptr->data=val;
	ptr->next=NULL;
	
	if(rear==NULL&&front==NULL)	//condition for queue is empty or not
 	{
  		rear=ptr;
  		front=ptr;
 	}
 	else						//inserting by incrementing the rear by 1
 	{							
 		rear->next=ptr;
 		rear=rear->next;
	 }
}

template<class t>
t queue<t>::dequeue()			//dequeue method defination
{								
	node<t> *temp;				//creating a node temp which holds front initially and then increment the front by 1 and delete temp 
	if(front!=NULL)      		//temp is created just to support the deletion function
	{
		temp=front;
		front=front->next;
		delete temp;
	}
	else
	{
		cout<<"Queue is empty"<<endl;
	}
}

template<class t>
void queue<t>::display()	//display method defination
{
	node<t> *temp1;			// I created another node temp1 personal choice 
	temp1 = front;			//assigning temp1 to front and use temp1 to traverse through the queue
   if ((front == NULL) && (rear == NULL)) //queue is empty condition
   {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   	while (temp1!= NULL) {			//condition for traversing the queue
      	cout<<temp1->data<<" ";
      	temp1= temp1->next;
   }
   cout<<endl;
}

#endif