// 1. 로프 내림차순으로 정렬
// 2. 가장 튼튼한 로프부터 추가하며 최대 중량 계산
// 3. 최대 중량 = max(로프 수 * 고른 로프 중 가장 약한 로프 중량, 최대 중량)

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

	// 1. 로프 내림차순으로 정렬
	sort(v.begin(), v.end(), Compare);

	int maxWeight = 0;

	// 2. 가장 튼튼한 로프부터 추가하며 최대 중량 계산
	for (int index = 0; index < N; index++)
	{
		// 3. 최대 중량 = max(로프 수 * 고른 로프 중 가장 약한 로프 중량, 최대 중량)
		maxWeight = max(maxWeight, v[index] * (index+1));
	}

	cout << maxWeight << endl;

	return 0;
}