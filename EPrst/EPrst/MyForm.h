#pragma once
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS 1
#pragma comment (lib, "netapi32.lib")
#ifndef UNICODE
#define UNICOD
#endif
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <Windows.h>
#include <locale.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <lm.h>
#include "MathLibrary.h"
#include "MyForm1.h"
#pragma warning(disable : 4716)

using namespace std;

HANDLE out;
HANDLE hSemaphore;
HANDLE hThread;

DWORD WINAPI Sort(LPVOID)
{
	string buffer = "";
	string buff = "";
	vector<string> v1(10);
	string path = "input.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		v1.clear();
		getline(fs, buffer);
		for (int i = 0; i < 10; i++)
		{
			v1.push_back(buffer.substr(i * 10, 10));
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << v1[i] << endl;
	};
	sort(v1.begin(), v1.end(), greater<>());
	for (int i = 0; i < 10; i++)
	{
		cout << v1[i] << endl;
		buff += v1[i];
		buff += '\n';
	}
	WriteFile(out, buff.c_str(), 110, NULL, NULL);
	ReleaseSemaphore(hSemaphore, 1, NULL);
	return 0;
}


namespace EPrst {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;










	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(119, 416);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 81);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить данные \r\nиз исходного файла";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(23, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(295, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Чернятинская Анна Сергеевна";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(23, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Группа 501";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(500, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Текущая дата: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(488, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(164, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Текущее время:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(36, 119);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(737, 221);
			this->textBox1->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(396, 416);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(199, 81);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Отсортировать данные и записать их в файл\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(806, 541);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ filename;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try 
		{
			filename = "C:\input.txt";
			System::Text::Encoding^ Code = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ Reader = gcnew IO::StreamReader(filename, Code);
			textBox1->Text = Reader->ReadToEnd();
			Reader->Close();
		}
		catch (IO::FileNotFoundException^ Ситуация)
		{ 
			MessageBox::Show(Ситуация->Message + "\nНет такого файла",
				"Ошибка", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
		catch (Exception^ Ситуация)
		{
			MessageBox::Show(Ситуация->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ NewForm = gcnew MyForm1();
		this->Hide();
		NewForm->ShowDialog();
		this->Show();
		time_t now = time(0);
		tm* date_time = localtime(&now);
		label3->Text += "   " + date_time->tm_mday + "." + (1 + date_time->tm_mon) + "." + (date_time->tm_year + 1900);
		label4->Text += "   " + date_time->tm_hour + ":" + date_time->tm_min + ":" + date_time->tm_sec;
		textBox1->Multiline = true; 
		// textBox1->Clear();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		out = CreateFile(L"output.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (out == INVALID_HANDLE_VALUE)
			cout << "Файл не создан " << GetLastError() << endl;
		else {
			hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
			hThread = CreateThread(NULL, 0, Sort, NULL, 0, NULL);
			WaitForSingleObject(hSemaphore, INFINITE);
		}
		CloseHandle(out);
		try
		{
			filename = "C:\output.txt";
			System::Text::Encoding^ Code = System::Text::Encoding::GetEncoding(1251);
			// IO::StreamReader^ Reader = gcnew IO::StreamReader(filename, Code);
			cli::array <String^> ^МассивСтрок = IO::File::ReadAllLines("C:\output.txt", Code);
			textBox1->Lines = МассивСтрок;
			// textBox1->Text = Reader->ReadToEnd();
			// Reader->Close();
		}
		catch (IO::FileNotFoundException^ Ситуация)
		{
			MessageBox::Show(Ситуация->Message + "\nНет такого файла",
				"Ошибка", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
		catch (Exception^ Ситуация)
		{
			MessageBox::Show(Ситуация->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
  
};
}
