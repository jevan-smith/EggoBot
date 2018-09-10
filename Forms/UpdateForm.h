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

//#ifdef _DEBUG
//#pragma comment(lib, "curl/libcurl_a_debug.lib")
//#endif

namespace Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for UpdateForm
	/// </summary>
	public ref class UpdateForm : public System::Windows::Forms::Form
	{
	public:
		UpdateForm(void)
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
		~UpdateForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  checkupdate;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  Update;




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
			this->checkupdate = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Update = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkupdate
			// 
			this->checkupdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->checkupdate->AutoSize = true;
			this->checkupdate->Location = System::Drawing::Point(80, 30);
			this->checkupdate->Name = L"checkupdate";
			this->checkupdate->Size = System::Drawing::Size(110, 13);
			this->checkupdate->TabIndex = 0;
			this->checkupdate->Text = L"Checking for Updates";
			this->checkupdate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &UpdateForm::backgroundWorker1_DoWork);
			// 
			// Update
			// 
			this->Update->Location = System::Drawing::Point(96, 64);
			this->Update->Name = L"Update";
			this->Update->Size = System::Drawing::Size(75, 23);
			this->Update->TabIndex = 1;
			this->Update->Text = L"Update";
			this->Update->UseVisualStyleBackColor = true;
			this->Update->Click += gcnew System::EventHandler(this, &UpdateForm::Update_Click);
			// 
			// UpdateForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(272, 105);
			this->Controls->Add(this->Update);
			this->Controls->Add(this->checkupdate);
			this->Name = L"UpdateForm";
			this->Text = L"Update";
			this->Load += gcnew System::EventHandler(this, &UpdateForm::UpdateForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void UpdateForm_Load(System::Object^  sender, System::EventArgs^  e) {
		remove("EggoBotOLD.exe");
		remove("update");
		Update->Enabled = false;
		backgroundWorker1->RunWorkerAsync();
		
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		CheckForIllegalCrossThreadCalls = false;
		string currentVersion = "v2.0.0"; // <<--------- CHANGE VERSION HERE

		HRESULT hr = URLDownloadToFile(NULL, _T("https://dl.dropbox.com/s/7clpaad6q0qn3kp/update.txt?dl=0"), _T("./update.txt"), 0, NULL);

		ifstream updateFile;
		vector<string> vec;
		string line;
		int counter = 0;
		updateFile.open("update.txt");

		if (hr == 0) {

			while (!updateFile.eof())
			{
				getline(updateFile, line, '\n');
				vec.push_back(line);
				counter++;
				line.clear();
			}

			updateFile.close();

			Sleep(1000);

			if (vec[0] != currentVersion)
			{
				checkupdate->Text = L"New Version Avaliable";
				Update->Enabled = true;
			}
			else
			{
				checkupdate->Text = L"No New Updates Avaliable";
				checkupdate->Location = System::Drawing::Point(68, 30);
			}

		}
		else {

			checkupdate->Text = L"Failed";

		}
	}

	private: System::Void Update_Click(System::Object^  sender, System::EventArgs^  e) {

		ifstream updateFile;
		vector<string> vec;
		string line;
		int counter = 0;
		updateFile.open("update.txt");


		while (!updateFile.eof())
		{
			getline(updateFile, line, '\n');
			vec.push_back(line);
			counter++;
			line.clear();
		}

		updateFile.close();

		std::string s = vec[2];
		// get temporary LPSTR (not really safe)
		LPSTR pst = &s[0];
		// get temporary LPCSTR (pretty safe)
		LPCSTR pcstr = s.c_str();
		// convert to std::wstring
		std::wstring ws;
		ws.assign(s.begin(), s.end());
		// get temporary LPWSTR (not really safe)
		LPWSTR pwst = &ws[0];
		// get temporary LPCWSTR (pretty safe)
		LPCWSTR pcwstr = ws.c_str();

		HRESULT hr = URLDownloadToFile(NULL, (pcwstr), _T("./EggoBotNEW.exe"), 0, NULL);

		rename("EggoBot.exe", "EggoBotOLD.exe");
		//Sleep(1000);
		rename("EggoBotNEW.exe", "EggoBot.exe");

		Application::Restart();

	}
};
}
