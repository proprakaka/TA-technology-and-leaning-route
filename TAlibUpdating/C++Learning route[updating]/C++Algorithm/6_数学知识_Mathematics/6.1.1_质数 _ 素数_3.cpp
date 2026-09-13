// 埃氏筛法
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = n;
            for (int j = i + 1; j <= n; j += i) st[j] = true;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    get_primes(n);

    cout << cnt << endl;
}

// 线性筛法
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
// primes 保存素数
int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    // 遍历所以备选数
    for (int i = 2; i <= n; i++)
    {
        // 备选数没有被标记为合数，则放到素数数组中
        if (!st[i])
            primes[cnt++] = i;
        // 标记后面的合数
        // 遍历素数
        for (int j = 0; primes[j] <= n / i; j++)
        {
            // 将 i * 素数标记为合数
            st[primes[j] * i] = true;
            // 如果 i 是 素数的倍数，则停止后面的标记。
            // 因为后续的，i 倍数的合数，
            // 一定能等待到被 primes[j] 标记 
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}