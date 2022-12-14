#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

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
	private: System::Windows::Forms::Button^ calculateButton;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// User Defined Variables
		int  numClass = 0, numSample = 0, inputDim = 2, weightCount = 0, KacDongu = 0, currentClass = 0;
		float* Samples, * targets, * Weights, * bias, * normalizedSamples, error = 2, * fakeTargets, * finalWeights, * finalBias;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveDataToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::RadioButton^ PerceptronButton;

	private: System::Windows::Forms::RadioButton^ Deltabutton;
	private: System::Windows::Forms::GroupBox^ learningMethodBox;
	private: System::Windows::Forms::CheckBox^ checkBox1;



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
			   this->learningMethodBox = (gcnew System::Windows::Forms::GroupBox());
			   this->Deltabutton = (gcnew System::Windows::Forms::RadioButton());
			   this->PerceptronButton = (gcnew System::Windows::Forms::RadioButton());
			   this->calculateButton = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->learningMethodBox->SuspendLayout();
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
			   this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			   this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->learningMethodBox);
			   this->groupBox1->Controls->Add(this->calculateButton);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->ClassCountBox);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->groupBox1->Location = System::Drawing::Point(869, 50);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(189, 152);
			   this->groupBox1->TabIndex = 1;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Network Architecture";
			   this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			   // 
			   // learningMethodBox
			   // 
			   this->learningMethodBox->Controls->Add(this->Deltabutton);
			   this->learningMethodBox->Controls->Add(this->PerceptronButton);
			   this->learningMethodBox->Location = System::Drawing::Point(10, 46);
			   this->learningMethodBox->Margin = System::Windows::Forms::Padding(2);
			   this->learningMethodBox->Name = L"learningMethodBox";
			   this->learningMethodBox->Padding = System::Windows::Forms::Padding(2);
			   this->learningMethodBox->Size = System::Drawing::Size(173, 62);
			   this->learningMethodBox->TabIndex = 8;
			   this->learningMethodBox->TabStop = false;
			   this->learningMethodBox->Text = L"Learning method to use:";
			   this->learningMethodBox->Enter += gcnew System::EventHandler(this, &Form1::learningMethodBox_Enter);
			   // 
			   // Deltabutton
			   // 
			   this->Deltabutton->AutoSize = true;
			   this->Deltabutton->Location = System::Drawing::Point(111, 26);
			   this->Deltabutton->Margin = System::Windows::Forms::Padding(2);
			   this->Deltabutton->Name = L"Deltabutton";
			   this->Deltabutton->Size = System::Drawing::Size(55, 17);
			   this->Deltabutton->TabIndex = 7;
			   this->Deltabutton->Text = L"Delta";
			   this->Deltabutton->UseVisualStyleBackColor = true;
			   this->Deltabutton->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			   // 
			   // PerceptronButton
			   // 
			   this->PerceptronButton->AutoSize = true;
			   this->PerceptronButton->Checked = true;
			   this->PerceptronButton->Location = System::Drawing::Point(20, 26);
			   this->PerceptronButton->Margin = System::Windows::Forms::Padding(2);
			   this->PerceptronButton->Name = L"PerceptronButton";
			   this->PerceptronButton->Size = System::Drawing::Size(87, 17);
			   this->PerceptronButton->TabIndex = 6;
			   this->PerceptronButton->TabStop = true;
			   this->PerceptronButton->Text = L"Perceptron";
			   this->PerceptronButton->UseVisualStyleBackColor = true;
			   this->PerceptronButton->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			   // 
			   // calculateButton
			   // 
			   this->calculateButton->Enabled = false;
			   this->calculateButton->Location = System::Drawing::Point(30, 113);
			   this->calculateButton->Name = L"calculateButton";
			   this->calculateButton->Size = System::Drawing::Size(131, 33);
			   this->calculateButton->TabIndex = 2;
			   this->calculateButton->Text = L"Select class count";
			   this->calculateButton->UseVisualStyleBackColor = true;
			   this->calculateButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(165, 23);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(0, 13);
			   this->label1->TabIndex = 1;
			   this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			   // 
			   // ClassCountBox
			   // 
			   this->ClassCountBox->FormattingEnabled = true;
			   this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			   this->ClassCountBox->Location = System::Drawing::Point(10, 20);
			   this->ClassCountBox->Name = L"ClassCountBox";
			   this->ClassCountBox->Size = System::Drawing::Size(173, 21);
			   this->ClassCountBox->TabIndex = 0;
			   this->ClassCountBox->Text = L"Select class count";
			   this->ClassCountBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ClassCountBox_SelectedIndexChanged);
			   this->ClassCountBox->DropDownClosed += gcnew System::EventHandler(this, &Form1::ClassCountBox_DropDownClosed);
			   this->ClassCountBox->TextChanged += gcnew System::EventHandler(this, &Form1::ClassCountBox_TextChanged);
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->label2);
			   this->groupBox2->Controls->Add(this->ClassNoBox);
			   this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->groupBox2->Location = System::Drawing::Point(879, 217);
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
			   this->label3->Location = System::Drawing::Point(1081, 298);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(35, 13);
			   this->label3->TabIndex = 3;
			   this->label3->Text = L"label3";
			   this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1443, 24);
			   this->menuStrip1->TabIndex = 4;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->readDataToolStripMenuItem,
					   this->saveDataToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // readDataToolStripMenuItem
			   // 
			   this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			   this->readDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			   this->readDataToolStripMenuItem->Text = L"Read_Data";
			   this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			   // 
			   // saveDataToolStripMenuItem
			   // 
			   this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			   this->saveDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			   this->saveDataToolStripMenuItem->Text = L"Save_Data";
			   this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Enabled = false;
			   this->textBox1->Location = System::Drawing::Point(869, 324);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(247, 258);
			   this->textBox1->TabIndex = 5;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			   this->checkBox1->Location = System::Drawing::Point(869, 298);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(101, 17);
			   this->checkBox1->TabIndex = 6;
			   this->checkBox1->Text = L"Agirliklari Goster";
			   this->checkBox1->UseVisualStyleBackColor = false;
			   this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1443, 633);
			   this->Controls->Add(this->checkBox1);
			   this->Controls->Add(this->textBox1);
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
			   this->learningMethodBox->ResumeLayout(false);
			   this->learningMethodBox->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
	private:float netHesaplaSingle(int index, bool normalized) {
		float output = 0;
		for (int i = 0; i < inputDim; i++) {
			if (normalized == true) {
				output += Weights[i] * normalizedSamples[index * inputDim + i];
			}
			else {
				output += Weights[i] * Samples[index * inputDim + i];
			}

		}
		output += bias[0];
		return output;
	}
	private:int unitStepFunc(float net) {
		if (net < 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	private:void agirlikGuncelle(float delta, int index, bool normalization) {
		if (checkBox1->Checked) {
			textBox1->AppendText("w1 w2 bias " + Weights[0] + " " + Weights[1] + "  " + bias[0] + "\r\n");
		}
		KacDongu++;
		for (int i = 0; i < weightCount; i++) {

			if (normalization == true) {
				Weights[i] += delta * normalizedSamples[index * inputDim + i];
			}
			else {
				Weights[i] += delta * Samples[index * inputDim + i];
			}

		}
		bias[0] += delta * 1; //bias'i X'i 1 olan ekstra bir sample'in agirligi gibi tutuyoruz
	}
	private:void Perceptron(float* targets) {
		bool allIsWell = false;
		while (!allIsWell) {
			allIsWell = true;

			for (int i = 0; i < numSample; i++) {
				int output = unitStepFunc(netHesaplaSingle(i, false));
				int delta = targets[i] - output;
				if (delta != 0) {
					allIsWell = false;
					agirlikGuncelle(delta, i, false);

				}
			}
		}
		LineCiz(Weights, bias, 2, 1);

	}
	private:void normalizeEt() {
		for (int i = 0; i < numSample * 2; i++) {
			if (i % 2 != 0) {
				normalizedSamples[i] = (Samples[i] + 300) / 600; //y ekseni
			}
			else {
				normalizedSamples[i] = (Samples[i] + 400) / 800; //x ekseni icin
			}
		}

	}
	private:float sigmoidDelta(float net) {
		int lambda = 1;
		return (float)1 / (1 + Math::Exp(-lambda * net));
	}
	private:float turevSigmoid(float net) {
		return (float)sigmoidDelta(net) * (1 - sigmoidDelta(net));
	}


	private:void Delta(float* targets) {
		float epsilon = 0.1;
		error = 2;
		normalizeEt();
		while (error > epsilon) {
			error = 0;
			for (int i = 0; i < numSample; i++) {
				float output = sigmoidDelta(netHesaplaSingle(i, true));
				float delta = (targets[i] - output) * turevSigmoid(netHesaplaSingle(i, true));
				error += (float)0.5 * (targets[i] - output) * (targets[i] - output);
				agirlikGuncelle(delta, i, true);
			}
		}
		LineCiz(Weights, bias, 2, 1);


	}

		   void  LineCiz(float* w, float* bias, int NumberOfClass, float Carpan) {
			   textBox1->AppendText(KacDongu + " kere dondu \r\n");
			   int x1, x2, y1, y2;
			   Pen^ pen;
			   float ww[2]; //inputDim=2



			   switch (currentClass) {
			   case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			   case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			   case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			   case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			   case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			   case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			   default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			   }//switch
			   ww[0] = w[0];
			   ww[1] = w[1];
			   x1 = -pictureBox1->Width / 2;     y1 = YPoint(x1, ww, bias[0], Carpan);
			   x1 += pictureBox1->Width / 2;     y1 = pictureBox1->Height / 2 - y1;
			   x2 = pictureBox1->Width / 2;      y2 = YPoint(x2, ww, bias[0], Carpan);
			   x2 += pictureBox1->Width / 2;   y2 = pictureBox1->Height / 2 - y2;

			   pictureBox1->CreateGraphics()->DrawLine(pen, x1, y1, x2, y2);

		   }//LineCÝz
		   void draw_sample(int temp_x, int temp_y, int label) {
			   Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			   switch (label) {
			   case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			   case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			   case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			   case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			   case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			   case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			   default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			   }//switch
			   pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			   pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		   }//draw_sample
#pragma endregion
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (numClass == 0)
			MessageBox::Show("The Network Architeture should be firtly set up");
		else {
			float* x;
			x = new float[inputDim];
			int temp_x = (System::Convert::ToInt32(e->X));
			int temp_y = (System::Convert::ToInt32(e->Y));

			x[0] = float(temp_x - (pictureBox1->Width / 2));
			x[1] = float(pictureBox1->Height / 2 - temp_y);
			int label;
			int numLabel = Convert::ToInt32(ClassNoBox->Text);
			if (numLabel > numClass)
				MessageBox::Show("The class label cannot be greater than the maximum number of classes.");
			else {
				label = numLabel - 1; //Dögüler 0 dan baþladýðýndan, bir eksiði alýnmýþtýr
				if (numSample == 0) { //Dinamik alýnan ilk örnek için sadece
					numSample = 1;
					Samples = new float[numSample * inputDim];
					targets = new float[numSample];
					fakeTargets = new float[numSample];
					normalizedSamples = new float[numSample * inputDim];
					for (int i = 0; i < inputDim; i++)
						Samples[i] = x[i];
					targets[0] = float(label);
					fakeTargets[0] = float(label);
				}
				else {
					numSample++;
					Samples = Add_Data(Samples, numSample, x, inputDim);
					targets = Add_Labels(targets, numSample, label);

				}//else
				draw_sample(temp_x, temp_y, label);
				label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
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
		Weights = new float[inputDim];
		bias = new float[numClass];
		finalBias = new float[numClass];
		//initialize weights for single layer
		// 2 den fazla class'imiz yoksa inputDim (2) adet agirlik olmasi yeterli
		// Ama eger multiclass calisiyorsak, katmandaki her class icin ayri agirliklar olacagi icin numClass * inputDim (x1 ve x2 icin) kadar agirliga ihtiyacimiz var
		if (numClass > 2) {

			weightCount = numClass * inputDim;

			for (int classno = 0; classno < numClass; classno++) {
				currentClass = classno;
				Weights = init_array_random(weightCount);
				bias = init_array_random(numClass);
				for (int j = 0; j < numSample; j++) {
					if (targets[j] == classno) {
						fakeTargets[j] = 1;
					}
					else {
						fakeTargets[j] = 0;
					}
				}


				//LineCiz(Weights, bias, numClass, 1.0);
				if (PerceptronButton->Checked == true) {
					Perceptron(fakeTargets);
				}
				else if (Deltabutton->Checked == true) {
					Delta(fakeTargets);
				}
				finalWeights[classno * inputDim + 0] = Weights[0];
				finalWeights[classno * inputDim + 1] = Weights[1];
				finalBias[classno] = bias[0];
			}
			textBox1->AppendText("final weights are:\r\n");
			for (int i = 0; i < numClass * inputDim; i += inputDim) {
				textBox1->AppendText(finalWeights[i] + " " + finalWeights[i + 1] + " " + finalBias[i / inputDim] + "\r\n");
			}
		}
		else {
			int numOutNeuron = 1;
			weightCount = inputDim;
			Weights = init_array_random(weightCount);
			bias = init_array_random(numOutNeuron); // bias[0]
			//LineCiz(Weights, bias, numClass, 1.0);
			if (PerceptronButton->Checked == true) {
				Perceptron(targets);
			}
			else if (Deltabutton->Checked == true) {
				Delta(targets);
			}
		}

	}
	private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		char** c = new char* [2];
		// Veri Kümesini okunacak 
		MessageBox::Show("Veri Kümesini Yükleyin");
		c[0] = "../Data/Samples.txt";
		c[1] = "../Data/weights.txt";
		ifstream file;
		int num, w, h, Dim, label;
		file.open(c[0]);
		if (file.is_open()) {
			//MessageBox::Show("Dosya acildi");
			file >> Dim >> w >> h >> num;
			textBox1->Text += "Dimension: " + Convert::ToString(Dim) + " w: " + Convert::ToString(w) + " h:" + Convert::ToString(h) + " numClass: " + Convert::ToString(num) + "\r\n";
			// Set network values
			numClass = num;
			inputDim = Dim;
			Weights = new float[numClass * inputDim];
			bias = new float[numClass];
			numSample = 0;
			float* x = new float[inputDim];
			while (!file.eof())
			{
				if (numSample == 0) { //ilk örnek için sadece
					numSample = 1;
					Samples = new float[inputDim]; targets = new float[numSample];
					for (int i = 0; i < inputDim; i++)
						file >> Samples[i];
					file >> targets[0];
				}
				else {

					for (int i = 0; i < inputDim; i++)
						file >> x[i];
					file >> label;
					if (!file.eof()) {
						numSample++;
						Samples = Add_Data(Samples, numSample, x, inputDim);
						targets = Add_Labels(targets, numSample, label);
					}
				}//else
			} //while
			delete[]x;
			file.close();
			for (int i = 0; i < numSample; i++) {
				draw_sample(Samples[i * inputDim] + w, h - Samples[i * inputDim + 1], targets[i]);
				for (int j = 0; j < inputDim; j++)
					textBox1->Text += Convert::ToString(Samples[i * inputDim + j]) + " ";
				textBox1->Text += Convert::ToString(targets[i]) + "\r\n";
			}
			//draw_sample(temp_x, temp_y, label);
			label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
			MessageBox::Show("Dosya basari ile okundu");
		}//file.is_open
		else MessageBox::Show("Dosya acilamadi");
		//Get weights
		int Layer;
		file.open(c[1]);
		if (file.is_open()) {
			file >> Layer >> Dim >> num;
			numClass = num;
			inputDim = Dim;
			Weights = new float[numClass * inputDim];
			bias = new float[numClass];
			textBox1->Text += "Layer: " + Convert::ToString(Layer) + " Dimension: " + Convert::ToString(Dim) + " numClass:" + Convert::ToString(num) + "\r\n";
			while (!file.eof())
			{
				for (int i = 0; i < numClass; i++)
					for (int j = 0; j < inputDim; j++)
						file >> Weights[i * inputDim + j];
				for (int i = 0; i < numClass; i++)
					file >> bias[i];
			}
			file.close();
			LineCiz(Weights, bias, numClass, 1.0);
		}//file.is_open
		delete[]c;
	}//Read_Data
	private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (numSample != 0) {
			char** c = new char* [2];
			// Veri Kümesi yazýlacak
			c[0] = "../Data/Samples.txt";
			c[1] = "../Data/weights.txt";
			ofstream ofs(c[0]);
			if (!ofs.bad()) {
				// Width,  Height, number of Class, data+label
				ofs << inputDim << " " << pictureBox1->Width / 2 << " " << pictureBox1->Height / 2 << " " << numClass << endl;
				for (int i = 0; i < numSample; i++) {
					for (int d = 0; d < inputDim; d++)
						ofs << Samples[i * inputDim + d] << " ";
					ofs << targets[i] << endl;
				}
				ofs.close();
			}
			else MessageBox::Show("Samples icin dosya acilamadi");
			ofstream file(c[1]);
			if (!file.bad()) {
				// #Layer Dimension numClass weights biases
				file << 1 << " " << inputDim << " " << numClass << endl;
				for (int k = 0; k < numClass * inputDim; k++)
					file << Weights[k] << " ";
				file << endl;
				for (int k = 0; k < numClass; k++)
					file << bias[k] << " ";
				file.close();
			}
			else MessageBox::Show("Weight icin dosya acilamadi");
			delete[]c;
		}
		else MessageBox::Show("At least one sample should be given");
	}//Save_Data
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ClassCountBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ClassCountBox_DropDownClosed(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void ClassCountBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// Network is constructed
		numClass = Convert::ToInt32(ClassCountBox->Text);
		Weights = new float[inputDim];
		finalWeights = new float[numClass * inputDim];
		bias = new float[numClass];
		//initialize weights for single layer
		// 2 den fazla class'imiz yoksa inputDim (2) adet agirlik olmasi yeterli
		// Ama eger multiclass calisiyorsak, katmandaki her class icin ayri agirliklar olacagi icin numClass * inputDim (x1 ve x2 icin) kadar agirliga ihtiyacimiz var
		if (numClass > 2) {
			Weights = init_array_random(numClass * inputDim);
			bias = init_array_random(numClass);
			//LineCiz(Weights, bias, numClass, 1.0);
		}
		else {
			int numOutNeuron = 1;
			Weights = init_array_random(inputDim);
			bias = init_array_random(numOutNeuron);
			//LineCiz(Weights, bias, numClass, 1.0);
		}
		calculateButton->Enabled = true;
		calculateButton->Text = "Calculate";
		ClassCountBox->Enabled = false;
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void learningMethodBox_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox1->Checked) {
			textBox1->Enabled = true;
		}
		else {
			textBox1->Enabled = false;
		}
	}
	};
}
