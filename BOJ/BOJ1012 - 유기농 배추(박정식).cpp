#define _CRT_SECURE_NO_WARNINGS
#define X first
#define Y second
#define MAX 50+1

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int visited[MAX][MAX];
int map[MAX][MAX];


// T : �׽�Ʈ ���̽� ����, M : ���߹��� ���� ����
// N : ���߹��� ���� ����, K : ���� ����
int T, M, N, K;
// wormCnt : ������������
int wormCnt;
// ��������
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };


// �׽�Ʈ ���̽����� ���߹��, �湮ó���� �ʱ�ȭ
void reset()
{
    wormCnt = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            map[x][y] = 0;
            visited[x][y] = 0;
        }
    }
}

void dfs_stack(int x, int y)
{
    stack<pair<int, int>> s;
    // ��� ���� �湮ó��
    visited[x][y] = 1;
    s.push({ x,y });

    while (!s.empty())
    {
        pair<int, int> cur = s.top();
        s.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            // nx = nextX, ny = nextY             
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // �������� Ž���� ���߹��� ����ų� 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // �̹� �湮�� �ߴ����̰ų�, �ش������� ���߰� ������� �湮�� �ʿ䰡 �����Ƿ� �湮ó�� X
            if (visited[nx][ny] == 1 || map[nx][ny] != 1)
                continue;
            visited[nx][ny] = 1;
            s.push({nx, ny});
        }
    }
}

void bfs_queue(int x, int y)
{
    queue<pair<int, int>> q;
    // ��� ���� �湮ó��
    visited[x][y] = 1;
    q.push({x,y});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            // nx = nextX, ny = nextY             
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // �������� Ž���� ���߹��� ����ų� 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // �̹� �湮�� �ߴ����̰ų�, �ش������� ���߰� ������� �湮�� �ʿ䰡 �����Ƿ� �湮ó�� X
            if (visited[nx][ny] == 1 || map[nx][ny] != 1)
                continue;
            visited[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;    
    
    for (int t = 0; t < T; t++)
    {        
        cin >> M >> N >> K;
        reset();
        // ���߹� ������ �Է�
        for (int k = 0; k < K; k++)
        {
            int x, y;
            cin >> x >> y;
            // �Է� �����Ϳ� �� ��ǥ�� ���߱����� y x �ٲ��ֱ�
            // ex 1 1 0
            //    0 1 0
            //    0 0 0
            // (0,0), (0,1), (1,1)
            map[y][x] = 1;
        }
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < M; y++)
            {
                if (map[x][y] == 1 && visited[x][y] == 0)
                {
                    //dfs_stack(x,y);
                    bfs_queue(x,y);
                    // Ž���� ���������� ������������ �Ѹ����� �÷��ֱ�
                    wormCnt++;
                }
            }
        }
        cout << wormCnt << endl;
    }

    return 0;
}