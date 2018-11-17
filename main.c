#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define WIN 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initate_bingo(int bingo[N][N]){
	int i, j, k, l;
	
	srand((unsigned)time(NULL));
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			bingo[i][j]=rand()%(N*N)+1;
			for(k=0;k<N;k++)
			{
				for(l=0;l<j;l++)
				{
					if(bingo[i][j]==bingo[k][l])
					{
						j--;
						break;
					}
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



void get_number_byMe(){
	int num;
	printf("Choose your number: ");
	scanf("%d", &num);
	if(num<1||num>25)
	{
		printf("범위밖의 숫자입니다.\n");
		printf("Choose your number: ");
		scanf(%d, &num);
	}
	//이전에 선택했던 숫자를 선택했을경우 메시지 출력 
}



void get_number_byCom(){
	int num_com;
	num_com=rand()%(N*N)+1;
	//똑같은 숫자를 선택했을 경우 바꿔줘야 
}


void process_bingo(int bingo[N][N], int num){
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)
			{
				bingo[i][j]=-1;
			}
		}
	}
	
}


void count_bingo(){
	
}


int main(int argc, char *argv[]) {
	do
	{
	}while()
	return 0;
}
