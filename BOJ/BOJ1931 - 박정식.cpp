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
	// ����ð��� ���ٸ�
	if (mt1.end == mt2.end)
	{
		// ���۽ð��� ���� ������� ����
		if (mt1.start > mt2.start)
			return false;
		else
			return true;
	}

	// ����ð��� ���� ������� ����
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
	// ���� �ð��� ��Ÿ���� ����
	int time = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// ����ð����� ȸ�ǽ� ����	�ð��� �ʴٸ� ȸ�Ǹ� ������ �� �ִ� �����̴�.
		if (v[i].start >= time)
		{
			// ȸ�Ǹ� ���������Ƿ� ���� �ð��� ���� ������ ȸ�ǿ� ���� �ð��� �ȴ�.
			time = v[i].end;
			// ȸ�Ǹ� �ϳ� �� ������ ȸ�ǽ� ���� Ƚ�� 1�� ���������ֱ�.
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