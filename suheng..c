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

	printf("��� Ƚ���� �Է����ּ��� : "); // ����� Ƚ���� ����
	scanf("%d", &a);
	getchar();
	printf("���ڿ� �и� �Է����ּ���: ");
	scanf("%d %d",&b[0], &b[1]);
	sum1[0] = b[0];
	sum2[0] = b[1];
	getchar();

	for (int i = 0; i < a-1 ; i++)
	{
		printf("����ȣ�� �Է����ּ���(+,-,/,*) : "); //����� Ƚ������ ����ȣ�� �Է¹ް�
		scanf("%c", &d);
		sum3[i + 1] = d;
		getchar();
		printf("���ڿ� �и� �Է����ּ��� : "); // ���� ����Ҷ� ó�� ���� ���ڿ� ��� �����ϸ鼭 ���ο� ���� �޾� ����ϰ� �ٽ� ó������ ���� �Լ��� ����
		scanf("%d %d",&c[0],&c[1]);
		sum1[i + 1] = c[0];
		sum2[i + 1] = c[1];
		getchar();
		                                                           
		switch (d) // �Է¹��� ����ȣ�� ���� ���
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
	if (b[0] < b[1]) // �� �Ʒ��δ� ���� ������� ���� �м��� ���м�ȭ �� ���
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
		printf("1�Դϴ�");
	}
	


}