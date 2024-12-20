#pragma once
#include <cmath>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace dashPicBox {

	/// <summary>
	/// Summary for dashPicBoxl
	/// </summary>
	public ref class dashPicBoxl : public System::Windows::Forms::UserControl
	{
	public:
		dashPicBoxl(void)
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
		~dashPicBoxl()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		const double g = 9.81;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// dashPicBoxl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Name = L"dashPicBoxl";
			this->Size = System::Drawing::Size(111, 107);
			this->ResumeLayout(false);
			

		}
#pragma endregion

	private: int _kolPics = 0;
	public: property int KolPics {
		int get() {
			return _kolPics;
		}
		void set(int num) {
			_kolPics = num;
		}
	}

	private: int _PicIndex = 0;
	public: property int PicIndex {
		int get() {
			return _PicIndex;
		}
		void set(int num) {
			_PicIndex = num;
		}
	}

	private: int _Alg = 0;
	public: property int Alg{
		int get() {
			return _Alg;
		}
		void set(int num) {
			_Alg = num;
		}
	}

	private: int _DigIndex = 0;
	public: property int DigIndex{
		int get() {
			return _DigIndex;
		}
		void set(int num) {
			_DigIndex = num;
		}
	}

	private: int _Angle = 0;
	public: property int Angle{
		int get() {
			return _Angle;
		}
		void set(int num) {
			_Angle = num;
		}
	}

	private: int _SpeedX = 0;
	public: property int SpeedX{
		int get() {
			return _SpeedX;
		}
		void set(int num) {
			_SpeedX = num;
		}
	}

	private: double _Time = 0;
	public: property double Time{
		double get() {
			return _Time;
		}
		void set(double num) {
			_Time = num;
		}
	}

	private: int _Depth = 0;
	public: property int Depth {
		int get() {
			return _Depth;
		}
		void set(int num) {
			_Depth = num;
		}
	}

	private: int _State = 0;
	public: property int State{
		int get() {
			return _State;
		}
		void set(int num) {
			_State = num;
		}
	}

	private: int _Land = 0;
	public: property int Land {
		int get() {
			return _Land;
		}
		void set(int num) {
			_Land = num;
		}
	}

	private: int _PrevLand = 0;
	public: property int PrevLand {
		int get() {
			return _PrevLand;
		}
		void set(int num) {
			_PrevLand = num;
		}
	}

	private: int _NewLand = 0;
	public: property int NewLand{
		int get() {
			return _NewLand;
		}
		void set(int num) {
			_NewLand = num;
		}
	}

	private: int _Points = 0;
	public: property int Points {
		int get() {
			return _Points;
		}
		void set(int num) {
			_Points = num;
		}
	}

	private: int _Coins = 0;

	//Отрисовка компоненты
	public: void Draw(PaintEventArgs^ e) {
		//Если картинка загружена
		if (this->BackgroundImage != nullptr) {
			//Копирование картинки из компоненты
			Bitmap^ bitmap = gcnew Bitmap(this->BackgroundImage);
			Graphics^ g = e->Graphics;
			int x1, y1;

			//Получение цвета нулевого пикселя
			Color mask = bitmap->GetPixel(0, 0);
			//Получение ширины картинки
			int WidthX = bitmap->Width / this->KolPics;

			//Перебор всех пикселей по X
			for (int x = PicIndex * WidthX; x < PicIndex * WidthX + WidthX; x++)
			{
				//Перебор всех пикселей по Y
				for (int y = 0; y < bitmap->Height; y++)
				{
					//Если цвет текущего пикселя отличается от цвета нулевого пикселя
					if (!bitmap->GetPixel(x, y).Equals(mask))
					{
						//Создание кисти такого цвета
						SolidBrush^ aBrush = gcnew SolidBrush(bitmap->GetPixel(x, y));
						//Отрисовка одного пикселя
						g->FillRectangle(aBrush, x - (PicIndex * WidthX) + this->Left, y + this->Top, 1, 1);
					}
				}
			}
		}
	}

	//Вычисление координат во время прыжка
	public: void Coordinates() {
		//Вычисление координаты Y по формуле
		double y = SpeedX * Time * sin(Angle * Math::PI / 180) - g * Time * Time / 2;

		//Если следующая координата ниже уровня земли
		if (PrevLand - int(y) > Land)
			//Приземляем объект
			Top = Land - Height;
		else
			//Присваиваем полученную координату
			Top = PrevLand - int(y) - Height;

		//Если объект делает сальто
		if (State == 2) {
			//Если он дошёл до последней картинки
			if (PicIndex >= KolPics - 1) {
				//Зануление индекса картинки
				PicIndex = 0;
				//Объект переходит в состояние 1
				State = 1;
				//Наращивание промежуточного счёта
				_Coins += 5;
			}
			else
				//Наращивание индекса картинки
				PicIndex++;
		}		
	}

	//Метод получения следующего состояния 
	public: void GetState(dashPicBoxl^ c, int coord) {
		//Объект стоит на месте
		if (State == 0) {
			//Есть пересечение с препятствием по X
			if (isIntersectingX(c)) {
				//Есть пересечение с препятстсвием по Y
				if (c->Top < Land && Left < c->Left)
					State = 4;
			}
			else
				//Объект начинает соскальзывание
				if (c->Top == Land) {
					PrevLand = Land;
					Land = coord;
					Angle = 0;
					State = 3;
				}
		}
		else 
			//Объект делает прыжок/сальто/соскальзывание
			if (State >= 1 && State <= 3) {
				//Есть пересечение с препятствием по X
				if (isIntersectingX(c)) {
					//Если препятствие ниже уровня земли
					if (c->Top > Land)
						//Запоминание следующего уровня земли
						NewLand = c->Top;
					//Если препятствие не ниже уровня земли
					else {
						//Получение нового уровня земли
						Land = c->Top;
						//Следующим уровнем будет низ окна
						NewLand = coord;
					}
					//Если объект приземлился
					if (Top + Height == Land){
						//Если индекс картинки отличен от нуля
						if (PicIndex != 0)
							State = 4;
						//Приземлился правильно
						else {
							//Начисление очков
							if (State == 1) Points += _Coins;
							_Coins = 0;
							Time = 0;
							State = 0;
						}
					}
					else
						//Столкновение
						if (Top + Height > Land && Left < c->Left)
							State = 4;
				}
				//Пересечения по X с этим объектом нет
				else {
					//Если уровень земли совпал с высотой препятствия
					if (Land == c->Top) {
						//Присвоение нового уровня земли
						Land = NewLand;
						NewLand = coord;
					}
					else
						//Если объект приземлился
						if (Top + Height == Land) {
							//Если индекс картинки отличен от нуля
							if (PicIndex != 0) State = 4;
							//Приземлился правильно
							else {
								//Начисление очков
								if (State == 1) Points += _Coins;
								Time = 0;
								State = 0;
								_Coins = 0;
							}
						}
				}			
			}
	}

	//Проверка пересечения по оси X
	public: bool isIntersectingX(dashPicBoxl^ cntrl) {
		//Копирование картинки из первой компоненты
		Bitmap^ bitmap1 = gcnew Bitmap(this->BackgroundImage);
		//Получение щирины картинки
		int widthX1 = bitmap1->Width / this->KolPics;

		//Копирование картинки из второй компоненты
		Bitmap^ bitmap2 = gcnew Bitmap(cntrl->BackgroundImage);
		//Получение щирины картинки
		int widthX2 = bitmap2->Width / cntrl->KolPics;

		//Получение и возврат результата проверки на пересечение
		return !((Left > cntrl->Left + widthX2 / 3 * 2) || (Left + widthX1  < cntrl->Left));
	}

	public: bool isSliding(dashPicBoxl^ cntrl) {
		return ((Top + Height > cntrl->Top) && (Top + Height < cntrl->Top + 20));
	}

	//Проверка пересечения по осям X Y
	public: bool isIntersectingXY(dashPicBoxl^ cntrl) {
		//Копирование картинки из первой компоненты
		Bitmap^ bitmap1 = gcnew Bitmap(this->BackgroundImage);
		//Получение щирины картинки
		int widthX1 = bitmap1->Width / this->KolPics;

		//Копирование картинки из второй компоненты
		Bitmap^ bitmap2 = gcnew Bitmap(cntrl->BackgroundImage);
		//Получение щирины картинки
		int widthX2 = bitmap2->Width / cntrl->KolPics;

		//Получение и возврат результата проверки на пересечение
		return !((Left > cntrl->Left + widthX2) || (Left + widthX1 < cntrl->Left) ||
				 (Top > cntrl->Top + bitmap2->Height) || (Top + bitmap1->Height < cntrl->Top));
	}

};
}
