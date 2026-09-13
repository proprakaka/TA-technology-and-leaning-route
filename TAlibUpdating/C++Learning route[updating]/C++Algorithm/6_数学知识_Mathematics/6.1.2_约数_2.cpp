#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int mod = 1e9+7 ;

int main()
{
    int T; 
    cin >> T;
    unordered_map<int, int> h;
    while(T--)
    {
        int n; cin >> n;
        //依次求出指数
        for(int i = 2; i <= n / i; i++)
        {
            while(n % i == 0)
            {
                //指数+1
                h[i] ++;
                n = n / i;
            }
        }
        //如果有剩余，也是一个质因子
        if(n > 1) h[n]++;
    }

    long long  res = 1;
    for(auto iter = h.begin(); iter != h.end(); iter++)
    {
        //res = (x1+1)(x2+1)(x3+1)…(xk+1)
        res = res * (iter->second + 1) % mod ;
    }
    cout << res;
}