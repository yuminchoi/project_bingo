#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initate_bingo(int bingo[N][N]){
	int i, j, k;
	
	srand((unsigned)time(NULL));
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			bingo[i][j]=rand()%(N*N)+1;
			for(k=0;k<N;k++)
			{
				if(bingo[i][j]==bingo[i][k])
				{
					j--;
					break;
				}
			}
		}
	}
}


void print_bingo(int bingo[N][N]){
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ", &bingo[i][j]);
		}
		printf("\n");
	}
}



void get_number_byMe()
void get_number_byCom()
void process_bingo()
void count_bingo()


int main(int argc, char *argv[]) {
	return 0;
}
