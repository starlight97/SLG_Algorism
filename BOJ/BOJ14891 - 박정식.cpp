#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string gear[6];
bool visit[6];
vector<pair<int, int>> v;
// ȸ�� Ƚ��
int K;

void Reset()
{
	for (int i = 1; i < 5; i++)
	{
		visit[i] = false;
	}
}

void Rotation(int index, int dir)
{
	// 1234 ��ϰ� �ƴ϶�� ��� ����
	if (index < 1 || index > 4)
		return;
	// �̹� �ѹ� ���ư� ��϶�� ��� ����
	if (visit[index] == true)
		return;

	// ���ư� ��� �湮 ǥ��
	visit[index] = true;

	// ���� ����
	if (dir == 1)
	{
		gear[index] = gear[index][7] + gear[index].substr(0, 7);

		if(gear[index][7] != gear[index - 1][2])
			Rotation(index - 1, -dir);
		if (gear[index][3] != gear[index + 1][6])
			Rotation(index + 1, -dir);
	}		
	// ���� ����
	else
	{
		gear[index] = gear[index].substr(1, 7) + gear[index][0];

		if (gear[index][5] != gear[index - 1][2])
			Rotation(index - 1, -dir);
		if (gear[index][1] != gear[index + 1][6])
			Rotation(index + 1, -dir);
	}
}

void Solution()
{
	int result = 0;
	// ������� �ʴ� ���
	gear[0] = "00000000";
	gear[5] = "00000000";

	for (int i = 0; i < K; i++)
	{
		int gearIndex = v[i].first;
		int dir = v[i].second;

		Rotation(gearIndex, dir);
		Reset();
	}

	// ���� ��Ϲ������� 12�� ���� üũ
	for (int i = 1; i < 5; i++)
	{
		if (gear[i][0] == '1')
		{
			result += pow(2, i - 1);
		}
	}
	cout << result << endl;
}

void Input()
{
	for (int i = 1; i < 5; i++)
	{
		cin >> gear[i];
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int gearIndex;
		int dir;
		cin >> gearIndex;
		cin >> dir;
		v.push_back({gearIndex, dir });
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solution();

	return 0;
}