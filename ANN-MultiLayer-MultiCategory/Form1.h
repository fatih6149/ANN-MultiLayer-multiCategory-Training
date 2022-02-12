#pragma once
#include "Process.h"
#include "time.h"
#include "pch.h"
#include <iostream>
#include "Training_rules.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// User Defined Variables
		int  numClass = 0, numSample = 0, numHideNeur = 0, inputDim = 2;
		float* Samples, * targets;
		float* weights;
		float* Vweights;
		float* tmp_samples;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomlyToolStripMenuItem;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ continuousToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^ Normalize;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ hideNeurCountBox;



		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Erforderliche Methode für die Designerunterstützung.
		   /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->hideNeurCountBox = (gcnew System::Windows::Forms::ComboBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->initialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->randomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->continuousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->Normalize = (gcnew System::Windows::Forms::CheckBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->pictureBox1->Location = System::Drawing::Point(13, 35);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(800, 600);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			   this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->label9);
			   this->groupBox1->Controls->Add(this->hideNeurCountBox);
			   this->groupBox1->Controls->Add(this->button1);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->ClassCountBox);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->groupBox1->Location = System::Drawing::Point(844, 57);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(240, 141);
			   this->groupBox1->TabIndex = 1;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Network Architecture";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(112, 60);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(117, 13);
			   this->label9->TabIndex = 11;
			   this->label9->Text = L"Hide neural number";
			   // 
			   // hideNeurCountBox
			   // 
			   this->hideNeurCountBox->FormattingEnabled = true;
			   this->hideNeurCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				   L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					   L"8", L"9", L"10"
			   });
			   this->hideNeurCountBox->Location = System::Drawing::Point(10, 56);
			   this->hideNeurCountBox->Name = L"hideNeurCountBox";
			   this->hideNeurCountBox->Size = System::Drawing::Size(82, 21);
			   this->hideNeurCountBox->TabIndex = 3;
			   this->hideNeurCountBox->Text = L"1";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(10, 95);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(131, 33);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"Network Setting";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(112, 23);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(82, 13);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Class number";
			   // 
			   // ClassCountBox
			   // 
			   this->ClassCountBox->FormattingEnabled = true;
			   this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			   this->ClassCountBox->Location = System::Drawing::Point(10, 20);
			   this->ClassCountBox->Name = L"ClassCountBox";
			   this->ClassCountBox->Size = System::Drawing::Size(82, 21);
			   this->ClassCountBox->TabIndex = 0;
			   this->ClassCountBox->Text = L"2";
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->label2);
			   this->groupBox2->Controls->Add(this->ClassNoBox);
			   this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->groupBox2->Location = System::Drawing::Point(844, 228);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(190, 61);
			   this->groupBox2->TabIndex = 2;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Data Collection";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(98, 23);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(81, 13);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Örnek Etiketi";
			   // 
			   // ClassNoBox
			   // 
			   this->ClassNoBox->FormattingEnabled = true;
			   this->ClassNoBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				   L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					   L"9"
			   });
			   this->ClassNoBox->Location = System::Drawing::Point(7, 20);
			   this->ClassNoBox->Name = L"ClassNoBox";
			   this->ClassNoBox->Size = System::Drawing::Size(75, 21);
			   this->ClassNoBox->TabIndex = 0;
			   this->ClassNoBox->Text = L"1";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(841, 400);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(35, 13);
			   this->label3->TabIndex = 3;
			   this->label3->Text = L"label3";
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1173, 24);
			   this->menuStrip1->TabIndex = 4;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // processToolStripMenuItem
			   // 
			   this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->initialToolStripMenuItem,
					   this->trainingToolStripMenuItem, this->exitToolStripMenuItem
			   });
			   this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			   this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			   this->processToolStripMenuItem->Text = L"Process";
			   // 
			   // initialToolStripMenuItem
			   // 
			   this->initialToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomlyToolStripMenuItem });
			   this->initialToolStripMenuItem->Name = L"initialToolStripMenuItem";
			   this->initialToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			   this->initialToolStripMenuItem->Text = L"Initial";
			   // 
			   // randomlyToolStripMenuItem
			   // 
			   this->randomlyToolStripMenuItem->Name = L"randomlyToolStripMenuItem";
			   this->randomlyToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			   this->randomlyToolStripMenuItem->Text = L"Randomly";
			   this->randomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::randomlyToolStripMenuItem_Click);
			   // 
			   // trainingToolStripMenuItem
			   // 
			   this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->continuousToolStripMenuItem });
			   this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			   this->trainingToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			   this->trainingToolStripMenuItem->Text = L"Training";
			   // 
			   // continuousToolStripMenuItem
			   // 
			   this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			   this->continuousToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			   this->continuousToolStripMenuItem->Text = L"Continuous";
			   this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::continuousToolStripMenuItem_Click);
			   // 
			   // exitToolStripMenuItem
			   // 
			   this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			   this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			   this->exitToolStripMenuItem->Text = L"Exit";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(841, 427);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(35, 13);
			   this->label4->TabIndex = 5;
			   this->label4->Text = L"label4";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(841, 461);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(35, 13);
			   this->label5->TabIndex = 6;
			   this->label5->Text = L"label5";
			   // 
			   // Normalize
			   // 
			   this->Normalize->AutoSize = true;
			   this->Normalize->Location = System::Drawing::Point(844, 362);
			   this->Normalize->Name = L"Normalize";
			   this->Normalize->Size = System::Drawing::Size(72, 17);
			   this->Normalize->TabIndex = 7;
			   this->Normalize->Text = L"Normalize";
			   this->Normalize->UseVisualStyleBackColor = true;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(1013, 400);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(35, 13);
			   this->label6->TabIndex = 8;
			   this->label6->Text = L"label6";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(1013, 431);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(35, 13);
			   this->label7->TabIndex = 9;
			   this->label7->Text = L"label7";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(1013, 462);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(35, 13);
			   this->label8->TabIndex = 10;
			   this->label8->Text = L"label8";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1173, 633);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->label7);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->Normalize);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Form1";
			   this->Text = L"Form1";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (numClass == 0)
			MessageBox::Show("The Network Architeture should be firtly set up");
		else {
			float* x;
			x = new float[inputDim];
			int temp_x = (System::Convert::ToInt32(e->X));//* take X coordinate
			int temp_y = (System::Convert::ToInt32(e->Y));//* take Y coordinate

			x[0] = float(temp_x - (pictureBox1->Width / 2));//* trans the coordinates to center
			x[1] = float(pictureBox1->Height / 2 - temp_y);

			label3->Text = System::Convert::ToString(x[0]);
			label4->Text = System::Convert::ToString(x[1]);
			int label;
			int numLabel = Convert::ToInt32(ClassNoBox->Text);
			if (numLabel > numClass)
				MessageBox::Show("The class label cannot be greater than the maximum number of classes.");
			else {
				label = numLabel - 1; //Dögüler 0 dan baþladýðýndan, bir eksiði alýnmýþtýr
				if (numSample == 0) {
					numSample = 1;  Samples = new float[numSample * inputDim]; targets = new float[numSample];
					for (int i = 0; i < inputDim; i++)
						Samples[i] = x[i];
					targets[0] = float(label);
				}
				else {
					numSample++;
					Samples = Add_Data(Samples, numSample, x, inputDim);
					targets = Add_Labels(targets, numSample, label);

				}//else
				Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
				switch (label) {
				case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Pink, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
				default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
				}//switch
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
				label3->Text = "Samples Count: " + System::Convert::ToString(numSample) + " ==|| lables = " + label;
				label4->Text = "x1 = " + x[0] + "|||||| x2 : " + x[1];
			}//else of if (Etiket ...
		}//else
	}//pictureMouseClick
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//Ana eksen doðrularini cizdir
		Pen^ pen = gcnew Pen(Color::Black, 3.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Network is constructed
		numClass = Convert::ToInt32(ClassCountBox->Text);
		numHideNeur = Convert::ToInt32(hideNeurCountBox->Text);

		weights = new float[numClass * (numHideNeur + 1)];
		Vweights = new float[numHideNeur * (inputDim + 1)];

		button1->Text = " Network is Ready : ";
	}
		   
	private: System::Void randomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		srand(time(0));

		for (int label = 0; label < numClass; label++) {// initilize output neurons weights
			for (int i = 0; i < numHideNeur + 1; i++)
				weights[label * (numHideNeur + 1) + i] = ((double)rand()) / (RAND_MAX);
		}

		srand(time(0));
		for (int label = 0; label < numHideNeur; label++) {// initilize input neurons weights
			for (int i = 0; i < inputDim + 1; i++)
				Vweights[label * (inputDim + 1) + i] = ((double)rand()) / (RAND_MAX);

			label3->Text = " w[0]: " + System::Convert::ToString(weights[3 * label]);
			label4->Text = " w[1]: " + System::Convert::ToString(weights[3 * label + 1]);
			label5->Text = " w[2]: " + System::Convert::ToString(weights[3 * label + 2]);

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, &Vweights[3 * label]);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, &Vweights[3 * label]);

			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			switch (label) {
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}//Randomly

	private: System::Void continuousToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int samples_size = numSample * inputDim;
		normalize(Samples, samples_size);

		Pen^ pen = gcnew Pen(Color::Blue, 3.0f);

		int min_x, max_x, min_y, max_y;

		pictureBox1->Refresh();
		for (int i = 0; i < numSample; i++) {
			int temp_x = Convert::ToInt32(50 * Samples[i * inputDim] + (pictureBox1->Width >> 1));
			int temp_y = Convert::ToInt32((pictureBox1->Height >> 1) - 1 * (50) * Samples[i * inputDim + 1]);


			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			switch ((int)(targets[i])) {
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}

		float Error_max = 0.5;
		int count = 0;
		float Error;
		bool state = true;
		int bias = 1;

		int cycle = 0;
		do {
			cycle++;
			Error = delta_train(Samples, numSample, weights, bias, targets, numClass, inputDim, numHideNeur, Vweights);
			if (Error < Error_max)
				state = false;
		} while (state);
		label6->Text = " Cycle = " + System::Convert::ToString(cycle);

		for (int label = 0; label < numHideNeur; label++) {

			min_x = (this->pictureBox1->Width) / -2;
			min_y = YPoint(min_x, &Vweights[3 * label], 50);
			max_x = (this->pictureBox1->Width) / 2;
			max_y = YPoint(max_x, &Vweights[3 * label], 50);

			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			switch (label) {
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
		}
	}

	void normalize(float* samples, int size) {
		//for (int i = 0; i < size; i++)
		//	samples[i] /= (pictureBox1->Width);

		float sum_of_x1 = 0, sum_of_x2 = 0;
		float mean_of_x1, mean_of_x2;
		float* tmp_sample_x1 = new float[numSample];
		float* tmp_sample_x2 = new float[numSample];
		float sum_of_tmp_samples_x1 = 0, sum_of_tmp_samples_x2 = 0;
		float ss1, ss2;

		tmp_samples = new float[numSample * inputDim];
		////==================== mean of samples ======================

		for (int i = 0; i < numSample * inputDim; i++) {
			if (i % 2 == 0) {
				sum_of_x1 += samples[i];
			}
			else
			{
				sum_of_x2 += samples[i];
			}
		}
		mean_of_x1 = sum_of_x1 / numSample;
		mean_of_x2 = sum_of_x2 / numSample;
		//===========================================================

		//======================== standart sapma====================
		for (int i = 0; i < numSample * inputDim; i++) {
			if (i % 2 == 0) {
				tmp_sample_x1[i] = samples[i] - mean_of_x1;
				tmp_sample_x1[i] = tmp_sample_x1[i] * tmp_sample_x1[i];
			}
			else
			{
				tmp_sample_x2[i] = samples[i] - mean_of_x2;
				tmp_sample_x2[i] = tmp_sample_x2[i] * tmp_sample_x2[i];
			}
		}
		for (int i = 0; i < numSample * inputDim; i++) {
			if (i % 2 == 0) {
				sum_of_tmp_samples_x1 += tmp_sample_x1[i];
			}
			else
			{
				sum_of_tmp_samples_x2 += tmp_sample_x2[i];
			}
		}
		ss1 = sum_of_tmp_samples_x1 / (numSample);//(numSample - 1)
		ss1 = sqrt(ss1);
		ss2 = sum_of_tmp_samples_x2 / (numSample);
		ss2 = sqrt(ss2);
		//===========================================================

		float delete_var;
		//======================== Normalize data====================
		for (int i = 0; i < numSample * inputDim; i++) {
			if (i % 2 == 0) {// if x1
				samples[i] = (samples[i] - mean_of_x1) / ss1;
				delete_var = samples[i];
			}
			else
			{// if x2
				samples[i] = (samples[i] - mean_of_x2) / ss2;
				delete_var = samples[i];
			}
		}
		//===========================================================
		label5->Text = "x1 = " + mean_of_x1 + " |||| x2 = " + mean_of_x2;
	}
};
}