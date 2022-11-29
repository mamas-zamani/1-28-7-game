#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int input(void);
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
int score = 0, highscore;
FILE *fsave, *fnow;
	enum direction {up, down, left, right, undo, save, Exit
	} in;
int main()
{
	srand(time(NULL));
//	enum direction {up, down, left, right, undo
//	} in;
	int matrix[10][10] = {0}, backup [10][10] = {0}, next[10][10] = {0};
	int size, i, j, flag = 1, flag_input = 1, counter = 0, backupscore = score;
	int firstinput, secondinput, dim, map, undoflag;
	char address[10];
	printf("1.New Game\n2.Saved Game\n");
	scanf("%d", &firstinput);
	if(firstinput == 2)
	{
		fnow = fopen("saved.txt", "r");
		if(fnow == NULL)
		{
			printf("there's no saved game available!!\n");
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
//					printf("%d ", matrix[i][j]);
				}
//				printf("\n");
			}
		}
	}
	if(firstinput == 1)
	{
		system("cls");	
		printf("1.Classic Game\n2.Featured Game\n");
		scanf("%d", &secondinput);
		system("cls");
		if(secondinput == 1)
		{
			printf("1.6x6\n2.7x7\n3.9x9\n");
			scanf("%d", &dim);
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
			scanf("%d", &map);
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
//				printf("%d ", matrix[i][j]);
			}
//			printf("\n");
		}
		new_block(matrix, size);
		new_block(matrix, size);
		new_block(matrix, size);
	}
	system("cls");
	printf("1.Undo off!! (Let's do this!!)\n2.Undo On (I'm a noob :|)\n");
 	scanf("%d", &undoflag);
 	undoflag--;
	system("cls");
	print(matrix, size, score, highscore, counter);
	printf("score: %d\n", score);	
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
				printf("U weren't a noob :))\n");
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
			printf("invalid input\n");
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
	printf("Game over!!\n");
	printf("Your score: %d", score);
	fclose(fnow);
	getch();
	return 0;
}
int input(void)
{
	char ch1 = 0, ch2 = 0;
	ch1 = getch();
	if(ch1 == - 0x20)
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
	else if(ch1 == 27)
		return 6;
	else
	{
		char input[7] = {0}, code[7] = {0};
		code[0] = ch1;
		printf("%c", ch1);
		gets(input);
		strcat(code, input);
		if(!strcmp(code, "up") || !strcmp(code, "Up") || !strcmp(code, "UP") || !strcmp(code, "W") || !strcmp(code, "w"))
			return 0;
		else if(!strcmp(code, "down") || !strcmp(code, "Down") || !strcmp(code, "DOWN") || !strcmp(code, "s") || !strcmp(code, "S"))
			return 1;
		else if(!strcmp(code, "left") || !strcmp(code, "Left") || !strcmp(code, "LEFT") || !strcmp(code, "a") || !strcmp(code, "A"))
			return 2;
		else if(!strcmp(code, "right") || !strcmp(code, "Right") || !strcmp(code, "RIGHT") || !strcmp(code, "d") || !strcmp(code, "D"))
			return 3;
		else if(!strcmp(code, "undo") || !strcmp(code, "Undo") || !strcmp(code, "UNDO") || !strcmp(code, "u") || !strcmp(code, "U"))
			return 4;
		else if(!strcmp(code, "save") || !strcmp(code, "Save") || !strcmp(code, "SAVE"))
			return 5;
		else if(!strcmp(code, "exit") || !strcmp(code, "Exit") || !strcmp(code, "EXIT"))
			return 6;
	return 7;
	}
}
void print(int matrix[][10], int size, int score, int highscore, int counter)
{
	
	int i, j, a = 0, b = 0;
	system("cls");
	for(i = 0; i <= size * 2; i++)
	{
		for(j = 0; j <= size * 5; j++) 
		{
			if(i % 2 == 0 && j % 5 == 0)
				printf(" ");
		    if(i % 2 == 0 && j % 5 != 0)
				printf("-");
			if(i % 2 == 1 && j % 5 == 0)
				printf("|");
			if(i % 2 == 1 && j % 5 == 1)
			{
				if(!matrix[a][b])
					printf("    ");
				else if(matrix[a][b] == 1)
					printf("||||");
				else
					printf("%4d", matrix[a][b]);
				b++;
				if(b == size)
					b = 0;
			}			
		}
		if(i % 2 == 1)
			a++;
		printf("\n");	
	}
	printf("score: %d\tmoves: %d\thighscore: %d\n", score, counter, highscore);	
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
void predictor(int matrix[][10], int next[][10], int size)
{
	int maxscore = 0, current;
	enum direction direct, maxdirect = 0;
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
	switch(maxdirect)
	{
		case up:
		printf("the best move for you is to go \"up\" and your score will be :%d\n", maxscore);
		break;
		case down:
		printf("the best move for you is to go \"down\" and your score will be :%d\n", maxscore);
		break;
		case left:
		printf("the best move for you is to go \"left\" and your score will be :%d\n", maxscore);
		break;
		case right:
		printf("the best move for you is to go \"right\" and your score will be :%d\n", maxscore);
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
//	printf("%d\n", lastscore);
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
