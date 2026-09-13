// 函数
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

// 完整代码
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        // 公式最前面的n
        int res = n;
        //求质因子
        for(int i = 2; i <= n / i; i++)
        {
            if(n % i == 0)//找到质因子
            {
                // (p - 1) / p
                // 先除后乘
                res = res / i * (i - 1) ;
                // 对 n 进行约分
                while(n % i == 0) n = n / i;
            }
        }
        // 如果有剩余，则剩余是个质因子
        if(n > 1) res = res / n * (n - 1) ;
        cout << res << endl;
    }
    return 0;
}