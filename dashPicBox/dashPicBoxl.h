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

	//��������� ����������
	public: void Draw(PaintEventArgs^ e) {
		//���� �������� ���������
		if (this->BackgroundImage != nullptr) {
			//����������� �������� �� ����������
			Bitmap^ bitmap = gcnew Bitmap(this->BackgroundImage);
			Graphics^ g = e->Graphics;
			int x1, y1;

			//��������� ����� �������� �������
			Color mask = bitmap->GetPixel(0, 0);
			//��������� ������ ��������
			int WidthX = bitmap->Width / this->KolPics;

			//������� ���� �������� �� X
			for (int x = PicIndex * WidthX; x < PicIndex * WidthX + WidthX; x++)
			{
				//������� ���� �������� �� Y
				for (int y = 0; y < bitmap->Height; y++)
				{
					//���� ���� �������� ������� ���������� �� ����� �������� �������
					if (!bitmap->GetPixel(x, y).Equals(mask))
					{
						//�������� ����� ������ �����
						SolidBrush^ aBrush = gcnew SolidBrush(bitmap->GetPixel(x, y));
						//��������� ������ �������
						g->FillRectangle(aBrush, x - (PicIndex * WidthX) + this->Left, y + this->Top, 1, 1);
					}
				}
			}
		}
	}

	//���������� ��������� �� ����� ������
	public: void Coordinates() {
		//���������� ���������� Y �� �������
		double y = SpeedX * Time * sin(Angle * Math::PI / 180) - g * Time * Time / 2;

		//���� ��������� ���������� ���� ������ �����
		if (PrevLand - int(y) > Land)
			//���������� ������
			Top = Land - Height;
		else
			//����������� ���������� ����������
			Top = PrevLand - int(y) - Height;

		//���� ������ ������ ������
		if (State == 2) {
			//���� �� ����� �� ��������� ��������
			if (PicIndex >= KolPics - 1) {
				//��������� ������� ��������
				PicIndex = 0;
				//������ ��������� � ��������� 1
				State = 1;
				//����������� �������������� �����
				_Coins += 5;
			}
			else
				//����������� ������� ��������
				PicIndex++;
		}		
	}

	//����� ��������� ���������� ��������� 
	public: void GetState(dashPicBoxl^ c, int coord) {
		//������ ����� �� �����
		if (State == 0) {
			//���� ����������� � ������������ �� X
			if (isIntersectingX(c)) {
				//���� ����������� � ������������� �� Y
				if (c->Top < Land && Left < c->Left)
					State = 4;
			}
			else
				//������ �������� ��������������
				if (c->Top == Land) {
					PrevLand = Land;
					Land = coord;
					Angle = 0;
					State = 3;
				}
		}
		else 
			//������ ������ ������/������/��������������
			if (State >= 1 && State <= 3) {
				//���� ����������� � ������������ �� X
				if (isIntersectingX(c)) {
					//���� ����������� ���� ������ �����
					if (c->Top > Land)
						//����������� ���������� ������ �����
						NewLand = c->Top;
					//���� ����������� �� ���� ������ �����
					else {
						//��������� ������ ������ �����
						Land = c->Top;
						//��������� ������� ����� ��� ����
						NewLand = coord;
					}
					//���� ������ �����������
					if (Top + Height == Land){
						//���� ������ �������� ������� �� ����
						if (PicIndex != 0)
							State = 4;
						//����������� ���������
						else {
							//���������� �����
							if (State == 1) Points += _Coins;
							_Coins = 0;
							Time = 0;
							State = 0;
						}
					}
					else
						//������������
						if (Top + Height > Land && Left < c->Left)
							State = 4;
				}
				//����������� �� X � ���� �������� ���
				else {
					//���� ������� ����� ������ � ������� �����������
					if (Land == c->Top) {
						//���������� ������ ������ �����
						Land = NewLand;
						NewLand = coord;
					}
					else
						//���� ������ �����������
						if (Top + Height == Land) {
							//���� ������ �������� ������� �� ����
							if (PicIndex != 0) State = 4;
							//����������� ���������
							else {
								//���������� �����
								if (State == 1) Points += _Coins;
								Time = 0;
								State = 0;
								_Coins = 0;
							}
						}
				}			
			}
	}

	//�������� ����������� �� ��� X
	public: bool isIntersectingX(dashPicBoxl^ cntrl) {
		//����������� �������� �� ������ ����������
		Bitmap^ bitmap1 = gcnew Bitmap(this->BackgroundImage);
		//��������� ������ ��������
		int widthX1 = bitmap1->Width / this->KolPics;

		//����������� �������� �� ������ ����������
		Bitmap^ bitmap2 = gcnew Bitmap(cntrl->BackgroundImage);
		//��������� ������ ��������
		int widthX2 = bitmap2->Width / cntrl->KolPics;

		//��������� � ������� ���������� �������� �� �����������
		return !((Left > cntrl->Left + widthX2 / 3 * 2) || (Left + widthX1  < cntrl->Left));
	}

	public: bool isSliding(dashPicBoxl^ cntrl) {
		return ((Top + Height > cntrl->Top) && (Top + Height < cntrl->Top + 20));
	}

	//�������� ����������� �� ���� X Y
	public: bool isIntersectingXY(dashPicBoxl^ cntrl) {
		//����������� �������� �� ������ ����������
		Bitmap^ bitmap1 = gcnew Bitmap(this->BackgroundImage);
		//��������� ������ ��������
		int widthX1 = bitmap1->Width / this->KolPics;

		//����������� �������� �� ������ ����������
		Bitmap^ bitmap2 = gcnew Bitmap(cntrl->BackgroundImage);
		//��������� ������ ��������
		int widthX2 = bitmap2->Width / cntrl->KolPics;

		//��������� � ������� ���������� �������� �� �����������
		return !((Left > cntrl->Left + widthX2) || (Left + widthX1 < cntrl->Left) ||
				 (Top > cntrl->Top + bitmap2->Height) || (Top + bitmap1->Height < cntrl->Top));
	}

};
}
