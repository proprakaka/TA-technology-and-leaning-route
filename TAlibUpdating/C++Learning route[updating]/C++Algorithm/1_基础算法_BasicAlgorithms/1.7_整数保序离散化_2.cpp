// 假定有一个无限长的数轴，数轴上每个坐标上的数都是 0
// 现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c 
// 接下来，进行 m 次询问，每个询问包含两个整数 l 和 r
// 你需要求出在区间 [l,r] 之间的所有数的和

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find (int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return r + 1; // 不需要处理边界
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});

        alls.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto i: add)
    {
        int x = find(i.first);
        a[x] += i.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    // 处理询问
    for (auto i: query)
    {
        int l = find(i.first);
        int r = find(i.second);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}