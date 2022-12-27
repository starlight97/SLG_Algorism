#include <iostream>

using namespace std;


int map[500][500];
int col, row, ownBlocks;
int totalBlockAmount, maxHeight;
int t = 99999999, height;

void Solution()
{
	// 최대 높이 구하기
	// 최대 높이 = 총블록갯수 / (가로 * 세로)
	maxHeight = totalBlockAmount / (col * row);

	for (int h = 0; h <= maxHeight; h++)
	{
		int currentTime = 0;

		for (int y = 0; y < col; y++)
		{
			for (int x = 0; x < row; x++)
			{
				// 현재 높이보다 크다면 땅을 판다.
				if (map[y][x] > h)				
					currentTime += ((map[y][x] - h) *2);				
				// 현재 높이보다 작다면 블록을 쌓는다.
				else if (map[y][x] < h)
					currentTime += (h - map[y][x]);				
			}
		}

		// 현재 작업시간이 최솟값 보다 작다면 갱신
		if (currentTime < t)
		{
			t = currentTime;
			height = h;
		}
		// 현재 작업시간이 최솟값과 같으면서 현재 높이가 더 높다면 갱신
		if (currentTime == t)
		{
			if (height < h)
				height = h;
		}
	}

	cout << t << " " << height;
}

void Input()
{
	cin >> col >> row >> ownBlocks;
	totalBlockAmount += ownBlocks;

	for (int y = 0; y < col; y++)
	{
		for (int x = 0; x < row; x++)
		{
			cin >> map[y][x];
			totalBlockAmount += map[y][x];
		}
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