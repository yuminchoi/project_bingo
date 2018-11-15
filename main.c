#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initate_bingo(int bingo[SIZE][SIZE]){
	int i, j, k;
	
	srand((unsigned)time(NULL));
	for (i=0;i<SIZE;i++)
	{
		for (j=0;j<SIZE;j++)
		{
			bingo[i][j]=rand()%(SIZE*SIZE)+1;
			if(bingo[i][j]==bingo[i][k])
			{
				j--;
			}	
		}
	}
}


void print_bingo(int bingo[SIZE][SIZE])

void get_number_byMe()
void get_number_byCom()
void process_bingo()
void count_bingo()


int main(int argc, char *argv[]) {
	return 0;
}
