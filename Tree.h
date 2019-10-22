#pragma once
using namespace System;

namespace TreeVisualizer { ref class TreeNode; }

namespace TreeVisualizer
{
	public ref class Tree
	{
	private:
		TreeNode ^root;

	public:
		Tree();

	internal:
		property TreeNode ^Root
		{
			TreeNode ^get();
		}

	public:
		void Add(int value);

		static int Height(TreeNode ^node);

		void insert(int value);

		void ClearMark();
	private:
		void clearMark(TreeNode ^node);

	public:
		void Search(int value);


	private:
		TreeNode ^Insert(int value, TreeNode ^node);

	public:
		TreeNode ^updateHeight(TreeNode ^node);

	private:
		TreeNode ^balance(TreeNode ^node);

		bool checkType(TreeNode ^node);
		TreeNode ^rightRotation(TreeNode ^node);

		TreeNode ^leftRotation(TreeNode ^node);

		TreeNode ^leftRightRotation(TreeNode ^node);

		TreeNode ^rightLeftRotation(TreeNode ^node);

		TreeNode ^findMin(TreeNode ^p);

		TreeNode ^removeMin(TreeNode ^p);

		int getBalance(TreeNode ^N);

		TreeNode ^remove(TreeNode ^p, int k);

	public:
		void Remove(int value);
	};
}
