#pragma once

namespace TreeVisualizer
{
	public ref class TreeNode
	{
	public:
		int value = 0;
		TreeNode^ left;
		TreeNode^ right;
		int height = 0;
		bool marked = false;
	};
}
