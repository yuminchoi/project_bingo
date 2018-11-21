#include "print_bingo.h"		//빙고판을 출력하는 함수를 소스파일로 만들었음. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int user_bingo[N][N];		//전역변수들 
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
			bingo[i][j]=rand()%SIZE+1;
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



int get_number_byMe(int bingo[N][N], int num){		//user에게 숫자를 받음 
	int i, j;
	int check;
	
	printf("Choose your number: ");
	scanf("%d", &num);
	
	while(1>num||num>SIZE)		//만약 user가 입력한 숫자가 범위 밖에 있을 때 
	{
		printf("범위밖의 숫자입니다.\n");
		printf("Choose your number: ");
		scanf("%d", &num);		//다시 입력받음 
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)		//만약 빙고판에 user가 입력한 숫자가 있다면  
			{
				check=1;
			}				
		}
	}
	while(1)
	{
		if(check==1)
		{
			break;		//그냥 user가 입력한 숫자를 그대로 사용 
		}
		else		//만약 빙고판에 숫자가 없다면 이미 선택했던 숫자이므로 다시 숫자를 입력받음 
		{
			printf("이전에 선택했던 숫자입니다.\n");
			printf("Choose your number: ");
			scanf("%d", &num);
		}
	}
	
	return num;
}



int get_number_byCom(int bingo[N][N], int num){		//컴퓨터가 숫자를 고르게 하는 함수 
	int i, j;
	int check;
	
	srand((unsigned)time(NULL));		//시도할 때마다 다른 숫자가 나오도록 한다. 
	num=rand()%(SIZE)+1;		//일단 난수를 이용해서 숫자 발생시킴 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)		//user에게 입력을 받는 함수와 같은 원리. 만약 빙고판에 숫자가 있으면 그 값을 선택 
			{
				check=1;
			}
		}
	}
	
	while(1)
	{
		if(check==1)
		{
			break;
		}
		else		//빙고판에 숫자가 없으면 다시 난수를 발생시킴. 
		{
			num=rand()%(SIZE)+1;
		}
	}
	printf("The number that computer chose: %d\n", num);
	
	return num;
}


void process_bingo(int bingo[N][N], int num){		//빙고의 값을 -1로 바꾸어주는 함수 
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)		//빙고판에서 입력받은 값과 똑같은 값을 찾아내면 그 곳의 값을 -1로 바꾼다. 
			{
				bingo[i][j]=-1;
			}
		}
	}
}


int count_bingo(int bingo[N][N], int count){		//빙고의 수를 세어주는 함수 
	int sum=0;
	int i, j;
	for(i=0;i<N;i++)		//빙고의 가로에 대해서 빙고의 개수를 계산 
	{
		sum=0;		 
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==-1)
			{
				sum++;
			}
			if(sum==N)		//빙고일 경우 -1이 N개만큼 존재하므로 
			{
				count++;
			}
		}
	}
	

	for(j=0;j<N;j++)		//빙고의 세로에 대해서 빙고의 개수를 계산 
	{
		sum=0;
		for(i=0;i<N;i++)
		{
			if(bingo[i][j]==-1)
			{
				sum++;
			}
			if(sum==N)
			{
				count++;
			}
		}
	}
	
	sum=0;	
	for(i=0;i<N;i++)		//왼쪽에서 오른쪽으로 내려오는 대각선에 대해서 빙고인지 아닌지 판단. 
	{
		if(bingo[i][i]==-1)
		{
			sum++;
		}
	}
	if(sum==N)
	{
		count++;
	}
	
	sum=0;
	for(i=0;i<N;i++)		//오른쪽에서 왼쪽으로 내려오는 대각선에 대해서 빙고인지 아닌지 판단. 
	{
		if(bingo[i][N-1-i]==-1)
		{
			sum++;
		}
	}
	if(sum==N)
	{
		count++;
	}
	
	return count;
}

int main(int argc, char *argv[]) {
	int num_user, num_com;
	int user_count, com_count;
	int win;
	int turn;
	
	initate_bingo(user_bingo);		//user의 빙고판 생성 
	initate_bingo(com_bingo);		//컴퓨터의 빙고판 생성 
	print_bingo(user_bingo);		//user의 빙고판 화면에 출력 
	
	
	do		//win=1이 될때까지 계속 반복 
	{
		get_number_byMe(user_bingo, num_user);
		process_bingo(user_bingo, num_user);
		process_bingo(com_bingo, num_user);
		get_number_byCom(com_bingo, num_com);
		process_bingo(user_bingo, num_com);
		process_bingo(com_bingo, num_com);
		count_bingo(user_bingo, user_count);
		count_bingo(com_bingo, com_count);
		turn++;
		
		
		if(com_count>=WIN)
		{
			printf("<컴퓨터의 빙고>\n");
			print_bingo(com_bingo);
			printf("COMPUTER WIN!\n");
			win++;
		}
		else if(user_count>=WIN)
		{
			printf("<컴퓨터의 빙고>\n");
			print_bingo(com_bingo);
			printf("USER WIN!\n");
			win++;
		}
	}while(win!=1);
	
	printf("턴 수: %d", turn);
	
	return 0;
}
