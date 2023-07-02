// 배열 A와 배열 B를 곱해서 최소의 수를 만들기 위해선 가장 높은 수 와 가장 낮은 수를 곱하면 됩니다.
// 1. 배열 A는 오름차순 정렬, 배열 B는 내림차순 정렬
// 2. 각 정렬된 배열 A와 배열 B를 곱한 후 더해줍니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 내림차순
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

	// 1. 배열 A는 오름차순 정렬, 배열 B는 내림차순 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), Compare);

	int result = 0;

	// 2. 각 정렬된 배열 A와 배열 B를 곱한 후 더해줍니다.
	for (int index = 0; index < N; index++)
		result += A[index] * B[index];


	cout << result << endl;

	return 0;
}
