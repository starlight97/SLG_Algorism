#include <iostream>
#define MAX 5000 + 1
using namespace std;

int N;

int Solution()
{
	int result = -1;
	int bigBagMaxAmount = N / 5;

	// 일단 큰봉지로 최대한 많이 덜어놓은다음 큰봉지를1개씩 빼보면서 찾는다.
	for (int i = bigBagMaxAmount; i >= 0; i--)
	{
		// n(남은사탕) = (총 사탕의 갯수) - (큰봉지의 갯수 * 5) 
		int n = N - (i * 5);
		// 남은 사탕이 3으로 나누어 떨어지면 답이 구해진다.
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