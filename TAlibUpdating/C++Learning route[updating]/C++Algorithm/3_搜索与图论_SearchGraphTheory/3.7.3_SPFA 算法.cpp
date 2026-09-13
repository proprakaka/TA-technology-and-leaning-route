#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], w[N], ne[N], idx; //邻接表，存储图
int st[N]; //标记顶点是不是在队列中
int dist[N]; //保存最短路径的值
int q[N], hh, tt = -1; //队列

void add(int a, int b, int c)
{
    //图中添加边和边的端点
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    q[++tt] = 1; //从1号顶点开始松弛，1号顶点入队
    dist[1] = 0; //1号到1号的距离为 0
    st[1] = 1; //1号顶点在队列中
    while (tt >= hh)
    {
        //不断进行松弛
        int a = q[hh++]; //取对头记作a，进行松弛
        st[a] = 0; //取完队头后，a不在队列中了
        for (int i = h[a]; i != -1; i = ne[i]) //遍历所有和a相连的点
        {
            int b = e[i], c = w[i]; //获得和a相连的点和边
            if (dist[b] > dist[a] + c)
            {
                //如果可以距离变得更短，则更新距离

                dist[b] = dist[a] + c; //更新距离

                if (!st[b])
                {
                    //如果没在队列中
                    q[++tt] = b; //入队
                    st[b] = 1; //打标记
                }
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h); //初始化邻接表
    memset(dist, 0x3f, sizeof dist); //初始化距离
    int n, m; //保存点的数量和边的数量
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        //读入每条边和边的端点
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w); //加入到邻接表
    }
    spfa();
    if (dist[n] == 0x3f3f3f3f) //如果到n点的距离是无穷，则不能到达 
        cout << "impossible";
    else cout << dist[n]; //否则能到达，输出距离
    return 0;
}