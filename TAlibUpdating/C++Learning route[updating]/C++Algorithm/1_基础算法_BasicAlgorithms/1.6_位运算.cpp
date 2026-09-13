// 给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        int x;
        scanf("%d", &x);

        int ans = 0;
        while (x)
        {
            x -= lowbit(x);
            ans++;
        }
        cout << ans << ' ';
    }

}