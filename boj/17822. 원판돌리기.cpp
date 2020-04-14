#include <iostream>
#include <cstring>
using namespace std;

int N, M, T;
int x, d, k;
int ans;
int map[51][51];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int flag = 0;
bool check[51][51];

int inside(int y, int x)
{
    return y >= 1 && y <= N && x >= 1 && x <= M;
}

void print_map()
{
    cout << endl;
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
        {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }
}

void Rotation()
{
    //원판 돌리기 함수
    //k값이 큰 경우를 대비해 M으로 나눠주었다.

    int cnt = k % M;

    for (int i = x; i <= N; i = i + x)
    {
        int arr[M + 1];
        //한번에 돌려도 되지만, 구현력이 부족한 덕분에 한번씩 움직여서 cnt만큼 반복했다.
        for (int k = 0; k < cnt; k++)
        {
            if (d == 0)
            {
                for (int j = 1; j < M; j++)
                    arr[j + 1] = map[i][j];
                arr[1] = map[i][M];
            }
            else
            {
                for (int j = M; j > 1; j--)
                    arr[j - 1] = map[i][j];
                arr[M] = map[i][1];
            }
            for (int j = 1; j <= M; j++)
                map[i][j] = arr[j];
        }
    }
    // print_map();
}

void value_change(int y, int x)
{
    //인접한 원판이 있고, 값이 동일한지 확인하는 함수
    //flag 는 전역플래그로 동일한 값을 가진 원판이 있는지 체크한다.
    //f는 지역플래그로 해당 좌표에서 동일한 값을 가진 원판이 있는지 체크한다.

    int f = 0;
    for (int i = 0; i < 2; i++)
    {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        if (inside(dy, dx))
        {
            if (map[dy][dx] == map[y][x])
            {
                flag = 1;
                f = 1;
                check[dy][dx] = true;
            }
        }
    }

    for (int i = 2; i < 4; i++)
    {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        //원판이 범위를 나갔을 경우, 돌려준다.
        if (dx > M)
            dx = 1;
        else if (dx == 0)
            dx = M;
        if (inside(dy, dx))
        {
            if (map[dy][dx] == map[y][x])
            {
                flag = 1;
                f = 1;
                check[dy][dx] = true;
            }
        }
    }
    if (f == 1)
        check[y][x] = true;
}

void minus_val()
{
    //모든 원판의 평균을 구하고, 각 값을 변경해주는 함수
    double cnt = 0;
    double sum = 0;
    for (int y_ = 1; y_ <= N; y_++)
    {
        for (int x_ = 1; x_ <= M; x_++)
        {
            if (map[y_][x_] != 0)
            {
                cnt++;
                sum += map[y_][x_];
            }
        }
    }
    if (cnt == 0)
        return;
    double value = sum / cnt;
    for (int y_ = 1; y_ <= N; y_++)
    {
        for (int x_ = 1; x_ <= M; x_++)
        {
            if (map[y_][x_] != 0)
            {
                if (map[y_][x_] > value)
                    map[y_][x_] -= 1;
                else if (map[y_][x_] < value)
                    map[y_][x_] += 1;
            }
        }
    }
}

void Check()
{
    //원판을 지울것인지 확인하는 함수
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (map[i][j] >= 1)
                value_change(i, j);
        }
    }
    //전역 플래그가 0일 경우, 어떠한 좌표에서도 인접한 원판이 동일한 값을 가지지 않으므로 평균값을 구해 원판값을 변경한다.
    if (flag == 0)
        minus_val();
    else
    {
        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= M; x++)
            {
                if (check[y][x] == true)
                    map[y][x] = 0;
            }
        }
    }
}

void Input()
{
    //입력 받는 함수
    cin >> N >> M >> T;
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
        {
            cin >> map[y][x];
        }
    }
    for (int i = 0; i < T; i++)
    {
        cin >> x >> d >> k;
        Rotation();
        Check();
        flag = 0;
    }
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
        {
            ans += map[y][x];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Input();
    cout << ans;
}