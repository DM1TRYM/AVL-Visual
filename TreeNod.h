#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

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
