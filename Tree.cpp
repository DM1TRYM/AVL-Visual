#include "Tree.h"
#include "TreeNode.h"

using namespace System;

namespace TreeVisualizer {
	Tree::Tree()
	{
		this->root = nullptr;
	}

	TreeNode^ Tree::Root::get()
	{
		return root;
	}

	void Tree::Add(int value)
	{
		insert(value);
	}

	int Tree::Height(TreeNode^ node)
	{
		if(node == nullptr)
		{
			return 0;
		}
		auto leftH = Height(node->left);
		auto rightH = Height(node->right);
		return Math::Max(leftH, rightH) + 1;
	}

	void Tree::insert(int value)
	{
		if(root == nullptr)
		{
			root = gcnew TreeNode();
			root->value = value;
			root->marked = false;
		}
		else
		{
			root = Insert(value, root);
		}
	}

	void Tree::ClearMark()
	{
		clearMark(root);
	}

	void Tree::clearMark(TreeNode^ node)
	{
		if(node == nullptr)
		{
			return;
		}
		node->marked = false;
		clearMark(node->left);
		clearMark(node->right);
	}

	void Tree::Search(int value)
	{
		TreeNode^ node = this->root;
		while(node != nullptr)
		{
			if(node->value > value)
			{
				node = node->left;
			}
			else
			{
				if(node->value < value)
				{
					node = node->right;
				}
				else
				{
					node->marked = true;
					break;
				}
			}
		}
		/*
		if(node->value > value)
		{
			while(node != nullptr)
				node = node->left;
		}
		else
		{
			if(node->value < value)
			{
				while(node != nullptr)
					node = node->right;
			}
			else
			{
				while(node != nullptr)
				{ 
					node->marked = true;
					break;
				}
				
			}
		}*/

	}

	TreeNode^ Tree::Insert(int value, TreeNode^ node)
	{
		if(node == nullptr)
		{
			TreeNode^ tempVar = gcnew TreeNode();
			tempVar->value = value;
			tempVar->marked = false;
			return tempVar;
		}

		if(node->value < value)
		{
			node->right = Insert(value, node->right);
		}
		else
		{
			node->left = Insert(value, node->left);
		}

		node->height = 1 + Math::Max(Height(node->left), Height(node->right));

		int balance = getBalance(node);

		if(balance > 1 && value < node->left->value)
		{
			return rightRotation(node);
		}

		if(balance > 1 && value > node->left->value)
		{
			node->left = leftRotation(node->left);
			return rightRotation(node);
		}

		if(balance < -1 && value > node->right->value)
		{
			return leftRotation(node);
		}

		if(balance < -1 && value < node->right->value)
		{
			node->right = rightRotation(node->right);
			return leftRotation(node);
		}

		return node;
	}

	TreeNode^ Tree::updateHeight(TreeNode^ node)
	{
		int left = (node == nullptr || (node->left == nullptr)) ? 0 : node->left->height + 1;
		int right = (node == nullptr || (node->right == nullptr)) ? 0 : node->right->height + 1;

		int height = Math::Max(left, right);
		node->height = height;

		int difference = Math::Abs(right - left);

		if(difference >= 2)
		{
			node = balance(node);
		}

		return node;
	}

	TreeNode^ Tree::balance(TreeNode^ node)
	{
		bool first = checkType(node);
		bool second = first ? checkType(node->left) : checkType(node->right);

		if(first && second)
		{
			return rightRotation(node);
		}
		else if(!first && !second)
		{
			return leftRotation(node);
		}
		else if(first && !second)
		{
			node = leftRightRotation(node);
			return rightRotation(node);
		}
		else if(!first && second)
		{
			node = rightLeftRotation(node);
			return leftRotation(node);
		}
		return updateHeight(node);
	}

	bool Tree::checkType(TreeNode^ node)
	{
		int left = (node->left == nullptr) ? 0 : node->left->height + 1;
		int right = (node->right == nullptr) ? 0 : node->right->height + 1;

		return left > right;
	}

	TreeNode^ Tree::rightRotation(TreeNode^ node)
	{
		TreeNode^ newRoot = node->left;
		TreeNode^ temp = (newRoot->right == nullptr) ? nullptr : newRoot->right;
		newRoot->right = node;

		node->left = temp;

		return newRoot;
	}

	TreeNode^ Tree::leftRotation(TreeNode^ node)
	{
		TreeNode^ newRoot = node->right;
		TreeNode^ temp = (newRoot->left == nullptr) ? nullptr : newRoot->left;
		newRoot->left = node;

		node->right = temp;

		return newRoot;
	}

	TreeNode^ Tree::leftRightRotation(TreeNode^ node)
	{
		TreeNode^ temp = node->left;
		TreeNode^ newRoot = node->left->right;

		temp->right = nullptr;
		node->left = newRoot;
		newRoot->left = temp;

		return node;
	}

	TreeNode^ Tree::rightLeftRotation(TreeNode^ node)
	{
		TreeNode^ temp = node->right;

		TreeNode^ newRoot = node->right->left;
		temp->left = nullptr;
		node->right = newRoot;
		newRoot->right = temp;

		return node;
	}

	TreeNode^ Tree::findMin(TreeNode^ p)
	{
		return (p->left != nullptr) ? findMin(p->left) : p;
	}

	TreeNode^ Tree::removeMin(TreeNode^ p)
	{
		if(p->left == nullptr)
		{
			return p->right;
		}
		p->left = removeMin(p->left);
		return balance(p);
	}

	int Tree::getBalance(TreeNode^ N)
	{
		if(N == nullptr)
		{
			return 0;
		}
		return Height(N->left) - Height(N->right);
	}

	TreeNode^ Tree::remove(TreeNode^ p, int k)
	{
		if(p == nullptr)
		{
			return p;
		}

		if(k < p->value)
		{
			p->left = remove(p->left, k);
		}
		else
		{
			if(k > p->value)
			{
				p->right = remove(p->right, k);
			}
			else
			{
				TreeNode^ q = p->left;
				TreeNode^ r = p->right;
				if(r == nullptr || q == nullptr)
				{
					TreeNode^ temp = nullptr;
					if(temp == p->left)
					{
						temp = p->right;
					}
					else
					{
						temp = p->left;
					}

					//temp = (temp == p->left) ? p->right : p->left;

					if(temp == nullptr)
					{
						temp = p;
						p = nullptr;
					}
					else
					{
						p = temp;
					}
				}
				else
				{
					TreeNode^ temp = findMin(p->right);
					p->value = temp->value;
					p->right = remove(p->right, temp->value);
				}
			}
		}

		if(p == nullptr)
		{
			return p;
		}

		p->height = Math::Max(Height(p->left), Height(p->right)) + 1;

		int balance = getBalance(p);

		if(balance > 1 && getBalance(p->left) >= 0)
		{
			return rightRotation(p);
		}

		if(balance > 1 && getBalance(p->left) < 0)
		{
			p->left = leftRotation(p->left);
			return rightRotation(p);
		}

		if(balance < -1 && getBalance(p->right) <= 0)
		{
			return leftRotation(p);
		}

		if(balance < -1 && getBalance(p->right) > 0)
		{
			p->right = rightRotation(p->right);
			return leftRotation(p);
		}

		return p;
	}

	void Tree::Remove(int value)
	{
		this->root = remove(root, value);
	}
}