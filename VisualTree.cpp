#include "VisualTree.h"
#include "Tree.h"
#include "TreeNode.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace TreeVisualizer {
	Size VisualTree::GetSize(Tree^ tree)
	{
		auto height = Tree::Height(tree->Root) + 1;
		auto width = Math::Pow(2, height - 1);

		auto heightPx = (height - 1) * VerticalMarging + 2 * Radius;
		auto widthPx = (width - 1) * HorizontalMarging + 2 * Radius;

		return Size(safe_cast<int>(widthPx), heightPx);
	}

	void VisualTree::Draw(Graphics^ g, TreeNode^ node, Rectangle rect)
	{
		auto newRect = Rectangle(rect.Left + Radius, rect.Top + Radius, rect.Width - 2 * Radius, rect.Height - 2 * Radius);
		DrowWithoutBorders(g, node, newRect);
	}

	Point VisualTree::DrowWithoutBorders(Graphics^ g, TreeNode^ node, Rectangle rect)
	{
		auto center = Point(rect.Left + rect.Width / 2, rect.Top);
		;
		if(node == nullptr)
		{
			return center;
		}
		DrawNode(g, node->value, node->marked, center.X, center.Y);

		auto subSize = Size((rect.Width - HorizontalMarging) / 2, rect.Height - VerticalMarging);
		auto leftRect = Rectangle(Point(rect.Left, rect.Top + VerticalMarging), subSize);
		auto rightRect = Rectangle(Point(rect.Left + (rect.Width + HorizontalMarging) / 2, rect.Top + VerticalMarging), subSize);

		auto leftPoint = DrowWithoutBorders(g, node->left, leftRect);
		auto rightPoint = DrowWithoutBorders(g, node->right, rightRect);

		if(node->left != nullptr)
		{
			DrawLine(g, center, leftPoint);
		}
		if(node->right != nullptr)
		{
			DrawLine(g, center, rightPoint);
		}

		return center;
	}

	void VisualTree::DrawLine(Graphics^ g, Point p1, Point p2)
	{
		auto pen = gcnew Pen(Color::Black);

		auto alpha = atg(p2.Y - p1.Y, p2.X - p1.X);
		auto p3 = Point(safe_cast<int>(p1.X + Radius * Math::Cos(alpha)), safe_cast<int>(p1.Y + Radius * Math::Sin(alpha)));
		auto p4 = Point(safe_cast<int>(p2.X - Radius * Math::Cos(alpha)), safe_cast<int>(p2.Y - Radius * Math::Sin(alpha)));
		g->DrawLine(pen, p3, p4);
	}

	double VisualTree::atg(double dy, double dx)
	{
		auto k = dy / dx;
		auto alpha = Math::Atan(k) + ((dx < 0) ? Math::PI : 0);
		return alpha;
	}

	void VisualTree::DrawNode(Graphics^ g, Nullable<int> value, bool isMark, int centerX, int centerY)
	{
		if(value.HasValue)
		{
			auto strValue = (!value.HasValue) ? "null" : value.ToString();
			g->DrawEllipse(isMark ? Pens::Red : Pens::Black, Rectangle(centerX - Radius, centerY - Radius, Radius * 2, Radius * 2));

			auto textSize = TextRenderer::MeasureText(strValue, _font);
			g->DrawString(strValue, SystemFonts::IconTitleFont, gcnew SolidBrush(Color::Black), centerX - textSize.Width / 2, centerY - textSize.Height / 2);
		}
	}
}