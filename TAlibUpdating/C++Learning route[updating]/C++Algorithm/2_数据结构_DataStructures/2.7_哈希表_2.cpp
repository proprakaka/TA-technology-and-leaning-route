// 2. 开放寻址法
int h[N]; // 大小开到数据范围的2～3倍
// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int x)
{
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x)
    {
        t++;
        if (t == N) t = 0;
    }
    return t;
}