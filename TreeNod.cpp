#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>
#include "TreeNode.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
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

