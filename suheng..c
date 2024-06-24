#include<stdio.h>

int main(void)
{
	int temp;
	int a;
	int b[2];
	int	c[2];
	char d;
	int sum1[100000];
	int sum2[100000];
	char sum3[100000];

	printf("계산 횟수를 입력해주세요 : "); // 계산의 횟수를 구함
	scanf("%d", &a);
	getchar();
	printf("분자와 분모를 입력해주세요: ");
	scanf("%d %d",&b[0], &b[1]);
	sum1[0] = b[0];
	sum2[0] = b[1];
	getchar();

	for (int i = 0; i < a-1 ; i++)
	{
		printf("계산부호를 입력해주세요(+,-,/,*) : "); //계산의 횟수동안 계산부호를 입력받고
		scanf("%c", &d);
		sum3[i + 1] = d;
		getchar();
		printf("분자와 분모를 입력해주세요 : "); // 식을 계산할때 처음 받은 숫자에 계속 저장하면서 새로운 수만 받아 계산하고 다시 처음수를 받은 함수에 저장
		scanf("%d %d",&c[0],&c[1]);
		sum1[i + 1] = c[0];
		sum2[i + 1] = c[1];
		getchar();
		                                                           
		switch (d) // 입력받은 계산부호에 따라 계산
		{
		case '*':
			
			b[1] = b[1] * c[1];
			b[0] = b[0] * c[0];
			
			break;

		case '+':
			temp = b[1];
			b[1] = b[1] * c[1];
			b[0] = b[0] * c[1];
			c[0] = c[0] * temp;
			b[0] = b[0] + c[0];
			
			break;
	
			
			
		case'-':
			temp = b[1];
			b[1] = b[1] * c[1];
			b[0] = b[0] * c[0];
			c[0] = c[0] * temp;
			b[0] = b[0] - c[0];
			break;

		case'/':
			b[1] = b[1] * c[0];
			b[0] = b[0] * c[1];
			break;

		}
		temp = 0;
	
	}
	printf("%d/%d ", sum1[0], sum2[0]);
	for (int k = 1; k < a; k++)
	{
		printf("%c %d/%d ", sum3[k], sum1[k], sum2[k]);
	}
	printf("\n =");
	if (b[0] < b[1]) // 이 아래로는 끝난 계산으로 나온 분수를 기약분수화 후 출력
	{
		
		for (int i = 1; i <= b[0]; i++)
		{
			for (int j = 0; j <= b[0]; j++)
			{
				if (b[0] % i == 0 && b[1] % i == 0)
				{
					b[1] /= i;
					b[0] /= i;
				}
			}
			
		}
		printf("%d/%d", b[0], b[1]);

	}
	else if (b[1] < b[0])
	{
		for (int i = 1; i <= b[1]; i++)
		{
			for (int j = 0; j <= b[1]; j++)
			{
				if (b[1] % i == 0 && b[0] % i == 0)
				{
					b[0] /= i;
					b[1] /= i;
					
				}
			}
			
		}
		printf("%d/%d", b[0], b[1]);
	}
	else if (b[0] == b[1])
	{
		printf("1입니다");
	}
	


}