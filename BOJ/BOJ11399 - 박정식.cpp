#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 1
using namespace std;

int N;
// 데이터 입력을 받을 벡터
vector<int> v;

int Solution()
{
	int result = 0;
	sort(v.begin(), v.end());
	// 누적합을 더하면서 result를 구할것 이기 떄문에 미리 맨처음 벡터값을 더해 놓는다.
	result += v[0];
	for (int i = 1; i < N; i++)
	{
		// 누적합 구하기
		v[i] += v[i - 1];
		// 누적합들의 합 result에 저장
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