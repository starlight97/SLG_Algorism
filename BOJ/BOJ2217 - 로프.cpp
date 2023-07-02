// 1. ���� ������������ ����
// 2. ���� ưư�� �������� �߰��ϸ� �ִ� �߷� ���
// 3. �ִ� �߷� = max(���� �� * �� ���� �� ���� ���� ���� �߷�, �ִ� �߷�)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int num1, int num2)
{
	if (num1 > num2)
		return true;
	return false;
}

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (int index = 0; index < N; index++)
		cin >> v[index];

	// 1. ���� ������������ ����
	sort(v.begin(), v.end(), Compare);

	int maxWeight = 0;

	// 2. ���� ưư�� �������� �߰��ϸ� �ִ� �߷� ���
	for (int index = 0; index < N; index++)
	{
		// 3. �ִ� �߷� = max(���� �� * �� ���� �� ���� ���� ���� �߷�, �ִ� �߷�)
		maxWeight = max(maxWeight, v[index] * (index+1));
	}

	cout << maxWeight << endl;

	return 0;
}