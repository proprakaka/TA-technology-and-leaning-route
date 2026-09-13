#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    ios::sync_with_stdio(false);
    
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt--;
        if (tt) cout << stk[tt] << " ";
        else cout << "-1" << " ";

        stk[++tt] = x;
    }
    return 0;
}