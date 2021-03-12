#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
void fail()
{
	cout << "\n+----------+\n";
	cout << "|Try again!|\n";
	cout << "+----------+\n\n";
}
enum ConsoleColor
{
	Black = 0,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Brown = 6,
	White = 15
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int main(int argc, char** argv) {
	system("color F0");
	srand(unsigned(time(NULL)));
	string symbol, results, empty = " ", enemy, hard = "Hard", mode = "computer";
	short int h = 0, a, b, m, n, k = 0, x, y, l, menu, complexity = 3, select;
	cout << "\t\t\t\t\t\t    +-----------+\n";
	cout << "\t\t\t\t\t\t   ~|TIC TAC TOE|~\n";
	cout << "\t\t\t\t\t\t    +-----------+\n";
trail:
	SetColor(Black, White);
	cout << "\nYour game mod: ";
	if (mode == "1 vs 1")
	{
		SetColor(Cyan, White);
		cout << mode;
	}
	if (mode == "computer")
	{
		SetColor(Red, White);
		cout << mode;
	}
	SetColor(Black, White);
	k = 0;
	cout << "\n\n1 - Start game.\n";
	cout << "2 - Select other game mod.\n";
	cout << "Enter:";
	cin >> menu;
	switch (menu)
	{
	case 1: break;
	case 2: cout << "Choose your mod:"
		<< " 1 - 1 versus 1\n"
		<< "\t\t 2 - Versus computer\n"
		<< "Enter:";
		cin >> select;
		switch (select)
		{
		case 1: mode = "1 vs 1";
			cout << endl;
			goto trail;
		case 2: mode = "computer";
			cout << endl;
			goto trail;
		default: fail(); goto trail;
		}
	default: fail(); goto trail;
	}
	if (mode == "computer")
	{
	no:
		cout << "Choose your complexity:"
			<< " 1 - Easy\n"
			<< "\t\t\t2 - Normal\n"
			<< "\t\t\t3 - Hard\n"
			<< "\t\t\t4 - Uber\n"
			<< "Enter:";
		cin >> complexity;
		switch (complexity)
		{
		case 1: hard = "Easy";
			cout << endl;
			break;
		case 2: hard = "Normal";
			cout << endl;
			break;
		case 3: hard = "Hard";
			cout << endl;
			break;
		case 4: hard = "Uber";
			cout << endl;
			break;
		default: fail();
			goto no;
		}
		cout << "Your complexity: ";
		if (hard == "Easy")
		{
			SetColor(Green, White);
			cout << hard;
		}
		if (hard == "Normal")
		{
			SetColor(Cyan, White);
			cout << hard;
		}
		if (hard == "Hard")
		{
			SetColor(Brown, White);
			cout << hard;
		}
		if (hard == "Uber")
		{
			SetColor(Red, White);
			cout << hard;
		}
	}
	SetColor(Black, White);
choose:
	cout << "\nChoose your symbol, X or O:";
	cin >> symbol;
	string c[3][3];
	if (symbol == "X" || symbol == "O")
	{
		if (symbol == "X")
		{
			enemy = "O";
		}
		else
		{
		}
		if (symbol == "O")
		{
			enemy = "X";
		}
		else
		{
		}
		h = 0;
		for (int i = 0; i < 3; i++)
		{
			cout << "+---+---+---+" << endl;
			for (int j = 0; j < 3; j++)
			{
				c[i][j] = empty;
				cout << "| " << c[i][j] << ' ';
			}
			cout << "|" << endl;
		}
		cout << "+---+---+---+\n";
		do
		{
			k++;
		ron:
			// Ход игрока
			if (mode == "1 vs 1")
			{
				cout << "\nFirst player is going\n";
			}
			cout << "Enter counters:\n";
			cout << "Gorisontal: ";
			cin >> a;
			cout << "Vertical: ";
			cin >> b;

			if (c[a][b] != symbol && c[a][b] != enemy && a >= 0 && a < 3 && b >= 0 && b < 3)
			{
				c[a][b] = symbol;
			}
			else
			{
				if (a == 24 || b == 24)
				{
					goto trail;
				}
				fail();
				goto ron;
			}
			// Конец хода игрока
			// Проверка на победу 1
			if ((c[0][0] == symbol && c[0][1] == symbol && c[0][2] == symbol) || (c[1][0] == symbol && c[1][1] == symbol && c[1][2] == symbol) || (c[2][0] == symbol && c[2][1] == symbol && c[2][2] == symbol) ||
				(c[0][0] == symbol && c[1][0] == symbol && c[2][0] == symbol) || (c[0][1] == symbol && c[1][1] == symbol && c[2][1] == symbol) || (c[0][2] == symbol && c[1][2] == symbol && c[2][2] == symbol) ||
				(c[0][0] == symbol && c[1][1] == symbol && c[2][2] == symbol) || (c[2][0] == symbol && c[1][1] == symbol && c[0][2] == symbol))
			{
				h = 1;
				break;
			}
			if ((c[0][0] == enemy && c[0][1] == enemy && c[0][2] == enemy) || (c[1][0] == enemy && c[1][1] == enemy && c[1][2] == enemy) || (c[2][0] == enemy && c[2][1] == enemy && c[2][2] == enemy) ||
				(c[0][0] == enemy && c[1][0] == enemy && c[2][0] == enemy) || (c[0][1] == enemy && c[1][1] == enemy && c[2][1] == enemy) || (c[0][2] == enemy && c[1][2] == enemy && c[2][2] == enemy) ||
				(c[0][0] == enemy && c[1][1] == enemy && c[2][2] == enemy) || (c[2][0] == enemy && c[1][1] == enemy && c[0][2] == enemy))
			{
				h = 2;
				break;
			}
			l = 0;
			// Ход компьюетера
			if (k < 5)
			{
				if (mode == "computer")
				{
					// Победа компьютера
					for (int z = 0; z < 3; z++)
					{
						if (c[1][1] == empty && complexity != 1)
						{
							c[1][1] = enemy;
							break;
						}
						if ((c[0][0] == enemy && c[1][1] == enemy && c[2][2] == empty) || (c[0][0] == enemy && c[1][1] == empty && c[2][2] == enemy) || (c[0][0] == empty && c[1][1] == enemy && c[2][2] == enemy))
						{
							for (int v = 0; v < 3; v++)
							{
								if (c[v][v] == empty)
								{
									c[v][v] = enemy;
								}
							}
							break;
						}
						if ((c[0][2] == enemy && c[1][1] == enemy && c[2][0] == empty) || (c[0][2] == enemy && c[1][1] == empty && c[2][0] == enemy) || (c[0][2] == empty && c[1][1] == enemy && c[2][0] == enemy))
						{
							if (c[0][2] == enemy && c[1][1] == enemy && c[2][0] == empty)
							{
								c[2][0] = enemy;
							}
							if (c[0][2] == enemy && c[1][1] == empty && c[2][0] == enemy)
							{
								c[1][1] = enemy;
							}
							if (c[0][2] == empty && c[1][1] == enemy && c[2][0] == enemy)
							{
								c[0][2] = enemy;
							}
							break;
						}
						for (int o = 0; o < 3; o++)
						{
							if ((c[o][0] == empty && c[o][1] == enemy && c[o][2] == enemy) || (c[o][0] == enemy && c[o][1] == empty && c[o][2] == enemy) || (c[o][0] == enemy && c[o][1] == enemy && c[o][2] == empty))
							{
								do
								{
									n = rand() % 3;
								} while (c[o][n] == enemy);
								c[o][n] = enemy;
								l = 1;
								break;
							}
						}
						if (l == 1)
						{
							break;
						}
						for (int o = 0; o < 3; o++)
						{
							if ((c[0][o] == empty && c[1][o] == enemy && c[2][o] == enemy) || (c[0][o] == enemy && c[1][o] == empty && c[2][o] == enemy) || (c[0][o] == enemy && c[1][o] == enemy && c[2][o] == empty))
							{
								do
								{
									m = rand() % 3;
								} while (c[m][o] == enemy);
								c[m][o] = enemy;
								l = 1;
								break;
							}
						}
						if (l == 1)
						{
							break;
						}
						// Конец победы компьютера
						// Блокировка победы
						if ((c[0][0] == symbol && c[1][1] == symbol && c[2][2] == empty) || (c[0][0] == symbol && c[1][1] == empty && c[2][2] == symbol) || (c[0][0] == empty && c[1][1] == symbol && c[2][2] == symbol) && complexity != 1)
						{
							for (int v = 0; v < 3; v++)
							{
								if (c[v][v] == empty)
								{
									c[v][v] = enemy;
								}
							}
							break;
						}
						if ((c[0][2] == symbol && c[1][1] == symbol && c[2][0] == empty) || (c[0][2] == symbol && c[1][1] == empty && c[2][0] == symbol) || (c[0][2] == empty && c[1][1] == symbol && c[2][0] == symbol) && complexity != 1)
						{
							if (c[0][2] == symbol && c[1][1] == symbol && c[2][0] == empty)
							{
								c[2][0] = enemy;
							}
							if (c[0][2] == symbol && c[1][1] == empty && c[2][0] == symbol)
							{
								c[1][1] = enemy;
							}
							if (c[0][2] == empty && c[1][1] == symbol && c[2][0] == symbol)
							{
								c[0][2] = enemy;
							}
							break;
						}
						if ((c[z][0] == empty && c[z][1] == symbol && c[z][2] == symbol) || (c[z][0] == symbol && c[z][1] == empty && c[z][2] == symbol) || (c[z][0] == symbol && c[z][1] == symbol && c[z][2] == empty) && complexity != 1)
						{
							do
							{
								n = rand() % 3;
							} while (c[z][n] == symbol);
							c[z][n] = enemy;
							break;
						}
						if ((c[0][z] == empty && c[1][z] == symbol && c[2][z] == symbol) || (c[0][z] == symbol && c[1][z] == empty && c[2][z] == symbol) || (c[0][z] == symbol && c[1][z] == symbol && c[2][z] == empty) && complexity != 1)
						{
							do
							{
								m = rand() % 3;
							} while (c[m][z] == symbol);
							c[m][z] = enemy;
							break;
						}
						//Конец основного блокиратора победы
						// Победа по вертикали и горизонтали
						if (c[1][1] == enemy && z == 2 && complexity != 1 && complexity != 2)
						{
							if (c[0][1] == empty && c[2][1] == empty)
							{
								do
								{
									m = rand() % 3;
									n = rand() % 3;
								} while (m != 0 || m != 2 && n != 1);
								cout << "\nWin vertical\n" << m << " " << n << endl;
								c[m][n] = enemy;
								break;
							}
							if (c[1][0] == empty && c[1][2] == empty)
							{
								do
								{
									m = rand() % 3;
									n = rand() % 3;
								} while (m != 1 && n != 0 || n != 2);
								cout << "\nWin gorisontal\n" << m << " " << n << endl;
								c[m][n] = enemy;
								break;
							}
						}
						// Победа по диагонали справо и слево
						if (c[1][1] == symbol && z == 2 && complexity != 1 && complexity != 2)
						{
							if (c[0][0] == empty && c[2][2] == empty && complexity != 1 && complexity != 2)
							{
								do
								{
									m = rand() % 3;
									n = rand() % 3;
								} while ((m != 0 && n != 2) || (m != 2 && n != 0));
								cout << "\nWin left diagonal\n" << m << " " << n << endl;
								c[m][n] = enemy;
								break;
							}
							if (c[2][0] == empty && c[0][2] == empty && complexity != 1 && complexity != 2)
							{
								do
								{
									m = rand() % 3;
									n = rand() % 3;
								} while ((m != 0 && n != 0) || (m != 2 && n != 2));
								cout << "\nWin right diagonal\n" << m << " " << n << endl;
								c[m][n] = enemy;
								break;
							}
						}
						// Блокиратор X
						if (c[1][0] == symbol && c[0][1] == symbol && c[0][0] == empty && z == 2 && complexity == 4)
						{
							c[0][0] = enemy;
							break;
						}
						if (c[0][1] == symbol && c[1][2] == symbol && c[0][2] == empty && z == 2 && complexity == 4)
						{
							c[0][2] = enemy;
							break;
						}
						if (c[2][0] == empty && c[1][0] == symbol && c[2][1] == symbol && z == 2 && complexity == 4)
						{
							c[2][0] = enemy;
							break;
						}
						if (c[2][2] == empty && c[1][2] == symbol && c[2][1] == symbol && z == 2 && complexity == 4)
						{
							c[2][2] = enemy;
							break;
						}
						if (c[2][0] == empty && c[0][2] == empty && c[1][1] == enemy && z == 2)
						{
							do
							{
								m = rand() % 3;
								n = rand() % 3;
							} while (m != 0 && n != 0 || m != 2 && n != 2);
							cout << "\nWin left(1)\n" << m << " " << n << endl;
							c[m][n] = enemy;
							break;
						}
						if (c[0][0] == empty && c[2][2] == empty && c[1][1] == enemy && z == 2)
						{
							do
							{
								m = rand() % 3;
								n = rand() % 3;
							} while (m != 2 && n != 0 || m != 0 && n != 2);
							cout << "\nWin left(2)\n" << m << " " << n << endl;
							c[m][n] = enemy;
							break;
						}
						// Конец блокировки победы
						if (z == 2)
						{
							do
							{
								m = rand() % 3;
								n = rand() % 3;
							} while (c[m][n] == symbol || c[m][n] == enemy);
							c[m][n] = enemy;
							break;
						}
						// Конец хода компьютера
					}
				}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						cout << "+---+---+---+" << endl;
						for (int j = 0; j < 3; j++)
						{
							cout << "| " << c[i][j] << ' ';
						}
						cout << "|" << endl;
					}
					cout << "+---+---+---+\n";
					cout << "\nSecond player is going\n";
					cout << "Enter counters:\n";
					cout << "Gorisontal: ";
					cin >> x;
					cout << "Vertical: ";
					cin >> y;
					if (c[x][y] != symbol && c[x][y] != enemy && x >= 0 && x < 3 && y >= 0 && y < 3)
					{
						c[x][y] = enemy;
					}
					else
					{
						if (x == 24 || y == 24)
						{
							goto trail;
						}
						fail();
						goto ron;
					}
				}
			}
			// Вывод поля
			for (int i = 0; i < 3; i++)
			{
				cout << "+---+---+---+" << endl;
				for (int j = 0; j < 3; j++)
				{
					cout << "| " << c[i][j] << ' ';

				}
				cout << "|" << endl;
			}
			cout << "+---+---+---+\n";
			// Проверка на победу 2
			if ((c[0][0] == symbol && c[0][1] == symbol && c[0][2] == symbol) || (c[1][0] == symbol && c[1][1] == symbol && c[1][2] == symbol) || (c[2][0] == symbol && c[2][1] == symbol && c[2][2] == symbol) ||
				(c[0][0] == symbol && c[1][0] == symbol && c[2][0] == symbol) || (c[0][1] == symbol && c[1][1] == symbol && c[2][1] == symbol) || (c[0][2] == symbol && c[1][2] == symbol && c[2][2] == symbol) ||
				(c[0][0] == symbol && c[1][1] == symbol && c[2][2] == symbol) || (c[2][0] == symbol && c[1][1] == symbol && c[0][2] == symbol))
			{
				h = 1;
				break;
			}
			if ((c[0][0] == enemy && c[0][1] == enemy && c[0][2] == enemy) || (c[1][0] == enemy && c[1][1] == enemy && c[1][2] == enemy) || (c[2][0] == enemy && c[2][1] == enemy && c[2][2] == enemy) ||
				(c[0][0] == enemy && c[1][0] == enemy && c[2][0] == enemy) || (c[0][1] == enemy && c[1][1] == enemy && c[2][1] == enemy) || (c[0][2] == enemy && c[1][2] == enemy && c[2][2] == enemy) ||
				(c[0][0] == enemy && c[1][1] == enemy && c[2][2] == enemy) || (c[2][0] == enemy && c[1][1] == enemy && c[0][2] == enemy))
			{
				h = 2;
				break;
			}
		} while (k != 5);
	}
	else
	{
		fail();
		goto choose;
	}
	switch (h)
	{
	case 0: cout << "\nDraw...\n"; break;
	case 1:
		if (mode == "computer")
		{
			cout << "\nCongrats you are winner!\n"; break;
		}
		else
		{
			cout << "\nFirst player is winner!\n"; break;
		}
	case 2: if (mode == "computer")
	{
		cout << "\nField...\n"; break;
	}
		  else
	{
		cout << "\nSecond player is winner!\n"; break;
	}
	}
Nichiporyk:
	cout << "\nDo you want try?\n";
	cout << "Enter:";
	cin >> results;
	if (results == "Yes" || results == "yEs" || results == "yeS" || results == "YES" || results == "yes")
	{
		cout << "\n\t\t\t\t\t\t\t+------------------+\n";
		cout << "\t\t\t\t\t\t\t|Game was restarted|\n";
		cout << "\t\t\t\t\t\t\t+------------------+\n";
		goto trail;
	}
	if (results == "No" || results == "nO" || results == "NO" || results == "no")
	{
		cout << "\n\t\t\t\t\t\t+---------------+\n";
		cout << "\t\t\t\t\t\t|Have a good day|\n";
		cout << "\t\t\t\t\t\t+---------------+\n";
	}
	else
	{
		fail();
		goto Nichiporyk;
	}
	system("pause");
	return 0;
}