// �迭 A�� �迭 B�� ���ؼ� �ּ��� ���� ����� ���ؼ� ���� ���� �� �� ���� ���� ���� ���ϸ� �˴ϴ�.
// 1. �迭 A�� �������� ����, �迭 B�� �������� ����
// 2. �� ���ĵ� �迭 A�� �迭 B�� ���� �� �����ݴϴ�.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ��������
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
	vector<int> A(N), B(N);

	for (int index = 0; index < N; index++)
		cin >> A[index];

	for (int index = 0; index < N; index++)
		cin >> B[index];

	// 1. �迭 A�� �������� ����, �迭 B�� �������� ����
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), Compare);

	int result = 0;

	// 2. �� ���ĵ� �迭 A�� �迭 B�� ���� �� �����ݴϴ�.
	for (int index = 0; index < N; index++)
		result += A[index] * B[index];


	cout << result << endl;

	return 0;
}
