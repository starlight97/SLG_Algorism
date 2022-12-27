#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string gear[6];
bool visit[6];
vector<pair<int, int>> v;
// 회전 횟수
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
	// 1234 톱니가 아니라면 즉시 종료
	if (index < 1 || index > 4)
		return;
	// 이미 한번 돌아간 톱니라면 즉시 종료
	if (visit[index] == true)
		return;

	// 돌아간 톱니 방문 표시
	visit[index] = true;

	// 우측 방향
	if (dir == 1)
	{
		gear[index] = gear[index][7] + gear[index].substr(0, 7);

		if(gear[index][7] != gear[index - 1][2])
			Rotation(index - 1, -dir);
		if (gear[index][3] != gear[index + 1][6])
			Rotation(index + 1, -dir);
	}		
	// 좌측 방향
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
	// 사용하지 않는 톱니
	gear[0] = "00000000";
	gear[5] = "00000000";

	for (int i = 0; i < K; i++)
	{
		int gearIndex = v[i].first;
		int dir = v[i].second;

		Rotation(gearIndex, dir);
		Reset();
	}

	// 최종 톱니바퀴들의 12시 방향 체크
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