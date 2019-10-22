#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace TreeVisualizer { ref class Tree; }
namespace TreeVisualizer { ref class TreeNode; }

namespace TreeVisualizer
{
	private ref class VisualTree
	{
	private:
		static constexpr int Radius = 20;
		static constexpr int VerticalMarging = 50;
		static constexpr int HorizontalMarging = 25;
		initonly Font^ _font = SystemFonts::DefaultFont;

	public:
		Size GetSize(Tree^ tree);

		void Draw(Graphics^ g, TreeNode^ node, Rectangle rect);

	private:
		Point DrowWithoutBorders(Graphics^ g, TreeNode^ node, Rectangle rect);

		void DrawLine(Graphics^ g, Point p1, Point p2);

		double atg(double dy, double dx);

		void DrawNode(Graphics^ g, Nullable<int> value, bool isMark, int centerX, int centerY);
	};
}
