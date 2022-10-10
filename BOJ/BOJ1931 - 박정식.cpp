#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 1
using namespace std;

struct MeetingTime
{
	int start;
	int end;
};
bool compare(MeetingTime mt1, MeetingTime mt2)
{
	// 종료시간이 같다면
	if (mt1.end == mt2.end)
	{
		// 시작시간이 빠른 순서대로 정렬
		if (mt1.start > mt2.start)
			return false;
		else
			return true;
	}

	// 종료시간이 빠른 순서대로 정렬
	if (mt1.end > mt2.end)
		return false;
	else
		return true;
}

vector<MeetingTime> v;
int N;

int Solution()
{
	int result = 0;

	sort(v.begin(), v.end(), compare);
	// 현재 시간을 나타내는 변수
	int time = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// 현재시간보다 회의실 시작	시간이 늦다면 회의를 시작할 수 있는 상태이다.
		if (v[i].start >= time)
		{
			// 회의를 시작했으므로 현재 시간은 현재 시작한 회의에 종료 시간이 된다.
			time = v[i].end;
			// 회의를 하나 할 때마다 회의실 배정 횟수 1씩 증가시켜주기.
			result++;
		}
	}
	return result;
}

void Input()
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		v.push_back({ startTime, endTime});
	}
}

int main()
{
	Input();
	cout << Solution() << endl;
	return 0;
}