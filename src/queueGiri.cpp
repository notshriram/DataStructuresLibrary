#include<iostream>
using namespace std;
template <class t>
class node							//node class which contains the structure of the node
{
 public:
  t data;							//data variable to hold the value of the entered number
  node<t> *next;					//next pointer which points to the next variable int the queue
};
template<class t>
class queue							//queue class for cointaining the methods ie enqueue and dequeue along with display method
{
 public:
  node<t> *front;					//2 pointers front and rear and declared
  node<t> *rear;					//insertion from the rear pointer and deletion from front pointer
 public:	
  queue();							//constructor which will be defined later so as of now empty
  void enqueue(t);
  t dequeue ();
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

int main()					//main function 
{	
	queue<int>q1;			//queue class object created
	q1.enqueue(10);			//engueued 10,20,30,40
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.dequeue();			//dequeued twice so the display function should print 30 and 40 since 10,20 have been dequeued
	q1.dequeue();
	q1.display();
	
}
