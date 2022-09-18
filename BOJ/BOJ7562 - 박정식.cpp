#define MAX 300 + 1
#define Y first
#define X second
#include <iostream>
#include <queue>

using namespace std;


// 나이트의 탐색 방향 일반적인 상하좌우가 아니에요.
// https://www.acmicpc.net/problem/7562
// 총 8방향이동 하니까 배열도 8개 만들어주기
// 좌상단부터 우상단순으로 넣었어요
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int map[MAX][MAX];
// I : 체스판의 크기는 I*I 이에요
int I;
queue<pair<int, int>> q;

// 테스트 케이스가 끝날때마다 맵과 큐를 초기상태로 초기화 해주는 작업이 필요해요.
void reset()
{
	for (int y = 0; y < I; y++)
	{
		for (int x = 0; x < I; x++)
		{
			map[y][x] = 0;
		}
	}

	while (!q.empty())
		q.pop();
}

void Bfs(int y, int x)
{
	// 시작지점 큐에 넣어놓고
	q.push({y, x});
	// 큐가 빌때까지 BFS 탐색 하기
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();		

		for (int dir = 0; dir < 8; dir++)
		{
			// 8방향 탐색
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			// 탐색 지점이 맵을 벗어났다면 스킵
			if (ny < 0 || nx < 0 || ny >= I || nx >= I)
				continue;
			// 도착 지점을 찾았다면 현재 맵에 있는 시간을 도착지점에 넣어놓고 탐색을 끝낸다.
			if (map[ny][nx] == -1)
			{
				map[ny][nx] = map[cur.Y][cur.X];
				return;
			}
			// 이미 방문한 지점이라면 스킵한다
			if (map[ny][nx] != 0)
				continue;

			// 맵에는 각지점에 도달하기 까지 걸리는 시간이 들어있는것을 구현하기위해 1씩 더해줌
			map[ny][nx] = map[cur.Y][cur.X] + 1;
			q.push({ny, nx});
				
		}
	}
}

int main()
{
	// t : 테스트케이스 개수
	int t;
	cin >> t;

	// 테스트케이스 개수만큼 실행
	for (int i = 0; i < t; i++)
	{
		// 체스판 크기 설정해주기
		cin >> I;

		// 나이트 시작 지점
		int startY, startX;
		cin >> startY >> startX;
		// 나이트 도착 지점
		int endY, endX;
		cin >> endY >> endX;

		// 시작 지점은 1부터 시작
		map[startY][startX] = 1;
		// 도착 지점은 -1로 표시해두기
		map[endY][endX] = -1;

		// 시작 지점부터 BFS 탐색 시작하기
		Bfs(startY, startX);
		cout << map[endY][endX] << "\n";
		reset();
	}

	return 0;
}