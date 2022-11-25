#include <iostream>
#include <conio.h>
#include <cstdio>
using namespace std;

const int SIZE_X = 25; 
const int SIZE_Y = 25;

class Player
{
private: int x, y;
public:
	Player(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) 
	{ 
		this->x += x; 
		if (this->x < 0 || this->x >= SIZE_X)
			this->x -= x;
	}
	void setY(int y) 
	{
		this->y += y;
		if ((this->y < 0) || (this->y >= SIZE_Y))
			this->y -= y;
				
	}
	void setXY(int a, int b) { x += a; y -= b; }
	void MovePlayer(char ch)
	{
		switch (ch)
		{
		case 'w': setY(-1); break;
		case 's': setY(1); break;
		case 'a': setX(-1); break;
		case 'd': setX(1); break;
		case 'q': exit(1);
		default:
			break;
		}
	}
};

void Draw(Player p, char field[SIZE_X][SIZE_Y])
{
	char old_field[SIZE_X][SIZE_Y]; 
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			old_field[i][j] = field[i][j];
			if ((p.getX() == j) && (p.getY() == i))
			{
				field[i][j] = '@';
			}
			else
			{
				field[i][j] = '*';
			}
		}
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (old_field[i][j] != field[i][j])
				cout << field[i][j];
		}
		cout << endl;
	}
	cout << p.getX() << " " << p.getY() << endl;
}

void Input(Player &p)
{
	p.MovePlayer(_getch());
}
void CreateField(char field[SIZE_X][SIZE_Y])
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			field[i][j] = '*';
		}
	}
}
void PrintField(char field[SIZE_X][SIZE_Y])
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			cout << field[i][j];
		}
		cout << endl;
	}
}

void main()
{
	char field[SIZE_X][SIZE_Y];
	Player p(10,16);
	CreateField(field);
	PrintField(field);
	while (true)
	{
		Draw(p, field);
		Input(p);
		//system("CLS");
	}
}



