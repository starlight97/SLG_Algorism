// 1. ���� ��ġ���� ���� ��ġ���� ���� �� �ʿ��� �⸧�� ���ٸ� �⸧�� ����
// 2. �⸧�� ������ �� �迭�� ���� ���󺸴� �⸧ ������ �� ���� �ִٸ� �ּ����� �⸧�� ����
// 3. �⸧�� ������ �� �迭�� ���� ���󺸴� �⸧ ������ �� ������ �̵��� �ʿ��� �⸧�� ����

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct City
{
	// �⸧ ����
	long long oilPrice;
	// ���� �������� �Ÿ�
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
		// 1. ���� ��ġ���� ���� ��ġ���� ���� �� �ʿ��� �⸧�� ���ٸ� �⸧�� ����
		if (oil < cities[index].nextDistances)
		{
			// 2. �⸧�� ������ �� �迭�� ���� ���󺸴� �⸧ ������ �� ���� �ִٸ� �ּ����� �⸧�� ����
			if (cities[index+1].oilPrice < cities[index].oilPrice)
			{
				oil += cities[index].nextDistances;
				result += oil * cities[index].oilPrice;
			}
			else
			{
				// 3. �⸧�� ������ �� �迭�� ���� ���󺸴� �⸧ ������ �� ������ �̵��� �ʿ��� �⸧�� ����
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