vector<int> alls; // 存储所有待离散化的值

// 排序并去重
sort(alls.begin(), alls.end());
alls.erase(unique(alls.begin(), alls.end()), alls.end());

// 二分查找 x 对应的离散化值
int find(int x) 
{
    int l = 0, r = alls.size() - 1;
    while (l < r) 
    {
        int mid = (l + r) / 2;
        if (alls[mid] >= x) 
            r = mid;
        else 
            l = mid + 1;
    }
    return r + 1; // 映射到 1, 2, ..., n
}