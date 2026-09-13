#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long i64; // 定义i64为long long类型，方便后续使用

const int INF = 0x3f3f3f3f; // 定义无穷大常量，通常用于初始化最短路径的数组

int n, m; // n是图中的点数，m是图中的边数

// SPFA改进版算法：检测图中是否存在负权回路
bool spfa_better()
{
    using edge = pair<int, int>; // 定义边的结构为一个pair，存储边的目标节点和权重
    cin >> n >> m; // 读取点数n和边数m
    vector<vector<edge>> G(n); // 建立图的邻接表表示，G[i]存储与点i相连的所有边

    // 读取图的边，并建立邻接表
    while (m--)
    {
        int a, b, z; // a到b的边，权重为z
        cin >> a >> b >> z; // 读取边的起点a，终点b和权重z
        G[a - 1].emplace_back(b - 1, z); // 注意图的点是从1开始的，所以这里减去1处理成0-indexed
    }

    // 初始化最短路径数组dist，前驱数组pre，标记数组inQueue
    vector<int> dist(n, 0); // dist[i]表示从起点到点i的最短路径
    vector<int> pre(n, -1); // pre[i]表示从点i到其前一个点的路径
    vector<bool> inQueue(n, true); // inQueue[i]表示点i是否在队列中
    queue<int> queue; // 使用队列来实现SPFA算法
    for (int i = 0; i < n; i++)
    {
        queue.emplace(i); // 将所有点都加入队列
    }

    int idx = 0; // 计数器，用来统计松弛操作次数

    // 检测是否存在负权回路的函数
    auto detectCycle = [&]()
    {
        vector<int> vec; // 用来记录当前遍历的路径
        vector<bool> inStack(n, false); // 标记当前点是否在路径中
        vector<bool> vis(n, false); // 标记点是否已访问
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                // 如果点i未被访问
                for (int j = i; j != -1; j = pre[j])
                {
                    // 从点i开始反向追踪路径
                    if (!vis[j])
                    {
                        vis[j] = true; // 标记点j为已访问
                        vec.push_back(j); // 将点j加入当前路径
                        inStack[j] = true; // 将点j标记为当前路径的一部分
                    }
                    else
                    {
                        if (inStack[j]) return true; // 如果点j已经在路径中，说明存在负权回路
                        break; // 否则，退出
                    }
                }
                // 清除路径标记
                for (int j : vec) inStack[j] = false;
                vec.clear(); // 清空路径
            }
        }
        return false; // 如果没有发现负权回路，返回false
    };

    // SPFA主循环
    while (!queue.empty())
    {
        int u = queue.front(); // 从队列中取出一个节点
        queue.pop(); // 队列出队
        inQueue[u] = false; // 标记该节点已出队

        // 遍历u的所有邻接边
        for (auto [v, w] : G[u])
        {
            // v是目标点，w是边的权重
            if (dist[u] + w < dist[v])
            {
                // 如果通过u到v的路径更短
                pre[v] = u; // 更新v的前驱为u
                dist[v] = dist[u] + w; // 更新v的最短路径
                if (++idx == n)
                {
                    // 如果已经进行n次松弛操作
                    idx = 0;
                    if (detectCycle()) return true; // 检测是否存在负权回路
                }
                if (!inQueue[v])
                {
                    // 如果v不在队列中，将其加入队列
                    queue.push(v);
                    inQueue[v] = true; // 标记v在队列中
                }
            }
        }
    }

    // 如果最终还是检测到负权回路，返回true
    if (detectCycle()) return true;
    return false; // 如果没有负权回路，返回false
}

int main()
{
    ios_base::sync_with_stdio(false); // 关闭同步，提高输入输出效率
    cin.tie(NULL); // 解除cin与cout的同步

    // 调用SPFA改进版算法，判断图中是否存在负权回路
    if (spfa_better())
        cout << "Yes" << endl; // 如果有负权回路，输出"Yes"
    else
        cout << "No" << endl; // 如果没有负权回路，输出"No"

    return 0;
}