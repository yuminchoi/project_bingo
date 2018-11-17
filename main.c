#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define WIN 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int user_bingo[N][N];
int com_bingo[N][N];
int count;
int num;


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



void get_number_byMe(int bingo[N][N], int num){
	int i, j;
	
	printf("Choose your number: ");
	scanf("%d", &num);
	if(num<1||num>(N*N))
	{
		printf("범위밖의 숫자입니다.\n");
		printf("Choose your number: ");
		scanf("%d", &num);
	}
	if(bingo[i][j]!=num)
	{
		printf("이전에 선택했던 숫자입니다.\n");
		printf("Choose your number: ");
		scanf("%d", &num);
	}
}



void get_number_byCom(int bingo[N][N], int num_com){
	int i, j;
	srand((unsigned)time(NULL));
	num_com=rand()%(N*N)+1;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]!=num_com)
			{
				num_com=rand()%(N*N)+1;
			}
		}
	}
	printf("The number that computer chose: %d\n", num_com);
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


void count_bingo(int bingo[N][N], int count){
	int sum=0;
	int i, j, k, m, n;
	for(i=0;i<N;i++)
	{
		if(bingo[i][j]==-1)
		{
			sum++;
		}
	}
	if(sum==5)
	{
		count++;
	}
	
	sum=0;
	for(j=0;j<N;j++)
	{
		if(bingo[i][j]==-1)
		{
			sum++;
		}
	}
	if(sum==5)
	{
		count++;
	}
	
	sum=0;
	for(k=0;k<N;k++)
	{
		if(bingo[k][k])
		{
			sum++;
		}
	}
	if(sum==5)
	{
		count++;
	}
	
	sum=0;
	for(m=0;m<N;m++)
	{
		for(n=N-1;n>=0;n--)
		{
			sum++;
		}
	}
	if(sum==5)
	{
		count++;
	}
}


int main(int argc, char *argv[]) {
	
	initate_bingo(user_bingo);
	initate_bingo(com_bingo);
	
	do
	{
	}while()
	return 0;
}
