#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <windows.h>
#define up 0
#define down 1
#define left 2
#define right 3
#define undo 4
#define save 5
#define Exit 6
int input(void);
int whatColor(int n);
void print(int matrix[][10], int size, int score, int highscore, int counter);
void new_block(int matrix[][10], int size);
void predictor(int matrix[][10], int next[][10], int size);
int future(int next[][10], int matrix[][10], int size, int direct);
void saveoriginal(char address[]);
void fsaver(char address[], int matrix[][10], int size, int counter, int highscore, int score);		
void savefile(char address[], int matrix[][10], int size, int counter, int highscore);
void left_move(int matrix[][10], int size);
void right_move(int matrix[][10], int size);
void up_move(int matrix[][10], int size);
void down_move(int matrix[][10], int size);
void left_mix(int matrix[][10], int size);
void right_mix(int matrix[][10], int size);
void up_mix(int matrix[][10], int size);
void down_mix(int matrix[][10], int size);
int check(int matrix[][10], int size);
void copy (int matrix[][10], int backup[][10], int size);
int changelog(int matrix[][10], int backup[][10], int size);
int score = 0, highscore, in;
FILE *fsave, *fnow;
int main()
{
	int mx, my;
	int gd=DETECT,gm;
	initwindow(1020,800,"Game");
	srand(time(NULL));
	int matrix[10][10] = {0}, backup [10][10] = {0}, next[10][10] = {0};
	int size, i, j, flag = 1, flag_input = 1, counter = 0, backupscore = score;
	int firstinput, secondinput, dim, map, undoflag;
	char address[10];
	settextstyle(10,HORIZ_DIR,5);
	outtextxy(10,10,"1.New Game");
	outtextxy(10,50,"2.Saved Game");
	firstinput=getch();
	firstinput-='0';
	if(firstinput == 2)
	{
		fnow = fopen("saved.txt", "r");
		if(fnow == NULL)
		{
			outtextxy(1,90,"there's no saved game available!!\n");
			firstinput = 1;
		}
		if(firstinput == 2)
		{
			fscanf(fnow, "%s", address);
			fscanf(fnow, "%d %d %d %d", &size, &highscore, &counter, &score);
			for(i = 0; i < size; i++)
			{
				for(j = 0; j < size; j++)
				{
					fscanf(fnow, "%d", &matrix[i][j]);
				}
			}
		}
	}
	if(firstinput == 1)
	{
		cleardevice();
		outtextxy(10,10,"1.Classic Game");
		outtextxy(10,50,"2.Featured Game");
		secondinput=getch();
		secondinput-='0';
		cleardevice();
		if(secondinput == 1)
		{
			outtextxy(10,10,"1.6x6");
			outtextxy(10,50,"2.7x7");
			outtextxy(10,90,"3.9x9");
			dim=getch();
			dim-='0';
			if(dim == 1)
			{
				fnow = fopen("6x6.txt", "r");
				strcpy(address, "6x6.txt");
			}
			else if(dim == 2)
			{
				fnow = fopen("7x7.txt", "r");
				strcpy(address, "7x7.txt");
			}
			else
			{
				fnow = fopen("9x9.txt", "r");
				strcpy(address, "9x9.txt");
			}
		}
		else if(secondinput == 2)
		{	
//			readimagefile("1.jpg",250,0,450,200);
//			readimagefile("2.jpg",550,0,750,200);
//			readimagefile("3.jpg",250,300,450,500);
//			readimagefile("4.jpg",550,300,750,500);
//			readimagefile("5.jpg",250,600,450,800);//for mamas
//			readimagefile("6.jpg",550,600,750,800);
//			getmouseclick(WM_MOUSEMOVE,mx,my);
//			if(mx <= 450 && mx >= 250 && my >= 0 && my <= 200)
//				map = 1;
//			if(mx <= 750 && mx >= 550 && my >= 0 && my <= 200)
//				map = 2;
//			if(mx <= 450 && mx >= 250 && my >= 300 && my <= 500)
//				map = 3;
//			if(mx <= 750 && mx >= 550 && my >= 300 && my <= 500)
//				map = 4;
//			if(mx <= 450 && mx >= 250 && my >= 600 && my <= 800)
//				map = 5;
//			if(mx <= 750 && mx >= 550 && my >= 600 && my <= 800)
//				map = 6;
			outtextxy(10,10,"1.		2.");
			outtextxy(10,50,"3.		4.");
			outtextxy(10,90,"5.		6.");
			printf("select the map:\n");
			printf("1.\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    ||||||    |    ||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |||||||||||||||||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |||||||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("2.\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |    ||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    ||||||    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |||||||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |||||||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    ||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("||||||    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- \n");
			printf("3.\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||||||||||||||||||||||||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("4.\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||    |    |    |    |    ||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    ||||||    |    |    ||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    ||||||    ||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    ||||||    ||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    ||||||    |    |    ||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||    |    |    |    |    ||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- \n");
			printf("5.\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|||||||||||||||||||||    |||||||||||||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||||||||||||    |    |    ||||||||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|||||||||||    |    |    |    |    |||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||    |    |    |    |    |    |    ||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||    |    |    |    |    |    |    ||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|||||||||||    |    |    |    |    |||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("||||||||||||||||    |    |    ||||||||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|||||||||||||||||||||    |||||||||||||||||||||\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("6.\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |||||||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    ||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    ||||||    |    |    |    ||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    ||||||    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    ||||||    |    |    |    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    ||||||    |    |    |    ||||||    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    ||||||    |    ||||||    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			printf("|    |    |    |    |||||||||||    |    |    |\n");
			printf(" ---- ---- ---- ---- ---- ---- ---- ---- ---- \n");
			map=getch();
			map-='0';
			switch(map)
			{
				case 1:
				fnow = fopen("1.txt", "r");
				strcpy(address, "1.txt");
				break;
				case 2:
				fnow = fopen("2.txt", "r");
				strcpy(address, "2.txt");
				break;
				case 3:
				fnow = fopen("3.txt", "r");
				strcpy(address, "3.txt");
				break;
				case 4:
				fnow = fopen("4.txt", "r");
				strcpy(address, "4.txt");
				break;
				case 5:
				fnow = fopen("5.txt", "r");
				strcpy(address, "5.txt");
				break;
				case 6:
				fnow = fopen("6.txt", "r");
				strcpy(address, "6.txt");
				break;
			}
		}
		fscanf(fnow, "%d %d %d", &size, &highscore, &counter);
		for(i = 0; i < size; i++)
		{
			for(j = 0; j < size; j++)
			{
				fscanf(fnow, "%d", &matrix[i][j]);
			}
		}
		new_block(matrix, size);
		new_block(matrix, size);
		new_block(matrix, size);
	}
	cleardevice();
	outtextxy(10,10,"1.Undo off!! (Let's do this!!)");
	outtextxy(10,50,"2.Undo On (I'm a noob :|)");
	undoflag=getch();
	undoflag-='0';
 	undoflag--;
 	cleardevice();
	print(matrix, size, score, highscore, counter);
	do
	{
		flag_input = 1;
		in = input();
		switch (in)
		{
		case up:
			copy(matrix, backup, size);
			up_move(matrix, size);
			up_mix(matrix, size);
			break;
		case down:
			copy(matrix, backup, size);
			down_move(matrix, size);
			down_mix(matrix, size);
			break;
		case left:
			copy(matrix, backup, size);
			left_move(matrix, size);
			left_mix(matrix, size);
			break;
		case right:
			copy(matrix, backup, size);
			right_move(matrix, size);
			right_mix(matrix, size);
			break;
		case undo:
			if(undoflag)
			{
				copy(backup, matrix, size);
				score = backupscore;
				print(matrix, size, score, highscore, counter);
			}
			else
			{
				MessageBox(0, "U weren't a noob :))", "Noob Alert!!", MB_ICONWARNING); 
				flag_input = 0;
			}
			break;
		case save:
			fclose(fnow);
			fsaver(address, matrix, size, counter, highscore, score);
			flag_input = 0;
			break;
		case Exit:
			fclose(fnow);
			return 0;
			break;
		default:
			MessageBox(0, "Invalid Input", "Error", MB_ICONWARNING); 
			flag_input = 0;
			continue;
		}
		if(score > highscore)
			highscore = score;
		backupscore = score;
		if(!changelog(matrix, backup, size))
			flag_input = 0;
		if(flag_input)
		{
			counter++;
			saveoriginal(address);
			new_block(matrix, size);
			print(matrix, size, score, highscore, counter);
			predictor(matrix, next, size);
		}
		flag = check(matrix, size);
	}while(flag);
	MessageBox(0, "Game over!!!!", "Gameover", MB_ICONHAND); 
 	cleardevice();
 	char last[100];
	sprintf(last, "Your score : %d , Moves: %d , Highscore: %d", score, counter, highscore);
 	outtextxy(500,100,last);	
	fclose(fnow);
	getch();
	return 0;
}
int input(void)
{
	char ch1 = 0, ch2 = 0;
	ch1 = getch();
	if(ch1 == 0)
	{
		ch2 = getch();
		switch (ch2)
		{
			case 72: 
			return 0;
			case 80:
			return 1;
			case 75:
			return 2;
			case 77: 
			return 3;
		}
	}
	else
	{
		switch (ch1)
		{
			case 'w':
			return 0;
			break;
			case 's':
			return 1;
			break;
			case 'a':
			return 2;
			break;
			case 'd':
			return 3;
			break;
			case 'u':
			return 4;
			break;
			case 'l':
			return 5;
			break;
			case 27:
			return 6;
			break;
			default:
			return 7;
			break;
		}	
	}
}
void print(int matrix[][10], int size, int score, int highscore, int counter)
{
	cleardevice();
	char buffer[50];
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(100,100,WHITE);
	settextjustify(1,1);
	settextstyle(10,HORIZ_DIR,4);
	setbkcolor(WHITE);
	setcolor(BLACK);
	sprintf(buffer,"score: %d    moves: %d    highscore: %d", score, counter, highscore);	
	outtextxy(500,30,buffer);
	if(size==6){
		for(int i=175;(i-175)/110<size;i+=110){
			for(int j=125;(j-125)/110<size;j+=110){
				if(matrix[(j-125)/110][(i-175)/110]==1)
					setfillstyle(SOLID_FILL,BLACK);
				else
					setfillstyle(SOLID_FILL,15-whatColor(matrix[(j-125)/110][(i-175)/110]));
				rectangle(i,j,i+100,j+100);
				floodfill(i+55,j+55,BLACK);
				sprintf(buffer,"%d",matrix[(j-125)/110][(i-175)/110]);
				setbkcolor(15-whatColor(matrix[(j-125)/110][(i-175)/110]));
				if(buffer[0]!='0' && buffer[0]!='1')
					outtextxy(i+55,j+55,buffer);
			}
		}
	}
	else if(size==7){
		for(int i=155;(i-155)/100<size;i+=100){
			for(int j=105;(j-105)/100<size;j+=100){
				if(matrix[(j-105)/100][(i-155)/100]==1)
					setfillstyle(SOLID_FILL,BLACK);
				else
					setfillstyle(SOLID_FILL,15-whatColor(matrix[(j-105)/100][(i-155)/100]));
				rectangle(i,j,i+100,j+100);
				floodfill(i+50,j+50,BLACK);
				sprintf(buffer,"%d",matrix[(j-105)/100][(i-155)/100]);
				setbkcolor(15-whatColor(matrix[(j-105)/100][(i-155)/100]));
				if(buffer[0]!='0' && buffer[0]!='1')
					outtextxy(i+50,j+50,buffer);
			}
		}
	}
	else if(size==9){
		for(int i=165;(i-165)/75<size;i+=75){
			for(int j=115;(j-115)/75<size;j+=75){
				if(matrix[(j-115)/75][(i-165)/75]==1)
					setfillstyle(SOLID_FILL,BLACK);
				else
					setfillstyle(SOLID_FILL,15-whatColor(matrix[(j-115)/75][(i-165)/75]));
				rectangle(i,j,i+75,j+75);
				floodfill(i+35,j+35,BLACK);
				sprintf(buffer,"%d",matrix[(j-115)/75][(i-165)/75]);
				setbkcolor(15-whatColor(matrix[(j-115)/75][(i-165)/75]));
				if(buffer[0]!='0' && buffer[0]!='1')
					outtextxy(i+35,j+35,buffer);
			}
		}
	}
}
void saveoriginal(char address[])
{
	int highscore2, base[10][10], size, counter, i, j;
	fclose(fnow);
	fnow = fopen(address, "r");
	fscanf(fnow, "%d %d %d", &size, &highscore2, &counter);
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
			fscanf(fnow, "%d", &base[i][j]);
	}
	fclose(fnow);
	savefile(address, base, size, counter, highscore);
}
void savefile(char address[], int matrix[][10], int size, int counter, int highscore)
{
	int i, j;
	fsave = fopen(address, "w");
	fprintf(fsave ,"%d %d %d\n", size, highscore, counter);
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			fprintf(fsave, "%d", matrix[i][j]);
			if(j != size - 1)
				fprintf(fsave, " ");
		}
		fprintf(fsave, "\n");
	}
	fclose(fsave);	
}
void fsaver(char address[], int matrix[][10], int size, int counter, int highscore, int score)
{
		int i, j;
	fsave = fopen("saved.txt", "w");
	fprintf(fsave, "%s\n", address);
	fprintf(fsave ,"%d %d %d %d\n", size, highscore, counter, score);
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			fprintf(fsave, "%d", matrix[i][j]);
			if(j != size - 1)
				fprintf(fsave, " ");
		}
		fprintf(fsave, "\n");
	}
	fclose(fsave);
}
void new_block(int matrix[][10], int size)
{
	int i, j, rnd;
	i = rand() % size;
	j = rand() % size;
	if(matrix[i][j])
		new_block(matrix, size);
	else
		{
			rnd = rand() % 5;
			if(rnd)
				matrix[i][j] = 3;
			else
				matrix[i][j] = 9;
		}
}
int whatColor(int n){
	int c=0;
	while(n/=3)
		c++;
	return c;
}
void predictor(int matrix[][10], int next[][10], int size)
{
	int maxscore = 0, current;
	int direct, maxdirect = 0;
	for(direct = 0; direct < 4; direct++)
	{
		copy(matrix, next, size);
		current = future(next, matrix, size, direct);
		if(current > maxscore)
		{
			maxscore = current;
			maxdirect = direct;
		}
	}
	char buffer[200];
	settextjustify(1,1);
	settextstyle(6,HORIZ_DIR,2);
	setcolor(BLACK);
	setbkcolor(WHITE);
	switch(maxdirect)
	{
		case up:
			sprintf(buffer,"the best move for you is to go \"up\" and your score will be :%d", maxscore);
			outtextxy(500,80,buffer);
			break;
		case down:
			sprintf(buffer,"the best move for you is to go \"down\" and your score will be :%d", maxscore);
			outtextxy(500,80,buffer);
			break;
		case left:
			sprintf(buffer,"the best move for you is to go \"left\" and your score will be :%d", maxscore);
			outtextxy(500,80,buffer);
			break;
		case right:
			sprintf(buffer,"the best move for you is to go \"right\" and your score will be :%d", maxscore);
			outtextxy(500,70,buffer);
			break;
	}
}
int future(int next[][10], int matrix[][10], int size, int direct)
{
	int lastscore = score, temp;
	in = direct;
		switch (in)
		{
		case up:
			up_move(next, size);
			up_mix(next, size);
			break;
		case down:
			down_move(next, size);
			down_mix(next, size);
			break;
		case left:
			left_move(next, size);
			left_mix(next, size);
			break;
		case right:
			right_move(next, size);
			right_mix(next, size);
			break;
		}
	temp = lastscore;
	lastscore = score;
	score = temp;
	if (changelog(next, matrix, size))
		return lastscore;
	return -1;
}
void left_move(int matrix[][10], int size)
{
	int i, j, k;
	for(i = 0; i < size ; i++)
		for(j = 0; j < size ; j++)
		{
			if (matrix[i][j] == 0)
				for (k = j; k < size; k++)
				{
					if(matrix[i][k])
					{
						if(matrix[i][k] == 1)
							break;
						matrix[i][j] = matrix[i][k];
						matrix[i][k] = 0;
						break;
					}
				}
		}
}
void right_move(int matrix[][10], int size)
{
	int i, j, k;
	for(i = 0; i < size ; i++)
		for(j = size - 1; j >= 0 ; j--)
		{
			if (matrix[i][j] == 0)
				for (k = j; k >= 0; k--)
				{
					if(matrix[i][k])
					{
						if(matrix[i][k] == 1)
							break;
						matrix[i][j] = matrix[i][k];
						matrix[i][k] = 0;
						break;
					}
				}
		}
}
void left_mix(int matrix[][10], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < size - 2; j++)
		{
			if(matrix[i][j] && matrix[i][j] != 1 && matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i][j + 2])
			{
				matrix[i][j] += matrix[i][j + 1] + matrix[i][j + 2];
				score += matrix[i][j];
				matrix[i][j + 1] = matrix[i][j + 2] = 0;
			}
		}
	left_move(matrix, size);
}
void right_mix(int matrix[][10], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = size - 1; j >= 2; j--)
		{
			if(matrix[i][j] && matrix[i][j] != 1 && matrix[i][j] == matrix[i][j - 1] && matrix[i][j] == matrix[i][j - 2])
			{
				matrix[i][j] += matrix[i][j - 1] + matrix[i][j - 2];
				score += matrix[i][j];
				matrix[i][j - 1] = matrix[i][j - 2] = 0;
			}
		}
	right_move(matrix, size);
}
void up_move(int matrix[][10], int size)
{
	int i, j, k;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(matrix[j][i] == 0)
			{
				for(k = j; k < size; k++)
				{
					if(matrix[k][i])
					{
						if(matrix[k][i] == 1)
							break;
						matrix[j][i] = matrix[k][i];
						matrix[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}
void down_move(int matrix[][10], int size)
{
	int i, j, k;
	for(i = size - 1; i >= 0; i--)
	{
		for(j = size - 1; j >= 0; j--)
		{
			if(matrix[j][i] == 0)
			{
				for(k = j; k >= 0; k--)
				{
					if(matrix[k][i])
					{
						if(matrix[k][i] == 1)
							break;
						matrix[j][i] = matrix[k][i];
						matrix[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}
void up_mix(int matrix[][10], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size - 2; j++)
		{
			if(matrix[j][i] && matrix[j][i] != 1 && matrix[j + 1][i] == matrix[j][i] && matrix[j + 2][i] == matrix[j][i])
			{
				matrix[j][i] = 3 * matrix[j][i];
				score += matrix[j][i];
				matrix[j + 1][i] = 0;
				matrix[j + 2][i] = 0;
			}
		}
	}
	up_move(matrix, size);
}
void down_mix(int matrix[][10], int size)
{
	int i, j;
	for(i = size - 1; i >= 0; i--)
	{
		for(j = size - 1; j >= 2; j--)
		{
			if(matrix[j][i] && matrix[j][i] != 1 && matrix[j - 1][i] == matrix[j][i] && matrix[j - 2][i] == matrix[j][i])
			{
				matrix[j][i]=3 * matrix[j][i];
				score += matrix[j][i];
				matrix[j - 1][i] = 0;
				matrix[j - 2][i] = 0;
			}
		}
	}
	down_move(matrix, size);
}
int check(int matrix[][10], int size)
{
	int i, j, flag = 0;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(matrix[i][j] == 0)
			return 1;
		}
	}
	for(i = 0; i < size - 2; i++)
	{
		for(j = 0; j < size - 2; j++)
		{
			if(matrix[i][j] != 1 && ((matrix[i][j] == matrix[i + 1][j] && matrix[i][j] == matrix[i + 2][j]) || (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i][j + 2])))
			{
				flag = 1;
				break;
			}
		}
			if(flag)
				break;
	}
	for(i = size-1; i > 1; i--)
	{
		for(j = size-1; j > 1; j--)
		{
			if(matrix[i][j] != 1 && ((matrix[i][j] == matrix[i - 1][j] && matrix[i][j] == matrix[i - 2][j]) || (matrix[i][j] == matrix[i][j - 1] && matrix[i][j] == matrix[i][j - 2])))
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
	}
	return flag;
}
void copy (int matrix[][10], int backup[][10], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
			backup[i][j] = matrix[i][j];
}
int changelog(int matrix[][10], int backup[][10], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
		{
			if(matrix[i][j] != backup[i][j])
				return 1;
		}
	return 0;
}
