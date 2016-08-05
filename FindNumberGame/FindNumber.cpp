#include"console.h"
#include<iostream>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include<fstream>
#define MAX 100

using namespace std;

int X = 4, Y = 0; // Tọa độ ô số đầu tiên tương ứng với phần tử đầu tiên mảng số.
int flag; // Biến này dùng để lưu tạm thời số vừa bị xóa
float thoiGian = 0;

bool Find(int a[], int n, int k) // Hàm tìm xem 1 số đã có trong mảng hay chưa
{
	for (int i = 0; i < n; i++)
		if (a[i] == k) return true;
	return false;
}
void InSo(int a[], int n) // số mảng số theo định dạng 10 x 10
{
	//In biên bên trái
	TextColor(14);
	for (int i = 0; i < 25; i++)
	{
		gotoXY(45, i);
		putchar(179);
	}

	//-----------------------------------------

	

	//-----------------------------------------
	int x = 0; // Tung độ
	int y = 0; // Hoành độ
	TextColor(200); // ô số đầu tiên có màu nền đỏ, tương ứng với vị trí con trỏ mặc định khi chưa di chuyển chọn số
	gotoXY(x += 4, y);
	printf("%3d", a[0]);
	TextColor(176); // các ô số khác có nền mày lam
	for (int i = 1; i < n; i++)
	{
		gotoXY(x += 4, y);
		printf("%3d", a[i]);
		if ((i + 1) % 10 == 0) // nếu đã in 10 số trên 1 dòng thì xuống hàng
		{
			y += 2;
			x = 0;
		}
	}
	TextColor(7); // set lại màu chữ mặc định
}

void DieuKhienSo(int a[]) // hàm di chuyển để chọn số bằng cách nhấn các phím mũi tên
{
	if (_kbhit())
	{
		if (GetAsyncKeyState(VK_LEFT) && X > 4)
		{
			// set lại màu nền lúc khởi tạo cho ô số trước đó
			if (a[Y / 2 * 10 + (X - 4) / 4] != 0) // nếu số trong mảng khác 0 thì set lại màu ô sô và điền số đó vào
			{
				gotoXY(X, Y);
				TextColor(176);
				printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]); // công thức liên hệ giữa tọa độ console và chỉ số mảng 
			}
			else // ngược lại xóa số đó(bằng cách in ra nền đen)
			{
				gotoXY(X, Y);
				TextColor(7);
				printf("%3c", ' ');
			}

			// đổi màu ô số đang được chọn

			gotoXY(X -= 4, Y);
			if (a[Y / 2 * 10 + (X - 4) / 4] != 0)
			{
				TextColor(200);
				printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
			}
			else
			{
				TextColor(200);
				printf("%3c", ' ');
			}
			TextColor(7);
		}
		else
			if (GetAsyncKeyState(VK_RIGHT) && X < 40)
			{
				if (a[Y / 2 * 10 + (X - 4) / 4] != 0) // nếu số trong mảng khác 0 thì set lại màu ô sô và điền số đó vào
				{
					gotoXY(X, Y);
					TextColor(176);
					printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
				}
				else // ngược lại xóa số đó(bằng cách in ra nền đen)
				{
					gotoXY(X, Y);
					TextColor(7);
					printf("%3c", ' ');
				}

				//------------------------------------------------

				gotoXY(X += 4, Y);
				if (a[Y / 2 * 10 + (X - 4) / 4] != 0)
				{
					TextColor(200);
					printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
				}
				else
				{
					TextColor(200);
					printf("%3c", ' ');
				}
				TextColor(7);
			}
			else
				if (GetAsyncKeyState(VK_UP) && Y > 0)
				{
					if (a[Y / 2 * 10 + (X - 4) / 4] != 0) // nếu số trong mảng khác 0 thì set lại màu ô sô và điền số đó vào
					{
						gotoXY(X, Y);
						TextColor(176);
						printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
					}
					else // ngược lại xóa số đó(bằng cách in ra nền đen)
					{
						gotoXY(X, Y);
						TextColor(7);
						printf("%3c", ' ');
					}
					//--------------------------------------------
					gotoXY(X, Y -= 2);
					if (a[Y / 2 * 10 + (X - 4) / 4] != 0)
					{
						TextColor(200);
						printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
					}
					else
					{
						TextColor(200);
						printf("%3c", ' ');
					}
					TextColor(7);
				}
				else
					if (GetAsyncKeyState(VK_DOWN) && Y < 18)
					{
						if (a[Y / 2 * 10 + (X - 4) / 4] != 0) // nếu số trong mảng khác 0 thì set lại màu ô sô và điền số đó vào
						{
							gotoXY(X, Y);
							TextColor(176);
							printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
						}
						else // ngược lại xóa số đó(bằng cách in ra nền đen)
						{
							gotoXY(X, Y);
							TextColor(7);
							printf("%3c", ' ');
						}
						//-----------------------------------------
						gotoXY(X, Y += 2);
						if (a[Y / 2 * 10 + (X - 4) / 4] != 0)
						{
							TextColor(200);
							printf("%3d", a[Y / 2 * 10 + (X - 4) / 4]);
						}
						else
						{
							TextColor(200);
							printf("%3c", ' ');
						}
						TextColor(7);
					}
	}
}

bool XuLyGame(int a[])
{
	if (_kbhit())
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (a[(X - 4) / 4 + Y / 2 * 10] != (flag + 1))
				return true;
			else
			{
				flag = a[(X - 4) / 4 + Y / 2 * 10]; // lưu số vừa xóa vào biến flag
				a[(X - 4) / 4 + Y / 2 * 10] = 0; // coi số trên màn hình đã xóa bằng cách cho số tương ứng trong mảng = 0
				gotoXY(X, Y);
				TextColor(7);
				printf("%3c", ' ');
				TextColor(5);
				gotoXY(47, 1);
				printf("So can xoa tiep theo: %d", flag + 1);
				return false;
			}
		}
	}
	// in ra thời gian
	thoiGian += 0.1f;
	gotoXY(47, 3);
	printf("Thoi gian: %0.1f", thoiGian);
	return false;
}

bool ThangGame(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			return false;
			break;
		}
	}
	return true;
}

void GioiThieuGame()
{
	fstream InFile;
	InFile.open("VeOSo.txt", ios::in);
	while (!InFile.eof())
	{
		char c = InFile.get();
		cout << c;
		Sleep(5);
	}
}


int main()
{
	int Board[MAX]; // Mảng chứa các số ngẫu nhiên từ 1 đến 100
	srand(unsigned int(time(0))); // Khởi tạo bộ sinh số ngẫu nhiên
	bool isOver;
	while (true)
	{
		clrscr();
		TextColor(3);
		GioiThieuGame();

		int luaChon;
		gotoXY(25, 15);
		TextColor(10);
		cout << "1.Choi game!";
		gotoXY(25, 17);
		cout << "2.Huong dan choi";
		do
		{
			gotoXY(0, 19);
			cout << "Nhap lua chon: ";
			cin >> luaChon;
		} while (luaChon <= 0 || luaChon > 2);
		if (luaChon == 1) break;
		else
		{
			clrscr();
			TextColor(4);
			printf("Su dung cac phim mui ten %c %c %c %c de di chuyen o chon so.",24,25,26,27);
			printf	("\nSu dung Space de xoa so.\nSo can xoa theo dung thu tu tang dan 1->100");
			printf("\nNhan phim bat ky de quay lai");
			char c = _getch();
			continue;
		}
	}
	clrscr();
	// Khởi tạo mảng số ngẫu nhiên từ 1 đến 100
	Board[0] = 1 + rand() % 100;
	for (int i = 0; i < MAX; i++)
	{
		int temp = 1 + rand() % 100;
		if (!Find(Board, MAX, temp))
			Board[i] = temp;
		else
			i -= 1;
	}
	InSo(Board, MAX);
	while (true)
	{

		DieuKhienSo(Board);

		isOver = XuLyGame(Board);

		if (isOver)
		{
			gotoXY(47, 4);
			printf("Ban thua roi!");
			gotoXY(47, 6);
			printf("Nhan Enter de thoat game");
			while (_getch() != 13);
			break;
		}

		if (ThangGame(Board, MAX))
		{
			gotoXY(47, 4);
			printf("Hoan thanh!");
			gotoXY(47, 6);
			printf("Nhan Enter de thoat game");
			while (_getch() != 13);
			break;
		}

		Sleep(100);
	}
	_getch();
	return 0;
}