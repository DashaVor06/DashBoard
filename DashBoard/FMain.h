#pragma once
#include <windows.h>
#include <stdbool.h>
#include <cmath>
#include <string>
#include <cstdlib> 
#include <ctime> 

namespace DashBoard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FMain
	/// </summary>
	public ref class FMain : public System::Windows::Forms::Form
	{
	public:
		property int Points;

		FMain(void)
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
		~FMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;
	private: dashPicBox::dashPicBoxl^ picbStoneSmall;
	private: dashPicBox::dashPicBoxl^ picbStoneBig;
	private: dashPicBox::dashPicBoxl^ picbMoon;
	private: dashPicBox::dashPicBoxl^ picbNumber3;
	private: dashPicBox::dashPicBoxl^ picbNumber2;
	private: dashPicBox::dashPicBoxl^ picbNumber1;
	private: dashPicBox::dashPicBoxl^ picbNumber0;
	private: dashPicBox::dashPicBoxl^ picbTreeFront;
	private: dashPicBox::dashPicBoxl^ picbTreeBack;
	private: dashPicBox::dashPicBoxl^ picbHuman;
	private: dashPicBox::dashPicBoxl^ picbCoin;
	private: Media::SoundPlayer^ playerJump = gcnew Media::SoundPlayer(".\\Sounds\\pryijka3.wav");
	private: Media::SoundPlayer^ playerCoin = gcnew Media::SoundPlayer(".\\Sounds\\metallicheskiy-zvon.wav");
	private: Media::SoundPlayer^ playerHooray = gcnew Media::SoundPlayer(".\\Sounds\\aplodismentyi.wav");

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int Speed = 5, DefaultLand = 0, prevPoints = 0, Time = 0;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FMain::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->picbTreeBack = (gcnew dashPicBox::dashPicBoxl());
			this->picbMoon = (gcnew dashPicBox::dashPicBoxl());
			this->picbCoin = (gcnew dashPicBox::dashPicBoxl());
			this->picbNumber0 = (gcnew dashPicBox::dashPicBoxl());
			this->picbNumber1 = (gcnew dashPicBox::dashPicBoxl());
			this->picbNumber2 = (gcnew dashPicBox::dashPicBoxl());
			this->picbNumber3 = (gcnew dashPicBox::dashPicBoxl());
			this->picbStoneBig = (gcnew dashPicBox::dashPicBoxl());
			this->picbStoneSmall = (gcnew dashPicBox::dashPicBoxl());
			this->picbHuman = (gcnew dashPicBox::dashPicBoxl());
			this->picbTreeFront = (gcnew dashPicBox::dashPicBoxl());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FMain::timer1_Tick);
			// 
			// picbTreeBack
			// 
			this->picbTreeBack->Alg = 1;
			this->picbTreeBack->Angle = 0;
			this->picbTreeBack->AutoSize = true;
			this->picbTreeBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbTreeBack.BackgroundImage")));
			this->picbTreeBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbTreeBack->Depth = 0;
			this->picbTreeBack->DigIndex = 0;
			this->picbTreeBack->KolPics = 1;
			this->picbTreeBack->Land = 0;
			this->picbTreeBack->Location = System::Drawing::Point(482, 299);
			this->picbTreeBack->Name = L"picbTreeBack";
			this->picbTreeBack->NewLand = 0;
			this->picbTreeBack->PicIndex = 0;
			this->picbTreeBack->Points = 0;
			this->picbTreeBack->PrevLand = 0;
			this->picbTreeBack->Size = System::Drawing::Size(120, 181);
			this->picbTreeBack->SpeedX = 50;
			this->picbTreeBack->State = 0;
			this->picbTreeBack->TabIndex = 4;
			this->picbTreeBack->Tag = L"d";
			this->picbTreeBack->Time = 0;
			this->picbTreeBack->Visible = false;
			// 
			// picbMoon
			// 
			this->picbMoon->Alg = 2;
			this->picbMoon->Angle = 0;
			this->picbMoon->AutoSize = true;
			this->picbMoon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbMoon.BackgroundImage")));
			this->picbMoon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbMoon->Depth = 0;
			this->picbMoon->DigIndex = 0;
			this->picbMoon->KolPics = 10;
			this->picbMoon->Land = 0;
			this->picbMoon->Location = System::Drawing::Point(778, 26);
			this->picbMoon->Name = L"picbMoon";
			this->picbMoon->NewLand = 0;
			this->picbMoon->PicIndex = 0;
			this->picbMoon->Points = 0;
			this->picbMoon->PrevLand = 0;
			this->picbMoon->Size = System::Drawing::Size(155, 151);
			this->picbMoon->SpeedX = 0;
			this->picbMoon->State = 0;
			this->picbMoon->TabIndex = 15;
			this->picbMoon->Tag = L"d";
			this->picbMoon->Time = 0;
			this->picbMoon->Visible = false;
			// 
			// picbCoin
			// 
			this->picbCoin->Alg = 1;
			this->picbCoin->Angle = 0;
			this->picbCoin->AutoSize = true;
			this->picbCoin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbCoin.BackgroundImage")));
			this->picbCoin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbCoin->Depth = 2;
			this->picbCoin->DigIndex = 0;
			this->picbCoin->KolPics = 1;
			this->picbCoin->Land = 0;
			this->picbCoin->Location = System::Drawing::Point(645, 250);
			this->picbCoin->Name = L"picbCoin";
			this->picbCoin->NewLand = 0;
			this->picbCoin->PicIndex = 0;
			this->picbCoin->Points = 0;
			this->picbCoin->PrevLand = 0;
			this->picbCoin->Size = System::Drawing::Size(68, 67);
			this->picbCoin->SpeedX = 100;
			this->picbCoin->State = 0;
			this->picbCoin->TabIndex = 14;
			this->picbCoin->Tag = L"d";
			this->picbCoin->Time = 0;
			this->picbCoin->Visible = false;
			// 
			// picbNumber0
			// 
			this->picbNumber0->Alg = 3;
			this->picbNumber0->Angle = 0;
			this->picbNumber0->AutoSize = true;
			this->picbNumber0->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbNumber0.BackgroundImage")));
			this->picbNumber0->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbNumber0->Depth = 0;
			this->picbNumber0->DigIndex = 3;
			this->picbNumber0->KolPics = 10;
			this->picbNumber0->Land = 0;
			this->picbNumber0->Location = System::Drawing::Point(714, 53);
			this->picbNumber0->Name = L"picbNumber0";
			this->picbNumber0->NewLand = 0;
			this->picbNumber0->PicIndex = 0;
			this->picbNumber0->Points = 0;
			this->picbNumber0->PrevLand = 0;
			this->picbNumber0->Size = System::Drawing::Size(29, 35);
			this->picbNumber0->SpeedX = 1;
			this->picbNumber0->State = 0;
			this->picbNumber0->TabIndex = 10;
			this->picbNumber0->Tag = L"d";
			this->picbNumber0->Time = 0;
			this->picbNumber0->Visible = false;
			// 
			// picbNumber1
			// 
			this->picbNumber1->Alg = 3;
			this->picbNumber1->Angle = 0;
			this->picbNumber1->AutoSize = true;
			this->picbNumber1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbNumber1.BackgroundImage")));
			this->picbNumber1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbNumber1->Depth = 0;
			this->picbNumber1->DigIndex = 2;
			this->picbNumber1->KolPics = 10;
			this->picbNumber1->Land = 0;
			this->picbNumber1->Location = System::Drawing::Point(684, 53);
			this->picbNumber1->Name = L"picbNumber1";
			this->picbNumber1->NewLand = 0;
			this->picbNumber1->PicIndex = 0;
			this->picbNumber1->Points = 0;
			this->picbNumber1->PrevLand = 0;
			this->picbNumber1->Size = System::Drawing::Size(29, 35);
			this->picbNumber1->SpeedX = 1;
			this->picbNumber1->State = 0;
			this->picbNumber1->TabIndex = 9;
			this->picbNumber1->Tag = L"d";
			this->picbNumber1->Time = 0;
			this->picbNumber1->Visible = false;
			// 
			// picbNumber2
			// 
			this->picbNumber2->Alg = 3;
			this->picbNumber2->Angle = 0;
			this->picbNumber2->AutoSize = true;
			this->picbNumber2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbNumber2.BackgroundImage")));
			this->picbNumber2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbNumber2->Depth = 0;
			this->picbNumber2->DigIndex = 1;
			this->picbNumber2->KolPics = 10;
			this->picbNumber2->Land = 0;
			this->picbNumber2->Location = System::Drawing::Point(648, 53);
			this->picbNumber2->Name = L"picbNumber2";
			this->picbNumber2->NewLand = 0;
			this->picbNumber2->PicIndex = 0;
			this->picbNumber2->Points = 0;
			this->picbNumber2->PrevLand = 0;
			this->picbNumber2->Size = System::Drawing::Size(30, 35);
			this->picbNumber2->SpeedX = 1;
			this->picbNumber2->State = 0;
			this->picbNumber2->TabIndex = 8;
			this->picbNumber2->Tag = L"d";
			this->picbNumber2->Time = 0;
			this->picbNumber2->Visible = false;
			// 
			// picbNumber3
			// 
			this->picbNumber3->Alg = 3;
			this->picbNumber3->Angle = 0;
			this->picbNumber3->AutoSize = true;
			this->picbNumber3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbNumber3.BackgroundImage")));
			this->picbNumber3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbNumber3->Depth = 0;
			this->picbNumber3->DigIndex = 0;
			this->picbNumber3->KolPics = 10;
			this->picbNumber3->Land = 0;
			this->picbNumber3->Location = System::Drawing::Point(613, 53);
			this->picbNumber3->Name = L"picbNumber3";
			this->picbNumber3->NewLand = 0;
			this->picbNumber3->PicIndex = 0;
			this->picbNumber3->Points = 0;
			this->picbNumber3->PrevLand = 0;
			this->picbNumber3->Size = System::Drawing::Size(29, 35);
			this->picbNumber3->SpeedX = 1;
			this->picbNumber3->State = 0;
			this->picbNumber3->TabIndex = 7;
			this->picbNumber3->Tag = L"d";
			this->picbNumber3->Time = 0;
			this->picbNumber3->Visible = false;
			// 
			// picbStoneBig
			// 
			this->picbStoneBig->Alg = 1;
			this->picbStoneBig->Angle = 0;
			this->picbStoneBig->AutoSize = true;
			this->picbStoneBig->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbStoneBig.BackgroundImage")));
			this->picbStoneBig->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbStoneBig->Depth = 1;
			this->picbStoneBig->DigIndex = 0;
			this->picbStoneBig->KolPics = 1;
			this->picbStoneBig->Land = 0;
			this->picbStoneBig->Location = System::Drawing::Point(648, 389);
			this->picbStoneBig->Name = L"picbStoneBig";
			this->picbStoneBig->NewLand = 0;
			this->picbStoneBig->PicIndex = 0;
			this->picbStoneBig->Points = 0;
			this->picbStoneBig->PrevLand = 0;
			this->picbStoneBig->Size = System::Drawing::Size(155, 165);
			this->picbStoneBig->SpeedX = 100;
			this->picbStoneBig->State = 0;
			this->picbStoneBig->TabIndex = 5;
			this->picbStoneBig->Tag = L"d";
			this->picbStoneBig->Time = 0;
			this->picbStoneBig->Visible = false;
			// 
			// picbStoneSmall
			// 
			this->picbStoneSmall->Alg = 1;
			this->picbStoneSmall->Angle = 0;
			this->picbStoneSmall->AutoSize = true;
			this->picbStoneSmall->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbStoneSmall.BackgroundImage")));
			this->picbStoneSmall->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbStoneSmall->Depth = 1;
			this->picbStoneSmall->DigIndex = 0;
			this->picbStoneSmall->KolPics = 1;
			this->picbStoneSmall->Land = 0;
			this->picbStoneSmall->Location = System::Drawing::Point(405, 433);
			this->picbStoneSmall->Name = L"picbStoneSmall";
			this->picbStoneSmall->NewLand = 0;
			this->picbStoneSmall->PicIndex = 0;
			this->picbStoneSmall->Points = 0;
			this->picbStoneSmall->PrevLand = 0;
			this->picbStoneSmall->Size = System::Drawing::Size(148, 121);
			this->picbStoneSmall->SpeedX = 100;
			this->picbStoneSmall->State = 0;
			this->picbStoneSmall->TabIndex = 3;
			this->picbStoneSmall->Tag = L"d";
			this->picbStoneSmall->Time = 0;
			this->picbStoneSmall->Visible = false;
			// 
			// picbHuman
			// 
			this->picbHuman->Alg = 0;
			this->picbHuman->Angle = 45;
			this->picbHuman->AutoSize = true;
			this->picbHuman->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbHuman.BackgroundImage")));
			this->picbHuman->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbHuman->Depth = 1;
			this->picbHuman->DigIndex = 0;
			this->picbHuman->KolPics = 12;
			this->picbHuman->Land = 0;
			this->picbHuman->Location = System::Drawing::Point(57, 433);
			this->picbHuman->Name = L"picbHuman";
			this->picbHuman->NewLand = 0;
			this->picbHuman->PicIndex = 0;
			this->picbHuman->Points = 0;
			this->picbHuman->PrevLand = 0;
			this->picbHuman->Size = System::Drawing::Size(133, 116);
			this->picbHuman->SpeedX = 100;
			this->picbHuman->State = 0;
			this->picbHuman->TabIndex = 0;
			this->picbHuman->Tag = L"d";
			this->picbHuman->Time = 0;
			this->picbHuman->Visible = false;
			// 
			// picbTreeFront
			// 
			this->picbTreeFront->Alg = 1;
			this->picbTreeFront->Angle = 0;
			this->picbTreeFront->AutoSize = true;
			this->picbTreeFront->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picbTreeFront.BackgroundImage")));
			this->picbTreeFront->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picbTreeFront->Depth = 0;
			this->picbTreeFront->DigIndex = 0;
			this->picbTreeFront->KolPics = 1;
			this->picbTreeFront->Land = 0;
			this->picbTreeFront->Location = System::Drawing::Point(787, 331);
			this->picbTreeFront->Name = L"picbTreeFront";
			this->picbTreeFront->NewLand = 0;
			this->picbTreeFront->PicIndex = 0;
			this->picbTreeFront->Points = 0;
			this->picbTreeFront->PrevLand = 0;
			this->picbTreeFront->Size = System::Drawing::Size(146, 246);
			this->picbTreeFront->SpeedX = 200;
			this->picbTreeFront->State = 0;
			this->picbTreeFront->TabIndex = 11;
			this->picbTreeFront->Tag = L"d";
			this->picbTreeFront->Time = 0;
			this->picbTreeFront->Visible = false;
			// 
			// FMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(954, 576);
			this->Controls->Add(this->picbTreeBack);
			this->Controls->Add(this->picbMoon);
			this->Controls->Add(this->picbCoin);
			this->Controls->Add(this->picbNumber0);
			this->Controls->Add(this->picbNumber1);
			this->Controls->Add(this->picbNumber2);
			this->Controls->Add(this->picbNumber3);
			this->Controls->Add(this->picbStoneBig);
			this->Controls->Add(this->picbStoneSmall);
			this->Controls->Add(this->picbHuman);
			this->Controls->Add(this->picbTreeFront);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &FMain::FMain_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FMain::FMain_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FMain::FMain_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion
	
	//Отрисовка формы
	private: System::Void FMain_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		for each (Control ^ control in this->Controls) {
			if (control->GetType() == picbHuman->GetType()) {
				dashPicBox::dashPicBoxl^ c = dynamic_cast<dashPicBox::dashPicBoxl^>(control);
				c->Draw(e);
			}
		} 
	}

	//Загрузка формы
	private: System::Void FMain_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Focus();
		DefaultLand = picbStoneBig->Top + picbStoneBig->Height;
		picbHuman->Land = DefaultLand;
		picbHuman->PrevLand = DefaultLand;
	}

	//Функция расчёта всех координат
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//Наращивание скорости со временем
		Time++;
		if (Time % 20 == 0) {
			Speed++;
			Time = 0;
		}

		//Расчёт координат для прыжка и соскальзывания
		if ((picbHuman->State >= 1) && (picbHuman->State <= 3)) {
			picbHuman->Time += 0.8;
			picbHuman->Coordinates();
		}

		//Перебор всех контролов формы
		for each(Control ^ control in this->Controls) {
			//Если тип совпадает с типом компоненты dashPicBox
			if (control->GetType() == picbHuman->GetType()) {
				//Приведение типа
				dashPicBox::dashPicBoxl^ c = dynamic_cast<dashPicBox::dashPicBoxl^>(control);

				/*В зависимости от алгоритма движения и анимации 
				производятся определённые действия*/
				switch (c->Alg) {
				case 1:
				case 2: {

					//Расчёт координаты
					c->Left -= Speed * c->SpeedX / 100;

					//Изменение индекса картинки
					if (++c->PicIndex == c->KolPics)
						c->PicIndex = 0;

					/*Если объект вышел за пределы экрана -
					переставить его в другую сторону за экран*/
					if ((c->Left + c->Width) < 0)
						c->Left = this->ClientSize.Width;

					//Запоминание счёта
					prevPoints = picbHuman->Points;

					//Если объект - препятствие
					if (c->Depth == 1) {

						//Получение следующего состояния главного героя
						picbHuman->GetState(c, DefaultLand);

						//Если число очков увеличилось - проиграть аплодисменты
						if (picbHuman->Points != prevPoints)
							playerHooray->Play();
					}

					//Если объект - бонус
					if (c->Depth == 2) {

						//Если главный герой пересекается с бонусом
						if (picbHuman->isIntersectingXY(c)) {
							//Проиграть звук монентки
							playerCoin->Play();
							//Увеличение очков за сбор монетки
							picbHuman->Points += 2;
							//Перенос монетки вправо за экран
							picbCoin->Left = this->ClientSize.Width;
							//Вычисление новой координаты Y для монентки
							int randCoord = rand() % 3;
							picbCoin->Top = this->ClientSize.Height / 4 * (randCoord + 1);
						}
					}
					break;
				}
				case 3: {

					//Перевод счёта в число и вывод на экран
					std::string str = std::to_string(picbHuman->Points);
					str.insert(str.begin(), 4 - str.length(), '0');
					c->PicIndex = std::stoi(str.substr((c->DigIndex), 1));
					break;
				}
				default:
					break;
				}
			}
		}

		//Перерисовка формы
		this->Invalidate();	

		//Если произошло столкновение
		if (picbHuman->State == 4) {
			//Остановка таймера
			timer1->Stop();
			//Изменение картинки и ее характеристик
			picbHuman->BackgroundImage = Image::FromFile(".\\pictures\\rip.png");
			picbHuman->KolPics = 1;
			picbHuman->PicIndex = 0;
			this->Refresh();
			Sleep(1000);

			//Присваивание полю формы количества очков
			this->Points = picbHuman->Points;
			//Закрытие формы
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		}
	}

	//Функция обработки нажатия клафиш
	private: System::Void FMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//Если нажата стрелка вверх
		if (e->KeyCode == Keys::Up) {
			//Если главный герой в состоянии прыжка
			if (picbHuman->State == 1)
				//То переходит в состояние сальто
				picbHuman->State = 2;

			//Если главный герой стоит на месте
			if (picbHuman->State == 0) {
				//Проиграть звук прыжка
				playerJump->Play();
				//Переходит в состояние прыжка
				picbHuman->State = 1;
				picbHuman->Angle = 45;
				//Запоминание предыдущего уровня земли
				picbHuman->PrevLand = picbHuman->Land;
			}
		}
	}
};
}
