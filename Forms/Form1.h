#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include "controls.h"
#include "helper.h"
#include "EasyBMP\EasyBMP.h"
#include <iomanip>
#include <process.h>
#include <tchar.h>
#include "resource2.h"
#include "UpdateForm.h"
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stdafx.h"
#include "ScanArea.h"
using namespace std;


namespace Forms {

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
	private: System::Windows::Forms::Button^  Start;
	public: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  Stop;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  Status;
	private: System::Windows::Forms::Label^  Result;
	private: System::Windows::Forms::GroupBox^  Settings;

	private: System::Windows::Forms::CheckBox^  Autoloot;



	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolTip^  toolTip2;
	private: System::Windows::Forms::ToolTip^  toolTip3;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::Button^  Restart;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  updateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  Beta;
	private: System::Windows::Forms::GroupBox^  bobberSetup;
	private: System::Windows::Forms::Button^  InkButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker3;

	private: System::Windows::Forms::CheckBox^  fishingWaitCheck;
	private: System::Windows::Forms::TextBox^  waitTimeTextBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  yValueText;
	private: System::Windows::Forms::Label^  xValueText;
	private: System::Windows::Forms::TextBox^  yBobberText;
	private: System::Windows::Forms::TextBox^  xBobberText;
	private: System::Windows::Forms::Label^  bobPositionText;
	private: System::Windows::Forms::Button^  screenShot;
	private: System::Windows::Forms::GroupBox^  fishScannerSetupBox;
	private: System::Windows::Forms::Button^  calibrate;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker4;






	private: System::Windows::Forms::ToolTip^  toolTip4;
	private: System::Windows::Forms::ToolTip^  toolTip5;
	private: System::Windows::Forms::CheckBox^  dark;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  checkBox1;



	private: System::ComponentModel::IContainer^  components;

	private:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Start = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Stop = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Status = (gcnew System::Windows::Forms::Label());
			this->Result = (gcnew System::Windows::Forms::Label());
			this->Settings = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->waitTimeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->fishingWaitCheck = (gcnew System::Windows::Forms::CheckBox());
			this->Autoloot = (gcnew System::Windows::Forms::CheckBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Restart = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Beta = (gcnew System::Windows::Forms::Label());
			this->bobberSetup = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dark = (gcnew System::Windows::Forms::CheckBox());
			this->bobPositionText = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->yValueText = (gcnew System::Windows::Forms::Label());
			this->InkButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->xBobberText = (gcnew System::Windows::Forms::TextBox());
			this->xValueText = (gcnew System::Windows::Forms::Label());
			this->yBobberText = (gcnew System::Windows::Forms::TextBox());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->screenShot = (gcnew System::Windows::Forms::Button());
			this->fishScannerSetupBox = (gcnew System::Windows::Forms::GroupBox());
			this->calibrate = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker4 = (gcnew System::ComponentModel::BackgroundWorker());
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->Settings->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->bobberSetup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->fishScannerSetupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(34, 542);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(160, 52);
			this->Start->TabIndex = 7;
			this->Start->Text = L"START - F2";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::Start_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			// 
			// Stop
			// 
			this->Stop->Location = System::Drawing::Point(200, 542);
			this->Stop->Name = L"Stop";
			this->Stop->Size = System::Drawing::Size(160, 23);
			this->Stop->TabIndex = 1;
			this->Stop->Text = L"STOP - F3";
			this->Stop->UseVisualStyleBackColor = true;
			this->Stop->Click += gcnew System::EventHandler(this, &Form1::Stop_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(34, 35);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(326, 176);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// Status
			// 
			this->Status->AutoSize = true;
			this->Status->Location = System::Drawing::Point(31, 526);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(40, 13);
			this->Status->TabIndex = 4;
			this->Status->Text = L"Status:";
			// 
			// Result
			// 
			this->Result->AutoSize = true;
			this->Result->ForeColor = System::Drawing::Color::Red;
			this->Result->Location = System::Drawing::Point(68, 526);
			this->Result->Name = L"Result";
			this->Result->Size = System::Drawing::Size(67, 13);
			this->Result->TabIndex = 5;
			this->Result->Text = L"Not Running";
			// 
			// Settings
			// 
			this->Settings->Controls->Add(this->checkBox1);
			this->Settings->Controls->Add(this->waitTimeTextBox);
			this->Settings->Controls->Add(this->fishingWaitCheck);
			this->Settings->Controls->Add(this->Autoloot);
			this->Settings->Location = System::Drawing::Point(34, 401);
			this->Settings->Name = L"Settings";
			this->Settings->Size = System::Drawing::Size(326, 98);
			this->Settings->TabIndex = 6;
			this->Settings->TabStop = false;
			this->Settings->Text = L"Settings";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(33, 62);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(108, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Click Fishing Rod";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// waitTimeTextBox
			// 
			this->waitTimeTextBox->Enabled = false;
			this->waitTimeTextBox->Location = System::Drawing::Point(275, 27);
			this->waitTimeTextBox->Name = L"waitTimeTextBox";
			this->waitTimeTextBox->Size = System::Drawing::Size(34, 20);
			this->waitTimeTextBox->TabIndex = 7;
			this->waitTimeTextBox->Text = L"17";
			this->waitTimeTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// fishingWaitCheck
			// 
			this->fishingWaitCheck->AutoSize = true;
			this->fishingWaitCheck->Location = System::Drawing::Point(166, 29);
			this->fishingWaitCheck->Name = L"fishingWaitCheck";
			this->fishingWaitCheck->Size = System::Drawing::Size(113, 17);
			this->fishingWaitCheck->TabIndex = 6;
			this->fishingWaitCheck->Text = L"Fishing Wait Time:";
			this->toolTip4->SetToolTip(this->fishingWaitCheck, L"Time in seconds waiting to catch fish");
			this->fishingWaitCheck->UseVisualStyleBackColor = true;
			this->fishingWaitCheck->CheckedChanged += gcnew System::EventHandler(this, &Form1::fishingWaitCheck_CheckedChanged);
			// 
			// Autoloot
			// 
			this->Autoloot->AutoSize = true;
			this->Autoloot->Checked = true;
			this->Autoloot->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Autoloot->Location = System::Drawing::Point(33, 29);
			this->Autoloot->Name = L"Autoloot";
			this->Autoloot->Size = System::Drawing::Size(65, 17);
			this->Autoloot->TabIndex = 0;
			this->Autoloot->Text = L"Autoloot";
			this->toolTip1->SetToolTip(this->Autoloot, L"Enabling this function will Autoloot items within \r\nWorld of Warcraft. Do not Ena"
				L"ble if autoloot is \r\nturned on ingame!");
			this->Autoloot->UseVisualStyleBackColor = true;
			// 
			// toolTip1
			// 
			this->toolTip1->ToolTipTitle = L"Autoloot";
			this->toolTip1->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &Form1::toolTip1_Popup);
			// 
			// toolTip2
			// 
			this->toolTip2->ToolTipTitle = L"Overlay";
			this->toolTip2->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &Form1::toolTip2_Popup);
			// 
			// toolTip3
			// 
			this->toolTip3->ToolTipTitle = L"Logout";
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker2_DoWork);
			// 
			// Restart
			// 
			this->Restart->Location = System::Drawing::Point(200, 571);
			this->Restart->Name = L"Restart";
			this->Restart->Size = System::Drawing::Size(160, 23);
			this->Restart->TabIndex = 7;
			this->Restart->Text = L"RESTART - F4";
			this->Restart->UseVisualStyleBackColor = true;
			this->Restart->Click += gcnew System::EventHandler(this, &Form1::Restart_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(395, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->updateToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// updateToolStripMenuItem
			// 
			this->updateToolStripMenuItem->Name = L"updateToolStripMenuItem";
			this->updateToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->updateToolStripMenuItem->Text = L"Update";
			this->updateToolStripMenuItem->Visible = false;
			this->updateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::updateToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(216, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L" EggoBot v2.1.0";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// Beta
			// 
			this->Beta->AutoSize = true;
			this->Beta->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Beta->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Beta->Location = System::Drawing::Point(297, 11);
			this->Beta->Name = L"Beta";
			this->Beta->Size = System::Drawing::Size(47, 13);
			this->Beta->TabIndex = 10;
			this->Beta->Text = L" (BETA) ";
			// 
			// bobberSetup
			// 
			this->bobberSetup->Controls->Add(this->label3);
			this->bobberSetup->Controls->Add(this->dark);
			this->bobberSetup->Controls->Add(this->bobPositionText);
			this->bobberSetup->Controls->Add(this->label2);
			this->bobberSetup->Controls->Add(this->yValueText);
			this->bobberSetup->Controls->Add(this->InkButton);
			this->bobberSetup->Controls->Add(this->pictureBox1);
			this->bobberSetup->Controls->Add(this->xBobberText);
			this->bobberSetup->Controls->Add(this->xValueText);
			this->bobberSetup->Controls->Add(this->yBobberText);
			this->bobberSetup->Location = System::Drawing::Point(34, 227);
			this->bobberSetup->Name = L"bobberSetup";
			this->bobberSetup->Size = System::Drawing::Size(160, 168);
			this->bobberSetup->TabIndex = 12;
			this->bobberSetup->TabStop = false;
			this->bobberSetup->Text = L"Bobber Setup";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Bobber Splash Mode:";
			// 
			// dark
			// 
			this->dark->AutoSize = true;
			this->dark->Checked = true;
			this->dark->CheckState = System::Windows::Forms::CheckState::Checked;
			this->dark->Location = System::Drawing::Point(23, 133);
			this->dark->Name = L"dark";
			this->dark->Size = System::Drawing::Size(79, 17);
			this->dark->TabIndex = 10;
			this->dark->Text = L"Dark Mode";
			this->toolTip5->SetToolTip(this->dark, L"Enable this setting when your fishing in a dark area\r\nDisable this setting when y"
				L"our fishing in a bright area");
			this->dark->UseVisualStyleBackColor = true;
			this->dark->CheckedChanged += gcnew System::EventHandler(this, &Form1::dark_CheckedChanged);
			// 
			// bobPositionText
			// 
			this->bobPositionText->AutoSize = true;
			this->bobPositionText->Location = System::Drawing::Point(20, 72);
			this->bobPositionText->Name = L"bobPositionText";
			this->bobPositionText->Size = System::Drawing::Size(111, 13);
			this->bobPositionText->TabIndex = 8;
			this->bobPositionText->Text = L"Bobber Color Position:";
			this->bobPositionText->Click += gcnew System::EventHandler(this, &Form1::bobPositionText_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Bobber Color:";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// yValueText
			// 
			this->yValueText->AutoSize = true;
			this->yValueText->Location = System::Drawing::Point(82, 91);
			this->yValueText->Name = L"yValueText";
			this->yValueText->Size = System::Drawing::Size(17, 13);
			this->yValueText->TabIndex = 7;
			this->yValueText->Text = L"Y:";
			this->yValueText->Click += gcnew System::EventHandler(this, &Form1::yValueText_Click);
			// 
			// InkButton
			// 
			this->InkButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InkButton.BackgroundImage")));
			this->InkButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->InkButton->Location = System::Drawing::Point(23, 38);
			this->InkButton->Name = L"InkButton";
			this->InkButton->Size = System::Drawing::Size(27, 28);
			this->InkButton->TabIndex = 1;
			this->InkButton->UseVisualStyleBackColor = true;
			this->InkButton->Click += gcnew System::EventHandler(this, &Form1::InkButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::WindowText;
			this->pictureBox1->Location = System::Drawing::Point(51, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(88, 28);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// xBobberText
			// 
			this->xBobberText->Location = System::Drawing::Point(37, 88);
			this->xBobberText->Name = L"xBobberText";
			this->xBobberText->Size = System::Drawing::Size(40, 20);
			this->xBobberText->TabIndex = 4;
			this->xBobberText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// xValueText
			// 
			this->xValueText->AutoSize = true;
			this->xValueText->Location = System::Drawing::Point(20, 91);
			this->xValueText->Name = L"xValueText";
			this->xValueText->Size = System::Drawing::Size(17, 13);
			this->xValueText->TabIndex = 6;
			this->xValueText->Text = L"X:";
			this->xValueText->Click += gcnew System::EventHandler(this, &Form1::xValueText_Click);
			// 
			// yBobberText
			// 
			this->yBobberText->Location = System::Drawing::Point(99, 88);
			this->yBobberText->Name = L"yBobberText";
			this->yBobberText->Size = System::Drawing::Size(40, 20);
			this->yBobberText->TabIndex = 5;
			this->yBobberText->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			this->yBobberText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker3_DoWork);
			// 
			// screenShot
			// 
			this->screenShot->Location = System::Drawing::Point(199, 232);
			this->screenShot->Name = L"screenShot";
			this->screenShot->Size = System::Drawing::Size(160, 33);
			this->screenShot->TabIndex = 13;
			this->screenShot->Text = L"SCREENSHOT - F5";
			this->screenShot->UseVisualStyleBackColor = true;
			this->screenShot->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// fishScannerSetupBox
			// 
			this->fishScannerSetupBox->Controls->Add(this->calibrate);
			this->fishScannerSetupBox->Location = System::Drawing::Point(200, 272);
			this->fishScannerSetupBox->Name = L"fishScannerSetupBox";
			this->fishScannerSetupBox->Size = System::Drawing::Size(160, 123);
			this->fishScannerSetupBox->TabIndex = 14;
			this->fishScannerSetupBox->TabStop = false;
			this->fishScannerSetupBox->Text = L"Fish Scanner Area";
			// 
			// calibrate
			// 
			this->calibrate->Location = System::Drawing::Point(18, 39);
			this->calibrate->Name = L"calibrate";
			this->calibrate->Size = System::Drawing::Size(125, 56);
			this->calibrate->TabIndex = 0;
			this->calibrate->Text = L"SHOW FISHING\r\nOVERLAY";
			this->calibrate->UseVisualStyleBackColor = true;
			this->calibrate->Click += gcnew System::EventHandler(this, &Form1::calibrate_Click);
			// 
			// backgroundWorker4
			// 
			this->backgroundWorker4->WorkerSupportsCancellation = true;
			this->backgroundWorker4->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker4_DoWork);
			// 
			// toolTip4
			// 
			this->toolTip4->ToolTipTitle = L"Fishing Wait Time";
			// 
			// toolTip5
			// 
			this->toolTip5->ToolTipTitle = L"Dark Mode";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(395, 606);
			this->Controls->Add(this->fishScannerSetupBox);
			this->Controls->Add(this->screenShot);
			this->Controls->Add(this->bobberSetup);
			this->Controls->Add(this->Beta);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Restart);
			this->Controls->Add(this->Settings);
			this->Controls->Add(this->Result);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->Stop);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->ImeMode = System::Windows::Forms::ImeMode::On;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->RightToLeftLayout = true;
			this->Text = L"EggoBot";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Settings->ResumeLayout(false);
			this->Settings->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->bobberSetup->ResumeLayout(false);
			this->bobberSetup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->fishScannerSetupBox->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion

	int startX = 0;
	int startY = 0;
	int redColor = 0;
	int greenColor = 0;
	int blueColor = 0;
	int mode = 2;
	bool clickFishingRod = false;


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		remove("update.txt");
		remove("EggoBotOLD.exe");

		backgroundWorker2->RunWorkerAsync();

		Stop->Enabled = false;


	}

	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {

		int xInt = 0;
		int yInt = 0;

		Int32::TryParse(xBobberText->Text, xInt);
		Int32::TryParse(yBobberText->Text, yInt);

		if (!backgroundWorker1->IsBusy)
		{
			HWND hwnd = ::FindWindow(NULL, _T("World of Warcraft"));
			HWND hwnd2 = ::FindWindow(NULL, _T("Fish Scanner Window"));
			if (hwnd == NULL)
				MessageBox::Show("Error! Please open 'World of Warcraft'.");
			else {
				if (redColor == 0 && greenColor == 0 && blueColor == 0)
				{
					MessageBox::Show("Error! You must set a 'Bobber Color'.");
				}
				else if (xInt == NULL || yInt == NULL)
				{
					MessageBox::Show("Error! 'Bobber Color Position' Cannot be Blank.");
				}
				else if (xInt > 1024 || yInt > 768)
				{
					MessageBox::Show("Error! 'Bobber Color Position' Cannot be\nGreater than 'X: 1024' or 'Y: 768'.");
				}
				else if (hwnd2 != NULL)
				{
					MessageBox::Show("Error! Fishing Overlay Must Be Closed, Please Select\n'Close Fishing Overlay' to close the Overlay.");
				}
				else
				{

					this->Result->ForeColor = System::Drawing::Color::Green;
					this->Result->Text = L"Running";
					screenShot->Enabled = false;
					Start->Enabled = false;
					Stop->Enabled = true;
					backgroundWorker1->RunWorkerAsync();
				}
			}
		}
	}

	private: System::Void Stop_Click(System::Object^  sender, System::EventArgs^  e) {
		if (backgroundWorker1->IsBusy)
		{
			this->Result->ForeColor = System::Drawing::Color::DarkOrange;
			this->Result->Text = L"Stopping in Progress, Waiting to Catch Last Fish!";
			Start->Enabled = false;
			Stop->Enabled = false;
			backgroundWorker1->CancelAsync();
		}
	}

	private: System::Void Restart_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Restart();
	}

	public: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		CheckForIllegalCrossThreadCalls = false;
		BMP image;
		HWND hwnd = ::FindWindow(NULL, _T("World of Warcraft"));
		SetWindowPos(hwnd, 0, 0, 0, 1024, 768, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
		//cout << "Casting Line" << endl;
		//SendText("1", hwnd);

		int n;
		int xBobber = System::Convert::ToInt32(xBobberText->Text);
		int yBobber = System::Convert::ToInt32(yBobberText->Text);
		bool check = false;
		std::clock_t start;
		double duration = 0;
		start = std::clock();
		int counter = 0;
		int timeToJump = 20 + rand() % 21;
		int fishWaitTime = 0;
		Int32::TryParse(waitTimeTextBox->Text, fishWaitTime);

		if (Autoloot->CheckState == System::Windows::Forms::CheckState::Checked)
		{
			check = true;
		}

		while (backgroundWorker1->CancellationPending ==  false)
		{
			counter++;
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			int hours = ((duration / 60) / 60);
			int minutes = (duration / 60);
			int seconds = duration;

			if (seconds > 60)
				seconds = seconds % 60;
			if (minutes > 60)
				minutes = minutes % 60;

			
			richTextBox1->AppendText(hours.ToString());
			richTextBox1->Text += ":";
			richTextBox1->AppendText(minutes.ToString());
			richTextBox1->Text += ":";
			richTextBox1->AppendText(seconds.ToString());
			richTextBox1->Text += ": ";
			richTextBox1->Text += "[USEFUL INFO] ";
			richTextBox1->Text += "Current Cycle: ";
			richTextBox1->AppendText(counter.ToString());
			richTextBox1->Text += ", Cycle to Jump: ";
			richTextBox1->AppendText(timeToJump.ToString());
			richTextBox1->Text += "\n";


			if (counter >= timeToJump)
			{
				PressKey(VK_SPACE, 1, hwnd);
				counter = 0;
				timeToJump = 20 + rand() % 21;
				Sleep(900 + rand() % 800);
				continue;
			}

			if (clickFishingRod == false)
			{
				PressKey(0x31, 1, hwnd);
				//SendText("1", hwnd); <----- OLD, WORKS FOR SOME NOT OTHERS
			}
			else
			{
				MoveMouse(30, 724, 1, hwnd);
			}
			SetForegroundWindow(hwnd);

			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			hours = ((duration / 60) / 60);
			minutes = (duration / 60);
			seconds = duration;

			if (seconds > 60)
				seconds = seconds % 60;
			if (minutes > 60)
				minutes = minutes % 60;

			richTextBox1->AppendText(hours.ToString());
			richTextBox1->Text += ":";
			richTextBox1->AppendText(minutes.ToString());
			richTextBox1->Text += ":";
			richTextBox1->AppendText(seconds.ToString());
			richTextBox1->Text += ": ";
			richTextBox1->Text += "Scanning for Fish\n";

			scanForFish(hwnd, image, redColor, greenColor, blueColor, xBobber, yBobber);


			grabFish(hwnd, image, check, redColor, greenColor, blueColor, xBobber, yBobber, fishWaitTime, mode);
			Sleep(700);
		}
		this->Result->ForeColor = System::Drawing::Color::Red;
		this->Result->Text = L"Not Running";
		screenShot->Enabled = true;
		Start->Enabled = true;
		e->Cancel = true;
		return;
	}
private: System::Void toolTip1_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
}
private: System::Void toolTip2_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
}
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	CheckForIllegalCrossThreadCalls = false;


	while (true)
	{

		if (GetAsyncKeyState(VK_F2) & 0x8000)
		{
			this->Start->PerformClick();
		}
		else if (GetAsyncKeyState(VK_F3) & 0x8000)
		{
			this->Stop->PerformClick();
		}
		else if (GetAsyncKeyState(VK_F4) & 0x8000)
		{
			this->Restart->PerformClick();
		}
		else if (GetAsyncKeyState(VK_F5) & 0x8000)
		{
			this->screenShot->PerformClick();
		}
	}

}

private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	// AUTO SCROLLS TEXT BOX
	// set the current caret position to the end
	richTextBox1->SelectionStart = richTextBox1->Text->Length;
	// scroll it automatically
	richTextBox1->ScrollToCaret();
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void updateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//UpdateForm^ updateForm = gcnew UpdateForm();
	//updateForm->Show();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	Application::Exit();

}
private: System::Void InkButton_Click(System::Object^  sender, System::EventArgs^  e) {

	if (!backgroundWorker1->IsBusy)
	{
		richTextBox1->Text += "Press the \'Enter\' Key to Select the Color\n";
		//colorStatus->Visible = true;
		InkButton->Enabled = false;
		backgroundWorker3->RunWorkerAsync();
	}

}
private: System::Void backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	HWND hwnd = ::FindWindow(NULL, _T("World of Warcraft"));
	CheckForIllegalCrossThreadCalls = false;

	POINT ptMouse;
	RECT windowPosition;
	COLORREF color;
	HDC hDC;
	BOOL b;

	while (true)
	{

		GetWindowRect(hwnd, &windowPosition);

		GetCursorPos(&ptMouse);

		hDC = GetDC(NULL);

		color = GetPixel(hDC, ptMouse.x, ptMouse.y);

		// Release the device context
		ReleaseDC(GetDesktopWindow(), hDC);

		pictureBox1->BackColor = Color::FromArgb(GetRValue(color), GetGValue(color), GetBValue(color));

		redColor = GetRValue(color);
		greenColor = GetGValue(color);
		blueColor = GetBValue(color);

		if (ScreenToClient(hwnd, &ptMouse))
		{
			startX = ptMouse.x;
			startY = ptMouse.y;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			//colorStatus->Visible = false;
			InkButton->Enabled = true;
			return;
		}

	}

}
private: System::Void bobPositionText_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void xValueText_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

	char keyCharacter = System::Convert::ToChar(e->KeyChar);

	if (isalpha(keyCharacter) || ispunct(keyCharacter))
	{
		e->Handled = true;
	}

}
private: System::Void yValueText_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void colorStatus_Click(System::Object^  sender, System::EventArgs^  e) {
}

bool ForceToForeground(HWND hWnd)
{
	HWND hForeground = GetForegroundWindow();

	int curThread = GetCurrentThreadId();
	int remoteThread = GetWindowThreadProcessId(hForeground, 0);

	AttachThreadInput(curThread, remoteThread, TRUE);
	SetForegroundWindow(hWnd);
	AttachThreadInput(curThread, remoteThread, FALSE);

	return GetForegroundWindow() == hWnd;
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	HWND hwnd = FindWindow(NULL, _T("World of Warcraft"));

	if (hwnd == NULL)
		MessageBox::Show("Error! Please open 'World of Warcraft'.");
	else {
		if (BringWindowToTop(hwnd) == false)
		{
			MessageBox::Show("Error! Please open 'World of Warcraft'.");
			return;
		}
		SetForegroundWindow(hwnd);

		Sleep(100);
		SetWindowPos(hwnd, 0, 0, 0, 1024, 768, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
		Sleep(100);
		screenshot(hwnd);
		richTextBox1->Text += "Screenshot Taken!\n";
	}

}

void GetWindowPos(HWND hWnd, int *x, int *y)
{
	HWND hWndParent = GetParent(hWnd);
	POINT p = { 0 };

	MapWindowPoints(hWnd, hWndParent, &p, 1);

	(*x) = p.x;
	(*y) = p.y;
}

private: System::Void calibrate_Click(System::Object^  sender, System::EventArgs^  e) {
	
	ScanArea^ scanArea = gcnew ScanArea();
	HWND newhwnd = FindWindow(NULL, _T("World of Warcraft"));
	if (newhwnd != NULL)
	{
		SetForegroundWindow(newhwnd);
		Sleep(100);
		SetWindowPos(newhwnd, 0, 0, 0, 1024, 768, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
		Sleep(100);
		if (!backgroundWorker4->IsBusy)
		{
			calibrate->Text = "CLOSE FISHING\n OVERLAY";
			scanArea->Show();
			backgroundWorker4->RunWorkerAsync();
		}
		else
		{
			calibrate->Text = "SHOW FISHING\n OVERLAY";
			//scanArea->Close();
			backgroundWorker4->CancelAsync();
		}
	}
	else
	{
		MessageBox::Show("Error! Please open 'World of Warcraft'\nBefore using the Overlay");
	}

}
private: System::Void backgroundWorker4_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

	HWND newhwnd = ::FindWindow(NULL, _T("World of Warcraft"));
	HWND hwnd = ::FindWindow(NULL, _T("Fish Scanner Window"));

	SetForegroundWindow(newhwnd);

	while (backgroundWorker4->CancellationPending == false)
	{
		if (hwnd == NULL || newhwnd == NULL)
			MessageBox::Show("Error! - 50");
		else {

			int x = 0;
			int y = 0;
			GetWindowPos(newhwnd, &x, &y); //Get x and y cords of our main window relative to the screen.
			SetWindowPos(hwnd, HWND_TOPMOST, x, y, 0, 0, SWP_NOSIZE);
		}
	}
	SendMessage(hwnd, WM_CLOSE, 0, 0);
	e->Cancel = true;

}

private: System::Void fishingWaitCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	//waitTimeTextBox
	if (fishingWaitCheck->CheckState != System::Windows::Forms::CheckState::Checked)
	{
		waitTimeTextBox->Enabled = false;
		waitTimeTextBox->Text = "17";
	}
	else
	{
		waitTimeTextBox->Enabled = true;
	}
}

private: System::Void dark_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (dark->CheckState == System::Windows::Forms::CheckState::Checked)
	{
		//darkText->Text = "Dark Mode On";
		mode = 2;
	}
	else
	{
		//darkText->Text = "Dark Mode Off";
		mode = 1;
	}

}

private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox1->CheckState == System::Windows::Forms::CheckState::Checked) {
		clickFishingRod = true;
	}
	else {
		clickFishingRod = false;
	}
}
};

}
