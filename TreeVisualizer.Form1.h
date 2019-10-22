#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Text;
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
		virtual ~Form1()
		{
			this->DisposeObject(true);
		}

	private protected:
		!Form1()
		{
			this->DisposeObject(false);
		}

	public:
		Form1();

	private:
		void addButton_Click(Object^ sender, EventArgs^ e);

		Rectangle ResizePanel();

		void treePanel_Paint(Object^ sender, PaintEventArgs^ e);

		void searchButton_Click(Object^ sender, EventArgs^ e);

		void removeButton_Click(Object^ sender, EventArgs^ e);

		void clearButton_Click(Object^ sender, EventArgs^ e);


		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::IContainer^ components = nullptr;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		void DisposeObject(bool disposing);

#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
