/*
Copyright(C) 2020 by Kusumba Vijith

This program is free software : you can redistribute it and /or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see < https://www.gnu.org/licenses/>.
*/

#pragma once
#ifndef BST_H
#define BST_H

/**
 * The <code>BST</code> class represents the data structure Binary Search Tree
 */
template <typename T>
class BST {
private:
	T value;
	BST* left;
	BST* right;

public:
	/**
	 * Constructor for Binary Search Tree
	 *
	 * @param[in] x the value of the root node
	 */
	BST(T val)
	{
		value = val;
		left = nullptr;
		right = nullptr;
	}
	/**
	 * Destructor for Binary Search Tree
	 */

	~BST();

	/**
	 * function to insert a value To the bst
	 *
	 * @param[in] x the value of the root node
	 */
	void insert(T val);

	/**
	 * function to search in te bst, returns a boolean
	 *
	 * @param[in] val the value which is to be searched for
	 *
	 * @return true if the value is present, false if not.
	 */
	bool search(T val);

	/**
	 * function to remove an element from the bst
	 *
	 * @param[in] val the value which is to be removed
	 * @param[in] ParentNode the parent node in the Binary Search Tree
	 */

	void remove(T val, BST* parentNode = nullptr);

	/**
	 * preoder traversal (root -> left -> right)
	 * @param[in] ParentNode the parent node in the Binary Search Tree
	 */
	void preorder(BST* parentNode);
	/**
	 * inoeder traversal (left -> root -> right)
	 * @param[in] ParentNode the parent node in the Binary Search Tree
	 */

	void inorder(BST* parentNode);
	/**
	 * postoder traversal (left -> right -> root)
	 * @param[in] ParentNode the parent node in the Binary Search Tree
	 */
	void postorder(BST* parentNode);
	/**
	 * Finds the minimum element in the Binary search tree
	 *
	 * @return value of the minimum element
	 *
	 */
	const T& findMin();
	/**
	 * Finds the maximum element in the Binary search tree
	 *
	 * @return value of the maximum element
	 *
	 */
	const T& findMax();
};
#endif