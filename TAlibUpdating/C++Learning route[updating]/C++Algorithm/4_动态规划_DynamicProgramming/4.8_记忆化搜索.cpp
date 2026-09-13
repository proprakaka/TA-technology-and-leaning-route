#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310;

int n, m; //网格滑雪场的行和列
int f[N][N]; //状态转移式
int h[N][N]; //网格滑雪场
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dp(int x, int y)
{
    int& v = f[x][y]; //Y总说的小技巧，等于把f[x][y]简化成了v，如果v发生变化，f[x][y]也会随之变化
    if (v != -1) return v; //如果已经计算过了，就可以直接返回答案
    v = 1; //注意v要先赋值为1哦~
    for (int i = 0; i < 4; i++)
    {
        //四个方向
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && h[x][y] > h[xx][yy])
        {
            //判断这点是否能走
            v = max(v, dp(xx, yy) + 1); //更新
        }
    }
    return v; //别忘了返回v啊（被坑了
}

int main()
{
    cin >> n >> m; //输入滑雪场行和列
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j]; //读入滑雪场数据
        }
    }
    memset(f, -1, sizeof f);
    int res = 0; //最后答案
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //因为这个人可以在任意一点开始滑，所以要遍历一遍滑雪场
            res = max(res, dp(i, j)); //更新答案
        }
    }
    cout << res << endl;
    return 0;
}