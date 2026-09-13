#include <iostream>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

void init()
{
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 下标为k的点的右边插入x
void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = l[r[k]];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

// 下标为k的点点左侧插入x，直接调用add(l[k], x);

// 删除第k个点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}