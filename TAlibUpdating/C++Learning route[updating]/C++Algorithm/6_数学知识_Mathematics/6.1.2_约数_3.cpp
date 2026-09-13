#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;

// 函数：分解质因子并计算所有结果的和
LL computeResult(int n)
{
    unordered_map<int, int> primes;

    // 对n个数进行质因子分解
    while (n--)
    {
        int x;
        cin >> x;

        // 对每个数字进行质因子分解
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i]++; // 增加质因子 i 的幂次
            }
        }

        // 如果 x > 1, 那么它本身就是一个质因子
        if (x > 1)
            primes[x]++;
    }

    // 计算结果
    LL res = 1;
    // 对所有质因子及其幂次进行处理
    for (auto p : primes)
    {
        LL a = p.first, b = p.second;
        LL t = 1;

        // 计算 (a^0 + 1) * (a^1 + 1) * ... * (a^b + 1)
        while (b--)
        {
            t = (t * a + 1) % mod;
        }

        // 将这一部分的结果乘入总结果
        res = res * t % mod;
    }

    return res;
}

int main()
{
    int n;
    cin >> n; // 输入数量
    cout << computeResult(n) << endl; // 调用函数并输出结果
    return 0;
}