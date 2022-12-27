#include <iostream>

using namespace std;


int map[500][500];
int col, row, ownBlocks;
int totalBlockAmount, maxHeight;
int t = 99999999, height;

void Solution()
{
	// �ִ� ���� ���ϱ�
	// �ִ� ���� = �Ѻ�ϰ��� / (���� * ����)
	maxHeight = totalBlockAmount / (col * row);

	for (int h = 0; h <= maxHeight; h++)
	{
		int currentTime = 0;

		for (int y = 0; y < col; y++)
		{
			for (int x = 0; x < row; x++)
			{
				// ���� ���̺��� ũ�ٸ� ���� �Ǵ�.
				if (map[y][x] > h)				
					currentTime += ((map[y][x] - h) *2);				
				// ���� ���̺��� �۴ٸ� ����� �״´�.
				else if (map[y][x] < h)
					currentTime += (h - map[y][x]);				
			}
		}

		// ���� �۾��ð��� �ּڰ� ���� �۴ٸ� ����
		if (currentTime < t)
		{
			t = currentTime;
			height = h;
		}
		// ���� �۾��ð��� �ּڰ��� �����鼭 ���� ���̰� �� ���ٸ� ����
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