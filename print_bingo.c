#include "print_bingo.h"

int user_bingo[N][N];
int count;
int num;


void print_bingo(int bingo[N][N]){		//�������� ȭ�鿡 ����ϴ� �Լ� 
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ", bingo[i][j]);
		}
		printf("\n");
	}
}

