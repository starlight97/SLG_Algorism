// 1 ~ N ���� �ڿ����� �� S
// 1. 1���� 1�� ������Ű�� ������ ���
// 2. �������� S�� �Ѿ�ٸ� ���� �ε����� �ִ�

#include <iostream>

using namespace std;

int main()
{
	long long S;
	cin >> S;

	long long index = 1;
	long long sum = 0;
	while (true)
	{
		// 1. 1���� 1�� ������Ű�� ������ ���
		sum += index;

		// 2. �������� S�� �Ѿ�ٸ� ���� �ε����� �ִ�
		if (sum > S)
			break;

		index++;

	}

	cout << index - 1;

	return 0;
}