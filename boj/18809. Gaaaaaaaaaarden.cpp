#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, g, r, ans;
int g_cnt, r_cnt;
int map[51][51];
int ground[51][51];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
typedef struct info
{
	int y;
	int x;
} info;
info input;
vector<info> possible;
vector<info> red;
vector<info> green;
queue<info> rtime;
queue<info> gtime;
int flower[51][51];

int RED[51][51];
int GREEN[51][51];
bool visit[12];

bool inside(int y, int x)
{
	return y >= 0 && y < n && x >= 0 && x < m;
}

void Input()
{
	cin >> n >> m >> g >> r;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 2)
			{
				input.y = y;
				input.x = x;
				possible.push_back(input);
			}
		}
	}
	g_cnt = g;
	r_cnt = r;
}

void DROP()
{
	memset(RED, 0, sizeof(RED));
	memset(flower, 0, sizeof(flower));
	memset(GREEN, 0, sizeof(GREEN));
	memset(ground, 0, sizeof(ground));
	for (int i = 0; i < red.size(); i++)
	{
		//	cout<<red[i].y<<" "<<red[i].x<<" ";
		ground[red[i].y][red[i].x] = 1;
		RED[red[i].y][red[i].x] = 1;
		input.y = red[i].y;
		input.x = red[i].x;
		rtime.push(input);
	}
	//cout<<endl;
	for (int i = 0; i < green.size(); i++)
	{
		//		cout<<green[i].y<<" "<<green[i].x<<" ";
		ground[green[i].y][green[i].x] = 1;
		GREEN[green[i].y][green[i].x] = 1;
		input.y = green[i].y;
		input.x = green[i].x;
		gtime.push(input);
	}
	//cout<<endl;
	//		cout<<red.size()<<" "<<green.size()<<endl;
	/*for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cout << ground[y][x] << " ";
		}
		cout << endl;
	}*/
}

void BFS()
{
	int cnt = 2;
	int ret = 0;
	while (!rtime.empty() || !gtime.empty())
	{
		int gsize = gtime.size();
		for (int i = 0; i < gsize; i++)
		{
			info cur = gtime.front();
			gtime.pop();
			if (flower[cur.y][cur.x])
				continue;
			for (int j = 0; j < 4; j++)
			{
				int dy = cur.y + dir[j][0];
				int dx = cur.x + dir[j][1];
				if (!inside(dy, dx))
					continue;
				if (GREEN[dy][dx] != 0)
					continue;
				if (RED[dy][dx] != 0)
					continue;
				if (map[dy][dx] == 0)
					continue;
				GREEN[dy][dx] = cnt;
				input.y = dy;
				input.x = dx;
				gtime.push(input);
			}
		}
		int rsize = rtime.size();
		for (int i = 0; i < rsize; i++)
		{
			info cur = rtime.front();
			rtime.pop();
			for (int j = 0; j < 4; j++)
			{
				int dy = cur.y + dir[j][0];
				int dx = cur.x + dir[j][1];
				if (!inside(dy, dx))
					continue;
				if (map[dy][dx] == 0)
					continue;
				if (RED[dy][dx] != 0)
					continue;

				if (RED[cur.y][cur.x] + 1 == GREEN[dy][dx] && !flower[dy][dx])
				{
					flower[dy][dx] = true;
					ret++;
					continue;
				}

				if (GREEN[dy][dx] != 0)
					continue;

				RED[dy][dx] = cnt;
				input.y = dy;
				input.x = dx;
				rtime.push(input);
			}
		}
		cnt++;
	}
	if (ret > ans)
		ans = ret;
}

void select(int index, int gcnt, int rcnt)
{
	//남은 배양액의 수가 남아있는 배양액을 뿌릴 수 있는 땅보다 많으면 안된다(배양액을 남김없이 사용해야 하므로)
	if (gcnt + rcnt > (possible.size() - index))
		return;
	if (gcnt == 0 && rcnt == 0)
	{
		//배양액을 모두 골랐다면 bfs로 배양액을 뿌려준다.
		DROP();
		BFS();
		return;
	}
	if (index == possible.size())
		return;

	int x = possible[index].x;
	int y = possible[index].y;

	//index번째 땅에 배양액을 뿌리지 않는 경우
	select(index + 1, gcnt, rcnt);

	//index번째 땅에 초록색 배양액을 뿌리는 경우
	if (gcnt > 0)
	{
		input.y = y;
		input.x = x;
		green.push_back(input);
		select(index + 1, gcnt - 1, rcnt);
		green.pop_back();
	}

	//index번째 땅에 빨간색 배양액을 뿌리는 경우
	if (rcnt > 0)
	{
		input.y = y;
		input.x = x;
		red.push_back(input);
		select(index + 1, gcnt, rcnt - 1);
		red.pop_back();
	}
}

void DFS(int depth)
{
	if (g_cnt + r_cnt > possible.size() - depth)
		return;
	if (r_cnt == 0 && g_cnt == 0)
	{
		DROP();
		BFS();
		return;
	}
	if (possible.size() == depth)
		return;
	for (int i = depth; i < possible.size(); i++)
	{
		if (!visit[i])
		{
			if (r_cnt != 0)
			{
				visit[i] = true;
				r_cnt--;
				input.y = possible[i].y;
				input.x = possible[i].x;
				red.push_back(input);
				DFS(depth + 1);
				visit[i] = false;
				r_cnt++;
				red.pop_back();
			}
			if (g_cnt != 0)
			{
				visit[i] = true;
				g_cnt--;
				input.y = possible[i].y;
				input.x = possible[i].x;
				green.push_back(input);
				DFS(depth + 1);
				visit[i] = false;
				g_cnt++;
				green.pop_back();
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	//select(0, g, r);
	DFS(0);
	cout << ans;
}
