#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 1
using namespace std;

int N;
// ������ �Է��� ���� ����
vector<int> v;

int Solution()
{
	int result = 0;
	sort(v.begin(), v.end());
	// �������� ���ϸ鼭 result�� ���Ұ� �̱� ������ �̸� ��ó�� ���Ͱ��� ���� ���´�.
	result += v[0];
	for (int i = 1; i < N; i++)
	{
		// ������ ���ϱ�
		v[i] += v[i - 1];
		// �����յ��� �� result�� ����
		result += v[i];
	}
	return result;
}

void Input()
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
}

int main()
{
	Input();
	cout << Solution() << endl;
	return 0;
}