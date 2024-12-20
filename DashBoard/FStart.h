#pragma once
#include "FMain.h"
#include <string>
#include <iostream>

namespace DashBoard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FStart
	/// </summary>
	public ref class FStart : public System::Windows::Forms::Form
	{
	public:
		property int Points;

		FStart(void)
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
		~FStart()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Label^ lbMain;
	private: System::Windows::Forms::Label^ lbScore;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int BestResult = 0;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FStart::typeid));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lbMain = (gcnew System::Windows::Forms::Label());
			this->lbScore = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStart->Location = System::Drawing::Point(397, 205);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(186, 70);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Начать";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &FStart::btnStart_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->Location = System::Drawing::Point(397, 300);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(186, 71);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Выход";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &FStart::btnExit_Click);
			// 
			// lbMain
			// 
			this->lbMain->AutoSize = true;
			this->lbMain->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbMain->Location = System::Drawing::Point(371, 9);
			this->lbMain->Name = L"lbMain";
			this->lbMain->Size = System::Drawing::Size(224, 46);
			this->lbMain->TabIndex = 2;
			this->lbMain->Text = L"Dashboard";
			this->lbMain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbScore
			// 
			this->lbScore->AutoSize = true;
			this->lbScore->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->lbScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbScore->Location = System::Drawing::Point(373, 55);
			this->lbScore->Name = L"lbScore";
			this->lbScore->Size = System::Drawing::Size(205, 31);
			this->lbScore->TabIndex = 3;
			this->lbScore->Text = L"Лучший счёт: 0";
			this->lbScore->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lbScore->Visible = false;
			// 
			// FStart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(954, 576);
			this->Controls->Add(this->lbScore);
			this->Controls->Add(this->lbMain);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnStart);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FStart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	//Начало игры
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		//Создание главной форсмы
		FMain^ formMain = gcnew FMain();
		//Скрытие стартовой формы
		this->Hide();
		//Открытие основной формы в качестве модальной
		formMain->ShowDialog();

		//Копирование очков из главной формы
		this->Points = formMain->Points;
		//Если новый результат больше лучшего
		if (this->Points > BestResult)
			//Запись нового лучщего результата
			BestResult = this->Points;
		//Закрытие основной формы
		formMain->Close();

		//Отображение метки
		lbScore->Visible = true;
		//Вывод текста с результататми
		lbScore->Text = "Ваш счёт: " + System::Convert::ToString(this->Points) + "\nЛучший счёт: " + System::Convert::ToString(BestResult);
		//Открытие стартовой формы
		this->Show();
	}

	//Выход из игры
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		//Закрытие формы
		this->Close();
	}
};
}
