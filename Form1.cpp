#define _CRT_SECURE_NO_WARNINGS
#include "Form1.h"
#include "Tree.h"
#include "VisualTree.h"
#include "chrono"
#include <iostream>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
namespace ch = std::chrono;


namespace TreeVisualizer {
	Form1::Form1()
	{
		float time;
		time = clock();
		const auto t1 = ch::high_resolution_clock::now();
		InitializeComponent();
		tree = gcnew Tree();
		visualTree = gcnew VisualTree();
		nodeTextBox->Focus();
		const auto t2 = ch::high_resolution_clock::now();
		const auto dur = ch::duration_cast<ch::microseconds>(t2 - t1).count();
		std::cout << dur;
	}

	Rectangle Form1::ResizePanel()
	{
		auto size = visualTree->GetSize(tree);
		treePanel->Width = size.Width + 2;
		treePanel->Height = size.Height + 2;
		return Rectangle(Point(0, 0), size);
	}

	void Form1::treePanel_Paint(Object^ sender, PaintEventArgs^ e)
	{
		auto graphics = treePanel->CreateGraphics();
		auto rectangle = ResizePanel();

		visualTree->Draw(graphics, tree->Root, rectangle);
		nodeTextBox->Focus();
	}

	void Form1::addButton_Click(Object^ sender, EventArgs^ e)
	{
		int value = 0;
		if(nodeTextBox->Text == "")
		{
			return;
		}
		try
		{
			value = Int32::Parse(nodeTextBox->Text);
		}
		catch(Exception ^ e1)
		{
			MessageBox::Show("Wrong value");
			nodeTextBox->Text = "";
			return;
		}
		tree->Add(value);
		treePanel->Refresh();
		nodeTextBox->Text = "";
		nodeTextBox->Focus();
	}

	void Form1::searchButton_Click(Object^ sender, EventArgs^ e)
	{
		int value = 0;
		if(nodeTextBox->Text == "")
		{
			return;
		}
		try
		{
			value = Int32::Parse(nodeTextBox->Text);
		}
		catch(Exception ^ e1)
		{
			MessageBox::Show("Wrong value");
			nodeTextBox->Text = "";
			return;
		}
		tree->Search(value);
		treePanel->Refresh();
		//nodeTextBox->Text = "";
		nodeTextBox->Focus();
		tree->ClearMark();
	}

	void Form1::removeButton_Click(Object^ sender, EventArgs^ e)
	{
		int value = 0;
		if(nodeTextBox->Text == "")
		{
			return;
		}
		try
		{
			value = Int32::Parse(nodeTextBox->Text);
		}
		catch(Exception ^ e1)
		{
			MessageBox::Show("Wrong value");
			nodeTextBox->Text = "";
			return;
		}

		tree->Remove(value);
		treePanel->Refresh();
		nodeTextBox->Text = "";
		nodeTextBox->Focus();
	}

	void Form1::clearButton_Click(Object^ sender, EventArgs^ e)
	{
		tree = gcnew Tree();
		treePanel->Refresh();
	}

	void Form1::DisposeObject(bool disposing)
	{
		if(disposing && (components != nullptr))
		{
			delete components;
		}
	}

	void Form1::InitializeComponent()
	{
		this->components = gcnew System::ComponentModel::Container();
		this->treePanel = gcnew System::Windows::Forms::Panel();
		this->nodeTextBox = gcnew System::Windows::Forms::TextBox();
		this->addButton = gcnew System::Windows::Forms::Button();
		this->searchButton = gcnew System::Windows::Forms::Button();
		this->bindingSource1 = gcnew System::Windows::Forms::BindingSource(this->components);
		this->removeButton = gcnew System::Windows::Forms::Button();
		this->clearButton = gcnew System::Windows::Forms::Button();
		(safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
		this->SuspendLayout();
		//
		// Form1
		//
		this->AutoScaleDimensions = System::Drawing::SizeF(6.0F, 13.0F);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(800, 450);
		this->Name = "Form1";
		this->Text = "Binary Tree";
		this->Controls->Add(this->clearButton);
		this->Controls->Add(this->removeButton);
		this->Controls->Add(this->searchButton);
		this->Controls->Add(this->addButton);
		this->Controls->Add(this->nodeTextBox);
		this->Controls->Add(this->treePanel);
		//
		// treePanel
		//
		this->treePanel->Location = System::Drawing::Point(251, 12);
		this->treePanel->Name = "treePanel";
		this->treePanel->Size = System::Drawing::Size(537, 426);
		this->treePanel->TabIndex = 0;
		this->treePanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::treePanel_Paint);
		//
		// nodeTextBox
		//
		this->nodeTextBox->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 12.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (safe_cast<System::Byte>(204)));
		this->nodeTextBox->Location = System::Drawing::Point(78, 28);
		this->nodeTextBox->Name = "nodeTextBox";
		this->nodeTextBox->Size = System::Drawing::Size(98, 26);
		this->nodeTextBox->TabIndex = 1;
		//
		// addButton
		//
		this->addButton->Location = System::Drawing::Point(22, 74);
		this->addButton->Name = "addButton";
		this->addButton->Size = System::Drawing::Size(100, 33);
		this->addButton->TabIndex = 0;
		this->addButton->Text = "Добавить";
		this->addButton->UseVisualStyleBackColor = true;
		this->addButton->Click += gcnew System::EventHandler(this, &Form1::addButton_Click);
		//
		// searchButton
		//
		this->searchButton->Location = System::Drawing::Point(128, 74);
		this->searchButton->Name = "searchButton";
		this->searchButton->Size = System::Drawing::Size(100, 33);
		this->searchButton->TabIndex = 2;
		this->searchButton->Text = "Найти";
		this->searchButton->UseVisualStyleBackColor = true;
		this->searchButton->Click += gcnew System::EventHandler(this, &Form1::searchButton_Click);
		//
		// removeButton
		//
		this->removeButton->Location = System::Drawing::Point(22, 113);
		this->removeButton->Name = "removeButton";
		this->removeButton->Size = System::Drawing::Size(100, 33);
		this->removeButton->TabIndex = 3;
		this->removeButton->Text = "Удалить";
		this->removeButton->UseVisualStyleBackColor = true;
		this->removeButton->Click += gcnew System::EventHandler(this, &Form1::removeButton_Click);
		//
		// clearButton
		//
		this->clearButton->Location = System::Drawing::Point(128, 113);
		this->clearButton->Name = "clearButton";
		this->clearButton->Size = System::Drawing::Size(100, 33);
		this->clearButton->TabIndex = 4;
		this->clearButton->Text = "Очистить";
		this->clearButton->UseVisualStyleBackColor = true;
		this->clearButton->Click += gcnew System::EventHandler(this, &Form1::clearButton_Click);

		(safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();
	}
}