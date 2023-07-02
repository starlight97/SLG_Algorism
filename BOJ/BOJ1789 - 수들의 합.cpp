// 1 ~ N 개의 자연수의 합 S
// 1. 1부터 1씩 증가시키며 누적합 계산
// 2. 누적합이 S를 넘어섰다면 이전 인덱스가 최댓값

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
		// 1. 1부터 1씩 증가시키며 누적합 계산
		sum += index;

		// 2. 누적합이 S를 넘어섰다면 이전 인덱스가 최댓값
		if (sum > S)
			break;

		index++;

	}

	cout << index - 1;

	return 0;
}