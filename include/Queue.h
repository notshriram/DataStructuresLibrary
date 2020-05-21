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

#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
 * The <code>Queue</code> class represents the Queue data structure
 *
 * @tparam Object type for the data contained in the Queue
 */

template <typename T>
class Queue
{
private:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* previous;

		Node(T value)
		{
			this->value = value;
		}
	};
private:
	int size_;
	Node* head_ = nullptr;
	Node* tail_ = nullptr;

public:
	/**
	 * Default Constructor for the class Queue
	 *
	 */
	Queue()
	{
		this->size_ = 0;
	}
	/**
	 * Inserts an element into the Queue
	 *
	 * @param[in] value the value which is to be inserted
	 *
	 */
	void enqueue(T value)
	{
		if (this->head_ == nullptr)
		{
			this->head_ = new Node(value);
			this->tail_ = this->head_;
		}
		else
		{
			this->tail_->next = new Node(value);
			this->tail_->next->previous = this->tail_;
			this->tail_ = this->tail_->next;
		}
		this->size_ += 1;
	}

	/**
	 * Removes the element at the tail of the queue
	 *
	 * @return The node which is removed
	 */
	Node dequeue()
	{
		Node* tmp = this->tail_;

		this->tail_ = this->tail->previous;
		this->tail_->next = nullptr;
		this->size_ -= 1;
		return tmp;
	}
};
#endif
