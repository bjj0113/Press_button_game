#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#define exp "PRESS GAME!! "
#define msg "***"
#define explain   "PRESS BUTTUN REPEATLY!       1P 'S'        2P 'K'      EXIT 'Q'"
#define upperline "---------------------------------------------------------------"
#define sideline  "|                                                             |"

void gameset();
int game();
void winner1();
void winner2();

int row1,row2;
int col1,col2;

int game()
{
	initscr();
	crmode();
	noecho();
	clear();
	
	gameset();
	int c;

	row1 = 25; row2 = 25;
	col1 = 20; col2 = 45;
	
	while(1)
	{	
		c = getch();
		if(c == 'q' || c == 'Q')
			break;
		if(row1 != 5 && row2 != 5){
			if(c == 's' || c == 'S')
			{
				move(row1,col1);
				addstr(msg);
				move(LINES,COLS);
				row1 = row1-1;
				if(row1 == 5){
					clear();
					winner1();
				}
				
			}
			if(c == 'k' || c == 'K')
			{
				move(row2,col2);
				addstr(msg);
				move(LINES,COLS);
				row2 = row2-1;
				if(row2 == 5){
					clear();
					winner2();
				}
			}
		}
	}
	refresh();
	endwin();
	return 0;
}

void gameset()
{
	move(3,5);
	addstr(exp);
	move(4,5);
	addstr(explain);
	move(5,5);
	addstr(upperline);
	for(int j=0; j<20;j++)
	{
		move(6+j,5);
		addstr(sideline);
	}
	move(26,5);
	addstr(upperline);
	move(27,20);
	addstr("1P");
	move(27,45);
	addstr("2P");
	move(LINES,COLS);
}

void winner1()
{
	gameset();
	move(15,5);
	addstr(upperline);
	move(20,5);
	addstr(upperline);
	move(16,20);
	addstr("1 Player is WINNER~~~~~!!!");
	move(17,20);
	addstr("PRESS Q to end the game");
	move(LINES,COLS);
}
void winner2()
{
	gameset();
	move(15,5);
	addstr(upperline);
	move(20,5);
	addstr(upperline);
	move(16,20);
	addstr("2 Player is WINNER~~~~~!!!");
	move(17,20);
	addstr("PRESS Q to end the game");
	move(LINES,COLS);
}
