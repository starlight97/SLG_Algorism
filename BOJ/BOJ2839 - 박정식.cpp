#include <iostream>
#define MAX 5000 + 1
using namespace std;

int N;

int Solution()
{
	int result = -1;
	int bigBagMaxAmount = N / 5;

	// �ϴ� ū������ �ִ��� ���� ����������� ū������1���� �����鼭 ã�´�.
	for (int i = bigBagMaxAmount; i >= 0; i--)
	{
		// n(��������) = (�� ������ ����) - (ū������ ���� * 5) 
		int n = N - (i * 5);
		// ���� ������ 3���� ������ �������� ���� ��������.
		if (n % 3 == 0)
		{
			result = i + (n / 3);
			break;
		}
	}

	return result;
}

void Input()
{
	cin >> N;
}

int main()
{
	Input();
	cout << Solution() << endl;
	return 0;
}