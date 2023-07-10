#pragma once
#include<string>
#include<iostream>
#include<cliext/vector>
#include<cliext/algorithm>
using namespace cliext;
using namespace System::IO;
namespace forms11lab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ labelRow;
	private: System::Windows::Forms::Button^ buttonFill;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel;

	private: System::Windows::Forms::Label^ labelCol;
	private: System::Windows::Forms::TextBox^ textBoxCol;
	private: System::Windows::Forms::TextBox^ textBoxRow;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Label^ labelError;
	private: System::Windows::Forms::Label^ labelI;
	private: System::Windows::Forms::TextBox^ textBoxJ;

	private: System::Windows::Forms::Label^ labelJ;
	private: System::Windows::Forms::TextBox^ textBoxI;
	private: System::Windows::Forms::Label^ labelValueIs;
	private: System::Windows::Forms::Label^ labelValue;
	private: System::Windows::Forms::Button^ buttonEnter;
	private: System::Windows::Forms::Button^ buttonSetValue;
	private: System::Windows::Forms::TextBox^ textBoxNewValue;
	private: System::Windows::Forms::Label^ labelNewValue;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readToolStripMenuItemRead;

	private: System::Windows::Forms::ToolStripMenuItem^ writeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fillToolStripMenuItemFill;
	private: System::Windows::Forms::ToolStripMenuItem^ getValueToolStripMenuItemGet;
	private: System::Windows::Forms::ToolStripMenuItem^ setValueToolStripMenuItemSet;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItemClear;




	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialogFileName;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialogFile;


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStripTable;
	private: System::Windows::Forms::ToolStripMenuItem^ fillToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ getValueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setValueToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;












	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonSetValue = (gcnew System::Windows::Forms::Button());
			this->textBoxNewValue = (gcnew System::Windows::Forms::TextBox());
			this->labelNewValue = (gcnew System::Windows::Forms::Label());
			this->buttonEnter = (gcnew System::Windows::Forms::Button());
			this->labelValue = (gcnew System::Windows::Forms::Label());
			this->labelValueIs = (gcnew System::Windows::Forms::Label());
			this->textBoxJ = (gcnew System::Windows::Forms::TextBox());
			this->labelJ = (gcnew System::Windows::Forms::Label());
			this->textBoxI = (gcnew System::Windows::Forms::TextBox());
			this->labelI = (gcnew System::Windows::Forms::Label());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->textBoxCol = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRow = (gcnew System::Windows::Forms::TextBox());
			this->labelCol = (gcnew System::Windows::Forms::Label());
			this->labelRow = (gcnew System::Windows::Forms::Label());
			this->buttonFill = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readToolStripMenuItemRead = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->writeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillToolStripMenuItemFill = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getValueToolStripMenuItemGet = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setValueToolStripMenuItemSet = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItemClear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialogFileName = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialogFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->contextMenuStripTable = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->fillToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->getValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setValueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->contextMenuStripTable->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Controls->Add(this->buttonSetValue);
			this->panel1->Controls->Add(this->textBoxNewValue);
			this->panel1->Controls->Add(this->labelNewValue);
			this->panel1->Controls->Add(this->buttonEnter);
			this->panel1->Controls->Add(this->labelValue);
			this->panel1->Controls->Add(this->labelValueIs);
			this->panel1->Controls->Add(this->textBoxJ);
			this->panel1->Controls->Add(this->labelJ);
			this->panel1->Controls->Add(this->textBoxI);
			this->panel1->Controls->Add(this->labelI);
			this->panel1->Controls->Add(this->labelError);
			this->panel1->Controls->Add(this->buttonClear);
			this->panel1->Controls->Add(this->textBoxCol);
			this->panel1->Controls->Add(this->textBoxRow);
			this->panel1->Controls->Add(this->labelCol);
			this->panel1->Controls->Add(this->labelRow);
			this->panel1->Controls->Add(this->buttonFill);
			this->panel1->Location = System::Drawing::Point(447, 26);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(213, 411);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// buttonSetValue
			// 
			this->buttonSetValue->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonSetValue->Location = System::Drawing::Point(105, 212);
			this->buttonSetValue->Name = L"buttonSetValue";
			this->buttonSetValue->Size = System::Drawing::Size(75, 23);
			this->buttonSetValue->TabIndex = 16;
			this->buttonSetValue->Text = L"Set value";
			this->buttonSetValue->UseVisualStyleBackColor = false;
			this->buttonSetValue->Click += gcnew System::EventHandler(this, &Form1::buttonSetValue_Click);
			// 
			// textBoxNewValue
			// 
			this->textBoxNewValue->Location = System::Drawing::Point(77, 184);
			this->textBoxNewValue->Name = L"textBoxNewValue";
			this->textBoxNewValue->Size = System::Drawing::Size(52, 22);
			this->textBoxNewValue->TabIndex = 15;
			// 
			// labelNewValue
			// 
			this->labelNewValue->AutoSize = true;
			this->labelNewValue->Location = System::Drawing::Point(7, 187);
			this->labelNewValue->Name = L"labelNewValue";
			this->labelNewValue->Size = System::Drawing::Size(64, 14);
			this->labelNewValue->TabIndex = 14;
			this->labelNewValue->Text = L"New value";
			// 
			// buttonEnter
			// 
			this->buttonEnter->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonEnter->Location = System::Drawing::Point(15, 212);
			this->buttonEnter->Name = L"buttonEnter";
			this->buttonEnter->Size = System::Drawing::Size(75, 23);
			this->buttonEnter->TabIndex = 13;
			this->buttonEnter->Text = L"Get value";
			this->buttonEnter->UseVisualStyleBackColor = false;
			this->buttonEnter->Click += gcnew System::EventHandler(this, &Form1::buttonEnter_Click);
			// 
			// labelValue
			// 
			this->labelValue->AutoSize = true;
			this->labelValue->Location = System::Drawing::Point(169, 149);
			this->labelValue->Name = L"labelValue";
			this->labelValue->Size = System::Drawing::Size(0, 14);
			this->labelValue->TabIndex = 12;
			// 
			// labelValueIs
			// 
			this->labelValueIs->AutoSize = true;
			this->labelValueIs->Location = System::Drawing::Point(113, 149);
			this->labelValueIs->Name = L"labelValueIs";
			this->labelValueIs->Size = System::Drawing::Size(49, 14);
			this->labelValueIs->TabIndex = 11;
			this->labelValueIs->Text = L"value is";
			// 
			// textBoxJ
			// 
			this->textBoxJ->Location = System::Drawing::Point(79, 146);
			this->textBoxJ->Name = L"textBoxJ";
			this->textBoxJ->Size = System::Drawing::Size(28, 22);
			this->textBoxJ->TabIndex = 10;
			this->textBoxJ->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// labelJ
			// 
			this->labelJ->AutoSize = true;
			this->labelJ->Location = System::Drawing::Point(59, 149);
			this->labelJ->Name = L"labelJ";
			this->labelJ->Size = System::Drawing::Size(18, 14);
			this->labelJ->TabIndex = 9;
			this->labelJ->Text = L"j=";
			this->labelJ->Click += gcnew System::EventHandler(this, &Form1::label1_Click_3);
			// 
			// textBoxI
			// 
			this->textBoxI->Location = System::Drawing::Point(27, 146);
			this->textBoxI->Name = L"textBoxI";
			this->textBoxI->Size = System::Drawing::Size(28, 22);
			this->textBoxI->TabIndex = 8;
			// 
			// labelI
			// 
			this->labelI->AutoSize = true;
			this->labelI->Location = System::Drawing::Point(7, 149);
			this->labelI->Name = L"labelI";
			this->labelI->Size = System::Drawing::Size(18, 14);
			this->labelI->TabIndex = 7;
			this->labelI->Text = L"i=";
			this->labelI->Click += gcnew System::EventHandler(this, &Form1::label1_Click_2);
			// 
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->Location = System::Drawing::Point(60, 7);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(10, 14);
			this->labelError->TabIndex = 6;
			this->labelError->Text = L" ";
			this->labelError->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonClear->Location = System::Drawing::Point(127, 95);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 5;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// textBoxCol
			// 
			this->textBoxCol->Location = System::Drawing::Point(127, 57);
			this->textBoxCol->Name = L"textBoxCol";
			this->textBoxCol->Size = System::Drawing::Size(75, 22);
			this->textBoxCol->TabIndex = 4;
			this->textBoxCol->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxCol_TextChanged);
			// 
			// textBoxRow
			// 
			this->textBoxRow->Location = System::Drawing::Point(15, 57);
			this->textBoxRow->Name = L"textBoxRow";
			this->textBoxRow->Size = System::Drawing::Size(75, 22);
			this->textBoxRow->TabIndex = 3;
			this->textBoxRow->UseWaitCursor = true;
			this->textBoxRow->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxRow_TextChanged);
			// 
			// labelCol
			// 
			this->labelCol->AutoSize = true;
			this->labelCol->Location = System::Drawing::Point(135, 40);
			this->labelCol->Name = L"labelCol";
			this->labelCol->Size = System::Drawing::Size(56, 14);
			this->labelCol->TabIndex = 2;
			this->labelCol->Text = L"Columns";
			this->labelCol->Click += gcnew System::EventHandler(this, &Form1::labelCol_Click);
			// 
			// labelRow
			// 
			this->labelRow->AutoSize = true;
			this->labelRow->Location = System::Drawing::Point(33, 40);
			this->labelRow->Name = L"labelRow";
			this->labelRow->Size = System::Drawing::Size(37, 14);
			this->labelRow->TabIndex = 1;
			this->labelRow->Text = L"Rows";
			this->labelRow->Click += gcnew System::EventHandler(this, &Form1::labelRow_Click);
			// 
			// buttonFill
			// 
			this->buttonFill->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->buttonFill->Location = System::Drawing::Point(15, 95);
			this->buttonFill->Name = L"buttonFill";
			this->buttonFill->Size = System::Drawing::Size(75, 23);
			this->buttonFill->TabIndex = 0;
			this->buttonFill->Text = L"Fill";
			this->buttonFill->UseVisualStyleBackColor = false;
			this->buttonFill->Click += gcnew System::EventHandler(this, &Form1::buttonFill_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Controls->Add(this->tableLayoutPanel);
			this->panel2->Location = System::Drawing::Point(0, 26);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(420, 411);
			this->panel2->TabIndex = 2;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel2_Paint);
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->AutoScroll = true;
			this->tableLayoutPanel->AutoSize = true;
			this->tableLayoutPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tableLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->tableLayoutPanel->ColumnCount = 10;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				30)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				84)));
			this->tableLayoutPanel->Location = System::Drawing::Point(28, 45);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 10;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel->Size = System::Drawing::Size(376, 322);
			this->tableLayoutPanel->TabIndex = 0;
			this->tableLayoutPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tableLayoutPanel_Paint);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->tableToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(662, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->readToolStripMenuItemRead,
					this->writeToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem_Click);
			// 
			// readToolStripMenuItemRead
			// 
			this->readToolStripMenuItemRead->Name = L"readToolStripMenuItemRead";
			this->readToolStripMenuItemRead->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->readToolStripMenuItemRead->Size = System::Drawing::Size(147, 22);
			this->readToolStripMenuItemRead->Text = L"Read";
			this->readToolStripMenuItemRead->Click += gcnew System::EventHandler(this, &Form1::readToolStripMenuItem_Click);
			// 
			// writeToolStripMenuItem
			// 
			this->writeToolStripMenuItem->Name = L"writeToolStripMenuItem";
			this->writeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->writeToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->writeToolStripMenuItem->Text = L"Write";
			this->writeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::writeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// tableToolStripMenuItem
			// 
			this->tableToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fillToolStripMenuItemFill,
					this->getValueToolStripMenuItemGet, this->setValueToolStripMenuItemSet, this->clearToolStripMenuItemClear
			});
			this->tableToolStripMenuItem->Name = L"tableToolStripMenuItem";
			this->tableToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->tableToolStripMenuItem->Text = L"Table";
			this->tableToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::tableToolStripMenuItem_Click);
			// 
			// fillToolStripMenuItemFill
			// 
			this->fillToolStripMenuItemFill->Name = L"fillToolStripMenuItemFill";
			this->fillToolStripMenuItemFill->Size = System::Drawing::Size(123, 22);
			this->fillToolStripMenuItemFill->Text = L"Fill";
			this->fillToolStripMenuItemFill->Click += gcnew System::EventHandler(this, &Form1::fillToolStripMenuItem_Click);
			// 
			// getValueToolStripMenuItemGet
			// 
			this->getValueToolStripMenuItemGet->Name = L"getValueToolStripMenuItemGet";
			this->getValueToolStripMenuItemGet->Size = System::Drawing::Size(123, 22);
			this->getValueToolStripMenuItemGet->Text = L"Get value";
			this->getValueToolStripMenuItemGet->Click += gcnew System::EventHandler(this, &Form1::getValueToolStripMenuItem_Click);
			// 
			// setValueToolStripMenuItemSet
			// 
			this->setValueToolStripMenuItemSet->Name = L"setValueToolStripMenuItemSet";
			this->setValueToolStripMenuItemSet->Size = System::Drawing::Size(123, 22);
			this->setValueToolStripMenuItemSet->Text = L"Set value";
			this->setValueToolStripMenuItemSet->Click += gcnew System::EventHandler(this, &Form1::setValueToolStripMenuItem_Click);
			// 
			// clearToolStripMenuItemClear
			// 
			this->clearToolStripMenuItemClear->Name = L"clearToolStripMenuItemClear";
			this->clearToolStripMenuItemClear->Size = System::Drawing::Size(123, 22);
			this->clearToolStripMenuItemClear->Text = L"Clear";
			this->clearToolStripMenuItemClear->Click += gcnew System::EventHandler(this, &Form1::clearToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::helpToolStripMenuItem_Click);
			// 
			// openFileDialogFileName
			// 
			this->openFileDialogFileName->FileName = L"3.txt";
			this->openFileDialogFileName->InitialDirectory = L"D:\\користувач\\Документи\\моє\\політех\\2_sem\\лаби\\oop\\forms_11lab";
			this->openFileDialogFileName->Title = L"Choose file name";
			// 
			// contextMenuStripTable
			// 
			this->contextMenuStripTable->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fillToolStripMenuItem,
					this->clearToolStripMenuItem, this->getValueToolStripMenuItem, this->setValueToolStripMenuItem
			});
			this->contextMenuStripTable->Name = L"contextMenuStripTable";
			this->contextMenuStripTable->Size = System::Drawing::Size(124, 92);
			this->contextMenuStripTable->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::contextMenuStripTable_Opening);
			// 
			// fillToolStripMenuItem
			// 
			this->fillToolStripMenuItem->Name = L"fillToolStripMenuItem";
			this->fillToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->fillToolStripMenuItem->Text = L"Fill";
			this->fillToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fillToolStripMenuItem_Click_1);
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->clearToolStripMenuItem->Text = L"Clear";
			// 
			// getValueToolStripMenuItem
			// 
			this->getValueToolStripMenuItem->Name = L"getValueToolStripMenuItem";
			this->getValueToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->getValueToolStripMenuItem->Text = L"Get value";
			// 
			// setValueToolStripMenuItem
			// 
			this->setValueToolStripMenuItem->Name = L"setValueToolStripMenuItem";
			this->setValueToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->setValueToolStripMenuItem->Text = L"Set value";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(662, 439);
			this->ContextMenuStrip = this->contextMenuStripTable;
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"Form1";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Text = L"Main Form";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStripTable->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		fillToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::buttonFill_Click);
		clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
		getValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::buttonEnter_Click);
		setValueToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::buttonSetValue_Click);
	}
	private: System::Void buttonFill_Click(System::Object^ sender, System::EventArgs^ e) {
		tableLayoutPanel->Visible = false;
		if (Convert::ToInt64(textBoxRow->Text) > 10 || Convert::ToInt64(textBoxCol->Text) > 10) {
			labelError->Text = "Max quantity of \nrow or cols is 10";
			tableLayoutPanel->RowCount = 3;
			tableLayoutPanel->ColumnCount = 3;
		}
		else if (Convert::ToInt64(textBoxRow->Text) < 3 || Convert::ToInt64(textBoxCol->Text) < 3) {
			labelError->Text = "Min quantity of \nrow or cols is 3";
			tableLayoutPanel->RowCount = 3;
			tableLayoutPanel->ColumnCount = 3;
		}
		else if (Convert::ToInt64(textBoxRow->Text) != Convert::ToInt64(textBoxCol->Text)) {
			labelError->Text = "Quantity of rows and cols \nmust be the same";
		}
		else {
			labelError->Text = "";
			tableLayoutPanel->RowCount = Convert::ToInt64(textBoxRow->Text);
			tableLayoutPanel->ColumnCount = Convert::ToInt64(textBoxCol->Text);
		}
		labelsForMatrix.resize(this->tableLayoutPanel->RowCount);
		for (auto it = labelsForMatrix.begin(); it != labelsForMatrix.end(); ++it) {
			*it = gcnew vector<Label^>();
			(*it)->resize(this->tableLayoutPanel->ColumnCount);
			for (auto it1 = (*it)->begin(); it1 != (*it)->end(); ++it1) {
				*it1 = gcnew Label();
			}
		}
		for (int i = 0; i < this->tableLayoutPanel->RowCount; i++) {
			for (int j = 0; j < this->tableLayoutPanel->ColumnCount; j++) {
				(*(labelsForMatrix[i]))[j]->Text = "0";
				(*(labelsForMatrix[i]))[j]->Location = System::Drawing::Point(0, 0);
				this->tableLayoutPanel->Controls->Add((*(labelsForMatrix[i]))[j], i, j);
			}
		}
		for (int i = 0; i < this->tableLayoutPanel->RowCount /2; i++) {
			for (int j = i; j < this->tableLayoutPanel->ColumnCount -i; j++) {
				(*(labelsForMatrix[j]))[i]->Text = "1";
			}
		}
		for (int i = this->tableLayoutPanel->RowCount / 2; i < this->tableLayoutPanel->RowCount; i++) {
			for (int j = this->tableLayoutPanel->ColumnCount-i-1; j <= i; j++) {
				(*(labelsForMatrix[j]))[i]->Text = "1";
			}
		}
		tableLayoutPanel->Visible = true;
	}
private: vector<vector<Label^>^> labelsForMatrix;
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void labelRow_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxRow_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanel->Visible = false;
	tableLayoutPanel->Controls->Clear();
	tableLayoutPanel->Visible = true;
}
private: System::Void textBoxCol_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void labelCol_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_3(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonEnter_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = Convert::ToInt64(textBoxI->Text), j = Convert::ToInt64(textBoxJ->Text);
	labelValue->Text = (*(labelsForMatrix[i]))[j]->Text;
}
private: System::Void buttonSetValue_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = Convert::ToInt64(textBoxI->Text), j = Convert::ToInt64(textBoxJ->Text);
	(*(labelsForMatrix[i]))[j]->Text = textBoxNewValue->Text;
}
private: System::Void fillToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanel->Visible = false;
	if (Convert::ToInt64(textBoxRow->Text) > 10 || Convert::ToInt64(textBoxCol->Text) > 10) {
		labelError->Text = "Max quantity of \nrow or cols is 10";
		tableLayoutPanel->RowCount = 3;
		tableLayoutPanel->ColumnCount = 3;
	}
	else if (Convert::ToInt64(textBoxRow->Text) < 3 || Convert::ToInt64(textBoxCol->Text) < 3) {
		labelError->Text = "Min quantity of \nrow or cols is 3";
		tableLayoutPanel->RowCount = 3;
		tableLayoutPanel->ColumnCount = 3;
	}
	else {
		labelError->Text = "";
		tableLayoutPanel->RowCount = Convert::ToInt64(textBoxRow->Text);
		tableLayoutPanel->ColumnCount = Convert::ToInt64(textBoxCol->Text);
	}
	labelsForMatrix.resize(this->tableLayoutPanel->RowCount);
	for (auto it = labelsForMatrix.begin(); it != labelsForMatrix.end(); ++it) {
		*it = gcnew vector<Label^>();
		(*it)->resize(this->tableLayoutPanel->ColumnCount);
		for (auto it1 = (*it)->begin(); it1 != (*it)->end(); ++it1) {
			*it1 = gcnew Label();
		}
	}
	for (int i = 0; i < this->tableLayoutPanel->RowCount; i++) {
		for (int j = 0; j < this->tableLayoutPanel->ColumnCount; j++) {
			(*(labelsForMatrix[i]))[j]->Text = "0";
			(*(labelsForMatrix[i]))[j]->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Controls->Add((*(labelsForMatrix[i]))[j], i, j);
		}
	}
	for (int i = 0; i < this->tableLayoutPanel->RowCount / 2; i++) {
		for (int j = i; j < this->tableLayoutPanel->ColumnCount - i; j++) {
			(*(labelsForMatrix[j]))[i]->Text = "1";
		}
	}
	for (int i = this->tableLayoutPanel->RowCount / 2; i < this->tableLayoutPanel->RowCount; i++) {
		for (int j = this->tableLayoutPanel->ColumnCount - i - 1; j <= i; j++) {
			(*(labelsForMatrix[j]))[i]->Text = "1";
		}
	}
	tableLayoutPanel->Visible = true;
}
private: System::Void getValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = Convert::ToInt64(textBoxI->Text), j = Convert::ToInt64(textBoxJ->Text);
	labelValue->Text = (*(labelsForMatrix[i]))[j]->Text;
}
private: System::Void setValueToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = Convert::ToInt64(textBoxI->Text), j = Convert::ToInt64(textBoxJ->Text);
	(*(labelsForMatrix[i]))[j]->Text = textBoxNewValue->Text;
}
private: System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	tableLayoutPanel->Visible = false;
	tableLayoutPanel->Controls->Clear();
	tableLayoutPanel->Visible = true;
}
private: System::Void readToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ MyStream;
	OpenFileDialog^ openFileDilogFileName = gcnew OpenFileDialog;
	openFileDialogFileName->InitialDirectory = "D:\\користувач\\Документи\\моє\\політех\\2_sem\\лаби\\oop\\forms_11lab\\";
	openFileDialogFileName->FilterIndex = 2;
	openFileDialogFileName->RestoreDirectory = true;
	if (openFileDialogFileName->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if ((MyStream = openFileDialogFileName->OpenFile()) != nullptr) {
			MyStream->Close();
		}
	}
	if (System::Windows::Forms::DialogResult::OK != openFileDialogFileName->ShowDialog()) return;
	StreamReader^ sr = gcnew StreamReader(openFileDialogFileName->FileName);
	String^ line = sr->ReadLine();
	tableLayoutPanel->Visible = false;
	tableLayoutPanel->RowCount = (Convert::ToInt64(line));
	tableLayoutPanel->ColumnCount = (Convert::ToInt64(line));
	labelsForMatrix.resize(this->tableLayoutPanel->RowCount);
	for (auto it = labelsForMatrix.begin(); it != labelsForMatrix.end(); ++it) {
		*it = gcnew vector<Label^>();
		(*it)->resize(this->tableLayoutPanel->ColumnCount);
		for (auto it1 = (*it)->begin(); it1 != (*it)->end(); ++it1) {
			*it1 = gcnew Label();
		}
	}
	for (int i = 0; i < this->tableLayoutPanel->RowCount; i++) {
		line = sr->ReadLine();
		for (int j = 0; j < this->tableLayoutPanel->ColumnCount; j++) {
			(*(labelsForMatrix[j]))[i]->Text = (Convert::ToString(line[j]));
			(*(labelsForMatrix[j]))[i]->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->Controls->Add((*(labelsForMatrix[j]))[i], j, i);
		}
	}
	tableLayoutPanel->Visible = true;
	sr->Close();
}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxFileName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_4(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonFileName_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	exit(0);
}
private: System::Void writeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ MyStream;
	SaveFileDialog^ saveFileDialogFile = gcnew SaveFileDialog;
	saveFileDialogFile->InitialDirectory= "D:\\користувач\\Документи\\моє\\політех\\2_sem\\лаби\\oop\\forms_11lab\\";
	saveFileDialogFile->RestoreDirectory = true;
	if (saveFileDialogFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if ((MyStream = saveFileDialogFile->OpenFile()) != nullptr) {
			MyStream->Close();
		}
	}
	if (System::Windows::Forms::DialogResult::OK != saveFileDialogFile->ShowDialog()) return;
	StreamWriter^ sr = gcnew StreamWriter(saveFileDialogFile->FileName);
	String^ temp = Convert::ToString(tableLayoutPanel->RowCount);
	sr->Write(temp);
	sr->Write(" ");
	temp = Convert::ToString(tableLayoutPanel->RowCount);
	sr->Write(temp);
	sr->Write("\n");
	for (int i = 0; i < this->tableLayoutPanel->RowCount; i++) {
		for (int j = 0; j < this->tableLayoutPanel->ColumnCount; j++) {
			sr->Write((*(labelsForMatrix[j]))[i]->Text);
		}
		sr->Write("\n");
	}
	sr->Close();
}
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("This program helps you to create a table with some patern", "About", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);

}
private: System::Void tableToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void fillToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void contextMenuStripTable_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
};
}