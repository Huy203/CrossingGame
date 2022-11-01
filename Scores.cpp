#include "Scores.h"
#include "ConsoleWindow.h"
void Score::time_setup(int score_x, int score_y, int scores)
{
	x = score_x;
	y = score_y;
	score = scores;
}
int Score::time_effect()
{
	SetConsoleOutputCP(CP_UTF8);
	for (score; score >= 0; score--)
	{
		tHundred = score / 100;
		tDozen = (score % 100) / 10;
		tUnit = score % 10;
		setTextColor(14);
		if (tHundred == 0)
		{
			gotoXY(x - 8, y);
			cout << u8"╔████╗ ";
			gotoXY(x - 8, y + 1);
			cout << u8"█    █ ";
			gotoXY(x - 8, y + 2);
			cout << u8"█    █ ";
			gotoXY(x - 8, y + 3);
			cout << u8"╚████╝ ";
		}
		if (tHundred == 1)
		{
			gotoXY(x - 8, y);
			cout << u8" ╔███╗ ";
			gotoXY(x - 8, y + 1);
			cout << u8" █ ██║ ";
			gotoXY(x - 8, y + 2);
			cout << u8"   ██║ ";
			gotoXY(x - 8, y + 3);
			cout << u8"   ██╝ ";
		}
		if (tHundred == 2)
		{
			gotoXY(x - 8, y);
			cout << u8"████╗  ";
			gotoXY(x - 8, y + 1);
			cout << u8"╔═══█  ";
			gotoXY(x - 8, y + 2);
			cout << u8"█      ";
			gotoXY(x - 8, y + 3);
			cout << u8"╚████  ";
		}
		if (tHundred == 3)
		{
			gotoXY(x - 8, y);
			cout << u8"████╗  ";
			gotoXY(x - 8, y + 1);
			cout << u8"╔═══█  ";
			gotoXY(x - 8, y + 2);
			cout << u8"╚═══█  ";
			gotoXY(x - 8, y + 3);
			cout << u8"████╝  ";
		}
		if (tHundred == 4)
		{
			gotoXY(x - 8, y);
			cout << u8"██  ██╗";
			gotoXY(x - 8, y + 1);
			cout << u8"██══██║";
			gotoXY(x - 8, y + 2);
			cout << u8" ╚══██║";
			gotoXY(x - 8, y + 3);
			cout << u8"    ██╝";
		}
		if (tHundred == 5)
		{
			gotoXY(x - 8, y);
			cout << u8"╔████  ";
			gotoXY(x - 8, y + 1);
			cout << u8"█═══╗  ";
			gotoXY(x - 8, y + 2);
			cout << u8"    █  ";
			gotoXY(x - 8, y + 3);
			cout << u8"████╝  ";
		}
		if (tHundred == 6)
		{
			gotoXY(x - 8, y);
			cout << u8"╔█████ ";
			gotoXY(x - 8, y + 1);
			cout << u8"█════╗ ";
			gotoXY(x - 8, y + 2);
			cout << u8"█    █ ";
			gotoXY(x - 8, y + 3);
			cout << u8"╚████╝ ";
		}
		if (tHundred == 7)
		{
			gotoXY(x - 8, y);
			cout << u8"██████╗";
			gotoXY(x - 8, y + 1);
			cout << u8"    ██╝";
			gotoXY(x - 8, y + 2);
			cout << u8"  ██╝  ";
			gotoXY(x - 8, y + 3);
			cout << u8"██╝    ";
		}
		if (tHundred == 8)
		{
			gotoXY(x - 8, y);
			cout << u8"╔█████╗";
			gotoXY(x - 8, y + 1);
			cout << u8"╚█═══█╝";
			gotoXY(x - 8, y + 2);
			cout << u8"╔█═══█╗";
			gotoXY(x - 8, y + 3);
			cout << u8"╚█████╝";
		}
		if (tHundred == 9)
		{
			gotoXY(x - 8, y);
			cout << u8"╔█████╗";
			gotoXY(x - 8, y + 1);
			cout << u8"██   ██";
			gotoXY(x - 8, y + 2);
			cout << u8" ╚═══██";
			gotoXY(x - 8, y + 3);
			cout << u8" █████╝";
		}
		if (tDozen == 0)
		{
			gotoXY(x, y);
			cout << u8"╔████╗ ";
			gotoXY(x, y + 1);
			cout << u8"█    █ ";
			gotoXY(x, y + 2);
			cout << u8"█    █ ";
			gotoXY(x, y + 3);
			cout << u8"╚████╝";
		}
		if (tDozen == 1)
		{
			gotoXY(x, y);
			cout << u8" ╔███╗ ";
			gotoXY(x, y + 1);
			cout << u8" █ ██║ ";
			gotoXY(x, y + 2);
			cout << u8"   ██║ ";
			gotoXY(x, y + 3);
			cout << u8"   ██╝ ";
		}
		if (tDozen == 2)
		{
			gotoXY(x, y);
			cout << u8"████╗  ";
			gotoXY(x, y + 1);
			cout << u8"╔═══█  ";
			gotoXY(x, y + 2);
			cout << u8"█      ";
			gotoXY(x, y + 3);
			cout << u8"╚████  ";
		}
		if (tDozen == 3)
		{
			gotoXY(x, y);
			cout << u8"████╗  ";
			gotoXY(x, y + 1);
			cout << u8"╔═══█  ";
			gotoXY(x, y + 2);
			cout << u8"╚═══█  ";
			gotoXY(x, y + 3);
			cout << u8"████╝  ";
		}
		if (tDozen == 4)
		{
			gotoXY(x, y);
			cout << u8"██  ██╗";
			gotoXY(x, y + 1);
			cout << u8"██══██║";
			gotoXY(x, y + 2);
			cout << u8" ╚══██║";
			gotoXY(x, y + 3);
			cout << u8"    ██╝";
		}
		if (tDozen == 5)
		{
			gotoXY(x, y);
			cout << u8"╔████  ";
			gotoXY(x, y + 1);
			cout << u8"█═══╗  ";
			gotoXY(x, y + 2);
			cout << u8"    █  ";
			gotoXY(x, y + 3);
			cout << u8"████╝  ";
		}
		if (tDozen == 6)
		{
			gotoXY(x, y);
			cout << u8"╔█████ ";
			gotoXY(x, y + 1);
			cout << u8"█════╗ ";
			gotoXY(x, y + 2);
			cout << u8"█    █ ";
			gotoXY(x, y + 3);
			cout << u8"╚████╝ ";
		}
		if (tDozen == 7)
		{
			gotoXY(x, y);
			cout << u8"██████╗";
			gotoXY(x, y + 1);
			cout << u8"    ██╝";
			gotoXY(x, y + 2);
			cout << u8"  ██╝  ";
			gotoXY(x, y + 3);
			cout << u8"██╝    ";
		}
		if (tDozen == 8)
		{
			gotoXY(x, y);
			cout << u8"╔█████╗";
			gotoXY(x, y + 1);
			cout << u8"╚█═══█╝";
			gotoXY(x, y + 2);
			cout << u8"╔█═══█╗";
			gotoXY(x, y + 3);
			cout << u8"╚█████╝";
		}
		if (tDozen == 9)
		{
			gotoXY(x, y);
			cout << u8"╔█████╗";
			gotoXY(x, y + 1);
			cout << u8"██   ██";
			gotoXY(x, y + 2);
			cout << u8" ╚═══██";
			gotoXY(x, y + 3);
			cout << u8" █████╝";
		}
		if (tUnit == 0)
		{
			gotoXY(x + 8, y);
			cout << u8"╔████╗ ";
			gotoXY(x + 8, y + 1);
			cout << u8"█    █ ";
			gotoXY(x + 8, y + 2);
			cout << u8"█    █ ";
			gotoXY(x + 8, y + 3);
			cout << u8"╚████╝ ";
		}
		if (tUnit == 1)
		{
			gotoXY(x + 8, y);
			cout << u8" ╔███╗ ";
			gotoXY(x + 8, y + 1);
			cout << u8" █ ██║ ";
			gotoXY(x + 8, y + 2);
			cout << u8"   ██║ ";
			gotoXY(x + 8, y + 3);
			cout << u8"   ██╝ ";
		}
		if (tUnit == 2)
		{
			gotoXY(x + 8, y);
			cout << u8"████╗  ";
			gotoXY(x + 8, y + 1);
			cout << u8"╔═══█  ";
			gotoXY(x + 8, y + 2);
			cout << u8"█      ";
			gotoXY(x + 8, y + 3);
			cout << u8"╚████  ";
		}
		if (tUnit == 3)
		{
			gotoXY(x + 8, y);
			cout << u8"████╗  ";
			gotoXY(x + 8, y + 1);
			cout << u8"╔═══█  ";
			gotoXY(x + 8, y + 2);
			cout << u8"╚═══█  ";
			gotoXY(x + 8, y + 3);
			cout << u8"████╝  ";
		}
		if (tUnit == 04)
		{
			gotoXY(x + 8, y);
			cout << u8"██  ██╗";
			gotoXY(x + 8, y + 1);
			cout << u8"██══██║";
			gotoXY(x + 8, y + 2);
			cout << u8" ╚══██║";
			gotoXY(x + 8, y + 3);
			cout << u8"    ██╝";
		}
		if (tUnit == 05)
		{
			gotoXY(x + 8, y);
			cout << u8"╔████  ";
			gotoXY(x + 8, y + 1);
			cout << u8"█═══╗  ";
			gotoXY(x + 8, y + 2);
			cout << u8"    █  ";
			gotoXY(x + 8, y + 3);
			cout << u8"████╝  ";
		}
		if (tUnit == 06)
		{
			gotoXY(x + 8, y);
			cout << u8"╔█████ ";
			gotoXY(x + 8, y + 1);
			cout << u8"█════╗ ";
			gotoXY(x + 8, y + 2);
			cout << u8"█    █ ";
			gotoXY(x + 8, y + 3);
			cout << u8"╚████╝ ";
		}
		if (tUnit == 07)
		{
			gotoXY(x + 8, y);
			cout << u8"██████╗";
			gotoXY(x + 8, y + 1);
			cout << u8"    ██╝";
			gotoXY(x + 8, y + 2);
			cout << u8"  ██╝  ";
			gotoXY(x + 8, y + 3);
			cout << u8"██╝    ";
		}
		if (tUnit == 8)
		{
			gotoXY(x + 8, y);
			cout << u8"╔█████╗";
			gotoXY(x + 8, y + 1);
			cout << u8"╚█═══█╝";
			gotoXY(x + 8, y + 2);
			cout << u8"╔█═══█╗";
			gotoXY(x + 8, y + 3);
			cout << u8"╚█████╝";
		}
		if (tUnit == 9)
		{
			gotoXY(x + 8, y);
			cout << u8"╔█████╗";
			gotoXY(x + 8, y + 1);
			cout << u8"██   ██";
			gotoXY(x + 8, y + 2);
			cout << u8" ╚═══██";
			gotoXY(x + 8, y + 3);
			cout << u8" █████╝";
		}
		Sleep(50);
	}
	return score;
}
