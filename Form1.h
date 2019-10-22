#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Threading::Tasks;
namespace TreeVisualizer { ref class Tree; }
namespace TreeVisualizer { ref class VisualTree; }

namespace TreeVisualizer
{
	public ref class Form1 : System::Windows::Forms::Form
	{

	private:
		Tree^ tree;
		initonly VisualTree^ visualTree;

	public:
		Form1();

	public:
		virtual ~Form1()
		{
			this->DisposeObject(true);
		}

	private protected:
		!Form1()
		{
			this->DisposeObject(false);
		}

	private:
		Rectangle ResizePanel();

		void addButton_Click(Object^ sender, EventArgs^ e);

		void treePanel_Paint(Object^ sender, PaintEventArgs^ e);

		void searchButton_Click(Object^ sender, EventArgs^ e);

		void removeButton_Click(Object^ sender, EventArgs^ e);

		void clearButton_Click(Object^ sender, EventArgs^ e);


		System::ComponentModel::IContainer^ components = nullptr;

		
		void DisposeObject(bool disposing);

#pragma region Windows Form Designer generated code

		void InitializeComponent();

#pragma endregion

		System::Windows::Forms::Panel^ treePanel;
		System::Windows::Forms::TextBox^ nodeTextBox;
		System::Windows::Forms::Button^ addButton;
		System::Windows::Forms::Button^ searchButton;
		System::Windows::Forms::BindingSource^ bindingSource1;
		System::Windows::Forms::Button^ removeButton;
		System::Windows::Forms::Button^ clearButton;
	};
}

