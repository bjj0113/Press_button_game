#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <curses.h>
#include <sys/time.h>
#include <string.h>

#define oops(msg) {perror(msg); exit(1);}

extern int ticker();
extern int game();

int main()
{
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);

	int pid;
	int c;
	int i;

	if((pid =fork()) == -1){
		oops("fork");
	}
	if(pid == 0) // child에서 시작 대기 5초 timeticker 이용
	{
		printf("	SET FULL SCREEN PLZ!!\n\n");
		printf("	If the screen changes, hit the button(1P : 'S' | 2P : 'K') repeatly!\n");
		printf("	press 25 times first, U R WINNER!!\n");
		printf("	Game will start soon!\n");
		ticker();
	}
	else  //parent에서 게임 실행
	{
		wait(NULL);
		game();
	}
	return 0;
}

