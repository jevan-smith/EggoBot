#include <stdio.h>
#include <sstream>
#include <string>
#include <tchar.h>
#include <urlmon.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h> 
using namespace std;

#pragma comment(lib, "urlmon.lib")

namespace Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ScanArea
	/// </summary>
	public ref class ScanArea : public System::Windows::Forms::Form
	{
	public:
		ScanArea(void)
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
		~ScanArea()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1024, 768);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Gold;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox2->Location = System::Drawing::Point(335, 84);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(23, 22);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Gold;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Location = System::Drawing::Point(662, 84);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(23, 22);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Gold;
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox3->Location = System::Drawing::Point(335, 242);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(23, 22);
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Gold;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox4->Location = System::Drawing::Point(662, 242);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(23, 22);
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ScanArea::backgroundWorker2_DoWork);
			// 
			// ScanArea
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 768);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ScanArea";
			this->Text = L"Fish Scanner Window";
			this->Load += gcnew System::EventHandler(this, &ScanArea::ScanArea_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		static int xPic1 = 0;
		static int xPic2 = 0;
		static int xPic3 = 0;
		static int xPic4 = 0;
		static int yPic1 = 0;
		static int yPic2 = 0;
		static int yPic3 = 0;
		static int yPic4 = 0;

	private: System::Void ScanArea_Load(System::Object^  sender, System::EventArgs^  e) {
		this->TransparencyKey = BackColor;
		this->ShowInTaskbar = false;
		this->Visible = "Hidden";
		backgroundWorker2->RunWorkerAsync();


	}
	/*private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
		int value = 1;
		if (!backgroundWorker1->IsBusy)
		{
			backgroundWorker1->RunWorkerAsync(value);
		}
		else
		{	
			backgroundWorker1->CancelAsync();
		}
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		int value = (int)e->Argument;
		POINT ptMouse;
		int xMoveAble = 0;
		int yMoveable = 0;
		HWND hwnd = ::FindWindow(NULL, _T("World of Warcraft"));
		HDC hdc = GetDC(hwnd);


		while (backgroundWorker1->CancellationPending == false)
		{

			GetCursorPos(&ptMouse);
			ScreenToClient(hwnd, &ptMouse);
				
			xMoveAble = ptMouse.x;
			yMoveable = ptMouse.y;

			if (value == 1)
			{
				this->pictureBox2->Location = System::Drawing::Point(ptMouse.x, ptMouse.y);
				this->pictureBox1->Location = System::Drawing::Point(327 + xMoveAble, yMoveable);
				this->pictureBox3->Location = System::Drawing::Point(xMoveAble, 158 + yMoveable);
				this->pictureBox4->Location = System::Drawing::Point(327 + xMoveAble, 158 + yMoveable);
				this->pictureBox1->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox2->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox3->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox4->BackColor = System::Drawing::Color::DarkOrange;
			}
			if (value == 2)
			{
				this->pictureBox1->Location = System::Drawing::Point(ptMouse.x, ptMouse.y);
				this->pictureBox2->Location = System::Drawing::Point(-327 + xMoveAble, yMoveable);
				this->pictureBox3->Location = System::Drawing::Point(-327 + xMoveAble, 158 + yMoveable);
				this->pictureBox4->Location = System::Drawing::Point(xMoveAble, 158 + yMoveable);
				this->pictureBox1->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox2->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox3->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox4->BackColor = System::Drawing::Color::DarkOrange;
			}
			if (value == 3)
			{
				this->pictureBox3->Location = System::Drawing::Point(xMoveAble, yMoveable);
				this->pictureBox1->Location = System::Drawing::Point(xMoveAble, -158 + yMoveable);
				this->pictureBox2->Location = System::Drawing::Point(327 + xMoveAble, -158 + yMoveable);
				this->pictureBox4->Location = System::Drawing::Point(327 + xMoveAble, yMoveable);
				this->pictureBox1->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox2->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox3->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox4->BackColor = System::Drawing::Color::DarkOrange;
			}
			if (value == 4)
			{
				this->pictureBox4->Location = System::Drawing::Point(xMoveAble, yMoveable);
				this->pictureBox1->Location = System::Drawing::Point(-327 + xMoveAble, -158 + yMoveable);
				this->pictureBox2->Location = System::Drawing::Point(xMoveAble, -158 + yMoveable);
				this->pictureBox3->Location = System::Drawing::Point(-327 + xMoveAble, yMoveable);
				this->pictureBox1->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox2->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox3->BackColor = System::Drawing::Color::DarkOrange;
				this->pictureBox4->BackColor = System::Drawing::Color::DarkOrange;
			}
		}
		this->pictureBox1->BackColor = System::Drawing::Color::Gold;
		this->pictureBox2->BackColor = System::Drawing::Color::Gold;
		this->pictureBox3->BackColor = System::Drawing::Color::Gold;
		this->pictureBox4->BackColor = System::Drawing::Color::Gold;

		xPic1 = pictureBox1->Location.X;
		xPic2 = pictureBox2->Location.X;
		xPic3 = pictureBox3->Location.X;
		xPic4 = pictureBox4->Location.X;
		yPic1 = pictureBox1->Location.Y;
		yPic2 = pictureBox2->Location.Y;
		yPic3 = pictureBox3->Location.Y;
		yPic4 = pictureBox4->Location.Y;


		e->Cancel = true;
		return;

	}


private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = 2;
	if (!backgroundWorker1->IsBusy)
	{
		backgroundWorker1->RunWorkerAsync(value);
	}
	else
	{
		backgroundWorker1->CancelAsync();
	}
}
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = 3;
	if (!backgroundWorker1->IsBusy)
	{
		backgroundWorker1->RunWorkerAsync(value);
	}
	else
	{
		backgroundWorker1->CancelAsync();
	}
}
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = 4;
	if (!backgroundWorker1->IsBusy)
	{
		backgroundWorker1->RunWorkerAsync(value);
	}
	else
	{
		backgroundWorker1->CancelAsync();
	}
}*/
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	HWND hwnd = ::FindWindow(NULL, _T("World of Warcraft"));
	
	while (true)
	{

		HWND hwnd = ::FindWindow(NULL, _T("World of Warcraft"));

		if (hwnd == NULL)
		{
			this->Close();
		}
	}
}
};
}
