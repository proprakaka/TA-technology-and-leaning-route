#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 函数：寻找并输出所有约数
void printDivisors(int n)
{
    vector<int> res;

    // 约数成对出现，所以只需要循环到 sqrt(n)
    // 注意：用 i * i <= n 会有溢出的风险，使用 i <= n / i 避免溢出
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            // 如果 i * i = n，添加 i 即可，不用重复添加 n / i
            if (n / i != i)
                res.push_back(n / i);
        }
    }

    // 对所有约数排序并输出
    sort(res.begin(), res.end());
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int T;
    cin >> T; // 读取测试用例数量
    while (T--)
    {
        int n;
        cin >> n; // 读取每个测试用例的数值
        printDivisors(n); // 调用函数输出约数
    }
    return 0;
}