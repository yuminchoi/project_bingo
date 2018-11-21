#include "print_bingo.h"		//�������� ����ϴ� �Լ��� �ҽ����Ϸ� �������. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int user_bingo[N][N];		//���������� 
int com_bingo[N][N];
int count;
int num;


void initate_bingo(int bingo[N][N]){		//���� ó���� ������ִ� �Լ� 
	int i, j, k, l;
	
	srand((unsigned)time(NULL));		//�� ������ �ٸ� ���� �������� 
	for (i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			bingo[i][j]=rand()%SIZE+1;		
		/*	for(k=0;k<N;k++)
			{
				for(l=0;l<N;l++)
				{
					if(i==k&&j==l)		//���� i=k, j=l�̶�� bingo[i][j]�� ������ bingo[k][l]�� ���� �����Ƿ� ��ȯ���� �������� 
					{
						break;
					}
					if(bingo[i][j]==bingo[k][l])		//�� �̿ܿ� ���� ���ٸ� �迭�� �ߺ��� �Ͼ�ٴ� ���̹Ƿ� j�� ��ĭ �ٿ��� ������ �ο��� ���� �ʱ�ȭ �ǵ��� 
					{
						j--;							//�̶�� ���������� �������� ���� ���� �ʽ��ϴ�. ��κп��� �߸��Ǿ����� ã�� ���� �������ϴ�. 
						break;							//���� �ߺ��� �����ϴ� ���� �����߽��ϴ�. �ּ�ó���� �ڵ�� ���� �����ߴ� �ߺ��� �����ϴ� �ڵ��Դϴ�. 
					}
				}
			}
	*/	}
	}
}

 

int get_number_byMe(int bingo[N][N], int num){		//user���� ���ڸ� ���� 
	int i, j;
	int check;
	
	printf("Choose your number: ");
	scanf("%d", &num);
	
	while(1>num||num>SIZE)		//���� user�� �Է��� ���ڰ� ���� �ۿ� ���� �� 
	{
		printf("�������� �����Դϴ�.\n");
		printf("Choose your number: ");
		scanf("%d", &num);		//�ٽ� �Է¹��� 
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)		//���� �����ǿ� user�� �Է��� ���ڰ� �ִٸ�  
			{
				check=1;
			}				
		}
	}
	while(1)
	{
		if(check==1)
		{
			break;		//�׳� user�� �Է��� ���ڸ� �״�� ��� 
		}
		else		//���� �����ǿ� ���ڰ� ���ٸ� �̹� �����ߴ� �����̹Ƿ� �ٽ� ���ڸ� �Է¹��� 
		{
			printf("������ �����ߴ� �����Դϴ�.\n");
			printf("Choose your number: ");
			scanf("%d", &num);
		}
	}
	
	return num;
}



int get_number_byCom(int bingo[N][N], int num){		//��ǻ�Ͱ� ���ڸ� ���� �ϴ� �Լ� 
	int i, j;
	int check;
	
	srand((unsigned)time(NULL));		//�õ��� ������ �ٸ� ���ڰ� �������� �Ѵ�. 
	num=rand()%(SIZE)+1;		//�ϴ� ������ �̿��ؼ� ���� �߻���Ŵ 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)		//user���� �Է��� �޴� �Լ��� ���� ����. ���� �����ǿ� ���ڰ� ������ �� ���� ���� 
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
		else		//�����ǿ� ���ڰ� ������ �ٽ� ������ �߻���Ŵ. 
		{
			num=rand()%(SIZE)+1;
		}
	}
	printf("The number that computer chose: %d\n", num);
	
	return num;
}


void process_bingo(int bingo[N][N], int num){		//������ ���� -1�� �ٲپ��ִ� �Լ� 
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==num)		//�����ǿ��� �Է¹��� ���� �Ȱ��� ���� ã�Ƴ��� �� ���� ���� -1�� �ٲ۴�. 
			{
				bingo[i][j]=-1;
			}
		}
	}
}


int count_bingo(int bingo[N][N], int count){		//������ ���� �����ִ� �Լ� 
	int sum=0;
	int i, j;
	for(i=0;i<N;i++)		//������ ���ο� ���ؼ� ������ ������ ��� 
	{
		sum=0;		 
		for(j=0;j<N;j++)
		{
			if(bingo[i][j]==-1)
			{
				sum++;
			}
			if(sum==N)		//������ ��� -1�� N����ŭ �����ϹǷ� 
			{
				count++;
			}
		}
	}
	

	for(j=0;j<N;j++)		//������ ���ο� ���ؼ� ������ ������ ��� 
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
	for(i=0;i<N;i++)		//���ʿ��� ���������� �������� �밢���� ���ؼ� �������� �ƴ��� �Ǵ�. 
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
	for(i=0;i<N;i++)		//�����ʿ��� �������� �������� �밢���� ���ؼ� �������� �ƴ��� �Ǵ�. 
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
	
	initate_bingo(user_bingo);		//user�� ������ ���� 
	initate_bingo(com_bingo);		//��ǻ���� ������ ���� 
	print_bingo(user_bingo);		//user�� ������ ȭ�鿡 ��� 
	
	
	do		//win=1�� �ɶ����� ��� �ݺ� 
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
			printf("<��ǻ���� ����>\n");
			print_bingo(com_bingo);
			printf("COMPUTER WIN!\n");
			win++;
		}
		else if(user_count>=WIN)
		{
			printf("<��ǻ���� ����>\n");
			print_bingo(com_bingo);
			printf("USER WIN!\n");
			win++;
		}
	}while(win!=1);
	
	printf("�� ��: %d", turn);
	
	return 0;
}
