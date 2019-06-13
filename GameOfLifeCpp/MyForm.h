#pragma once
#include<windows.h>
#include "GOL.h"
#include "RLE.h"
#include <stdlib.h>
#include <algorithm>


namespace GameOfLifeCpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	GOL GameOfLife;
	RLE rle;
	bool manualMode = false;

	std::vector<int>alive = {};

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
//			this->graphics = gcnew Graphics;
			this->graphics = pictureBox1->CreateGraphics();
			this->brush = gcnew SolidBrush(Color::Red);
			this->pen= gcnew Pen(Color::Pink);

			this->width = pictureBox1->Width;
			this->height = pictureBox1->Height;

			this->timer = gcnew Timer();
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::onTimedEvent);
			this->timer->Interval = 1000;

			button1->Enabled = false;
			button2->Enabled = false;
			button3->Enabled = false;
			button4->Enabled = false;
			button5->Enabled = false;
			button6->Enabled = false;
			button7->Enabled = false;
			button8->Enabled = false;
			button9->Enabled = false;
			button10->Enabled = false;
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;

	private:int width;
	private: int height;
	
	private: Graphics^graphics;
	private: SolidBrush^brush;
	private:Pen^pen;

			static Timer^timer;

	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;


	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::LavenderBlush;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->MaximumSize = System::Drawing::Size(1000, 750);
			this->pictureBox1->MinimumSize = System::Drawing::Size(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1000, 750);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numericUpDown3->Location = System::Drawing::Point(1101, 205);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 28);
			this->numericUpDown3->TabIndex = 3;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::Color::Maroon;
			this->label3->Location = System::Drawing::Point(1024, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(197, 22);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Size of the BOARD";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(1032, 209);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"FPS";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Monospac821 BT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->ForeColor = System::Drawing::Color::Maroon;
			this->label5->Location = System::Drawing::Point(1024, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 22);
			this->label5->TabIndex = 9;
			this->label5->Text = L"GAME";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numericUpDown2->Location = System::Drawing::Point(1101, 95);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 150, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 28);
			this->numericUpDown2->TabIndex = 2;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->numericUpDown1->Location = System::Drawing::Point(1101, 61);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 150, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 28);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(1024, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 24);
			this->label2->TabIndex = 6;
			this->label2->Text = L"height";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(1032, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"width";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(1037, 256);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 35);
			this->button1->TabIndex = 10;
			this->button1->Text = L"manual mode";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(1037, 348);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 35);
			this->button2->TabIndex = 11;
			this->button2->Text = L"bee-hieve";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(1179, 348);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 35);
			this->button3->TabIndex = 12;
			this->button3->Text = L"blinker";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(1033, 308);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(221, 24);
			this->label6->TabIndex = 13;
			this->label6->Text = L"ready-to-use PATTERNS";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(1315, 348);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(136, 36);
			this->button4->TabIndex = 14;
			this->button4->Text = L"glider";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(1036, 414);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(204, 36);
			this->button5->TabIndex = 15;
			this->button5->Text = L"copperhead";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(1247, 414);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(204, 36);
			this->button6->TabIndex = 16;
			this->button6->Text = L"gosper glider gun";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(1033, 393);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(76, 18);
			this->label7->TabIndex = 17;
			this->label7->Text = L"from RLE:";
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(1037, 456);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(204, 36);
			this->button7->TabIndex = 18;
			this->button7->Text = L"queen bee suttle";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button8->ForeColor = System::Drawing::Color::Maroon;
			this->button8->Location = System::Drawing::Point(1160, 580);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(102, 35);
			this->button8->TabIndex = 19;
			this->button8->Text = L"START";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button9->ForeColor = System::Drawing::Color::Maroon;
			this->button9->Location = System::Drawing::Point(1268, 580);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(102, 35);
			this->button9->TabIndex = 20;
			this->button9->Text = L"STOP";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button10->ForeColor = System::Drawing::Color::Maroon;
			this->button10->Location = System::Drawing::Point(1123, 580);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(31, 35);
			this->button10->TabIndex = 21;
			this->button10->Text = L"<";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button11->Location = System::Drawing::Point(1268, 61);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(183, 60);
			this->button11->TabIndex = 22;
			this->button11->Text = L"set the board";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(1247, 694);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(85, 28);
			this->textBox1->TabIndex = 23;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(1134, 697);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(92, 24);
			this->label8->TabIndex = 24;
			this->label8->Text = L"RAM info:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(1333, 697);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 24);
			this->label9->TabIndex = 25;
			this->label9->Text = L"MB left";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 753);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1500, 800);
			this->MinimumSize = System::Drawing::Size(1500, 800);
			this->Name = L"MyForm";
			this->Text = L"Convay\'s Game of Life in C++";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void onTimedEvent(System::Object^  sender, System::EventArgs^  e) {

		GameOfLife.board.update();
		pictureBox1->Refresh();
		

		for (int y = 0; y < GameOfLife.board.a; y++)
			for (int x = 0; x < GameOfLife.board.b; x++)
			{
				if (GameOfLife.board.cells[y*GameOfLife.board.b + x].isAlive())
				{
					graphics->FillRectangle(brush, x*GameOfLife.size, y*GameOfLife.size, GameOfLife.size, GameOfLife.size);
				}
			}
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		textBox1->Text = (statex.ullAvailPhys / (1024 * 1024)).ToString();

		GameOfLife.addIterationInfo(GameOfLife.board.getAlive());
	}
//---------------------------------START BUTTON---------------------------------------------------------
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		
		manualMode = false;
		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		button5->Enabled = false;
		button6->Enabled = false;
		button7->Enabled = false;
		button8->Enabled = false;
		button10->Enabled = false;
		button11->Enabled = false;

		button9->Enabled = true;

		timer->Start();
	}

//-------------------------------SETTING THE BOARD BUTTON-----------------------------------------------
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {

		button1->Enabled = true;
		button2->Enabled = true;
		button3->Enabled = true;
		button4->Enabled = true;
		button5->Enabled = true;
		button6->Enabled = true;
		button7->Enabled = true;
		button8->Enabled = false;
		button9->Enabled = false;
		button10->Enabled = false;
		

		pictureBox1->Refresh();

		int nW= (int)numericUpDown1->Value;
		int nH = (int)numericUpDown2->Value;

		int cellSize = ((width/ nW) > (height / nH)) ? (height / nH) : (width / nW);
		GameOfLife.setSize(cellSize);
		pictureBox1->Width = cellSize * nW;
		pictureBox1->Height = cellSize * nH;

		GameOfLife.setBoard(nH, nW);

		pictureBox1->Refresh();

		int FPS = (int)numericUpDown3->Value;

		DateTime start = DateTime::Now;

		this->draw();

		DateTime stop = DateTime::Now;
		TimeSpan t = stop - start;
		int maxFPS = 1000 / t.TotalMilliseconds;
		FPS=(FPS>maxFPS)?maxFPS:FPS;
		timer->Interval = (1000 / FPS);
		numericUpDown3->Value = FPS;
	}

	//--------------------------STOP BUTTON------------------------------------------------
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		timer->Stop();
		button1->Enabled = true;
		button2->Enabled = true;
		button3->Enabled = true;
		button4->Enabled = true;
		button5->Enabled = true;
		button6->Enabled = true;
		button7->Enabled = true;
		button8->Enabled = true;
		button10->Enabled = true;
		button11->Enabled = true;

		button9->Enabled = false;

		GameOfLife.getPastIteration();
		GameOfLife.getPastIteration();

	}
	//-----------------------------back button-----------------------------------------------
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {

		GameOfLife.board.init(GameOfLife.getPastIteration());

		this->draw();

		if (GameOfLife.firstIter())
			button10->Enabled = false;
	}
//-----------------------manual mode button---------------------------------------------
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		button8->Enabled = true;
		manualMode = true;

		for (int it = 0; it < pictureBox1->Width; it += GameOfLife.size)
			graphics->DrawLine(pen, it, 0, it, pictureBox1->Height);

		for (int it = 0; it < pictureBox1->Height; it += GameOfLife.size)
			graphics->DrawLine(pen, 0, it, pictureBox1->Width, it);
	}
//-----------------------------bee-hieve-------------------------------------------------
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	std::vector<vector<int>>pattern = { {2,1},{3,1},{1,2},{4,2},{2,3},{3,3} };
	alive = GameOfLife.makePattern(pattern);
	GameOfLife.board.init(alive);
	button8->Enabled = true;

	GameOfLife.addIterationInfo(alive);

	this->draw();
}

//-------------------------------blinker-------------------------------------------------
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	std::vector<vector<int>>pattern = { {1,2},{2,2},{3,2}};
	alive=GameOfLife.makePattern(pattern);
	GameOfLife.board.init(alive);
	button8->Enabled = true;

	GameOfLife.addIterationInfo(alive);

	this->draw();
}

//--------------------------------glider-----------------------------------------------
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	std::vector<vector<int>>pattern = { {2,1},{3,2},{1,3},{2,3},{3,3} };
	alive = GameOfLife.makePattern(pattern);
	GameOfLife.board.init(alive);
	button8->Enabled = true;

	GameOfLife.addIterationInfo(alive);

	this->draw();
}

		 //cooperhead
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	//RLE format:
	vector<string>pattern = { "12F","5F2T5F","4F4T4F","12F","3F6T3F","4F4T4F","12F","3F2T2F2T3F","1F2T1F1T2F1T1F2T1F","4F1T2F1T4F","12F","12F",
								"5F2T5F","5F2T5F","12F" };

	alive = rle.decode(pattern, GameOfLife.board.b);

	GameOfLife.board.init(alive);
	button8->Enabled = true;

	GameOfLife.addIterationInfo(alive);

	this->draw();
}

//-------------------------------gosper glider gun-----------------------------------------
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	//RLE format:
	vector<string>pattern = { "38F","25F1T12F","23F1T1F1T12F","13F2T6F2T12F2T1F","12F1T3F1T4F2T12F2T1F","1F2T8F1T5F1T3F2T15F",
							"1F2T8F1T3F1T1F2T4F1T1F1T12F","11F1T5F1T7F1T12F","12F1T3F1T21F","13F2T23F","38F" };

	alive = rle.decode(pattern, GameOfLife.board.b);

	GameOfLife.board.init(alive);
	button8->Enabled = true;

	GameOfLife.addIterationInfo(alive);

	this->draw();
}
//--------------------------------queen bee suttle-----------------------------------------
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		//RLE format:
		vector<string>pattern = { "24F","13F2T9F","12F1T3F1T7F","11F1T5F1T6F","1F2T8F1T3F1T1F2T2F2T1F","1F2T8F1T5F1T3F2T1F",
								"12F1T3F1T7F","13F2T9F","24F" };

		alive = rle.decode(pattern, GameOfLife.board.b);

		GameOfLife.board.init(alive);
		button8->Enabled = true;

		GameOfLife.addIterationInfo(alive);

		this->draw();
	}

private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (manualMode == true)
	{
		alive = GameOfLife.checkCurrent();

		MouseEventArgs^ me = (MouseEventArgs^)e;
		if (me->Button == System::Windows::Forms::MouseButtons::Left)
		{
			if (me->X >= width || me->Y >=height)
				return;
			if (me->X < 0 || me->Y < 0)
				return;
			int id = (me->X / GameOfLife.size) + ((me->Y / GameOfLife.size)*GameOfLife.board.b);
			if (!GameOfLife.board.cells[id].isAlive())
				alive.push_back(id);
			else
			{
				std::vector<int>::iterator position = std::find(alive.begin(), alive.end(), id);
				if (position != alive.end())
					alive.erase(position);
			}
				
			
			GameOfLife.board.init(alive);

			this->draw();
		}
	}
}

//==========================================DRAW FULL BOARD FUNCTION====================================================
		 private: void draw()
		 {
			 pictureBox1->Refresh();
			 for (int it = 0; it < pictureBox1->Width; it += GameOfLife.size)
				 graphics->DrawLine(pen, it, 0, it, pictureBox1->Height);

			 for (int it = 0; it < pictureBox1->Height; it += GameOfLife.size)
				 graphics->DrawLine(pen, 0, it, pictureBox1->Width, it);

			 for (int y = 0; y < GameOfLife.board.a; y++)
				 for (int x = 0; x < GameOfLife.board.b; x++)
				 {
					 if (GameOfLife.board.cells[y*GameOfLife.board.b + x].isAlive())
					 {
						 graphics->FillRectangle(brush, x*GameOfLife.size, y*GameOfLife.size, GameOfLife.size, GameOfLife.size);
					 }
				 }
		 }
};
}
