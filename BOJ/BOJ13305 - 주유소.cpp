// 1. 현재 위치에서 다음 위치까지 가는 데 필요한 기름이 없다면 기름을 충전
// 2. 기름을 충전할 때 배열에 현재 나라보다 기름 가격이 싼 곳이 있다면 최소한의 기름만 충전
// 3. 기름을 충전할 때 배열에 현재 나라보다 기름 가격이 싼 곳까지 이동에 필요한 기름을 충전

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct City
{
	// 기름 가격
	long long oilPrice;
	// 다음 지역까지 거리
	long long nextDistances;
};

vector<City> cities(100001);
int N;

int main()
{
	cin >> N;

	long long oil = 0;
	long long result = 0;

	for (int index = 0; index < N - 1; index++)
		cin >> cities[index].nextDistances;

	for (int index = 0; index < N - 1; index++)
		cin >> cities[index].oilPrice;

	for (int index = 0; index < N - 1; index++)
	{
		// 1. 현재 위치에서 다음 위치까지 가는 데 필요한 기름이 없다면 기름을 충전
		if (oil < cities[index].nextDistances)
		{
			// 2. 기름을 충전할 때 배열에 현재 나라보다 기름 가격이 싼 곳이 있다면 최소한의 기름만 충전
			if (cities[index+1].oilPrice < cities[index].oilPrice)
			{
				oil += cities[index].nextDistances;
				result += oil * cities[index].oilPrice;
			}
			else
			{
				// 3. 기름을 충전할 때 배열에 현재 나라보다 기름 가격이 싼 곳까지 이동에 필요한 기름을 충전
				long long remainingDistance = 0;
				for (int j = index; j < N - 1; j++)
				{
					if (cities[j].oilPrice < cities[index].oilPrice)
						break;
					remainingDistance += cities[j].nextDistances;
				}

				oil += remainingDistance;
				result += oil * cities[index].oilPrice;
			}
		}

		oil -= cities[index].nextDistances;
	}

	cout << result << endl;
	return 0;
}